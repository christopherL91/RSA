#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
void check_of_message(char *checkptr){

	while(*checkptr != '\0') {

    if (isdigit(*checkptr) || isspace(*checkptr) ) {
      checkptr++;
       }
    else {
	raise(SIGABRT);
    }
  } /*End of while-loop*/


} /*End of function*/
