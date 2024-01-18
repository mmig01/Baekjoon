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
    for (int h = 0 ; h < height ; h ++){
        for (int r = 0 ; r < row ; r ++){
            for (int c = 0 ; c < col ; c ++){
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
    for (int h = 0 ; h < height ; h ++){
        for (int r = 0 ; r < row ; r ++){
            for (int c = 0 ; c < col ; c ++){
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
    int dx[6] = {1 , -1 , 0 , 0 , 0 , 0} ;
    int dy[6] = {0 , 0 , 1 , -1 , 0 , 0} ;
    int dz[6] = {0 , 0 , 0 , 0 , 1 , -1} ;
    for (int h = 0 ; h < height ; h ++){
        for (int r = 0 ; r < row ; r ++){
            for (int c = 0 ; c < col ; c ++){
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
        for (int j = 0 ; j < size ; j ++){
            point temp = point_deque.front() ;
            point_deque.pop_front() ;
            for (int i = 0 ; i < 6 ; i ++){
                x = temp.x + dx[i] ;
                y = temp.y + dy[i] ;
                z = temp.z + dz[i] ;
                if (x > -1 && x < col && y > -1 && y < row && z > -1 && z < height && is_visit[z][y][x] == false && my_deque[z][y][x] == 0)
                {
                    element.x = x ;
                    element.y = y ;
                    element.z = z ;
                    my_deque[z][y][x] = 1 ;
                    is_visit[z][y][x] = true ;
                    point_deque.push_back(element) ;
                }
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
    for (int h = 0 ; h < height ; h ++){
        for (int r = 0 ; r < row ; r ++){
            for (int c = 0 ; c < col ; c ++){
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