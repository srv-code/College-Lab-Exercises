#include <stdio.h>

const int ARRAY_SIZE = 8;

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

        result_idx = binary_search(array, ARRAY_SIZE, search_element);

        if(result_idx == -1)
                printf("Result: Element not found! \n");
        else
                printf("Result: Element found at index %d \n", result_idx);

        return 0;
}

int binary_search(      const int array[],
                        const int array_size,
                        const int search_element)
{
        int low_idx = 0, high_idx = array_size - 1, mid_idx;

        while(low_idx <= high_idx)
        {
                // printf("    [low=%d | high=%d | mid=%d] \n", low_idx, high_idx, mid_idx); // DEBUG

                mid_idx = (low_idx + high_idx) / 2;
                
                if(array[mid_idx] == search_element)
                        return mid_idx;
                if(search_element > array[mid_idx])
                        low_idx = mid_idx + 1;
                else
                        high_idx = mid_idx - 1;
        }

        return -1;
}