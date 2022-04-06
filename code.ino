                                                                                                                                                                                 #define enA 5
#define enB 6
#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define T_right 2
#define T_left 4
#define T_center 3

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(T_right, INPUT);
  pinMode(T_left, INPUT);
  pinMode(T_center, INPUT);
  // Set initial rotation direction

}
void loop() {

  
  int potValue = analogRead(A0); // read from potentiometer 
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // map the potentiometer value from 0 to 255
  analogWrite(enA, 255); // send PWM signal to L298N Enable pin
  analogWrite(enB, 255); // send PWM signal to L298N Enable pin
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
  delay(20);
  
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
 if (digitalRead(T_center)) {

    forward();

    if (digitalRead(T_right)) {
       left();
    }
    if (digitalRead(T_left)) {
     right();
    }

    if (digitalRead(T_right) && !digitalRead(T_left)) {
     stop();
    }
    
 } else if (digitalRead(T_right))
   {
     left();
   } else if (digitalRead(T_left)) {
     right();
   } else {
   stop();  
   }
   
 
 
  

}

void forward() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
