#define t0 33
#define t1 36
#define t2 98

#define pinOne 8    //PWM pins S1
#define pinTwo 9    //S2
#define pinThree 10 //S3
#define pinFour 11  //S4
#define pinFive 12  //S5
#define pinSix 13   //S6


//
const uint16_t t0_load = 155;
const uint16_t t0_compA = 163;
const uint16_t t0_compB = 246;

const uint16_t t1_load = 59136;
const uint16_t t1_compA = 61808;
const uint16_t t1_compB = 62864;

const uint16_t t2_load = 155;
const uint16_t t2_compA = 172;
const uint16_t t2_compB = 237;


int sector = 1;

void setup() {
  DDRB = B00111111;   //Output mode
  PORTB = B00000000;  // digital pins -,-,13,12,11,10,9,8
  Serial.begin(9600);

  //  Reset Timer1 Control RegA
  TCCR1A = 0;
  TCCR1B = 0;

  //   CTC mode
  TCCR1B &= ~(1 << WGM13);
  TCCR1B &= (1 << WGM12);

  //  Set to prescaler
  bitSet(TCCR1B, CS10);
  //  TCCR1B &= ~(1 << CS12);
  //  TCCR1B &= ~(1 << CS11);
  //  TCCR1B |= (1 << CS10);

  //  Reset Timer1 and set compare value
  TCNT1 = t1_load;
  OCR1A = t1_compA;
  OCR1B = t1_compB;

  bitSet(TIMSK1, 1);      //TC1 Compare Match A interrupt is enabled
  bitSet(TIMSK1, 2);      //TC1 Compare Match B interrupt is enabled
  bitSet(TIMSK1, TOIE1);  // enable Timer1 overflow interrupt:

  //  #### Timer0

  //set timer0
  TCCR0A = 0;// set entire TCCR0A register to 0
  TCCR0B = 0;// same for TCCR0B

  TCNT0  = t0_load;//initialize counter value to 0
  OCR0A = t0_compA;
  OCR0A = t0_compB;

  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);

  // enable timer compare interrupt
  bitSet(TIMSK0, 1);      //TC1 Compare Match A interrupt is enabled
  bitSet(TIMSK0, 2);      //TC1 Compare Match B interrupt is enabled
  //  bitSet(TIMSK0, TOIE0);  // enable Timer1 overflow interrupt:

  //  #### Timer2
  //set timer2
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B

  TCNT2  = t2_load;//initialize counter value to 0

  // set compare match register
  OCR2A = t2_compA;
  OCR2B = t2_compB;

  // turn on CTC mode
  //  TCCR2A |= (1 << WGM21);

  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS22);  // Set CS#2 bit for 64 prescaler for timer 2

  // enable timer compare interrupt
  bitSet(TIMSK2, 1);      //TC1 Compare Match A interrupt is enabled
  bitSet(TIMSK2, 2);      //TC1 Compare Match B interrupt is enabled
  //  bitSet(TIMSK2, TOIE2);  // enable Timer1 overflow interrupt:

  //  enable global interrupts
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (sector == 6) {
    sector = 1;
  }
}

ISR(TIMER1_COMPA_vect) {
  //  Serial.print("COMPA:  ");
  //  Serial.println(micros());
  bitSet(PORTB, 0);
}

ISR(TIMER1_COMPB_vect) {
  //  Serial.print("COMPB:  ");
  //  Serial.println(micros());
  bitClear(PORTB, 0);
}

ISR(TIMER1_OVF_vect) {      // interrupt overflow routine
  // preload timer
  //  Serial.print("OVF:    ");
  //  Serial.println(micros());
  //  Serial.print("SECTOR:");
  //  Serial.println(sector);
  //  Serial.println("");
  sector += 1;
  TCNT0 = t0_load;
  TCNT1 = t1_load;
  TCNT2 = t2_load;
}

ISR(TIMER0_COMPA_vect) {
  //    Serial.print("COMPA:  ");
  //    Serial.println(micros());
  bitSet(PORTB, 1);
}

ISR(TIMER0_COMPB_vect) {
  //    Serial.print("COMPB:  ");
  //    Serial.println(micros());
  bitClear(PORTB, 1);
}

ISR(TIMER2_COMPA_vect) {
  //  Serial.print("COMPA:  ");
  //  Serial.println(micros());
  bitSet(PORTB, 2);
}

ISR(TIMER2_COMPB_vect) {
  //  Serial.print("COMPB:  ");
  //  Serial.println(micros());
  bitClear(PORTB, 2);
}


void sectorOneOn() {
  //  Serial.print("SectorOneOn: ");
  //  Serial.println(millis());
  //  PORTB = B00100011;
}
void sectorOneComp() {}
//
void sectorTwoOn() {}
void sectorTwoComp() {}
//
void sectorThreeOn() {}
void sectorThreeComp() {}
//
void sectorFourOn() {}
void sectorFourComp() {}
//
void sectorFiveOn() {}
void sectorFiveComp() {}
//
void sectorSixOn() {}
void sectorSixComp() {}
