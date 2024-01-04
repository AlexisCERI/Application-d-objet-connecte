unsigned int val[] = {35, 38, 35, 20, 20, 20, 25, 5, 140, 255, 0, 20, 20, 20, 25, 35, 45, 55, 58, 56, 25};
int repos = 250;
//int repos = 
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()) {
    repos=Serial.readStringUntil('\n').toInt();
  }
  digitalWrite(13, HIGH );
  int i;
  for (i = 0; i <= 20; i++)
  {
    analogWrite(9, val[i]);
    delay(20);
  }
  digitalWrite(13, LOW );
  analogWrite(9, 0);
  delay(repos);
}