#include<iostream>
int main()
{
    using namespace std ;
    int number , iDivideSum , iObjectNum , iDigitSum , iTemp ;
    cin >> number ;

    iObjectNum = 1 ;
    while (true)
    {
        iDigitSum = iDivideSum = 0 ;
        iTemp = iObjectNum ;
        while (true)
        {
            iDigitSum = iDigitSum + iTemp % 10 ;
            iTemp = iTemp / 10 ;
            if (iTemp == 0) break ;
        }
        
        iDivideSum = number - iDigitSum ;
        if (iDivideSum == iObjectNum) break ;
        else iObjectNum ++ ;

        if (iObjectNum > 1000000)
        {
            iObjectNum = 0 ;
            break ;
        }
    }
    cout << iObjectNum ;
    return 0 ;
}
