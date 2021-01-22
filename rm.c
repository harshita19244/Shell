#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h>
  
int main(char* path,char **argv) 
{ 
   
   if(argv[1]==NULL){
      printf("Provide file or directory to remove\n");
      return 0;
   }
   else if(argv[2]==NULL){
   	if (remove(argv[1]) == 0) {
      printf("Deleted successfully\n"); 
      return 0;
   }
   else{
      printf("File or directory specified does not exist\n");
      return 0; 
   }
   }
   else if(strcmp(argv[2],"i")==0){
   	char str[20];
   	printf("rm: remove regular file %s?",argv[3]);
   	scanf("%[^\n]%*c",str);
   	if(strcmp(str,"y")==0){
   		remove(argv[3]);
   	}

   	else{
         
   		return 0;
   	}
   }
   else if(strcmp(argv[2],"d")==0){
   	 int status;
   	 status=rmdir(argv[3]);
       if(status!=0){
         printf("Specified directory does not exist\n");
       }

   }
   
   
  
   return 0; 
} 