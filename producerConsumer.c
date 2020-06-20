/*
Zachary Gardner
CST-221
producerConsumer project

In this assignment we are to manage
processes and threads as they are
produced and then consumed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int theProduct;

#define bufferSize 4

//The produce() function creates a thread that fills the buffer with numbers.
int produce() {
	theProduct++;
	printf("Produced: %i\n", theProduct);
	return theProduct;
}
//The consume() function creates a thread that consumes numbers from the buffer.
int consume(){
    theProduct--;
	printf("Consumed: %i\n", theProduct);
	return theProduct;
}
//The producer function uses an infinite while loop to generate numbers from the
//produce and put functions.
void *producer() {
	int i;
	while(1) {
		i = produce();
            put(i);
    if(theProduct == bufferSize) {
        sleep(i);
    }
    else {
        produce();

    }
	}
}
// the consumer() function uses the consume and get functions
//to "consume" numbers from the buffer.
int *consumer() {
	int i;
	while(1) {
		i = consume();
		get(i);
    if (theProduct == 0) {
        sleep(i);
    } else {
        consume();
    }
	}
}
// If there is room in the buffer for more numbers,
//the put() function will insert numbers until
//the buffer is filled.  It will then wake the consume function.
void put(int i) {
    if(theProduct == bufferSize) {
        sleep(i);
    } else {
        produce(i);
    }
}
// the wake() function(when working) will wake the consumer when the buffer is filled,
//And wake the producer when the buffer is empty.
void wake() {
}
int get(int i) {
    if(theProduct == 0) {


        sleep(i);
    } else {
        consume(i);
}
}
//Here we have the main function.  This is where we run all of our code.
//With the current build, producer will produce 4 numbers, it will then pause for about 10 seconds,
//It will then continue producing indefinitely.
//As for the consumer function, it will only consume if the producer function is not running.
int main() {
    /*For some reason the producer function will produce on it's own, and with the consumer function.
    However, the consumer function will not run unless it is by itself.*/

    consumer();

}






