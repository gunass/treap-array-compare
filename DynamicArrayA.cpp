
#include "DynamicArrayA.h"
#include "DataGenerator.h"

# This code is the unique and singular work of ALEX EPSTEIN, 836435
# except where lines are attributed to other sources :) 

uint64_t* DynamicArrayA::resize(float factor) {
	// Create a new array with size original*factor
	uint32_t to_size = factor*length;
	length = to_size;
	uint64_t* arr_new = (uint64_t*) malloc(to_size * sizeof(uint64_t));
	
	// Replace each element into the new array
	for (uint32_t j = 0; j <= elems; j++) {
		arr_new[j] = arr[j];
	}
	
	free(arr);
	
	return arr_new;
}

void DynamicArrayA::print_arr() {
	
}


void DynamicArrayA::pushback(uint64_t x) {
	// Pushback to insert element x
	arr[elems++] = x;
	if (elems == length) {
		arr = resize(2);
	}
}

uint32_t DynamicArrayA::search_idx(uint32_t key) {
	// Linear scan over array to find key
	for (uint32_t i = 0; i <= elems; i++) {
		if (key_of(arr[i]) == key) {
			return i;
		}
	}
	return -1;
}

void DynamicArrayA::delet(uint32_t key) {
	int i = search_idx(key);
	
	if (i == -1) {
		return;
	}
	
	
	elems--;
	// Swap element to delete with end of array
	uint64_t tmp = arr[i];
	arr[i] = arr[elems];
	arr[elems] = tmp;
	
	// Resize if too small after
	if (elems <= (length * 0.25)) {
		arr = resize(0.5);
	}
}
	

uint64_t DynamicArrayA::search(uint32_t key) {
	int i = search_idx(key);
	// Search for key and if it exists, return entire element
	
	if (i == -1) {
		return 0;
		
	} else {
		return arr[i];
	}
}


	
	
	
	
	
	
	
		