// 연속 합
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std ;
int dp[100001] ;
int arr[100001] ;
int GetCount(int N)
{
    int result = INT_MIN ;
    for (int i = 1 ; i <= N ; i ++)
    {
        dp[i] = max(dp[i - 1] + arr[i] , arr[i]) ;
    }
    for (int i = 1 ; i <= N ; i ++)
        result = max(result , dp[i]) ;
    return result ;
}
int main()
{
    int length ;
    cin >> length ;
    for (int i = 1 ; i <= length ; i ++)
        cin >> arr[i] ;
    cout << GetCount(length) ;
    return 0 ;
}