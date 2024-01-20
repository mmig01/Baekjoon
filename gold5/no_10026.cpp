// 적록색약
#include<iostream>
#include<deque>
using namespace std ;
void SearchRGB(deque< deque<char> > & my_graph , bool is_visit[][100] , int col , int row , pair<int , int> start_point , char target_alpha)
{
    deque< pair<int , int> > point_deque ;
    pair<int , int> current ;
    int x , y ;

    int dx[4] = {1 , -1 , 0 , 0} ;
    int dy[4] = {0 , 0 , 1 , -1} ;
    point_deque.push_back(start_point) ;
    while (true)
    {
        current = point_deque.front() ;
        is_visit[current.second][current.first] = true ;
        point_deque.pop_front() ;
        for (int i = 0 ; i < 4 ; i ++)
        {
            x = current.first + dx[i] ;
            y = current.second + dy[i] ;
            if (x > -1 && x < col && y > -1 && y < row && is_visit[y][x] == false)
            {
                if (my_graph[y][x] == target_alpha)
                {
                    is_visit[y][x] = true ;
                    point_deque.push_back(make_pair(x , y)) ;
                }
            }
        }
        if (point_deque.empty()) break ;
    } 
}
void Input(deque< deque<char> > & my_deque , int N)
{
    for (int y = 0 ; y < N ; y ++){
        for (int x = 0 ; x < N ; x ++){
            char temp ;
            cin >> temp ;
            my_deque[y].push_back(temp) ;
        }
    }
}
int GetRGBCount(deque< deque<char> > & my_deque , bool is_visit[][100] , int N , char target_alpha)
{
    int count = 0 ;
    for (int y = 0 ; y < N ; y ++){
        for (int x = 0 ; x < N ; x ++){
            if (my_deque[y][x] == target_alpha && is_visit[y][x] == false)
            {
                SearchRGB(my_deque , is_visit , N , N , make_pair(x , y) , target_alpha) ;
                count ++ ;
            } 
        }  
    }
    return count ;
}
int GetFirst(deque< deque<char> > & my_deque , int N)
{
    int count = 0 ;
    bool is_visit[100][100] = {false} ;
    char alpha[3] = {'R' , 'G' , 'B'} ;
    for (int i = 0 ; i < 3 ; i ++)
    {
        count = count + GetRGBCount(my_deque , is_visit , N , alpha[i]) ;
    }
    return count ;
}
int GetSecond(deque< deque<char> > & my_deque , int N)
{
    int count ;
    bool is_visit[100][100] = {false} ;
    char alpha[2] = {'R' , 'B'} ;
    for (int i = 0 ; i < 2 ; i ++)
    {
        count = count + GetRGBCount(my_deque , is_visit , N , alpha[i]) ;
    }
    return count ;
}
void ChangeGraph(deque< deque<char> > & my_deque , int N)
{
    for (int y = 0 ; y < N ; y ++){
        for (int x = 0 ; x < N ; x ++){
            if (my_deque[y][x] == 'G')
            {
                my_deque[y][x] = 'R' ;
            } 
        }  
    }
}
int main()
{
    deque< deque<char> > RGB_deque(100) ;
    int N , count ;
    cin >> N ;
    Input(RGB_deque , N) ;
    cout << GetFirst(RGB_deque , N) << ' ' ;
    ChangeGraph(RGB_deque , N) ;
    cout << GetSecond(RGB_deque , N) ;
    return 0 ;
}