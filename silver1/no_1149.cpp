// RGB 거리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int dp_R[1001] ;
int dp_G[1001] ;
int dp_B[1001] ;
int GetCount(vector< vector<int> > & my_vec , int N)
{
    int result ;
    for (int i = 0 ; i < N ; i ++)
    {
        int index = i + 1 ;
        dp_R[index] = min(dp_G[index - 1] , dp_B[index - 1]) + my_vec[index][0] ;
        dp_G[index] = min(dp_B[index - 1] , dp_R[index - 1]) + my_vec[index][1] ;
        dp_B[index] = min(dp_R[index - 1] , dp_G[index - 1]) + my_vec[index][2] ;
    }
    result = min(min(dp_R[N] , dp_G[N]) , dp_B[N]) ;
    return result ;
}
int main()
{
    vector< vector<int> > RGB_vec(1001) ;
    int N ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        int row = i + 1 ;
        for (int j = 0 ; j < 3 ; j ++)
        {
            int temp ;
            cin >> temp ;
            RGB_vec[row].push_back(temp) ;
        }
    }
    cout << GetCount(RGB_vec , N) ;
    return 0 ;
}