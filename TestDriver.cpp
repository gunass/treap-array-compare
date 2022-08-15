
// Data Generator Test Driver
#include <iostream>
#include <string>
#include "DataGenerator.h"
#include "DynamicArrayA.h"
#include "TreapNode.h"

uint32_t LIMIT = 5;

int main() {
	
	DataGenerator d;
	DynamicArrayA a;
	TreapNode t(2.0,0);
	
	for (int i = 0; i < LIMIT; i++) {
		Generation operation = d.gen_insertion();
		short opcode = (short) operation.op;
		uint64_t val = operation.val;
		uint32_t e_id = id_of(val);
		uint32_t e_key = key_of(val);
		
		printf("Op %d, on id %d, key %d\n", opcode, e_id, e_key);
		
		//a.pushback(val);
		//a.print_arr();
		t.insert(val);
	}
	
	for (int i = 0; i < LIMIT; i++) {
		Generation operation = d.gen_deletion();
		short opcode = (short) operation.op;
		uint64_t val = operation.val;
		uint32_t e_id = id_of(val);
		uint32_t e_key = key_of(val);
		
		printf("Op %d, key %d\n", opcode, e_key);
		
		t.delet(e_key);
		//a.delet(e_key);
		//a.print_arr();
	}
	
	for (int i = 0; i < LIMIT; i++) {
		Generation operation = d.gen_search();
		short opcode = (short) operation.op;
		uint64_t val = operation.val;
		uint32_t e_id = id_of(val);
		uint32_t e_key = key_of(val);
		
		printf("Op %d, key %d\n", opcode, e_key);
		
		//printf("%d\n", a.search(e_key));
	}
	
	return 0;
}









