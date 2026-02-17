#include <stdio.h>
#include <string.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>


typedef struct 
{
  int id;
  char name[50];
  char pin[5];
  float balance;
}AccountData;

void saveAccToFile(AccountData acc);
void loginFun();
void transactionMenu(AccountData user);
void updateBalance(AccountData u);
int transferMoney(int recipientID, float amount, AccountData *sender);


AccountData signupFun(){
AccountData newPersonAcc;
printf("\nWELCOME TO MMUST BANK:the bank of endless opportunities: NEW USER \n\n");
printf("PLEASE ENTER YOUR ID NUMBER\n");
scanf("%d",&newPersonAcc.id);


printf("PLEASE ENTER YOUR FULL NAME \n");
while (getchar() != '\n');
fgets(newPersonAcc.name,sizeof(newPersonAcc.name),stdin);
newPersonAcc.name[strcspn(newPersonAcc.name, "\n")] = '\0';


newPersonAcc.balance = 0.0f;
srand(time(NULL));
for(int i = 0 ; i<=3 ; i++){
   newPersonAcc.pin[i] = (rand() % 10) + '0';
}
        newPersonAcc.pin[4] = '\0';
      


printf("\n\nHELLO: %s \n",newPersonAcc.name);
printf("\nYOUR ID NUMBER IS: %d\n",newPersonAcc.id);
printf("\nYOUR PRIVATE PIN IS %c %c %c %c", 
        newPersonAcc.pin[0], newPersonAcc.pin[1], 
        newPersonAcc.pin[2], newPersonAcc.pin[3]);
        printf("\n\nYOUR CURRENT BALANCE IS: %.2f",newPersonAcc.balance);

return newPersonAcc;
}

int main(){
    int choice = 0;
   do{
    printf("\nWELCOME TO MMUST BANK ACCOUNT MANAGEMENT SYSTEM MADE BY RYAN OCHIENG\n");
    printf("-------------------------------------------------------------\n");
    printf("           WHAT WOULD YOU LIKE TO DO TODAY??\n");
    printf("1:LOGIN\n\n");
    printf("2:SIGN-UP\n\n");
    printf("3:EXIT\n");
    scanf(" %d",&choice);
  switch(choice){
    case 1:
   loginFun();
    break;
    case 2:
      AccountData tempAccount = signupFun();
      saveAccToFile(tempAccount);
  }


   }while(choice!=3);


    return 0;
}

void saveAccToFile(AccountData acc){ 
    FILE *fptr = fopen("database.dat", "ab");
    if (fptr == NULL) {
        printf("ERROR OPENING FILE!\n");
        return;
    }
    fwrite(&acc, sizeof(AccountData), 1, fptr);
    fclose(fptr);
}

void loginFun(){
    char enteredName[50];
    char enteredPin[10];
    int found = 0;
    AccountData temp;
       while (getchar() != '\n');
    printf("MMUST BANK LOGIN CHECK PAGE\n");
    printf("ENTER YOUR NAME\n");
    fgets(enteredName,sizeof(enteredName),stdin);
    enteredName[strcspn(enteredName, "\n")] = '\0';
  

    printf("PLEASE ENTER YOUR PIN\a");
    fgets(enteredPin,sizeof(enteredPin),stdin);
    enteredPin[strcspn(enteredPin, "\n")] = '\0';
  
      FILE *fptr = fopen("database.dat", "rb");
      if(fptr==NULL){
        printf("PLEASE SIGN UP FIRST TO USE THE BANK SYSTEM");
        return;
      }

      while (fread(&temp, sizeof(temp), 1, fptr) == 1){
       if(strcmp(temp.name,enteredName)==0 && strcmp(temp.pin,enteredPin)==0){
        printf("\n------------------------------------------------------\n");
        printf("          WELCOME BACK %s",temp.name);
        printf("\n------------------------------------------------------\n");
        transactionMenu(temp);
        found = 1; 
           break;     
            }
           
      }
      

 fclose(fptr);
   }

void transactionMenu(AccountData currentUser){
int choice = 0;
float money;
char enteredPin[10];
int recipientId;
do{
printf("        MMUST BANK TRANSACTION MENU\n");
printf("------------------------------------------------\n");
printf("1.CHECK BALANCE\n");
printf("2.DEPOSIT MONEY\n");
printf("3.WITHDRAW MONEY\n");
printf("4.TRANSFER FUNDS\n");
printf("5.LOGOUT\n");
scanf("%d",&choice);

switch(choice){
  case 1:
printf("\nAVAILABLE BALANCE %0.02fksh\n\n",currentUser.balance);
  break;
  case 2:
  printf("HOW MUCH MONEY WOULD YOU LIKE TO DEPOSIT");
  scanf(" %f",&money);
  if(money > 0){
    currentUser.balance = currentUser.balance + money;
    updateBalance(currentUser);
  }


  break;
  case 3:
  printf("ENTER PIN TO CONFIRM WITHDRAWL OF FUNDS\t");
  while(getchar() != '\n');
  fgets(enteredPin, sizeof(enteredPin), stdin);
   enteredPin[strcspn(enteredPin, "\n")] = '\0';
   if (strcmp(enteredPin, currentUser.pin) == 0) {
                    printf("ENTER AMOUNT TO WITHDRAW: ");
                    scanf("%f", &money);

                    if(money > 0 && money <= currentUser.balance){
                        currentUser.balance = currentUser.balance - money;
                        updateBalance(currentUser);
                        printf(" WITHDRAWAL SUCCESSFUL\n");
                        printf("BALANCE: %.2f KSH\n", currentUser.balance);
                      }
                        else {
                        printf(" INSUFFICIENT FUNDS!\n");
                    }
                } else {
                    printf("\n WRONG PIN! PLEASE TRY AGAIN\n");
                }

  break;
  case 4:
  int targetId;
printf("ENTER PIN TO CONFIRM TRANSFER: ");
 while(getchar() != '\n');
       fgets(enteredPin, sizeof(enteredPin), stdin);
      enteredPin[strcspn(enteredPin, "\n")] = '\0'; 

      if (strcmp(enteredPin, currentUser.pin) == 0) {
    printf("\nENTER RECIPIENT ID: ");
    scanf("%d", &targetId);

    if (targetId == currentUser.id) {
        printf("\nERROR:CANNOT SEND MONEY TO YOURSELF\n");
        break;
    }
    else {
        printf("ENTER AMOUNT TO TRANSFER: ");
        scanf("%f", &money);
         if (money > currentUser.balance) {
            printf(" INSUFFICIENT FUNDS! You have %.2f KSH.\n", currentUser.balance);
                        } 
                        else if (money <= 0) {
                            printf(" INVALID AMOUNT.\n");
                        }
                        else {
                           
                            if (transferMoney(recipientId, money, &currentUser)) {
                                printf(" SUCCESS! Sent %.2f KSH to ID %d.\n", money, recipientId);
                                printf(" Your New Balance: %.2f KSH\n", currentUser.balance);
                            } else {
                                printf(" FAILED: User ID %d does not exist.\n", recipientId);
                            }
                        }
                    }
                    
                } else {
                    
                    printf("\n WRONG PIN! TRANSACTION CANCELLED.\n");
            
    }
    break;

  break;
  case 5:
  printf("LOGGING OUT GOODBYE");
  break;

}
}while(choice!=5);

}

void updateBalance(AccountData u){
    FILE *file = fopen("database.dat", "rb+");
    AccountData temp;
    if(file == NULL){
        printf("ERROR: Database not found.\n");
        return;
    }
    while (fread(&temp, sizeof(AccountData), 1, file) == 1) {
        if (temp.id == u.id) {
            fseek(file, -(long)sizeof(AccountData), SEEK_CUR);
            fwrite(&u, sizeof(AccountData), 1, file);
            break;
        }
    }
    fclose(file);
}
int transferMoney(int recipientId, float amount, AccountData *sender){
    FILE *file = fopen("database.dat", "rb+");
    AccountData temp;
    int found = 0;

    if (file == NULL){ 
      printf("DATABASE DOES NOT EXIST PLEASE CREATE USER");
      return 0;}

    while (fread(&temp, sizeof(AccountData), 1, file) == 1) {
        if (temp.id == recipientId) {
            temp.balance =temp.balance + amount; 
            
            
            fseek(file, -(long)sizeof(AccountData), SEEK_CUR);
            fwrite(&temp, sizeof(AccountData), 1, file);
            
            found = 1;
            break;
        }
    }
    if (found == 1) {
        sender->balance -= amount; 
        updateBalance(*sender);   
    }

    fclose(file);
    return found;
}
