#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <unistd.h>

//////////////////////////////Signal handler for Alarm/////////////////////////////////////
void  alarm_handler(int  siga){
if (siga  ==  SIGALRM){
printf ("Alarm\n");
}
}
//////////////////////////////Signal handler for Interrupt/////////////////////////////////

void  interrupt_handler(int  sigb){
if (sigb  ==  SIGINT){
printf ("CTRL+C pressed!\n");
}
}
//////////////////////////////Signal handler for Terminal Stop/////////////////////////////

void  termstop_handler(int  sigc){
if (sigc  ==  SIGTSTP){
printf ("CTRL+Z pressed!\n");
exit(1);
}
}
/////////////////////////////////////////// MAIN //////////////////////////////////////////
int  main(void){
//  Register  the  signal  handler for SIGALRM, SIGINT and SIGTSTP AND
// Checks for Errors in the registry of the handlers to the significant signals////////////
if (signal(SIGALRM , alarm_handler) ==  SIG_ERR){
printf (" Failed to register Alarm handler. ");
exit (1);
}
if (signal(SIGINT , interrupt_handler) ==  SIG_ERR){
printf (" Failed to register interrupt handler. ");
exit (1);
}
if (signal(SIGTSTP , termstop_handler) ==  SIG_ERR){
printf (" Failed to register Terminal Stop handler. ");
exit (1);
}
///////////////////////////////////////////////////////////////////////////////////////////
while (1){
alarm (2);                 // set  alarm  to fire in 2 seconds.
sleep(2);
}
}

