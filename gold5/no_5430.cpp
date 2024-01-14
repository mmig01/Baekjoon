// AC
#include<iostream>
#include<deque>
#include<string>
using namespace std ;
void input_value(deque<int> & arr_deque , deque<char> & fun_deque , int & element_count)
{
    string input_str ;
    string temp = "" ;
    getline(cin , input_str) ;
    for (string::iterator it = input_str.begin() ; it != input_str.end() ; it ++)
    {
        fun_deque.push_back(*it) ;
    }
    cin >> element_count ;
    cin.get() ;
    getline(cin , input_str) ;
    for (string::iterator it = input_str.begin() ; it != input_str.end() ; it ++)
    {
        if (*it >= 48 && *it <= 57)
            temp = temp + *it ;
        else 
        {
            if (temp != "")
            {
                arr_deque.push_back(stoi(temp)) ;
                temp = "" ;
            }
        }
    }
}
int main()
{
    int test_count ;
    deque<int> arr_deque ;
    deque<char> fun_deque ;
    int element_count ;
    bool error_flag ;
    bool R_is_odd ;
    cin >> test_count ;
    cin.get() ;
    for (int i = 0 ; i < test_count ; i ++)
    {
        arr_deque.clear() ;
        fun_deque.clear() ;
        error_flag = false ;
        R_is_odd = false ;
        input_value(arr_deque , fun_deque , element_count) ;
        for (deque<char>::iterator it = fun_deque.begin() ; it != fun_deque.end() ; it ++)
        {
            if (*it == 'R')
            {
                R_is_odd = !R_is_odd ;
            }
            else // 'D'
            {
                if (element_count == 0)
                {
                    error_flag = true ;
                    break ;
                }
                else
                {
                    if (R_is_odd)
                    {
                        arr_deque.pop_back() ;
                    }
                    else
                    {
                        arr_deque.pop_front() ;
                    }
                }
                element_count -- ;    
            }
        }
        if (error_flag)
        {
            cout << "error\n" ;
        }
        else
        {
            int index ;
            cout << "[" ;
            for (size_t i = 0 ; i < arr_deque.size() ; i ++)
            {  
                if (R_is_odd)
                    index = arr_deque.size() - i - 1 ;
                else
                    index = i ;
                cout << arr_deque[index] ;
                if (i < arr_deque.size() - 1)
                    cout << "," ;
            }
            cout << "]\n" ;
        }
    }
    return 0 ;
}