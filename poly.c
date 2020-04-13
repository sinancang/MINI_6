/* poly.c
 * This file contains the linked list polynomials will be stored in
 * 
 * Also contains the following functions:
 * - addPolyTerm
 * - displayPolynomial
 * - evaluatePolynomial
 *
 * Author: Sinan Can Gulan
 * Department of Computer Science
 * History:
 * 13/4/2020: Initial file created
 */
struct head;

struct PolyTerm{
        int head;
        int expo;
        struct PolyTerm *next;
}
