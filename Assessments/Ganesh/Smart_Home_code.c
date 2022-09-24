float x,y,z,temp;            //initializing the variables
const int ledPin = 13;       // led connected to 13
const int buzzerPin = 12;    //piezo buzzer connected to 12
void setup()
{
  pinMode(8, INPUT);          //set pir values as input
  pinMode(12, OUTPUT);        //set d12 as ooutput for buzzer
  pinMode(13, OUTPUT);        //set d13 as output for led
  pinMode(A5, INPUT);         //set a5 for input from photodiode
  pinMode(A4, INPUT);         //set a4 for input from temperature sensor
  Serial.begin(9600);
}
void loop()                    // run the proogram continuously
{
  x= digitalRead(8);           //get the digital input from pir
  y= analogRead(A5);           //get the analog input from photodiode
  z= analogRead(A4);           //get analog input from temperature sensor
  Serial.println(x);            
  Serial.println(y);
  Serial.println(z);
  temp = (double)z / 1024;      //calculating the temperature
  temp = temp * 5;                
  temp = temp - 0.5;              
  temp = temp * 100;              
  if ( (x==HIGH) )
  {
   if(y<600 && temp>30)         //checking for both the temperature and brightness value
   {
      tone(12,1000,250);        //turn on buzzer with 1000Hz for 250ms
      digitalWrite(13, HIGH);   //turn on led            
   }
  }
   
  else
  {
    digitalWrite(13, LOW);       //turn off led
  }
}
