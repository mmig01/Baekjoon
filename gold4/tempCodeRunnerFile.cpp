// 테트로미노
#include<iostream>
#include<deque>
#include<algorithm>
#include<map>
using namespace std ;
deque< deque<int> > graph(500 ,deque<int>(500)) ;
map< pair<int , int> , int> point_and_sum ;
map< pair<int , int> , int> point_and_count ;
int dx[4] = {1 , -1 , 0 , 0} ;
int dy[4] = {0 , 0 , 1 , -1} ;
bool is_visit[500][500] = {false} ;
int CrossCheck(pair<int , int> start_pt , int col , int row)
{
    int result = 0 , x , y , total_sum ; 
    int cross_sum[4] = {0 , 0 , 0 , 0} ;
    total_sum = graph[start_pt.second][start_pt.first] ;
    for (int i = 0 ; i < 4 ; i ++)
    {
        x = start_pt.first + dx[i] ;
        y = start_pt.second + dy[i] ;
        if (x >= 0 && x < col && y >= 0 && y < row)
            cross_sum[i] = graph[y][x] ;
        total_sum = total_sum + cross_sum[i] ;
    }
    for (int i = 0 ; i < 4 ; i ++)
    {
        int temp = total_sum - cross_sum[i] ;
        result = max(temp , result) ;
    }
    return result ;
}
void Clear(pair<int , int> start_pt , int col , int row)
{
    int start_x = max(start_pt.first - 8 , 0) ;
    int end_x = min(start_pt.first + 9 , col) ;
    int start_y = max(start_pt.second - 8 , 0) ;
    int end_y = min(start_pt.second + 9 , row) ;
    for (int i = start_y ; i < end_y ; i ++)
        for (int j = start_x ; j < end_x ; j ++)
            is_visit[i][j] = false ;
}
int DFS(pair<int , int> start_pt , int col , int row)
{
    deque< pair<int , int> > my_dqe ;
    int result , x , y ;

    result = CrossCheck(start_pt , col , row) ;
    my_dqe.push_back(start_pt) ;
    point_and_sum[start_pt] = graph[start_pt.second][start_pt.first] ;
    point_and_count[start_pt] = 1 ;
    while (!my_dqe.empty())
    {
        pair<int , int> cur = my_dqe.back() ;
        my_dqe.pop_back() ;
        is_visit[cur.second][cur.first] = true ;
        for (int i = 0 ; i < 4 ; i ++)
        {
            x = cur.first + dx[i] ;
            y = cur.second + dy[i] ;
            if (x >= 0 && x < col && y >= 0 && y < row && is_visit[y][x] == false)
            {
                pair<int , int> temp = make_pair(x , y) ;
                if (point_and_count[cur] == 3)
                    result = max(result , point_and_sum[cur] + graph[y][x]) ;
                else if (point_and_count[cur] < 3)
                {
                    my_dqe.push_back(temp) ;
                    point_and_sum[temp] = point_and_sum[cur] + graph[y][x] ;
                    point_and_count[temp] = point_and_count[cur] + 1 ;
                }    
            }
        }
    }
    return result ;
}
int main()
{
    int col , row , result = 0 ;
    cin >> row >> col ;
    for (int r = 0 ; r < row ; r ++)
        for (int c = 0 ; c < col ; c ++)
            cin >> graph[r][c] ;
    for (int r = 0 ; r < row ; r ++)
        for (int c = 0 ; c < col ; c ++)
        {
            point_and_count.clear() ;
            point_and_sum.clear() ;
            Clear(make_pair(c , r) , col , row) ;
            result = max(result , DFS(make_pair(c , r) , col , row)) ;
        }
    cout <<  result ;
    //cout << CrossCheck(make_pair(0 , 1) , col , row) ;
    return 0 ;
}