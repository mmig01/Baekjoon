#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;
int main()
{
    unordered_map<string , int> a ;
    a.insert(make_pair("hihi" , 1)) ;
    cout << a["hihl"] ;
    return 0 ;
} 