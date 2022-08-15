
#include <stdlib.h>

# This code is the unique and singular work of ALEX EPSTEIN, 836435
# except where lines are attributed to other sources :) 

class TreapNode {
	public:
		
		TreapNode(float pr, uint64_t val) {
			priority = pr;
			data = val;
		};
		void insert(uint64_t elem);
		void delet(uint32_t key);
		uint64_t search(uint32_t key);
		
		TreapNode* l = 0;
		TreapNode* r = 0;
		float priority;
		uint64_t data;
		
	private:
		
		int bubble_up();
		int bubble_down();
		void left_rotate(TreapNode* rightchild);
		void right_rotate(TreapNode* leftchild);
};
		
		





