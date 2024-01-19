// 파도반 수열
#include<iostream>
using namespace std ;
long long dp[101] ;
long long Fa(int N)
{
    long long result ;
    int start_num = 6 ;
    if (N <= 5)
        result = dp[N] ;
    else
    {
        while (true)
        {
            dp[start_num] = dp[start_num - 1] + dp[start_num - 5] ;
            start_num ++ ;
            if (start_num > N)
            break ;
        }
        result = dp[N] ;
    }
    return result ;
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    int test_case ;
    int N ;
    dp[1] = 1 ;
    dp[2] = 1 ;
    dp[3] = 1 ;
    dp[4] = 2 ;
    dp[5] = 2 ;

    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> N ;
        cout << Fa(N) << '\n' ;
    }
    return 0 ;
}