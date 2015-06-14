# include "msp430g2553.h"
// Connect the servo SIGNAL wire to P1.2 through a 1K resistor.
#define MCU_CLOCK			1000000
#define PWM_FREQUENCY		46		// In Hertz, ideally 50Hz.
#define SERVO_STEPS			180		// Maximum amount of steps in degrees (180 is common)
#define SERVO_MIN			650		// The minimum duty cycle for this servo
#define SERVO_MAX			2700	// The maximum duty cycle
unsigned int PWM_Period		= (MCU_CLOCK / PWM_FREQUENCY);	// PWM Period
unsigned int PWM_Duty		= 0;							// %
unsigned int i=0;
//Definition of the notes' frequecies in Hertz.
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_C4_1 260
void delay_ms(unsigned int ms )
{
    unsigned int i;
    for (i = 0; i<= ms; i++)
       __delay_cycles(500); //Built-in function that suspends the execution for 500 cicles
}

void delay_us(unsigned int us )
{
    unsigned int i;
    for (i = 0; i<= us/2; i++)
       __delay_cycles(1);
}

//This function generates the square wave that makes the piezo speaker sound at a determinated frequency.
void beep(unsigned int note, unsigned int duration)
{
    int i;
    long delay = (long)(10000/note);  //This is the semiperiod of each note.
    long time = (long)((duration*100)/(delay*2));  //This is how much time we need to spend on the note.
    for (i=0;i<time;i++)
    {
        P1OUT |= BIT2;     //Set P1.2...
        delay_us(delay);   //...for a semiperiod...
        P1OUT &= ~BIT2;    //...then reset it...
        delay_us(delay);   //...for the other semiperiod.
    }
    delay_ms(20); //Add a little delay to separate the single notes
}
//This is the Imperial March code.
//As you can see, there are lots of beeps at different frequencies and durations, and some delays to separate the various bits of this wonderful song.
void play()
{
    beep(a, 500);
    beep(a, 500);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);

    delay_ms(150);
    //end of first bit

    beep(eH, 500);
    beep(eH, 500);
    beep(eH, 500);
    beep(fH, 350);
    beep(cH, 150);
    beep(gS, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);

    delay_ms(150);
    //end of second bit...

    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 400);
    beep(gSH, 200);
    beep(gH, 200);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);

    delay_ms(250);

    beep(aS, 250);
    beep(dSH, 400);
    beep(dH, 200);
    beep(cSH, 200);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);

    delay_ms(2000);

    beep(f, 125);
    beep(gS, 500);
    beep(f, 375);
    beep(a, 125);
    beep(cH, 520);
    beep(a, 375);
    beep(cH, 135);
    beep(eH, 650);

    //end of third bit... (Though it doesn't play well)
    //let's repeat it

    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 400);
    beep(gSH, 200);
    beep(gH, 200);
    beep(fSH, 100);
    beep(fH, 125);
    beep(fSH, 250);

    delay_ms(250);

    beep(aS, 250);
    beep(dSH, 400);
    beep(dH, 200);
    beep(cSH, 200);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);

    delay_ms(250);

    beep(f, 250);
    beep(gS, 500);
    beep(f, 375);
    beep(cH, 125);
    beep(a, 500);
    beep(f, 375);
    beep(cH, 125);
    beep(a, 650);
    delay_ms(1000);
    //end of the song
}
void main (void){


	 WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	    P1DIR |=0b00000011;
		P2DIR |=0b00001111;
		unsigned int j=0;



		for(j=0;j<2;j++)
			{
				P1OUT &=0x00;
						P2OUT &=0x00;
								for(i=0;i<20000;i++);

								P1OUT ^=0x01;
								for(i=0;i<50000;i++);

								P2OUT ^=0x01;
										for(i=0;i<50000;i++);

										P2OUT ^=0x02;
												for(i=0;i<50000;i++);

												P2OUT ^=0x04;
														for(i=0;i<50000;i++);

														P2OUT ^=0x08;
																for(i=0;i<50000;i++);
			}


		for(j=0;j<3;j++)
				{
					P1OUT &=0x00;
							P2OUT &=0x00;
									for(i=0;i<20000;i++);

									P1OUT ^=0x01;
									for(i=0;i<50000;i++);

									P2OUT ^=0x08;
											for(i=0;i<50000;i++);

											P2OUT ^=0x01;
													for(i=0;i<50000;i++);

													P2OUT ^=0x04;
															for(i=0;i<50000;i++);

															P2OUT ^=0x02;
																	for(i=0;i<50000;i++);
				}



	 WDTCTL = WDTPW + WDTHOLD; //Disable Watchdog Timer
	    P1DIR|=BIT2;              // P1.2 output
	    play();
		delay_ms(2000);      //Add a 2 sec. delay to avoid replaying right after the end.
	unsigned int servo_stepval, servo_stepnow;
	unsigned int servo_lut[ SERVO_STEPS+1 ];
	unsigned int i;
	// Calculate the step value and define the current step, defaults to minimum.
	servo_stepval 	= ( (SERVO_MAX - SERVO_MIN) / SERVO_STEPS );
	servo_stepnow	= SERVO_MIN;
	// Fill up the LUT
	for (i = 0; i< SERVO_STEPS; i++) {
		servo_stepnow += servo_stepval;
		servo_lut[i] = servo_stepnow;
	}
	// Setup the PWM, etc.
	WDTCTL	= WDTPW + WDTHOLD;     // Kill watchdog timer
	TACCTL1	= OUTMOD_7;            // TACCR1 reset/set
	TACTL	= TASSEL_2 + MC_1;     // SMCLK, upmode
	TACCR0	= PWM_Period-1;        // PWM Period
	TACCR1	= PWM_Duty;            // TACCR1 PWM Duty Cycle
	P1DIR	|= BIT2;               // P1.2 = output
	P1SEL	|= BIT2;               // P1.2 = TA1 output
	while (1){
		// Go to 0°
		TACCR1 = servo_lut[0];
		__delay_cycles(1000000);

		// Go to 45°
		TACCR1 = servo_lut[45];
		__delay_cycles(1000000);

		// Go to 90°
		TACCR1 = servo_lut[90];
		__delay_cycles(1000000);

		// Go to 180°
		TACCR1 = servo_lut[179];
		__delay_cycles(1000000);

		// Move forward toward the maximum step value
		for (i = 0; i< SERVO_STEPS; i++) { 			TACCR1 = servo_lut[i]; 			__delay_cycles(20000); 		} 		 		// Move backward toward the minimum step value 		for (i = SERVO_STEPS; i &gt; 0; i--) {
			TACCR1 = servo_lut[i];
			__delay_cycles(20000);
		}



   }

