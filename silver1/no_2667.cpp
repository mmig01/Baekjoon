//단지 번호 붙이기
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std ;
int BFS(deque< deque<int> > & my_deque , bool is_visit[][25] , pair<int , int> start_point , int N)
{
    deque< pair<int , int> > BFS_deque ;
    int x , y ;
    int count = 1 ;
    BFS_deque.push_back(start_point) ;
    is_visit[start_point.second][start_point.first] = true ;
    while (!BFS_deque.empty())
    {
        pair<int , int> current_point ;
        current_point = BFS_deque.front() ;
        BFS_deque.pop_front() ;
        x = current_point.first ;
        y = current_point.second ;
        if ( (x + 1) < N && (my_deque[y][x + 1] == 1) && (is_visit[y][x + 1] == false) )
        {
            BFS_deque.push_back(make_pair(x + 1 , y)) ;
            is_visit[y][x + 1] = true ;
            count ++ ;
        }
        if ( (x - 1) >= 0 && (my_deque[y][x - 1] == 1) && (is_visit[y][x - 1] == false) )
        {
            BFS_deque.push_back(make_pair(x - 1 , y)) ;
            is_visit[y][x - 1] = true ;
            count ++ ;
        }
        if ( (y + 1) < N && (my_deque[y + 1][x] == 1) && (is_visit[y + 1][x] == false) )
        {
            BFS_deque.push_back(make_pair(x , y + 1)) ;
            is_visit[y + 1][x] = true ;
            count ++ ;
        }
        if ( (y - 1) >= 0 && (my_deque[y - 1][x] == 1) && (is_visit[y - 1][x] == false) )
        {
            BFS_deque.push_back(make_pair(x , y - 1)) ;
            is_visit[y - 1][x] = true ;
            count ++ ;
        }
    }
    return count ;
}
int main()
{
    deque< deque<int> > apartment(25) ;
    deque<int> result_deque ;
    int apartment_count ;
    char c ;
    bool is_visit[25][25] = {false} ;
    cin >> apartment_count ;
    cin.get() ;
    for (int i = 0 ; i < apartment_count ; i ++)
    {
        for (int j = 0 ; j < apartment_count ; j ++)
        {
            cin >> c ;
            apartment[i].push_back(c - 48) ;
        }
    }
    for (int i = 0 ; i < apartment_count ; i ++)
    {
        for (int j = 0 ; j < apartment_count ; j ++)
        {
            if (apartment[i][j] == 1 && is_visit[i][j] == false)
                result_deque.push_back(BFS(apartment , is_visit , make_pair(j , i) , apartment_count)) ;
        }
    }
    sort(result_deque.begin() , result_deque.end()) ;
    cout << result_deque.size() << '\n' ;
    for (deque<int>::iterator it = result_deque.begin() ; it != result_deque.end() ; it ++)
    {
        cout << *it << '\n' ;
    }
    return 0 ;
}