#include <avr/io.h>

#define r_dir 11 //A4988 right direction
#define r_step 10 //A4988 right setp (PWM)
#define l_step 9 //A4988 left setp (PWM)
#define l_dir 8 //A4988 left direction
#define led_b 7 //blue
#define led_y 6 //yellow
#define led_g 5 //green

#define max_frq 5813
#define max_speed 100

#define CW 0 //前進
#define CCW 1 //後進

int dir = 1;
bool st = true;
unsigned long time_temp;

unsigned int frq = 5813; // 周波数
float duty = 0.5; // 指定したいデューティ比
unsigned int prd = 86; //周期(us)

void setup() {
  pinMode(r_dir, OUTPUT);
  pinMode(r_step, OUTPUT);
  pinMode(l_step, OUTPUT);
  pinMode(l_dir, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_g, OUTPUT);

  time_temp = micros();

  // モード指定
  TCCR1A = 0b10100000;
  TCCR1B = 0b00010010;
}

void loop() {
  digitalWrite(led_b, HIGH);
  for (int i=0; i<100; i++)
  {
    drive_stepper_motor(CCW, i);
    delay(5);
  }
  for (int i=100; i>0; i--)
  {
    drive_stepper_motor(CCW, i);
    delay(5);
  }
  digitalWrite(led_b, LOW);
  digitalWrite(led_g, HIGH);
  for (int i=0; i<100; i++)
  {
    drive_stepper_motor(CW, i);
    delay(5);
  }
  for (int i=100; i>0; i--)
  {
    drive_stepper_motor(CW, i);
    delay(5);
  }
  digitalWrite(led_g, LOW);
  /*
  if((micros() - time_temp) >= prd)
  {
    drive_stepper_motor();
    time_temp = micros();
  }*/
}
