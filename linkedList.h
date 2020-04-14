/* header file for a simple linked list data structure
 * Author: Sinan Can Gulan
 * Department of Computer Science
 * History:
 * 14/03/2020: file created & finalized
 */
struct PolyTerm{
        int coeff;
        int expo;
        struct PolyTerm *next;
};

// methods to be defined in poly.c
int addPolyTerm(int coefficient, int exponent);
void displayPolynomial();
int evaluatePolynomial(int x);
