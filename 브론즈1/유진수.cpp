#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
int main()
{
    string sNumber;
    string sFirstNum, sSecondNum, sResultStr;
    int iFirstMux, iSecondMux, i, iCount;

    cin >> sNumber ;
    iCount = 1;
    sResultStr = "NO" ;
    while (true)
    {
        if (iCount == sNumber.length()) break ;
        iFirstMux = 1;
        iSecondMux = 1;

        sFirstNum = sNumber.substr(0, iCount);
        sSecondNum = sNumber.substr(iCount, sNumber.length());

        for (i = 0; i < sFirstNum.length(); i++)
        {
            iFirstMux = iFirstMux * int(sFirstNum[i] - 48);
        }

        
        for (i = 0; i < sSecondNum.length(); i++)
        {
            iSecondMux = iSecondMux * int(sSecondNum[i] - 48);
        }

        if (iFirstMux == iSecondMux)
        {
            sResultStr = "YES";
            break ;
        }
        
        iCount ++ ;
        
    }

    cout << sResultStr;
    return 0;
}