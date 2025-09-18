#include<p18f4580.h>
#define rs PORTCbits.RC0
#define rw PORTCbits.RC1
#define E PORTCbits.RC2

void cmd(char cm);
void data(char dt);
void delay(int a);
void string(const rom char* str);

int main()
{
TRISC=0x00;
TRISD=0x00;

cmd(0x02);  // 4 bit line only 
cmd(0x28);  
cmd(0x0f);  //corsor,dislpay on
//cmd(0x38);  //matrix 5*7
cmd(0x01);  //clear screen 
cmd(0x80);  // dataa show at first line
cmd(0x06);  //increment cursor


while(1)
{
int i;
// data('a'); // char a send to the data function 

//techscript
/* char str[20]="TECHNO_SCRIPT";
 for(i=0;i<20;i++)
 {
    data(str[i]);
 }
*/
cmd(0x80);
string("TECHNO");
cmd(0xc0);
string("SCRIPT");
}
}

void cmd(char cm)
{
    int temp;
    temp=(cm & 0xf0);
    PORTD=temp;
    rs=0;
    E=1;
    delay(100);
    E=0;

    temp=(cm & 0x0f);
    temp=temp<<4;
    PORTD=temp;
    E=1;
    delay(100);
    E=0;

    
}

void data(char dt)
{
    int temp;
      temp=(dt & 0xf0);
    PORTD=temp;
    rs=1;
    E=1;
    delay(100);
    E=0;

    temp=(dt & 0x0f);
    temp=temp<<4;
    PORTD=temp;
    E=1;
    delay(100);
    E=0;


    
}

void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
        }
    }
}

void string(const rom char* str)
{
while(*str != '\0')
{
data(*str);
str++;
}
}