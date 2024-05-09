#include <stdio.h>
#include <stdlib.h> // Required for malloc and free
#include <unistd.h> // Required for sleep function

#define MEGABYTE 1048576 // 1 MB = 1024 * 1024 bytes

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <size_in_MB> [block_size_MB] [timer_in_seconds]\n", argv[0]);
        return 1; // Exit with an error if size in MB is not provided
    }

    int size_MB = atoi(argv[1]); // Convert the first argument to an integer
    int block_size_MB;

    if (argc >= 3)
    {
        block_size_MB = atoi(argv[2]); // Convert the first argument to an integer
    }
    else if (size_MB >= 128)
    {
        block_size_MB = 128;
    }
    else
    {
        block_size_MB = 1;
    }

    if (size_MB <= 0)
    {
        printf("Invalid size in MB. Please provide a positive integer for total memory allocation.\n");
        return 1; // Exit with an error if the provided size is not valid
    }
    if (block_size_MB <= 0)
    {
        printf("Invalid size in MB. Please provide a positive integer for block size.\n");
        return 1; // Exit with an error if the provided size is not valid
    }

    // Calculate the number of integers needed to fill 'size_MB' MB of memory
    long int size_bytes = size_MB * MEGABYTE;                     // Convert MB to bytes
    long int block_size_bytes = block_size_MB * MEGABYTE;         // Convert block size MB to bytes
    long int num_elements = size_bytes / sizeof(int);             // Calculate number of integers
    long int block_num_elements = block_size_bytes / sizeof(int); // Calculate number of integers

    // Input elements (integers) into the array
    printf("=====%ld %ld %ld %ld====\n", size_bytes, block_size_bytes, num_elements, block_num_elements); // DEBUG

    printf("Filling %d MB of allocated memory\n", size_MB);

    for (long int i = 0; i < (size_MB / block_size_MB); i++)
    {
        // printf("%ld %ld %ld\n", num_elements, block_num_elements, num_elements / block_num_elements); //DEBUG
        int *arr = (int *)malloc(block_num_elements * sizeof(int)); // Allocate memory for the array
        if (arr == NULL)
        {
            printf("Memory allocation failed. Exiting...\n");
            return 1; // Exit with an error if memory allocation fails
        }
        else
        {
            for (long int i = 0; i < block_num_elements; i++)
            {
                arr[i] = 1; // Fill the array with sequential integers
            }
            printf("%ld MB Memory filled ...\n", (i + 1) * block_size_MB);
        }
    }

    printf("=================================================\n");
    printf("%d MB Memory filled successfully.\n", size_MB);

    // Check if a timer duration is provided as the second argument
    if (argc >= 4)
    {
        int timer_seconds = atoi(argv[3]); // Convert the second argument to an integer
        if (timer_seconds > 0)
        {
            printf("Waiting for %d seconds before freeing memory...\n", timer_seconds);
            sleep(timer_seconds); // Pause execution for the specified duration
        }
    }
    else
    {
        // If no timer argument is provided, wait for user input
        printf("Press Enter to free memory...");
        while (getchar() != '\n')
            ; // Wait for the user to press Enter
    }

    // Free the dynamically allocated memory
    // free(arr);

    return 0;
}