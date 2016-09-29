// Reference: http://extremeelectronics.co.in/avr-tutorials/interfacing-ultrasonic-rangefinder-with-avr-mcus-%E2%80%93-avr-tutorial/

#include "ultrasonic.h"
#include "pins.h"
#include "bitmacros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

void ultrasonicInit() {
	// Set trigger pins as output, leave echo pins as input
	setBit(DDRD, TRIG0);
	clearBit(DDRD, ECHO0);
	setBit(DDRD, TRIG1);
	clearBit(DDRD, ECHO1);
	setBit(DDRC, TRIG2);
	clearBit(DDRC, ECHO2);
	setBit(DDRC, TRIG3);
	clearBit(DDRC, ECHO3);
	setBit(DDRC, TRIG4);
	clearBit(DDRC, ECHO4);
	setBit(DDRC, TRIG5);
	clearBit(DDRC, ECHO5);
	setBit(DDRA, TRIG6);
	clearBit(DDRA, ECHO6);
	setBit(DDRA, TRIG7);
	clearBit(DDRA, ECHO7);
	setBit(DDRA, TRIG8);
	clearBit(DDRA, ECHO8);
	setBit(DDRA, TRIG9);
	clearBit(DDRA, ECHO9);
	
	// turn on timer at 1/8 scaling
	TCCR1B = bitValue(CS11);
}

void trigger() {
	clearBit(PORTA, TRIG8);
	_delay_us(1);
	setBit(PORTA, TRIG8);
	_delay_us(10);
	clearBit(PORTA, TRIG8);	
}

unsigned int read() {
	trigger();
	
	start_timer();
	
	while (!queryBit(PINA, ECHO8)) {
		if (timer_val() > 60000) {
			return -1;
		}
	}
	
	start_timer();
	
	while (queryBit(PINA, ECHO8)) {
		if (timer_val() > 60000) {
			return -2;
		}
	}
	
	// Bit shift takes care of scaling, division takes care of conversion to centimeters
	return ((timer_val() >> 1) / 58.0);
}

void start_timer() {
	TCNT1 = 0;
}

unsigned int timer_val() {
	unsigned int count = TCNT1;
	return (count);
}