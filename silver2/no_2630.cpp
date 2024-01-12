//색종이 만들기
#include<iostream>
#include<vector>
using namespace std ;
int ColorPaperCount(vector< vector<int> > & my_vector , pair<int , int> start , int N , int flag)
{
    bool is_same = true ;
    int col , row ;
    int result ;
    if (N == 1)
    {
        if (my_vector[start.second][start.first] == flag)
            result = 1 ;
        else
            result = 0 ;
    }
    else
    {
        for (int i = 0 ; i < N ; i ++)
        {
            for (int j = 0 ; j < N ; j ++)
            {
                col = j + start.first ;
                row = i + start.second ;
                if (my_vector[row][col] != flag)
                {
                    is_same = false ;
                    break ;
                }   
            }
        }
        if (is_same)
            result = 1 ;
        else
        {
            int total ;
            total = ColorPaperCount(my_vector , start , N / 2 , flag) ;
            total = total + ColorPaperCount(my_vector , make_pair(start.first + N / 2 , start.second) , N / 2 , flag) ;
            total = total + ColorPaperCount(my_vector , make_pair(start.first , start.second + N / 2) , N / 2 , flag) ;
            total = total + ColorPaperCount(my_vector , make_pair(start.first + N / 2 , start.second + N / 2) , N / 2 , flag) ;
            result = total ;
        }
    }
    return result ;
}
int main()
{
    vector< vector<int> > color_paper(128) ;
    int N , input_num ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {
        for (int j = 0 ; j < N ; j ++)
        {
            cin >> input_num ;
            color_paper[i].push_back(input_num) ;
        }
    }
    cout << ColorPaperCount(color_paper , make_pair(0 , 0) , N , 0) << '\n';
    cout << ColorPaperCount(color_paper , make_pair(0 , 0) , N , 1) ;
    return 0 ;
}