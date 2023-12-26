#include<iostream>
#include<vector>
//hihi
using namespace std ;
void getExample(vector<int> & vExample)
{
    int iInput ;

    cin >> iInput ;
    for (int i = 0 ; i < iInput ; i ++)
    {
        int iTemp ;
        cin >> iTemp ;
        vExample.push_back(iTemp) ;
    }
}
vector<int> getResult(vector<int> & vExample , vector<char> & vChar)
{
    int iNum ;
    vector<int> vArr ;
    vector<int> vResult ;
    iNum = 1 ;
    for (int i = 0 ; i < vExample.size() ; i ++)
    {
        if (vExample[i] < iNum)
        {
            if (!vArr.empty())
            {
                vResult.push_back(vArr.back()) ;
                vArr.pop_back() ;
                vChar.push_back('-') ;
            }      
        }
        else
        {   // iArr[i] > iNum
            while (true)
            {   
                if (vExample[i] == iNum)
                {
                    vArr.push_back(iNum) ;
                    vChar.push_back('+') ;
                    vResult.push_back(vArr.back()) ;
                    vArr.pop_back() ;
                    vChar.push_back('-') ;

                    iNum ++ ;
                    break ;
                }
                else
                {
                    vArr.push_back(iNum) ;
                    vChar.push_back('+') ;
                    iNum ++ ;
                } 
            }  
        } 
    }
    return vResult ;
}
bool isSame(vector<int> & vResult , vector<int> & vExample)
{
    bool bResult ;
    bResult = true ;
    for (int i = 0 ; i < vResult.size() ; i ++)
    {
        if (vResult[i] != vExample[i])
            bResult = false ;
    }
    return bResult ;
}
int main()
{
    int iInput ;
    bool bResult ;
    vector<int> vExample ;
    vector<int> vResult ;
    vector<char> vChar ;

    getExample(vExample) ;
    
    vResult = getResult(vExample , vChar) ;
    
    bResult = isSame(vResult , vExample) ;

    if (bResult == true)
    {
        for (int i = 0 ; i < vChar.size() ; i ++)
        {
            cout << vChar[i] << '\n' ;
        }
    }
    else
    {
        cout << "NO" ;
    }
    return 0 ;
}