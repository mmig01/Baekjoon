#include<iostream>
#include<algorithm>
int main()
{
    using std::sort ;
    using std::cin ;
    using std::cout ;

    int iCount , iTempNumber , iRealNumber ;
    int iIndex ;
    cin >> iCount ;
    int * iDivisorArray = new int[iCount] ; 
    for (int i = 0 ; i < iCount ; i++ )
    {
        cin >> iTempNumber ;
        iDivisorArray[i] = iTempNumber ;
    }

    sort(iDivisorArray , iDivisorArray + iCount) ;

    if (iCount % 2 == 0)
    {
        iIndex = iCount - 1 ;
        iRealNumber = iDivisorArray[0] * iDivisorArray[iIndex] ;
    }
    else
    {
        iIndex = iCount / 2 ;
        iRealNumber = iDivisorArray[iIndex] * iDivisorArray[iIndex] ;
    }
    cout << iRealNumber ;
    delete [] iDivisorArray ;
    return 0 ;
}