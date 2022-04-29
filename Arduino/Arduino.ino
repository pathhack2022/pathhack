#include<Wire.h>
#include <LiquidCrystal_I2C.h>

const int moterPin1 = 6,moterPin2 = 5,lm35Pin = A0,TRIG = 13,ECHO = 12;
float temperature;  
int reading,value = 0;
long duration,cm;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(moterPin1,OUTPUT);
  pinMode(moterPin2,OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  analogReference(INTERNAL);

 lcd.init();
 // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();
}


void tmper(){
    reading = analogRead(lm35Pin);
    temperature = reading / 9.31;

    temperature -= 45;
    if(temperature <= 20 || temperature >= 30) temperature = 22.6;
    Serial.println(temperature);
  if(temperature >= 20){

      if(cm > 20){
        digitalWrite(2,HIGH);
        delay(500);
        digitalWrite(2,LOW); 
        delay(500);    
      }
    
   
    lcd.setCursor(0,0);           // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("   Very Hot!!  ");       // 문구를 출력합니다.
  
  // 랜덤 값이 1이라면 아래의 조건을 실행합니다.
    lcd.setCursor(0,1);           // 1번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("     ");
    lcd.print(temperature);     // 문구를 출력합니다.
  
  // 1초간 대기합니다.
    delay(100);
  // LCD의 모든 내용을 삭제합니다.
    }
    else{
       lcd.setCursor(0,0);           // 0번째 줄 0번째 셀부터 입력하게 합니다.
       lcd.print("    good day  ");       // 문구를 출력합니다.
  
     // 랜덤 값이 1이라면 아래의 조건을 실행합니다.
       lcd.setCursor(0,1);           // 1번째 줄 0번째 셀부터 입력하게 합니다.
       lcd.print("     ");
       lcd.print(temperature);     // 문구를 출력합니다.
    }
   delay(100);
}

void chomfa(){
   digitalWrite (TRIG, HIGH);  // 트리거 핀 HIGH 펄스
   delayMicroseconds (10);        // 10 μs 지연
   digitalWrite (TRIG, LOW);   // 8 Cycle 초음파 출력

   duration = pulseIn (ECHO, HIGH); // HIGH가 유지된 시간 반환
   cm = duration / 58.0; // 거리 = 왕복에 걸린 시간 ÷ 58

   if(cm <= 20){
        digitalWrite(2,HIGH);
        analogWrite(moterPin1,0);
        analogWrite(moterPin2,0);
        delay(500);
   }
   else{
      analogWrite(moterPin1,500);
      analogWrite(moterPin2,500);
      digitalWrite(2,LOW);
      delay(500);
   }

   Serial.print ("distance: ");
   Serial.print (cm);
   Serial.println (" cm");
   
}

void loop() {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  chomfa();
  tmper();
}
