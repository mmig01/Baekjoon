//IOIOI
#include<iostream>
#include<string>
using namespace std ;
int main()
{
    string test ;
    int N , length , compare_length_size ;
    int start , end ;
    int result = 0 ;
    bool is_checking , is_before_O ;

    cin >> N ;
    cin >> length ;
    cin >> test ;
    compare_length_size = 2 * N + 1 ; // 비교할 전체 문자열 길이
    is_checking = false ;
    is_before_O = false ;
    start = end = 0 ;
    for (size_t i = 0 ; i < test.size() ; i ++)
    {
        if (test[i] == 'I')
        {  
            if (is_checking)
            {
                end = i ; // I 를 만날 때마다 끝 포인트로 설정
                if ((end - start + 1) == compare_length_size) 
                {   // 시작 포인트와 끝 포인트 사이의 길이가 비교 문자열 길이와 같을 때
                    result ++ ;
                    start = start + 2 ; // I , O 가 반복되므로 시작 포인트를 2칸 뒤로 옮김
                }
            }
            else
            {
                start = i ; // checking 시작 포인트를 설정
                is_checking = true ; // I를 만나면 checking 시작
            }  
            is_before_O = false ;
            if (i + 1 < test.size() && test[i + 1] == 'I') // 다음 칸이 I 이면 Checking 중지
                    is_checking = false ;
        }
        else    // 'O'
        {
            if (is_before_O)
                is_checking = false ; // O가 연속으로 나올 시 Checking 중지

            is_before_O = true ;
        }
    }
    cout << result ;
    exit(0) ;
}
