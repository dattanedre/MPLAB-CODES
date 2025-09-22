#include<p18f4580.h>
#define led PORTCbits.RC0

void delay();

void main()
{
TRISCbits.RC0=0;
T1CON=0xf0;

while(1)
{
led=1;
delay();
delay();
delay();
delay();
delay();
delay();
delay();
delay();
delay();
delay();

led=0;
delay();
}
}

void delay()
{
TMR1H=0xcf;
TMR1L=0x2b;
T1CONbits.TMR1ON=1;
PIR1bits.TMR1IF=0;
while(PIR1bits.TMR1IF !=1);
T1CONbits.TMR1ON=0;
PIR1bits.TMR1IF=0;
}