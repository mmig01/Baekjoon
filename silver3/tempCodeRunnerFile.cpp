// Four Squares
#include<iostream>
#include<cmath>
#include<climits>
using namespace std ;
int dp[50001] ;
int Count(int N)
{
    int result = INT_MAX ;
    int cur_num , num , count ;

    for (int i = (int)sqrt(N) ; i >= 1 ; i --)
    {
        num = N ;
        count = 0 ;
        cur_num = i ;
        for (int j = cur_num ; j >= 1  ; j --)
        {
            while (true)
            {
                int diff = num - j * j ;
                if (diff < 0) break ;
                else
                {
                    num = diff ;
                    count ++ ;    
                }
            }
        }
        if (result > count && num == 0)
            result = count ;
    }
    return result ;
}
int main()
{
    int N ;
    cin >> N ;
    cout << Count(N) ;
    return 0 ;
}