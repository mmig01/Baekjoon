#include<iostream>
int main()
{
    using namespace std ;
    cout<<fixed;
    cout.precision(100);
    int iCount , iMax ;
    double a , dTotal ;
    cin >> iCount ;
    int * arr = new int[iCount] ;

    iMax = 0 ;
    for (int i = 0 ; i < iCount ; i ++)
    {
        cin >> arr[i] ;
        if (arr[i] > iMax) iMax = arr[i] ;
    }
    dTotal = 0 ;
    for (int i = 0 ; i < iCount ; i ++)
    {
        dTotal = dTotal + (double)arr[i]/(double)iMax * 100 ;
    }
    dTotal = (double)dTotal / (double)iCount ;
    cout << dTotal ;
    delete[] arr ;
    return 0 ;
}