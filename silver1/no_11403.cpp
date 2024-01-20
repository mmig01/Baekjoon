// 경로 찾기
#include<iostream>
#include<deque>
using namespace std ;
deque< deque<int> > graph_dqe(100 , deque<int>(100)) ;
int main()
{
    int test_case ; 
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++){
        for (int j = 0 ; j < test_case ; j ++){
            cin >> graph_dqe[i][j] ;
        }
    }

    for (int m = 0 ; m < test_case ; m ++){
        for (int s = 0 ; s < test_case ; s ++){
            for (int e = 0 ; e < test_case ; e ++){
                if (graph_dqe[s][m] == 1 && graph_dqe[m][e] == 1)
                        graph_dqe[s][e] = 1 ;
            }
        }
    }
    for (int i = 0 ; i < test_case ; i ++){
            for (int j = 0 ; j < test_case ; j ++){
                cout << graph_dqe[i][j] << ' ' ;
            }
        cout << '\n' ;
    }
    return 0 ;
}

