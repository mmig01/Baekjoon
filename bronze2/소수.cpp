#include<iostream>
int searchNum(int num) ;
int main()
{
    using namespace std ;
    int iCount , iTotal ;
    cin >> iCount ;
    int * arr = new int[iCount] ;
    for (int i = 0 ; i < iCount ; i ++)
    {
        cin >> arr[i] ;
    }

    iTotal = 0 ;
    for (int i = 0 ; i < iCount ; i ++)
    {
        iTotal = iTotal + searchNum(arr[i]) ;
    }
    cout << iTotal ;
    delete[] arr ;
    return 0 ;
}
int searchNum(int num)
{
    if (num == 1) return 0 ;
    int iDivide , iResult ;
    iDivide = 2 ;
    while (true)
    {
        iResult = num % iDivide ;
        if (iResult == 0) break ;
        iDivide ++ ;
    }
    if (iDivide == num) return 1 ;
    else return 0 ;
}