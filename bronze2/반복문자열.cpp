#include<iostream>
using std::cin ;
using std::cout ;
using std::string ;
int main()
{
    int iCount , iNumber ;
    string sString , sSecond ;
    cin >> iNumber ;

    while (true)
    {
        cin >> iCount ;
        cin >> sString ;
        for (int j = 0 ; j < sString.length() ; j ++)
        {
            for (int i = 0 ; i < iCount ; i ++)
            {
                cout << sString[j] ;
            }
        }
        cout << '\n' ;
        iNumber -- ;
        if (iNumber <= 0) break ;
    }
    
    return 0 ;
}