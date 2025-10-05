void setup() {
  DDRB = (1 << PB5);  // same as 0b00100000
}

void loop() {
  PORTB = (1 << PB5);   // LED ON
  delay(500);
  PORTB = (0 << PB5);   // LED OFF
  delay(500);
}
