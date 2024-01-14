// 1 , 2 , 3 더하기
#include<iostream>
using namespace std ;
int dp[12] ;
int Plus(int N)
{
    if (N == 1)
        return 1 ;
    else if (N == 2)
        return 2 ;
    else if (N == 3)
        return 4 ;
    else
    {
        if (dp[N] == 0)
        {
            dp[N] = Plus(N - 1) + Plus(N - 2) + Plus(N - 3) ;
        }
        return dp[N] ;
    }
}
int main()
{
    int N ;
    int test_case ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> N ;
        cout << Plus(N) << '\n' ;
    }
    return 0 ;
}