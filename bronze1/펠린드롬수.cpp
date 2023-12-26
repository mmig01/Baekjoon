#include<iostream>
#include<string>
int main()
{
    using std::cin ;
    using std::cout ;
    using std::string ;
    
    int iHalfLength , iIndex , i ;
    string sPalNumber ;


    while (true)
    {
        cin >> sPalNumber ;
        if (sPalNumber == "0") 
        {
            break ;
        }
        iHalfLength = sPalNumber.length() / 2 ;
        for (i = 0 ; i < iHalfLength ; i ++)
        {  
            iIndex = (sPalNumber.length() - 1) - i ;
            if (sPalNumber[i] == sPalNumber[iIndex])
            {
                continue ;
            }
            else
            {
                break ;
            }
        }
        if (i == iHalfLength) 
        {
            cout << "yes" << std::endl ;
        }
        else
        {
            cout << "no" << std::endl ;
        }

    }
    return 0 ;
}