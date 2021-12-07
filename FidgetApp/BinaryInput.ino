int binaryInPin0 = 16;
int binaryInPin1 = 15;
int binaryInPin2 = 14;
int binaryInPin3 = 21;

void binaryInputSetup() 
{
  // put your setup code here
  pinMode(binaryInPin0, INPUT_PULLUP);
  pinMode(binaryInPin1, INPUT_PULLUP);
  pinMode(binaryInPin2, INPUT_PULLUP);
  pinMode(binaryInPin3, INPUT_PULLUP);
}

int binaryInputRead()
{
  int result = 0;

  if (!digitalRead(binaryInPin0))
  {
    result+= 1;
  }
  if (!digitalRead(binaryInPin1))
  {
    result+= 2;
  }
  if (!digitalRead(binaryInPin2))
  {
    result+= 4;
  }
  if (!digitalRead(binaryInPin3))
  {
    result+= 8;
  }

  return result;
}
