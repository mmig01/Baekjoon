//포켓몬
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std ;
int main()
{
    cin.tie(nullptr) ;
    unordered_map<string , int> str_key ;
    unordered_map<int , string> int_key ;
    string str ;
    int N , M ;
    cin >> N >> M ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> str ;
        str_key.insert(make_pair(str , i + 1)) ;
        int_key.insert(make_pair(i + 1 , str)) ;
    }

    for (int i = 0 ; i < M ; i ++)
    {
        cin >> str ;
        if (isdigit(str[0]))
        {
            cout << int_key[stoi(str)] << '\n' ;
        }
        else
        {
            cout << str_key[str] << '\n' ;
        }
    }
    return 0 ;
}