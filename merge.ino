//The following Code is not Complete to get the Complete Code Go to my Pateron Page by clicking the sponsor button or by 
//going to the url : https://www.patreon.com/SawairaRafi/
#include<PID_v1.h>
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define FAN 12
#define bulb 13
#define pwm 10
#define pwmb 9

#define DHTPIN A1
#define DHTTYPE DHT11   

float t;

DHT dht(DHTPIN, DHTTYPE);

double setPoint, Input, Output,Output1;
double error;
//kp , ki, kd values define below

LiquidCrystal_I2C lcd(0x3F, 16, 2);
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//initializing PID


void setup(){

setPoint =20;  

pinMode(bulb,OUTPUT);

  	lcd.init();
    Serial.begin(9600);
    dht.begin();    
	  lcd.backlight();
	  lcd.setCursor(0, 0);     //column,row
    pinMode(FAN, OUTPUT);  
    lcd.print("Temp Control");
    delay(100);
    lcd.init();
 
  digitalWrite(bulb,HIGH);
  digitalWrite(FAN,HIGH);
  myPID.SetMode(AUTOMATIC);
  myPID1.SetMode(AUTOMATIC);
}

void loop(){

  k = keypad.getKey(); //getting values in character

 float t = dht.readTemperature();


  // Check if any reads failed and exit early (to try again).
  if ( isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }




   Serial.print(setPoint);
   Serial.print(",");
   Serial.print(abs(error));  
   Serial.print(",");

   Serial.println(t);

 lcd.setCursor(0,0);
 lcd.print("Temp");
  lcd.print(t);
  
  delay(1000);
  k = keypad.getKey();  
 if(k==35){
  lcd.init();
  lcd.print("**Settings**");
  lcd.init();
  lcd.print("Enter Mode:");
  mode=computeMode();
  lcd.init();

      if(mode==-666){ //***/
            lcd.init();
            lcd.setCursor(0, 1);
            lcd.print(" Auto Tune PID  ");
            setPoint=15;
            kp=2;
            ki=5;
            kd=9;
            mode=0;
            k=42;
            z=0;
            
          }
          else if(mode==-660){  //**0
            lcd.init();
            lcd.setCursor(0, 0);
            lcd.print("setpoint=");
            lcd.print(setPoint);
            lcd.setCursor(12, 0);
            lcd.print("kp=");
            lcd.print(kp);
            lcd.setCursor(0, 1);
            lcd.print(" ki=");
            lcd.print(ki);
            lcd.print(" kd=");
            lcd.print(kd);            
            delay(2000);
lcd.init();            
            overshoot=(overshoot-(setPoint-2))/(setPoint-2);
            lcd.print(" OS=");
            lcd.print(overshoot);            
            delay(2000);
            mode=0;
           
            k=42;
          } 
      else if(mode==-659){  //**1
            lcd.init();
            lcd.setCursor(0, 0);
            lcd.print("Enter setPoint:");
            lcd.setCursor(0, 1);
            setPoint=computeMode(); 
            lcd.init();
            lcd.setCursor(0, 0);
            lcd.print("setPoint:");
            lcd.print(setPoint);
            Serial.print("setPoint:");
            Serial.print(setPoint);
            Serial.println();
            delay(2000);
          
            mode=0;
            k=42;
          }

      else if(mode==-658){ //**2
            lcd.init();
            lcd.print(" Enter kp:  ");
            kp=computeMode();
            lcd.setCursor(0, 1);
            lcd.print("kp=");
            lcd.print(kp);
            Serial.print("kp:\r\n");
            Serial.print(kp);
            Serial.println();
            delay(2000);
            
            mode=0;
            k=42;
            //  lcd.print(kp);
          }

      else if(mode==-657){ //**3
            lcd.init();
            lcd.print(" Enter ki:  ");
            ki=computeMode();
            lcd.setCursor(0, 1);
            lcd.print("ki=");
            lcd.print(ki);
            Serial.print("ki\r\n");
            Serial.print(ki);
            // Serial.println();
            delay(2000);
            
            mode=0;
            k=42;
            //  lcd.print(ki);
          }
      else if(mode==-656){ //**4
            lcd.init();
            lcd.print(" Enter kd:  ");
            kd=computeMode();
            lcd.setCursor(0, 1);
            lcd.print("kd=");
            lcd.print(kd);
            Serial.print("kd\r\n");
            Serial.print(kd);
            // Serial.println();
            delay(2000);
          
            mode=0;
            k=42;
            
        }

else{
     
      k=42;
       myPID.Compute();
       myPID1.Compute();

      

}
}
  
else if(k!=35){ 

  myPID.Compute();
 // main logic is missing

//To get Complete Code Go to my Pateron Page 

//
  lcd.print(t);
  lcd.print(" > ");
  lcd.print(setPoint);
  delay(2000);  
  lcd.init();
  k = keypad.getKey();  
  Serial.println("PID F : B");
  Serial.print(Output1);
  Serial.print(" :");
Serial.println(Output);
      delay(1000);      
  }
   
  else if(t<setPoint){
 
       Serial.println("PID F : B");
  Serial.print(Output1);
  Serial.print(" :");
Serial.println(Output);
      delay(1000);
}

else{
  k=keypad.getKey();
 analogWrite(pwmb,0); 
 analogWrite(pwm, 0); 
}
 

}
}


int computeMode(){
 
//To get Complete Code Go to my Pateron Page 


return value;
}
