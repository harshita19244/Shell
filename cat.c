#include<stdio.h>
#include<string.h>

int main(char* path,char **argv)
{
              //printf("%s\n",argv[2]);
               FILE *file;
               char line[10000];

               if(argv[1]==NULL){
                 printf("Enter a file to read\n");
                 return 0;
               }

               else if(strcmp(argv[1],"-")!=0 && strcmp(argv[1],"")!=0){
               file = fopen(argv[1],"r");
               if(file==NULL){
                printf("cat: No such file or directory\n");
                return 0;
               }
               while(fscanf(file,"%[^\n]\n",line)!=EOF)
               {
                  printf("     %s\n", line);
               }
              }

              
                
              else if(strcmp(argv[2],"n")!=0 && strcmp(argv[2],"E")!=0){
                printf("Enter valid flag\n");
                return 0;
               }

              else if(strcmp(argv[2],"n")==0 || strcmp(argv[2],"E")==0){
               if(strcmp(argv[2],"n")==0){
               int count=0;
               file = fopen(argv[3],"r");
               if(file==NULL){
                printf("cat: No such file or directory\n");
                return 0;
               }
               while(fscanf(file,"%[^\n]\n",line)!=EOF)
               {
                  count++;
                  printf("      %d    %s\n", count,line);
               }
               }
               else if(strcmp(argv[2],"E")==0){
                file = fopen(argv[3],"r");
                if(file==NULL){
                printf("cat: No such file or directory\n");
                return 0;
               }
                while(fscanf(file,"%[^\n]\n",line)!=EOF)
               {
                  
                  printf("     %s", line);
                  printf("%s\n","$");
               }
               }
             }
               
               
            

               fclose(file);
               return 0;
}