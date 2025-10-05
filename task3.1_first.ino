void setup() {
  DDRB = 0b00100000; // Set PB5 (pin 13) as OUTPUT
}

void loop() {
  // 1) Direct assignment
  PORTB = 0b00100000;   // LED ON
  delay(500);
  PORTB = 0b00000000;            // LED OFF
  delay(500);
}