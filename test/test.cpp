#include<iostream>
int main()
{
    int a ;
    a = 0x12345678 ;
    char * b ;
    b = (char *) & a ;
    for (int i = 0 ; i < sizeof(int) ; i ++)
    {
        printf("%x " , b[i]) ;
    }
} // little endian