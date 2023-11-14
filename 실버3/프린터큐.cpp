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
// 자료구조가 원형 큐일 필요는 없음
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
} // 주어진 배열에서 최댓값을 구하는 함수
int getQueueOrder(CircleQueue & circleQ , CircleQueue & orderQ , vector<int> & iNum)
{   
    int iTempNum , iTempOrder;
    int iSize , iMax ;

    iSize = circleQ.size() ;
    iMax = getMax(iNum) ; // 최댓값 설정
    for (int i = 0 ; i < iSize ; i ++)
    {
        iTempNum = circleQ.dequeue() ;
        iTempOrder = orderQ.dequeue() ;
        // 배열 값을 담은 큐와 인덱스 자체를 값으로 담은 큐
        // 이 둘은 함께 동작함. 
        if (iTempNum == iMax) // front 부터 dequeue 를 하다 최댓값을 만나면 break
        {
            break ;
        }
        else 
        {
            circleQ.enqueue(iTempNum) ;
            orderQ.enqueue(iTempOrder) ;
            // 원형 큐를 사용 했으므로 맨 뒤에 다시 삽입
        }      
    }
    return iTempOrder ; // 최댓값에 해당하는 인덱스 정보를 리턴
    //ex) [0] -> 2 , [1] -> 1 , [2] -> 3 이면 3에 해당하는 인덱스인 '2' 를 리턴
}
void getCircleQAndOrderQ(CircleQueue & circleQ , CircleQueue & orderQ , vector<int> & iNum, int iSize)
{
    for (int i = 0 ; i < iSize ; i ++)
    {
        circleQ.enqueue(iNum[i]) ; // 주어진 배열 정보를 저장
    }
    for (int i = 0 ; i < iSize ; i ++)
    {
        orderQ.enqueue(i) ; // 0부터 차례대로 인덱스 값을 저장
    }   
}
void getNumberArray(vector<int> & iNum , int iSize)
{
    iNum.clear() ; // vector 초기화
    for (int i = 0 ; i < iSize ; i ++)
    {
        int iTemp ;
        cin >> iTemp ;
        iNum.push_back(iTemp) ; // 문제에서 주어진 배열을 vector 에 추가
    }
}
// 본 예제는 원형 큐를 활용하여 구현 하였습니다.
int main()
{
    vector<int> iNum ;
    int iTotalCount ;
    int iSize , iIndex ; 
    int iCount , iResult ;

    cin >> iTotalCount ;
    for (int i = 0 ; i < iTotalCount ; i ++)
    {
        cin >> iSize >> iIndex ;
        CircleQueue circleQ = CircleQueue(iSize + 1) ;
        CircleQueue orderQ = CircleQueue(iSize + 1) ;

        getNumberArray(iNum , iSize) ;
        getCircleQAndOrderQ(circleQ , orderQ , iNum , iSize) ;

        iCount = 0 ; // 순서를 저장할 변수
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