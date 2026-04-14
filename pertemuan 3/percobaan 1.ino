const int PIN_LED = 12;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();

    if (data == '1') {
      digitalWrite(PIN_LED, HIGH);
    } 
    else if (data == '0') {
      digitalWrite(PIN_LED, LOW);
    }
  }
}
