// 나무 자르기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int GetResult(vector<int> & my_vector , int total_wood_length)
{
    int answer ;
    int sum ;
    answer = my_vector.back() ;
    while (true)
    {
        sum = 0 ;
        for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
        {
            int temp ;
            if (answer <= (*it))
            {
                temp = *it - answer ;
            }
            else
            {
                temp = 0 ;
            }
            sum = sum + temp ;
        }
        if (sum >= total_wood_length)
        {
            break ;
        }
        else
        {
            answer = 0 ;
        }
    }
    return answer ;
}
int main()
{
    vector<int> wood ;
    int wood_num ;
    int total_wood_length ;
    wood_num = 4 ;
    total_wood_length = 7 ;
    wood.push_back(20) ;
    wood.push_back(15) ;
    wood.push_back(10) ;
    wood.push_back(17) ;

    sort(wood.begin() , wood.end()) ;
    cout << GetResult(wood , total_wood_length) ;
    return 0 ;
}