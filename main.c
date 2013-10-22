/* Copyright (C) 2013 Christopher
 * This file is part of RSA.
 *
 * RSA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RSA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RSA.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Author: Christopher Lillthors.
   Purpose: Create RSA encryption/decryption
   Date: 26/7-13 (Redesigned)
   Usage: echo "message" | RSA, output will be either a textfile or a message printed out on the terminal
   Language: ANSI C (old school)
   Executable RSA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"
#include "check_of_message.h"
#include "message.h"
#define BUFFER_SIZE 100000

void terminate (int param) {
	printf("Illegal characters in input file\nPlease remove those before trying again\n");
	exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {

    /*Declare variables*/
  int ch, i;
  char message_buffer[BUFFER_SIZE];
  char *message_buffer_ptr;
  char encrypt_buffer[BUFFER_SIZE];
/* Get input from user using pipe
  fgets(message_buffer,BUFFER_SIZE,stdin); */

  signal(SIGABRT,terminate); /*Error handling*/

  ch = getchar();

  for (i = 0; ch != EOF; i++) {
    if (ch != EOF) {
      if (ch == '\n' || ch == '\r')
        message_buffer[i] = ' ';
      else
        message_buffer[i] = (char)ch;
    }

    ch = getchar();
  }

  check_of_message(message_buffer); /*call function to check the message*/

  /*Split the message into pieces*/
  
  message_buffer_ptr = strtok(message_buffer," ");
  
  while (message_buffer_ptr != NULL){
    message(message_buffer_ptr);
    message_buffer_ptr = strtok(NULL , " ");
   }
  
  /*Print out the message from the user*/
  /*fprintf(stdout,message_buffer,"%s"); */
  
  printf("\n");
  return (EXIT_SUCCESS);
} /*End of main() */
