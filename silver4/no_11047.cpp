// 동전0
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std ;
int main()
{
    vector<int> test ;
    int N , target_num ;
    int count ;

    count = 0 ;
    cin >> N >> target_num ;
    for (int i = 0 ; i < N ; i ++)
    {
        int temp ;
        cin >> temp ;
        test.push_back(temp) ;
    }
    sort(test.begin() , test.end() , greater<int>()) ;
    for (int i : test)
    {
        int temp ;
        temp = target_num / i ;
        target_num = target_num % i ;
        count = count + temp ;
        if (target_num == 0) break ; 
    }
    cout << count ;
}