#include<Servo.h>
Servo servo;

const int moterPin = 9,ServoPin = 2,lm35Pin = A0,TRIG = 13,ECHO = 12;
float temperature;  
int reading,value = 0;
long duration,cm;

void setup() {
  Serial.begin(9600);
  pinMode(moterPin,OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  analogReference(INTERNAL);
  servo.attach(2);
}

void dcmoter(){ //dc모터 제어
  analogWrite(moterPin,500);
}
void tmper(){   //온도센서 제어
    reading = analogRead(lm35Pin);
    temperature = reading / 9.31;
    
    Serial.println(temperature);
    delay(1000);
}

void sv(){    //서버모터 제어
    for(int i=0;i<180;i+=45){
      value = i;
      servo.write(value), delay(500);
    }
}

void chomfa(){
   digitalWrite (TRIG, HIGH);  // 트리거 핀 HIGH 펄스
   delayMicroseconds (10);        // 10 μs 지연
   digitalWrite (TRIG, LOW);   // 8 Cycle 초음파 출력

   duration = pulseIn (ECHO, HIGH); // HIGH가 유지된 시간 반환
   cm = duration / 58.0; // 거리 = 왕복에 걸린 시간 ÷ 58

   Serial.print ("distance: ");
   Serial.print (cm);
   Serial.println (" cm");
   delay (1000);
}

void loop() {




   
}
