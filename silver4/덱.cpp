#include<iostream>
#include<map>
using namespace std ;
map<string , int> myMap ;
typedef struct deque
{
    int iArr[20000] ;
    int iFront , iBack ;
    void clear(){ iFront = 20000 ; iBack = 19999 ; } 
    bool empty()
    {  
        if ((iBack - iFront + 1 == 0)) return true ; 
        else return false ;
    }
    void push_front(int iValue)
    { 
        iFront -- ;
        iArr[iFront] = iValue ; 
    }
    void push_back(int iValue)
    { 
        iBack ++ ;
        iArr[iBack] = iValue ; 
    }
    int pop_front()
    {
        if (empty() == true) return -1 ;
        else
        {
            return iArr[iFront ++] ;
        }
    }
    int pop_back()
    {
        if (empty() == true) return -1 ;
        else
        {   
            return iArr[iBack --] ;
        }
    }
    int size()
    {
        int iSize ;
        iSize = iBack - iFront + 1 ;
        return iSize ;
    }
    int front()
    {
        if (empty()) return -1 ;
        else return iArr[iFront] ;
    }
    int back()
    {   
        if (empty()) return -1 ;
        else return iArr[iBack] ;
    }
} Deque ;
int main()
{
    myMap.insert(pair<string , int>("push_front" , 1)) ;
    myMap.insert(pair<string , int>("push_back" , 2)) ;
    myMap.insert(pair<string , int>("pop_front" , 3)) ;
    myMap.insert(pair<string , int>("pop_back" , 4)) ;
    myMap.insert(pair<string , int>("size" , 5)) ;
    myMap.insert(pair<string , int>("empty" , 6)) ;
    myMap.insert(pair<string , int>("front" , 7)) ;
    myMap.insert(pair<string , int>("back" , 8)) ;

    int N , iTemp ;
    string sTemp ;
    Deque deque ;
    deque.clear() ;

    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> sTemp ;
        switch (myMap[sTemp])
        {
            case 1 : 
            cin >> iTemp ;
            deque.push_front(iTemp) ;
            break;

            case 2 : 
            cin >> iTemp ;
            deque.push_back(iTemp) ;
            break;

            case 3 :
            cout << deque.pop_front() << '\n' ;
            break;

            case 4 :
            cout << deque.pop_back() << '\n' ;
            break;

            case 5 :
            cout << deque.size() << '\n' ;
            break;

            case 6 :
            cout << deque.empty() << '\n' ;
            break;

            case 7 :
            cout << deque.front() << '\n' ;
            break;

            case 8 :
            cout << deque.back() << '\n' ;
            break;

            default:
            break;
        }
    }
}