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

Sensor s8;

void setup() {
	serialInit();
	// Redirect stdout to the UART
	stdout = &uartOut;
	
	sensor_init(&s8, PORTA, PINA, DDRA, TRIG8, ECHO8);
}

void loop() {
	unsigned int s = sensor_read(&s8);
	
	printf("Distance: %d\n", s);
	
	_delay_ms(100);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

