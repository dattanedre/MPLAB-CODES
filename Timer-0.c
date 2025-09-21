#include<p18f4580.h>
#define LED PORTCbits.RC0 //LED Connected to RC0
#define dir_LED TRISCbits.RC0 // dir of led

void delay(void);

void main()
{
dir_LED=0; //led is output
T0CON=0x07; //Prescaller 256 // and timer 0 off
while(1)
{
LED=1;// LED On
delay();
delay();
delay();
LED=0;
delay();
}
}

void delay()
{
TMR0H=0Xfe; //100ms delay calculation
TMR0L=0x79;

INTCONbits.TMR0IF=0; //interupt flag reset
T0CONbits.TMR0ON=1; //timer 0 on
while(INTCONbits.TMR0IF!=1); //wait until the overflow
T0CONbits.TMR0ON=0; //timer off
INTCONbits.TMR0IF=0; // interupt flag reset

}