
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
FILE* fp;
int main (char* path, char** args) {
   
  if(strcmp(args[1],"def")==0){
   struct tm *info;
   time_t rawtime;

   time( &rawtime );
   info = localtime( &rawtime );
   printf("%s", asctime(info));
   }

   else if(strcmp(args[1],"u")==0){
   time_t rawtime;
   struct tm *info;

   time(&rawtime);
  
   info = gmtime(&rawtime );
   printf("%s", asctime(info));
   }

   else if(strcmp(args[1],"help")==0){
    fp = fopen("date.txt", "r"); 
    char ch;
    while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
   }

   else{
     printf("Command not found\n");
  }
   return(0);
}


