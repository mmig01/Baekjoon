// 2 x n 타일링
#include<iostream>
using namespace std ;
long long dp[1001] ;
long long FUN(int N)
{
    if (N == 2)
        return 2 ;
    else if (N == 1)
        return 1 ;
    else
    {
        if (dp[N] == 0)
            dp[N] = FUN(N - 1) + FUN(N - 2) ;
        return dp[N] % 10007 ;
    }
}
int main()
{
    int N ;
    cin >> N ;
    cout << FUN(N) ;
    return 0 ;
}