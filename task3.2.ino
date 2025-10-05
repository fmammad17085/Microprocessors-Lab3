void setup() {
  Serial.begin(9600);

  uint8_t sum;    // total sum is stored
  uint8_t cnt;    // counter 1..10
  uint8_t limit;  // = 10 

  asm volatile(
    "clr %[sum]        \n\t"   // set register holding sum = 0
    "ldi %[cnt], 1     \n\t"   // cnt = 1
    "ldi %[limit], 10  \n\t"   // limit = 10

    "loop%=:           \n\t"
    "add %[sum], %[cnt]\n\t"   // sum += cnt
    "cp  %[cnt], %[limit]\n\t" // compare cnt with 10
    "breq end%=        \n\t"   // if cnt == 10, then done
    "inc %[cnt]        \n\t"   // cnt++
    "rjmp loop%=       \n\t"   // repeat

    "end%=:            \n\t"
    : [sum]   "=r"(sum), // output: result of the summation (1..10)
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
