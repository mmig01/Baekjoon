#include<iostream>
#include<cmath>
using namespace std ;
int f(int n)
{
    if (n == 0) return 0 ;
    if (n == 1) return 1 ;

    return f(n-1) + f(n-2) ;
}
int main()
{
    cout << pow(2 , 0) ;
    return 0 ;
} 