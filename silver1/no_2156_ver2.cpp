// 포도주 시식 ver 2
#include<iostream>
#include<algorithm>
using namespace std ;
int dp[10001] ;
int wine[10001] ;
int GetCount(int N)
{
    int result = 0 ;
    dp[1] = wine[1] ;
    dp[2] = wine[2] + dp[1] ;
    for (int i = 3 ; i <= N ; i ++)
    {
        dp[i] = max(dp[i - 1] , max(dp[i - 2] , dp[i - 3] + wine[i - 1]) + wine[i]) ;
    }
    for (int i = 1 ; i <= N ; i ++)
        result = max(result , dp[i]) ;
    return result ;
}
int main()
{
    int N ;
    cin >> N ;
    for (int i = 1 ; i <= N ; i ++)
        cin >> wine[i] ;
    cout << GetCount(N) ;
}