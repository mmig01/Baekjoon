#include<iostream>
#include<string>
using std::string ;
using std::cout ;
using std::cin ;
typedef struct
{
    string color ;
    int value ;
    int mul ;
}Color ;
int main()
{
    string sColor ;
    long lResult ;
    Color regist[10] = 
    {
        {"black" , 0 , 1} ,
        {"brown" , 1 , 10} ,
        {"red" , 2 , 100} ,
        {"orange" , 3 , 1000} ,
        {"yellow" , 4 , 10000} ,
        {"green" , 5 , 100000} ,
        {"blue" , 6 , 1000000} ,
        {"violet" , 7 , 10000000} ,
        {"grey" , 8 , 100000000} ,
        {"white" , 9 , 1000000000} 
    } ;

    cin >> sColor ;
    for (int i = 0 ; i < 10 ; i ++)
    {
        if (regist[i].color == sColor) 
        lResult = regist[i].value * 10 ;
    }
    cin >> sColor ;
    for (int i = 0 ; i < 10 ; i ++)
    {
        if (regist[i].color == sColor) 
        lResult = lResult + regist[i].value ;
    }
    cin >> sColor ;
    for (int i = 0 ; i < 10 ; i ++)
    {
        if (regist[i].color == sColor) 
        lResult = lResult * regist[i].mul ;
    }
    cout << lResult ;
    return 0 ;
}