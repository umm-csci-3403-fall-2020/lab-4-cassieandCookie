#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define BUF_SIZE 1024

bool is_vowel(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c== 'o' || c== 'u'|| c == 'A' || c == 'E' || c == 'I' || c== 'O' || c== 'U' ){
	  return true;
  }
  return false;
}

int copy_non_vowel(int num_char, char* in_buff, char* out_buff){
int index =0;
  for(int i = 0; i< num_char-1; i++){
     if( is_vowel(in_buff[i]) == false ){
	out_buff[index] = in_buff[i];
	index++;
     }   
  }  
return index;
}

void disemvowel(FILE* inputFile, FILE* outputFile){
 
  char* in_buff = (char*)calloc(BUF_SIZE, sizeof(char));
  char* out_buff = (char*)calloc(BUF_SIZE, sizeof(char));
  
    while(true){

  
    int num_chars = 0; 
    num_chars = (int)fread(in_buff, sizeof(char), BUF_SIZE, inputFile);
    if(num_chars == 0){
      break;
    }    
    int non_vowels = copy_non_vowel(num_chars, in_buff, out_buff);
    fwrite(out_buff, sizeof(char), non_vowels, outputFile);

    //fwrite(1,2,3,4)
    //1 = pointer to array of elements to be written
    //2 = size of each element to be written
    //3 = number of elements (size in bytes)
    //4 = pointer to a FILE object specifying an output stream

    //fread(1,2,3,4)
    //1 = pointer to a block of memory
    //2 = size of each element to be read
    //3 = number of elements (size in bytes)
    //4 = pointer to a FILE object specifying input stream
  
    }
  free(in_buff);
  free(out_buff);
  fclose(inputFile);
  fclose(outputFile);
  
}

int main(int argc, char *argv[]) {
//You should set the to stdin and stdout 
//by default, and then set them to the user specified files when the 
//user provides file names as command line argumentst
//FILE *inputFile = fopen(argv[1], "r");
FILE *inputFile; 
FILE *outputFile;
// argv[0] is the name of the program
if(argc == 1){
  inputFile = stdin;
  outputFile = stdout; 
}
else if( argc == 2 ){
  inputFile = fopen(argv[1], "r");
  outputFile = stdout;
}
else if(argc == 3){
  inputFile = fopen(argv[1], "r"); 	
  outputFile = fopen(argv[2], "w");
}
// exit if too many command line arguments are given
else{
 printf("too many arguements.  I dead");
  exit(0);
}

disemvowel(inputFile, outputFile);
return 0;

}
