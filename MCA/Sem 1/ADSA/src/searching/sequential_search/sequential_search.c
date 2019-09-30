#include <stdio.h>

const int ARRAY_SIZE = 5;

int main()
{        
        int i, search_element, result_idx, array[ARRAY_SIZE];

        system("clear");

        printf("Provide array elements: \n");
        for(i = 0; i < ARRAY_SIZE; i++)
        {
                printf("\t Element at index %2d: ", i);
                scanf("%d", &array[i]);
        }

        printf("Enter search element: ");
        scanf("%d", &search_element);

        result_idx = linear_search(array, ARRAY_SIZE, search_element);

        if(result_idx == -1)
                printf("Result: Element not found! \n");
        else
                printf("Result: Element found at index %d \n", result_idx);

        return 0;
}

int linear_search(      const int array[],
                        const int array_size,
                        const int search_element)
{
        int i;
        for(i = 0; i < array_size; i++)
                if(array[i] == search_element)
                        return i;
        return -1;
}