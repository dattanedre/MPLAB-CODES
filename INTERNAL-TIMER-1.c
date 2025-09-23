#include<p18f4580.h>///
#define led PORTCbits.RC0////led connecyted t0 RC0
void INT_TIMER1(void);////fun declaration
int count=0;
void main()
{
TRISCbits.RC0=0; ////led is output device
RCONbits.IPEN=1; /////
//ADCON1=0x0f; ///port b and port a use as a digital

//INTCON=0xe0; ////global int enable and tmr0 int enable//1110

INTCONbits.GIEH = 1;
PIE1bits.TMR1IE = 1;
T1CON=0xb1; /////prescaller 256 ///timer 0 on

TMR1H=0xcf;
TMR1L=0x2b;

led=0;  ////initially led is off
while(1)
{
if (count==10)
{
    led=~led;
    count=0;
}

}
}
#pragma code INT_TIMER1=0x08   ///INT_TIMER0 is a function name and 0x08 is a priority
#pragma interrupt INT_TIMER1   //

void INT_TIMER1()
{

TMR1H=0xcf;
TMR1L=0x2b;
count++;
//led=~led;

PIR1bits. TMR1IF=0;  ///int flag reset

}