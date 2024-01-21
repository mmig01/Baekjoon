// 다리 놓기
#include<iostream>
#include<algorithm>
using namespace std ;
int dp[30][30] ;
int GetCount(int N , int M)
{
    dp[1][1] = 1 ;
    for (int i = 2 ; i <= M ; i ++)
    {
        for (int j = 1 ; j <= i ; j ++)
        {
            if (j == 1)
                dp[i][j] = i ;
            else if (j == i)
                dp[i][j] = 1 ;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] ;
        }
    }
    return dp[M][N] ;
}
int main()
{
    int test_case , N , M ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> N >> M ;
        cout << GetCount(N , M) << '\n' ;
    }
    return 0 ;
}