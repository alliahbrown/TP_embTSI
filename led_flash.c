#include <avr/io.h>
#include <util/delay.h>
#include <string.h>


#define DURATION 3330
#define LEDPIN PB4



int up() {
	PORTB |= (1 << LEDPIN);
	_delay_us(DURATION);
	return(0);
}


int down() {
	PORTB &= ~ (1 << LEDPIN);
	_delay_us(DURATION);
	return(0);
}

// 	char c = '65';

void convert( char c) {
	for (int i = 0; i<8; i++) {
		
		if(c & 1) {
			up();
			}
		else {
			down();
		
		}
		
		c = c >> 1;
	}
}


void convert_str(char * str) {
	
	int end = strlen(str);
	
	for (int i =0; i < end ; i++) {
		convert(str[i]);
	}
}


int main () {

	while(1) {

		DDRB |= (1 << LEDPIN); // mettre PB4 en sortie 
		
		PORTB |= (1 << LEDPIN); // LED allumée par défaut

		
		// état initial
		for (int i=0 ;i<1000 ; i++) {
		
			 up();
		}
		
		// start 
		
		down();
		
		convert(65);
		
		//stop 
		
		for (int i=0 ;i<1000 ; i++) {
		
			 up();
		}
		
	}
	
		
	return(0);
};


