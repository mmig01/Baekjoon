#include<iostream>
using namespace std ;
int main()
{
    int k , iIndex , iMax , tempIndex ;
    cin >> iMax >> k ;
    int * arr = new int[iMax] ;
    for (int i = 0 ; i < iMax ; i ++)
    {
        arr[i] = i + 1 ;
    }
    iIndex = 0 ;
    cout << "<" ;
    while (true)
    {
        iIndex = (iIndex + k) - 1 ;
        if (iIndex >= iMax) iIndex = iIndex % iMax ;
        cout << arr[iIndex] ;

        iMax = iMax - 1 ;
        if (iMax == 0) 
        {
            cout << ">" ;
            break ;
        }
        else
        {
            cout << ", " ;
        }

        tempIndex =  iIndex ;
        while (tempIndex < iMax)
        {
            arr[tempIndex] = arr[tempIndex + 1] ;
            tempIndex ++ ;
        }
    }
    delete[] arr ;
    return 0 ;
}