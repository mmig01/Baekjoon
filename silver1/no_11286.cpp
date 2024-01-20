// 절댓값 힙
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std ;
struct Compare
{
    bool operator()(int a , int b)
    {
        if (abs(a) == abs(b))
            return a > b ;
        else
            return abs(a) > abs(b) ;
    }
} ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    priority_queue<int , vector<int> , Compare> test ;
    int test_case , num ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> num ;
        if (num == 0)
        {
            if (test.empty())
                cout << 0 << '\n' ;
            else
            {
                cout << test.top() << '\n' ;
                test.pop() ;
            }
        }
        else
            test.push(num) ;
    }
    return 0 ;
}