#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
long long getLarge(vector<long long> iNumber , long start , long end , long iCount)
{   // 이분 탐색
    long long iMid , iTemp , iTempCount ;
    iMid = (start + end) / 2 ; // 중앙 값 설정

    iTempCount = 0 ;
    for (int i = 0 ; i < iNumber.size() ; i ++)
    { 
        iTemp = iNumber[i] / iMid ;
        iTempCount = iTempCount + iTemp ;
    }
    if (start >= end) // 이분 탐색이 끝났을 때
    {   // 재귀함수 리턴 조건
        if (iTempCount >= iCount)
            return iMid ;
        else
        {   // 만약 마지막에 실행한 이분탐색 결과가 Count를 만족하지 못할 때
            // Mid 값을 한 칸 왼쪽으로 변경
            return iMid - 1 ;
        }
    }
    else
    {
        if (iTempCount >= iCount) 
        {   // 혹시 Count 를 만족하는 더 큰 수가 있을수도 있기 때문에
            // 오른쪽 이분 탐색 결과를 리턴
            return getLarge(iNumber , iMid + 1 , end , iCount) ;
        }
        else 
        {   // 왼쪽 이분 탐색
            return getLarge(iNumber , start , iMid - 1 , iCount) ;
        }
    }
    
}
int main()
{
    vector<long long> iNumber ;
    long long iResult ;
    int iHave , iCount ; // = 4 , = 11 
    cin >> iHave >> iCount ;

    for (int i = 0 ; i < iHave ; i ++)
    {
        int temp ;
        cin >> temp ;
        iNumber.push_back(temp) ;
    }

    sort(iNumber.begin() , iNumber.end()) ; // 벡터 정렬
    iResult = getLarge(iNumber , 1 , iNumber.back() , iCount) ;
    cout << iResult ;

    return 0 ;
}