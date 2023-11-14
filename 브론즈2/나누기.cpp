#include <iostream>
using std::cin;
using std::cout;
int main()
{
    unsigned int iFirstNum, iSecondNum ;
    int iResult ;
    cin >> iFirstNum >> iSecondNum ;
    iFirstNum = iFirstNum / 100;
    iFirstNum = iFirstNum * 100;
    while (true)
    {
        if (iFirstNum % iSecondNum == 0)
        {
            break;
        }
        else
        {
            iFirstNum++;
        }
    }
    iResult = iFirstNum % 100 ;
    if (iResult >= 10)
    {
        cout << iResult  ;
    }
    else
    {
        cout << "0" << iResult ;
    }
    
    return 0;
}