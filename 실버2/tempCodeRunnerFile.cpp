// 마인크래프트 
#include<iostream>
#include<vector>
#include<climits>
using namespace std ;
typedef vector<int> ROW ;
int main()
{
    int N , M , B ;
    cin >> N >> M >> B ;
    int max_height = 0 , min_time = INT_MAX ;
    int time , top ;
    vector<ROW> ground ;
    pair<int , int> time_and_height ;

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
    
    for (int k = 0 ; k < 257 ; k ++)
    {
        int total_block = B ;
        top = 256 - k ;
        time = 0 ;
        bool possible = true ;
        for (int i = 0 ; i < N ; i ++)
        { 
            for (int j = 0 ; j < M ; j ++)
            {
                int temp = 0 ;
                if (top > ground[i][j])
                {
                    temp = top - ground[i][j] ;
                    if (total_block >= temp)
                    {
                        total_block = total_block - temp ;
                    }
                    else
                    {
                        possible = false ;
                        break ;
                    }
                }
                else if (top < ground[i][j])
                {
                    temp = (ground[i][j] - top) * 2 ;
                }

                time = time + temp ;
            }
            if (possible == false) break ;
        }

        if (possible == false) continue ;
        else
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
    cout << min_time << " " << max_height ; 
    return 0 ;
}