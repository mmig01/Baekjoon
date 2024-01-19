// 이중 우선순위 큐
#include<iostream>
#include<set>
using namespace std ;
multiset<int> test ;
void Input()
{
    multiset<int>::iterator it ;
    int num , length ;
    char c ;
    cin >> length ;
    for (int i = 0 ; i < length ; i ++)
    {
        cin >> c >> num ;
        if (c == 'I')
        {
            test.insert(num) ;
        }
        else
        {
            if (!test.empty())
            {
                if (num == 1)
                {
                    it = test.end() ;
                    it-- ;
                    test.erase(it) ;
                }
                else
                {
                    it = test.begin() ;
                    test.erase(it) ;
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

    multiset<int>::iterator it_max , it_min ;
    int test_case ;
    cin >> test_case ;
    for (int i = 0 ; i < test_case ; i ++)
    {
        test.clear() ;
        Input() ;
        if (test.empty())
            cout << "EMPTY\n" ;
        else
        {
            it_max = test.end() ;
            it_max-- ;
            it_min = test.begin() ;
            cout << *it_max << " " << *it_min << '\n' ;
        }
    }
    exit(0) ;
}