#include <stdio.h>
#include <stdbool.h>

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
  fp = fopen(inputFile, "r");

  char* in_buff = (char*)calloc(BUFF_SIZE, sizeof(char));
  char* out_buff = (char*)calloc(BUFF_SIZE, sizeof(char));
  

  while(true){ 
    num_chars = (int)fread(in_buff, sizeof(char), BUFF_SIZE, inputFile);
    if(num_chars<0){
      break;
    }    
    int non-vowels = copy_non_vowels(num_chars, in_buff


  }


  if(fp == NULL){
    printf("Error opening file\n");
	exit(1);    
  }
  while(fread(&inputFile, sizeof(char),


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
printf("%d", copy_non_vowel(6,inputFile, outputFile));



//disemvowel(inputFile, outputFile);
return 0;

}
