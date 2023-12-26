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
    
    cout << (int)round(result) << '\n' ;
}
void showManyView(vector<int> & vArr , int N)
{  
    int iMaxNum ;
    int iMaxCount ;
    bool bCount ;
    for (int i = 0 ; i < N ; i ++)
    {  
        if (vArr[i] >= 0)
            vPositive[vArr[i]] ++ ;
        else
            vNegative[(- vArr[i])] ++ ;
    }

    bCount = false ;
    iMaxNum = 0 ;
    iMaxCount = 0 ;
    for (int i = 4000 ; i > 0 ; i --)
    {  
        if (vNegative[i] >= 1) // 한 번 이상 입력 되었을 때
        {
            if (iMaxCount <= vNegative[i])
            {
                if ((iMaxCount == vNegative[i]) && (bCount == false))
                {
                    iMaxNum = -i ;
                    bCount = true ;
                }
                else if (iMaxCount < vNegative[i])
                {
                    iMaxCount = vNegative[i] ;
                    iMaxNum = -i ;
                    bCount = false ;
                }
            }     
        }   
    }
    for (int i = 0 ; i < 4001 ; i ++)
    {  
        if (vPositive[i] >= 1) // 한 번 이상 입력 되었을 때
        {
            if (iMaxCount <= vPositive[i])
            {
                if ((iMaxCount == vPositive[i]) && bCount == false)
                {
                    iMaxNum = i ;
                    bCount = true ;
                }
                else if (iMaxCount < vPositive[i])
                {
                    iMaxCount = vPositive[i] ;
                    iMaxNum = i ;
                    bCount = false ;
                }
            }     
        }
    }
    // maxcount is available
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