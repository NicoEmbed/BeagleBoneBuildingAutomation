//============================================================================
// Name        : ClassExample.cpp
// Author      : nic
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Class.h"
#include <cstdlib>
#include <pthread.h>

#define NUM_THREADS     5
using namespace std;
void *PrintHello(void *threadid);




int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	 programming object;




	   object.input_value();
	   object.output_value();
	   object.stampa_messaggio("inizio thread esec");
	   pthread_t threads[NUM_THREADS];
	   int rc;
	   for( int i=0; i < NUM_THREADS; i++ ){
	         cout << "main() : creating thread, " << i << endl;
	         rc=pthread_create(&threads[i],NULL,PrintHello,(void*)i);

	         if (rc){
	            cout << "Error:unable to create thread," << rc << endl;
	            exit(-1);
	         }
	      }
	      pthread_exit(NULL);

	return 0;
}

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}
