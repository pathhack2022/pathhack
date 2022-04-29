const int moterPin = 9;
float temperature;  
int reading;  
int lm35Pin = A0;



void setup() {
  Serial.begin(9600);
  pinMode(moterPin,OUTPUT);
  analogReference(INTERNAL);
}

void moter(){
  analogWrite(moterPin,500);
}
void tmper(){
    reading = analogRead(lm35Pin);
    temperature = reading / 9.31;
    
    Serial.println(temperature);
    delay(1000);
}

void loop() {
   
   
}
