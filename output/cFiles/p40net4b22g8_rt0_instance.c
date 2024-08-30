#include<stdio.h>
#include <stdlib.h>
int nondet_Int();
//problem definition
//state
int n = 9102;
char state[9102];
//reserve state[0] to always be false
int nextIndex = 1;
//objects
int object[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83};
int pipe[] = {31, 32, 33, 34};
int area[] = {27, 28, 29, 30};
int product[] = {0, 1, 2, 3, 4};
int batch_atom[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
int tank_slot[] = {35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83};
//predicates
int connect[84][84][84];
int unitary[84];
int not_unitary[84];
int last[84][84];
int first[84][84];
int follow[84][84];
int is_product[84][84];
int on[84][84];
int may_interface[84][84];
int normal[84];
int push_updating[84];
int pop_updating[84];
int tank_slot_product_location[84][84][84];
int occupied[84];
int not_occupied[84];
int equals[84][84];

//get index functions
int getIndex_connect(int x0, int x1, int x2, int set){
	int index;
	if(connect[x0][x1][x2] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			connect[x0][x1][x2] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = connect[x0][x1][x2];
	}
	return index;
}
int getIndex_unitary(int x0, int set){
	int index;
	if(unitary[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			unitary[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = unitary[x0];
	}
	return index;
}
int getIndex_not_unitary(int x0, int set){
	int index;
	if(not_unitary[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			not_unitary[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = not_unitary[x0];
	}
	return index;
}
int getIndex_last(int x0, int x1, int set){
	int index;
	if(last[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			last[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = last[x0][x1];
	}
	return index;
}
int getIndex_first(int x0, int x1, int set){
	int index;
	if(first[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			first[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = first[x0][x1];
	}
	return index;
}
int getIndex_follow(int x0, int x1, int set){
	int index;
	if(follow[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			follow[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = follow[x0][x1];
	}
	return index;
}
int getIndex_is_product(int x0, int x1, int set){
	int index;
	if(is_product[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			is_product[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = is_product[x0][x1];
	}
	return index;
}
int getIndex_on(int x0, int x1, int set){
	int index;
	if(on[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			on[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = on[x0][x1];
	}
	return index;
}
int getIndex_may_interface(int x0, int x1, int set){
	int index;
	if(may_interface[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			may_interface[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = may_interface[x0][x1];
	}
	return index;
}
int getIndex_normal(int x0, int set){
	int index;
	if(normal[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			normal[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = normal[x0];
	}
	return index;
}
int getIndex_push_updating(int x0, int set){
	int index;
	if(push_updating[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			push_updating[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = push_updating[x0];
	}
	return index;
}
int getIndex_pop_updating(int x0, int set){
	int index;
	if(pop_updating[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			pop_updating[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = pop_updating[x0];
	}
	return index;
}
int getIndex_tank_slot_product_location(int x0, int x1, int x2, int set){
	int index;
	if(tank_slot_product_location[x0][x1][x2] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			tank_slot_product_location[x0][x1][x2] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = tank_slot_product_location[x0][x1][x2];
	}
	return index;
}
int getIndex_occupied(int x0, int set){
	int index;
	if(occupied[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			occupied[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = occupied[x0];
	}
	return index;
}
int getIndex_not_occupied(int x0, int set){
	int index;
	if(not_occupied[x0] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			not_occupied[x0] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = not_occupied[x0];
	}
	return index;
}
int getIndex_equals(int x0, int x1, int set){
	int index;
	if(equals[x0][x1] < 0){
		if(set){
			if(nextIndex >= n) {
				exit(-1);
			}
			index = nextIndex;
			nextIndex += 1;
			equals[x0][x1] = index;
		}
		else{
			index = 0;
		}
	}
	else{
		index = equals[x0][x1];
	}
	return index;
}

//actions functions
void push(int pipe, int batch_atom_in, int from_area, int to_area, int first_batch_atom, int product_batch_atom_in, int product_first_batch, int from_slot, int last_batch_atom, int next_last_batch_atom, int product_last_batch, int to_slot){
	if(state[getIndex_not_unitary(pipe, 0)] && state[getIndex_connect(from_area, to_area, pipe, 0)] && state[getIndex_first(first_batch_atom, pipe, 0)] && state[getIndex_on(batch_atom_in, from_area, 0)] && state[getIndex_is_product(batch_atom_in, product_batch_atom_in, 0)] && state[getIndex_is_product(first_batch_atom, product_first_batch, 0)] && state[getIndex_may_interface(product_batch_atom_in, product_first_batch, 0)] && state[getIndex_tank_slot_product_location(from_slot, product_batch_atom_in, from_area, 0)] && state[getIndex_occupied(from_slot, 0)] && state[getIndex_last(last_batch_atom, pipe, 0)] && state[getIndex_follow(last_batch_atom, next_last_batch_atom, 0)] && state[getIndex_is_product(last_batch_atom, product_last_batch, 0)] && state[getIndex_tank_slot_product_location(to_slot, product_last_batch, to_area, 0)] && state[getIndex_not_occupied(to_slot, 0)]){
		state[getIndex_first(first_batch_atom, pipe, 1)] = 0;
		state[getIndex_on(batch_atom_in, from_area, 1)] = 0;
		state[getIndex_occupied(from_slot, 1)] = 0;
		state[getIndex_follow(last_batch_atom, next_last_batch_atom, 1)] = 0;
		state[getIndex_last(last_batch_atom, pipe, 1)] = 0;
		state[getIndex_not_occupied(to_slot, 1)] = 0;
		state[getIndex_first(batch_atom_in, pipe, 1)] = 1;
		state[getIndex_follow(first_batch_atom, batch_atom_in, 1)] = 1;
		state[getIndex_not_occupied(from_slot, 1)] = 1;
		state[getIndex_last(next_last_batch_atom, pipe, 1)] = 1;
		state[getIndex_on(last_batch_atom, to_area, 1)] = 1;
		state[getIndex_occupied(to_slot, 1)] = 1;
	}
	return;
}
void pop(int pipe, int batch_atom_in, int from_area, int to_area, int last_batch_atom, int product_batch_atom_in, int product_last_batch, int from_slot, int first_batch_atom, int next_first_batch_atom, int product_first_batch, int to_slot){
	if(state[getIndex_not_unitary(pipe, 0)] && state[getIndex_connect(from_area, to_area, pipe, 0)] && state[getIndex_last(last_batch_atom, pipe, 0)] && state[getIndex_on(batch_atom_in, to_area, 0)] && state[getIndex_is_product(batch_atom_in, product_batch_atom_in, 0)] && state[getIndex_is_product(last_batch_atom, product_last_batch, 0)] && state[getIndex_may_interface(product_batch_atom_in, product_last_batch, 0)] && state[getIndex_tank_slot_product_location(from_slot, product_batch_atom_in, to_area, 0)] && state[getIndex_occupied(from_slot, 0)] && state[getIndex_first(first_batch_atom, pipe, 0)] && state[getIndex_follow(next_first_batch_atom, first_batch_atom, 0)] && state[getIndex_tank_slot_product_location(to_slot, product_first_batch, from_area, 0)] && state[getIndex_not_occupied(to_slot, 0)]){
		state[getIndex_last(last_batch_atom, pipe, 1)] = 0;
		state[getIndex_on(batch_atom_in, to_area, 1)] = 0;
		state[getIndex_occupied(from_slot, 1)] = 0;
		state[getIndex_follow(next_first_batch_atom, first_batch_atom, 1)] = 0;
		state[getIndex_first(first_batch_atom, pipe, 1)] = 0;
		state[getIndex_not_occupied(to_slot, 1)] = 0;
		state[getIndex_last(batch_atom_in, pipe, 1)] = 1;
		state[getIndex_follow(batch_atom_in, last_batch_atom, 1)] = 1;
		state[getIndex_not_occupied(from_slot, 1)] = 1;
		state[getIndex_first(next_first_batch_atom, pipe, 1)] = 1;
		state[getIndex_on(first_batch_atom, from_area, 1)] = 1;
		state[getIndex_occupied(to_slot, 1)] = 1;
	}
	return;
}
void push_unitarypipe(int pipe, int batch_atom_in, int from_area, int to_area, int first_batch_atom, int product_batch_atom_in, int product_first_batch, int from_slot, int to_slot){
	if(state[getIndex_first(first_batch_atom, pipe, 0)] && state[getIndex_connect(from_area, to_area, pipe, 0)] && state[getIndex_on(batch_atom_in, from_area, 0)] && state[getIndex_unitary(pipe, 0)] && state[getIndex_is_product(batch_atom_in, product_batch_atom_in, 0)] && state[getIndex_is_product(first_batch_atom, product_first_batch, 0)] && state[getIndex_may_interface(product_batch_atom_in, product_first_batch, 0)] && state[getIndex_tank_slot_product_location(from_slot, product_batch_atom_in, from_area, 0)] && state[getIndex_occupied(from_slot, 0)] && state[getIndex_tank_slot_product_location(to_slot, product_first_batch, to_area, 0)] && state[getIndex_not_occupied(to_slot, 0)]){
		state[getIndex_first(first_batch_atom, pipe, 1)] = 0;
		state[getIndex_last(first_batch_atom, pipe, 1)] = 0;
		state[getIndex_on(batch_atom_in, from_area, 1)] = 0;
		state[getIndex_occupied(from_slot, 1)] = 0;
		state[getIndex_not_occupied(to_slot, 1)] = 0;
		state[getIndex_first(batch_atom_in, pipe, 1)] = 1;
		state[getIndex_last(batch_atom_in, pipe, 1)] = 1;
		state[getIndex_not_occupied(from_slot, 1)] = 1;
		state[getIndex_on(first_batch_atom, to_area, 1)] = 1;
		state[getIndex_occupied(to_slot, 1)] = 1;
	}
	return;
}
void pop_unitarypipe(int pipe, int batch_atom_in, int from_area, int to_area, int first_batch_atom, int product_batch_atom_in, int product_first_batch, int from_slot, int to_slot){
	if(state[getIndex_first(first_batch_atom, pipe, 0)] && state[getIndex_connect(from_area, to_area, pipe, 0)] && state[getIndex_on(batch_atom_in, to_area, 0)] && state[getIndex_unitary(pipe, 0)] && state[getIndex_is_product(batch_atom_in, product_batch_atom_in, 0)] && state[getIndex_is_product(first_batch_atom, product_first_batch, 0)] && state[getIndex_may_interface(product_batch_atom_in, product_first_batch, 0)] && state[getIndex_tank_slot_product_location(to_slot, product_batch_atom_in, to_area, 0)] && state[getIndex_occupied(to_slot, 0)] && state[getIndex_tank_slot_product_location(from_slot, product_first_batch, from_area, 0)] && state[getIndex_not_occupied(from_slot, 0)]){
		state[getIndex_last(first_batch_atom, pipe, 1)] = 0;
		state[getIndex_first(first_batch_atom, pipe, 1)] = 0;
		state[getIndex_on(batch_atom_in, to_area, 1)] = 0;
		state[getIndex_occupied(to_slot, 1)] = 0;
		state[getIndex_not_occupied(from_slot, 1)] = 0;
		state[getIndex_last(batch_atom_in, pipe, 1)] = 1;
		state[getIndex_first(batch_atom_in, pipe, 1)] = 1;
		state[getIndex_not_occupied(to_slot, 1)] = 1;
		state[getIndex_on(first_batch_atom, from_area, 1)] = 1;
		state[getIndex_occupied(from_slot, 1)] = 1;
	}
	return;
}
//main loop
int main(){
	//setting connect to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			for(int i2 = 0; i2 < 84; i2++){
				connect[i0][i1][i2] = -1;
			}
		}
	}
	//setting unitary to -1
	for(int i0 = 0; i0 < 84; i0++){
		unitary[i0] = -1;
	}
	//setting not_unitary to -1
	for(int i0 = 0; i0 < 84; i0++){
		not_unitary[i0] = -1;
	}
	//setting last to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			last[i0][i1] = -1;
		}
	}
	//setting first to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			first[i0][i1] = -1;
		}
	}
	//setting follow to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			follow[i0][i1] = -1;
		}
	}
	//setting is_product to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			is_product[i0][i1] = -1;
		}
	}
	//setting on to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			on[i0][i1] = -1;
		}
	}
	//setting may_interface to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			may_interface[i0][i1] = -1;
		}
	}
	//setting normal to -1
	for(int i0 = 0; i0 < 84; i0++){
		normal[i0] = -1;
	}
	//setting push_updating to -1
	for(int i0 = 0; i0 < 84; i0++){
		push_updating[i0] = -1;
	}
	//setting pop_updating to -1
	for(int i0 = 0; i0 < 84; i0++){
		pop_updating[i0] = -1;
	}
	//setting tank_slot_product_location to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			for(int i2 = 0; i2 < 84; i2++){
				tank_slot_product_location[i0][i1][i2] = -1;
			}
		}
	}
	//setting occupied to -1
	for(int i0 = 0; i0 < 84; i0++){
		occupied[i0] = -1;
	}
	//setting not_occupied to -1
	for(int i0 = 0; i0 < 84; i0++){
		not_occupied[i0] = -1;
	}
	//setting equals to -1
	for(int i0 = 0; i0 < 84; i0++){
		for(int i1 = 0; i1 < 84; i1++){
			equals[i0][i1] = -1;
		}
	}
	state[getIndex_normal(31, 1)] = 1;
	state[getIndex_normal(32, 1)] = 1;
	state[getIndex_normal(33, 1)] = 1;
	state[getIndex_normal(34, 1)] = 1;
	state[getIndex_may_interface(0, 0, 1)] = 1;
	state[getIndex_may_interface(1, 1, 1)] = 1;
	state[getIndex_may_interface(2, 2, 1)] = 1;
	state[getIndex_may_interface(3, 3, 1)] = 1;
	state[getIndex_may_interface(4, 4, 1)] = 1;
	state[getIndex_may_interface(0, 1, 1)] = 1;
	state[getIndex_may_interface(1, 0, 1)] = 1;
	state[getIndex_may_interface(0, 3, 1)] = 1;
	state[getIndex_may_interface(3, 0, 1)] = 1;
	state[getIndex_may_interface(0, 4, 1)] = 1;
	state[getIndex_may_interface(4, 0, 1)] = 1;
	state[getIndex_may_interface(0, 2, 1)] = 1;
	state[getIndex_may_interface(2, 0, 1)] = 1;
	state[getIndex_may_interface(1, 2, 1)] = 1;
	state[getIndex_may_interface(2, 1, 1)] = 1;
	state[getIndex_may_interface(1, 3, 1)] = 1;
	state[getIndex_may_interface(3, 1, 1)] = 1;
	state[getIndex_may_interface(1, 4, 1)] = 1;
	state[getIndex_may_interface(4, 1, 1)] = 1;
	state[getIndex_may_interface(3, 4, 1)] = 1;
	state[getIndex_may_interface(4, 3, 1)] = 1;
	state[getIndex_connect(27, 28, 31, 1)] = 1;
	state[getIndex_connect(27, 29, 32, 1)] = 1;
	state[getIndex_connect(29, 30, 33, 1)] = 1;
	state[getIndex_connect(28, 29, 34, 1)] = 1;
	state[getIndex_tank_slot_product_location(35, 0, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(36, 0, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(37, 0, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(38, 1, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(39, 1, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(40, 2, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(41, 3, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(42, 3, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(43, 3, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(44, 4, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(45, 4, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(46, 4, 27, 1)] = 1;
	state[getIndex_tank_slot_product_location(47, 0, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(48, 0, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(49, 0, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(50, 1, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(51, 1, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(52, 2, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(53, 3, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(54, 3, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(55, 3, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(56, 4, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(57, 4, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(58, 4, 28, 1)] = 1;
	state[getIndex_tank_slot_product_location(59, 0, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(60, 0, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(61, 0, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(62, 1, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(63, 1, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(64, 2, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(65, 2, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(66, 3, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(67, 3, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(68, 3, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(69, 4, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(70, 4, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(71, 4, 29, 1)] = 1;
	state[getIndex_tank_slot_product_location(72, 0, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(73, 0, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(74, 0, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(75, 1, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(76, 1, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(77, 2, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(78, 3, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(79, 3, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(80, 3, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(81, 4, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(82, 4, 30, 1)] = 1;
	state[getIndex_tank_slot_product_location(83, 4, 30, 1)] = 1;
	state[getIndex_is_product(5, 4, 1)] = 1;
	state[getIndex_is_product(6, 0, 1)] = 1;
	state[getIndex_is_product(7, 3, 1)] = 1;
	state[getIndex_is_product(8, 1, 1)] = 1;
	state[getIndex_is_product(9, 1, 1)] = 1;
	state[getIndex_is_product(10, 0, 1)] = 1;
	state[getIndex_is_product(11, 3, 1)] = 1;
	state[getIndex_is_product(12, 4, 1)] = 1;
	state[getIndex_is_product(13, 1, 1)] = 1;
	state[getIndex_is_product(14, 3, 1)] = 1;
	state[getIndex_is_product(15, 0, 1)] = 1;
	state[getIndex_is_product(16, 2, 1)] = 1;
	state[getIndex_is_product(17, 4, 1)] = 1;
	state[getIndex_is_product(18, 4, 1)] = 1;
	state[getIndex_is_product(19, 2, 1)] = 1;
	state[getIndex_is_product(20, 3, 1)] = 1;
	state[getIndex_is_product(21, 0, 1)] = 1;
	state[getIndex_is_product(22, 1, 1)] = 1;
	state[getIndex_is_product(23, 3, 1)] = 1;
	state[getIndex_is_product(24, 0, 1)] = 1;
	state[getIndex_is_product(25, 3, 1)] = 1;
	state[getIndex_is_product(26, 4, 1)] = 1;
	state[getIndex_on(5, 30, 1)] = 1;
	state[getIndex_occupied(83, 1)] = 1;
	state[getIndex_on(7, 30, 1)] = 1;
	state[getIndex_occupied(80, 1)] = 1;
	state[getIndex_on(8, 29, 1)] = 1;
	state[getIndex_occupied(63, 1)] = 1;
	state[getIndex_on(9, 29, 1)] = 1;
	state[getIndex_occupied(62, 1)] = 1;
	state[getIndex_on(10, 30, 1)] = 1;
	state[getIndex_occupied(74, 1)] = 1;
	state[getIndex_on(12, 27, 1)] = 1;
	state[getIndex_occupied(46, 1)] = 1;
	state[getIndex_on(13, 27, 1)] = 1;
	state[getIndex_occupied(39, 1)] = 1;
	state[getIndex_on(14, 30, 1)] = 1;
	state[getIndex_occupied(79, 1)] = 1;
	state[getIndex_on(16, 29, 1)] = 1;
	state[getIndex_occupied(65, 1)] = 1;
	state[getIndex_on(19, 29, 1)] = 1;
	state[getIndex_occupied(64, 1)] = 1;
	state[getIndex_on(20, 28, 1)] = 1;
	state[getIndex_occupied(55, 1)] = 1;
	state[getIndex_on(23, 28, 1)] = 1;
	state[getIndex_occupied(54, 1)] = 1;
	state[getIndex_on(25, 27, 1)] = 1;
	state[getIndex_occupied(43, 1)] = 1;
	state[getIndex_on(26, 30, 1)] = 1;
	state[getIndex_occupied(82, 1)] = 1;
	state[getIndex_not_occupied(37, 1)] = 1;
	state[getIndex_not_occupied(36, 1)] = 1;
	state[getIndex_not_occupied(35, 1)] = 1;
	state[getIndex_not_occupied(38, 1)] = 1;
	state[getIndex_not_occupied(40, 1)] = 1;
	state[getIndex_not_occupied(42, 1)] = 1;
	state[getIndex_not_occupied(41, 1)] = 1;
	state[getIndex_not_occupied(45, 1)] = 1;
	state[getIndex_not_occupied(44, 1)] = 1;
	state[getIndex_not_occupied(49, 1)] = 1;
	state[getIndex_not_occupied(48, 1)] = 1;
	state[getIndex_not_occupied(47, 1)] = 1;
	state[getIndex_not_occupied(51, 1)] = 1;
	state[getIndex_not_occupied(50, 1)] = 1;
	state[getIndex_not_occupied(52, 1)] = 1;
	state[getIndex_not_occupied(53, 1)] = 1;
	state[getIndex_not_occupied(58, 1)] = 1;
	state[getIndex_not_occupied(57, 1)] = 1;
	state[getIndex_not_occupied(56, 1)] = 1;
	state[getIndex_not_occupied(61, 1)] = 1;
	state[getIndex_not_occupied(60, 1)] = 1;
	state[getIndex_not_occupied(59, 1)] = 1;
	state[getIndex_not_occupied(68, 1)] = 1;
	state[getIndex_not_occupied(67, 1)] = 1;
	state[getIndex_not_occupied(66, 1)] = 1;
	state[getIndex_not_occupied(71, 1)] = 1;
	state[getIndex_not_occupied(70, 1)] = 1;
	state[getIndex_not_occupied(69, 1)] = 1;
	state[getIndex_not_occupied(73, 1)] = 1;
	state[getIndex_not_occupied(72, 1)] = 1;
	state[getIndex_not_occupied(76, 1)] = 1;
	state[getIndex_not_occupied(75, 1)] = 1;
	state[getIndex_not_occupied(77, 1)] = 1;
	state[getIndex_not_occupied(78, 1)] = 1;
	state[getIndex_not_occupied(81, 1)] = 1;
	state[getIndex_first(6, 31, 1)] = 1;
	state[getIndex_follow(11, 6, 1)] = 1;
	state[getIndex_last(11, 31, 1)] = 1;
	state[getIndex_first(22, 32, 1)] = 1;
	state[getIndex_follow(15, 22, 1)] = 1;
	state[getIndex_last(15, 32, 1)] = 1;
	state[getIndex_first(17, 33, 1)] = 1;
	state[getIndex_last(17, 33, 1)] = 1;
	state[getIndex_first(21, 34, 1)] = 1;
	state[getIndex_follow(18, 21, 1)] = 1;
	state[getIndex_follow(24, 18, 1)] = 1;
	state[getIndex_last(24, 34, 1)] = 1;
	state[getIndex_not_unitary(31, 1)] = 1;
	state[getIndex_not_unitary(32, 1)] = 1;
	state[getIndex_unitary(33, 1)] = 1;
	state[getIndex_not_unitary(34, 1)] = 1;
	state[getIndex_equals(0, 0, 1)] = 1;
	state[getIndex_equals(1, 1, 1)] = 1;
	state[getIndex_equals(2, 2, 1)] = 1;
	state[getIndex_equals(3, 3, 1)] = 1;
	state[getIndex_equals(4, 4, 1)] = 1;
	state[getIndex_equals(5, 5, 1)] = 1;
	state[getIndex_equals(6, 6, 1)] = 1;
	state[getIndex_equals(7, 7, 1)] = 1;
	state[getIndex_equals(8, 8, 1)] = 1;
	state[getIndex_equals(9, 9, 1)] = 1;
	state[getIndex_equals(10, 10, 1)] = 1;
	state[getIndex_equals(11, 11, 1)] = 1;
	state[getIndex_equals(12, 12, 1)] = 1;
	state[getIndex_equals(13, 13, 1)] = 1;
	state[getIndex_equals(14, 14, 1)] = 1;
	state[getIndex_equals(15, 15, 1)] = 1;
	state[getIndex_equals(16, 16, 1)] = 1;
	state[getIndex_equals(17, 17, 1)] = 1;
	state[getIndex_equals(18, 18, 1)] = 1;
	state[getIndex_equals(19, 19, 1)] = 1;
	state[getIndex_equals(20, 20, 1)] = 1;
	state[getIndex_equals(21, 21, 1)] = 1;
	state[getIndex_equals(22, 22, 1)] = 1;
	state[getIndex_equals(23, 23, 1)] = 1;
	state[getIndex_equals(24, 24, 1)] = 1;
	state[getIndex_equals(25, 25, 1)] = 1;
	state[getIndex_equals(26, 26, 1)] = 1;
	state[getIndex_equals(27, 27, 1)] = 1;
	state[getIndex_equals(28, 28, 1)] = 1;
	state[getIndex_equals(29, 29, 1)] = 1;
	state[getIndex_equals(30, 30, 1)] = 1;
	state[getIndex_equals(31, 31, 1)] = 1;
	state[getIndex_equals(32, 32, 1)] = 1;
	state[getIndex_equals(33, 33, 1)] = 1;
	state[getIndex_equals(34, 34, 1)] = 1;
	state[getIndex_equals(35, 35, 1)] = 1;
	state[getIndex_equals(36, 36, 1)] = 1;
	state[getIndex_equals(37, 37, 1)] = 1;
	state[getIndex_equals(38, 38, 1)] = 1;
	state[getIndex_equals(39, 39, 1)] = 1;
	state[getIndex_equals(40, 40, 1)] = 1;
	state[getIndex_equals(41, 41, 1)] = 1;
	state[getIndex_equals(42, 42, 1)] = 1;
	state[getIndex_equals(43, 43, 1)] = 1;
	state[getIndex_equals(44, 44, 1)] = 1;
	state[getIndex_equals(45, 45, 1)] = 1;
	state[getIndex_equals(46, 46, 1)] = 1;
	state[getIndex_equals(47, 47, 1)] = 1;
	state[getIndex_equals(48, 48, 1)] = 1;
	state[getIndex_equals(49, 49, 1)] = 1;
	state[getIndex_equals(50, 50, 1)] = 1;
	state[getIndex_equals(51, 51, 1)] = 1;
	state[getIndex_equals(52, 52, 1)] = 1;
	state[getIndex_equals(53, 53, 1)] = 1;
	state[getIndex_equals(54, 54, 1)] = 1;
	state[getIndex_equals(55, 55, 1)] = 1;
	state[getIndex_equals(56, 56, 1)] = 1;
	state[getIndex_equals(57, 57, 1)] = 1;
	state[getIndex_equals(58, 58, 1)] = 1;
	state[getIndex_equals(59, 59, 1)] = 1;
	state[getIndex_equals(60, 60, 1)] = 1;
	state[getIndex_equals(61, 61, 1)] = 1;
	state[getIndex_equals(62, 62, 1)] = 1;
	state[getIndex_equals(63, 63, 1)] = 1;
	state[getIndex_equals(64, 64, 1)] = 1;
	state[getIndex_equals(65, 65, 1)] = 1;
	state[getIndex_equals(66, 66, 1)] = 1;
	state[getIndex_equals(67, 67, 1)] = 1;
	state[getIndex_equals(68, 68, 1)] = 1;
	state[getIndex_equals(69, 69, 1)] = 1;
	state[getIndex_equals(70, 70, 1)] = 1;
	state[getIndex_equals(71, 71, 1)] = 1;
	state[getIndex_equals(72, 72, 1)] = 1;
	state[getIndex_equals(73, 73, 1)] = 1;
	state[getIndex_equals(74, 74, 1)] = 1;
	state[getIndex_equals(75, 75, 1)] = 1;
	state[getIndex_equals(76, 76, 1)] = 1;
	state[getIndex_equals(77, 77, 1)] = 1;
	state[getIndex_equals(78, 78, 1)] = 1;
	state[getIndex_equals(79, 79, 1)] = 1;
	state[getIndex_equals(80, 80, 1)] = 1;
	state[getIndex_equals(81, 81, 1)] = 1;
	state[getIndex_equals(82, 82, 1)] = 1;
	state[getIndex_equals(83, 83, 1)] = 1;
	//decision variables
	int actionDecision;
	int index0;
	int index1;
	int index2;
	int index3;
	int index4;
	int index5;
	int index6;
	int index7;
	int index8;
	int index9;
	int index10;
	int index11;
	//main loop
	while(1 == 1){
		//choose action
		actionDecision = nondet_Int();
		switch(actionDecision){
		case 1:
 			index0 = nondet_Int();
			if(index0 >= 0 && index0 < 4){
				index1 = nondet_Int();
				if(index1 >= 0 && index1 < 22){
					index2 = nondet_Int();
					if(index2 >= 0 && index2 < 4){
						index3 = nondet_Int();
						if(index3 >= 0 && index3 < 4){
							index4 = nondet_Int();
							if(index4 >= 0 && index4 < 22){
								index5 = nondet_Int();
								if(index5 >= 0 && index5 < 5){
									index6 = nondet_Int();
									if(index6 >= 0 && index6 < 5){
										index7 = nondet_Int();
										if(index7 >= 0 && index7 < 49){
											index8 = nondet_Int();
											if(index8 >= 0 && index8 < 22){
												index9 = nondet_Int();
												if(index9 >= 0 && index9 < 22){
													index10 = nondet_Int();
													if(index10 >= 0 && index10 < 5){
														index11 = nondet_Int();
														if(index11 >= 0 && index11 < 49){
															push(pipe[index0], batch_atom[index1], area[index2], area[index3], batch_atom[index4], product[index5], product[index6], tank_slot[index7], batch_atom[index8], batch_atom[index9], product[index10], tank_slot[index11]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 2:
 			index0 = nondet_Int();
			if(index0 >= 0 && index0 < 4){
				index1 = nondet_Int();
				if(index1 >= 0 && index1 < 22){
					index2 = nondet_Int();
					if(index2 >= 0 && index2 < 4){
						index3 = nondet_Int();
						if(index3 >= 0 && index3 < 4){
							index4 = nondet_Int();
							if(index4 >= 0 && index4 < 22){
								index5 = nondet_Int();
								if(index5 >= 0 && index5 < 5){
									index6 = nondet_Int();
									if(index6 >= 0 && index6 < 5){
										index7 = nondet_Int();
										if(index7 >= 0 && index7 < 49){
											index8 = nondet_Int();
											if(index8 >= 0 && index8 < 22){
												index9 = nondet_Int();
												if(index9 >= 0 && index9 < 22){
													index10 = nondet_Int();
													if(index10 >= 0 && index10 < 5){
														index11 = nondet_Int();
														if(index11 >= 0 && index11 < 49){
															pop(pipe[index0], batch_atom[index1], area[index2], area[index3], batch_atom[index4], product[index5], product[index6], tank_slot[index7], batch_atom[index8], batch_atom[index9], product[index10], tank_slot[index11]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 3:
 			index0 = nondet_Int();
			if(index0 >= 0 && index0 < 4){
				index1 = nondet_Int();
				if(index1 >= 0 && index1 < 22){
					index2 = nondet_Int();
					if(index2 >= 0 && index2 < 4){
						index3 = nondet_Int();
						if(index3 >= 0 && index3 < 4){
							index4 = nondet_Int();
							if(index4 >= 0 && index4 < 22){
								index5 = nondet_Int();
								if(index5 >= 0 && index5 < 5){
									index6 = nondet_Int();
									if(index6 >= 0 && index6 < 5){
										index7 = nondet_Int();
										if(index7 >= 0 && index7 < 49){
											index8 = nondet_Int();
											if(index8 >= 0 && index8 < 49){
												push_unitarypipe(pipe[index0], batch_atom[index1], area[index2], area[index3], batch_atom[index4], product[index5], product[index6], tank_slot[index7], tank_slot[index8]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 4:
 			index0 = nondet_Int();
			if(index0 >= 0 && index0 < 4){
				index1 = nondet_Int();
				if(index1 >= 0 && index1 < 22){
					index2 = nondet_Int();
					if(index2 >= 0 && index2 < 4){
						index3 = nondet_Int();
						if(index3 >= 0 && index3 < 4){
							index4 = nondet_Int();
							if(index4 >= 0 && index4 < 22){
								index5 = nondet_Int();
								if(index5 >= 0 && index5 < 5){
									index6 = nondet_Int();
									if(index6 >= 0 && index6 < 5){
										index7 = nondet_Int();
										if(index7 >= 0 && index7 < 49){
											index8 = nondet_Int();
											if(index8 >= 0 && index8 < 49){
												pop_unitarypipe(pipe[index0], batch_atom[index1], area[index2], area[index3], batch_atom[index4], product[index5], product[index6], tank_slot[index7], tank_slot[index8]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		}
		//check if goal state reached
		if(state[getIndex_on(8, 30, 0)] && state[getIndex_on(10, 27, 0)] && state[getIndex_on(11, 28, 0)] && state[getIndex_on(12, 29, 0)] && state[getIndex_on(15, 27, 0)] && state[getIndex_on(21, 30, 0)] && state[getIndex_on(22, 27, 0)] && state[getIndex_on(25, 29, 0)] && state[getIndex_normal(31, 0)] && state[getIndex_normal(32, 0)] && state[getIndex_normal(33, 0)] && state[getIndex_normal(34, 0)]){
			__CPROVER_assert(1 == 0, "GOAL CHECKER: FAIL MEANS PLAN FOUND");
		}
	}
}
