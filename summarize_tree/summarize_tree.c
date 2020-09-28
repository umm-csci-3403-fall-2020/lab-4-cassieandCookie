#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024

//variables visible to functions in this file
static int num_dirs, num_regular;

bool is_dir(const char* path) {
  struct stat statBuff;
  //char* in_buff = (char*)calloc(BUF_SIZE,sizeof(char));
  //int stat(path, statBuff);
  if (stat(path, &statBuff) !=0){
	return false;
  }
  return S_ISDIR(statBuff.st_mode);
}

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

void process_directory(const char* path) {
  // move to the correct directory 
  chdir(path);
  struct dirent *dp; 	
  DIR *dirp = opendir(".");
  // to avoid errors
  if(!dirp){
    return;
  }
  // add to number of dirs after passing error test
  num_dirs++; 
  // while directory stream has info
  while(dp = readdir(dirp) != NULL){
      // check d_name to make sure dir is not curr or parent dir
      if(strcmp(dp->d_name,"." ) != 0 && strcmp(dp->d_name, ".." ) != 0){
	  process_path(dp->d_name);
      }
  }
  // close and return user
  closedir(dirp);
  chdir("..");

}

void process_file(const char* path) {
  // updating number of regualar files
  num_regular++;
}

void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
