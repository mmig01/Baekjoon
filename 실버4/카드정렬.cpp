#include<iostream>
#include<deque>
int main()
{
    using namespace std ;
    deque <int> dDeque ;
    int N , temp ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        dDeque.push_back(i + 1) ;
    }
    while (true)
    {
        dDeque.pop_front() ;

        temp = dDeque.front() ;
        dDeque.pop_front() ;
        dDeque.push_back(temp) ;
        if (dDeque.size() == 1) break ;
    }
    
    cout << dDeque.front() ;


    return 0 ;
}