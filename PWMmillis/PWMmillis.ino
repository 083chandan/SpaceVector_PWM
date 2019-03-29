
const uint16_t t_load = 40536;

const uint16_t t1_compA = 42598;
const uint16_t t1_compB = 63473;

const uint16_t t3_compA = 44848;
const uint16_t t3_compB = 61223;

const uint16_t t4_compA = 50973;
const uint16_t t4_compB = 55093;

int sector = 1;

void setup() {
  DDRB = B00111111;   //Output mode
  PORTB = B00000000;  // digital pins -,-,13,12,11,10,9,8
  Serial.begin(9600);

  //  ***** Timer 1 *****
  //  Reset Timer1 Control RegA
  TCCR1A = 0;
  TCCR1B = 0;

  //  Set to prescaler
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);

  //  Reset Timer1 and set compare value
  TCNT1 = t_load;
  OCR1A = t1_compA;
  OCR1B = t1_compB;

  bitSet(TIMSK1, 1);      //TC1 Compare Match A interrupt is enabled
  bitSet(TIMSK1, 2);      //TC1 Compare Match B interrupt is enabled
  bitSet(TIMSK1, TOIE1);  // enable Timer1 overflow interrupt:

  //  ***** Timer 3 *****
  //  Reset Timer3 Control Reg
  TCCR3A = 0;
  TCCR3B = 0;

  //  Set to prescaler
  TCCR3B |= (1 << CS32);
  TCCR3B &= ~(1 << CS31);
  TCCR3B &= ~(1 << CS30);

  //  Reset Timer3 and set compare value
  TCNT3 = t_load;
  OCR3A = t3_compA;
  OCR3B = t3_compB;

  bitSet(TIMSK3, 1);      //TC3 Compare Match A interrupt is enabled
  bitSet(TIMSK3, 2);      //TC3 Compare Match B interrupt is enabled
  bitSet(TIMSK3, TOIE3);  // enable Timer3 overflow interrupt:


  //  ***** Timer 4 *****
  //  Reset Timer4 Control Reg
  TCCR4A = 0;
  TCCR4B = 0;

  //  Set to prescaler
  TCCR4B |= (1 << CS42);
  TCCR4B &= ~(1 << CS41);
  TCCR4B &= ~(1 << CS40);

  //  Reset Timer4 and set compare value
  TCNT4 = t_load;
  OCR4A = t4_compA;
  OCR4B = t4_compB;

  bitSet(TIMSK4, 1);      //TC4 Compare Match A interrupt is enabled
  bitSet(TIMSK4, 2);      //TC4 Compare Match B interrupt is enabled
  bitSet(TIMSK4, TOIE4);  // enable Timer1 overflow interrupt:

  //  enable global interrupts
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (sector == 7) {
    sector = 1;
  }
  //  uncomment this for Waveforms on serial plotter
  //    Serial.print(bitRead(PORTB, 0) + 7.5);
  //    Serial.print(',');
  //    Serial.print(bitRead(PORTB, 1) + 6);
  //    Serial.print(',');
  //    Serial.print(bitRead(PORTB, 2) + 4.5);
  //    Serial.print(',');
  //    Serial.print(bitRead(PORTB, 3) + 3);
  //    Serial.print(',');
  //    Serial.print(bitRead(PORTB, 4) + 1.5);
  //    Serial.print(',');
  //    Serial.println(bitRead(PORTB, 5));
}

ISR(TIMER1_COMPA_vect) {
  //  Serial.print("TIMER1 COMPA:  ");
  //  Serial.println(millis());
  switch (sector) {
    case 1:
      bitSet(PORTB, 0); //S1
      bitClear(PORTB, 3); //S4
      break;
    case 2:
      bitSet(PORTB, 1); //S3
      bitClear(PORTB, 4); //S6
      break;
    case 3:
      bitSet(PORTB, 1); //S3
      bitClear(PORTB, 4); //S6
      break;
    case 4:
      bitSet(PORTB, 2); //S5
      bitClear(PORTB, 5); //S2
      break;
    case 5:
      bitSet(PORTB, 2); //S5
      bitClear(PORTB, 5); //S2
      break;
    case 6:
      bitSet(PORTB, 0); //S1
      bitClear(PORTB, 3); //S4
      break;
  }
}

ISR(TIMER1_COMPB_vect) {
  //  Serial.print("TIMER1 COMPB:  ");
  //  Serial.println(millis());
  switch (sector) {
    case 1:
      bitClear(PORTB, 0); //S1
      bitSet(PORTB, 3); //S4
      break;
    case 2:
      bitClear(PORTB, 1); //S3
      bitSet(PORTB, 4); //S6
      break;
    case 3:
      bitClear(PORTB, 1); //S3
      bitSet(PORTB, 4); //S6
      break;
    case 4:
      bitClear(PORTB, 2); //S5
      bitSet(PORTB, 5); //S2
      break;
    case 5:
      bitClear(PORTB, 2); //S5
      bitSet(PORTB, 5); //S2
      break;
    case 6:
      bitClear(PORTB, 0); //S1
      bitSet(PORTB, 3); //S4
      break;
  }
}

ISR(TIMER1_OVF_vect) {      // interrupt overflow routine
  // preload timer
  //  Serial.print("TIMER1 OVF:    ");
  //  Serial.println(millis());
  //  Serial.print("SECTOR:");
  //  Serial.println(sector);
  //  Serial.println("");
  sector += 1;
  TCNT1 = t_load;
}

ISR(TIMER3_COMPA_vect) {
  //  Serial.print("TIMER3 COMPA:  ");
  //  Serial.println(millis());
  switch (sector) {
    case 1:
      bitSet(PORTB, 1); //S3
      bitClear(PORTB, 4); //S6
      break;
    case 2:
      bitSet(PORTB, 0); //S1
      bitClear(PORTB, 3); //S4
      break;
    case 3:
      bitSet(PORTB, 2); //S5
      bitClear(PORTB, 5); //S2
      break;
    case 4:
      bitSet(PORTB, 1); //S3
      bitClear(PORTB, 4); //S6
      break;
    case 5:
      bitSet(PORTB, 0); //S1
      bitClear(PORTB, 3); //S4
      break;
    case 6:
      bitSet(PORTB, 2); //S5
      bitClear(PORTB, 5); //S2
      break;
  }
}

ISR(TIMER3_COMPB_vect) {
  //  Serial.print("TIMER3 COMPB:  ");
  //  Serial.println(millis());
  switch (sector) {
    case 1:
      bitClear(PORTB, 1); //S3
      bitSet(PORTB, 4); //S6
      break;
    case 2:
      bitClear(PORTB, 0); //S1
      bitSet(PORTB, 3); //S4
      break;
    case 3:
      bitClear(PORTB, 2); //S5
      bitSet(PORTB, 5); //S2
      break;
    case 4:
      bitClear(PORTB, 1); //S3
      bitSet(PORTB, 4); //S6
      break;
    case 5:
      bitClear(PORTB, 0); //S1
      bitSet(PORTB, 3); //S4
      break;
    case 6:
      bitClear(PORTB, 2); //S5
      bitSet(PORTB, 5); //S2
      break;
  }
}

ISR(TIMER3_OVF_vect) {      // interrupt overflow routine
  // preload timer
  //  Serial.print("TIMER3 OVF:    ");
  //  Serial.println(millis());
  //  Serial.print("SECTOR:");
  //  Serial.println(sector);
  //  Serial.println("");
  TCNT3 = t_load;
}

ISR(TIMER4_COMPA_vect) {
  //  Serial.print("TIMER4 COMPA:  ");
  //  Serial.println(millis());
  switch (sector) {
    case 1:
      bitSet(PORTB, 2); //S5
      bitClear(PORTB, 5); //S2
      break;
    case 2:
      bitSet(PORTB, 2); //S5
      bitClear(PORTB, 5); //S2
      break;
    case 3:
      bitSet(PORTB, 0); //S1
      bitClear(PORTB, 3); //S4
      break;
    case 4:
      bitSet(PORTB, 0); //S1
      bitClear(PORTB, 3); //S4
      break;
    case 5:
      bitSet(PORTB, 1); //S3
      bitClear(PORTB, 4); //S6
      break;
    case 6:
      bitSet(PORTB, 1); //S3
      bitClear(PORTB, 4); //S6
      break;
  }
}

ISR(TIMER4_COMPB_vect) {
  //  Serial.print("TIMER4 COMPB:  ");
  //  Serial.println(millis());
  switch (sector) {
    case 1:
      bitClear(PORTB, 2); //S5
      bitSet(PORTB, 5); //S2
      break;
    case 2:
      bitClear(PORTB, 2); //S5
      bitSet(PORTB, 5); //S2
      break;
    case 3:
      bitClear(PORTB, 0); //S1
      bitSet(PORTB, 3); //S4
      break;
    case 4:
      bitClear(PORTB, 0); //S1
      bitSet(PORTB, 3); //S4
      break;
    case 5:
      bitClear(PORTB, 1); //S3
      bitSet(PORTB, 4); //S6
      break;
    case 6:
      bitClear(PORTB, 1); //S3
      bitSet(PORTB, 4); //S6
      break;
  }
}

ISR(TIMER4_OVF_vect) {      // interrupt overflow routine
  // preload timer
  //  Serial.print("TIMER4 OVF:    ");
  //  Serial.println(millis());
  //  Serial.print("SECTOR:");
  //  Serial.println(sector);
  //  Serial.println("");
  TCNT4 = t_load;
}
