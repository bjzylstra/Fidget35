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
  int digitMaps[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  int digitMap = digitMaps[digit];
  int i;

  if (decimal)
  {
    digitalWrite(segDPPin, LOW);
  }
  else
  {
    digitalWrite(segDPPin, HIGH);
  }
  
  for (i = 0; i < 7; i++)
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
