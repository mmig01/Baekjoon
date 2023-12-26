//피보나치 수열
#include<iostream>
#include<vector>
using namespace std ;
vector<pair<int , int> > zero_one_count(41) ;
pair<int , int> fibonacci(int N)
{
    if (N == 0) 
    {
        return make_pair(1 , 0) ;
    }
    if (N == 1) 
    {
        return make_pair(0 , 1) ;
    }

    if (zero_one_count[N].first == 0 && zero_one_count[N].second == 0)
    {
        zero_one_count[N] = {fibonacci(N-1).first + fibonacci(N-2).first , fibonacci(N-1).second + fibonacci(N-2).second} ;
    }
    
    return zero_one_count[N] ;
}

int main()
{
    int T , N ;
    cin >> T ;
    for (int i = 0 ; i < T ; i ++)
    {
        cin >> N ;
        cout << fibonacci(N).first << " " << fibonacci(N).second << '\n' ;
    }
    return 0 ;
}