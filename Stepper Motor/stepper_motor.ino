#include <Stepper.h>

const int StepsPerRevolution = 1000;
const int Speed = 120;
const int dir_pin = 2;
const int stp_pin = 3;

Stepper motor(StepsPerRevolution, stp_pin, dir_pin);  

void setup() {
  Serial.begin(9600);
  motor.setSpeed(Speed);
}

void loop() {
  if (Serial.available() > 0 ){
    int data = Serial.parseInt();
    
    // Movimiento
    if (data > 10000 && data < 20000) { 
      int steps = data - 10000;
      motor.step(steps); 
    }

    //Ajustar Velocidad
    else if (data > 20000 && data < 30000){
      int speed = data - 20000;
      motor.setSpeed(speed);
      Serial.println("velocidad");
    }
  }
}
