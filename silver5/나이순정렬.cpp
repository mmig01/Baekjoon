#include<iostream>
using namespace std ;
typedef struct
{
    int age ;
    std::string name ;
    int order ;
} Member ;
Member member[100001] ;
void makeHeap(int mIndex , int N) ;
void sortHeap(int mIndex) ;
int main()
{
    int iIndex , N ;
    cin >> N ;
    for (int i = 0 ; i < N ; i ++)
    {  
        iIndex = i + 1 ;
        cin >> member[iIndex].age >> member[iIndex].name ;
        member[iIndex].order = iIndex ;
    }
    for (int i = 0 ; i < N / 2 ; i ++)
    {
        iIndex = N / 2 - i ;
        makeHeap(iIndex , N) ;
    }
    for (int i = 0 ; i < N ; i ++)
    {  
        iIndex = N - i ;
        sortHeap(iIndex) ;
    }
    for (int i = 0 ; i < N ; i ++)
    {  
        iIndex = i + 1 ;
        cout << member[iIndex].age << " " << member[iIndex].name << '\n' ;
    }
    return 0 ;
}
void makeHeap(int mIndex , int N)
{
    int iRoot , iCursor , iIndex ;
    //mIndex = 5 / 2 ;
    iRoot = mIndex ;
    iCursor = iRoot * 2 ;
    if (iCursor < N )
    {
        if (member[iCursor].age < member[iCursor + 1].age) iCursor ++ ;
        else if (member[iCursor].age == member[iCursor + 1].age)
        {
            if (member[iCursor].order < member[iCursor + 1].order) 
            iCursor ++ ;
        }
    }
   

    if (member[iCursor].age > member[iRoot].age) 
    {
        swap(member[iCursor].age , member[iRoot].age) ;
        swap(member[iCursor].name , member[iRoot].name) ;
        swap(member[iCursor].order , member[iRoot].order) ;
        if (iCursor <= (N / 2)) makeHeap(iCursor , N) ;
    }
    else if(member[iCursor].age == member[iRoot].age)
    {
        if (member[iCursor].order > member[iRoot].order) 
        {
            swap(member[iCursor].age , member[iRoot].age) ;
            swap(member[iCursor].name , member[iRoot].name) ;
            swap(member[iCursor].order , member[iRoot].order) ;
            if (iCursor <= (N / 2)) makeHeap(iCursor , N) ;
        }
    }
}
void sortHeap(int mIndex)
{
    swap(member[1].age , member[mIndex].age) ;
    swap(member[1].name , member[mIndex].name) ;
    swap(member[1].order , member[mIndex].order) ;
    int iRoot , iCursor = 0 ;
    
    iRoot = 1 ;
    while (true)
    {
        if (iCursor >= mIndex) break ;
        iCursor = iRoot * 2 ;
        
        if (iCursor < mIndex - 1)
        {
            if (member[iCursor].age < member[iCursor + 1].age) iCursor ++ ;
            else if (member[iCursor].age == member[iCursor + 1].age) 
            {
                if (member[iCursor].order < member[iCursor + 1].order)
                iCursor ++ ;
            }
        }

        if (iCursor < mIndex)  
        {
            if (member[iCursor].age > member[iRoot].age)
            {
                swap(member[iCursor].age , member[iRoot].age) ;
                swap(member[iCursor].name , member[iRoot].name) ;
                swap(member[iCursor].order , member[iRoot].order) ;
            }
            else if (member[iCursor].age == member[iRoot].age)
            {
                if (member[iCursor].order > member[iRoot].order)
                {
                    swap(member[iCursor].age , member[iRoot].age) ;
                    swap(member[iCursor].name , member[iRoot].name) ;
                    swap(member[iCursor].order , member[iRoot].order) ;
                }
            }
        }
        
        
        iRoot = iCursor ;
    }

}