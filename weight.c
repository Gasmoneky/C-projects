#include <stdio.h>
#include <string.h>

int main(){
printf("WEIGHT CONVERSION PROGRAM\n\a");

float kilograms = 0.0f;
float grams = 0;
char choice[15] = "";
const char kg[]= "kilogram";
char g[6]= "grams";
float result = 0.0f;

printf("What do you want to convert to (kilogram) or (grams)");
fgets(choice,sizeof(choice),stdin);
choice[strcspn(choice, "\n")] = '\0';


if(strcmp(choice,kg) ==0){
printf("What is the weight in grams\n");
scanf("%f",&result);
kilograms= (result / 1000.00);
printf("Your weight in kilograms is %.1f kilograms",kilograms);
}
else if(strcmp(choice,g) ==0 ){
printf("What is the weight in kilograms\n");
scanf("%f",&result);
grams = result*1000;
printf("your weight in grams is %.2f grams",grams);
}
else{
printf("please enter a valid statement either (kilogram) or grams");

}

    return 0;
}