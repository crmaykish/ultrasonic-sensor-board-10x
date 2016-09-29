#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

void ultrasonicInit();

void trigger();

unsigned int read();

void start_timer();
unsigned int timer_val();

#endif /* ULTRASONIC_H_ */