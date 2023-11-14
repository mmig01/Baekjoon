#include<iostream>
typedef struct circleQueue
{
    int MAX_SIZE ;
    int front ;
    int rear ;

    void clear()
    {
        front = rear ;
    }
    int size()
    {
        return (front - rear + MAX_SIZE) % MAX_SIZE ;
    } 

    bool isEmpty()
    {

    }
    bool isFull()
    {

    }
    bool enqueue()
    {

    }
    bool dequeue()
    {

    }

} CircleQueue ;
int main()
{
    int a ;
    return 0 ;
    
}