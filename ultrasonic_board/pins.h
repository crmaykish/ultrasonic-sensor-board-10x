#ifndef PINS_H_
#define PINS_H_

// 16 MHz crystal
#define F_CPU 16000000UL

// Sensor 0
#define S_PORT0		PORTD
#define S_PIN0		PIND
#define S_DDR0		DDRD
#define S_TRIG0		PD4
#define	S_ECHO0		PD5

// Sensor 1
#define S_PORT1		PORTD
#define S_PIN1		PIND
#define S_DDR1		DDRD
#define	S_TRIG1		PD6
#define	S_ECHO1		PD7

// Sensor 2
#define S_PORT2		PORTC
#define S_PIN2		PINC
#define S_DDR2		DDRC
#define	S_TRIG2		PC0
#define	S_ECHO2		PC1

// Sensor 3
#define S_PORT3		PORTC
#define S_PIN3		PINC
#define S_DDR3		DDRC
#define	S_TRIG3		PC2
#define	S_ECHO3		PC3

// Sensor 4
#define S_PORT4		PORTC
#define S_PIN4		PINC
#define S_DDR4		DDRC
#define	S_TRIG4		PC4
#define	S_ECHO4		PC5

// Sensor 5
#define S_PORT5		PORTC
#define S_PIN5		PINC
#define S_DDR5		DDRC
#define	S_TRIG5		PC6
#define	S_ECHO5		PC7

// Sensor 6
#define S_PORT6		PORTA
#define S_PIN6		PINA
#define S_DDR6		DDRA
#define	S_TRIG6		PA7
#define	S_ECHO6		PA6

// Sensor 7
#define S_PORT7		PORTA
#define S_PIN7		PINA
#define S_DDR7		DDRA
#define	S_TRIG7		PA5
#define	S_ECHO7		PA4

// Sensor 8
#define S_PORT8		PORTA
#define S_PIN8		PINA
#define S_DDR8		DDRA
#define	S_TRIG8		PA3
#define	S_ECHO8		PA2

// Sensor 9
#define S_PORT9		PORTA
#define S_PIN9		PINA
#define S_DDR9		DDRA
#define	S_TRIG9		PA1
#define	S_ECHO9		PA0

#endif /* PINS_H_ */