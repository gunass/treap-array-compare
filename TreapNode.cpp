
#include "TreapNode.h"
#include <time.h>
#include "DataGenerator.h"
#include <stdio.h>

# This code is the unique and singular work of ALEX EPSTEIN, 836435
# except where lines are attributed to other sources :) 


uint64_t TreapNode::search(uint32_t key) {
	uint32_t this_key = key_of(data);
	
	if (key == this_key) {
		return data;
	}
	
	if (key < this_key) {
		if (l) {
			return l->search(key);
		} else {
			return 0;
		}
	}
	
	if (key > this_key) {
		if (r) {
			return r->search(key);
		} else {
			return 0;
		}
	}
	
	return 0;
}

float random_priority() {
	//srand((unsigned) time(&t));
	// Copied code from link
	// https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c
	return ((float)rand()/(float)(RAND_MAX)) * 1;;

}


void TreapNode::insert(uint64_t elem) {
	
	uint32_t this_key = key_of(data);
	uint32_t elem_key = key_of(elem);
	
	
	if (this_key == elem_key) {
		// Break key ties using id
		this_key = id_of(data);
		elem_key = id_of(elem);
	}
	
	if (elem_key < this_key) {
		if (l) {
			l->insert(elem);
		} else {
			l = new TreapNode(random_priority(), elem);
		}
	} 
	if (elem_key > this_key) {
		if (r) {
			r->insert(elem);
		} else {
			r = new TreapNode(random_priority(), elem);
		}
	}

	bubble_up();
	
	return;
	
}

void TreapNode::delet(uint32_t key) {
	
	uint32_t this_key = key_of(data);
	
	if (key == this_key) {
		priority = 2.0;
		this->bubble_down();
	}
	
	if (key < this_key) {
		if (l) {
			l->delet(key);
		} else {
			return;
		}
	}
	
	if (key > this_key) {
		if (r) {
			r->delet(key);
		} else  {
			return;
		}
	}
}


int TreapNode::bubble_up() {

	// This method is called by the PARENT node of the new node
	// If the child is a leaf assume its priority = infinity

	float l_pr = l ? l->priority : 2.0;
	float r_pr = r ? r->priority : 2.0;
	
	if (l_pr == r_pr) return 1;
	
	
	// Else find the smaller child and bubble it up
	if (l_pr < r_pr && l_pr < priority) {
		this->right_rotate(l);
		return 0;
	} else if (l_pr > r_pr && r_pr < priority) {
		this->left_rotate(r);
		return 0;
	} else {
		return 1;
	}
	return 1;
}

void TreapNode::right_rotate(TreapNode* leftchild) {
	//Basically a swap operation--called by the PARENT node
	//Store the old values of the parent
	float parent_pr = priority;
	uint64_t parent_data = data;
	TreapNode* parent_r = r;
	TreapNode* child_r = leftchild->r;
	
	//Parent' ~= leftchild
	//Parent'.r = Parent
	//Parent'.l = leftchild.l
	//Parent'.r.l = leftchild.r
	//Parent'.r.r = Parent.r
	
	priority = leftchild->priority;
	data = leftchild->data;
	l = leftchild->l;
	r = new TreapNode(parent_pr, parent_data);
	r->r = parent_r;
	r->l = child_r;

	return;
}

void TreapNode::left_rotate(TreapNode* rightchild) {
	//Reverse of above
	float parent_pr = priority;
	uint64_t parent_data = data;
	TreapNode* parent_l = l;
	TreapNode* child_l = rightchild->l;
	
	priority = rightchild->priority;
	data = rightchild->data;
	r = rightchild->r;
	l = new TreapNode(parent_pr, parent_data);
	l->l = parent_l;
	l->r = child_l;

	return;
	
}

int TreapNode::bubble_down() {
	//This method is called by the node selected for deletion
	//Its priority is already guaranteed to be 2.0 = infinity

	// Base case: node is now a leaf
	if (!r && !l) {
		return 1;
	}
	
	if (!r) {
		right_rotate(l);
		if (r->bubble_down()) r = NULL;
		return 0;
	}
	if (!l) {
		left_rotate(r);
		if (l->bubble_down()) l = NULL;
		return 0;
	}
	
	if (r->priority > l->priority) {
		right_rotate(l);
		if (r->bubble_down()) r = NULL;
		return 0;
	} else {
		left_rotate(r);
		if (l->bubble_down()) l = NULL;
		return 0;
	}
	
	return 0;
	
}













