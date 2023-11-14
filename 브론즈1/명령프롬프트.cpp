#include<iostream>
#include<string>
int main()
{
    using std::string ;
    int i , iCount ;
    string sFirstArray = "contest.txt" ;
    string sTempArray = new char[sFirstArray.length()];

    std::cin >> iCount ;
    std::cin >> sFirstArray ;
    sTempArray = sFirstArray ;
    for (int j = 0 ; j < iCount - 1 ; j ++)
    {
        std::cin >> sFirstArray ;
        for (i = 0 ; i < sFirstArray.length() ; i ++)
        {
            
            if (sFirstArray[i] != sTempArray[i]) 
            {
                sTempArray[i] = '?' ;
                std::cout << sTempArray[i] ;
            }
            else
            {
                std::cout << sTempArray[i] ;
            }
        }
    }
    
    return 0 ;
}