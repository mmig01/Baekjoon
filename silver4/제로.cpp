#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    int N , input_num , total_sum = 0 ;
    vector<int> num_vector ;
    cin >> N ; 
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> input_num ;
        if (input_num == 0)
        {
            num_vector.pop_back() ;
        }
        else
        {
            num_vector.push_back(input_num) ;
        }
    }

    for (int i = 0 ; i < num_vector.size() ; i ++)
    {
        total_sum = total_sum + num_vector[i] ;
    }
    cout << total_sum ;
    exit(0) ;
}