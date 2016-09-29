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

void setup() {
	ultrasonicInit();
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
}

void loop() {
	unsigned int distance = read();
	printf("Distance: %d\n", distance);
	
	_delay_ms(100);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

