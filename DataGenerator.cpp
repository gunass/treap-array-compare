
#include "DataGenerator.h"
#include <iostream>

# This code is the unique and singular work of ALEX EPSTEIN, 836435
# except where lines are attributed to other sources :) 

uint32_t id_of(uint64_t element) {
	// Return the largest 4 bytes of the element = id
	return element >> 32;
}

uint32_t key_of(uint64_t element) {
	// Return the smallest 4 bytes of the element = key
	return element & 0x00000000FFFFFFFF;
}

uint32_t DataGenerator::rand_key(uint32_t limit) {
	// Generates a random uint32 between (0, limit)
	uint32_t r = rand() % limit;
	return ( r );
}

uint64_t DataGenerator::gen_element() {
	// Generate a random key for the next element and increment id_next
	uint64_t elem = ((uint64_t) id_next << 32) + (rand_key(max_key));
	elems[id_next] = key_of(elem);
	
	id_next++;	
	return elem;
}

Generation DataGenerator::gen_insertion() {
	
	// Insertion for a randomly generated element
	
	Generation g = {
		.op = (char) 1,
		.val = gen_element()
	};
	
	// 
	
	return g;
	
}

Generation DataGenerator::gen_deletion() {
	// Deletion for a random element within generated ids
	uint32_t rand_id = rand_key(id_next);
	uint64_t val;
	
	if (elems[rand_id]) {
		// If there is an element with the generated ID return key and zero out
		val = (uint64_t) elems[rand_id];
		elems[rand_id] = 0;
	} else {
		// If element has already been zeroed out, return random ID
		val = rand_key(max_key);
	}
	
	Generation g = {
		.op = (char) 2,
		.val = (uint64_t) val
	};
	
	return g;
}

Generation DataGenerator::gen_search() {
	// Search for a random key
	
	Generation g = {
		.op = (char) 3,
		.val = (uint64_t) rand_key(max_key)
	};
	
	return g;
}










	