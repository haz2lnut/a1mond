#ifndef __SA_H__
#define __SA_H__

#include "netype.h"

typedef struct {
	struct {
		ip4_addr ip;
	}local, remote;
}sa_t;

#endif //__SA_H__
