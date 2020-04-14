/* polyapp.c
 * Polynomial Evaluation App
 * -------------------------
 * This is the main file for an application that constructs a polynomial and evaluates it for certain predetermined values. 
 *
 * Author: Sinan Can Gulan
 * Department of Computer Science
 * History:
 * 13/4/2020: File created, function headers added.
 * 14/4/2020: File finalized
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "linkedList.h"

int main(int argc, char *argv[]){
	char filename[150]; 
	strcpy(filename, argv[1]);
	
	char singleLine[150];
	FILE *fPointer;
	fPointer = fopen(filename, "r");
	
	fgets(singleLine, 150, fPointer);	
	while(!feof(fPointer)){
		int coeff;
		int expo;
	        parse(singleLine, &coeff, &expo);
		addPolyTerm(coeff, expo);
		fgets(singleLine, 150, fPointer);
	}
	displayPolynomial();
	int i = -2;
	while (i <= 2) {
		evaluatePolynomial(i);
		i++;
	}
}
