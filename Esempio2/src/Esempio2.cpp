//============================================================================
// Name        : Esempio2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <unistd>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
		FILE *LEDHandle = NULL;
	  char *LEDBrightness = "/sys/class/leds/beaglebone:green:usr0/brightness";
	  printf("\nStarting simple LED blink program\n");


	  for (int i=0; i<10 ;i++) {
	  if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
	  	      fwrite("1", sizeof(char), 1, LEDHandle);
	  	      fclose(LEDHandle);
	  	   // printf("\nfine simple LED blink program\n");
	  }

	  	    sleep(2);
	  	    //while(1){
//
	    if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
	      fwrite("0", sizeof(char), 1, LEDHandle);
	      fclose(LEDHandle);
	    }
		 sleep(2);
	  }
//
//	    if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
//	      fwrite("0", sizeof(char), 1, LEDHandle);
//	      fclose(LEDHandle);
//	    }
//
//	    sleep(10);
//	  }
	  return 0;
}



