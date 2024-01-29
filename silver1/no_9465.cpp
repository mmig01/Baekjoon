// 스티커
#include<iostream>
#include<algorithm>
using namespace std ;
int sticker[2][100001] ;
int dp[2][100001] ;
int GetCount(int N)
{
    int result = 0 ;
    dp[0][1] = sticker[0][1] ;
    dp[1][1] = sticker[1][1] ;
    for (int i = 2 ; i <= N ; i ++)
    {
        dp[0][i] = max(dp[1][i - 1] , max(dp[0][i - 2] , dp[1][i - 2]))+ sticker[0][i] ;
        dp[1][i] = max(dp[0][i - 1] , max(dp[0][i - 2] , dp[1][i - 2]))+ sticker[1][i] ;
    }
    for (int i = 1 ; i <= N ; i ++)
        result = max(result , max(dp[0][i] , dp[1][i])) ;
    return result ;
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int test_case ;
    int length ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> length ;
        for (int k = 0 ; k < 2 ; k ++)
            for (int j = 1 ; j <= length ; j ++)
                cin >> sticker[k][j] ;
        cout << GetCount(length) << '\n' ;
    }
    return 0 ;
}