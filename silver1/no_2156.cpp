// 포도주 시식
#include<iostream>
#include<algorithm>
using namespace std ;
int dp[3][10001] ;
int arr[10001] ;
int GetCount(int N)
{
    int result = 0 ;
    dp[0][1] = dp[1][1] = dp[2][1] = arr[1] ;
    for (int i = 2 ; i <= N ; i ++)
    {
        dp[0][i] = max(dp[1][i - 1] , dp[2][i - 1]) + arr[i] ; 
        dp[1][i] = max(dp[0][i - 2] , max(dp[1][i - 2] , dp[2][i - 2])) + arr[i] ;
        if (i >= 3)
            dp[2][i] = max(dp[0][i - 3] , max(dp[1][i - 3] , dp[2][i - 3])) + arr[i] ;
       
    }
    for (int i = 1 ; i <= N ; i ++)
        result = max(result , max(dp[0][i] , max(dp[1][i] , dp[2][i]))) ;
    return result ;
}
int main()
{
    int N ;
    cin >> N ;
    for (int i = 1 ; i <= N ; i ++)
        cin >> arr[i] ;
    cout << GetCount(N) ;
    return 0 ;
}
