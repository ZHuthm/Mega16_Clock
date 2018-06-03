//ICC-AVR application builder : 4/18/2017 1:56:13 AM
// Target : M16
// Crystal: 1.0000Mhz

#include <iom16v.h>
#include <macros.h>

void port_init(void)
{
 PORTA = 0x00; // common cathode
 DDRA  = 0xFF;
 PORTB = 0x00;
 DDRB  = 0x00;
 PORTC = 0xC0; //m103 output only
 DDRC  = 0x3F;
 PORTD = 0x0C;
 DDRD  = 0x00;
}

/********************************
// TIMER0 initialize - prescale:8
// WGM: Normal
// desired value: 1mSec
// actual value:  1.000mSec (0.0%)
*********************************/
void timer0_init(void)
{
 TCCR0 = 0x00; 		  			  		 //stop
 TCNT0 = 0x83;							 //set count
 OCR0  = 0x7D;  						 //set compare
 TCCR0 = 0x02;							 //start timer
}

//call this routine to initialize all peripherals
void init_devices(void)
{
 //stop errant interrupts until set up
 CLI(); //disable all interrupts
 port_init();
 timer0_init();

 MCUCR = 0x00;
 GICR  = 0x00;
 TIMSK = 0x01; //timer interrupt sources
 SEI(); //re-enable interrupts
 //all peripherals are now initialized
}



