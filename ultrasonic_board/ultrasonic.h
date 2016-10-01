#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define TRIGGER_TIMEOUT		0xFFFF
#define ECHO_TIMEOUT		0xFFFF

#define TRIGGER_ERROR		-1
#define ECHO_ERROR			-2

#define TIME_CONVERSION		58.0

#include <inttypes.h>

typedef struct Ultrasonic {
	volatile uint8_t *port;
	volatile uint8_t *pin;
	volatile uint8_t *ddr;
	uint8_t trigger;
	uint8_t echo;
} Ultrasonic;

void ultrasonic_init(Ultrasonic *u);
unsigned int ultrasonic_read(Ultrasonic *u);

#endif /* ULTRASONIC_H_ */