#include<iostream>
#include<vector>
using namespace std ;

int main()
{
    std::vector<int> user ;
    std::vector<int>::iterator iter ;
    for (iter = user.begin() ; iter != user.end() ; iter ++)
    {
        std::cout << *iter << " " ;
    }
    return 0 ;
} 