# Space Vector PWM generation using Atmega 2560

(Arduino Mega) 

Using Timer 1, Timer 3, Timer 4 and Timer 5 in the microcontroller to generate 6 varying PWMs

**PWMmicros:** PWM period is in **Micro Seconds**. Uses 256 as prescaler for the counter.

**PWMmillis:** PWM period is in **Milli Seconds**. Uses 1 as prescaler for the counter.

> Both PWMmicros and PWMmillis generate same waveform with timing change.

**Counter calculation:**

counter = (frequency * time)/prescaler

> Default prescaler values: **1**, 8, 64, 256, 1024

**Max counter Values**

* 16Bit: 65536
* 8Bit: 255
  <br>
  <br>
  <br>



|   Pin No.   |  Waveform no.  |
| :---------: | :------------: |
| PORTB0 (53) | S1 (High side) |
| PORTB1 (52) | S3 (High side) |
| PORTB2 (51) | S5 (High side) |
| PORTB3 (50) | S4 (Low side)  |
| PORTB4 (10) | S6 (Low side)  |
| PORTB5 (11) | S2 (Low side)  |



![img](https://github.com/083chandan/SpaceVector_PWM/blob/master/refrences/Timing%20diagram/Waveforms%20Timings.png)

![1553932476551](https://github.com/083chandan/SpaceVector_PWM/blob/master/refrences/Sector.png)

![img](http://1.bp.blogspot.com/-Pp_9dZX434A/UeaA5XiMEuI/AAAAAAAAAIY/tNYQzwg6n1I/s280/pattern+sectors.jpg)

### OUTPUT

![alt text](https://github.com/083chandan/svm/blob/master/refrences/Generated%20SVM/All%20Sectors%20and%20PWM.PNG)
<br>
<br>
<br>

### REF
* SPACE VECTOR PWM INVERTER, JIN-WOO JUNG <br>
* http://electrotech4u.blogspot.com/2011/07/implementation-of-space-vector.html?m=1
