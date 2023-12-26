#include<iostream>
int main()
{
    using namespace std ;
    int iNumber , iCount , iIndex , i ;
    cin >> iNumber ;
    iCount = 1 ;
    iIndex = 2 ;
    i = 0 ;
    while (true)
    {
        iIndex = iIndex + 6 * i ;
        if (iNumber < iIndex) break ;
        i ++ ;
        iCount ++ ;
    }
   
    cout << iCount ;
    return 0 ;
}