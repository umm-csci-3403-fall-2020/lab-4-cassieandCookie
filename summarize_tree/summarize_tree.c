#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

//variables visible to functions in this file
static int num_dirs, num_regular;

bool is_dir(const char* path) {
  struct stat *statBuff;
  statBuff = malloc(sizeof(struct stat));
  if (stat(path, statBuff) !=0){ //stat() returns an int
	// there was an error, if the file doesn't actually exist
	return false;
  }
  if(S_ISDIR(statBuff->st_mode)){ //Determining if a something is a directory or not
    free(statBuff);
    return true;
  }
  else{
    free(statBuff); 	  
    return false;
  }
   
}


void process_path(const char*);

void process_directory(const char* path) { //checks the directory in a path, increments it and checks to see if more directories within that path need to be processed
  // move to the correct directory 
  chdir(path);
  struct dirent *dp; //dirent is another type of struct	
  DIR *dirp = opendir("."); //opening the current directory that we're in
  // to avoid errors, if directory is nonexistent
  if(!dirp){
    return;
  }
  // add to number of dirs after passing error test
  num_dirs++; 
  // while directory stream has info
  while((dp = readdir(dirp)) != NULL){ //looking if there is anything left to read in the directory 
      // check d_name to make sure dir is not curr or parent dir
      if(strcmp(dp->d_name,"." ) != 0 && strcmp(dp->d_name, ".." ) != 0){ //returns 0 if they're the same, strcmp is similar to a compareTo method
	  process_path(dp->d_name);
      }
  }
  // close and return user
  closedir(dirp);
  chdir(".."); //have to out of path you're looking at

}

void process_file(const char* path) {
  // updating number of regualar files
  num_regular++;
}

void process_path(const char* path) { //checks to see if path is a file or a directory which determines whether or not it needs to be processed
  if (is_dir(path)) {
    process_directory(path); //if the path is a directory, recurively opening it up and seeing if there are more files/directories inside
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
