#include <stdio.h>

void print_array(       const int array[],
                        const int array_size)
{
        int i;
        for(i=0; i < array_size; i++)
                printf("[%2d]  %d \n", i, array[i]);
}

void exchange_sort(     int array[],
                        const int array_size)
{
        int i, j, temp;
        for(i=0; i < array_size-1; i++)
                for(j=i+1; j < array_size; j++)
                        if(array[i] > array[j])
                        {
                                // swapping array elements
                                temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
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

        exchange_sort(array, ARRAY_SIZE);

        printf("Array after sorting: \n");
        print_array(array, ARRAY_SIZE);


        return 0;
}