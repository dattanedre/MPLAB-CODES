#include<p18f4580.h>

#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define EN1 PORTCbits.RC2

#define EN2 PORTCbits.RC3
#define IN3 PORTCbits.RC4
#define IN4 PORTCbits.RC5

#define SW1 PORTDbits.RD0
#define SW2 PORTDbits.RD1

int main()
{
TRISC = 0x00; //Configure PORTC as output
TRISDbits.RD0=1;// RD0 pin as input bqz switch is input device
TRISDbits.RD1=1;



while(1)
{
if(SW1==0)// if switch 1 is press motor is ON
{
EN1 = 1;
IN1 = 1;
IN2 = 0;
}

else // Otherwise Motor is OFF
{
EN1 = 0;
}

if(SW2==0)
{
EN2 = 1;
IN3 = 1;
IN4 = 0;
}

else
{
EN2 = 0;
}

}
}
