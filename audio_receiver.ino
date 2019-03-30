int pin =A0;
void setup() {
  Serial.begin(9600);
}
void loop()
{
  int audioone[] = {0,0,0,0,0,0,0,0};
  int b;
  int bit1 = analogRead(pin);
    if(bit1 <= 100)
  {
    int audiovalue=0;
    Serial.print("9-Bit data received is: ");
    Serial.print("1");
       delay(10);
          delay(10);
    for(int i =0;i<8;i++)
    {
      bit1 = analogRead(pin);
      if(bit1 <= 70)
      {
        audioone[i] = 1;
        Serial.print("1");
      }
      else
      {
        audioone[i] = 0;
        Serial.print("0");
      }
     delay(10);
    }
      Serial.println(" ");
      Serial.print("string is:");
      int n=128;
      for(int i =0;i<8;i++)
        {
          int x = audioone[i];
          audiovalue = audiovalue+ n*x;
          Serial.print(audioone[i]);
         delay(10);
          n=n/2;
        }
      Serial.println("");
      Serial.print("Audio value is:");
      Serial.println(audiovalue);
      analogWrite(3,audiovalue);
  }
}
