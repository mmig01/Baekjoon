// 구간 합 구하기
#include<iostream>
#include<vector>
using namespace std ;
int dp[100001] ;
void SetDP(vector<int> & my_vector)
{
    int index ;
    for (size_t i = 0 ; i < my_vector.size() ; i ++)
    {
        index = i + 1 ;
        dp[index] = dp[index - 1] + my_vector[i] ;
    }
}
int main()
{
    cin.tie(nullptr) ;
    vector<int> num_vector ;
    int num_count , test_case ;
    int start , end ;
    int sum ;
    cin >> num_count >> test_case ;
    for (int i = 0 ; i < num_count ; i ++)
    {
        int temp ;
        cin >> temp ;
        num_vector.push_back(temp) ;
    }
    SetDP(num_vector) ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> start >> end ;
        cout << dp[end] - dp[start - 1] << '\n' ;
    }
    return 0 ;
}
