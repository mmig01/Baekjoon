#include<iostream>
int main()
{
    using namespace std ;
    int iFirstNumber , iSecondNumber  , iMin , iMax , iTemp ;
    int iFirstResult , iSecondResult ;
    cin >> iFirstNumber >> iSecondNumber ;
    iFirstResult = iFirstNumber ;
    iSecondResult = iSecondNumber ;
    while (true)
    {
        iTemp = iFirstNumber % iSecondNumber ;
        if (iTemp == 0) 
        {
            iMin = iSecondNumber ;
            break ;
        }
        else
        {
            iFirstNumber = iSecondNumber ;
            iSecondNumber = iTemp ;
        }
    }
    cout << iMin << '\n' ;
    iMax = (iFirstResult / iMin) * (iSecondResult / iMin) * iMin ;
    cout << iMax ;


    return 0 ;

}