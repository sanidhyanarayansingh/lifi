int audiovalue=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop()
{
  int b=0;
  audiovalue = analogRead(A5);
  Serial.print("Analog value is:");
  Serial.println(audiovalue);
  String audioString = String(audiovalue,BIN);
  b = audioString.length();
  if( b > 8)
  {
    goto l;
  }
  Serial.print("Binary form is:");
  Serial.println(audioString);
  Serial.print("length of string is:");
  Serial.println(b);
  Serial.println("bits transmitted after 0 padding: ");
  l:
  switch(b)
  {
    case 1 : digitalWrite(12,HIGH);
             Serial.print("1");
             delay(10);
             for(int i=0;i<7;i++)
             {
              digitalWrite(12,LOW);
              Serial.print("0");
              delay(10);
             }
             //Serial.println("");
             //Serial.println("End of zero padding");
             if(audioString[8-b] == '1')
             {
              digitalWrite(12,HIGH);
              //Serial.println("HIGH");
              Serial.print("1");
             }
             else
             {
              digitalWrite(12,LOW);
              //Serial.println("LOW");
              Serial.print("0");
             }
             //Serial.println("End of data");
             delay(10);
             break;
             
    case 2 : //Serial.println("HIGH");
             digitalWrite(12,HIGH);
             Serial.print("1");
             delay(10);
             for(int i=0;i<6;i++)
             {
              //Serial.println("LOW");
              digitalWrite(12,LOW);
              Serial.print("0");
              delay(10);
             }
             for(int i=2;i>0;i--)
             {
              if(audioString[8-i] == '1')
              { 
               digitalWrite(12,HIGH);
               //Serial.println("HIGH");
               Serial.print("1");
              }
              else
              {
               digitalWrite(12,LOW);
               //Serial.println("LOW");
               Serial.print("0");
              }
              delay(10);
             }
             break;

    case 3 :
    //Serial.println("HIGH");
    digitalWrite(12,HIGH);
    Serial.print("1");
  delay(10);
    for(int i=0;i<5;i++)
    {
      //Serial.println("LOW");
      digitalWrite(12,LOW);
      Serial.print("0");
    delay(10);
    }
    for(int i=3;i>0;i--)
    {
    if(audioString[8-i] == '1')
      { 
        digitalWrite(12,HIGH);
      //  Serial.println("HIGH");
      Serial.print("1");
      }
      else
      {
        digitalWrite(12,LOW);
        //Serial.println("LOW");
        Serial.print("0");
      }
        delay(10);
    }
  
    break;

    case 4:
    //Serial.println("HIGH");
    digitalWrite(12,HIGH);
    Serial.print("1");
  delay(10);
    for(int i=0;i<4;i++)
    {
      digitalWrite(12,LOW);
      //Serial.println("LOW");
      Serial.print("0");
    delay(10);
    }
    for(int i=4;i>0;i--)
    {
    if(audioString[8-i] == '1')
      { 
        digitalWrite(12,HIGH);
      //  Serial.println("HIGH");
      Serial.print("1");
      }
      else
      {
        digitalWrite(12,LOW);
        //Serial.println("LOW");
        Serial.print("0");
      }
      delay(10);
    }
    break;

    case 5:
   // Serial.println("HIGH");
    digitalWrite(12,HIGH);
    Serial.print("1");
  delay(10);
    for(int i=0;i<3;i++)
    {
      digitalWrite(12,LOW);
     // Serial.println("LOW");
     Serial.print("0");
    delay(10);
    }
    for(int i=5;i>0;i--)
    {
    if(audioString[8-i] == '1')
      { 
        digitalWrite(12,HIGH);
      //  Serial.println("HIGH");
      Serial.print("1");
      }
      else
      {
        digitalWrite(12,LOW);
        //Serial.println("LOW");
        Serial.print("0");
      }
         delay(10);
    }
    break;

    case 6:
    //Serial.println("HIGH");
    digitalWrite(12,HIGH);
    Serial.print("1");
  delay(10);
    for(int i=0;i<2;i++)
    {
      digitalWrite(12,LOW);
      //Serial.println("LOW");
      Serial.print("0");
    delay(10);
    }
    for(int i=6;i>0;i--)
    {
    if(audioString[8-i] == '1')
      { 
        digitalWrite(12,HIGH);
      //  Serial.println("HIGH");
      Serial.print("1");
      }
      else
      {
        digitalWrite(12,LOW);
        //Serial.println("LOW");
        Serial.print("0");
      }
         delay(10);
    }
    break;

    case 7:
    //Serial.println("HIGH");
    digitalWrite(12,HIGH);
    Serial.print("1");
  delay(10);
    digitalWrite(12,LOW);
    //Serial.println("LOW");
    Serial.print("0");
  delay(10);
    for(int i=7;i>0;i--)
    {
    if(audioString[8-i] == '1')
      { 
        digitalWrite(12,HIGH);
      //  Serial.println("HIGH");
      Serial.print("1");
      }
      else
      {
        digitalWrite(12,LOW);
        //Serial.println("LOW");
        Serial.print("0");
      }
         delay(10);
    }
    break;

    case 8:
    //Serial.println("HIGH");
    digitalWrite(12,HIGH);
    Serial.print("1");
  delay(10);
    for(int i=8;i>0;i--)
    {
    if(audioString[8-i] == '1')
      { 
        digitalWrite(12,HIGH);
      //  Serial.println("HIGH");
      Serial.print("1");
      }
      else
      {
        digitalWrite(12,LOW);
        //Serial.println("LOW");
        Serial.print("0");
      }
         delay(10);
    }
    break;

    default:
  //delay(10);
  Serial.print("");
  }
    Serial.println("");
}
