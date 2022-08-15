
#include <stdlib.h>
#include <stdio.h>

# This code is the unique and singular work of ALEX EPSTEIN, 836435
# except where lines are attributed to other sources :) 

class DynamicArrayA {
	public:
		DynamicArrayA() {};
		void pushback(uint64_t x); // Synonymous with insert
		void delet(uint32_t key);
		uint64_t search(uint32_t key);
		void print_arr();
	private:
		uint32_t search_idx(uint32_t key);
		uint64_t* arr = (uint64_t*) malloc(sizeof(uint64_t));
		uint32_t elems = 0;  // equivalent to small n
		uint32_t length = 1; // equivalent to big N
		uint64_t* resize(float factor);
};

		