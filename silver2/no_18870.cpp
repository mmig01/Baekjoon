// 좌표 압축
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std ;
vector<int> result_vec(1000001) ;
void GetCount(vector< pair<int , int> > & pair_vector)
{
    int count = -1 ;
    int max_num = INT_MIN ;
    int origin_index ;
    vector< pair<int , int> >::iterator it ;
    for (it = pair_vector.begin() ; it != pair_vector.end() ; it ++)
    {
        if ((*it).first > max_num)
        {
            count ++ ;
            max_num = (*it).first ;
            origin_index = (*it).second ;
            result_vec[origin_index] = count ;
        }
        else
        {
            origin_index = (*it).second ;
            result_vec[origin_index] = count ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    vector< pair<int , int> > input_vec ;
    int input_size ;
    int input_num ;
    cin >> input_size ;
    for (int i = 0 ; i < input_size ; i ++)
    {
        cin >> input_num ;
        input_vec.push_back(make_pair(input_num , i)) ;
        // 첫 번째 원소는 값 , 두 번째 원소는 배열의 인덱스를 저장
    }
    sort(input_vec.begin() , input_vec.end()) ;
    GetCount(input_vec) ;
    for (int i = 0 ; i < input_size ; i ++)
    {
        cout << result_vec[i] << ' ' ;
    }
    exit(0) ;
}