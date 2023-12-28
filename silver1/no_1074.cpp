//Z
#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;
int search_Z(pair<int , int> point , int N , int start_count)
{
    int count ;
    if (N == 0)
    {
        return start_count ;
    }
    if (point.first <= pow(2 , N - 1))
    {
        if (point.second <= pow(2 , N - 1))
        {
            count = search_Z(point , N - 1 , start_count + 3 * pow(4 , N - 1)) ;
        }
        else
        {
            count = search_Z(point , N - 1 , start_count + pow(4 , N - 1)) ;
        }
    }
    else
    {
        if (point.second <= pow(2 , N - 1))
        {
            count = search_Z(point , N - 1 , start_count + (2 * pow(4 , N - 1))) ;
        }
        else
        {
            count = search_Z(point , N - 1 , start_count) ;
        }
    }
    return count ;
}
int main()
{
    pair<int , int> temp = make_pair(1, 3) ;
    cout << search_Z(temp , 2 , 0) ;
}