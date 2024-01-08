//듣보잡
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std ;
int main()
{
    vector<string> test ;
    vector<string> result ;
    int N , M ;
    int total = 0 ;
    cin >> N >> M ;
    for (int i = 0 ; i < M + N ; i ++)
    {
        string temp ;
        cin >> temp ;
        test.push_back(temp) ;
    }
    sort(test.begin() , test.end()) ;
    for (int i = 0 ; i < M + N - 1; i ++)
    {
        if (test[i] == test[i + 1])
        {
            total ++ ;
            result.push_back(test[i]) ;
        }
    }
    cout << total << '\n' ;
    for (size_t i = 0 ; i < result.size() ; i ++)
    {
       cout << result[i] << '\n' ;
    }
    
    exit(0) ;
}