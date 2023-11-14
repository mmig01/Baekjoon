#include<iostream>
#include<map>
using namespace std ;
map<string , int> mMap ;
typedef struct stack
{
    int iStack[20000] ;
    int iCurrent ;

    void clear(){ iCurrent = -1 ; }
    void push(int iValue){ iStack[++ iCurrent] = iValue ; }
    int pop()
    {   
        if (empty() == true) return -1 ;
        else return iStack[iCurrent --] ; 
    } 
    int size(){ return iCurrent + 1 ; }
    bool empty() { return iCurrent == -1 ; }
    int top()
    {  
        if (empty() == true) return -1 ;
        return iStack[iCurrent] ; 
    }
} MyStack ;
int main()
{   
    mMap.insert(pair<string , int>("push" , 1)) ;
    mMap.insert(pair<string , int>("pop" , 2)) ;
    mMap.insert(pair<string , int>("size" , 3)) ;
    mMap.insert(pair<string , int>("empty" , 4)) ;
    mMap.insert(pair<string , int>("top" , 5)) ;

    MyStack stack ;
    string sTemp ;
    int iTemp , N ;
    stack.clear() ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> sTemp ;
        switch (mMap[sTemp])
        {
            case 1 : 
            cin >> iTemp ;
            stack.push(iTemp) ;
            break;

            case 2 :
            cout << stack.pop() << '\n' ;
            break;

            case 3 :
            cout << stack.size() << '\n' ;
            break;

            case 4 :
            cout << stack.empty() << '\n' ;
            break;

            case 5 :
            cout << stack.top() << '\n' ;
            break;

            default:
            break;
        }
    }

    return 0 ;
}