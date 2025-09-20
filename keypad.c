#include<p18f4580.h>

#define RS PORTCbits.RC0
#define E PORTCbits.RC1

void cmd(int b);
void data(char x);
void delay(int a);
void cmdata();
void string(const rom char *str);

void main()
{
ADCON1=0x0f;
TRISCbits.RC0=0;
TRISCbits.RC1=0;
TRISB=0x00;
TRISD=0x00;

cmdata();
  string("Enter no.");
cmd(0xc0);// second line

while(1)
{

//r1=0

PORTB=0xfe;///r1=0;r2,r3,r4=1
if(PORTB==0xee)   
{
while(PORTB==0xee);
data('7');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xde) // 1101 1110 
{
while(PORTB==0xde);  //polling method to check the input
data('8');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xbe)
{
while(PORTB==0xbe);
data('9');
//delay(100);
//cmd(0x01);
}
if(PORTB==0x7e)
{
while(PORTB==0x7e);
data('/');
//delay(100);
//cmd(0x01);
}

//r2=0

PORTB=0xfd;///r2=0 and r1 r3 r4 are 1
if(PORTB==0xed) // 1110 1101
{
while(PORTB==0xed);
data('4');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xdd)
{
while(PORTB==0xdd);
data('5');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xbd)
{
while(PORTB==0xbd);
data('6');
//delay(100);
//cmd(0x01);
}
if(PORTB==0x7d)
{
while(PORTB==0x7d);
data('*');
//delay(100);
//cmd(0x01);
}

//r3=0

PORTB=0xfb;
if(PORTB==0xeb)
{
while(PORTB==0xeb);
data('1');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xdb)
{
while(PORTB==0xdb);
data('2');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xbb)
{
while(PORTB==0xbb);
data('3');
//delay(100);
//cmd(0x01);
}
if(PORTB==0x7b)
{
while(PORTB==0x7b);
data('-');
//delay(100);
//cmd(0x01);
}

//r4=0

PORTB=0xf7;
if(PORTB==0xe7)
{
while(PORTB==0xe7);
data('C');
delay(300);
cmd(0x01);
cmd(0x80);
  string("Enter no.");
cmd(0xc0);
}
if(PORTB==0xd7)
{
while(PORTB==0xd7);
data('0');
//delay(100);
//cmd(0x01);
}
if(PORTB==0xb7)
{
while(PORTB==0xb7);
data('=');
//delay(100);
//cmd(0x01);
}
if(PORTB==0x77)
{
while(PORTB==0x77);
data('+');
//delay(100);
//cmd(0x01);
}
}
}

void cmdata()
{
cmd(0x01);
cmd(0x38);
cmd(0x0e );
cmd(0x06);
cmd(0x80);
}

void cmd(int cd)
{
PORTD=cd;
RS=0;

E=1;
delay(100);
E=0;
}


void data( char x)
{
PORTD=x;
RS=1;

E=1;
delay(100);
E=0;
}


void delay(int a)
{
int i,j;
for(i=0;i<a;i++)

for(j=0;j<i;j++);
}


void string(const rom char *str)
{
while(*str)
data(*str++);
}