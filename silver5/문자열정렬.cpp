#include<iostream>
#include<algorithm>
#include<string>
bool compare(std::string a , std::string b) ;
int main()
{
    using namespace std ;
    using std::string ;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i , j , iTest , iMin , iIndex ;
    string sMin ,sTemp ;
    cin >> iTest ;
    cin.ignore();
    string * sString = new string [iTest] ;
    for (i = 0 ; i < iTest ; i ++)
    {
        getline(cin , sString[i]) ;
    }
    sort(sString , sString + iTest , compare) ;
    /*j = 0 ;
    for (i = 0; i < iTest ; i++)
	{
		while (sString[i] == sString[i + 1]) i ++;
		sString[j] = sString[i];
        j ++ ;
	}
    
	for (i = 0; i < j; i++)
	{
		cout << sString[i] << '\n';
	}
    */
    for (int i = 0 ; i < iTest ; i ++)
    {
        if (sTemp == sString[i]) continue ;
        cout << sString[i] << '\n' ;
        sTemp = sString[i] ;
    }
    delete[] sString ;
    return 0 ;
}

bool compare(std::string a , std::string b)
{
    if (a.length() == b.length())
    {
        return a < b ;
    }
    else
    {
        return a.length() < b.length() ;
    }
}