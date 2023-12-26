#include<iostream>
#include<algorithm>
using namespace std ;
int iFirstArr[100001] ;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , M , iIndex , iNodeHasChild , iResult ;
    int iSecondNum ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        cin >> iFirstArr[i] ;
    }
    sort(iFirstArr , iFirstArr + N) ;

    cin >> M ;
    for (int i = 0 ; i < M ; i ++)
    {
        cin >> iSecondNum ;
        iResult = binary_search(iFirstArr , iFirstArr + N , iSecondNum) ;
        cout << iResult << '\n' ;
    }
    
    return 0 ;
}
