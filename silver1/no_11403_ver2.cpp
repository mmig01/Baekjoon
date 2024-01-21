// 최단 경로
#include<iostream>
#include<deque>
using namespace std ;
deque<deque <int> > test(100) ;
void DFS(int vertex , deque<int> & visit)
{
    deque<int> bucket ;
    int cur;
    bucket.push_back(vertex) ;
    while (!bucket.empty())
    {
        vertex = bucket.back() ;
        bucket.pop_back() ;
        for (size_t i = 0 ; i < test[vertex].size() ; i ++)
        {
            cur = test[vertex][i] ;
            if (visit[cur] == 0)
            {
                visit[cur] = 1 ;
                bucket.push_back(cur) ;
            }
        }
    } 
}
void Clear(deque<int> & visit)
{
    for (int i = 0 ; i < 100 ; i ++)
        visit[i] = 0 ;
}
int main()
{
    int test_case ;
    deque<int> visit(100) ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        for (int j = 0 ; j < test_case ; j ++)
        {
            int temp ;
            cin >> temp ;
            if (temp == 1)
                test[i].push_back(j) ;
        }
    }
    for (int i = 0 ; i < test_case ; i ++){
        Clear(visit) ;
        DFS(i , visit) ;
        for (int j = 0 ; j < test_case ; j ++)
            cout << visit[j] << ' ' ;
        cout << '\n' ;
    }
    return 0 ;
}