#include<iostream>

using namespace std ;
int main()
{   
    int iInput , iNum , iCount ;
    cin >> iInput ;
    iCount = 0 ;

    for (int i = 0 ; i < iInput ; i ++)
    {
        iNum = i + 1 ;
        if (iNum % 5 == 0)
        {
            while (true)
            {
                iNum = iNum / 5 ;
                iCount ++ ;
                if (iNum % 5 != 0) break ;
            }
        }
    }
        
    cout << iCount ;
    return 0  ;
}