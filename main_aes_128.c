/* Main Test file for encryption
*/


#include "TI_aes_128.h"
#include <stdio.h>
#include <time.h>

int main( void )
{
  //The state is the 16-byte data
  unsigned char state[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
                               0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
  //expected cipher text
  unsigned char ciphertext[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
                              0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};

  //key for encryption
  unsigned char key[]   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                           0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

  //unsigned char key2[]   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  //                         0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};


  clock_t start = clock(), diff;

  printf("Beginning encryption of 16 byte data: ");
  int i = 0;
  for (i = 0; i < 16; ++i) {
	  printf("0x%02x ", state[i]);
  }

  aes_enc_dec(state, key, 0);

  printf("\n\n");
  printf("Expected Encrypted Message: \n");
  for (i = 0; i < 16; ++i) {
	  printf("0x%02x ", ciphertext[i]);
  }
  printf("\n\n");
  printf("Actual Encryption: \n");
  for (i = 0; i < 16; ++i) {
	  printf("0x%02x ", state[i]);
  }
  printf("\n\n");

  printf("Beginning decryption of cipher text : ");
  
  aes_enc_dec(state, key,1);
  
  printf("\n\n");

  printf("Decrypted Message: \n");
  for (i = 0; i < 16; ++i) {
	  printf("0x%02x ", state[i]);
  }

  printf("\n\n");

  diff = clock() - start;

  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Time taken %d seconds %d milliseconds", msec / 1000, msec % 1000);

  getch();
  return 0;
}

 

