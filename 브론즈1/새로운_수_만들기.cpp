#include<iostream>
int main()
{ // 26 68 84 42 26
    using std::cin ;
    using std::cout ;
    int iNumber , iFirstNum , iSecondNum , iTempNum , iCompNum , iCount ;
    int iOriginFirstDigit , iOriginSecondDigit ;
    iCount = 0 ;
    cin >> iNumber ;
    iCompNum = iNumber ;
    while (true)
    {
        iOriginFirstDigit = iNumber / 10 ;
        iOriginSecondDigit = iNumber % 10 ;

        iFirstNum = iOriginSecondDigit ;
        iSecondNum = (iOriginFirstDigit + iOriginSecondDigit) % 10 ;
        iTempNum = iFirstNum * 10 + iSecondNum ;
        iNumber = iTempNum ;
        iCount ++ ;
        if (iCompNum == iNumber)
        {
            break ;
        }
    }
    cout << iCount ;
    return 0 ;
}