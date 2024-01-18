//카잉달력
#include<iostream>
#include<vector>
using namespace std ;
int GetCount(int big_num_mod , int small_num_mod , int big_num , int small_num)
{
    int result = -1 ;
    int size = big_num_mod * small_num_mod ;
    int cur_num = big_num ;
    while (true)
    {
        int temp = (cur_num - 1) % small_num_mod + 1 ;
        if (temp == small_num)
        {
            result = cur_num ;
            break ;
        }
        cur_num = cur_num + big_num_mod ;
        if (cur_num > size) break ;
    }
    return result ;
}
int main()
{
    int test_case ;
    int M , N , x , y ;
    int result ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        cin >> M >> N >> x >> y ;
        if (x > y)
            result = GetCount(M , N , x , y) ;
        else
            result = GetCount(N , M , y , x) ;
        cout << result << '\n' ;
    }
    exit(0) ;
}