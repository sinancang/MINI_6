/* utils.c
 *
 * Utility file for polynomial evaluation application.
 * Does parsing and computation.
 * Author: Sinan Can Gulan
 * Department of Computer Science
 * History:
 * 13/4/2020: File created, function headers added.
 * 14/4/2020: Add fcts parse & powi
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int parse(char str[], int *coeff, int *expo); //parses csv file data
int powi(int *x, int exponent); //computes x to the power of exponent

int main(int argc, char *argv[]){
        int coeff;
        int expo;
        char string[] = "10 20";
        parse(string, &coeff, &expo);

        int x = 2;
        int exponent = 0;

        powi(&x, exponent);
        printf("%d\n", x);
}

int parse(char str[], int *coeff, int *expo) {
        char * token = strtok(str, " ");
        *coeff = atoi(token);
        token = strtok(NULL, " ");
        *expo = atoi(token);
        return 0;
}

int powi(int *x, int exponent){
        int power_of = *x;
        int i = 1;
        *x = 1;
        while (i <= exponent){
                *x *= power_of;
                i++;
        }

        return 0;
}
