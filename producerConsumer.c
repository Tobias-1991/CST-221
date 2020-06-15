/* 
Zachary Gardner
Consumer Producer problem
This project proved to be extremely challenging for me.
I understand the concept of what needs to happen: Create a buffer between two processes
in such a way that they can run continuously without failing. 
 This should be done without the use of semaphores or monitors. 
I am very new to C, and my lack of experience made this project difficult.
I used the textbook and assignment instructions as much as I could
but ran out of time to get my program running.

*/



#include <stdio.h>
#include <pthread.h>
#define N 4
int count = 0;
int theProduct;
// Declare global variables

//producer function checks for count, if 4, producer going to sleep and signals consumer to wake up
//if count is below 4, producer adds 1 to the count. 
void producer() {

	int i;

	while(1) {
		
		i  = produce();
		if (count == N) sleep();
		puts(i); 
		count = count +1;
		if(count == 1) wakeup(consumer);
		
	}
}
// Consumer checks count for it's value, if 0 consumer falls asleep and directs producer to start.
// if >= 1 consumer will consume and count down on the counter.
void consumer() {
	int i;
	while(1) {
		if(count ==0) sleep();
		i = gets();
		count = count - 1;
		if(count == N - 1) wakeup(producer);
		consume(i);
	}
}
// This function was found in the   textbook but I don't understand it's use at this time.
int produce() {

	theProduct++;

	return theProduct;
}

void consume(int i) {
	printf("%i", i);


void main() {

	pthread_t threadOne;
	
	pthread_create(&threadOne, NULL, producer, NULL);
	
	consumer();
	producer();
	
}
}
