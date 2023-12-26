#include<iostream>
int getCheckColor(char (* sChess)[8], int iStartRow , int iStartCol) ;
int main()
{
    using namespace std ;
    int row , col , iResult ;
    cin >> row >> col ;
    /*
    char ** sChess = new char *[row] ;
    for (int i = 0 ; i < row ; i ++)
    {
        sChess[i] = new char [col] ;
    }

    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            sChess[i][j] = '.' ;
        }
    }
    */
    char sChess[2][8] =
    {
        {'W' , 'B' , 'W' , 'B' , 'W' , 'B' , 'W' , 'B'} ,
        {'W' , 'B' , 'W' , 'B' , 'W' , 'B' , 'W' , 'B'}
    } ;
    // WBWBWBWB
    
    
    iResult = getCheckColor(sChess , 0 , 0) ;


    for (int i = 0 ; i < row ; i ++)
    {
        for (int j = 0 ; j < col ; j ++)
        {
            cout << sChess[i][j] << " " ;
        }
        cout << '\n' ;
    }
      

    cout << iResult ;
    /*
    for (int i = 0 ; i < row ; i ++)
    {
        delete [] sChess[i] ;
    }
    delete [] sChess ;
    */
    return 0 ;
}
int getCheckColor(char (* sChess)[8], int iStartRow , int iStartCol)
{
    char cFirst ;
    int iCount ;
    cFirst = sChess[iStartRow][iStartCol] ;
    iCount = 0 ;
    for (int i = 0 ; i < 2 ; i ++)
    {
        if (sChess[i][1] == cFirst) 
        iCount ++ ;

        if (sChess[i][2] != cFirst) 
        iCount ++ ;

        if (sChess[i][3] == cFirst) 
        iCount ++ ;

        if (sChess[i][4] != cFirst) 
        iCount ++ ;

        if (sChess[i][5] == cFirst) 
        iCount ++ ;

        if (sChess[i][6] != cFirst) 
        iCount ++ ;

        if (sChess[i][7] == cFirst) 
        iCount ++ ;
    }
    return iCount ;
}