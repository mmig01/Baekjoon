#include<iostream>
int main()
{
    using namespace std ;
    int number , iTemp , iSixCount , iCompare ,iTotalCount  , N ;
    cin >> N ;
    iTotalCount = 0 ;
    number = 1 ;

    while (true)
    {
        iSixCount = 0 ;
        iCompare = number ;
        while (true) // 하나의 수에 대해서 '연속된' 6의 개수를 세는 반복문
        {   
            iTemp = iCompare % 10 ;
            if (iTemp == 6) iSixCount ++ ;
            else iSixCount = 0 ;

            iCompare = iCompare / 10 ;
            if (iSixCount == 3) 
            {
                iTotalCount ++ ;
                break ;
            }
            if (iCompare == 0) break ;
        }
        
        if (iTotalCount == N) break ;
        number ++ ;
    }

    cout << number ;
    return 0 ;
}