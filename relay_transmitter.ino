char incomingByte = 0;
int b=0;
int  ascii_value =0;
int pin =A0;
void setup() {
Serial.begin(9600); 
pinMode(11, OUTPUT);
pinMode(pin, INPUT);
//Serial.println(" Data transmitted:");
}

void loop()
{
  if (Serial.available() > 0) 
  {
    //Serial.println("");
    //Serial.print("JAI: ");
    while(Serial.available()>0)
    {
  int a = 0;
  incomingByte = Serial.read();
  ascii_value = incomingByte; 
  String thisString = String(ascii_value,BIN);
  a = thisString.length();
  //Serial.print(" Data transmitted:");
  Serial.print(incomingByte);
  //Serial.print("ASCII value is:");
  //Serial.println(ascii_value);
  //Serial.print("Binary form is:");
  //Serial.println(thisString);
  // Serial.print("length of string is:");
 // Serial.println(a);
 // Serial.print("8-bits transmitted after 0 padding: ");
  switch(a)
  {
    case 6:
    digitalWrite(11,HIGH);
   // Serial.print("1");
   delay(80);
    digitalWrite(11,LOW);
   // Serial.print("0");
   delay(80);
    for(int i=0; i<a; i++)
    {
     // Serial.print(thisString[i]);
      if(thisString[i] == '1')
      { 
        digitalWrite(11,HIGH);
        //Serial.println("HIGH");
      }
      else
      {
        digitalWrite(11,LOW);
        //Serial.println("LOW");
      }
     delay(80);
      digitalWrite(11,LOW);
     }
     break;
     
     default:
         digitalWrite(11,HIGH);
     //    Serial.print("1");
        delay(80);
         for(int i=0; i<a; i++)
         {
        //    Serial.print(thisString[i]);
            if(thisString[i] == '1')
            { 
              digitalWrite(11,HIGH);
              //Serial.println("HIGH");
            }
            else
            {
              digitalWrite(11,LOW);
              //Serial.println("LOW");
            }
           delay(80);
            digitalWrite(11,LOW);
          }
   }
  // Serial.println(" ");
  
  delay(80);
    }
    Serial.println("  ");
  }
  int arrayone[] = {0,0,0,0,0,0,0};
  int bit = analogRead(pin);
  if(bit <= 150)
  {
    char data = 0;
    int asciivalue=0;
    Serial.print("8-Bit data received is:");
    delay(80);
    Serial.print("1");
    for(int i =0;i<7;i++)
    {
      bit = analogRead(pin);
      if(bit <= 150)
      {
        arrayone[i] = 1;
        Serial.print("1");
      }
      else
      {
        arrayone[i] = 0;
        Serial.print("0");
      }
     delay(80);
    }
     // Serial.println(" ");
    //  Serial.print("string is:");
      int m=64;
      for(int i =0;i<7;i++)
        {
          int x = arrayone[i];
          asciivalue = asciivalue+ m*x;
      //    Serial.print(arrayone[i]);
          m=m/2;
        }
        data = asciivalue;
      //Serial.println("");
      //Serial.print("ASCII value is:");
      //Serial.println(asciivalue);
      //Serial.print("Data received is:");
      Serial.print(data);
      }
      
   else
        {
          b =0;
        }
}
