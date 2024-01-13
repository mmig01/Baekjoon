// 나무 자르기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int GetResult(vector<int> & my_vector , int total_wood_length)
{
    int answer ;
    long long sum ;
    int start , end , mid ;
    start = 0 ;
    end = my_vector.back() ;
    
    while (true)
    {
        sum = 0 ;
        mid = (start + end) / 2 ;
        if (start > end)
            break ;
        for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
        {
            int temp ;
            if (mid <= (*it))
            {
                temp = *it - mid ;
            }
            else
            {
                temp = 0 ;
            }
            sum = sum + temp ;
        }
        if (sum >= (long long)total_wood_length)
        {
            answer = mid ;
            start = mid + 1 ;
        }
        else
        {
            end = mid - 1 ;
        }
    }
    return answer ;
}
int main()
{
    vector<int> wood ;
    int wood_num ;
    int total_wood_length ;
    cin >> wood_num >> total_wood_length ;
    for (int i = 0 ; i < wood_num ; i ++)
    {
        int temp ;
        cin >> temp ;
        wood.push_back(temp) ;
    }
    
    sort(wood.begin() , wood.end()) ;
    cout << GetResult(wood , total_wood_length) ;
    return 0 ;
}