#include<iostream>
int main()
{
    using namespace std ;
    int iFloor[15][14] , iTempSum , T , k , n ;
    for (int i = 0 ; i < 15 ; i ++)
    {
        iTempSum = 0 ;
        for (int j = 0 ; j < 14 ; j ++)
        {
            if (i == 0)
            {
                iFloor[i][j] = j + 1 ;
            }
            else
            {
                iTempSum = iTempSum + iFloor[i - 1][j] ;
                iFloor[i][j] = iTempSum ;
            }
        }
    }
    cin >> T ;
    for (int i = 0 ; i < T ; i ++)
    {
        cin >> k >> n ;
        cout << iFloor[k][n - 1] << '\n' ;
    }
    return 0 ;
}