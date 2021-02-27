#include <stdio.h>
#include <stdbool.h>

int swap(int *num_a, int *num_b) {
	int holder = *num_a;
	*num_a = *num_b;
	*num_b = holder;
}

int bubble_sort(int array[], int length) {
	int loop1, loop2;
	bool swapped;
	for(loop1 = 0; loop1 < length - 1; loop1++) { // We stop at length-1 because the inner loop checks one element ahead anyway
		swapped = false;
		for(loop2 = 0; loop2 < length - loop1 - 1; loop2++) { // This loop checks the number from array position 0 and swaps if num ahead is smaller
			if(array[loop2] > array[loop2 + 1]) {
				swap(&array[loop2], &array[loop2 + 1]);
				swapped = true;
			}
		}
		// In the case the array is already sorted and no swaps have been made, cut the loop for speed
		if (swapped == false)
			break;
	}
	// You basically drag the largest element you find to the last position,
	// then the second largest element to the second-to-last position, etc.
	// Until you are back at position 0.
}

int main () {
	int num_array[50], array_length, i;
	puts("How long would you like your array to be?");
	scanf("%d", &array_length);
	
	puts("Enter your numbers.");
	for(i = 0; i < array_length; i++)
		scanf("%d", &num_array[i]);
	bubble_sort(num_array, array_length);
	
	puts("Sorted array:");
	for(i = 0; i < array_length; i++)
		printf("%d\t", num_array[i]);
	puts("Done!");
	return 0;
}
