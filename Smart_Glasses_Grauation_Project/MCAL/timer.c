
#include "timer.h"

 extern uint16 tot_overflow;
 extern uint16 tot_overflow1;
 extern uint16 tot_overflow2;
 
 extern uint16 timer_l;
 extern uint16 timer_r;
 extern uint16 timer_m;


// initialize timer, interrupt and variable
void timer0_init()
{
	// set up timer with prescaler = 256
	TCCR0 |= (1 << CS00);
	
	// initialize counter
	TCNT0 = 0;
	
	// enable overflow interrupt
	TIMSK |= (1 << TOIE0);
	
	// enable global interrupts
	sei();
	
	// initialize overflow counter variable
	tot_overflow = 0;
}

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
	// keep a track of number of overflows
	tot_overflow++;
	tot_overflow1++;
	tot_overflow2++;
	
	
	timer_l++;
	timer_r++;
	timer_m++;


}