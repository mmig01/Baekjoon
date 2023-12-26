#include<iostream>
using namespace std ;
typedef struct stack
{
    char cStack[50] ;
    int iCurrent ;

    void clear(){iCurrent = - 1 ;}
    bool empty(){return iCurrent == -1;}
    bool full(){return iCurrent == 49 ;}
    void push(char iData)
    {
        if (full() == true) cout << "stack is full.\n" ;
        iCurrent ++ ;
        cStack[iCurrent] = iData ;
    }
    char pop()
    {
        if(empty() == true) return -1 ;
        return cStack[iCurrent--] ;
    }
    int size()
    {
        return iCurrent + 1 ;
    }
    char top()
    {
        if (empty() == true) return '0' ;
        return cStack[iCurrent] ;
    }
} Stack ;
int main()
{
    Stack stack ;
    std::string temp ;
    char cTemp ;
    int T ;
    cin >> T ;
    for (int i = 0 ; i < T ; i ++)
    {
        stack.clear() ;
        cin >> temp ;
        for (int i = 0 ; i < temp.length() ; i ++)
        {
            if (stack.empty()) stack.push(temp[i]);
            else
            {
                cTemp = stack.top() ;
                stack.push(temp[i]) ;
                if (cTemp == '(')
                {
                    if (stack.top() == ')') 
                    {
                        stack.pop() ;
                        stack.pop() ;
                    }
                }
            }
        }
        if (stack.top() == '0') cout << "YES" ;
        else cout << "NO" ;
        cout << '\n' ;
    }
    return 0 ;
}