// 헌내기는 친구가 필요해
#include<iostream>
#include<deque>
using namespace std ;
deque< deque<char> > graph(600 , deque<char>(600 , 'O')) ;
bool is_visit[600][600] = {false} ;
int GetCount(pair<int , int> start_point , int col , int row)
{
    deque< pair<int , int> > my_dqe ;
    int x , y , count ;
    int dx[4] = {1 , -1 , 0 , 0} ;
    int dy[4] = {0 , 0 , 1 , -1} ;

    my_dqe.push_back(start_point) ;
    count = 0 ;
    while (!my_dqe.empty())
    {
        pair<int , int> cur_point ;
        cur_point = my_dqe.front() ;
        my_dqe.pop_front() ;
        for (int i = 0 ; i < 4 ; i ++)
        {
            x = cur_point.first + dx[i] ;
            y = cur_point.second + dy[i] ;
            if (x >= 0 && x < col && y >= 0 && y < row && is_visit[y][x] == false && graph[y][x] != 'X')
            {
                if (graph[y][x] == 'P')
                    count ++ ;
                my_dqe.push_back(make_pair(x , y)) ;
                is_visit[y][x] = true ;
            }
        }
    }
    return count ;
}
int main()
{
    int col , row ;
    int result ;
    cin >> row >> col ;
    for (int i = 0 ; i < row ; i ++)
        for (int j = 0 ; j < col ; j ++)
            cin >> graph[i][j] ;

    for (int i = 0 ; i < row ; i ++)
        for (int j = 0 ; j < col ; j ++)
        {
            if (graph[i][j] == 'I')
                result = GetCount(make_pair(j , i) , col , row) ;
        }
    if (result == 0)
        cout << "TT" ;
    else
        cout << result ;
    return 0 ;
}