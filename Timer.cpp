/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年10月29日 10时42分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sun lianqiang (milton), 170262941@qq.com
 *        Company:  Giant
 *
 * =====================================================================================
 */



/*
 * Timer.cpp
 *
 *  Created on: Sep 11, 2012
 *      Author: root
 */

#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "Timer.h"

using namespace std;

TimerThread* TimerThread::_instance;



TimerThread::TimerThread()
{

}

TimerThread::~TimerThread()
{

}

void* TimerThread::run(void)
{
    while(true)
    {
        unsigned int start_clock = get_systime_clock();
        this->_timer_list.sort();
        list<Timer>::iterator iter;
        for(iter = this->_timer_list.begin();
                iter != this->_timer_list.end();
                    iter ++)
        {
            iter->leftsecs --;
            if(iter->leftsecs == 0)
            {
                iter->_callback();
                iter->leftsecs = iter->_interval;
            }
        }
        unsigned int end_clock = get_systime_clock();

        usleep(1000 + start_clock - end_clock);
    }
    return (void*)0;
}

void TimerThread::Register(Timer _timer)
{
    this->_timer_list.push_back(_timer);
}

void TimerThread::unRegister(Timer _timer)
{
    this->_timer_list.remove(_timer);
}

TimerThread* TimerThread::get_instance()
{
    if(_instance == NULL)
    {
        _instance = new TimerThread();
    }
    return _instance;
}



unsigned int get_systime_clock()
{
    struct timeval now;
    gettimeofday(&now,NULL);
    return now.tv_sec*1000 + now.tv_usec/1000;
}
