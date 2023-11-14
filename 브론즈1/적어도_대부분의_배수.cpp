#include<iostream>
int main()
{
    using std::cin ;
    using std::cout ;
    int iNumber[5] ;
    int iNo , i , iCount ;
    for (i = 0 ; i < 5 ; i ++)
    {
        cin >> iNumber[i] ;
    }
    
    iNo = 1 ;
    while (true)
    {
        iCount = 0 ;
        for (i = 0 ; i < 5 ; i ++)
        {
            if (iNo % iNumber[i] == 0)
            {
                iCount ++ ;
            }
        }

        if (iCount >= 3) 
        {
            break ;
        }

        iNo ++ ;
    }
    cout << iNo ;
    return 0 ;
}