// DSLR
#include<iostream>
#include<deque>
using namespace std ;
bool is_visit[10000] ;
string DSLR_str[10000] ;
void Clear()
{
    for (int i = 0 ; i < 10000 ; i ++)
        is_visit[i] = false ;
}
void ClearStr()
{
    for (int i = 0 ; i < 10000 ; i ++)
        DSLR_str[i] = "" ;
}
int D(int N)
{
    return 2 * N % 10000 ;
}
int S(int N)
{
    if (N == 0)
        return 9999 ;
    else
        return N - 1 ;
}
int L(int N)
{
    N = N * 10 ;
    return N / 10000 + N % 10000 ; ;
}
int R(int N)
{
    return N / 10 + (N % 10) * 1000 ;
}
void BFS(int A , int B)
{
    deque<int> my_dqe ;
    int point[4] = {0 , 0 , 0 , 0} ;
    char inst[4] = {'D' , 'S' , 'L' , 'R'} ;
    my_dqe.push_back(A) ;
    while (!my_dqe.empty())
    {
        int size = (int)my_dqe.size() ;
        for (size_t j = 0 ; j < size ; j ++)
        {
            int cur = my_dqe.front() ;
            my_dqe.pop_front() ;
            is_visit[cur] = true ;
            point[0] = D(cur) ;
            point[1] = S(cur) ;
            point[2] = L(cur) ;
            point[3] = R(cur) ;
            for (int i = 0 ; i < 4 ; i ++)
            {
                if (point[i] == B)
                {
                    cout << DSLR_str[cur] + inst[i] << '\n' ;
                    return ;
                }
                else if (!is_visit[point[i]])
                {
                    is_visit[point[i]] = true ;
                    DSLR_str[point[i]] = DSLR_str[cur] + inst[i] ;
                    my_dqe.push_back(point[i]) ;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    int A , B , test_case ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        ClearStr() ;
        Clear() ;
        cin >> A >> B ;
        BFS(A , B) ;
    }
    return 0 ;
}