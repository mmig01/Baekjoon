// 계단 오르기
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
vector<int> step_score(301) ;
int dp[301][3] ;
void clear()
{
    for (int i = 0 ; i < 301 ; i ++)
    {
        for (int j = 0 ; j < 3 ; j ++)
            dp[i][j] = 0 ;
    }
}
int FUN(int target_index)
{
    int result ;
    int i = 2 ;
    dp[1][1] = dp[1][2] = step_score[1] ;
    if (target_index == 1)
        result = step_score[1] ;
    else
    {
        while (true)
        {
            dp[i][1] = dp[i - 1][2] + step_score[i] ;
            dp[i][2] = max(dp[i - 2][1] , dp[i - 2][2]) + step_score[i] ;
            i ++ ;
            if (i > target_index) 
                break ;
        }
        result = max(dp[target_index][1] , dp[target_index][2]) ;
    }
    return result ;
}
int main()
{
    int count ;
    clear() ;
    cin >> count ;
    for (int i = 0 ; i < count ; i ++)
    {
        int temp ;
        cin >> temp ;
        step_score[i + 1] = temp ;
    }
    cout << FUN(count) ;
    exit(0) ;
}