// 쉬운 계단 수
#include<iostream>
using namespace std ;
long long dp[10] = {0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1} ;
void SetDP()
{
    long long temp[10] = {0} ;
    for (int i = 0 ; i < 10 ; i ++)
    {
        if (i == 0)
            temp[i] = dp[i + 1] ;
        else if (i >= 1 && i <= 8)
            temp[i] = (dp[i - 1] + dp[i + 1]) % 1000000000 ;
        else
            temp[i] = dp[i - 1] ;
    }
    for (int i = 0 ; i < 10 ; i ++)
    {
        dp[i] = temp[i] ;
    }
}
long long GetCount()
{
    long long result = 0 ;
    for (int i = 0 ; i < 10 ; i ++)
    {
        result = (result + dp[i]) % 1000000000 ;
    }
    return result ;
}
int main()
{
    int N ;
    cin >> N ;
    for (int i = 0 ; i < N - 1 ; i ++)
    {
        SetDP() ;
    }
    cout << GetCount() ;
    return 0 ;
}