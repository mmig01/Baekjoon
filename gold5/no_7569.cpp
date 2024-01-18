// 토마토
#include<iostream>
#include<deque>
using namespace std ;
struct point
{
    int x ;
    int y ;
    int z ;
} ;
bool RipeCheck(deque< deque< deque<int> > > & my_deque , int col , int row , int height)
{
    bool is_ripe = true ;
    for (int h = 0 ; h < height ; h ++)
    {
        for (int r = 0 ; r < row ; r ++)
        {
            for (int c = 0 ; c < col ; c ++)
            {
                if (my_deque[h][r][c] == 0)
                {
                    is_ripe = false ;
                    break ;
                }
            }
        }
    }
    return is_ripe ;
}
bool ImpossibleRipeCheck(deque< deque< deque<int> > > & my_deque , int col , int row , int height)
{
    bool is_impossible = false ;
    for (int h = 0 ; h < height ; h ++)
    {
        for (int r = 0 ; r < row ; r ++)
        {
            for (int c = 0 ; c < col ; c ++)
            {
                if (my_deque[h][r][c] == 0)  
                    is_impossible = true ;
            }
        }
    }
    return is_impossible ;
}
int GetTomatoCount(deque< deque< deque<int> > > & my_deque , bool is_visit[][100][100] , int col , int row , int height)
{
    int result = - 1 ;
    deque<point> point_deque ;
    point element ;
    for (int h = 0 ; h < height ; h ++)
    {
        for (int r = 0 ; r < row ; r ++)
        {
            for (int c = 0 ; c < col ; c ++)
            {
                if (my_deque[h][r][c] == 1)
                {
                    element.x = c ;
                    element.y = r ;
                    element.z = h ;
                    point_deque.push_back(element) ;
                    is_visit[h][r][c] = true ;
                }
            }
        }
    }
    
    while (!point_deque.empty())
    {
        int x , y , z ;
        int size = point_deque.size() ;
        for (int i = 0 ; i < size ; i ++)
        {
            point temp = point_deque.front() ;
            x = temp.x ;
            y = temp.y ;
            z = temp.z ;
            point_deque.pop_front() ;
            if (x + 1 < col && my_deque[z][y][x + 1] == 0 && is_visit[z][y][x + 1] == false)
            {
                my_deque[z][y][x + 1] = 1 ;
                is_visit[z][y][x + 1] = true ;
                element.x = x + 1 ;
                element.y = y ;
                element.z = z ;
                point_deque.push_back(element) ;
            }
            if (x - 1 >= 0 && my_deque[z][y][x - 1] == 0 && is_visit[z][y][x - 1] == false)
            {
                my_deque[z][y][x - 1] = 1 ;
                is_visit[z][y][x - 1] = true ;
                element.x = x - 1 ;
                element.y = y ;
                element.z = z ;
                point_deque.push_back(element) ;
            }
            if (y + 1 < row && my_deque[z][y + 1][x] == 0 && is_visit[z][y + 1][x] == false)
            {
                my_deque[z][y + 1][x] = 1 ;
                is_visit[z][y + 1][x] = true ;
                element.x = x ;
                element.y = y + 1 ;
                element.z = z ;
                point_deque.push_back(element) ;
            }
            if (y - 1 >= 0 && my_deque[z][y - 1][x] == 0 && is_visit[z][y - 1][x] == false)
            {
                my_deque[z][y - 1][x] = 1 ;
                is_visit[z][y - 1][x] = true ;
                element.x = x ;
                element.y = y - 1 ;
                element.z = z ;
                point_deque.push_back(element) ;
            }
            if (z + 1 < height && my_deque[z + 1][y][x] == 0 && is_visit[z + 1][y][x] == false)
            {
                my_deque[z + 1][y][x] = 1 ;
                is_visit[z + 1][y][x] = true ;
                element.x = x ;
                element.y = y ;
                element.z = z + 1 ;
                point_deque.push_back(element) ;
            }
            if (z - 1 >= 0 && my_deque[z - 1][y][x] == 0 && is_visit[z - 1][y][x] == false)
            {
                my_deque[z - 1][y][x] = 1 ;
                is_visit[z - 1][y][x] = true ;
                element.x = x ;
                element.y = y ;
                element.z = z - 1 ;
                point_deque.push_back(element) ;
            }
        }
        result ++ ;
    }
    return result ;
}
int main()
{
    deque< deque< deque<int> > > tomato_deque(100 , deque<deque <int> >(100 , deque<int>(100 , 0))) ;
    bool is_visit[100][100][100] = {false} ;
    int row , col , height ;
    int result ;
    cin >> col >> row >> height ;
    for (int h = 0 ; h < height ; h ++)
    {
        for (int r = 0 ; r < row ; r ++)
        {
            for (int c = 0 ; c < col ; c ++)
            {
                int num ;
                cin >> num ;
                tomato_deque[h][r][c] = num ;
            }
        }
    }
    
    if (RipeCheck(tomato_deque , col , row , height))
    {
        result = 0 ;
    }
    else
    {
        result = GetTomatoCount(tomato_deque , is_visit , col , row , height) ;
        if (ImpossibleRipeCheck(tomato_deque , col , row , height))
            result = -1 ;
    }
    cout << result ;
    return 0 ;
}