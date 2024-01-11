//미로 탐색
#include<iostream>
#include<vector>
#include<deque>
using namespace std ;
int GetCount(vector< vector<int> > & my_vector , bool is_visit[][100] , int col , int row)
{
    deque< pair<int, int> > my_deque ;
    my_deque.push_back(make_pair(0,0)) ;
    bool isResult = false ;
    int result ;
    int count = 1 ;
    while (!my_deque.empty())
    {
        int size = my_deque.size() ;
        for (size_t i = 0 ; i < size ; i ++)
        {
            pair<int , int> point = my_deque.front() ;
            my_deque.pop_front() ;
            if (point.first == col - 1 && point.second == row - 1)
            {
                result = count ;
                isResult = true ;
                break ;
            }
            int x , y ;
            x = point.first ;
            y = point.second ;
            if (y + 1 < row && my_vector[y + 1][x] == 1 && is_visit[y + 1][x] == false)
            {
                my_deque.push_back(make_pair(x , y + 1)) ;
                is_visit[y + 1][x] = true ;
            }
            if (y - 1 >= 0 && my_vector[y - 1][x] == 1 && is_visit[y - 1][x] == false)
            {
                my_deque.push_back(make_pair(x , y - 1)) ;
                is_visit[y - 1][x] = true ;
            }
            if (x + 1 < col && my_vector[y][x + 1] == 1 && is_visit[y][x + 1] == false)
            {
                my_deque.push_back(make_pair(x + 1, y)) ;
                is_visit[y][x + 1] = true ;
            }
            if (x - 1 >= 0 && my_vector[y][x - 1] == 1 && is_visit[y][x - 1] == false)
            {
                my_deque.push_back(make_pair(x - 1 , y)) ;
                is_visit[y][x - 1] = true ;
            }
        }
        if (isResult == true)
            break ;
        else
            count ++ ;
    }
    return result ;
}
int main()
{
    bool is_visit[100][100] = {false} ;
    vector< vector<int> > my_vector(100) ;
    int col , row ;
    char c ;
    cin >> row >> col ;
    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            cin >> c ;
            if (c < char(48) || c > char(49))
            {
                cin >> c ;
            }
            if (c == char(48))  
                my_vector[i].push_back(0) ;
            else
                my_vector[i].push_back(1) ;
        }
    }
    cout << GetCount(my_vector , is_visit , col , row) ;
    exit(0) ;
}