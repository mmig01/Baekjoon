#include<iostream>
using std::cin ;
using std::cout ;
int reverseN(int n);
int main()
{
    int iFirstNum , iSecondNum ;
    cin >> iFirstNum >> iSecondNum ;
    cout << reverseN(reverseN(iFirstNum) + reverseN(iSecondNum)) ;
    return 0 ;
}
int reverseN(int number){
	int reverseNum = 0 ;
	while(true)
    {
        if (number <= 0) break ;
		reverseNum = reverseNum * 10 ;
        reverseNum = reverseNum + (number % 10) ;
		number = number / 10 ;
	}
	return reverseNum ;
}
