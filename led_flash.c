#include <avr/io.h>
#include <util/delay.h>
#include <string.h>


#define DURATION 3330
#define LEDPIN PB4



void up() {
	PORTB |= (1 << LEDPIN);
}


void down() {
	PORTB &= ~ (1 << LEDPIN);
}

// 	char c = '65';

void convert(char c) {
    down();
    _delay_us(DURATION);
    for (int i = 0; i < 8; i++) {
        if(c & 1) {
            up();
        }
        else {
            down();
        }
        c = c >> 1;
    _delay_us(DURATION);
    }
    
    up(); 
    _delay_us(DURATION);  }


void convert_str(char * str) {
    int end = strlen(str);
    
    for (int i = 0; i < end; i++) {
        convert(str[i]);
    }
}

int main() {
    DDRB |= (1 << LEDPIN);  //PB4 en sortie
    PORTB |= (1 << LEDPIN); // HAUT
    
    _delay_ms(DURATION);  // premier delai
    
    while(1) {
        convert_str("test");
        _delay_ms(1000);  
    }
    
    return 0;
}



