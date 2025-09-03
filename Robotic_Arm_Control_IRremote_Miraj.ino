#include <IRremote.h>
#include <Servo.h>

int RECV_PIN =2;
int servopin1 = 5;
int servopin2 = 6;
int servopin3 =9;
int servopin4 =10;

int pos1 =90;
int pos2 =148;
int pos3 =90;
int pos4 = 90;

unsigned long lastcode;

IRrecv irrecv (RECV_PIN);
decode_results results;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;


void setup ()
{
  Serial.begin(9600);

  irrecv.enableIRIn();

  myservo1.attach(servopin1);
  myservo2.attach(servopin2);
  myservo3.attach(servopin3);
  myservo4.attach(servopin4);

  myservo1.write (pos1);
  myservo2.write (pos2);
  myservo3.write (pos3);
  myservo4.write (pos4);

  

  
}


void loop ()
{
  if (irrecv.decode(&results))
  {
    
    Serial.println (results.value , HEX);

if (results.value == 0xFFFFFFFF)
{
  results. value = lastcode;
}

if (results.value == 0xFEDA25)  //FEDA25   //right
{
  lastcode = results.value;

  pos1+=2;
  
  if (pos1 >180){pos1=180;}

  myservo1.write (pos1);
  
}

if (results.value == 0xFE1AE5) //FEDA25  //left
{
  lastcode = results.value;

  pos1-=2;
  
  if (pos1 <0){ pos1=0; }

  myservo1.write (pos1);
}

if (results.value== 0xFE5AA5)       // all past
{
 lastcode = results.value;

  pos1=90;
  pos2=120;
  pos3=90;
 // pos4=90;
  
  

  myservo1.write (pos1);
  myservo2.write (pos2);
  myservo3.write (pos3);
 // myservo4.write (pos4);
  
   
}

if (results.value == 0xFE6A95) //FE6A95  // down1
{
  lastcode = results.value;

  pos2+=2;
  
  if (pos2 >180){pos2=180;}

  myservo2.write (pos2);
  
}

if (results.value == 0xFE7A85)  //FE7A85   // up1
{
  lastcode = results.value;

  pos2-=2;
  
  if (pos2 <100){ pos2=100; }

  myservo2.write (pos2);
}

if (results.value == 0xFEDF20)  
{
  lastcode = results.value;

  pos3+=2;
  
  if (pos3 >180){ pos3=180; }

  myservo3.write (pos3);
}

if (results.value == 0xFE5FA0)  
{
  lastcode = results.value;

  pos3-=2;
  
  if (pos3 <0){ pos3=0; }

  myservo3.write (pos3);
}

if (results.value == 0xFE9F60)  
{
  lastcode = results.value;

  pos4+=5;
  
  if (pos4 <1800){ pos4=180; }

  myservo4.write (pos4);
}
if (results.value == 0xFE1FE0)  
{
  lastcode = results.value;

  pos4-=5;
  
  if (pos4<0){ pos4=0; }

  myservo4.write (pos4);
}

  delay (30);  
    irrecv.resume();

    //Serial.println (pos2);
    
  }
}
