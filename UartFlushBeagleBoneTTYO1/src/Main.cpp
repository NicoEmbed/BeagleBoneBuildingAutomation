/*
 * Main.c
 *
 *  Created on: Oct 15, 2013
 *      Author: ubuntu
 */


#include <stdio.h>
#include "serialib.h"


#if defined (_WIN32) || defined( _WIN64)
#define         DEVICE_PORT             "COM1"                               // COM1 for windows
#endif

#ifdef __linux__
#define         DEVICE_PORT             "/dev/ttyO1"                         // ttyS0 for linux
#endif


int main()
{
    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
    char Buffer[200];
    //char string[96];
    // Open serial port
    int allarme=0;
       int counter=0;
       int point=0;
       char firstSample;
       int pointer_tofirst=0;
       bool trovato=true;
       char alarmElement;
    Ret=LS.Open(DEVICE_PORT,9600);                                        // Open serial link at 115200 bauds
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");




    		 	 	 	//printf("primo char, %s\n",Buffer);
//    		 	 	 	 while(firstSample!=0x7E){
//    		 	 	 		 usleep(1);
//							  if (pointer_tofirst==199){
//								  //gestire
//		 //end while allarme
//    while(allarme==0){
//        	printf("inizio letture\r\n");
//        	Ret=LS.ReadString(Buffer,'\n',200,1000);
//        	printf("ret= %d",Ret);
//        	printf(Buffer);
//        	if (Ret==1||Ret==0){
//        	    		 	 	 	 firstSample =Buffer[0] ;
//        	    		 	 	 	 printf("car ric %c\r\n",&firstSample);
//
//        	    		 	 	 	 while(firstSample!=0x7E){
//        	    		 	 	 		 usleep(1);
//        								  if (pointer_tofirst==199){
//        									  //gestire
//        									  trovato=false;
//        									  pointer_tofirst=0;
//        									  break;
//        								  }
//
//        								   pointer_tofirst++;
//        								   firstSample=Buffer[pointer_tofirst];
//
//        						}
//
//        	    if (trovato){
//
//        	    	printf("car ric %c\r\n",&firstSample);
//
//        	    }
//        	}
//        	 LS.FlushReceiver();
//    }



    LS.FlushReceiver();


	LS.Close();


    //printf("lanching mail client\r\n");
   // system("python /home/ubuntu/Script/./smtp.py");
    printf("finito\r\n");


    return 0;
}
