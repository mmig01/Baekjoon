// 마인크래프트 
#include<iostream>
#include<vector>
#include<climits>
using namespace std ;
typedef vector<int> ROW ;
void input_value(vector<ROW> & ground , int N , int M , int B)
{
    for (int i = 0 ; i < N ; i ++)
    {
        ROW temp ;
        for (int j = 0 ; j < M ; j ++)
        { 
            int height ;
            cin >> height ;
            temp.push_back(height) ;
        }
        ground.push_back(temp) ; 
    }
}
pair<int , int> set_pair(vector<ROW> & ground , int N , int M , int B)
{
    int time , top ;
    int max_height = 0 , min_time = INT_MAX ;
    pair<int , int> time_and_height ;
    for (int k = 0 ; k < 257 ; k ++)
    {
        int total_block = B ;
        top = 256 - k ;
        time = 0 ;
        for (int i = 0 ; i < N ; i ++)
        { 
            for (int j = 0 ; j < M ; j ++)
            {
                int temp ;
                if (top > ground[i][j])
                {
                    temp = top - ground[i][j] ;
                    total_block = total_block - temp ;
                    time = time + temp ;
                }
                else if (top < ground[i][j])
                {
                    temp = (ground[i][j] - top) ;
                    total_block = total_block + temp ;
                    time = time + temp * 2 ;
                }
            }
        }
        if (total_block >= 0)
        {
            time_and_height = make_pair(time , top) ;
            //cout << time_and_height.first << ", " << time_and_height.second << '\n' ;
            if (time_and_height.first < min_time)
            {
                min_time = time_and_height.first ;
                max_height = time_and_height.second ;
            }
        }
    }
    return make_pair(min_time , max_height) ;
}
int main()
{
    vector<ROW> ground ;
    pair<int , int> min_time_and_max_height ;
    int N , M , B ;
    cin >> N >> M >> B ;
    input_value(ground , N , M , B) ;
    min_time_and_max_height = set_pair(ground , N , M , B) ;
    
    cout << min_time_and_max_height.first ;
    cout << " " << min_time_and_max_height.second ; 
    return 0 ;
}