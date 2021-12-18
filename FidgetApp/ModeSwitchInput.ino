int mode10Pin = 38;
int mode1Pin = 37;
int mode2Pin = 36;
int mode3Pin = 35;

bool isMode1Output;
Mode lastReadMode = Mode::unknown;

void modeInputSetup() 
{
  // Start with driving mode 1 to read mode 10/2
  pinMode(mode10Pin, INPUT_PULLUP);
  pinMode(mode2Pin, INPUT_PULLUP);
  pinMode(mode3Pin, INPUT_PULLUP);
  pinMode(mode1Pin, OUTPUT);
  digitalWrite(mode1Pin, LOW);
  isMode1Output = true;
}

Mode modeInputRead()
{
  Mode currentMode = lastReadMode;
  // Using active LOW on all inputs
  if (isMode1Output)
  {
    Serial.println("Mode 1 output");
    Serial.print("Mode 10 pin ");
    Serial.println(digitalRead(mode10Pin));
    Serial.print("Mode 2 pin ");
    Serial.println(digitalRead(mode2Pin));
    Serial.print("Mode 3 pin ");
    Serial.println(digitalRead(mode3Pin));
    if (!digitalRead(mode10Pin))
    {
      currentMode = Mode::left;
    }
    else if (!digitalRead(mode2Pin))
    {
      currentMode = Mode::center;
    }
    else
    {
      // No read on mode 1. Try mode 2 on the next cycle.
      pinMode(mode1Pin, INPUT_PULLUP);
      pinMode(mode2Pin, OUTPUT);
      digitalWrite(mode2Pin, LOW);
      isMode1Output = false;
    }
  }
  else
  {
    Serial.println("Mode 2 output");
    Serial.print("Mode 10 pin ");
    Serial.println(digitalRead(mode10Pin));
    Serial.print("Mode 2 pin ");
    Serial.println(digitalRead(mode2Pin));
    Serial.print("Mode 3 pin ");
    Serial.println(digitalRead(mode3Pin));
    if (!digitalRead(mode1Pin))
    {
      currentMode = Mode::center;
    }
    else if (!digitalRead(mode3Pin))
    {
      currentMode = Mode::right;
    }
    else
    {
      // No read on mode 2. Try mode 1 on the next cycle.
      pinMode(mode2Pin, INPUT_PULLUP);
      pinMode(mode1Pin, OUTPUT);
      digitalWrite(mode1Pin, LOW);
      isMode1Output = true;
    }
  }
  lastReadMode = currentMode;
  return currentMode;
}
