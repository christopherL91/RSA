#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"

void message(char *string_number){
  mpz_t test, n;
  mpz_init(test);
  mpz_init(n);
  mpz_set_str(n,"15",10);
  mpz_set_str(test,string_number,10);
	      
  if(mpz_cmp(test,n) >=0){
    printf("%s\n","Warning,the message is to big!, please note that the message < n ");
    mpz_clear(test);
    mpz_clear(n);
    exit(EXIT_FAILURE);
  }
  else{
  mpz_t encrypt,temp,e,d,decrypt; /*Decleration of variables */
  mpz_init(temp);
  mpz_init(encrypt);
  mpz_init(e);
  mpz_init(d);
  mpz_init(decrypt);
  
  
  mpz_set_str(temp,string_number,10);
  mpz_set_str(e,"3",10);
  mpz_set_str(d,"3",10);

  mpz_powm(encrypt,temp,e,n);
  mpz_powm(decrypt,encrypt,d,n);
  printf("\n");
  printf("%s","Message: ");
  mpz_out_str(stdout,10,encrypt); /*Print out the encrypted number on the screen*/
  printf("\n");
  
  printf("%s","Decrypted message: ");
  mpz_out_str(stdout,10,decrypt);

  /*Clean up!*/

  mpz_clear(encrypt);
  mpz_clear(test);
  mpz_clear(n);
  mpz_clear(e);
  mpz_clear(d);
  mpz_clear(temp);
  mpz_clear(decrypt);
  } /* End of else block */

}
