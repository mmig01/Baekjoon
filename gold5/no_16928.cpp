// 뱀과 사다리 게임
#include<iostream>
#include<deque>
using namespace std ;
deque< pair <int , int> > ladder_and_snake_vec ;
void GetCount()
{
    deque<int> BFS_dqe ;
    int count = 0 ;
    bool is_visit[101] = {false} ;

    BFS_dqe.push_back(1) ;
    while (!BFS_dqe.empty())
    {
        int size = (int)BFS_dqe.size() ;
        for (int j = 0 ; j < size ; j ++)
        {
            int cur = BFS_dqe.front() ;
            BFS_dqe.pop_front() ;
            if (cur == 100)
            {
                cout << count ;
                return ;
            }
            for (int i = 1 ; i < 7 ; i ++)
            {
                int index = cur + i ;
                if (index <= 100)
                {
                    for (deque< pair<int , int> > ::iterator it = ladder_and_snake_vec.begin() ; it != ladder_and_snake_vec.end() ; it ++)
                    {
                        if ((*it).first == index)
                            index = (*it).second ;
                    }
                    if (is_visit[index] == false)
                    {
                        is_visit[index] = true ;
                        BFS_dqe.push_back(index) ;
                    } 
                }
            }
        }
        count ++ ;
    }
}
int main()
{
    int ladder_cnt , snake_cnt ;
    cin >> ladder_cnt >> snake_cnt ;
    for (int i = 0 ; i < ladder_cnt + snake_cnt ; i ++)
    {
        pair<int , int> temp ;
        cin >> temp.first >> temp.second ;
        ladder_and_snake_vec.push_back(temp) ;
    }
    GetCount() ;
    return 0 ;   
}