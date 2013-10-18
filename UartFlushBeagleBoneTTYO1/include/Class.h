//============================================================================
// Name        : ClassExample.cpp
// Author      : nic
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class programming
{
   private:
      int variable;

   public:

      void input_value()
      {
         cout << "In function input_value, Enter an integer\n";
         cin >> variable;
      }

      void output_value()
      {
         cout << "Variable entered is ";
         cout << variable << "\n";
      }
      void stampa_messaggio(char * string){
    	  cout << string<<"\n";
      }

};

