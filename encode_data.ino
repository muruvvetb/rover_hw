// Motor Front_left connections
int en_fl = 9;
int in1_fl = 8;
int in2_fl = 7;
// Motor Front_right connections
int en_fr = 3;
int in3_fr = 5;
int in4_fr = 4;
//Motor Back_left connections
int en_bl = 6;
int in1_bl = 2;
int in2_bl = 12;
//Motor Back_right connections
int en_br = 11;
int in3_br = 13;
int in4_br = 10;

String first = "s";
String last = "f";
String str;

void setup()
{
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  
  pinMode(en_fl, OUTPUT);
  pinMode(in1_fl, OUTPUT);
  pinMode(in2_fl, OUTPUT);
  
  pinMode(en_fr, OUTPUT);
  pinMode(in3_fr, OUTPUT);
  pinMode(in4_fr, OUTPUT);
  
  pinMode(en_bl, OUTPUT);
  pinMode(in1_bl, OUTPUT);
  pinMode(in2_bl, OUTPUT);
  
  pinMode(en_br, OUTPUT);
  pinMode(in3_br, OUTPUT);
  pinMode(in4_br, OUTPUT);

}

void loop()
{ 
  direction_speed_Control(first, last);
  delay(1000);
}

void direction_speed_Control(String f, String l)
{
  
  int directions[4];
  int speeds[4];
  int direction, speed;
  str = f;
  
  for(int i = 0; i < 4; i++)
  {
    direction = random(2);
    speed = random(256);

    directions[i] = direction;
    speeds[i] = speed;
    str = str + String(direction) + String(speed);
  }

  str += last;

  Serial.println(str);
 
  turnon_motor(in1_fl, in2_fl, speeds[0], directions[0], en_fl);
  turnon_motor(in3_fr, in4_fr, speeds[1], directions[1], en_fr);
  turnon_motor(in1_bl, in2_bl, speeds[2], directions[2], en_bl);
  turnon_motor(in3_br, in4_br, speeds[3], directions[3], en_br);

}
void turnon_motor(int in1, int in2, int speed, int direction, int en){
  
  if(direction == 1){ // forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);    
  }
  else{ //backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  
  analogWrite(en, speed);
}

















