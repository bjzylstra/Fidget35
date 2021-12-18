int bar1Pin = 0;
int bar2Pin = 1;
int bar3Pin = 2;
int bar4Pin = 3;
int bar5Pin = 4;
int bar6Pin = 5;
int bar7Pin = 6;
int bar8Pin = 7;
int bar9Pin = 8;
int bar10Pin = 9;
int barPins[] = {bar1Pin,bar2Pin,bar3Pin,bar4Pin,bar5Pin,bar6Pin,bar7Pin,bar8Pin,bar9Pin,bar10Pin};

void bar10Setup() 
{
  // put your setup code here, to run once:
  int i;
  for (i = 0; i < 10; i++)
  {
    // Initialize all segments as outputs and turn off by setting low
    pinMode(barPins[i], OUTPUT);
    digitalWrite(barPins[i], LOW);
  }
}

void digitToBar10(int digit)
{
  Serial.print("Digit ");
  Serial.println(digit);

  // Use bar 10 as the 10s place.
  if (digit > 9)
  {
    digitalWrite(bar10Pin, HIGH);
    digit = digit - 10;
  }
  else
  {
    digitalWrite(bar10Pin, LOW);
  }
  
  for (int i = 0; i < 9; i++)
  {
    if (i < digit)
    {
      digitalWrite(barPins[i], HIGH);
    }
    else
    {
      digitalWrite(barPins[i], LOW);
    }
  }  
}

void maskToBar10(int mask)
{
  int i;
  for (i = 0; i < 10; i++)
  {
    if ((mask & 0x1) == 0x1)
    {
      digitalWrite(barPins[i], HIGH);
    }
    else
    {
      digitalWrite(barPins[i], LOW);
    }
    mask >>= 1;
  }  
}
