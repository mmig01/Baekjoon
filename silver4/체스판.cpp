#include<iostream>
int getChessCount(char ** cChess , int iFirstStart , int iSecondStart) ;
int main()
{
    using std::cin ;
    using std::cout ;
    int row , col ;
    int iMin , iTemp , i , j , iFirstStart , iSecondStart ;
    cin >> row >> col ;
    char ** cTempArray = new char *[row] ;
    for (i = 0 ; i < row ; i ++)
    {
        cTempArray[i] = new char[col] ;
    }

    for (i = 0 ; i < row ; i ++)
    {
        for (j = 0 ; j < col ; j ++)
        {
            cin >> cTempArray[i][j] ;
        }
    }
    /*for (i = 0 ; i < row ; i ++)
    {
        for (j = 0 ; j < col ; j ++)
        {
            cout << cTempArray[i][j] << " ";
        }
        cout << '\n' ;
    }*/
    iMin = 0 ;
    iFirstStart = 0 ;
    iSecondStart = 0 ;
    while (true)
    {
        if (iSecondStart == 0 && iFirstStart == 0) 
        {
            iMin = getChessCount(cTempArray , iFirstStart , iSecondStart) ;
            iSecondStart ++ ;
        }
        else
        {
            iTemp = getChessCount(cTempArray , iFirstStart , iSecondStart) ;
            if (iTemp < iMin)
            {
                iMin = iTemp ;
            }
            iSecondStart ++ ;
        }
        if (iSecondStart + 8 > col) 
        {
            iFirstStart ++ ;
            iSecondStart = 0 ;
        }
        if (iFirstStart + 8 > row)
        break ;
    }

    
    cout << iMin ;

    for (i = 0 ; i < row ; i ++)
    {
        delete [] cTempArray[i] ;
    }
    delete [] cTempArray ;
    return 0 ;
}

int getChessCount(char ** cChess , int iFirstStart , int iSecondStart)
{
    int iBCount , iWCount , iFirstIndex , iSecondIndex , iSumIndex ;
    int i , j ;
    iBCount = 0 ; 
    iWCount = 0 ;
    // if 'B'
    for (i = 0 ; i < 8 ; i ++)
    {
        for (j = 0 ; j < 8 ; j ++)
        {
            iFirstIndex = iFirstStart + i ;
            iSecondIndex = iSecondStart + j ;
            iSumIndex = iFirstIndex + iSecondIndex ;
            if (iSumIndex % 2 == 0) 
            {
                if (cChess[iFirstIndex][iSecondIndex] != 'B') 
                iBCount ++ ;
            }
            else
            {
                if (cChess[iFirstIndex][iSecondIndex] != 'W') 
                iBCount ++ ;
            }
        }
    }
    // if 'W'
    for (i = 0 ; i < 8 ; i ++)
    {
        for (j = 0 ; j < 8 ; j ++)
        {
            iFirstIndex = iFirstStart + i ;
            iSecondIndex = iSecondStart + j ;
            iSumIndex = iFirstIndex + iSecondIndex ;
            if (iSumIndex % 2 == 0) 
            {
                if (cChess[iFirstIndex][iSecondIndex] != 'W') 
                iWCount ++ ;
            }
            else
            {
                if (cChess[iFirstIndex][iSecondIndex] != 'B') 
                iWCount ++ ;
            }
        }
    }
    return iBCount < iWCount ? iBCount : iWCount ;
}