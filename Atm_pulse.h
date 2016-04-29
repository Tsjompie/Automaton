
#ifndef Atm_pulse_h
#define Atm_pulse_h

#include <Automaton.h>

// Detects a pulse (LOW -> HIGH ) on a digital pin with a minimum duration in ms
// On detection another machine is messaged or a callback is fired

typedef void (*pulsecb_t)( void );

class Atm_pulse: public Machine {

  public:
    Atm_pulse( void ) : Machine() { class_label = "PULSE"; };

    short pin;     
    Machine * client_machine;
    uint8_t client_event;
    void (*callback)( void ) = 0;
    int state_high, state_low;
    atm_timer_millis timer;

    enum { IDLE, WAIT, PULSE };
    enum { EVT_TIMER, EVT_HIGH, EVT_LOW, ELSE };
    enum { ACT_PULSE };
	
    Atm_pulse & begin( int attached_pin, int minimum_duration );
    Atm_pulse & trace( Stream & stream );
    int event( int id ); 
    void action( int id ); 
    Atm_pulse & onPulse( Machine * machine, uint8_t event ); 
    Atm_pulse & onPulse( pulsecb_t press_callback ); 
};

// TinyMachine version

class Att_pulse: public TinyMachine {

  public:
    Att_pulse( void ) : TinyMachine() { };

    short pin;     
    TinyMachine * client_machine;
    uint8_t client_event;
    void (*callback)( void ) = 0;
    int state_high, state_low;
    atm_timer_millis timer;

    enum { IDLE, WAIT, PULSE };
    enum { EVT_TIMER, EVT_HIGH, EVT_LOW, ELSE };
    enum { ACT_PULSE };
	
    Att_pulse & begin( int attached_pin, int minimum_duration );
    int event( int id ); 
    void action( int id ); 
    Att_pulse & onPulse( TinyMachine * machine, uint8_t event ); 
    Att_pulse & onPulse( pulsecb_t press_callback ); 
};


#endif

