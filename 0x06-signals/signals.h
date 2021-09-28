#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <signal.h> /* sigset_t */
#include <stddef.h> /* NULL */
#include <stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS */
#include <stdio.h> /* fprintf */

int handle_pending(void (*handler)(int));
int handle_sigaction(void);
int handle_signal(void);
int pid_exist(pid_t pid);
int signals_block(int *signals);
int signals_unblock(int *signals);
int sigset_init(sigset_t *set, int *signals);
int trace_signal_sender(void);
void (*current_handler_sigaction(void))(int);
void (*current_handler_signal(void))(int);
void all_in_one(void);
#endif /* _SIGNALS_H_ */
