//리모콘
#include<iostream>
#include<deque>
#include<cstdlib>
using namespace std ;
void SetRemoteControllerButtons(deque<int> & remote_controller_buttons)
{
    for (int i = 0 ; i < 10 ; i ++)
    {
        remote_controller_buttons.push_back(i) ;
    }
}
void SetChannelElements(deque<int> & channel_elements , int & current_channel)
{   // 버튼을 누를 때 활용하기 위해 각 자리수를 나누어서 저장
    int channel = current_channel ;
    int elements ;
    channel_elements.clear() ;
    while (true)
    {
        elements = channel % 10 ;
        channel_elements.push_front(elements) ;
        channel = channel / 10 ;
        if (channel == 0) break ;
    }
}
int SetMinCount(deque<int> & channel_elements , deque<int> & remote_controller_buttons , int & target_channel)
{
    bool exist ;
    int current_channel ;
    int count ;
    int min_count = abs(target_channel - 100) ; // 초기 최소 카운트는 up , down 버튼으로만 이동한 거리로 설정
    for (int i = 0 ; i < 1000001 ; i ++) // 이동 채널이 500000 번보다 클 수도 있으므로 1000001 번째 채널까지 탐색
    {   // 1000001 은 단지 임의의 큰 숫자임.
        current_channel = i ;
        SetChannelElements(channel_elements , current_channel) ;
        exist = true ;
    
        for (size_t i = 0 ; i < channel_elements.size() ; i ++)
        {
            int element = channel_elements[i] ;
            if (remote_controller_buttons[element] == -1) // 버튼이 존재하지 않을 때
            {
                exist = false ;
                break ;
            }
        }

        if (exist == true)
        {   // 버튼이 모두 존재하므로 channel elements 의 size 는 버튼을 누른 횟수를 의미
            count = abs(target_channel - current_channel) + (int)channel_elements.size() ;
        }
        else
        {
            continue ;
        }

        if (count < min_count)
        {   // 최소 카운트를 설정
            min_count = count ;
            //cout << "current_channel : " << current_channel << '\n' ;
            //cout << "count : " << count << '\n' ;
        }
    }
    return min_count ;
}
int main()
{
    deque<int> channel_elements ;
    deque<int> remote_controller_buttons ;
    int target_channel ;
    int remove_button ;
    int remove_button_count ;
    int min_count ; 
    SetRemoteControllerButtons(remote_controller_buttons) ; // 0 부터 9까지의 버튼 설정

    cin >> target_channel >> remove_button_count ;
    for (int i = 0 ; i < remove_button_count ; i ++)
    {   // 고장난 버튼은 -1로 처리
        cin >> remove_button ;
        remote_controller_buttons[remove_button] = -1 ;
    }
    
    min_count = SetMinCount(channel_elements , remote_controller_buttons , target_channel) ;
    cout << min_count ;
    return 0 ;
}