int segAPin = 27;
int segBPin = 28;
int segCPin = 30;
int segDPin = 31;
int segEPin = 32;
int segFPin = 26;
int segGPin = 25;
int segDPPin = 29;
int segPins[] = {segAPin, segBPin, segCPin, segDPin, segEPin, segFPin, segGPin, segDPPin};

void segment7setup() 
{
  // put your setup code here, to run once:
  int i;
  for (i = 0; i < 8; i++)
  {
    // Initialize all segments as outputs and turn off by setting high
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH);
  }
}

void digitTo7Segment(int digit, bool decimal)
{
  int digitMaps[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
  int digitMap = 0x0;

  if (digit <= 0xF)
  {
    digitMap = digitMaps[digit];
  }

  if (decimal)
  {
    digitalWrite(segDPPin, LOW);
  }
  else
  {
    digitalWrite(segDPPin, HIGH);
  }
  
  digitMapTo7Segment(digitMap);
}

void letterTo7Segment(char letter)
{
  int digitMaps[] = 
  {
    0x77, // A
    0x7C, // B
    0x39, // C
    0x5E, // D
    0x79, // E
    0x71, // F
    0x3D, // G
    0x76, // H
    0x30, // I
    0x1E, // J
    0x46, // K
    0x38, // L
    0x4F, // M
    0x54, // N
    0x3F, // O
    0x73, // P
    0x67, // Q
    0x50, // R
    0x6D, // S
    0x39, // T
    0x3E, // U
    0x1C, // V
    0x4E, // W
    0x36, // X
    0x66, // Y
    0x5B  // Z
  };
  
  // Always turn of the decimal in letter mode
  digitalWrite(segDPPin, HIGH);

  int digitMap = 0x0;

  // Map lower case letters to upper case
  if (letter >= 'a' && letter <= 'z')
  {
    letter -= 0x20;
  }

  if (letter >= 'A' && letter <= 'Z')
  {
    digitMap = digitMaps[letter - 'A'];
  }

  digitMapTo7Segment(digitMap);
}

void digitMapTo7Segment(int digitMap)
{
  for (int i = 0; i < 7; i++)
  {
    if (digitMap & 1)
    {
      digitalWrite(segPins[i], LOW);
    }
    else
    {
      digitalWrite(segPins[i], HIGH);
    }
    digitMap = digitMap >> 1;
  }
}
