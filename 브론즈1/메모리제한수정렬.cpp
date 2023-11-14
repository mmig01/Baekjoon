#include<iostream>
int main()
{
    using namespace std ;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int iFirstArr[10001] ;
    int iFirstOrder[10001] ;
    int N , iTempNum , iIndex ;
    for (int i = 0 ; i < 10001 ; i ++)
    {
        iFirstArr[i] = 0 ;
        iFirstOrder[i] = 0 ;
    }
    cin >> N ; 
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> iTempNum ;
        if (iFirstArr[iTempNum] == 0) 
        {
            iFirstArr[iTempNum] = iTempNum ;
            iFirstOrder[iTempNum] ++ ;
        }
        else
        {
            iFirstOrder[iTempNum] ++ ;
        }
    }

    for (int i = 0 ; i < 10000 ; i ++)
    {
        iIndex = i + 1 ;
        if (iFirstOrder[iIndex] == 0) continue ;
        else
        {
            for (int j = 0 ; j < iFirstOrder[iIndex] ; j ++)
            {
                cout << iFirstArr[iIndex] << '\n' ;
            }
        }
    }
    return 0 ;
}