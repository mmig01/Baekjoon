// 바이러스
#include<iostream>
#include<deque>
using namespace std ;
int BFS(deque< deque<int> > & virus , bool * is_visit)
{
    deque<int> my_deque ;
    int result = 0 ;
    my_deque.push_back(1) ;
    while (!my_deque.empty())
    {
        int step ;
        step = my_deque.front() ;
        my_deque.pop_front() ;
        is_visit[step] = true ;
        for (size_t i = 0 ; i < virus[step].size() ; i ++)
        {
            int current = virus[step][int(i)] ;
            if (current != 0 && is_visit[current] == false)
            {
                is_visit[current] = true ;
                result ++ ;
                my_deque.push_back(current) ;
            }
        }
    } 
    return result ;
}
int main()
{
    deque< deque<int> > virus(101) ;
    bool is_visit[101] = {false} ;
    int computer_count , pair_count ;
    pair<int , int> temp ;
    cin >> computer_count ;
    cin >> pair_count ;
    
    for (int i = 0 ; i < pair_count ; i ++)
    {
        cin >> temp.first >> temp.second ;
        virus[temp.first].push_back(temp.second) ;
        virus[temp.second].push_back(temp.first) ;
    }

    cout << BFS(virus , is_visit) ;
    return 0 ;
}