#include "stdio.h"

void scan( )  
{  
    k = num = 0, bit = 1;  
   while( ( ch[++num] = getchar( ) ) != 32 );  
    num--;  
   while( num ) k += ( ch[num--]-48 )*bit, bit *= 10;  
}  


void print( int k )  
{  
    num = 0;  
    while( k > 0 ) ch[++num] = k % 10, k /= 10;  
    while( num )   
        putchar( ch[num--]+48 );  
   putchar( 32 );  
}  
main()
{
	int k=3;
	scan();
	print(k);
	return 0;
}
