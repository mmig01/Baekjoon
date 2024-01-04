//잃어버린 괄호
#include<iostream>
#include<string>
#include<vector>

int main()
{
    std::string result ;
    std::getline(std::cin , result) ;
    bool isPlus = true ;
    int start , sum ;
    start = 0 ;
    sum = 0 ;
    for (size_t i = 0 ; i < result.size() ; i ++)
    {
        int index = int(i) ;
        int element = int(result[index]) ;
        if (element >= 48 && element <= 57 && (i + 1 != result.size()))
        {
            continue ;
        }
        else
        {
            // - or + or last element
            std::string temp = result.substr(start) ;
            if (isPlus)
            {
                sum = sum + stoi(temp) ;
            }
            else
            {
                sum = sum - stoi(temp) ;
            }

            if (element == 45) // -
            {
                isPlus = false ;
            }
            start = index ;
            start ++ ;
        }
    }
    
    std::cout << sum ;
    exit(0) ;
}