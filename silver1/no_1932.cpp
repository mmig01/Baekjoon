// 정수 삼각형
#include<iostream>
#include<vector>
#include<algorithm>
int dp[501][501] ;
using namespace std ;
int GetCount(vector<vector <int> > & my_vec , int size)
{
    int result = 0 ;
    for (int i = 1 ; i <= size ; i ++)
    {
        for (int j = 1 ; j <= i ; j ++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] , dp[i - 1][j]) + my_vec[i][j] ;
        }
    }
    for (int i = 1 ; i <= size ; i ++)
        result = max(result , dp[size][i]) ;
    return result ;
}
int main()
{
    vector< vector<int> > tri_vec(501 , vector<int>(501)) ;
    int size ;
    cin >> size ;
    for (int i = 1 ; i <= size ; i ++)
    {
        for (int j = 1 ; j <= i ; j ++)
        {
            int temp ; 
            cin >> temp ;
            tri_vec[i][j] = temp ;
        }
    }
    cout << GetCount(tri_vec , size) ;
    return 0 ;
}
