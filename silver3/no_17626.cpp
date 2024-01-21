// Four Squares
#include<iostream>
#include<cmath>
using namespace std ;
int Count(int N)
{
    int result = 4 ;
    int count ;
    for (int i = 0 ; i < sqrt(N) + 1 ; i ++)
        for (int j = 0 ; j < sqrt(N) + 1 ; j ++)
            for (int k = 0 ; k < sqrt(N) + 1 ; k ++)
            {
                if (i * i + j * j + k * k == N)
                {
                    count = 0 ;
                    if (i != 0)
                        count ++ ;
                    if (j != 0)
                        count ++ ;
                    if (k != 0)
                        count ++ ;
                    if (count < result)
                        result = count ;
                }
            }
    return result ;
}
int main()
{
    int N ;
    cin >> N ;
    cout << Count(N) ;
    return 0 ;
}