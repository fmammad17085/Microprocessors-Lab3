void setup() {
  DDRB = 0b00100000; // Set PB5 (pin 13) as OUTPUT
}

void loop() {
  PORTB |= 0b00100000;  // LED ON
  delay(500);
  PORTB &= 0b11011111; // LED OFF
  delay(500);
}
