// 집합
#include<iostream>
#include<vector>
#define EMPTY -1
using namespace std ;
int MyCheck(vector<int> & my_vector , int x)
{
    int result = 0 ;
    for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
    {
        if (*it == x)
            result = 1 ;
    }
    return result ;
}
void MyAdd(vector<int> & my_vector , int x)
{
    if (!MyCheck(my_vector , x))
    {
        for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
        {
            if (*it == EMPTY)
            {
                *it = x ;
                break ;
            }
        }
    }
}
void MyRemove(vector<int> & my_vector , int x)
{
    if (MyCheck(my_vector , x))
    {
        for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
        {
            if (*it == x)
            {
                *it = EMPTY ;
                break ;
            }
        }
    }
}

void MyToggle(vector<int> & my_vector , int x)
{
    if (MyCheck(my_vector , x))
    {
        MyRemove(my_vector , x) ;
    }
    else
    {
        MyAdd(my_vector , x) ;
    }
}
void MyAll(vector<int> & my_vector)
{
    int i = 1 ;
    for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
    {
        *it = i ;
        i ++ ;
    }
}
void MyEmpty(vector<int> & my_vector)
{
    for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end() ; it ++)
    {
        *it = EMPTY ;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_count ;
    int result , x ;
    vector<int> num_vector(20) ;
    string input_instruction ;

    MyEmpty(num_vector) ;
    cin >> test_count ;
    for (int i = 0 ; i < test_count ; i ++)
    {
        cin >> input_instruction ;
        if (input_instruction == "add")
        {
            cin >> x ;
            MyAdd(num_vector , x) ;
        }
        else if (input_instruction == "remove")
        {
            cin >> x ;
            MyRemove(num_vector , x) ;
        }
        else if (input_instruction == "check")
        {
            cin >> x ;
            cout << MyCheck(num_vector , x) << '\n' ;
        }
        else if (input_instruction == "toggle")
        {
            cin >> x ;
            MyToggle(num_vector , x) ;
        }
        else if (input_instruction == "all")
        {
            MyAll(num_vector) ;
        }
        else if (input_instruction == "empty")
        {
            MyEmpty(num_vector) ;
        }
        else
        {
            cout << "error." ;
        }
    }
    return 0 ;
}