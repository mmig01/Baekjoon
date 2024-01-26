// 가장 가까운 세 사람의 심리적 거리
#include<iostream>
#include<vector>
using namespace std ;
vector<string> my_vec ;
string MBTI[16] = {"ISTJ" , "ISFJ" , "INFJ" , "INTJ" , "ISTP" , "ISFP" , 
    "INFP" , "INTP" , "ESTP" , "ESFP" , "ENFP" , "ENTP" , "ESTJ" , "ESFJ" , "ENFJ" , "ENTJ"} ;
bool is_visit[100000] = {false} ;
void Clear()
{
    for (int i = 0 ; i < 100000 ; i ++)
        is_visit[i] = false ;
}
bool Search(string & target_str)
{
    bool result = false ;
    for (size_t i = 0 ; i < my_vec.size() ; i ++)
    {
        if (is_visit[i] == false && my_vec[i] == target_str)
        {
            is_visit[i] = true ;
            result = true ;
            break ;
        }
    }
    return result ;
}
int GetCount()
{
    int count , result = 12 ;
    for (int i = 0 ; i < 16 ; i ++)
        for (int j = i ; j < 16 ; j ++)
            for (int k = j ; k < 16 ; k ++)
            {
                count = 0 ;
                Clear() ;
                for (int l = 0 ; l < 4 ; l ++)
                {
                    if (MBTI[i][l] != MBTI[j][l])
                        count ++ ;
                    if (MBTI[j][l] != MBTI[k][l])
                        count ++ ;
                    if (MBTI[k][l] != MBTI[i][l])
                        count ++ ;
                }
                if (Search(MBTI[i]) && Search(MBTI[j]) && Search(MBTI[k]) && result > count)
                        result = count ;
            }
    return result ;
}
int main()
{
    int test_count , total_count ;
    cin >> total_count ;
    for (int j = 0 ; j < total_count ; j ++)
    {
        my_vec.clear() ;
        cin >> test_count ;
        for (int i = 0 ; i < test_count ; i ++)
        {
            string temp ;
            cin >> temp ;
            my_vec.push_back(temp) ;
        }
        cout << GetCount() << '\n' ;
    }
    return 0 ;
}