#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#include "types.h"
#include "defs.h"
#include "spinlock.h"
#include "queue.h"
#include "user.h"

// every time semaphore is declared, 
// initialize its queue field using init_q
struct Semaphore 
{
	lock_t lock;		// the lock
	int value;		// increment/decrement value
	struct queue * q;    	// waiting queue
};

void sem_init(struct Semaphore * s, int a)
{
	s->value = a;
	init_q(s->q);
	lock_init(s->lock);
};	
	

void sem_acquire(struct Semaphore * s)
{
	if (s->value >= 0)
	{
		s->value = s->value - 1;
		if (s->value < 0)
		{
			lock_acquire(s->lock);
		}

	}
	// while (s->value < 1);	
};

void sem_signal(struct Semaphore * s)
{
	
};





#endif
