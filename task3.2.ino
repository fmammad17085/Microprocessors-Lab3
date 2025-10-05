void setup() {
  Serial.begin(9600);

  uint8_t sum;    // total sum is stored
  uint8_t cnt;    // counter 1..10
  uint8_t limit;  // = 10 

  asm volatile(
    "clr %[sum]        \n\t"   // sum = 0
    "ldi %[cnt], 1     \n\t"   // cnt = 1
    "ldi %[limit], 10  \n\t"   // limit = 10

    "loop%=:           \n\t"
    "add %[sum], %[cnt]\n\t"   // sum += cnt
    "cp  %[cnt], %[limit]\n\t" // compare cnt with limit
    "brne cont%=       \n\t"   // if cnt != limit → continue
    "rjmp end%=        \n\t"   // else finished

    "cont%=:           \n\t"
    "inc %[cnt]        \n\t"   // cnt++
    "rjmp loop%=       \n\t"   // repeat

    "end%=:            \n\t"
    : [sum]   "=r"(sum),   // output: result of summation (1..10)
      [cnt]   "=r"(cnt),   // output: counter value at loop end
      [limit] "=r"(limit)  // output: limit value (10)
    :
    : "cc"
  );

  Serial.print("Sum = ");
  Serial.print(sum);
  Serial.print(" (0x");
  Serial.print(sum, HEX);
  Serial.println(")");
}

void loop() {
  // nothing
}
