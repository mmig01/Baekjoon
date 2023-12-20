// solved.ac 
#include<iostream>
#include<deque>
#include<algorithm>
#include<cmath>
using namespace std ;
int getAverage(int opinion , deque<int> & difficulty)
{
    int result = 0 ;
    int except_person ;
    
    if (opinion == 0) 
        result = 0 ;
    else
    {
        sort(difficulty.begin() , difficulty.end()) ;
        except_person = round(opinion * 0.15) ;
        for (int i = 0 ; i < except_person ; i ++)
        {  
            difficulty.pop_front() ;
            difficulty.pop_back() ;
        } 
        
        for(int i = 0 ; i < difficulty.size() ; i ++)
        {  
            result = result + difficulty[i] ;
        }
        result = round((double)result / difficulty.size()) ;
    }
    return result ;
}
int main()
{ 
    int opinion ;
    deque<int> difficulty ;
    cin >> opinion ;
    for (int i = 0 ; i < opinion ; i ++)
    {
        int temp ;
        cin >> temp ;
        difficulty.push_back(temp) ;
    }
    cout << getAverage(opinion , difficulty) ;
}