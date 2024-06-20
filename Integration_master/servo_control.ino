void begin_head() { //หันหน้าตรง   face origin
  servo_head.attach(servo_head_pin);
  servo_head.write(100);
  delay(100);
  servo_head.detach();
}
void head_shake(int x, int y) { //ส่ายหัว    turn left and turn right head input x is in the range 0-100 and input y is in the range 100-180
  servo_head.attach(servo_head_pin);
  if ( 0 <= x <= 100) {
    servo_head.write(x);
  }
  delay(200);
  servo_head.write(100);
  delay(200);
  if ( 100 <= y <= 180) {
    servo_head.write(y);
  }
  delay(200);
  servo_head.write(100);
  delay(100);
  servo_head.detach();
}
void head_turnleft(int x) {     //ส่ายหัว ไปทางซ้าย  x คือค่าองศา ตั้งแต่ 0-100  turn left input x is in the range 0-100
  if ( 0 <= x <= 100) {
    servo_head.attach(servo_head_pin);
    servo_head.write(x);
    delay(100);
    servo_head.detach();
  }
}
void head_turnright(int x) {  //ส่ายหัว ไปทางขวา  x คือค่าองศา ตั้งแต่ 100-180  turn Right input x is in the range 100-180
  if ( 100 <= x <= 180) {
    servo_head.attach(servo_head_pin);
    servo_head.write(x);
    delay(100);
    servo_head.detach();
  }
}

void lift_twohand() {            //ยกมือขึ้น 2 มือ  aise both hands
  servo_armRight.attach(servo_armRight_pin);
  servo_armleft.attach(servo_armleft_pin);
  servo_armleft.write(0); //arm right
  servo_armRight.write(180);
  delay(100);
  servo_armleft.detach();
  servo_armRight.detach();
}
void lift_righthand() {         //ยกมือ ขาว ขึ้น  aise Right hand
  servo_armRight.attach(servo_armRight_pin);
  servo_armRight.write(180);
  delay(100);
  servo_armRight.detach();
}
void lift_lefthand() {          //ยกมือ ซ้าย ขึ้น  aise left hand
  servo_armleft.attach(servo_armleft_pin);
  servo_armleft.write(0); //arm right
  delay(100);
  servo_armleft.detach();
}
void begin_twohand() {          //มือสอง มืออยู่ในท่าปกติ origin hand
  servo_armRight.attach(servo_armRight_pin);
  servo_armleft.attach(servo_armleft_pin);
  servo_armleft.write(180); //arm right
  servo_armRight.write(0);
  delay(100);
  servo_armleft.detach();
  servo_armRight.detach();
}
void begin_righthand() {       // มือ ซ้าย อยู่ในท่าปกติ origin Right hand
  servo_armRight.attach(servo_armRight_pin);
  servo_armRight.write(0);
  delay(100);
  servo_armRight.detach();
}
void begin_lefthand() {         // มือ ขวา อยู่ในท่าปกติ origin left hand
  servo_armleft.attach(servo_armleft_pin);
  servo_armleft.write(180); //arm right
  delay(100);
  servo_armleft.detach();
}
