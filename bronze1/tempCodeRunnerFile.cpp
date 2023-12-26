#include<iostream>
using namespace std ;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N , iIndex , iMaxIndex , iMaxTotal ;
    bool check ;
    int Class[1000][5] ;
    int Student[1000] ;

    for (int i = 0 ; i < 1000 ; i ++)
    {
        Student[i] = 0 ;
    }

    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        for (int j = 0 ; j < 5 ; j ++)
        {
            cin >> Class[i][j] ;
        }
    }

    for (int k = 0 ; k < N - 1 ; k ++)
    {
        check = false ; // 중복 체크
        for (int i = 0 ; i < 5 ; i ++)
        {
            iIndex = k + 1 ;
            while (true)
            {
                if (Class[k][i] == Class[iIndex][i])
                {
                    if (i == 0)
                    {
                        Student[k] ++ ;
                        Student[iIndex] ++ ;
                    }
                    else
                    {
                        if (Class[k][i - 1] == Class[iIndex][i - 1])
                        {
                            check = true ;
                        }

                        if (check != true)
                        {
                            Student[k] ++ ;
                            Student[iIndex] ++ ;
                        }
                    }
                }
                iIndex ++ ;
                if (iIndex == N) break ;
            }
        }
        cout << Student[k] << '\n' ;
    }
    cout << Student[N - 1] << '\n' ;
    iMaxIndex = 1 ;
    iMaxTotal = -1 ;
    for (int i = 0 ; i < N ; i ++)
    {
        if (Student[i] > iMaxTotal)
        {
            iMaxIndex = i + 1 ;
            iMaxTotal = Student[i] ;
        }
    }
    cout << iMaxIndex ;
    return 0 ;
}