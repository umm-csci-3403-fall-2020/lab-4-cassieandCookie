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

#define MAX_TFW_DEPTH 16

int main(int argc, char** argv){
  //check arguements and set things up 

  ftw(argv[1], callback, MAX_FTW_DEPTH);

  // Prit out the results  
}
