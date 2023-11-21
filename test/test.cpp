#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    vector<int> a(10) ;
    a.pop_back() ;
    cout << a.size() ;
} // little endian