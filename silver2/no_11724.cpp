// 연결 요소의 개수
#include<iostream>
#include<deque>
using namespace std ;
int GetCount(deque <deque<int> > & my_graph , bool visit_arr[] , int start)
{
    deque<int> my_deque ;
    my_deque.push_back(start) ;
    visit_arr[start] = true ;

    while (!my_deque.empty())
    {
        int current_vertex ;
        current_vertex = my_deque.front() ;
        my_deque.pop_front() ;
        for (deque<int>::iterator it = my_graph[current_vertex].begin() ; it != my_graph[current_vertex].end() ; it ++)
        {
            if (visit_arr[(*it)] == false)
            {
                visit_arr[(*it)] = true ;
                my_deque.push_back(*it) ;
            }
        }
    }
    return 1 ;
}
int main()
{
    deque< deque<int> > graph_deque(1001) ;
    bool is_visit[1001] = {false} ;
    int vertex_count , edge_count ;
    int vertex , edge ;
    int result = 0 ;
    cin >> vertex_count >> edge_count ;
    for (int i = 0 ; i < edge_count ; i ++)
    {
        cin >> vertex >> edge ;
        graph_deque[vertex].push_back(edge) ;
        graph_deque[edge].push_back(vertex) ;
    }

    for (int i = 0 ; i < vertex_count ; i ++)
    {
        if (is_visit[i + 1] == false)
        {
            result = result + GetCount(graph_deque , is_visit , i + 1) ;
        }
    }
    cout << result ;
    return 0 ;
}