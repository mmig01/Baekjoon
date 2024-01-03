//케빈 베이컨의 6단계 법칙
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
void SetGraph(std::vector<int> * my_graph , int edge_count)
{
    int vertex , edge ;
    for (int i = 0 ; i < edge_count ; i ++)
    {
        std::cin >> vertex >> edge ;
        my_graph[vertex].push_back(edge) ;
        my_graph[edge].push_back(vertex) ;
    }
}
void GraphSort(std::vector<int> * my_graph)
{
    std::vector<int>::iterator iter ;
    for (int i = 0 ; i < 101 ; i ++)
    {
        for (iter = my_graph[i].begin() ; iter != my_graph[i].end() ; iter ++)
        {
            sort(my_graph[i].begin() , my_graph[i].end()) ;
        }
    }
}
void RemoveSameElements(std::vector<int> * my_graph)
{
    std::vector<int>::iterator iter ;
    for (int i = 0 ; i < 101 ; i ++)
    {
        iter = std::unique(my_graph[i].begin() , my_graph[i].end()) ;
        my_graph[i].resize(std::distance(my_graph[i].begin() , iter)) ;
    }
}
int BFS(std::vector<int> * my_graph , int start_vertex)
{
    int current_vertex ;
    int sum = 0 ;
    int step = 0 ;
    bool isVisit[101] = {false} ;
    isVisit[start_vertex] = true ;
    std::deque<int> bfs_deque ;
    bfs_deque.push_back(start_vertex) ;
    while (true)
    {
        int size = bfs_deque.size() ;
        for (int i = 0 ; i < size ; i ++)
        {
            current_vertex = bfs_deque.front() ;
            bfs_deque.pop_front() ;
            sum = sum + step ;
            for (size_t i = 0 ; i < my_graph[current_vertex].size() ; i ++)
            {
                int current_edge = my_graph[current_vertex][int(i)] ;
                if (isVisit[current_edge] == false)
                {
                    isVisit[current_edge] = true ;
                    bfs_deque.push_back(current_edge) ;
                }
            }
        }
        step ++ ;
        if (bfs_deque.empty()) break ;
    } 
    return sum ;
}
int main()
{
    std::vector<int> user[101] ;
    int user_count , relationship_count ;
    int min_count , min_user ;
    std::cin >> user_count >> relationship_count ;
    SetGraph(user , relationship_count) ;
    GraphSort(user) ;
    RemoveSameElements(user) ;
    for (int i = 0 ; i < user_count ; i ++)
    {
        if (i == 0)
        {
            min_count = BFS(user, i + 1) ;
            min_user = i + 1 ;
        }
        else
        {
            int count = BFS(user , i + 1) ;
            if (min_count > count)
            {
                min_count = count ;
                min_user = i + 1 ;
            }
        }
    }
    std::cout << min_user ;
    return 0 ;
}