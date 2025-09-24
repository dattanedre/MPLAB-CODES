#include<p18f4580.h>///
#define led PORTCbits.RC0////led connecyted t0 RC0
void INT_TIMER0(void);////fun declaration
void main()
{
TRISCbits.RC0=0;////led is output device

//ADCON1=0x0f;///port b and port a use as a digital
RCONbits.IPEN=1;/////
INTCON=0xe0;////global int enable and tmr0 int enable//1110
T0CON=0x87;/////prescaller 256 ///timer 0 on
TMR0H=0xfe; ///   100ms delay calculation
TMR0L=0x79;
led=0;////initially led is off
while(1)
{
}
}
#pragma code INT_TIMER0=0x08   ///INT_TIMER0 is a function name and 0x08 is a priority
#pragma interrupt INT_TIMER0   ///

void INT_TIMER0()
{

TMR0H=0xfe; ///   100ms delay calculation
TMR0L=0x79;
led=~led;

INTCONbits.TMR0IF=0;///int flag reset

}