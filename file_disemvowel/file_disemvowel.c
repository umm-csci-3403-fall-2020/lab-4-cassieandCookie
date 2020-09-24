#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c){

  if(c == 'a' || c == 'e' || c == 'i' || c== 'o' || c== 'u'|| c == 'A' || c == 'E' || c == 'I' || c== 'O' || c== 'U' ){
	  return true;
  }
  return false;
// Returns true if c is a vowel
return true;
}

int copy_non_vowel(char c){


// copy all thenon-vowels from 
// in_buf to out_buf.
// num_chars indicatees how many chars in in_buf
// //This functino should return the number of non vowels
// that were coppied over
return 1;
}

void disemvowel(FILE* inputFile, FILE* outputFile){
	 /*        * Copy all the non-vowels from inputFile to outputFile.
	  *      * Create input and output buffers, and use fread() to repeatedly read
	  *           * in a buffer of data, copy the non-vowels to the output buffer, and
	  *      * use fwrite to write that out.
	  *                     */



}

int main(int argc, char *argv[]) {
//You should set the to stdin and stdout 
//by default, and then set them to the user specified files when the 
//user provides file names as command line argumentst
//FILE *inputFile = fopen(argv[1], "r");
FILE *inputFile = stdin;
FILE *outputFile = stdout;
if(argc>2){
printf("Too many arguements supplied. \n");
}



//disemvowel(inputFile, outputFile);
return 0;

}
