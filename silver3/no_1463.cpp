//1로 만들기
#include<iostream>
int dp[1000001] ;
void clear()
{
    for (int i = 0 ; i < 1000001 ; i ++)
    {
        dp[i] = 0 ;
    }
}
int MakeOne(int X)
{
    int result = INT16_MAX ;
    int temp1 , temp2 , temp3 ;
    if (X == 1) return 0 ;

    if (X % 3 == 0)
    {
        if (dp[X / 3] == 0)
        {
            dp[X / 3] = MakeOne(X / 3) ; 
        }
    
        temp1 = 1 + dp[X / 3] ;
        result = temp1 ;
    }
    if (X % 2 == 0)
    {
        if (dp[X / 2] == 0)
        {
            dp[X / 2] = MakeOne(X / 2) ; 
        }
        temp2 = 1 + dp[X / 2] ;
        if (result > temp2)
            result = temp2 ;
    }

    if (dp[X - 1] == 0)
    {
        dp[X - 1] = MakeOne(X - 1) ;
    }
    temp3 = 1 + dp[X - 1] ;

    if (result > temp3)
            result = temp3 ;
    //std::cout << "current result is : " << result << '\n' ;
    return result ;
}
int main()
{
    clear() ;
    std::cout << MakeOne(2) ;
    return 0 ;
}