/*
 * =====================================================================================
 *
 *       Filename:  Thread.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年10月29日 10时40分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sun lianqiang (milton), 170262941@qq.com
 *        Company:  Giant
 *
 * =====================================================================================
 */

/*************************************************************************
  > File Name: Thread.cpp
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年10月29日 星期四 10时40分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

/*
 * Thread.cpp
 *
 *  Created on: Sep 11, 2012
 *      Author: root
 */

#include "Thread.h"

Thread::Thread() {

	// TODO Auto-generated constructor stub

}

Thread::~Thread() {

	// TODO Auto-generated destructor stub
}

void* Thread::thread_entry(void* para)
{

	Thread *pThread = static_cast<Thread *>(para);
	return pThread->run();
}

int Thread::start(void)
{

	if(pthread_create(&pid,0,thread_entry,static_cast<void *>(this)) < 0)
	{

		pthread_detach(this->pid);
		return -1;
	}
	return 0;
}

int Thread::cancel(void)
{

	pthread_cancel(this->pid);
	return 0;
}
