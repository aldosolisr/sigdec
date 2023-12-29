/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *      Author : Aldo Solis Rincon                                                               *
 *        Date : 2023/12/29                                                                      *
 * Description : Program that prints signals numbers until command kill -9 <PID> is executed.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

static void print_signals(int sig);

int main(void){
    for(int i = 1; i <= 64; i++){
        signal(i, print_signals); // signal macro is asynchronous.
    }
    char* msg= "Program that prints signals numbers until command kill -9 <PID> is executed.\n";
    write(STDOUT_FILENO, msg, strlen(msg));  // write function is async friendly that's why of its usage.
    char str[10];
    sprintf(str, "%d", getpid());  // trick to convert a integer to string.
    write(STDOUT_FILENO, "Program PID: ", 13);
    write(STDOUT_FILENO, str, 10);
    write(STDOUT_FILENO, "\n", 1);
    for(;;){
        sleep(1);
    }
}

static void print_signals(int sig){
    char str[2];
    sprintf(str, "%d", sig);
    write(STDOUT_FILENO, "\rsignal #", 9);
    write(STDOUT_FILENO, str, 2);
    write(STDOUT_FILENO, " catched!\n", 10);
}
