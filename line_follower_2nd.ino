#define ir_1 11
#define ir_2 10

#define enA 9     // Right motor enable
#define in1 8
#define in2 7

#define enB 3     // Left motor enable
#define in3 5
#define in4 4

void setup() {
  Serial.begin(9600);
  pinMode(11,INPUT);  //right sensor
  pinMode(10,INPUT);  //left sensor 
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(8,OUTPUT); // right motor
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT); // left motor
  pinMode(4,OUTPUT);

}

void loop() {
  int Right = digitalRead(ir_1);
  int Left = digitalRead(ir_2);

   // Case 1: both sensors on line (black)
  if (Right == LOW && Left == LOW) {
    forward();
  }
  // Case 2: Right off, Left on -> turn right
  else if (Right == HIGH && Left == LOW) {
    turnRight();
  }
  // Case 3: Right on, Left off -> turn left
  else if (Right == LOW && Left == HIGH) {
    turnLeft();
  }
  // Case 4: both off -> stop
  else {
    stopRobot();
  }

}
void forward() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
}

void turnRight() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
}

void turnLeft() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
}

void stopRobot() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}


