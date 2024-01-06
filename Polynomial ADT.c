// Polynomial ADT

// Node structure to represent a term in the polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next; // Pointer to the next term in the polynomial
} Term;

// Polynomial structure
typedef struct Polynomial {
    Term* head; // Pointer to the first term in the polynomial
} Polynomial;

// Function to create a new term with the given coefficient and exponent
Term* createTerm(int coefficient, int exponent);

// Function to initialize an empty polynomial
Polynomial* initializePolynomial();

// Function to add a term to a polynomial
void addTerm(Polynomial* poly, int coefficient, int exponent);

// Function to add two polynomials and return the result
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2);

// Function to multiply two polynomials and return the result
Polynomial* multiplyPolynomials(Polynomial* poly1, Polynomial* poly2);

// Function to evaluate a polynomial for a given value of x
int evaluatePolynomial(Polynomial* poly, int x);

// Function to display a polynomial
void displayPolynomial(Polynomial* poly);

// Function to free the memory allocated for a polynomial
void freePolynomial(Polynomial* poly);

// Additional functions can be added based on the specific requirements of your application
//***********************************************************************************
#include <stdlib.h>

Polynomial* initializePolynomial() {
    // Allocate memory for a new Polynomial structure
    Polynomial* newPoly = (Polynomial*)malloc(sizeof(Polynomial));

    // Check if memory allocation was successful
    if (newPoly == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Initialize the members of the Polynomial structure
    newPoly->head = NULL; // Initialize the head pointer to NULL

    return newPoly;
}

#include <stdlib.h>

Term* createTerm(int coefficient, int exponent) {
    // Allocate memory for a new Term structure
    Term* newTerm = (Term*)malloc(sizeof(Term));
//************************************************************************


    // Check if memory allocation was successful
    if (newTerm == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Initialize the members of the Term structure
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL; // Initialize the next pointer to NULL

    return newTerm;
}

//*****************************************************************************
#include <stdlib.h>

void addTerm(Polynomial* poly, int coefficient, int exponent) {
    // Create a new term
    Term* newTerm = createTerm(coefficient, exponent);

    // Check if term creation was successful
    if (newTerm == NULL) {
        // Handle error, e.g., by returning or printing an error message
        return;
    }

    // If the polynomial is empty, set the new term as the head
    if (poly->head == NULL) {
        poly->head = newTerm;
    } else {
        // Traverse to the end of the polynomial to find the last term
        Term* current = poly->head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Add the new term to the end of the polynomial
        current->next = newTerm;
    }
}

//******************************************************************
#include <stdlib.h>

Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    // Create a new polynomial to store the sum
    Polynomial* sumPoly = initializePolynomial();

    // Traverse the terms of both polynomials and add corresponding terms
    Term* term1 = poly1->head;
    Term* term2 = poly2->head;

    while (term1 != NULL || term2 != NULL) {
        // Get the coefficients and exponents of the current terms (or 0 if a term is NULL)
        int coef1 = (term1 != NULL) ? term1->coefficient : 0;
        int exp1 = (term1 != NULL) ? term1->exponent : 0;
        int coef2 = (term2 != NULL) ? term2->coefficient : 0;
        int exp2 = (term2 != NULL) ? term2->exponent : 0;

        // Calculate the sum of coefficients and exponents
        int sumCoef = coef1 + coef2;
        int sumExp = (exp1 > exp2) ? exp1 : exp2; // Take the larger exponent

        // Add the term to the sum polynomial
        addTerm(sumPoly, sumCoef, sumExp);

        // Move to the next terms in both polynomials
        if (term1 != NULL) term1 = term1->next;
        if (term2 != NULL) term2 = term2->next;
    }

    return sumPoly;
}
//*********************************************************************************************
#include <stdlib.h>

Polynomial* multiplyPolynomials(Polynomial* poly1, Polynomial* poly2) {
    // Create a new polynomial to store the product
    Polynomial* productPoly = initializePolynomial();

    // Multiply each term of poly1 with each term of poly2
    Term* term1 = poly1->head;

    while (term1 != NULL) {
        Term* term2 = poly2->head;

        while (term2 != NULL) {
            // Multiply coefficients and add exponents
            int coefProduct = term1->coefficient * term2->coefficient;
            int expSum = term1->exponent + term2->exponent;

            // Add the term to the product polynomial
            addTerm(productPoly, coefProduct, expSum);

            // Move to the next term in poly2
            term2 = term2->next;
        }

        // Move to the next term in poly1
        term1 = term1->next;
    }

    return productPoly;
}
//*************************************************************************************************
int evaluatePolynomial(Polynomial* poly, int x) {
    int result = 0;

    // Traverse each term in the polynomial and evaluate for the given value of x
    Term* currentTerm = poly->head;

    while (currentTerm != NULL) {
        // Evaluate the term for the given value of x and add to the result
        result += currentTerm->coefficient * pow(x, currentTerm->exponent);

        // Move to the next term
        currentTerm = currentTerm->next;
    }

    return result;
}
//*****************************************************************************
// Create terms for the polynomial 3x^2 + 2x + 1
Term* term1 = createTerm(3, 2);  // 3x^2
Term* term2 = createTerm(2, 1);  // 2x
Term* term3 = createTerm(1, 0);  // 1

// Create a polynomial and link the terms
Polynomial* poly = initializePolynomial();
poly->head = term1;
term1->next = term2;
term2->next = term3;
term3->next = NULL;
