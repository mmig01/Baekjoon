//숨바꼭질
#include<iostream>
#include<deque>
using namespace std ;
int dp[200001] ;
int Count(int initial_num , int target_num)
{
    int total_count ;
    int current_point ;
    int moved_point ;
    bool isResult = false ;
    deque<int> my_deque ;
    if (initial_num == target_num)
        total_count = 0 ;
    else
    {
        my_deque.push_back(initial_num) ;
        while(!my_deque.empty())
        {
            current_point = my_deque.front() ;
            my_deque.pop_front() ;
            for (int i = 0 ; i < 3 ; i ++)
            {
                if (i == 0)
                    moved_point = current_point - 1 ;
                else if (i == 1)
                    moved_point = current_point + 1 ;
                else
                    moved_point = current_point * 2 ;


                if (moved_point == target_num)
                {
                    total_count = 1 + dp[current_point] ;
                    isResult = true ;
                    break ;
                }
                else if (moved_point < 0 || moved_point > 200000)
                    continue ;
                else if (dp[moved_point] >= 1)
                    continue ; 
                else
                {
                    my_deque.push_back(moved_point) ;
                    dp[moved_point] = 1 + dp[current_point] ;
                }
            }
            if (isResult == true)
                break ;
        }
    }
    return total_count ;
}
int main()
{
    int N , M ;
    cin >> N >> M ;
    cout << Count(N , M) ;
    exit(0) ;
}