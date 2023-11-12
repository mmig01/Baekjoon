#include<iostream>
#include<algorithm>
using namespace std ;
int main()
{
    long long iNumber[10000] ;
    long long iTotal = 0 ; 
    long long iResult , iTemp , iTempCount , iDivide ;
    int iHave , iCount ; // = 4 , = 11 
    cin >> iHave >> iCount ;

    for (int i = 0 ; i < iHave ; i ++)
    {
        cin >> iNumber[i] ;
    }

    sort(iNumber , iNumber + iHave) ;
    
    iDivide = 1 ;
    while (true)
    {
        iTempCount = 0 ;
        iResult = iNumber[iHave - 1] / iDivide ;
        for (int i = 0 ; i < iHave ; i ++)
        {
            iTemp = iNumber[i] / iResult ;
            iTempCount = iTempCount + iTemp ;
        }
        if (iTempCount >= iCount) break ;
        else 
        {
            iDivide ++ ;
        }
    }

    cout << iResult ;

    return 0 ;
}