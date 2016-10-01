/*
 * Ultrasonic Sensor Board 10x
 *
 * Created: 9/25/2016 11:54:17 PM
 * Author : Colin Maykish
 * https://github.com/crmaykish/ultrasonic-sensor-board-10x
 */ 

#include <avr/io.h>
#include "pins.h"
#include "bitmacros.h"
#include "serial.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

Ultrasonic s8 = {&S_PORT8, &S_PIN8, &S_DDR8, S_TRIG8, S_ECHO8};

void setup() {
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
	
	// turn on timer at 1/8 scaling
	TCCR1B = bitValue(CS11);
	
	ultrasonic_init(&s8);
}

void loop() {
	unsigned int distance = ultrasonic_read(&s8);
	printf("Distance: %d\n", distance);
	
	_delay_ms(60);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

