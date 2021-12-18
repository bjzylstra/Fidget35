int upPin = 10;
int centerPin = 11;
int downPin = 12;

void upDownInputSetup() 
{
  // Start with driving mode 1 to read mode 10/2
  pinMode(upPin, INPUT_PULLUP);
  pinMode(centerPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
}

UpDownPosition upDownInputRead()
{
  UpDownPosition pos = UpDownPosition::unknown;
  if (!digitalRead(upPin))
  {
    pos = UpDownPosition::up;
  }
  else if (!digitalRead(centerPin))
  {
    pos = UpDownPosition::center;
  }
  else if (!digitalRead(downPin))
  {
    pos = UpDownPosition::down;
  }
  return pos;
}
