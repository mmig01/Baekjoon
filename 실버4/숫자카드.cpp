#include<iostream>
int iPlusNumber[10000001] ;
int iMinusNumber[10000001] ;
int main()
{
    using namespace std ;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int iIndex , N , iTemp , M , iObjectNum ;
    iPlusNumber[0] = 0 ;
    for (int i = 0 ; i < 10000000 ; i ++)
    {
        iIndex = i + 1 ;
        iPlusNumber[iIndex] = 0 ;
    }
    iMinusNumber[0] = 0 ; // trash index 
    for (int i = 0 ; i < 10000000 ; i ++)
    {
        iIndex = i + 1 ;
        iMinusNumber[iIndex] = 0 ;
    }

    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> iTemp ;
        if (iTemp >= 0) iPlusNumber[iTemp] ++ ;
        else 
        {
            iIndex = - iTemp ;
            iMinusNumber[iIndex] ++ ;
        }
    }

    cin >> M ;
    for (int i = 0 ; i < M ; i ++)
    {
        cin >> iObjectNum ;
        if (iObjectNum >= 0) 
        {
            cout << iPlusNumber[iObjectNum] ;
            cout << " " ;
        }
        else
        {
            iIndex = - iObjectNum ;
            cout << iMinusNumber[iIndex] ;
            cout << " " ;
        }
    }
    
    
    return 0 ;
}