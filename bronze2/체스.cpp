#include <iostream>
#include <string>
using std::cout;
using std::cin ;
using std::string;
int main()
{
    string sChess;
    int iCount, iIndex , iModJ;
    char ch;

    iCount = 0;

    for (int j = 0; j < 8; j++)
    {
        cin >> sChess ;
    
        for (int i = 0; i < 4; i++)
        {
            iModJ = j % 2 ;
            iIndex = 2 * i + iModJ;
            if ('F' == sChess[iIndex])
            {
                    iCount++;
            }   
        }
    }

    cout << iCount;
    return 0;
}