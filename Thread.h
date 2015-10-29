/*
 * =====================================================================================
 *
 *       Filename:  Thread.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年10月29日 10时36分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sun lianqiang (milton), 170262941@qq.com
 *        Company:  Giant
 *
 * =====================================================================================
 */

/*************************************************************************
  > File Name: Thread.h
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年10月29日 星期四 10时36分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
/*
 *   Thread.h
 *   
 *      Created on: Sep 11, 2012
 *           Author: root
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class Thread {


	public:
		enum THREADSTATE
		{

			IDLE,
			WORK,
			BUSY,
		};

	public:

		Thread();

		virtual ~Thread();

		virtual void* run(void) = 0;

		virtual int start(void);

		virtual int cancel(void);

		pthread_t get_pid() const
		{

			return pid;
		}

	protected:

		THREADSTATE _thread_state;

	private:

		pthread_t pid;

		static void* thread_entry(void* para);
};

#endif /* THREAD_H_ */
