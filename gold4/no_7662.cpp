// 이중 우선순위 큐
#include<iostream>
#include<queue>
#include<map>
using namespace std ;
priority_queue<int , vector<int>> max_pq ;
priority_queue<int , vector<int>, greater<int> > min_pq ;
map<int , int> count ;
void Input()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    char c ;
    int num , length ;
    cin >> length ;
    for (int i = 0 ; i < length ; i ++)
    {
        cin >> c >> num ;
        if (c == 'I')
        {
            max_pq.push(num) ;
            min_pq.push(num) ;
            count[num] ++ ;
        }
        else if (c == 'D')
        {
            if (num == 1)
            {
                if (!max_pq.empty())
                {
                    count[max_pq.top()] -- ;
                    max_pq.pop() ;
                }
            }
            else
            {
                if (!min_pq.empty())
                {
                    count[min_pq.top()] -- ;
                    min_pq.pop() ;
                }
            }
        }
        while (!max_pq.empty() && count[max_pq.top()] == 0)
        {
            max_pq.pop() ;
        }
        while (!min_pq.empty() && count[min_pq.top()] == 0)
        {
            min_pq.pop() ;
        }
    }
}
int main()
{
    int test_case ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        while (!max_pq.empty())
        {
            max_pq.pop() ;
        }
        while (!min_pq.empty())
        {
            min_pq.pop() ;
        }
        count.clear() ;
        Input() ;
        if (max_pq.empty() || min_pq.empty())
            cout << "EMPTY\n" ;
        else
        {
            cout << max_pq.top() << ' ' ;
            cout << min_pq.top() << '\n' ;
        }
    }
    exit(0) ;
}