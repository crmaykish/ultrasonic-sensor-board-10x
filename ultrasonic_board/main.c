/*
* Ultrasonic Sensor Board 10x
*
* Created: 9/25/2016 11:54:17 PM
* Author : Colin Maykish
* https://github.com/crmaykish/ultrasonic-sensor-board-10x
*/
#define SENSOR_COUNT	10

#include <avr/io.h>
#include "pins.h"
#include "bitmacros.h"
#include "serial.h"
#include "ultrasonic.h"
#include <stdio.h>
#include <util/delay.h>

Ultrasonic sensors[SENSOR_COUNT] = {
	{&S_PORT0, &S_PIN0, &S_DDR0, S_TRIG0, S_ECHO0},
	{&S_PORT1, &S_PIN1, &S_DDR1, S_TRIG1, S_ECHO1},
	{&S_PORT2, &S_PIN2, &S_DDR2, S_TRIG2, S_ECHO2},
	{&S_PORT3, &S_PIN3, &S_DDR3, S_TRIG3, S_ECHO3},
	{&S_PORT4, &S_PIN4, &S_DDR4, S_TRIG4, S_ECHO4},
	{&S_PORT5, &S_PIN5, &S_DDR5, S_TRIG5, S_ECHO5},
	{&S_PORT6, &S_PIN6, &S_DDR6, S_TRIG6, S_ECHO6},
	{&S_PORT7, &S_PIN7, &S_DDR7, S_TRIG7, S_ECHO7},
	{&S_PORT8, &S_PIN8, &S_DDR8, S_TRIG8, S_ECHO8},
	{&S_PORT9, &S_PIN9, &S_DDR9, S_TRIG9, S_ECHO9}
};

void setup() {
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
	
	// turn on timer at 1/8 scaling
	TCCR1B = bitValue(CS11);
	
	for (int i = 0; i < 10; i++) {
		ultrasonic_init(&sensors[i]);
	}
}

// Read all sensors and output JSON over serial
void loop() {
	printf("{ \"sensors\" : [");
	for (int i = 0; i < SENSOR_COUNT; i++) {
		unsigned int distance = ultrasonic_read(&sensors[i]);
		printf("{ \"pos\" : %d, \"val\" : %d }", i, distance);
		if (i != SENSOR_COUNT - 1) printf(", ");
	}
	printf("] }\n");
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

