// ATM
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int main()
{
    int test_case ;
    int sum , term_sum ;
    int size ;
    vector<int> ATM ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        int temp ;
        cin >> temp ;
        ATM.push_back(temp) ;
    }
    sort(ATM.begin() , ATM.end()) ;
    size = ATM.size() ;
    sum = 0 ;
    term_sum = 0 ;
    for (size_t j = 0 ; j < size ; j ++)
    { 
        term_sum = term_sum + ATM[j] ;
        sum = sum + term_sum ;
    }
    cout << sum ;
    return 0 ;
}
