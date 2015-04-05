//continuous servo sm-s4315R is being used as the murukku maker(indian snack)
//rotatory enabler. The motor should be able to rotate both ways. 
//inital plan
// 5 different speeds able to be selected with a switch or rotatory encoder
//possibly stop after dispersing the right amount of dough

#include <Servo.h>
const int forward = 1;      //button to make the motor rotate clockwise
const int pause = 2;        //button to make the motor stop
const int backward = 3;     //button to make the motor rotate counterclockwise
int forwardpress = 0;       //hold the state of the forward button
int pausepress = 0;        //holds the state of the reverse button
int backwardpress = 0;      //holds the state of the backward button
int state = 0;              //holds the value of the most recent button press
Servo servo;

void setup(){
    pinMode(forward, INPUT);
    pinMode(pause, INPUT);
    pinMode(backward, INPUT);
    servo.attach(8);    //connect servo to digital pin 9
   Serial.begin(9600);
}

void loop()                                  // Main loop auto-repeats
{   
  forwardpress = digitalRead(forward);
  pausepress   = digitalRead(pause);
  backwardpress = digitalRead(backward);

  if (forwardpress == HIGH) {     
    state = 1;
     Serial.println(state);
  } 
  else if(pause ==HIGH){
    state = 0;
    Serial.println(state);
  }
  else if(backwardpress ==HIGH){
    state = -1;
    Serial.println(state);
  }
  if(state ==1){
    //servo.writeMicroseconds(1300);
    delay(10);
    servo.detach();
  }
  else if(state ==0){
   // servo.writeMicroseconds(1500);
    delay(10);
    servo.detach();
  }
  else if(state==-1){
   // servo.writeMicroseconds(1800);
   servo.detach();
  }
}
    
  

