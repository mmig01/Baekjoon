#include<iostream>
int main()
{
    using std::cin ;
    using std::cout ;
    int i , j , iFirstNum , iSecondNum ;
    int iRowSecurityCount , iColSecurityCount , iResult ; 
    cin >> iFirstNum >> iSecondNum ;
    char ** cCastleArr = new char * [iFirstNum] ;
    for (i = 0; i < iFirstNum ; i++)
    {
        cCastleArr[i] = new char[iSecondNum] ;
    }
    
    for (i = 0; i < iFirstNum ; i++)
    {
        for (j = 0; j < iSecondNum ; j++)
        {
            cin >> cCastleArr[i][j] ;
        }
    }

    iColSecurityCount = 0 ;
    iRowSecurityCount = 0 ;
    for (i = 0; i < iFirstNum ; i++)
    {
        for (j = 0; j < iSecondNum ; j++)
        {
            if (cCastleArr[i][j] == 'X')
            {
                break ;
            }  
        }
        if (j == iSecondNum) iRowSecurityCount ++ ;
    }
    for (j = 0; j < iSecondNum ; j++)
    {
        for (i = 0; i < iFirstNum ; i++)
        {
            if (cCastleArr[i][j] == 'X')
            {
                break ;
            }  
        }
        if (i == iFirstNum) iColSecurityCount ++ ;
    }

    iResult = iRowSecurityCount > iColSecurityCount ? iRowSecurityCount : iColSecurityCount ;
    cout << iResult ;
    /*cout << "************************" << std::endl ;
    
    for (i = 0; i < iFirstNum ; i++)
    {
        for (j = 0; j < iSecondNum ; j++)
        {
            cout << cCastleArr[i][j] ;
        }
        cout << std::endl ;
    }
    */
    
    


    for (i = 0; i < iFirstNum ; i++)
    {
        delete [] cCastleArr[i]  ;
    }

    delete [] cCastleArr ;
    return 0 ;
}