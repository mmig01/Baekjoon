// 거짓말
/*
변수 : 사람의 수 person_cnt , 파티의 수 party_cnt , 
    진실을 아는 사람의 수 truth_cnt , 진실을 아는 사람 truth_person
    각 파티마다 오는 사람의 수 join_party_cnt , 파티마다 오는 사람 join_party_person
    진실을 아는 사람의 수를 저장할 배열 'int' know_truth[person_cnt]
    사람들 전체의 배열 person[51] ;
알고리즘 :
know_truth[51] 에 있는 사람 A , person[A] = true ;
party[k][51] 에 A 가 있고 party[k] 의 사람들이 진실을 모르는 상태일 때 person[사람] 을 true 로 변경한 다음 queue 에 push
*/
#include<iostream>
#include<deque>
using namespace std ;
bool isPartyPossible[51] ;
bool person[51] ; 
int know_truth_person[51] ;
int party[51][51] ;
void Clear()
{
    for (int i = 1 ; i <= 51 ; i ++)
        isPartyPossible[i] = true ;
}
bool IsExist(int row , int party_person_cnt , int know_person)
{
    bool result = false ;
    for (int i = 1 ; i <= party_person_cnt ; i ++)
    {
        if (party[row][i] == know_person)
            result = true ;
    }
    return result ;
}
void BFS(int truth_person_cnt , int total_party_cnt)
{
    deque<int> BFS_dqe ;
    for (int i = 1 ; i <= truth_person_cnt ; i ++)
    {
        BFS_dqe.push_back(know_truth_person[i]) ;
        while (!BFS_dqe.empty())
        {
            int cur = BFS_dqe.front() ;
            BFS_dqe.pop_front() ;
            person[cur] = true ;
            for (int j = 1 ; j <= total_party_cnt ; j ++)
            {
                int party_person_cnt = party[j][0] ;
                if (IsExist(j , party_person_cnt , cur))
                {
                    isPartyPossible[j] = false ;
                    for (int k = 1 ; k <= party_person_cnt ; k ++)
                    {
                        if (person[party[j][k]] == false)
                        {
                            person[party[j][k]] = true ;
                            BFS_dqe.push_back(party[j][k]) ;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int total_person_cnt , total_party_cnt ;
    int truth_person_cnt , truth_person ;
    int party_person_cnt , party_person ;
    int result = 0 ;

    Clear() ;
    cin >> total_person_cnt >> total_party_cnt ;
    cin >> truth_person_cnt ;
    for (int i = 1 ; i <= truth_person_cnt ; i ++)
        cin >> know_truth_person[i] ;
    for (int i = 1 ; i <= total_party_cnt ; i ++)
    {
        cin >> party_person_cnt ;
        party[i][0] = party_person_cnt ;
        for (int j = 1 ; j <= party_person_cnt ; j ++)
            cin >> party[i][j] ;
    }
    BFS(truth_person_cnt , total_party_cnt) ;
    for (int i = 1 ; i <= total_party_cnt ; i ++)
    {
        if (isPartyPossible[i])
            result ++ ;
    }
    cout << result ;
    return 0 ;
}