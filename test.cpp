/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年10月29日 10时42分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sun lianqiang (milton), 170262941@qq.com
 *        Company:  Giant
 *
 * =====================================================================================
 */


//============================================================================
// Name        : test.cpp
// Author      : archy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>

#include "Timer.h"


using namespace std;

int handle_timeout()
{
    unsigned int time = get_systime_clock();
    printf("time out,%u\n",time);
    return 0;
}

int main()
{
    Timer _timer;
    _timer.open(1,handle_timeout);
    TIMERMANAGE->Register(_timer);
    TIMERMANAGE->start();
    getchar();
    return 0;
}