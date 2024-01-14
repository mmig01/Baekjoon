// 토마토
#include<iostream>
#include<deque>
using namespace std ;
bool RipeCheck(deque< deque<int> > & my_deque , int col , int row)
{
    bool is_ripe = true ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            if (my_deque[i][j] == 0)
            {
                is_ripe = false ;
                break ;
            }
        }
    }
    return is_ripe ;
}
bool ImpossibleRipeCheck(deque< deque<int> > & my_deque , int col , int row)
{
    bool is_impossible = false ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            if (my_deque[i][j] == 0)  
                is_impossible = true ;
        }
    }
    return is_impossible ;
}
int GetTomatoCount(deque< deque<int> > & my_deque , bool is_visit[][1000] , int col , int row)
{
    int result = - 1 ;
    deque< pair<int , int> > point_deque ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            if (my_deque[i][j] == 1)
            {
                point_deque.push_back(make_pair(j , i)) ;
                is_visit[i][j] = true ;
            }
        }
    }
    while (!point_deque.empty())
    {
        int x , y ;
        int size = point_deque.size() ;
        for (size_t i = 0 ; i < size ; i ++)
        {
            x = point_deque.front().first ;
            y = point_deque.front().second ;
            point_deque.pop_front() ;
            if (x + 1 < col && my_deque[y][x + 1] == 0 && is_visit[y][x + 1] == false)
            {
                my_deque[y][x + 1] = 1 ;
                is_visit[y][x + 1] = true ;
                point_deque.push_back(make_pair(x + 1 , y)) ;
            }
            if (x - 1 >= 0 && my_deque[y][x - 1] == 0 && is_visit[y][x - 1] == false)
            {
                my_deque[y][x - 1] = 1 ;
                is_visit[y][x - 1] = true ;
                point_deque.push_back(make_pair(x - 1 , y)) ;
            }
            if (y + 1 < row && my_deque[y + 1][x] == 0 && is_visit[y + 1][x] == false)
            {
                my_deque[y + 1][x] = 1 ;
                is_visit[y + 1][x] = true ;
                point_deque.push_back(make_pair(x , y + 1)) ;
            }
            if (y - 1 >= 0 && my_deque[y - 1][x] == 0 && is_visit[y - 1][x] == false)
            {
                my_deque[y - 1][x] = 1 ;
                is_visit[y - 1][x] = true ;
                point_deque.push_back(make_pair(x , y - 1)) ;
            }
        }
        result ++ ;
    }
    return result ;
}
int main()
{
    deque< deque<int> > tomato_deque(1000) ;
    bool is_visit[1000][1000] = {false} ;
    int row , col ;
    int result ;
    cin >> col >> row ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            int temp ;
            cin >> temp ;
            tomato_deque[i].push_back(temp) ;
        }
    }
    
    if (RipeCheck(tomato_deque , col , row))
    {
        result = 0 ;
    }
    else
    {
        result = GetTomatoCount(tomato_deque , is_visit , col , row) ;
        if (ImpossibleRipeCheck(tomato_deque , col , row))
            result = -1 ;
    }
    cout << result ;
    return 0 ;
}