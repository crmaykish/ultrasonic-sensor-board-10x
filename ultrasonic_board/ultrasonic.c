// Reference: http://extremeelectronics.co.in/avr-tutorials/interfacing-ultrasonic-rangefinder-with-avr-mcus-%E2%80%93-avr-tutorial/

#include "ultrasonic.h"
#include "pins.h"
#include "bitmacros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

void start_timer() {
	TCCR1B = bitValue(CS11);
	TCNT1 = 0;
}

unsigned int timer_val() {
	unsigned int count = TCNT1;
	return (count);
}

// probably some mapping and cleanup to do here instead of just setting everything manually
void sensor_init(Sensor *sensor, int port, int pin, int ddr, int trigger, int echo) {
	sensor->port = port;
	sensor->pin = pin;
	sensor->ddr = ddr;
	sensor->trigger = trigger;
	sensor->echo = echo;
	
	setBit(sensor->ddr, sensor->trigger);
	clearBit(sensor->ddr, sensor->echo);
}

unsigned int sensor_read(Sensor *sensor) {
	// Trigger sensor
	clearBit(sensor->port, sensor->trigger);
	_delay_us(1);
	setBit(sensor->port, sensor->trigger);
	_delay_us(10);
	clearBit(sensor->port, sensor->trigger);
	
	start_timer();
	
	while (!queryBit(sensor->pin, sensor->echo)) {
		if (timer_val() > TRIGGER_TIMEOUT) {
			return TRIGGER_ERROR;
		}
	}
	
	start_timer();
	
	while (queryBit(sensor->pin, sensor->echo)) {
		if (timer_val() > DISTANCE_TIMEOUT) {
			return DISTANCE_ERROR;
		}
	}
	
	// Bit shift takes care of scaling, division takes care of conversion to centimeters
	return ((timer_val() >> 1) / 58.0);
}
