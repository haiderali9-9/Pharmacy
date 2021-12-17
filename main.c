
 #include<stdio.h>
 #include<string.h>
 #include<windows.h>
 #include<stdbool.h>
 #include<stdlib.h>


 typedef struct Account{
 char name[50];
 char email[50];
 char username[50];
 char pass_word[50];
 char status[50];
 char salary[50];
 }LoginManagement;
  

 typedef struct supplier{
 char name[50];
 char mobilenumber[50];
 char email[50];
 char medicinesupplied[50];
 int quantitysupplied;
 }SupplierManagement;
 
 
 typedef struct medicine{
 char name[50];
 char companyname[50];
 char Mfg_Date[50];
 char Exp_Date[50];
 int cabnitno;
 int quantity;
 int cost;
 }MedicineManagement;
 
 LoginManagement acc;
 MedicineManagement med;
 SupplierManagement sup;

// input function
 void input(char ch[50]){
 fgets(ch,50,stdin);
 ch[strlen(ch)-1] = '\0';
 }
 
// Add Medicine Function
 void addmedicine(){
 system("cls");
 printf("Enter Medicine Name:");
 input(med.name);
 printf("Enter Company Name");
 input(med.companyname);
 printf("Enter MFG_Date");
 input(med.Mfg_Date);
 printf("Enter EXP_Date:");
 input(med.Exp_Date);
 printf("Enter cabinet number:");
 scanf("%d",&med.cabnitno);
 printf("Enter Quantity Per Pack:");
 scanf("%d",&med.quantity);
 printf("Enter Cost Per Pack:");
 scanf("%d",&med.cost);
 fflush(stdin);
 }

// Add Supplier Function
 void addsupplier(){
 system("cls");
 printf("Enter Supplier Name:");
 input(sup.name);
 printf("Enter Supplier Phone Number:");
 input(sup.mobilenumber);
 printf("Enter Supplier Email:");
 input(sup.email);
 printf("Enter Supplier MedicineSupplied:");
 input(sup.medicinesupplied);
 printf("Enter Supplier MedcicineSupplied Quantity:");
 scanf("%d",&sup.quantitysupplied);
 fflush(stdin);	
 }

// Get password
 void getpassword(char pass_[50]){
 int k;
 int counter = 0;
 char character;
 while(1){
 character = getch();
 if( character == '\r'){
 pass_[counter] == '\0';
 break;
 }else if( character == '\b'){
 if(counter > 0){
 printf("\b \b");
 counter--;
 }}else{
 pass_[counter] = character;
 printf("*");
 counter++;
 }}}
 
// Generate Username function
 char getUsername(char email[50],char username[50]){
 int j;
 for(j = 0; j<=strlen(email); j++){
 if(email[j] == '@'){
 username[j] = '\0';
 break;
 } else {
 username[j] = email[j];
 }}}
 
 // Add login information function
 void username(){
 int attherate = false;
 bool symbolpresent = false;
 bool passwordlength = false;
 char passwod[50];
 int  code;
 int i;
 printf("\nEnter Your Name:\t");
 input(acc.name);
 do{
 printf("\nEnter Your Email:\t");
 input(acc.email);
 for(i = 0; i < strlen(acc.email); i++){
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
 do{
 printf("\nEnter Your Password:\t");
 getpassword(acc.pass_word);
 // check symoblepresent
 for (i = 0; i < strlen(acc.pass_word); i++){
 if(acc.pass_word[i] == '!' || acc.pass_word[i] == '@' || acc.pass_word[i] == '#' || acc.pass_word[i] == '$'
 || acc.pass_word[i] == '%' || acc.pass_word[i] == '^' || acc.pass_word[i] == '&' || acc.pass_word[i] == '*'){
     symbolpresent = true;
     system("COLOR 5F");
 }
 }
 // check passwordlength
 if((strlen(acc.pass_word)) >= 8){
     passwordlength = true;
 }
 if(symbolpresent == false){
 printf("\n\nPassword must contain Atleast-One-Symbol.");
 system("COLOR 4f");
 Beep(750,500);
 }
 if(passwordlength == false){
 printf("\n\nPassword must contain atleast 9 character.");
 system("COLOR 4f");
 Beep(750,500);}
 }while((symbolpresent != true) || (passwordlength != true));
 do{
 memset(&passwod, 0, sizeof passwod);
 printf("\n\nConfirm Your Password:\t");
 getpassword(passwod);
 if (!strcmp(acc.pass_word,passwod)){
 system("COLOR 5f");
 printf("\n\nYour Password Matched Successfully.");
 //add username
 getUsername(acc.email,acc.username);
 }else{
 system("COLOR 4f");
 printf("\n\nYour password don't Matched.\n");
 }}while(strcmp(acc.pass_word,passwod));
 // Add status
 printf("\n\nEnter Code For STATUS:\t");
 scanf("%d",&code);
 if(code == 455){
 strcpy(acc.status,"Admin");
 }else if (code == 460){
 strcpy(acc.status,"Employee");
 }else if( code == 465){
 strcpy(acc.status,"Customer");
 }
 }  
 void gotoxy(int x,int y){
       COORD c;
       c.X = x;
       c.Y = y;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
 }
   
 // Main Function
 int main(){
 // Get Systemdate;
 SYSTEMTIME d;
 GetSystemTime(&d);
 int day = d.wDay;
 int month = d.wMonth;
 int year = d.wYear;
 
 
 char gtchar;
 int i , n = 0;
 int option; 
 char pass[50] , user[50];
 char medi[20];
 
 
 FILE *sc;
 FILE *sc2;
 FILE *mc;
 FILE *mc2;
 FILE *sp;
 FILE *sp2;
 
 
 do{
 char ch;
 bool userfound = false;
 bool passfound = false;
 memset(&acc, 0, sizeof acc);
 memset(&med, 0, sizeof med);
 memset(&sup, 0, sizeof sup);
 memset(&medi,0, sizeof medi);
 system("cls");
 system("COLOR 5F");
 gotoxy(50,10);
 printf("Pharmacy Management System");
 gotoxy(43,12);
 printf("--- Welcome To Authentication System ---");
 gotoxy(10,16);
 printf("Enter Your Operation:");
 gotoxy(10,17);
 printf("1:Signup");
 gotoxy(10,18);
 printf("2:Login");
 gotoxy(10,19);
 printf("3:Exit");
 gotoxy(10,20);
 printf("Your choice:\t");
 scanf("%d",&option);
 fflush(stdin);
 switch(option){
 case 1:
 username();
 sc = fopen("Users\\Users.txt","a+");
 fwrite(&acc,sizeof(acc),1,sc);
 fclose(sc);
 system("cls");
 printf("Your profile has been successfully created.");
 printf("\n\n\t\t\t\t\t                    --- Your Profile ---               ");
 printf("\n\n Name: %s",acc.name);
 printf("\n Email: %s",acc.email);
 printf("\n Status: %s",acc.status);
 printf("\n Username: %s",acc.username);
 printf("\n\nPRESS Y TO CONTINUE:\t");
 scanf(" %c",&gtchar);
 fflush(stdin);
 break;
 case 2:
 memset( &pass, 0, sizeof pass);
 printf("\nEnter Your Username:\t");
 input(user);
 printf("\nEnter Your Password:\t");
 getpassword(pass);
 sc =  fopen("Users\\Users.txt","r");
 while(fread(&acc,sizeof(acc),1,sc)){
 if(!strcmp(acc.username,user)){
 userfound = true;
 if(!strcmp(acc.pass_word,pass)){
 passfound = true;
 if(!strcmp(acc.status,"Admin")){
 char name[50];
 char email[50];
 char username[50];
 strcpy(email,acc.email);
 strcpy(name,acc.name);
 strcpy(username,acc.username);
 fclose(sc);
 do{
 system("cls");
 printf("\t\t---------------------  Welcome To Your Profile  ---------------------\n");
 printf("\t\t---------------------          Admin            ---------------------\n");
 printf("\n\nWelcome %s\n",name);
 printf("\nYour Email:%s",email);
 printf("\nYour Username:%s",username);
 printf("\n\n\nEnter Your Operation:");
 printf("\n1:TOTAL MEDICINE");
 printf("\n2:TOTAL SUPPLIER");
 printf("\n3:EDIT EMPLOYEE SALARY");
 printf("\n4:EMPLOYEE SALARY");
 printf("\n5:REMOVE EMPLOYEE");
 printf("\n6:BACK");
 printf("\nEnter choice:");
 scanf("%d",&option);
 fflush(stdin);
 switch(option){
 case 1:
 do{
 system("cls");
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 mc = fopen("Medicine\\Medicine.txt", "r");
 i = 1;
 while(fread(&med,sizeof(med),1,mc) == 1){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",i,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 i++;
 }
 fclose(mc);
 ch = getch();
 }while(ch != '\r');
 break;
 case 2:
 do{
 system("cls");
 printf("%-5s%-20s%-20s%-40s%-20s%-20s\n","ID","SUPPLIER NAME","PHONE NUMBER","EMAIL","MEDICINE SUPPLIED","MEDICINE QUANTITY");
 sp = fopen("Supplier\\Supplier.txt", "r");
 i = 1;
 while(fread(&sup,sizeof(sup),1,sp) == 1){
 printf("%-5d%-20s%-20s%-40s%-20s%-20s\n",i,sup.name,sup.mobilenumber,sup.email,sup.medicinesupplied,sup.quantitysupplied);
 i++;
 }
 fclose(sp);
 ch = getch();
 }while( ch != '\r');
 break;
 case 3: 
 system("cls");
 printf("Enter the employee name you want to update salary: ");
 gets(medi);
 fflush(stdin);
 sc = fopen("Users\\Users.txt","r+");
 bool salaryupdate = false;
 int offset = 0 , pos = 0;
 while(fread(&acc,sizeof(acc),1,sc) == 1){
 offset = (300 * pos);
 if((!stricmp(acc.name,medi)) && (!stricmp(acc.status,"Employee"))){
 salaryupdate = true;
 int length = strlen(acc.salary);
 printf("Enter the salary amount:");
 input(acc.salary);
 fseek(sc,offset + 250,SEEK_SET);
 fputs(acc.salary,sc);
 for( i = strlen(acc.salary); i < length;i++){
 fputc('\0',sc);
 }
 break;
 }
 pos++;
 }
 fclose(sc);
 if(salaryupdate == false){
 printf("Employee Not Found:");
 Beep(800,1200);
 }
 break;
 case 4:
 do{
 system("cls");
 printf("%-5s%-20s%-20s\n","ID","EMPLOYEE NAME","EMPLOYEE SALARY");
 sc = fopen("Users\\Users.txt", "r");
 i = 1;
 while(fread(&acc,sizeof(acc),1,sc) == 1){ 
 if(!stricmp(acc.status,"Employee")){
 printf("%-5d%-20s%-20s",i,acc.name,acc.salary);
 i++;
 }
 }
 fclose(sc);
 ch = getch();
 }while(ch != '\r');
 break;
 case 5:
 printf("\nEnter the Employee Name to remove:");
 input(medi);
 bool employeedelet = false;
 sc = fopen("Users\\Users.txt", "r");
 sc2 = fopen("Users\\Users2.txt","a");
 while(fread(&acc,sizeof(acc),1,sc) == 1){
 if((stricmp(acc.name,medi) != 0 ) && (stricmp(acc.status,"Employee") != 0)){
 fwrite(&acc,sizeof(acc),1,sc2);
 }else{
 employeedelet = true;
 }
 }
 fclose(sc);
 fclose(sc2);
 remove("Users\\Users.txt");
 rename("Users\\Users2.txt","Users\\Users.txt");
 if( employeedelet == true){
 printf("Employee Deleted Successfully");
 Beep(500,1200);
 }else{
 printf("EMPLOYEE NOT FOUND");
 Beep(500,1200);
 } 
 break;
 }} while(option != 6);
 break;
 }else if(!strcmp(acc.status,"Employee")){
 do{
 system("cls");
 printf("\t\t---------------------  Welcome To Your Profile  ---------------------\n");
 printf("\t\t---------------------      Employee Section     ---------------------\n");
 printf("\nWelcome %s.",acc.name);
 printf("\nYour Email:%s",acc.email);
 printf("\nYour Username:%s",acc.username);
 printf("\n\n\nEnter Your Operation:");
 printf("\n1: MEDICINE DETAILS\n");
 printf("2: SUPPLIERS DETAILS\n");
 printf("3: BACK\n");
 printf("Enter Choice: ");
 scanf("%d",&option);
 fflush(stdin);
 switch(option){
 case 1:
 do{
 system("cls"); 
 printf("\n\n1:ADD MEDICINE");
 printf("\n2:REMOVE MEDICINE");
 printf("\n3:UPDATE MEDICINE");
 printf("\n4:TOTAL MEDICINE");
 printf("\n5:SEARCH MEDICINE");
 printf("\n6:EXPIRY MEDICINE");
 printf("\n7:OUT_OF_STOCK MEDICINE");
 printf("\n8:BACK");
 printf("\nEnter your choice:\t");
 scanf("%d", &option);
 fflush(stdin);
 switch(option){
 case 1:
 addmedicine();
 mc = fopen("Medicine\\Medicine.txt","a+");
 fwrite(&med, sizeof(med),1,mc);
 fclose(mc);
 break;
 case 2:
 printf("\nEnter the Medicine to remove:");
 input(medi);
 bool medicinedelet = false;
 mc = fopen("Medicine\\Medicine.txt", "r");
 mc2 = fopen("Medicine\\Medicine2.txt","a");
 while(fread(&med,sizeof(med),1,mc) == 1){
 if(strcmp(med.name,medi) != 0){
 fwrite(&med,sizeof(med),1,mc2);
 }else{
 medicinedelet = true;
 }
 }
 fclose(mc);
 fclose(mc2);
 remove("Medicine\\Medicine.txt");
 rename("Medicine\\Medicine2.txt","Medicine\\Medicine.txt");
 if( medicinedelet == true){
 printf("Medicine Deleted Successfully");
 Beep(500,800);
 }else{
 printf("Medicine Not Match");
 Beep(500,800);
 }
 break;
 case 3:
 printf("\nEnter the Medicine you want to update:");
 input(medi);
 fflush(stdin);
 int offset = 0, pos = 0;
 bool medicinematch = false;
 mc = fopen("Medicine\\Medicine.txt", "r+");
 while(fread(&med,sizeof(med),1,mc) == 1){
 offset = (212 * pos);
 if(!strcmp(med.name,medi)){
 medicinematch = true;
 printf("Enter Update");
 printf("\n1:Name");
 printf("\n2:CompanyName");
 printf("\n3:Mfg_Date");
 printf("\n4:Exp_Date");
 printf("\n5:Cabnit Number");
 printf("\n6:Quantity");
 printf("\n7:Cost");
 printf("\nEnter choice:");
 input(medi);
 fflush(stdin);
 if(stricmp(medi,"name") == 0){
 printf("Enter the New name:");
 input(medi);
 fseek(mc,offset,SEEK_SET);
 fputs(medi,mc);
 for( i = strlen(medi); i <strlen(med.name);i++){
 fputc('\0',mc);
 }
 break;
 }else if(stricmp(medi,"companyname") == 0){
 printf("Enter the New Companyname:");
 input(medi);
 fseek(mc,offset + 50,SEEK_SET);
 fputs(medi,mc);
 for( i = strlen(medi); i <strlen(med.companyname);i++){
 fputc('\0',mc);
 }
 break;
 }else if(stricmp(medi,"Mfg_Date") == 0){
 printf("Enter the New Mfg_Date:");
 input(medi);
 fseek(mc,offset + 100,SEEK_SET);
 fputs(medi,mc);
 for( i = strlen(medi); i <strlen(med.Mfg_Date);i++){
 fputc('\0',mc);
 }  
 break;
 }else if(stricmp(medi,"Exp_Date") == 0){
 printf("Enter the New Exp_Date:");
 input(medi);
 fseek(mc,offset + 150,SEEK_SET);
 fputs(medi,mc);
 for( i = strlen(medi); i <strlen(med.Exp_Date);i++){
 fputc('\0',mc);
 }
 break;
 }else if(stricmp(medi,"Cabnit Number") == 0){
 printf("Enter the New Cabnit Number:");
 scanf("%d",&n);
 fflush(stdin);
 fseek(mc,offset + 200,SEEK_SET);
 putw(n,mc);
 break;
 }else if(stricmp(medi,"Quantity") == 0){
 printf("Enter the New Qunatity");
 scanf("%d",&n);
 fflush(stdin);
 fseek(mc,offset + 204,SEEK_SET);
 putw(n,mc);
 break;
 }else if(stricmp(medi,"Cost") == 0){
 printf("Enter the New Cost");
 scanf("%d",&n);
 fflush(stdin);
 fseek(mc,offset + 208,SEEK_SET);
 putw(n,mc);
 break;
 }
 }
 pos++;
 }
 if(medicinematch == false) {
 printf("NO MEDICINE MATCH");
 Beep(500,2000);
 }else{
 printf("MEDICINE UPDATED SUCCESSFULLY");
 Beep(500,2000);	
 }
 fclose(mc);
 break;
 case 4:
 do{
 system("cls");
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 mc = fopen("Medicine\\Medicine.txt", "r");
 i = 1;
 while(fread(&med,sizeof(med),1,mc) == 1){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",i,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 i++;
 }
 fclose(mc);
 ch = getch();
 }while(ch != '\r');
 break;
 // Search Medicine
 case 5:
 do{
 system("cls");
 printf("Enter the Medicine Name you want to search:");
 gets(medi);
 fflush(stdin);
 bool medicinepresent = false;
 mc = fopen("Medicine\\Medicine.txt", "r");
 while(fread(&med,sizeof(med),1,mc) == 1){
 if(stricmp(med.name,medi) == 0){
 system("cls");
 i = 1;
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",i,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 medicinepresent = true;
 }
 }
 if(medicinepresent = false){
 printf("\n NO MEDICINE FOUND");
 }
 fclose(mc);
 ch = getch();
 }while(ch != '\r');
 break;
 case 6:
 do{
 system("cls");
 bool expiredmedicine = false;
 int count = 1;
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 mc = fopen("Medicine\\Medicine.txt", "r");
 while(fread(&med,sizeof(med),1,mc) == 1){
 char s1[50]= {0};
 char *token;
 int month1 = 0;
 int day1 = 0;
 int year1 = 0;
 strcpy(s1,med.Exp_Date);
 token = strtok(s1,"-");
 month1 = atoi(token);
 for ( i = 1; token != NULL; i++){
 token = strtok(NULL,"-");
 if(i == 1){
 day1 = atoi(token);
 }else if( i == 2){
 year1 = atoi(token);
 }
 }
 free(token);
 if(year1 > year){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",count,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);	
 expiredmedicine = true;
 count++;
 }else if((year1 <= year) && (month1 > month)){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",count,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);	
 expiredmedicine = true;
 count++;

 }else if((year1 <= year) && (month1 >= month) && (day1 > day)){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",count,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 expiredmedicine = true;
 count++;
 }
 }
 fclose(mc);
 if(expiredmedicine == false){
 printf("NO More Expired Medicine");
 }
 ch = getch();
 }while(ch != '\r');
 break;
 // out of stock medicine
 case 7:
 do{
 system("cls");
 mc = fopen("Medicine\\Medicine.txt", "r");
 i = 1;
 bool out_of_stock = false;
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 while(fread(&med,sizeof(med),1,mc) == 1){
 int q = med.quantity;
 if(q <= 10){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",i,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 out_of_stock = true;
 }
 }
 if(out_of_stock == false){
 printf("NO OUT OF STOCK MEDICINE:");
 }
 fclose(mc);
 ch = getch();
 }while(ch != '\r');
 break;}
 }while(option != 8);
 break;
 case 2:
 do{
 system("cls");
 printf("Enter Your Operation:");
 printf("\n\n1:ADD SUPPLIER");
 printf("\n2:REMOVE SUPPLIER");
 printf("\n3:UPDATE SUPPLIER");
 printf("\n4:TOTAL SUPPLIER");
 printf("\n5:SEARCH SUPPLIER");
 printf("\n6:BACK");
 printf("\nEnter Your choice:");
 scanf("%d", &option);
 fflush(stdin);
 switch(option){
 case 1: 
 addsupplier();
 sp = fopen("Supplier\\Supplier.txt","a+");
 fwrite(&sup, sizeof(sup),1,sp);
 fclose(sp);
 break;
 case 2:
 printf("\nEnter the Supplier to remove:");
 gets(medi);
 bool removesupplier = false;
 sp = fopen("Supplier\\Supplier.txt", "r");
 sp2 = fopen("Supplier\\Supplier2.txt","a");
 while(fread(&sup,sizeof(sup),1,sp) == 1){
 if(strcmp(sup.name,medi) != 0){
 fwrite(&sup,sizeof(sup),1,sp2);
 }else{
 removesupplier = true;
 }
 }
 fclose(sp);
 fclose(sp2);
 remove("Supplier\\Supplier.txt");
 rename("Supplier\\Supplier2.txt","Supplier\\Supplier.txt");
 if(removesupplier == true){
 printf("Supplier Deleted Successfully");
 }else{
 printf("Supplier Not Found.");
 }
 Beep(500,800);
 break;
 case 3:
 printf("\nEnter the Supplier you want to update:");
 input(medi);
 fflush(stdin);
 bool supplierupdate = false;
 int offset = 0, pos = 0;
 sp = fopen("Supplier\\Supplier.txt", "r+");
 while(fread(&sup,sizeof(sup),1,sp) == 1){
 offset = (204 * pos);
 if(!stricmp(sup.name,medi)){
 supplierupdate = true;
 printf("Enter Update");
 printf("\n1:Name");
 printf("\n2:Phone Number");
 printf("\n3:Email");
 printf("\n4:Medicine Supplied");
 printf("\n5:Medicine Supplied");
 printf("\nEnter choice:");
 input(medi);
 fflush(stdin);
 if(stricmp(medi,"Name") == 0){
 printf("Enter the New name:");
 input(medi);
 fseek(sp,offset,SEEK_SET);
 fputs(medi,sp);
 for( i = strlen(medi); i <strlen(sup.name);i++){
 fputc('\0',sp);
 }
 break;
 }else if(stricmp(medi,"Phone Number") == 0){
 printf("Enter the New Phone Number:");
 input(medi);
 fseek(sp,offset + 50,SEEK_SET);
 fputs(medi,sp);
 for( i = strlen(medi); i <strlen(sup.mobilenumber);i++){
 fputc('\0',sp); 
 }
 break;
 // New Email Address:
 }else if(stricmp(medi,"Email") == 0){
 printf("Enter the New Email:");
 input(medi);
 fseek(sp,offset + 100,SEEK_SET);
 fputs(medi,sp);
 for( i = strlen(medi); i <strlen(sup.email);i++){
 fputc('\0',sp);
 }
 break;
 // New Medicine Supplied:
 }else if(stricmp(medi,"Medicine Supplied") == 0){
 printf("Enter the New Medicine Supplied:");
 input(medi);
 fseek(sp,offset + 150,SEEK_SET);
 fputs(medi,sp);
 for( i = strlen(medi); i <strlen(sup.medicinesupplied);i++){
 fputc('\0',sp);
 }
 break;
 }else if(stricmp(medi,"Quantity Supplied") == 0){
 printf("Enter the New Quantity Supplied:");
 scanf("%d",&n);
 fseek(sp,offset + 200,SEEK_SET);
 putw(n,sp);
 
 break;
 }
 }
 pos++;
 }
 fclose(sp);
 if(supplierupdate == false){
 printf("NO SUPPLIER MATCH");
 Beep(500,2000);
 }else{
 printf("SUPPLIER UPDATED SUCCESSFULLY");
 Beep(500,2000);	
 }

 break;
 case 4:
 do{
 system("cls");
 printf("%-5s%-20s%-20s%-40s%-20s%-20s\n","ID","SUPPLIER NAME","PHONE NUMBER","EMAIL","MEDICINE SUPPLIED","MEDICINE QUANTITY");
 sp = fopen("Supplier\\Supplier.txt", "r");
 i = 1;
 while(fread(&sup,sizeof(sup),1,sp) == 1){
 printf("%-5d%-20s%-20s%-40s%-20s%-20s\n",i,sup.name,sup.mobilenumber,sup.email,sup.medicinesupplied,sup.quantitysupplied);
 i++;
 }
 fclose(sp);
 ch = getch();
 }while(ch != '\r');
 break;
 }}while( option != 6);
 break;
 }
 }while(option != 3);
 break;
 }else if(!strcmp(acc.status,"Customer")){
 do{
 system("cls");
 int order;
 printf("\t\t---------------------  Welcome To Your Profile  ---------------------\n");
 printf("\t\t---------------------      Customer Section            ---------------------\n");
 printf("\n\nWelcome %s\n",acc.name);
 printf("\nYour Email:%s",acc.email);
 printf("\nYour Username:%s",acc.username);
 printf("\n\n\nEnter Your Operation:");
 printf("\n1:TOTAL MEDICINE");
 printf("\n2:ORDER MEDICINE");
 printf("\n3:BACK");
 printf("\nEnter choice:");
 scanf("%d",&option);
 fflush(stdin);
 switch(option){
 case 1:
 do{
 system("cls");
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 mc = fopen("Medicine\\Medicine.txt", "r");
 i = 1;
 while(fread(&med,sizeof(med),1,mc) == 1){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",i,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 i++;
 }
 fclose(mc);
 ch = getch();
 }while(ch != '\r');
 break;
 case 2:
 do{
 system("cls");
 printf("%-5s%-20s%-50s%-20s%-20s%-20s%-20s%-20s\n","ID","MED-NAME","COMY-NAME","MFG_DATE","EXP_DATE","CAB-Name","PRICE","QUANTITY");
 mc = fopen("Medicine\\Medicine.txt", "r");
 i = 1;
 while(fread(&med,sizeof(med),1,mc) == 1){
 printf("%-5d%-20s%-50s%-20s%-20s%-20d%-20d%-20d\n",i,med.name,med.companyname,med.Mfg_Date,med.Exp_Date,med.cabnitno,med.cost,med.quantity);
 i++;
 }
 fclose(mc);
 printf("\nEnter the amount of tablet you want to purchase:");
 scanf("%d",&order);
 fflush(stdin);	
 int price = 0 , quantity;

 bool medicinepresent;
 for( i = 0; i < order;i++){
 int offset = 0 ,pos = 0;
 printf("\nEnter the medicine name you want to purchase:");
 input(medi);
 fflush(stdin);
 mc = fopen("Medicine\\Medicine.txt", "r+");
 while(fread(&med,sizeof(med),1,mc) == 1){
 offset = (212 * pos);
 if(stricmp(med.name,medi) == 0){
 price = price + med.cost;
 printf("ORDER PRICE: %d",price);
 quantity = med.quantity;
 quantity = quantity - 1;
 fseek(mc,offset + 204,SEEK_SET);
 putw(quantity,mc); 
 break;
 }
 pos++;
 }
 fclose(mc);
 }
 ch = getch();
 }while(ch != '\r');
 break;
 }
 }while(option != 3);
 }
 }
 }
 }
 if(userfound == false){
 printf("\n\nUser Is Not found");
 Beep(750,1500);
 system("cls");
 }else if(passfound == false){
 printf("\n\nINVALID PASSWORD");
 Beep(750,1500);
 system("cls");
 }
 fclose(sc);
 break;
 case 3:
 return 1;
 break;
 }
 }while( gtchar == 'Y' || 'y');
 return 0;
 }
