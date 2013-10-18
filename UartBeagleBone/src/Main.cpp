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
#define         DEVICE_PORT             "/dev/ttyO2"                         // ttyS0 for linux
#endif
char Buffer[200];
void svuotaBuffer(){

	for (int p=0;p<200;p++)
		Buffer[p]='2';

}
int main()
{
    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values

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



    while(allarme==0){
    	printf("inizio letture\r\n");
    	Ret=LS.ReadString(Buffer,'\n',200,1000);
    	printf("Ret= %d\n",Ret);
    	// if (Ret==1||Ret==0){
    		 	 	 	 firstSample =Buffer[0] ;

    		 	 	 	//printf("primo char, %s\n",Buffer);
//    		 	 	 	 while(firstSample!=0x7E){
//    		 	 	 		 usleep(1);
//							  if (pointer_tofirst==199){
//								  //gestire
//								  trovato=false;
//								  pointer_tofirst=0;
//								  break;
//							  }
//
//							   pointer_tofirst++;
//							   firstSample=Buffer[pointer_tofirst];
//
//					}
				 //ottenuto il valoreindice primo campione buono in pointer_tofirst
					 int counter=0;
					 printf("uscito\r\n");
				//controlloo se c'è un pakketto buono
				//	 if (trovato==true){


						 //elaboro il buffer
											 while(firstSample==0x7E||counter!=7){
												 printf("parsing\r\n");

												 usleep(10000);
														 if (counter==0){

															 alarmElement=Buffer[pointer_tofirst+20];
															 printf("elemento 20esimo %c", alarmElement);
														 }

														 else{
															 printf(" elemento %d",pointer_tofirst+24*counter+20);
															 alarmElement=Buffer[pointer_tofirst+24*counter+20];
															 printf("alarm element = %c",alarmElement);
														 }

														 if (alarmElement=='x'){
															 //trovato allarme
															 printf("alarm\r\n");
															 allarme=1;
														 }
														 else {
															 //analisi dati
														 }
														 counter++;

														 //printf("pacchetto %d",counter+1);
														 firstSample=Buffer[pointer_tofirst+24*counter];
														 printf("firstSample %c", firstSample);
														 printf("\r\n");
														 printf("pointer to first  %d",pointer_tofirst);
														 printf("\r\n");




													 }

											 pointer_tofirst=0;

											 svuotaBuffer();


								//	 }


    	 //}
	     printf("flushing serial port\r\n");
    	 LS.FlushReceiver();


 	 } //end while allarme
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






	LS.Close();


    printf("lanching mail client\r\n");
    system("python /home/ubuntu/Script/./smtp.py");
    printf("finito\r\n");


    return 0;
}
