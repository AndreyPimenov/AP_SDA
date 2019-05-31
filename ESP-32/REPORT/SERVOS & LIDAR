// This is program for taking mesurements from lidar with moving servos
#include <Servo.h>
static const int servoHPin = 13; //change from 65 to 110 = 45 graduses
static const int servoVPin = 12; //change from 15 t0 60 = 45 graduses
Servo servoH; //ServoHorizontal
Servo servoV; //ServoVertical

#define RxD2 16
#define TxD2 17
String d_distance =" "; // Possible variable for gathering data from the lidar

int dist;//actual distance measurements of LiDAR
int strength;//signal strength of LiDAR
int check;//save check value
int i;
int uart[9];//save data measured by LiDAR
const int HEADER=0x59;//frame header of data package

void setup() {
Serial.begin(9600);
servoH.attach(servoHPin);
servoV.attach(servoVPin);
Serial2.begin(115200, SERIAL_8N1, RxD2, TxD2);
Serial.println("Serial TxD is on pin: " + String(TX));
Serial.println("Serial RxD is on pin " + String(RX));
Serial.println("Horizontal Servo Pin: " + String(servoHPin));
Serial.println("Vertical Servo Pin: " + String(servoVPin));
/*
// Only once:
Serial.println("Start changing data format of the lidar ");
Serial2.write("42 57 02 00 00 00 01 02"); //Command to enter configuration mode
delay(20);
if (String(Serial2.read())== "42 57 02 01 00 00 01 02"){
  Serial2.write("42 57 02 00 EE FF GG HH"); //enter the configuration table 
  Serial2.write("42 57 02 00 00 00 04 06"); //Pixhawk data format(decimal string)
  Serial2.write("42 57 02 00 00 00 00 1A"); //Output unit of distnace data is mm
  Serial2.write("42 57 02 00 00 00 03 11"); //Middle distance mode, applicable for 0.5 - 5m
  Serial2.write("42 57 02 00 00 00 00 02"); //exit configuration mode
  Serial.println("Data format of the lidar is changed ");
}
*/
}

void loop() {
  // This works following:
  // 45grades on Horizonat is a external loop
  // 45grades on Vertical is an internal loop
  // 1 grades on Horizontal, than 45 grades of internal Bottom Up and 45 grades of internal Upside Down
  // On each point of the map I take a lidar measuremrent
  // Repeat it until 45 grades achived
  // Pause for 1 seconds
  // from 45 grades on Horizontal to 0 grades
  // Pause for 1 seconds 
      
      for(float posHDegrees = 65; posHDegrees <= 110; /*posHDegrees++*/ posHDegrees = posHDegrees + 0.1) {
        servoH.write(posHDegrees);
        
        for(float posVDegrees = 15; posVDegrees <= 60; posVDegrees = posVDegrees + 0.1) 
        {   
        //delay(10);-----------------------------------------------------------------------------
        if (Serial2.available())//check if serial port has data input
{
 //Serial.print("Starting: ");
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[0]=HEADER;
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[1]=HEADER;

for(i=2;i<9;i++)//save data in array
{
uart[i]=Serial2.read();
}
check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
if(uart[8]==(check&0xff))//verify the received data as per protocol
{
dist=uart[2]+uart[3]*256;//calculate distance value
strength=uart[4]+uart[5]*256;//calculate signal strength value
//Serial.print("dist = ");
Serial.print(dist);//output measure distance value of LiDAR
Serial.print('\t');
//Serial.print("strength = ");
Serial.print(strength);//output signal strength value
Serial.print('\t');
//Serial.print("H_angle = ");
Serial.print(posHDegrees);
Serial.print('\t');
//Serial.print("V_angle = ");
Serial.print(posVDegrees);
Serial.print('\t');
Serial.print('\n');
}
}
}
}
        servoV.write(posVDegrees);
        //delay(5);-------------------------------------------------------------------------------------------
        }
        
        //Sending to Serial Port:
        //Serial.println("Lifting Up: " + d_distance);
        //d_distance = " ";
        //------------------------------
        
        for(float posVDegrees = 60; posVDegrees >= 15; posVDegrees = posVDegrees - 0.1) {
        //d_distance = d_distance + String(Serial2.read()) + " ";
        //delay(5);-------------------------------------------------------------------------------------------
 if (Serial2.available())//check if serial port has data input
{
//Serial.print("Starting: ");
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[0]=HEADER;
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[1]=HEADER;

for(i=2;i<9;i++)//save data in array
{
uart[i]=Serial2.read();
}
check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
if(uart[8]==(check&0xff))//verify the received data as per protocol
{
dist=uart[2]+uart[3]*256;//calculate distance value
strength=uart[4]+uart[5]*256;//calculate signal strength value
//Serial.print("dist = ");
Serial.print(dist);//output measure distance value of LiDAR
Serial.print('\t');
//Serial.print("strength = ");
Serial.print(strength);//output signal strength value
Serial.print('\t');
//Serial.print("H_angle = ");
Serial.print(posHDegrees);
Serial.print('\t');
//Serial.print("V_angle = ");
Serial.print(posVDegrees);
Serial.print('\t');
Serial.print('\n');
}
}
}
}
        servoV.write(posVDegrees);
        //delay(5);-------------------------------------------------------------------------------------------
        }
        
        //Sending to Serial Port:
        //Serial.println("Pulling down: " + d_distance);
        //d_distance = " ";
        //------------------------------
        }
//////////////////
    //delay (100);
/////////////////

    for(float posHDegrees = 110; posHDegrees >= 65; /*posHDegrees--*/ posHDegrees = posHDegrees - 0.1 ) {
        servoH.write(posHDegrees);

        for(float posVDegrees = 15; posVDegrees <= 60; posVDegrees = posVDegrees + 0.1) 
        {       
        //d_distance = d_distance + String(Serial2.read()) + " ";
        //delay(5);-----------------------------------------------------------------------------------
if (Serial2.available())//check if serial port has data input
{
//Serial.print("Starting: ");
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[0]=HEADER;
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[1]=HEADER;

for(i=2;i<9;i++)//save data in array
{
uart[i]=Serial2.read();
}
check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
if(uart[8]==(check&0xff))//verify the received data as per protocol
{
dist=uart[2]+uart[3]*256;//calculate distance value
strength=uart[4]+uart[5]*256;//calculate signal strength value
//Serial.print("dist = ");
Serial.print(dist);//output measure distance value of LiDAR
Serial.print('\t');
//Serial.print("strength = ");
Serial.print(strength);//output signal strength value
Serial.print('\t');
//Serial.print("H_angle = ");
Serial.print(posHDegrees);
Serial.print('\t');
//Serial.print("V_angle = ");
Serial.print(posVDegrees);
Serial.print('\t');
Serial.print('\n');
}
}
}
}
        servoV.write(posVDegrees);
        //delay(5);-------------------------------------------------------------------------------
        }
        
        //Sending to Serial Port:
        //Serial.println("Lifting Up: " + d_distance);
        //d_distance = " ";
        //------------------------------
        
        for(float posVDegrees = 60; posVDegrees >= 15; posVDegrees = posVDegrees - 0.1) 
        {
        //d_distance = d_distance + String(Serial2.read()) + " ";
        //delay(5);-------------------------------------------------------------------------------
 if (Serial2.available())//check if serial port has data input
{
//Serial.print("Starting: ");
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[0]=HEADER;
if(Serial2.read()==HEADER)//assess data package frame header 0x59
{ uart[1]=HEADER;

for(i=2;i<9;i++)//save data in array
{
uart[i]=Serial2.read();
}
check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
if(uart[8]==(check&0xff))//verify the received data as per protocol
{
dist=uart[2]+uart[3]*256;//calculate distance value
strength=uart[4]+uart[5]*256;//calculate signal strength value
//Serial.print("dist = ");
Serial.print(dist);//output measure distance value of LiDAR
Serial.print('\t');
//Serial.print("strength = ");
Serial.print(strength);//output signal strength value
Serial.print('\t');
//Serial.print("H_angle = ");
Serial.print(posHDegrees);
Serial.print('\t');
//Serial.print("V_angle = ");
Serial.print(posVDegrees);
Serial.print('\t');
Serial.print('\n');
}
}
}
}
        servoV.write(posVDegrees);
        //delay(5);----------------------------------------------------------------------------------------------
        }
        
        //Sending to Serial Port:
        //Serial.println("Pulling Down: " + d_distance);
        //d_distance = " ";
        //------------------------------
    }
}

