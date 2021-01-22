#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

char *help[2000];
char **args;
int itr=0;
int count=0;
FILE* fp;
int cd_command(char **args);
int help_command(char **args);
int exit_command(char **args);
int ls_command(char **args);
int date_command(char** args);
int echo_command(char** args);
int history_command(char **help,char **args);
int pwd_command(char **args);
int cat_command(char **args);
int rm_command(char **args);
int mkdir_command(char **args);

char cwd[1024];

char *functions[] = {"cd","help","pwd","echo","ls","cat","date","rm","mkdir","exit"};

int (*functions_exec[]) (char **) = {&cd_command,&help_command,&pwd_command,&echo_command, 
  &ls_command,&cat_command,&date_command,&rm_command,&mkdir_command,&exit_command};


int cd_command(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "my_shell: expected required argument to \"cd\"\n");
  } 
  else if(*args[1]==126){
    char *homedir = getenv("HOME");
    chdir(homedir);
  }
  else if(*args[1]==46){
    chdir("..");
  }
  else if(*args[1]==47){
    fprintf(stderr,"my_shell: expected required argument to \"cd\"\n");
  }
  else if(*args[1]==45 && *args[2]==76){
   char *homedir = getenv("HOME");
    chdir(homedir);
  
}
else if(*args[1]==45 && *args[2]==104){
  fp = fopen("cd.txt", "r"); 
      char ch;
      while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
      }
      printf("\n");
           fclose(fp);
}
  else {
    if (chdir(args[1]) != 0) {
      perror("my_shell");
    }
  }
  return 1;
}

int echo_command(char **args){
  int g=sizeof(*args)/sizeof(char);
  if(args[1]==NULL){
    printf("No argument entered!\n");
    return 1;
  }
  if(*args[1]!=45 && *args[1]!=42){
   for(int i=1;i<g;i++){
    if(args[i]!=NULL && i==1){
      printf("%s", args[i]);
    }
    else if(args[i]!=NULL){
      printf(" %s", args[i]);
    }
  }

  printf("\n");
   
  }

  
else if(*args[1]==45){
  if(*args[2]!=92){
  for(int i=2;i<g;i++){
    if(args[i]!=NULL && i==2){
      printf("%s", args[i]);
    }
    
    else if(args[i]!=NULL){
      printf(" %s", args[i]);
    }}
  }
  else{
    char beep = '\a';
    printf("%c", beep);
    for(int i=2;i<g;i++){
    if(args[i]!=NULL && i==2 && *args[i]!=92){
      printf("%s", args[i]);
    }
    
    else if(args[i]!=NULL && *args[i]!=92){
      printf(" %s", args[i]);
    }}
     printf("\n");
  }
}

  else if(*args[1]==42){
    DIR *mydir;
    struct dirent *file;
    FILE* fp;
    mydir = opendir(".");
    while((file = readdir(mydir)) != NULL)
    {
       printf(" %s\n", file->d_name);
    }
    closedir(mydir);
    
  }

  return 1;
}

int pwd_command(char **args){
  if(args[1]==NULL){
   getcwd(cwd, sizeof(cwd));
   printf("Current working dir: %s\n", cwd);
  }

  else if(*args[1]==45 && *args[2]==104){
    printf("%s","pwd: pwd [-LP]\n");
    printf("%s","Print the name of the current working directory.\n");
    printf("%s","Options:-L  print the value of $PWD if it names the current working directory\n");
    printf("%s","printf  -P  print the physical directory, without any symbolic links\n");
    printf("%s","By default, `pwd' behaves as if `-L' were specified.\n");
    printf("%s","Exit Status:\n");
    printf("%s","Returns 0 unless an invalid option is given or the current directory cannot be read.\n");
  }
  else if(*args[2]==76){
   getcwd(cwd, sizeof(cwd));
   printf("Current working dir: %s\n", cwd);
  }
  else{
    fprintf(stderr,"Command not found\n");
  }
  return 1;
  }


int history_command(char **help,char **args){
int m=0; 
 if(args[1]==NULL && help==NULL){
  printf("Nothing to show, no command executed\n");
 }

 else if(args[1]==NULL){
   fp = fopen("his.txt", "r"); 
   char ch;
   while((ch = fgetc(fp)) != EOF){
    printf("%c", ch);
  }
  printf("\n");
  fclose(fp);
 }

 else{
  if(*args[1]==45 && *args[2]==114){
    fp = fopen("his.txt", "r");
    char ch;
    while((ch = fgetc(fp)) != EOF){
      *help[m]=ch;
      m++;
}
}

  else if(*args[1]==45 && *args[2]==99){
 
  fp = fopen("his.txt", "w"); 
  if(fp!=NULL){
    fputs("",fp);
  }
  
  fclose(fp);
  printf("Nothing to show, no command executed\n");

}

else{

  printf("Command not found\n");
}
}

return 1;
}

int help_command(char **args)
{
    if(args[1]!=NULL){
      fprintf(stderr, "help does not accept any arguments!\n");
      return 1;
    }
    else{
    int i;
    printf("The list of all commands currently available for execution in my_shell\n");
    int c=sizeof(functions) / sizeof(char *);
    for(int i=0;i<c;i++){
       printf(" %s\n", functions[i]);
    }
    printf(" %s\n","history");}
    return 1;
  

}

int exit_command(char **args)
{
  if(args[1]==NULL){
    return 0;
  }
  else if(*args[1]==45){
    printf("exit: exit [n]\n");
    printf("Exit the shell.Exits the shell with a status of N.\n");
    printf("If N is omitted, the exit status is that of the last command executed.\n");
  }

  else{
    system("clear");
    exit(*args[1]);
    return 0;
  }

  
}

int ls_command(char **args){
  
  char* arr[5];
  
  if(args[2]==NULL){
    arr[0]="ls";
    arr[1]="def";
  }
  else if(*args[2]==115){
   arr[0]="ls";
   arr[1]="s";
  }

  else if(*args[2]==82){
    arr[0]="ls";
    arr[1]="R";
  }
  
  else{
    arr[0]="ls";
    arr[1]="arb";
  }
  
  
  int pid;  
  pid = fork();     
  if ( pid < 0 ) 
  {                                 
    printf("\nFork failed\n"); 
    exit (-1); 
  } 
  else if ( pid == 0 ) 
  {   
    
    execvp("./ls",arr);
  
  } 
  else 
  {                             
  wait (NULL);              
  return 1;
  } 
}


int cat_command(char **args){
  int pid;  
  pid = fork(); 

  if ( pid < 0 ) 
  {                                 
    printf("\nFork failed\n"); 
    exit (-1); 
  } 
  else if ( pid == 0 ) 
  {    
    execvp("./cat",args); 
  } 
  else 
  {                             
  wait (NULL);              
  return 1; 
  } 
}

int date_command(char** args){
  int pid;  
  char* arr[5];
  if(args[2]==NULL){
    arr[0]="date";
    arr[1]="def";
  }

  else if(*args[2]==117){
    arr[0]="date";
    arr[1]="u";
  }
  else if(strcmp(args[2],"help")==0){
    arr[0]="date";
    arr[1]="help";
  }

  else{
    arr[0]="date";
    arr[1]="arb";
  }

  pid = fork();     
  if ( pid < 0 ) 
  {                                 
    printf("\nFork failed\n"); 
    exit (-1); 
  } 
  else if ( pid == 0 ) 
  {    

    execvp("./date",arr);
  } 
  else 
  {                             
  wait (NULL);              
  return 1; 
  } 
}

int rm_command(char **args){
  int pid;  
  pid = fork();     
  if ( pid < 0 ) 
  {                                 
    printf("\nFork failed\n"); 
    exit (-1); 
  } 
  else if ( pid == 0 ) 
  {    
    execvp("./rm",args);  
  } 
  else 
  {                             
  wait (NULL);              
  return 1; 
  } 
}

int mkdir_command(char **args){
  int pid;  
  pid = fork();

  if ( pid < 0 ) 
  {                                 
    printf("\nFork failed\n"); 
    exit (-1); 
  } 
  else if ( pid == 0 ) 
  {    
    
    execvp("./mkdir",args);  
  } 
  else 
  {                             
  wait (NULL);              
  return 1; 
  } 
}

int execute_command(char **args)
{
  int i;
  bool c=true;
  if (args[0] == NULL) {
    
    return 1;
  }
  int p=sizeof(functions) / sizeof(char *);
  for (i = 0; i < p; i++) {
    if(strcmp(args[0],"history")==0){
      return history_command(help,args);
    } 
    else if (strcmp(args[0], functions[i]) == 0) {

      return (*functions_exec[i])(args);
    }
    else{
      c=false;
    }
  }
  if(c==false){
    fprintf(stderr, "No such command found in my_shell\n");
  }
   
   return 1;
}


char* read_line(void)
{

  char *line;
  bool flag;
  size_t bufsize = 1024;
  line= (char *)malloc(bufsize* sizeof(char));
  if(line==NULL){
    fprintf(stderr,"Unable to allocate buffer");
    exit(EXIT_FAILURE);
  }

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
       flag=true;
       exit(0);  
    } 
    else  {
      fprintf(stderr,"Read line error");
      exit(1);
    }
  }
  
  
  return line;

  
}

char **parse(char *line)
{
  int bufsize = 1024;
  int i = 0;
  bool flag=true;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;
  if (tokens!=0 && flag) {
  token = strtok(line," \r\t\n\a");
  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " \r\t\n\a");
  }
}

else{
  perror("Improper Allocation");
  exit(1);
}

  tokens[i] = NULL;
  return tokens;
}


void loop(void)
{
  char *line;
  
  
  int status;
  system("clear");

  while(status) {
    
    printf("%s","harshita@root >");
    line = read_line();
    fp = fopen("his.txt", "a");
    if(line!=NULL){
     count++;
    fprintf(fp, "%d ", count);
    fprintf(fp, "%s\n", line);
    }
    args = parse(line);
    
    help[itr]=*args;
    itr++;
    status = execute_command(args);
   
  }

}
int main(int argc, char **argv)
{
  
  loop();
  system("clear");
  return 0;
}