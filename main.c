#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
// Store Login Information
struct Account{
    char name[40];
    char email[40];
    char username[40];
    char password[10]; 
    char status[10];
   };

// Function For Taking Email and Generate Username
char getUsername(char email[40],char username[40]){
int j;
for(j = 0; j<strlen(email); j++){
if(email[j] == '@') username[j] = 0;
else username[j] = email[j];
}
}
int main(){
struct Account acc;
int option; 
int attherate = false;
bool symbolpresent = false;
bool passwordlength = false;
char password[20];
char pass[20] , user[20];
bool userfound = false;
int code;
int i;
FILE *sc;
// Change Color Of Command Line Interface
 system("COLOR 5F");

 printf("\n\n\n\n\t\t\t\t\t\t\" Pharmacy Management System \"");
 printf("\n\n\t\t\t\t\t   --- Welcome To Authentication System ---");
 printf("\n\nEnter Your Operation:");
 printf("\n1:Signup");
 printf("\n2:Login");
 printf("\n3:Exit");
 // Enter the Choice
 printf("\n\nYour choice:\t");
 scanf("%d",&option);
 fgetc(stdin);
 switch(option){
     case 1:
     // Get The Name Of User
     printf("\nEnter Your Name:\t");
     fgets(acc.name,40,stdin);
     acc.name[strlen(acc.name) - 1] = 0;
    // Get The email
    do{
     printf("\nEnter Your Email:\t");
     fgets(acc.email,40,stdin);
     acc.email[strlen(acc.email) - 1] = 0;
     for(i = 0; i < strlen(acc.email); i++){
     // Check Email Contain @:
     if(acc.email[i] == '@'){
     attherate =  true;
     system("COLOR 5F");
     break;
     }
     }
    if(attherate == false){
         printf("Email Must Include @ ");
         system("COLOR 4f");
         Beep(750,200);
     }
     }while(attherate != true );
    // Get The Password:
    do{
    printf("\nEnter Your Password:\t");
    fgets(acc.password,40,stdin);
    // Remove The trailing zero from the string
    acc.password[strlen(acc.password) - 1] = 0;
    // Check the Password contain Symbol and Digit
    for (i = 0; i < strlen(acc.password); i++){
    if(acc.password[i] == '!' || acc.password[i] == '@' || acc.password[i] == '#' || acc.password[i] == '$'
    || acc.password[i] == '%' || acc.password[i] == '^' || acc.password[i] == '&' || acc.password[i] == '*'){
        symbolpresent = true;
        system("COLOR 5F");
    }
    }
    // Check the Password Length Greater Than 8
    if((strlen(acc.password)) >= 8){
        passwordlength = true;
    }
    if(symbolpresent == false){
    printf("\nPassword must contain Atleast-One-Symbol.");
    system("COLOR 4f");
    Beep(750,200);
    }
    if(passwordlength == false){
    printf("\nPassword must contain atleast 9 character.");
    system("COLOR 4f");
    Beep(750,500);}
    }while((symbolpresent != true) || (passwordlength != true));
    // Confirm Password
    do{
    printf("\nConfirm Your Password:\t");
    fgets(password,20,stdin);
    password[strlen(password) - 1] = 0;
    if (!strcmp(acc.password,password)){
    system("COLOR 5f");
    printf("\nYour Password Matched Successfully\n.");
    getUsername(acc.email,acc.username);
    }else{
    system("COLOR 4f");
    printf("\nYour password don't Matched.\n");
    }}while(strcmp(acc.password,password));
    // Check the code provided to everyone to set STATUS
    printf("\nEnter Code For STATUS:\t");
    scanf("%d",&code);
    if(code == 455){
    strcpy(acc.status,"Admin");
    }else if (code == 460){
    strcpy(acc.status,"Employee");
    }else if( code == 465){
    strcpy(acc.status,"Customer");
    }
    sc = fopen("Users\\Users.txt","a+");
    fwrite(&acc,sizeof(acc),1,sc);
    fclose(sc);
    // Your Profile
    printf("Your profile has been successfully created.");
    printf("\n\n\t\t\t\t\t                    --- Your Profile ---       ");
    printf("\n\n Name: %s",acc.name);
    printf("\n Email: %s",acc.email);
    printf("\n Status: %s",acc.status);
    printf("\n Username: %s",acc.username);
    break;
    case 2:
    printf("Enter Your Username: ");
    fgets(user,40,stdin);
    user[strlen(user) - 1] = 0;
    printf("Enter Your Password: ");
    fgets(pass,40,stdin);
    pass[strlen(pass) - 1] = 0;
    // Check Username and Password
    sc =  fopen("Users\\Users.txt","r");
    while(fread(&acc,sizeof(acc),1,sc)){
         if(!strcmp(acc.username,user)){
             if(!strcmp(acc.password,pass)){
            printf("---------------------   Welcome To Your Profile   --------------------- ");
            printf("\n\nWelcome %s",acc.name);
             userfound = true;
             break;
             }
         }else{
             printf("INVALID PASSWARD");
         }
        if(userfound == false){
          printf("User Is Not found");
        }
    }
    fclose(sc);
    break;
    case 3:
    return 1;
    break;
   }


 return 0;
 }

