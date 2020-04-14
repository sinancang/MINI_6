/* poly.c
 * This file builds the linked list polynomials will be stored in
 * 
 * Also contains definitions for the following functions:
 * - addPolyTerm
 * - displayPolynomial
 * - evaluatePolynomial
 *
 * Author: Sinan Can Gulan
 * Department of Computer Science
 * History:
 * 13/4/2020: Initial file created
 * 14/4/2020: File finalized
 */
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
#include "utils.h"

struct PolyTerm *head;

int addPolyTerm(int coefficient, int exponent){
	struct PolyTerm *temp = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
	if (temp == NULL) return -1; // -1 to designate malloc error
	temp->coeff = coefficient;
	temp->expo = exponent;
	
	if (head == NULL){  // first element of the list
		head = temp;
		temp->next = NULL;
		return 0;
	} else {
		if (head->expo < temp->expo){
			int added = 0;
			struct PolyTerm *tempHead = head;
			while (tempHead->next != NULL){  //iterate through the list to the end
				if (tempHead->next->expo > temp->expo){ //if next element has higher expo, place 
					temp->next = tempHead->next;
					tempHead->next = temp;
					return 0;
				}
				tempHead = tempHead->next;
			}
			tempHead->next = temp; //if temp isn't added, add to the tail of the list
			return 0;
		}else {
			temp->next = head; //exponent of temp <= head, add to front of list
			head = temp;
			return 0;
		}
	}
}

void displayPolynomial(){
	struct PolyTerm *temp = head;
	while (1) {
		int expo = temp->expo;
		int coeff = temp->coeff;
		while (temp->next != NULL && temp->next->expo == expo){     // if exponents are the same, add coefficients up and display only one
			coeff += temp->next->coeff;
			temp = temp->next;
		}
		
		printf("%dx%d", coeff, expo);
		if (temp->next != NULL) {	// if this is the last element, end. otherwise print a plus
			printf("+");
		} else {
			break;
		}
		temp = temp->next;
	}
	printf("\n");
}

int evaluatePolynomial(int x){
	int sum = 0;
	struct PolyTerm *temp = head;
	while (temp != NULL) {
		int power = x;
		powi(&power, temp->expo);
		sum += temp->coeff * power;
		temp = temp->next;
	}
	printf("for x=%d, y=%d\n", x, sum);
}
