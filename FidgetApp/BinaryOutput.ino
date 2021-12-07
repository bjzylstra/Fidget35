int binaryOutPin0 = 20;
int binaryOutPin1 = 19;
int binaryOutPin2 = 18;
int binaryOutPin3 = 17;

void binaryOutputSetup() 
{
  // put your setup code here
  pinMode(binaryOutPin0, OUTPUT);
  pinMode(binaryOutPin1, OUTPUT);
  pinMode(binaryOutPin2, OUTPUT);
  pinMode(binaryOutPin3, OUTPUT);
}

void digitToBinaryOutput(int digit)
{
  if ((digit & 1) != 0)
  {
    digitalWrite(binaryOutPin0,HIGH);
  }
  else
  {
    digitalWrite(binaryOutPin0,LOW);
  }
  if ((digit & 2) != 0)
  {
    digitalWrite(binaryOutPin1,HIGH);
  }
  else
  {
    digitalWrite(binaryOutPin1,LOW);
  }
  if ((digit & 4) != 0)
  {
    digitalWrite(binaryOutPin2,HIGH);
  }
  else
  {
    digitalWrite(binaryOutPin2,LOW);
  }
  if ((digit & 8) != 0)
  {
    digitalWrite(binaryOutPin3,HIGH);
  }
  else
  {
    digitalWrite(binaryOutPin3,LOW);
  }
}
