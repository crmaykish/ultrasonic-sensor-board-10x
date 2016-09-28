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
}

void trigger() {
	clearBit(PORTD, TRIG0);
	_delay_us(1);
	setBit(PORTD, TRIG0);
	_delay_us(10);
	clearBit(PORTD, TRIG0);	
	//_delay_us(1);
}

unsigned int read() {
	int distance = 0;
	unsigned int response_timer = 0;
	unsigned int distance_timer = 0;
	
	printf("ping\n");
	
	trigger();
	
	while (!(PIND & (1 << ECHO0))) {
		response_timer++;
	}
	
	// don't do anything in here... messes up the timing
	
	//printf("response timer: %d\n", response_timer);
	
	while ((PIND & (1 << ECHO0))) {
		distance_timer++;
	}
	
	distance = distance_timer;
	
	printf("returning %d \n", distance);
	
	return distance;
}