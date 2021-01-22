#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listdir(const char *name,int i);

char* p=NULL;
char* arr[200];int i=0;
DIR *mydir;
struct dirent *file;

void listdir(const char *name,int i)
{
    DIR *dir;
    struct dirent *entry;
    char path[1000];
    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s|%s|\n", i, "", entry->d_name);
            listdir(path, i + 2);
        } else {
            printf("%*s* %s\n", i, "", entry->d_name);
        }
    }
    closedir(dir);
}


int main(char* path, char** args)

{ 
    if(strcmp(args[1],"s")==0){
      
      FILE *fp;
      mydir = opendir(".");
      while((file = readdir(mydir)) != NULL)
    {
        struct stat fi;
        stat(file->d_name, &fi);
        printf("%ld %s\n",fi.st_blocks/2,file->d_name);
       
    }
    
    closedir(mydir);
    }
    else if(strcmp(args[1],"R")==0){
      listdir(".",0);
    }

    else if(strcmp(args[1],"arb")==0){
      fprintf(stderr, "Command not found, please supply correct flag\n");
    }

  
  else{
      
      FILE *fp;
      mydir = opendir(".");
      while((file = readdir(mydir)) != NULL)
    {
       printf(" %s\n", file->d_name);
    }
    closedir(mydir);
    }
    return 0;
} 


    
