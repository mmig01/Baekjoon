#include<iostream>
#include<string>
using std::cin ;
using std::cout ;
using std::string ;
int main()
{
    string sHash ;
    int iLength , iHash ;
    long long iTotal , iKey , iTemp ;
    cin >> iLength >> sHash ;

    iTotal = 0 ;
    iKey = 1 ;
    for (int i = 0 ; i < iLength ; i ++)
    {
        iHash = sHash[i] - 96 ;
        iTemp = (iHash * iKey ) % 1234567891 ;
        iTotal = (iTotal + iTemp) % 1234567891 ;
        iKey = (iKey * 31) % 1234567891 ;
    }
    iTotal = iTotal % 1234567891 ;
    cout << iTotal ;
   
    return 0 ;

}
