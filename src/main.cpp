#include <Arduino.h>

const float trigger = 2;
const float echo = 3;
const int buzzer = 6;
float time_taken, dist, dist_buff, sum ;
float ar_measure[2];


// put function declarations here:
float get_distance(float, float);
void set_tone(int);

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  float abstand = get_distance(trigger, echo);
  Serial.println(abstand);
  if (abstand > 55)
  {
    noTone(buzzer);
  }
  else if (abstand > 15 && abstand < 25)
  {
    set_tone(100);
  }
  else if (abstand >= 25 && abstand < 35)
  {
    set_tone(200);
  }
  else if (abstand >= 35 && abstand < 45)
  {
    set_tone(300);
  }
  else if (abstand >= 45 && abstand < 55)
  {
    set_tone(400);
  }
  else if(abstand < 15) {
    tone(buzzer, 500);
  }
}


// put function definitions here:
float get_distance(float trigger_f, float echo_f) {
  for(int i = 0; i<2;i++){

    digitalWrite(trigger, LOW);
    delay(2);
    digitalWrite(trigger, HIGH);
    delay(10);
    digitalWrite(trigger, LOW);
    time_taken = pulseIn(echo, HIGH);
    dist_buff = time_taken*0.034/2;
    ar_measure[i] = dist_buff;
    sum = ar_measure[0]+ar_measure[1];
    delay(5);
  }
  dist = sum/2;
  return dist;
}

void set_tone(int tone_f){
    tone(buzzer, 500);
    delay(tone_f);
    noTone(buzzer);
    delay(tone_f);
}