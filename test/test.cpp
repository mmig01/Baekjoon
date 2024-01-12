#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;
int main()
{
    string str ;
    vector<char> temp ;
    char c ;
    while (cin.get(c))
        temp.push_back(c) ;
    for (vector<char>::iterator it = temp.begin() ; it != temp.end() ; it ++)
        cout << *it ;
    return 0 ;
} 