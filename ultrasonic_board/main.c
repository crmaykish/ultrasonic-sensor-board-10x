/*
 * Ultrasonic Sensor Board 10x
 *
 * Created: 9/25/2016 11:54:17 PM
 * Author : Colin Maykish
 * https://github.com/crmaykish/ultrasonic-sensor-board-10x
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "pins.h"
#include "bitmacros.h"
#include "serial.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


int counter = 0;

void setup() {
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;

	ultrasonicInit();
}

void loop() {
	printf("Hello, Ansel! %d\n", counter);
	//setBit(PORTC, TRIG3);
	//_delay_us(12);
	//clearBit(PORTC, TRIG3);
	counter++;
	_delay_ms(1000);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

