#include <avr/io.h>
#include <util/delay.h>

uint8_t red_brightness = 0;
uint8_t green_brightness = 50;
uint8_t blue_brightness = 100;

int main(){

  DDRB |= (1 << PB1) | (1 << PB3);
  DDRD |= (1 << PD6);
  TCCR0A = (1 << WGM10) | (1 << COM1A1);
  TCCR1A = (1 << WGM10) | (1 << COM1A1);
  TCCR2A = (1 << WGM10) | (1 << COM1A1);
  TCCR0B = (1 << CS11) | (1 << CS10);
  TCCR1B = (1 << CS11) | (1 << CS10);
  TCCR2B = (1 << CS11) | (1 << CS10);

  OCR0A = 0;
  OCR1A = 0;
  OCR2A = 0;

  while(true){
    _delay_ms(10);
      red_brightness++;
      green_brightness++;
      blue_brightness++;

      OCR0A = blue_brightness;
      OCR1A = red_brightness;
      OCR2A = green_brightness;
  }

  return 0;
}