// 집합 비트마스킹 구현
#include<iostream>
#include<string>
using namespace std ;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int set = 0 ;
    int test_count , x ;
    string input_instruction ;
    cin >> test_count ;
    for (int i = 0 ; i < test_count ; i ++)
    {
        cin >> input_instruction ;
        if (input_instruction == "add")
        {
            cin >> x ;
            set = set | (1 << (x - 1)) ;
        }
        else if (input_instruction == "remove")
        {
            cin >> x ;
            set = set & ~(1 << (x - 1)) ;
        }
        else if (input_instruction == "check")
        {
            cin >> x ;
            if (set & (1 << (x - 1)))
                cout << 1 << '\n' ;
            else
                cout << 0 << '\n' ;
        }
        else if (input_instruction == "toggle")
        {
            cin >> x ;
            set = set ^ (1 << (x - 1)) ;
        }
        else if (input_instruction == "all")
        {
            set = (1 << 20) - 1 ;
        }
        else if (input_instruction == "empty")
        {
            set = 0 ;
        }
        else
        {
            cout << "error." ;
        }
    }
    return 0 ;
}