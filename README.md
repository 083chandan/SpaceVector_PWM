# Space Vector PWM generation using Atmega 2560

(Arduino Mega) <br>
Using Timer 1, Timer 3 and Timer 4 in the microcontroller to generate 6 PWMs

**PWMmicros:** PWM period is in **Micro Seconds**. <br>
**PWMmillis:** PWM period is in **Milli Seconds**.
> Both PWMmicros and PWMmillis generate same waveform with timing change.

**Counter calculation:** <br>
*counter = (frequency * time)/prescaler* <br>
> Default prescaler values: 1, 8, 64, 256, 1024
<br>

**Max counter Values**
* 16Bit: 65536
* 8Bit: 255
<br>
<br>
<br>

### OUTPUT
![alt text](https://github.com/083chandan/svm/blob/master/refrences/Generated%20SVM/All%20Sectors%20and%20PWM.PNG)
<br>
<br>
<br>

### REF
* SPACE VECTOR PWM INVERTER, JIN-WOO JUNG <br>
* http://electrotech4u.blogspot.com/2011/07/implementation-of-space-vector.html?m=1
