// 패션왕 신해빈
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std ;
void Input(unordered_map<string , int> & test)
{
    string input_str , input_key ;
    int input_size ;
    cin >> input_size ;
    for (int i = 0 ; i < input_size ; i ++)
    {
        cin >> input_str >> input_key ;
        test[input_key] ++ ;
    }
}
int main()
{
    unordered_map<string , int> test ;
    unordered_map<string , int>::iterator it ;
    int test_case , total ;

    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        test.clear() ;
        total = 1 ;
        Input(test) ;
        for (it = test.begin() ; it != test.end() ; it ++)
        {   
            total = total * ((*it).second + 1) ;
        }
        total-- ;
        cout << total << '\n' ;
    }
    exit(0) ;
}

