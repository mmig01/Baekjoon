//Z
#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;
int search_Z(pair<int , int> & start_point , pair<int , int> & target_point , int N , int start_count)
{
    int count ;
    if (N == 0)
    {
        return start_count ;
    }
    //cout << start_count << '\n' ;
    //cout << start_point.first << " , " << start_point.second << '\n' ;
    if (target_point.first >= pow(2 , N - 1) + start_point.first)
    {
        if (target_point.second >= pow(2 , N - 1) + start_point.second)
        {
            start_point.first = start_point.first + pow(2 , N - 1) ;
            start_point.second = start_point.second + pow(2 , N - 1) ;
            count = search_Z(start_point , target_point , N - 1 , start_count + 3 * pow(4 , N - 1)) ;
        }
        else
        {
            start_point.first = start_point.first + pow(2 , N - 1) ;
            count = search_Z(start_point , target_point , N - 1 , start_count + pow(4 , N - 1)) ;
        }
    }
    else
    {
        if (target_point.second >= pow(2 , N - 1) + start_point.second)
        {
            start_point.second = start_point.second + pow(2 , N - 1) ;
            count = search_Z(start_point , target_point , N - 1 , start_count + 2 * pow(4 , N - 1)) ;
        }
        else
        {
            count = search_Z(start_point , target_point , N - 1 , start_count) ;
        }
    }
    return count ;
}
int main()
{
    int N ;
    int r , c ;
    cin >> N >> r >> c ;
    pair<int , int> start_point = make_pair(0 , 0) ;
    pair<int , int> target_point = make_pair(c, r) ;
    cout << search_Z(start_point , target_point , N , 0) ;
    return 0 ;
}