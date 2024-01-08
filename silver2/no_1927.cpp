//최소 힙
#include<iostream>
#include<queue>
using namespace std ;
int main()
{
    cin.tie(nullptr) ;
    priority_queue<int , vector<int> , greater<int>> test ;
    int N ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        int num ;
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
    exit(0) ;
}