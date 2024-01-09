// 회의실 배정
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int GetCount(vector<pair<int , int> > & meeting)
{
    int count = 1 ;
    int compare_time = meeting[0].second ;
    for (size_t i = 1 ; i < meeting.size() ; i ++)
    {
        if (meeting[i].first < compare_time)
            continue ;
        else
        {
            compare_time = meeting[i].second ;
            count ++ ;
        }
    }
    return count ;
}
int main()
{
    vector<pair<int , int> > meeting ;
    vector<pair<int , int> > reverse_vector ;
    int input_length ;
    cin >> input_length ;
    for (int i = 0 ; i < input_length ; i ++)
    {
        pair<int , int> temp ;
        cin >> temp.second >> temp.first ;
        reverse_vector.push_back(temp) ;
    }
    sort(reverse_vector.begin() , reverse_vector.end()) ;
    for (int i = 0 ; i < input_length ; i ++)
    {
        meeting.push_back(make_pair(reverse_vector[i].second , reverse_vector[i].first)) ;
    }

    cout << GetCount(meeting) ;
    exit(0) ;
}