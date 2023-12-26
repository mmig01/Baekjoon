#include <iostream>
int main()
{
    using std::cin ;
    using std::cout ;
    int iFirstTotal , iFirstIndexNum , iFirstIndexCount ;
    int iSecondTotal , iSecondIndexNum , iSecondIndexCount ;
    int iFirstInput , iSecondInput ;
    iFirstTotal = 0 ;
    iFirstIndexCount = 0 ;
    iFirstIndexNum = 1 ;

    iSecondTotal = 0 ;
    iSecondIndexCount = 0 ;
    iSecondIndexNum = 1 ;

    cin >> iFirstInput ;
    iFirstInput = iFirstInput - 1 ;
    while (true)
    {
        
        for (int i = 0 ; i < iFirstIndexNum ; i ++)
        {
            if (iFirstIndexCount == iFirstInput) break ;
            //cout << "indexnum : " << iIndexNum << std::endl ;
            iFirstTotal = iFirstTotal + iFirstIndexNum ;
            iFirstIndexCount ++ ;
            //cout << "Count : " << iIndexCount << std::endl ;
        }

        if (iFirstIndexCount == iFirstInput) break ;
        iFirstIndexNum ++ ;
    }

    cin >> iSecondInput ;
    iSecondInput = iSecondInput ;
    while (true)
    {
        
        for (int i = 0 ; i < iSecondIndexNum ; i ++)
        {
            if (iSecondIndexCount == iSecondInput) break ;
            //cout << "indexnum : " << iIndexNum << std::endl ;
            iSecondTotal = iSecondTotal + iSecondIndexNum ;
            iSecondIndexCount ++ ;
            //cout << "Count : " << iIndexCount << std::endl ;
        }

        if (iSecondIndexCount == iSecondInput) break ;
        iSecondIndexNum ++ ;
    }
    
    cout << "total : " << iFirstTotal << std::endl ;
    cout << "total : " << iSecondTotal << std::endl ;

    cout << iSecondTotal - iFirstTotal ;
    
    return 0 ;
}