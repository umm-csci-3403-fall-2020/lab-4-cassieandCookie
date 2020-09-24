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
  for(int i = 0; i< num_char; i++){
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
  
  //free(in_buff);
  //free(out_buff);
    }
  fclose(inputFile);
  fclose(outputFile);
  
}

int main(int argc, char *argv[]) {
//You should set the to stdin and stdout 
//by default, and then set them to the user specified files when the 
//user provides file names as command line argumentst
//FILE *inputFile = fopen(argv[1], "r");
FILE *inputFile = stdin;
FILE *outputFile = stdout;

disemvowel(inputFile, outputFile);
return 0;

}
