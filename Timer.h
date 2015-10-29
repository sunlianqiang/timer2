/*
 * =====================================================================================
 *
 *       Filename:  Timer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年10月29日 10时42分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sun lianqiang (milton), 170262941@qq.com
 *        Company:  Giant
 *
 * =====================================================================================
 */


/*
 * Timer.h
 *
 *  Created on: Sep 11, 2012
 *      Author: root
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Thread.h"
#include <list>

using namespace std;

struct Timer
{

    void *_args;
    int (*_callback)();
    int _interval;
    int leftsecs;
    void open(int interval,int (*callback)())
    {
        _interval = interval * 1000;
        leftsecs = _interval;
        _callback = callback;
    }

    bool operator < (Timer _timer)
    {
        return _timer.leftsecs < this->leftsecs;
    }

    bool operator == (Timer _timer)
    {
        return _timer.leftsecs == this->leftsecs;
    }

};

class TimerThread : public Thread
{

public:

    static TimerThread* _instance;

    static TimerThread* get_instance();

    virtual void* run(void);

    virtual ~TimerThread();

    void Register(Timer _timer);

    void unRegister(Timer _timer);

private:

    TimerThread();

    list<Timer> _timer_list;

};

extern unsigned int get_systime_clock();



#define TIMERMANAGE TimerThread::get_instance()

#endif /* TIMER_H_ */