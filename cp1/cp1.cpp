// link do projeto: https://wokwi.com/projects/410212363945925633

#define ledR 13
#define ledY 12
#define ledG 11
#define buzina 10
#define sensorLDR A1 

int gamma = 0.7;
int rl10 = 0.5;

void setup() {
  Serial.begin(115200);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(sensorLDR, INPUT);
  pinMode(buzina, OUTPUT);
}

void loop() {
int analogValue = analogRead(A1);
int sensorValue = analogRead(sensorLDR);
Serial.println(sensorValue);
  if(sensorValue <= 300) {
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  } else if(sensorValue > 300 && sensorValue <= 650) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
    tone(buzina, 1000);
    delay(3000);
    noTone(buzina);  
    delay(3000);  
  } else {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH); 
  }
}