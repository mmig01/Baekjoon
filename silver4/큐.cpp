#include<iostream>
#include<map>
using namespace std ;
map<string , int> mMap ;
typedef struct queue
{
    int iQueue[20000] ;
    int iFront , iBack ;

    void clear(){ iFront = 0 ; iBack = - 1 ; }
    void push(int iValue){ iQueue[++iBack] = iValue ; }
    int pop()
    {
        if (empty()) return - 1 ;
        else return iQueue[iFront ++] ;  
    }
    bool empty(){ return iBack - iFront + 1 == 0 ; }
    int size(){ return iBack - iFront + 1 ; }
    int front()
    { 
        if (empty()) return - 1 ;
        return iQueue[iFront] ;
    }
    int back()
    { 
        if (empty()) return - 1 ; 
        return iQueue[iBack] ;
    }
} MyQueue ;
int main()
{
    mMap.insert(pair<string , int>("push" , 1)) ;
    mMap.insert(pair<string , int>("pop" , 2)) ;
    mMap.insert(pair<string , int>("size" , 3)) ;
    mMap.insert(pair<string , int>("empty" , 4)) ;
    mMap.insert(pair<string , int>("front" , 5)) ;
    mMap.insert(pair<string , int>("back" , 6)) ;

    MyQueue queue ;
    int N , iTemp ;
    string sTemp ;
    queue.clear() ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> sTemp ;
        switch (mMap[sTemp])
        {
            case 1 : 
            cin >> iTemp ;
            queue.push(iTemp) ;
            break;

            case 2 :
            cout << queue.pop() << '\n' ;
            break;

            case 3 :
            cout << queue.size() << '\n' ;
            break;

            case 4 :
            cout << queue.empty() << '\n' ;
            break;

            case 5 :
            cout << queue.front() << '\n' ;
            break;

            case 6 :
            cout << queue.back() << '\n' ;
            break;

            default:
            break;
        }
    }
    return 0 ;
}