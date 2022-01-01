// It appears that enums have to go in main even though it belongs in ModeSwicthInput
enum class Mode
{
  unknown = 0,
  left = 1,
  center = 2,
  right = 3
};

enum class UpDownPosition
{
  unknown = 0,
  up = 1,
  center = 2,
  down = 3
};

int delayTime = 200;
bool decimalOn = true;
int lastDigit = 0;
int counterDelay = 0;
char messages[15][10] = {
  "Hel lo",
  "Isaiah",
  "Gideon",
  "Papa",
  "Grandma",
  "Dad",
  "Mom",
  "loves",
  "bye",
  " ",
  " ",
  " ",
  " ",
  " ",
  " "
};
int messageIndex = -1;
char* text = "";
int textIndex = 0;

void setup() {
  // put your setup code here, to run once:
  segment7setup();
  binaryInputSetup();
  binaryOutputSetup();
  bar10Setup();
  sliderSetup();
  modeInputSetup();
  upDownInputSetup();
}

void loop() {
  // Toggle the decimal point on every loop to show life
  int digit = lastDigit;
  Mode mode = modeInputRead();
  UpDownPosition upDown = upDownInputRead();
  int sliderDigit = sliderInputRead(9);
  decimalOn = true;
  switch (mode)
  {
    case Mode::left:
      if (counterDelay > (10 - sliderDigit))
      {
        counterDelay = 0;
        sliderLedOutput(true);
      }
      else
      {
        counterDelay++;
        sliderLedOutput(false);
      }
    
      if (upDown == UpDownPosition::center && messageIndex >= 0)
      {
        // Show text mode
        decimalOn = false;
      }
      if (counterDelay == 0)
      {
        switch (upDown)
        {
          case UpDownPosition::up:
            digit++;
            if (digit > 9)
            {
              digit = 0;
            }
            break;
          case UpDownPosition::down:
            digit--;
            if (digit < 0)
            {
              digit = 9;
            }
            break;
          case UpDownPosition::center:
            if (text[textIndex] == 0)
            {
              // End of message. Find next message
              textIndex = 0;
              messageIndex = binaryInputRead() - 1;
              if (messageIndex >= 0)
              {
                text = messages[messageIndex];
              }
              else
              {
                text = "";
              }
            }
            else
            {
              textIndex++;
              if (text[textIndex] == ' ')
              {
                // A space between identical letters. Make it half as long.
                counterDelay = (10 - sliderDigit) - 1;
              }
            }
            break;
          case UpDownPosition::unknown:
            break;
        }
      }
      break;
    case Mode::center:
      digit = binaryInputRead();
      sliderLedOutput(false);
      break;
    case Mode::right:
      digit = sliderDigit;
      sliderLedOutput(true);
      break;
    case Mode::unknown:
      sliderLedOutput(decimalOn);
      break;
  }

  if (decimalOn)
  {
    digitTo7Segment(digit, decimalOn);
    digitToBinaryOutput(digit);
    digitToBar10(digit);
    lastDigit = digit;
  }
  else
  {
    letterTo7Segment(text[textIndex]);
    digitToBinaryOutput(0);
    digitToBar10(0);
  }
  delay(delayTime);
}
