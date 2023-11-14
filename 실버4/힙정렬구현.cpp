#include<iostream>
#include<algorithm>
using namespace std ;
int iFirstArr[100001] ;
void makeHeap(int iRoot , int N) ;
void sortHeap(int N) ;
int main()
{
    int N , M , iIndex , iNodeHasChild ;
    int iSecondNum ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        iIndex = i + 1 ;
        cin >> iFirstArr[iIndex] ;
    }

    iNodeHasChild = N / 2 ;
    makeHeap(iNodeHasChild , N) ;
    sortHeap(N) ;
    cin >> M ;
    for (int i = 0 ; i < M ; i ++)
    {
        cin >> iSecondNum ;
        cout << binary_search(iFirstArr + 1 , iFirstArr + N + 1 , iSecondNum) << '\n' ;
    }
    
    return 0 ;
}
void makeHeap(int iRoot , int N)
{
    int iLeftChild , iRightChild , iCurrent , iNodeHasChild ;
    iNodeHasChild = N / 2 ;
    while (true)
    {
        iLeftChild = iRoot * 2 ;
        iRightChild = iRoot * 2 + 1 ;
        iCurrent = iLeftChild ;
        if (iLeftChild <= N)
        {
            if (iFirstArr[iLeftChild] > iFirstArr[iCurrent]) 
                iCurrent = iLeftChild ;
        }
        if (iRightChild <= N)
        {
            if (iFirstArr[iRightChild] > iFirstArr[iCurrent])
                iCurrent = iRightChild ;
        }
        if (iFirstArr[iRoot] < iFirstArr[iCurrent])
        {
            swap(iFirstArr[iRoot] , iFirstArr[iCurrent]) ;
            if (iCurrent <= iNodeHasChild) makeHeap(iCurrent , N) ;
        }
        iRoot -- ;
        if (iRoot == 0) break ;
    }
}
void sortHeap(int N) 
{
    int iNodeHasChild ;
    while (true)
    {
        swap(iFirstArr[1] , iFirstArr[N]) ;
        N -- ;
        if (N == 1) break ;
        iNodeHasChild = N / 2 ;
        makeHeap(iNodeHasChild , N) ;
    }
}

