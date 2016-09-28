#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define SPEED_OF_SOUND		343		// meters per second

void ultrasonicInit();

void trigger();

unsigned int read();

#endif /* ULTRASONIC_H_ */