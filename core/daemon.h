#ifndef __DAEMON_H__
#define __DAEMON_H__

#include "queue.h"
#include "network.h"
#include "command_interface.h"
#include "log.h"
#include "configure.h"
#include "sa.h"

#define WORKER_MAX 10
#define SDB_MAX 10

typedef struct {
	int				pid_fd;
	char			pid_file[256];
	bool			is_running;
	pthread_t worker[WORKER_MAX];
	queue_t*	job_que;
	pthread_t job_worker_id;

	// Modules
	network_t*						net;
	command_interface_t*	ci;
	log_t*								log;
	configure_t*					cnf;

	sa_t*									sdb[SDB_MAX];
	int										sdb_len;
}daemon_t;

typedef struct {
	void*		(*func)(void*);
	void*		arg;
}job_t;

extern daemon_t g_daemon;

int		daemon_create(const char* pid_fil);
void	daemon_free();

void	push_job(void* (*func)(void*), void* arg);

#endif //__DAEMON_H__
			 //
