//유기농배추
#include<iostream>
#include<vector>
using namespace std ;
int tile[50][50] ;
bool already_counted[50][50] ;
void clear()
{
    for (int i = 0 ; i < 50 ; i ++)
    {
        for (int j = 0 ; j < 50 ; j ++)
        {
            tile[i][j] = 0 ;
            already_counted[i][j] = false ;
        }
    }
}
int check_tile(int col , int row , int start_x , int start_y)
{
    int x ;
    int y ;
    int count = 1 ;
    vector<pair<int , int>> pair_of_points ;
    
    if (already_counted[start_y][start_x] == true)
    {
        return 0 ;
    }

    pair_of_points.clear() ;
    pair_of_points.push_back(make_pair(start_x , start_y)) ;
    while (true)
    {
        x = pair_of_points.back().first ;
        y = pair_of_points.back().second ;
        pair_of_points.pop_back() ;
        already_counted[y][x] = true ;
        if ((x + 1 < col) && (tile[y][x + 1] == 1))
        {
            if (already_counted[y][x + 1] == false)
            {
                pair_of_points.push_back(make_pair(x + 1 , y)) ;
            } 
        }
        if ((y + 1 < row) && (tile[y + 1][x] == 1))
        {
            if (already_counted[y + 1][x] == false)
            {
                pair_of_points.push_back(make_pair(x , y + 1)) ;
            }
        }
        if ((x >= 1) && (tile[y][x - 1] == 1))
        {
            if (already_counted[y][x - 1] == false)
            {
                pair_of_points.push_back(make_pair(x - 1 , y)) ;
            } 
        }
        if ((y >= 1) && (tile[y - 1][x] == 1))
        {
            if (already_counted[y - 1][x] == false)
            {
                pair_of_points.push_back(make_pair(x , y - 1)) ;
            }
        }
        if (pair_of_points.empty()) break ;
    } 
    return count ;  
}
int main()
{
    int test ;
    int col , row , total_point ;
    int point_X , point_Y ;
    int count ;
    
    cin >> test ;
    for (int i = 0 ; i < test ; i ++)
    {
        clear();
        count = 0 ;
        cin >> col >> row >> total_point ;
        for (int j = 0 ; j < total_point ; j ++)
        {
            cin >> point_X >> point_Y ;
            tile[point_Y][point_X] = 1 ;
        }

        for (int y = 0 ; y < row ; y ++)
        {
            for (int x = 0 ; x < col ; x ++)
            {
                if (tile[y][x] == 1)
                    count = count + check_tile(col , row , x , y) ;
            }
        }
        cout << count << '\n' ;
    }
    return 0 ;
}