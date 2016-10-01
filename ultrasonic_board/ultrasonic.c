#include "ultrasonic.h"
#include "pins.h"
#include "bitmacros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

void reset_timer() {
	TCNT1 = 0;
}

unsigned int timer_val() {
	unsigned int count = TCNT1;
	return (count);
}

// Send a trigger pulse to start the sensor
void _ultrasonic_trigger(Ultrasonic *u) {
	clearBit(*(u->port), u->trigger);
	_delay_us(1);
	setBit(*(u->port), u->trigger);
	_delay_us(10);
	clearBit(*(u->port), u->trigger);
}

// Set trigger pin to output and echo to input
void ultrasonic_init(Ultrasonic *u) {
	setBit(*(u->ddr), u->trigger);
	clearBit(*(u->ddr), u->echo);
}

// Read sensor distance
unsigned int ultrasonic_read(Ultrasonic *u) {
	// Trigger the sensor and start timing
	_ultrasonic_trigger(u);
	reset_timer();
	
	// Wait until ECHO pin goes HIGH
	while (!queryBit(*(u->pin), u->echo)) {
		if (timer_val() >= TRIGGER_TIMEOUT) {
			return TRIGGER_ERROR;
		}
	}

	// Reset timer and wait until ECHO pin goes back to LOW
	reset_timer();
	while (queryBit(*(u->pin), u->echo)) {
		if (timer_val() >= ECHO_TIMEOUT) {
			return ECHO_ERROR;
		}
	}
	
	// Bit shift takes care of scaling, division takes care of conversion to centimeters
	return ((timer_val() >> 1) / TIME_CONVERSION);
}
