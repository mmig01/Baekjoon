#include<iostream>
#include<string>
#include<deque>
using namespace std ;
void setDeque(char ch , deque<char> & dArr , deque<char> & dTrash)
{  
    if (ch == '(' || ch == '[')
    {
        dArr.push_back(ch) ;
    }
    else if (ch == ')' || ch == ']')
    {
        if (ch == ')')
        {
            if (!dArr.empty() && dArr.back() == '(')
            {
                dArr.pop_back() ;
            }
            else
            { 
                dTrash.push_back(ch) ;
            }
        }
        else if (ch == ']')
        {
            if (!dArr.empty() && dArr.back() == '[')
            {
                dArr.pop_back() ;
            }
            else
            { 
                dTrash.push_back(ch) ;
            }
        }
    } 
}
int main()
{
    deque<char> dArr ;
    deque<char> dTrash ;
    string str ;
    bool bExit ;
    while (true)
    {
        dArr.clear() ;
        dTrash.clear() ;
        bExit = false ;
        getline(cin , str , '.') ;
        // 한 문장 입력이 끝났을 때
        if (str.size() == 0) break ;
        else if (str.size() == 1 && str[0] == '\n') break ; 
        for (int i = 0 ; i < str.size() ; i ++)
        {
            setDeque(str[i] , dArr , dTrash) ;
        }

        if (dArr.empty())
        {  
            if (!dTrash.empty()) cout << "no\n" ;
            else cout << "yes\n" ;
        } 
        else
            cout << "no\n" ; 
    }
    return 0 ;
}