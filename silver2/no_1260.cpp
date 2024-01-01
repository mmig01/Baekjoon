//dfs bfs
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<functional>
using namespace std ;
void SetGraph(vector<int> * my_graph , int edge_count)
{
    int vertex , edge ;
    for (int i = 0 ; i < edge_count ; i ++)
    {
        cin >> vertex >> edge ;
        my_graph[vertex].push_back(edge) ;
        my_graph[edge].push_back(vertex) ;
    }
}
void GraphClear(vector<int> * my_graph)
{
    for (int i = 0 ; i < 1001 ; i ++)
    {
        my_graph[i].clear() ;
    }
}
void IncreaseSort(vector<int> * my_graph)
{
    for (int i = 0 ; i < 1001 ; i ++)
    {
        for (size_t j = 0 ; j < my_graph[i].size() ; j ++)
        {
            sort(my_graph[i].begin() , my_graph[i].end()) ;
        }
    }
}
void DecreaseSort(vector<int> * my_graph)
{
    for (int i = 0 ; i < 1001 ; i ++)
    {
        for (size_t j = 0 ; j < my_graph[i].size() ; j ++)
        {
            sort(my_graph[i].begin() , my_graph[i].end() , greater<int>()) ;
        }
    }
}
void EraseSameElements(vector<int> * my_graph)
{
    for (int i = 0 ; i < 1001 ; i ++)
    {
        for (size_t j = 0 ; j < my_graph[i].size() ; j ++)
        {
            my_graph[i].erase(unique(my_graph[i].begin() , my_graph[i].end()) , my_graph[i].end()) ;
        }
    }
}
void IsVisitClear(bool * isVisit)
{
    for (int i = 0 ; i < 1001 ; i ++)
    {
        isVisit[i] = false ;
    }
}
void DFS(vector<int> * my_graph , vector<int> & dfs_vector , bool * isVisit , int start_vertex)
{
    int current_vertex ;
    dfs_vector.push_back(start_vertex) ;
    while (true)
    {
        current_vertex = dfs_vector.back() ;
        dfs_vector.pop_back() ;
        if (isVisit[current_vertex] == false)
        {
            isVisit[current_vertex] = true ;
            cout << current_vertex << " " ;
            for (size_t i = 0 ; i < my_graph[current_vertex].size() ; i ++)
            {
                int current_edge = my_graph[current_vertex][int(i)] ;
                if (isVisit[current_edge] == false)
                {
                    dfs_vector.push_back(current_edge) ;
                }
            }
        }
        if (dfs_vector.empty()) break ;
    } 
}
void BFS(vector<int> * my_graph , deque<int> & bfs_deque , bool * isVisit , int start_vertex)
{
    int current_vertex ;
    bfs_deque.push_back(start_vertex) ;
    while (true)
    {
        current_vertex = bfs_deque.front() ;
        bfs_deque.pop_front() ;
        if (isVisit[current_vertex] == false)
        {
            isVisit[current_vertex] = true ;
            cout << current_vertex << " " ;
            for (size_t i = 0 ; i < my_graph[current_vertex].size() ; i ++)
            {
                int current_edge = my_graph[current_vertex][int(i)] ;
                if (isVisit[current_edge] == false)
                {
                    bfs_deque.push_back(current_edge) ;
                }
            }
        }
        if (bfs_deque.empty()) break ;
    }
        
}
int main()
{
    vector<int> my_graph[1001] ;
    vector<int> dfs_vector ;
    deque<int> bfs_deque ;
    bool isVisit[1001] ;
    int vertex_count , edge_count , start_vertex ;

    cin >> vertex_count >> edge_count >> start_vertex ;
    GraphClear(my_graph) ;
    SetGraph(my_graph , edge_count) ;
    EraseSameElements(my_graph) ;

    IsVisitClear(isVisit) ;
    DecreaseSort(my_graph) ;
    DFS(my_graph , dfs_vector , isVisit , start_vertex) ;
    cout << '\n' ;

    IsVisitClear(isVisit) ;
    IncreaseSort(my_graph) ;
    BFS(my_graph , bfs_deque , isVisit , start_vertex) ;
    
    return 0 ;
}