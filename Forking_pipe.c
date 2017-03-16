//MOSTAFA OKASHA ---- 
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>
#include  <sys/types.h>
//  Parent: reads from P1_READ, writes on P1_WRITE
//  Child:  reads from P2_READ, writes on P2_WRITE
#define PREAD     0
#define CWRITE    1
#define CREAD     2
#define PWRITE    3
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
int  main(void){

    int fd1[2];                // Creates an array to be used as 1 way pipe
    int fd2[2];                // Creates an array to be used as another 1 way pipe
    int inp[1];               // single character array
    char temp[1];
    char out[500];

    //x and y used to check if pipes have been previously closed or not
    int x = 0; //for child
    int y = 0;  // for parent

    int total = 0; //this number is gonna be the output
    int send = 0;
    int i = 0;  //for continuous while loop until user enters -1

    pid_t    pid;                  // PID type to check ID of processes
    pipe(fd1);                     // Create a pipe descriptor CHILD TO PARENT
    pipe(fd2);                     // create a second descriptor PARENT TO CHILD

//forking happens here
if(( pid = fork()) < 0){    //if failure to produce child occurs error is given
    perror("fork");
exit (0);
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
while(i == 0){

if(pid  == 0){ //This is the child process now


    close(fd1[0]);
    close(fd2[1]);
    printf("Enter a 1-byte integer: ");
    scanf("%d",&inp[x]);
    temp[x] = inp[x];
    write(fd1[1], &temp[x], 1);

    if (inp[x] == -1){
        read(fd2[0], &send, 1);
        printf("Child: The sum is: %d \n", send);
        i = 10;
}

}
else{
    close(fd1[1]);
    close(fd2[0]);
    read(fd1[0], &out[y], 1);
    if (out[y] == -1){
        for (int j = 0; j < y; j++){
            total = total + out[j];
}
        write(fd2[1], &total, 1);
        //i = 10;
}

    y = y + 1;
    
}
}
//While loop terminates and program returns to this point 


exit (0);
} //END MAIN
