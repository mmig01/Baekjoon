// 가장 긴 증가하는 부분 수열
#include<iostream>
#include<algorithm>
using namespace std ;
int dp[1000] ;
int GetLength(int arr[] , int N)
{
    int result = 0 ;
    for (int i = 0 ; i < N ; i ++)
    {
        int cur = arr[i] ;
        int max = 0 ;
        for (int j = 0 ; j < i ; j ++)
        {
            if (max < dp[j] && arr[j] < cur)
                max = dp[j] ;
        }
        dp[i] = max + 1 ;
    }
    for (int i = 0 ; i < N ; i ++)
        result = max(result , dp[i]) ;
    return result ;
}
int main()
{
    int N ;
    int arr[1000] ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        int temp ;
        cin >> temp ;
        arr[i] = temp ;
    }
    cout << GetLength(arr , N) ;
    return 0 ;
}