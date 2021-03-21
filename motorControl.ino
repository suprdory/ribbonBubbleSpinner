int spd = 0;
int dir = -1;
int dur = 0;
int stt = 0;
int end = 0;


void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}



void loop()
{

  // linspd(0, 255, 10);
  // linspd(255, 255, 10);
  // linspd(255, 0, 5);
  // linspd(0, 0, 20);

  if (random(100) < 10) {
    spd = random(50, 100);
    powdir(spd, dir);
  }

  if (random(100) < 2 ) {
    dir = -dir;
    powdir(0, dir);
    delay(200);
    powdir(spd, dir);
  }

  delay(100);

}

void linspd(int spd1, int spd2, int dur)
{
  for (int i = 0; i <= dur * 10; i++) {
    spd = map(i, 0, dur * 10, spd1, spd2);
    powdir(spd, dir);
    delay(10);
    Serial.println(spd);
  }
}

void powdir(int spd, int dir)
{
  if (dir > 0) {
    //  digitalWrite(13, HIGH);
    analogWrite(9, spd);
    digitalWrite(10, LOW);
  }

  else if (dir < 0)
  {
    //digitalWrite(13, LOW);
    digitalWrite(9, LOW);
    analogWrite(10, spd);
  }

}
