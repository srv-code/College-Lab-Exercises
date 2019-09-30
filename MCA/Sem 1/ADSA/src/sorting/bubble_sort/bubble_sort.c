#include <stdio.h>

void print_array(       const int array[],
                        const int array_size)
{
        int i;
        for(i=0; i < array_size; i++)
                printf("[%2d]  %d \n", i, array[i]);
}

void bubble_sort(       int array[],
                        const int array_size)
{
        int i, j, temp;
        for(i=0; i < array_size; i++)
                for(j=0; j < array_size-i; j++)
                        if(array[j] > array[j+1])
                        {
                                // swapping array elements
                                temp = array[j];
                                array[j] = array[j+1];
                                array[j+1] = temp;
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

        bubble_sort(array, ARRAY_SIZE);

        printf("Array after sorting: \n");
        print_array(array, ARRAY_SIZE);


        return 0;
}