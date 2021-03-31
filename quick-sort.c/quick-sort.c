#include <stdio.h>

int swap(int *num_a, int *num_b) {
	int holder = *num_a;
	*num_a = *num_b;
	*num_b = holder;
}

/* 1. Takes last element as pivot
 * 2. Places pivot element at its correct position in sorted array
 * 3. Places all elements smaller than pivot element to the left of pivot element
 * 4. Places all elements larger than pivot element to the right of pivot element
 * NOTE that pivot is called when low is smaller than high.
 */
int partition(int array[], int low, int high) {
	// Pivot is element that will be placed at the right.
	int pivot = array[high];
	
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++) {
		if (array[j] < pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return(i + 1);
}

// Quick sort picks an element as pivot and partitions around this pivot.
// It recursively calls itself
void quick_sort(int array[], int low, int high) {
	if (low < high) {
		int partition_index = partition(array, low, high);
		quick_sort(array, low, partition_index - 1);
		quick_sort(array, partition_index + 1, high);
	}
}

int main () {
	int num_array[50], array_length, i;
	puts("How long would you like your array to be?");
	scanf("%d", &array_length);
	
	puts("Enter your numbers.");
	for(i = 0; i < array_length; i++)
		scanf("%d", &num_array[i]);
	
	
	quick_sort(num_array, 0, array_length - 1);
	
	puts("Sorted array:");
	for(i = 0; i < array_length; i++)
		printf("%d\t", num_array[i]);
	puts("Done!");
	return 0;
}
