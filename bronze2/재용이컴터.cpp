#include <iostream>
using std::cin;
using std::cout;
int main()
{
    int iComNumber, iCount;
    int iFirstNum, iSecondNum, i;
    cin >> iCount;
    for (int j = 0; j < iCount; j++)
    {
        cin >> iFirstNum ;
        cin >> iSecondNum;
    
        for (i = 0; i < iSecondNum; i++)
        {
            if (i == 0)
            {
                iComNumber = iFirstNum;
                iComNumber = iComNumber % 10;
                continue;
            }
            else
            {
                iComNumber = iComNumber * iFirstNum;
                iComNumber = iComNumber % 10;
            }
        }
        if (iComNumber == 0)
        {
            iComNumber = 10;
        }

        cout << iComNumber << std::endl ;
    }
    
    return 0;
}