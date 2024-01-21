// 비밀번호 찾기
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    
    unordered_map<string , string> test ;
    int add_count , pwd_count ;
    string addr , pwd ;
    cin >> add_count >> pwd_count ;
    for (int i = 0 ; i < add_count ; i ++)
    {
        cin >> addr >> pwd ;
        test[addr] = pwd ;
    }
    for (int i = 0 ; i < pwd_count ; i ++)
    {
        cin >> addr ;
        cout << test[addr] << '\n' ;
    }
    return 0 ;     
}