#include<iostream>
class CircleQueue
{
    private :
        int MAX_SIZE ;
        int front ;
        int rear ;
        int * iCircleQueue ;

    public :
        CircleQueue(int size)
        { 
            MAX_SIZE = size ; 
            iCircleQueue = new int[MAX_SIZE] ;
        } 
        ~CircleQueue()
        {
            delete iCircleQueue ;
        } 
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
            if (front == rear) return true ;
            else return false ;
        }
        bool isFull()
        {
            int temp = (rear + 1) % MAX_SIZE ;
            if (front == temp) return true ;
            else return false ;
        }
        void enqueue(int item)
        {
            if (!isFull())
            {
                rear = (rear + 1) % MAX_SIZE ;
                iCircleQueue[rear] = item ;
            }
        }
        void dequeue()
        {

        }
} ;
int main()
{
    int a ;
    return 0 ;
    
}