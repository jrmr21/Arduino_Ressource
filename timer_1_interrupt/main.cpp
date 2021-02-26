#include <Arduino.h>
#include<avr/io.h>
#include<avr/interrupt.h>

#define LED PB5

// this code make to atmega328p
// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf#G1191133

// tho

// Routine d'interruption
//TIMER1_OVF == overflow timer 1
ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	PORTB ^= (1 << LED);	
	TCNT1 = 49911;   // for 1 sec at 16 MHz
}

void setup() {

  DDRB |= (1<< LED);     // led is output
  PORTB = 0;            // power off all PORTB
  
  cli();    // disable interrupt
  
  /*
      https://exploreembedded.com/wiki/AVR_Timer_Interrupts


      (16*10^6)/1024 (F clock / prescalar) = 15625 (15k62)
      1/ 15.625 (1 tick / new F ) =  0.000064

      0.000064 * 65536 = 4.194304 s

      65536 / 4.194304 = 15625 (1s)

      65536 - 15625 = 49911.    (you substract 1s before overflow)

      (65536 is max int16, so, max count before overflow event)
  */


  TCNT1 = 49911;   // for 1 sec at 16 MHz, you set time value before 1s overflow

	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);  // Timer mode with 1024 
  
	TIMSK1 = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
  sei();    // enable interrupt

  Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:
}