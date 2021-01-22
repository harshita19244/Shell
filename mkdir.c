
#include <sys/types.h> 
#include <sys/stat.h> 
#include <string.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

char* token=NULL;
FILE* fp;
char sum[40]="";
int main(char* path,char** args) 
{   
    
    if(args[1]==NULL){
      printf("mkdir: missing operand\n");
      return 0;
    }

    else if(strcmp(args[1],"-")==0){
    if(strcmp(args[2],"v")==0){
      printf("mkdir: created directory\n"); 
      mkdir(args[3],0777); 
    }
    else if(strcmp(args[2],"help")==0){
      fp = fopen("mkdir.txt", "r"); 
      char ch;
      while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
      }
      printf("\n");
           fclose(fp);
      }
      
      
    
    else{
      printf("Command not found, please enter valid command\n");
    }
    
   } 
    else if(strcmp(args[1],"-")!=0){
      if(strcmp(args[3],"")!=0 && args[4]==NULL){
      for(int i=1;i<4;i++){
        
        if(args[i]!=NULL){
          size_t length = strlen(args[i]);
          args[i][length] = ' '; 
          args[i][length+1] = '\0'; 
          strcat(sum, args[i]);
        }
      }
}
      else if(strcmp(args[5],"")!=0){
        for(int i=1;i<7;i++){
        
        if(args[i]!=NULL){
          size_t length = strlen(args[i]);
          args[i][length] = ' '; 
          args[i][length+1] = '\0'; 
          strcat(sum, args[i]);
        }
      }
      }
      
      mkdir(sum,0777);
    }
    return 0;
 }

