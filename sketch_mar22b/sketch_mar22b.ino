uint16_t OUTPUT_VOLTAGE = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  while(Serial.available() == 0) {
//    Serial.print("available: \t");
//    Serial.println(Serial.available());
    }
  OUTPUT_VOLTAGE = Serial.parseInt();
  Serial.println(OUTPUT_VOLTAGE);
  int dummy = Serial.parseInt();
  Serial.println(dummy);
  delay(500);
}
