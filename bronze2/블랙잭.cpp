#include<iostream>
int main()
{
    using namespace std ;
    int iTotal , i , j , k , iCount ;
    int iSub , iTotalSum , iMinSub , iMaxTotal ;
    cin >> iCount >> iTotalSum ;
    int * arr = new int[iCount] ;
    for (int i = 0 ; i < iCount ; i ++)
    {
        cin >> arr[i] ;
    }
    iMaxTotal = 0 ;
    iMinSub = 300001 ;
    iSub = 0 ;
    iTotal = 0 ;
    k = 0 ;
    while (true)
    {
        j = k + 1 ;
        while (true)
        {
            i = j + 1 ;
            while (true)
            {
                iTotal = arr[k] + arr[j] + arr[i] ;
                iSub = iTotalSum - iTotal ;
                i ++ ;
                //cout << "iTotal : " << iTotal << ", " ; 
                //cout << "iSub : " << iSub << "|||" ; // temp
                if (iSub < iMinSub && iSub >= 0)
                {
                    iMinSub = iSub ;
                    iMaxTotal = iTotal ;
                }
                if (i == 10) break ;
            }
            j ++ ;
            //cout << '\n' ; // temp
            if (j == 9) break ;
        }
        k ++ ;
        //cout << '\n' ; // temp
        if (k == 8) break ;
    }
    
    cout << iMaxTotal ;
    delete[] arr ;
    return 0 ;
}