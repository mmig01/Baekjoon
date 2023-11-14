#include<iostream>
using namespace std ;
bool bPrimeNum[1000001] ;
int main()
{
    int iNum = 2 ;
    int iIndex ;
    int iStart , iEnd ;

    for (int i = 0 ; i < 1000001 ; i ++)
    {
        iIndex = i + 1 ;
        bPrimeNum[i] = true ;
    }
    bPrimeNum[1] = false ;
    cin >> iStart >> iEnd ;
    while (true)
    {
        if (bPrimeNum[iNum] == true)
        {
            iIndex = iNum * iNum ;
            while (true)
            { 
                bPrimeNum[iIndex] = false ;
                iIndex = iIndex + iNum ;
                if (iIndex > 1000000) break ;
            }
        }
        iNum ++ ;
        if (iNum * iNum > 1000000) break ;
    }
    
    for (int i = iStart ; i < iEnd + 1 ; i ++)
    {
        if (bPrimeNum[i] == true)
            cout << i << '\n' ;
    }
    return 0 ;
}