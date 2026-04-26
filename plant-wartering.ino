/**
 * plant-watering.ino - 
 *
 *
 *
 */

#include <math.h>
#include <SparkFun_TB6612.h>

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;

// Motor: pins for all inputs, 
// keep in mind the PWM defines must be on PWM pins
#define PWMA 2
#define AIN2 3
#define AIN1 4
#define STBY 5

// Moisture sensor: what values are considered
// dry and what values are considered wet
/**
 Moisture sensor

 Some values: 

  - sensor on air: 840
  - sensor on somewhat wet sand: 818
  - sensor on wet ground: 530
  - sensor on very wet sand: 570
  - sensor on very much wet ground: 550 

  Let's say that, on average, these are the values we are going 
  to use to say that a given plan has this soil dry or 
  watered: 

  - value for "dry": > 800
  - value for "wet": < 550



*/
#define MOISTURE_SENSOR A0
#define DRY_VALUE 800
#define WET_VALUE 550

/*
 * configuration dips
 */
#define SW1 12
#define SW2 11
#define SW3 10
#define SW4 9

int moistureModes[4] = { 700, 680, 660, 640 };
// the larger the pot, more seconds it will need 
// to properly water it
int wateringSeconds[4] = {2, 4, 8, 16};

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

int readMoisture( int sensorNumber ){
  return analogRead(A0);
}


int readPinValues( int s1, int s2 ){
  int v1 = digitalRead(s1) == LOW ? 1 : 0;
  int v2 = digitalRead(s2) == LOW ? 1 : 0;

  return (v2 << 1) | v1;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Nano watering system");
  // Configure pins
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop....");
  int moistureReading = readMoisture(MOISTURE_SENSOR);
  int wateringMode = readPinValues( SW1, SW2 );
  if( moistureReading > moistureModes[wateringMode] ){
    int secondsToWater = wateringSeconds[readPinValues( SW3, SW4 )]; 
    Serial.print("Because the moisture reading is ");
    Serial.print( moistureReading );
    Serial.print(" and the desired humidity is ");
    Serial.print( moistureModes[wateringMode] );
    Serial.print( " we are firing the watering for " );
    Serial.print(secondsToWater);
    Serial.println(" seconds");
    motor1.drive(100, secondsToWater * 1000 );
    motor1.brake();
  }else{
    Serial.print("No need to water. Moisture: ");
    Serial.println( moistureReading );
    Serial.print("Desired humidity: ");
    Serial.println( moistureModes[wateringMode] );    
  }
  // FORDEBUG
  delay(3000);
  //delay( 3600 * 1000 );
}

