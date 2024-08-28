/* 1. Write a program in C to input a string and print it.

Test Data :
Input the string : Welcome, w3resource

Expected Output :

The string you entered is : Welcome, w3resourc */

#include <stdio.h>

int main(void){

char string[50];

printf("Input the string : ");

fgets(string, sizeof(string), stdin);

printf("The string you entered is : %s", string);


}