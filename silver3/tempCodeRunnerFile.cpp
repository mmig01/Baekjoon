#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std ;
vector<int> vPositive(4001) ;
vector<int> vNegative(4001) ;
void showMean(vector<int> & vArr , int N)
{
    int total = 0 ;
    double result ;
    for (int i = 0 ; i < N ; i ++)
    {  
        total = total + vArr[i] ;
    }
    result = (double)total / N ;
    
    cout << floor(result + 0.5) << '\n' ;
}
void showManyView(vector<int> & vArr , int N)
{  
    int iMaxNum = -4000 ;
    int iMaxCount = vNegative[4000] ;
    int iCount = 0 ;
    for (int i = 0 ; i < N ; i ++)
    {  
        if (vArr[i] >= 0)
            vPositive[vArr[i]] ++ ;
        else
            vNegative[(- vArr[i])] ++ ;
    }

    for (int i = 3999 ; i > 0 ; i --)
    {  
        if (vNegative[i] >= 1)
        {
            if (iMaxCount < vNegative[i])
            {
                iMaxCount = vNegative[i] ;
                iMaxNum = -i ;
            }     
        }   
    }
    for (int i = 0 ; i < 4001 ; i ++)
    {  
        if (iMaxCount < vPositive[i])
        {
            iMaxCount = vPositive[i] ;
            iMaxNum = i ;
        }     
    }
    // maxcount is available
    for (int i = 3999 ; i > 0 ; i --)
    {  
        if (vNegative[i] == iMaxCount)
        {
            iCount ++ ;
            if (iCount == 2)
                iMaxNum = - i ;
        }
    }
    for (int i = 0 ; i < 4001 ; i ++)
    {  
        if (vPositive[i] == iMaxCount)
        {
            iCount ++ ;
            if (iCount == 2)
                iMaxNum = i ;
        }
    }
    cout << iMaxNum << '\n' ;
}
void showRange(vector<int> & vArr , int N)
{
    int iMax = vArr[0] ;
    int iMin = vArr[0] ;
    for (int i = 0 ; i < N ; i ++)
    {
        if (iMax < vArr[i])
            iMax = vArr[i] ;
    }
    for (int i = 0 ; i < N ; i ++)
    {
        if (iMin > vArr[i])
            iMin = vArr[i] ;
    }

    cout << iMax - iMin << '\n' ;
}
void showMiddle(vector<int> & vArr , int N)
{
    cout << vArr[N/2] << '\n' ;
}
int main()
{
    int N ;
    vector<int> vArr ;

    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {  
        int temp ;
        cin >> temp ;
        vArr.push_back(temp) ;
    }
    sort(vArr.begin() , vArr.end()) ;

    showMean(vArr , N) ;
    showMiddle(vArr , N) ;
    showManyView(vArr , N) ;
    showRange(vArr , N) ;

    return 0 ;
}