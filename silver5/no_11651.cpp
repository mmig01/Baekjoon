// 좌표 정렬하기 2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
typedef pair<int , int> pair_num ;
int main()
{
    vector<pair_num> x_and_y ;
    vector<pair_num> swaped_x_y ;
    int N , x , y ;

    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {  
        cin >> x >> y ;
        swaped_x_y.push_back(make_pair(y , x)) ;
    }
    sort(swaped_x_y.begin() , swaped_x_y.end()) ;

    for (int i = 0 ; i < N ; i ++)
    {
        x = swaped_x_y[i].second ;
        y = swaped_x_y[i].first ;
        x_and_y.push_back(make_pair(x , y)) ;
    }

    for (int i = 0 ; i < N ; i ++)
    {
        cout << x_and_y[i].first << " " << x_and_y[i].second ;
        cout << '\n' ;
    }
    exit(0) ;
}