#include<ftw.h>
#include<stdio.h>
#include<stdlib.h>

static int num_dirs, num_regular;
static int callback(const char *fpath, const struct stat*sb, int typeflag){
  if(typeflag == FTW_D){
	num_dirs++;
  }	
  if(typeflag == FTW_F){
  	num_regular++;
  }
  // if typeflag is not a file or a dir, we dont want to count it
  return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv){
  //check arguements and set things up 
  if(argc != 2){
    printf("need two arguements");
    exit(0);
  }
  num_dirs = 0; 
  num_regular =0; 
  ftw(argv[1], callback, MAX_FTW_DEPTH);
  printf("number of dirs : %d" , num_dirs);
  printf("number of files : %d", num_regular);

  return 0;
}
