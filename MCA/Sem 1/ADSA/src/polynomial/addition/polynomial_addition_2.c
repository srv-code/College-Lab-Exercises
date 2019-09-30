// Abid's version

#include <stdio.h>


struct polynomial 
{
        int coeff , exp;
} arr1[20], arr2[20], ans[20];

int main()
{
        system("clear");

        int i, j, count = 0, arr1count = 1, arr2count = 1;
        
        printf("Input polynomial 1: \n");
        printf("  Enter size:  ");
        scanf("%d", &arr1[0].coeff);
        
        printf("  Enter co-efficient and exponential parts: \n");
        for(i = 1 ; i <= arr1[0].coeff ; i++)
        {
                printf("    Term %d:  ", i);
                scanf("%d %d", &arr1[i].coeff, &arr1[i].exp);
        }

        printf("Input polynomial 2: \n");
        printf("  Enter size:  ");
        scanf("%d", &arr2[0].coeff);

        printf("  Enter co-efficient and exponential parts: \n");
        for(i = 1 ; i <= arr2[0].coeff ; i++)
        {
                printf("    Term %d:  ", i);
                scanf("%d %d", &arr2[i].coeff, &arr2[i].exp);
        }

        while(arr1[0].coeff >= arr1count || arr2[0].coeff >= arr2count)
        {
                if(arr1[arr1count].exp == arr2[arr2count].exp)
                {
                        if(arr1[arr1count].coeff + arr2[arr2count].coeff != 0)
                        {
                                ans[count].coeff = arr1[arr1count].coeff + arr2[arr2count].coeff;
                                ans[count].exp = arr1[arr1count].exp;
                                count++;
                        }
                        arr1count++;
                        arr2count++;
                }
                else if(arr1[arr1count].exp < arr2[arr2count].exp)
                {
                        ans[count].coeff = arr2[arr2count].coeff;
                        ans[count].exp = arr2[arr2count].exp;
                        arr2count++;
                        count++;
                }
                else if(arr1[arr1count].exp > arr2[arr2count].exp)
                {
                        ans[count].coeff = arr1[arr1count].coeff;
                        ans[count].exp = arr1[arr1count].exp;
                        arr1count++;
                        count++;
                }
        }

        printf("\nPolynomial 1:  ");
        for(i=1; i<=arr1[0].coeff; i++)
                printf("( %d, %d ) ", arr1[i].coeff, arr1[i].exp);

        printf("\nPolynomial 2:  ");
        for(i=1; i<=arr2[0].coeff; i++)
                printf("( %d, %d ) ", arr2[i].coeff, arr2[i].exp);

        printf("\nSummation:     ");
        for(i=0; i<count; i++)
                printf("( %d, %d ) ", ans[i].coeff, ans[i].exp);
        printf("\n");
}