int sliderLedPin = 33;
int sliderAnalogPin = A15;

void sliderSetup() 
{
  // put your setup code here, to run once:
  pinMode(sliderLedPin, OUTPUT);
  digitalWrite(sliderLedPin, LOW);
  pinMode(sliderAnalogPin, INPUT);
}

void sliderLedOutput(bool on)
{
  if (on)
  {
    digitalWrite(sliderLedPin, HIGH);
  }
  else
  {
    digitalWrite(sliderLedPin, LOW);
  }
}

int sliderInputRead(int upperLimit)
{
  int raw = analogRead(sliderAnalogPin);
  int scaler = 0x3FF / (upperLimit);
  int scaledValue = raw / scaler;
  if (scaledValue > upperLimit)
  {
    scaledValue = upperLimit;
  }
  return scaledValue;
}
