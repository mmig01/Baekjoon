#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    int x , y , N ;
    int iCount ;
    vector<pair<int , int> > vArr ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> x >> y ;
        vArr.push_back(make_pair(x , y)) ;
    }
    
    for (int i = 0 ; i < N ; i ++) 
    {
        iCount = 0 ;
        for (int j = 0 ; j < N ; j ++)
        {
            if (vArr[i].first < vArr[j].first)
            {
                if (vArr[i].second < vArr[j].second)
                {
                    iCount ++ ;
                }
            }
        } 
        cout << iCount + 1 << " " ;
    }

    exit(0) ;
}