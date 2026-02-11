led_flash.hex: led_flash.elf 
	avr-objcopy -O ihex led_flash.elf led_flash.hex

led_flash.elf: led_flash.c
	avr-gcc -Os -DF_CPU=1000000 -mmcu=attiny85 -o led_flash.elf led_flash.c
	

.PHONY:  clean upload

upload: led_flash.hex
	avrdude -c avrisp -p attiny85 -b 19200 -P /dev/ttyACM0 -U flash:w:led_flash.hex

clean:
	rm -f *.elf *.hex



