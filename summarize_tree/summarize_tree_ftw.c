#include<ftw.h>
#include<stdio.h>
#include<stdlib.h>

static int num_dirs, num_regular;
static int callback(const char *fpath, const struct stat*sb, int typeflag){
  if(typeflag == FTW_D){ //Directory has a number, and if typeflag equals that number, it means that file is a directory, increment directory
	num_dirs++;
  }	
  if(typeflag == FTW_F){ //Directory has a number, and if typeflag equals that number, it means that file is a file, increment directory 
  	num_regular++;
  }
  // if typeflag is not a file or a dir, we dont want to count it
  return 0; //0 return value signifies that nothing went wrong
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv){
  //check arguements and set things up 
  if(argc != 2){ //argc is the number of arguments passed into the command line
    printf("need two arguements");
    exit(1);
  }
  num_dirs = 0; //reinitializing variables 
  num_regular =0; 
  ftw(argv[1], callback, MAX_FTW_DEPTH); //ftw is what "walks" through the file, going 16 directories deep based on MAX_FTW_DEPTH
  printf("There were %d directories.\n" , num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
