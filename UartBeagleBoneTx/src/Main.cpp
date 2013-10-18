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
void Sleep(float s)
{
    int sec = int(s*1000000);
    usleep(sec);
}

int main()
{
    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
    char Buffer[24];

    // Open serial port

    Ret=LS.Open(DEVICE_PORT,9600);                                        // Open serial link at 115200 bauds
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");
    char choice;
    // Write the AT command on the serial port
     // while(1){
    	//   usleep(2);
//    	   printf ("scegli opzione:\r\n");
//    	   printf("1--3 packets with alarm\r\n");
//    	   printf("2--3 packets no alarmr\r\n");
//    	   printf("3--2,5 packets  alarm \r\n");
//    	   printf("4--2,5 packets no alarm\r\n");
//    	   scanf("%c",&choice);
//
//    	   switch((int)choice){
//
//    	   case 1:
//    		   Ret=LS.WriteString("~22222222222222222221222~22222222222222222221222~22222222222222222221222");
//    		   break;
//
//    	   case 2:
//    		   Ret=LS.WriteString("~22222222222222222222222~22222222222222222222222~22222222222222222222222");
//    		   break;
//
//    	   case 3:
//    		   Ret=LS.WriteString("~22222222222222222221222~22222222222222222221222~222222222");
//    		   break;
//    	   case 4:
//    		   Ret=LS.WriteString("~22222222222222222222222~22222222222222222222222~222222222");
//    		   break;
//    	   case default:
//
//    		   Ret=LS.WriteString("~22222222222222222221222~22222222222222222221222~22222222222222222221222");
//    		       		   break;
//
//
//    	   }
//    Ret=LS.WriteString("~22222222222222222221222~22222222222222222221222~22222222222222222221222");





   //   }


//    Ret=LS.WriteString("AT\n");                                             // Send the command on the serial port
//    if (Ret!=1) {                                                           // If the writting operation failed ...
//        printf ("Error while writing data\n");                              // ... display a message ...
//        return Ret;                                                         // ... quit the application.
//    }
//    printf ("Write operation is successful \n");

    // Read a string from the serial device

    //Ret=LS.ReadString(Buffer,1,15000);
    //Ret=LS.ReadChar(Buffer,10000);

    // Read a maximum of 128 characters with a timeout of 5 seconds
                                                                        // The final character of the string must be a line feed ('\n')
   /* if (Ret>0)                                                              // If a string has been read from, print the string
        printf ("String read from serial port : %s",Buffer);
    else
        printf ("TimeOut reached. No data received !\n");                   // If not, print a message.
*/
    // Close the connection with the device
    Ret=LS.WriteString("~22222222222222222221222~22222222222222222221222~2222222222222222222x222");
    Sleep(5);
    if (Ret!=1) {                                                           // If the writting operation failed ...
           printf ("Error while writing data\n");                              // ... display a message ...
            return Ret;                                                         // ... quit the application.
        }
    else{
    	printf("ok");
    }
    LS.Close();

    return 0;
}

