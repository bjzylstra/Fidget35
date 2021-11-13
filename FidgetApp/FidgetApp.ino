int delayTime = 500;
int loopIndex = 0;

void setup() {
  // put your setup code here, to run once:
  segment7setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (i = 0; i <= 9; i++)
  {
    digitTo7Segment(i, i & 1);
    delay(delayTime);
  }
}
