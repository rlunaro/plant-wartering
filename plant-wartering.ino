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
const int PWMA = 2;
const int AIN2 = 3;
const int AIN1 = 4;
const int STBY = 5;

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

const int BUTTON_PIN = 2;

int moistureModes[4] = { 700, 680, 660, 640 };
// the larger the pot, more seconds it will need 
// to properly water it
int wateringSeconds[4] = {2, 4, 8, 16};

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

int readMoisture( int sensorNumber ){
  return analogRead(A0);
}

volatile long int pressed = 0L;

void onButtonPressed() {
  //estadoBoton = digitalRead(PIN_BOTON);
  pressed++;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Nano watering system");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(
      digitalPinToInterrupt(BUTTON_PIN),
      onButtonPressed,
      CHANGE
    );  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop....");
  int moistureReading = readMoisture(MOISTURE_SENSOR);
  // FORDEBUG
  delay(5000);
  //delay( 3600 * 1000 );
}


