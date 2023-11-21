#include<iostream>
using namespace std ;
int getResult(int N)
{
    int iFiveCount = N / 5 ;
    int iThreeCount ;
    int iFiveMod , iThreeMod ;
    while (true)
    {
        iFiveMod = N - (iFiveCount * 5) ;
        iThreeCount = iFiveMod / 3 ;
        iThreeMod = iFiveMod - (iThreeCount * 3) ;

        if (iThreeMod == 0)
        {
            return iFiveCount + iThreeCount ;
        }  
        else 
        {
            iFiveCount -- ;
        }   
        if (iFiveCount < 0)
            break ;
    }

    return - 1 ; // if didn't set best choice
}
int main()
{   
    int N ;
    cin >> N ;
    cout << getResult(N) ;
    return 0 ;
}