#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int main()
{
    int N ;
    int x , y ;
    vector< pair <int , int> > vPoint ;
    
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> x >> y ;
        vPoint.push_back(pair <int , int>(x , y)) ;
    }

    sort(vPoint.begin() , vPoint.end()) ;
    for (int i = 0 ; i < vPoint.size() ; i ++)
    {
        cout << vPoint[i].first << " " << vPoint[i].second ;
        cout << '\n' ;
    }
    return 0 ;
}
