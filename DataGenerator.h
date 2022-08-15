
#include <stdlib.h>
#include <time.h>

# This code is the unique and singular work of ALEX EPSTEIN, 836435
# except where lines are attributed to other sources :) 

struct Generation {
	// Return type for calls to gen_ functions = 9 bytes constant
	char op;
	uint64_t val;
};

class DataGenerator {
	public:
		DataGenerator() {
			time_t t;
			srand((unsigned) time(&t));
			};
		uint64_t gen_element();
		Generation gen_insertion();
		Generation gen_deletion();
		Generation gen_search();
	private:
		// Array to store generated elements - ID is index and key is value
		uint32_t elems[1000001];
		
		// Next ID and procedure to generate random key with limit
		uint32_t id_next = 1;
		uint32_t max_key = 10000001;
		uint32_t rand_key(uint32_t limit);
};

// Data elements are formatted as unsigned long ints 
// Largest 4 bytes = ID, smallest 4 bytes = key
// Same size as a pointer and faster to use
uint32_t id_of(uint64_t element);
uint32_t key_of(uint64_t element);