# TP noté

Projet de transmission de données série via une LED sur ATtiny85.

## Principe

Le code transmet des caractères en série via une LED en utilisant :
- Bit de start (LOW)
- 8 bits de données (LSB first)
- Bit de stop (HIGH)

## Matériel

- Arduino Uno 
- ATtiny85
- LED + résistance
- XBUSB (compteur décimal)
- Breadboard et câbles

## Branchements

### Arduino → ATtiny85 
```
Arduino    ATtiny85
  10    →   1 
  11    →   5 
  12    →   6 
  13    →   7 
  5V    →   8
  GND   →   4 
```

### ATtiny85 → LED
```
ATtiny85 Pin 3 (PB4) → Résistance → LED → GND
```

### ATtiny85 → XBUSB
```
ATtiny85 PB4 → RX
XBUSB GND  → GND
```


## Installation

1. **Config Arduino**
   - Ouvrir Arduino IDE
   - Fichier → Exemples → ArduinoISP
   - Téléverser sur l'Arduino

2. **installation avr-gcc et avrdude**
```bash
   sudo apt-get install gcc-avr avr-libc avrdude
```

3. **compilation **
```bash
   make
   make upload
```

