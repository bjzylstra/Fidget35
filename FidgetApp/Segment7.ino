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
    0x77,
    0x7C,
    0x39,
    0x5E,
    0x79,
    'F',
    'G',
    0x74,
    0x04,
    0x1E,
    'K',
    'L',
    'M',
    'N',
    0x5C,
    'P',
    'Q',
    0x50,
    0x6D,
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z'
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
