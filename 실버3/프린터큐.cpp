#include<iostream>
#include<vector>
using namespace std ;
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
            clearQueue() ;
            MAX_SIZE = size ; 
            iCircleQueue = new int[MAX_SIZE] ;
        } 
        ~CircleQueue()
        {
            delete iCircleQueue ;
        } 
        void clearQueue()
        {
            front = rear  = 0 ;
        }
        int size()
        {
            return ((rear - front) + MAX_SIZE) % MAX_SIZE ;
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
            if (isFull())
            {
                cout << "Full.\n" ;
                return ;
            }
            
            rear = (rear + 1) % MAX_SIZE ;
            iCircleQueue[rear] = item ;
        }
        int dequeue()
        {
            if (isEmpty())
            {
                cout << "Empty.\n" ;
                return -1 ; 
            }
            front = (front + 1) % MAX_SIZE ;
            return iCircleQueue[front] ;
        }
        int getRear()
        {
            if (isEmpty())
            {
                cout << "Empty.\n" ;
                return -1 ; 
            }
            return iCircleQueue[rear] ;
        }
        
} ; 
// Circular Queue 코드 구현 연습

int getMax(vector<int> & iNum)
{
    int iMax = - 1 ;
    int iTemp ;
    for (int i = 0 ; i < iNum.size() ; i ++)
    {
        if (iMax < iNum[i])
        {
            iMax = iNum[i] ;
            iTemp = i ;
        }
    }
    iNum[iTemp] = -1 ; //  음수 값으로 설정
    return iMax ;
}
int getQueueOrder(CircleQueue & circleQ , CircleQueue & orderQ , vector<int> & iNum)
{   
    int iTempNum , iTempOrder;
    int iSize , iMax ;

    iSize = circleQ.size() ;
    iMax = getMax(iNum) ;
    for (int i = 0 ; i < iSize ; i ++)
    {
        iTempNum = circleQ.dequeue() ;
        iTempOrder = orderQ.dequeue() ;
        if (iTempNum == iMax) 
        {
            break ;
        }
        else 
        {
            circleQ.enqueue(iTempNum) ;
            orderQ.enqueue(iTempOrder) ;
        }      
    }
    return iTempOrder ;
}
int main()
{
    vector<int> iNum ;
    int iTotalCount , iSize , iIndex ;
    int iCount , iResult ;

    cin >> iTotalCount ;
    for (int i = 0 ; i < iTotalCount ; i ++)
    {
        cin >> iSize >> iIndex ;
        iNum.clear() ;
        CircleQueue circleQ = CircleQueue(iSize + 1) ;
        CircleQueue orderQ = CircleQueue(iSize + 1) ;
        for (int i = 0 ; i < iSize ; i ++)
        {
            int iTemp ;
            cin >> iTemp ;
            iNum.push_back(iTemp) ;
        }

        for (int i = 0 ; i < iSize ; i ++)
        {
            circleQ.enqueue(iNum[i]) ;
        }
        for (int i = 0 ; i < iSize ; i ++)
        {
            orderQ.enqueue(i) ;
        }

        iCount = 0 ;
        while (true)
        {
            if (circleQ.isEmpty()) break ;

            iResult = getQueueOrder(circleQ , orderQ , iNum) ;
            iCount ++ ;
            if (iResult == iIndex) break ;
        }
        cout << iCount << '\n' ;
    }
    
    return 0 ;
}