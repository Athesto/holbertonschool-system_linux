#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <sys/types.h> /* pid_t */
#include <signal.h> /* signal */
#include <stdio.h> /* printf */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE */
/* #include <unistd.h> */

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);
void all_in_one(void);
int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);
int signals_unblock(int *signals);
int handle_pending(void (*handler)(int));

#endif /* _SIGNALS_H_ */
