#include <stdio.h>

int binary_search(      const int array[],
                        const int low_idx,
                        const int high_idx,
                        const int search_element)
{
        if(high_idx >= low_idx)
        {
                int mid_idx = low_idx + (high_idx - low_idx) / 2;
                
                if(array[mid_idx] == search_element)
                       return mid_idx;
               
                if(search_element > array[mid_idx]) 
                       return binary_search(array, mid_idx+1, high_idx, search_element);
                
                return binary_search(array, low_idx, mid_idx-1, search_element);
        }	

        return -1;
}


int main()
{
        const int ARRAY_SIZE = 5;
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
		
		printf("\n\n");

        result_idx = binary_search(array, 0, ARRAY_SIZE-1, search_element);

        if(result_idx == -1)
                printf("Result: Element not found! \n");
        else
                printf("Result: Element found at index %d \n", result_idx);

        return 0;
}