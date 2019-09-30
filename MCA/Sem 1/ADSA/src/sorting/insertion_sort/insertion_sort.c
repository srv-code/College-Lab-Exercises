#include <stdio.h>

void print_array(       const int array[],
                        const int array_size)
{
        int i;
        for(i=0; i < array_size; i++)
                printf("[%2d]  %d \n", i, array[i]);
}

void insertion_sort(    int array[],
                        const int array_size)
{
        int i, j, element_to_insert;
        for(i = 1; i < array_size; i++)
        {
                element_to_insert = array[i];
                for(j = i-1; j >= 0; j--)
                        if(element_to_insert < array[j])
                                // shift current element to right
                                array[j+1] = array[j];
                        else
                                break;
                array[j+1] = element_to_insert;
        }
}

int main()
{
        const int ARRAY_SIZE = 5;
        int i, array[ARRAY_SIZE];

        system("clear");

        printf("Enter array values: \n");
        for(i=0; i < ARRAY_SIZE; i++)
        {
                printf("\t Enter element %2d: ", i);
                scanf("%d", &array[i]);
        }

        printf("Array before sorting: \n");
        print_array(array, ARRAY_SIZE);

        insertion_sort(array, ARRAY_SIZE);

        printf("Array after sorting: \n");
        print_array(array, ARRAY_SIZE);


        return 0;
}