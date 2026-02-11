#include <avr/io.h>
#include <util/delay.h>

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

convert(const char c) {


	for (int i = 0; i<8; i++) {
		
		if(65 & 1) {
			up();
			}
		else {
			down();
		
		}
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
		
		//  $ en ASCII
		
		down();
		down();
		
		up();
		
		down();
		down();
		
		up();
		
		down();
		down();
		
		//stop 
		
		for (int i=0 ;i<1000 ; i++) {
		
			 up();
		}
		
	}
	
		
	return(0);
};


