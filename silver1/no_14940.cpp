// 쉬운 최단거리
#include<iostream>
#include<vector>
#include<deque>
using namespace std ;
void SetGraph(vector< vector<int> > & graph_vector , bool is_visit[][1001] , int col , int row , pair<int, int> start_point)
{
    deque< pair<int, int> > my_deque ;
    bool isResult = false ;
    int level ;
    my_deque.push_back(start_point) ;
    level = 0 ;
    while (!my_deque.empty())
    {
        int x , y ;
        int size = my_deque.size() ;
        for (size_t i = 0 ; i < size ; i ++)
        {
            pair<int , int> point = my_deque.front() ;
            x = point.first ;
            y = point.second ;
            graph_vector[y][x] = level ;
            my_deque.pop_front() ;
            if (y + 1 < row && graph_vector[y + 1][x] == 1 && is_visit[y + 1][x] == false)
            {
                my_deque.push_back(make_pair(x , y + 1)) ;
                is_visit[y + 1][x] = true ;
            }
            if (y - 1 >= 0 && graph_vector[y - 1][x] == 1 && is_visit[y - 1][x] == false)
            {
                my_deque.push_back(make_pair(x , y - 1)) ;
                is_visit[y - 1][x] = true ;
            }
            if (x + 1 < col && graph_vector[y][x + 1] == 1 && is_visit[y][x + 1] == false)
            {
                my_deque.push_back(make_pair(x + 1, y)) ;
                is_visit[y][x + 1] = true ;
            }
            if (x - 1 >= 0 && graph_vector[y][x - 1] == 1 && is_visit[y][x - 1] == false)
            {
                my_deque.push_back(make_pair(x - 1 , y)) ;
                is_visit[y][x - 1] = true ;
            }
        }
        level ++ ;
    }
}
void SetImpossiblePoint(vector< vector<int> > & graph_vector , bool is_visit[][1001] , int col , int row)
{
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            if (graph_vector[i][j] == 1 && is_visit[i][j] == false)
                graph_vector[i][j] = -1 ;
        }
    }
}
int main()
{
    vector< vector<int> > my_graph(1001) ;
    bool is_visit[1001][1001] = {false} ;
    pair<int , int> start_point ;
    int col , row ;
    cin >> row >> col ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            int temp ;
            cin >> temp ;
            my_graph[i].push_back(temp) ;
        }
    }
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            if (my_graph[i][j] == 2)
            {
                start_point = make_pair(j , i) ;
                break ;
            }
        }
    }
    SetGraph(my_graph , is_visit , col , row , start_point) ;
    SetImpossiblePoint(my_graph , is_visit , col , row) ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            cout << my_graph[i][j] << ' ' ;
        }
        cout << '\n' ;
    }
    exit(0) ;
}