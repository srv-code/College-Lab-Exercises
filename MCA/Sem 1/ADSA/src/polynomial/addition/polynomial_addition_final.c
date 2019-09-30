#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct
{
    int coeff, exp;
} Poly;

void fill_poly(Poly p[MAX_SIZE])
{ 
    int len;
    printf("  Length:  ");
    scanf("%d", &len);

    if(len > MAX_SIZE) {
        printf("Error: Value greater than max size=%d \n", MAX_SIZE);
        exit(-1);
    }

    p[0].coeff = len;
    printf("  Coefficients and exponents: \n");
    
    int i;
    for(i=1; i<=len; i++) {
        printf("    [%d]:  ", i);
        scanf("%d %d", &p[i].coeff, &p[i].exp);
    }
}

void add_poly(Poly p1[MAX_SIZE], Poly p2[MAX_SIZE], Poly p3[MAX_SIZE])
{
    int p1_len = p1[0].coeff, p2_len = p2[0].coeff, i, j, k;

    // add two poly wrt poly1
    for(i=1, j=1, k=1; i<=p1_len && j<=p2_len;) {
        // perform addition
        if(p1[i].exp == p2[j].exp) {
            if(p1[i].coeff + p2[j].coeff != 0) {
                p3[k].exp = p1[i].exp;
                p3[k].coeff = p1[i].coeff + p2[j].coeff;
                k++;
            }
            i++; j++;
        } else if(p1[i].exp > p2[j].exp) {
            if(p1[i].coeff != 0) {
                p3[k].exp   = p1[i].exp;
                p3[k].coeff = p1[i].coeff;
                k++;
            }
            i++;
        } else {
            if(p2[j].coeff != 0) {
                p3[k].exp   = p2[j].exp;
                p3[k].coeff = p2[j].coeff;
                k++;
            }
            j++;
        }
    }

    if(i<=p1_len) {
        // fill from rest of p1
        for(; i<=p1_len; i++) {
            if(p1[i].coeff !=  0) {
                p3[k].exp   = p1[i].exp;
                p3[k].coeff = p1[i].coeff;
                k++;
            }
        }
    } else if(j<=p2_len) { // else-if since cases are mutually exclusive
        // fill from rest of p2
        for(; j<=p2_len; j++) {
            if(p2[j].coeff !=  0) {
                p3[k].exp   = p2[j].exp;
                p3[k].coeff = p2[j].coeff;
                k++;
            }
        }
    }
    
    // set length of p3
    p3[0].coeff = k-1;
}

void show_poly(const Poly p[MAX_SIZE]) 
{
    int i, len = p[0].coeff;
    for(i=1; i<=len; i++) {
        printf("(%2d,%2d) ", p[i].coeff, p[i].exp);
    }
    printf("\n");
}

int main() 
{
    system("clear");

    Poly p1[MAX_SIZE], p2[MAX_SIZE], p3[MAX_SIZE];

    printf("Enter polynomial 1: \n");
    fill_poly(p1);

    printf("Enter polynomial 2: \n");
    fill_poly(p2);

    printf("\n");

    printf("Polynomial 1:  ");
    show_poly(p1);

    printf("Polynomial 2:  ");
    show_poly(p2);    

    add_poly(p1, p2, p3);

    printf("Summation:     ");
    show_poly(p3);

    return 0;
}