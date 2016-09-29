#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define TRIGGER_TIMEOUT		0xFF
#define DISTANCE_TIMEOUT	0xFF
#define TRIGGER_ERROR		-1
#define DISTANCE_ERROR		-2

typedef struct Sensor {
	int port;
	int pin;
	int ddr;
	int trigger;
	int echo;
} Sensor;

void sensor_init(Sensor *sensor, int port, int pin, int ddr, int trigger, int echo);

unsigned int sensor_read(Sensor *sensor);

#endif /* ULTRASONIC_H_ */