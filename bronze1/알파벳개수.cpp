//알파벳은 총 26 개
#include<iostream>
#include<string>
#include<cctype>
int main()
{
    using std::cin ;
    using std::cout ;
    using std::string ;

    int i , iIndex , iMax ;
    char cIndex ;
    int iAlphaCount[26] ;
    for (i = 0 ; i < 26 ; i ++)
    {
        iAlphaCount[i] = 0 ;
    }
    string sAlphaArray ;
    cin >> sAlphaArray ;

    for (i = 0 ; i < sAlphaArray.size() ; i ++)
    {
        if (islower(sAlphaArray[i]))
        {
            sAlphaArray[i] = toupper(sAlphaArray[i]) ;
        }
    }
    
    for (i = 0 ; i < sAlphaArray.size() ; i ++)
    {
        iIndex = int(sAlphaArray[i]) - 65 ;
        iAlphaCount[iIndex] ++ ;
    }

    iMax = iAlphaCount[0] ;
    cIndex = 'A' ;

    for (i = 0 ; i < 25 ; i ++) // 26 - 1 
    {
        iIndex = i + 1 ;
        if (iMax < iAlphaCount[iIndex])
        {
            iMax = iAlphaCount[iIndex] ;
            cIndex = char(iIndex + 65) ;
        }
        else if (iMax == iAlphaCount[iIndex])
        {
            cIndex = '?' ;
        }
    
    }
    cout << cIndex ;
    return 0 ;

}