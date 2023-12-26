#include<iostream>
#include<string>
using std::string ;
using std::cin ;
using std::cout ;
int main()
{
    string sArray ;
    int iCount ;
    int iIndex ;

    iCount = 0 ;
    iIndex = 0 ;
    getline(cin , sArray) ;
    while (true)
    {
        if (sArray[iIndex] == ' ')
        {
            if (iIndex != 0)
            {
                iCount ++ ;
            } 
        }
        else if (sArray[iIndex] == '\0') //iIndex == arr.length()
        {
            if (sArray[iIndex - 1] == ' ') break ;
            else iCount ++ ;
        }
        iIndex ++ ;
        if (iIndex == sArray.length() + 1) break ;
    }
    cout << iCount ; 
    return 0 ;
}