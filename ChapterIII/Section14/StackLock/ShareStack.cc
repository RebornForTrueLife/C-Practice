/********************************************
 * ShareStack - define a class provide a way to share 
 * a stack that only one instance can use at a time
 * Uage: 
	- run object file
	- the program will print out the ShareStack's services
 ********************************************/

#include <iostream>
#include <string>

// MODE
#define CODING		// coding mode
// #undef CODING		// turn off coding mode


// CLASS DECLARE
// a class that allow its instance share a single stack one at a time
class ShareStack {
private:
	static std::string stack;	// the stack, declare as string for simplicity
	static bool state;		// the state of stack, TRUE means stack is being used
	static int key;			// the key to check when unlock stack
	static int count;			// the number of instances have been created, no decrease when destroy instance
	const int INDEX;		// index for an instance, unchangable after created

public:
	// constructor
	ShareStack();
	
	// destructor
	// ~ShareStack();	// let it default

	// to use the stack after check if the stack is available
	void use_stack(void);

	// to lock the stack
	void lock(void);

	// to unlock the stack
	void unlock(void);
};	// close ShareStack


// main
int main(int argc, char const *argv[]) {
	// print the instruction
	std::cout << "The program is used to define class: ShareStack\n";
	// print ShareStack's services
	std::cout << "ShareStack provide some services:\n";
	std::cout << "\t1. Use stack when stack is available\n";
	std::cout << "\t2. Lock the stack after using the stack\n";
	std::cout << "\t3. Unlock the stack for others can use\n";
	// coding mode
	#ifdef CODING
		ShareStack user1;
		ShareStack user2;
		user1.use_stack();
		user1.lock();
		user2.use_stack();
		user2.unlock();
		user1.unlock();
		user2.use_stack();
	#endif // CODING
	return 0;
}	// end  main 


// INITIALIZE STATIC and CONST 
std::string ShareStack::stack = "STACK";
bool ShareStack::state = false;	// stack is available
int ShareStack::key = 0;			// stack is unlocked
int ShareStack::count = 0;		


// IMPLEMENT

// // CLASS ShareStack

/*	constructor */
ShareStack::ShareStack(void) : INDEX((ShareStack::count) + 1) {
	count += 1; 		// increase count by 1
}	// close constructor


void ShareStack::use_stack(void) {
	// check if stack is free
	if (state == false)
		std::cout << "ACCESSED STACK\n";
	else
		std::cout << "DENY USING, the stack is not available now\n";
}	// close use_stack


void ShareStack::lock(void) {
	// check if the stack is locked
	if (state == true)
		std::cout << "The stack is being used, LOCK is denied\n";
	else {	// the stack is free
		state = true;
		key = INDEX;
		std::cout << "The stack is locked successfully\n";
	}	// close if
}	// close lock


void ShareStack::unlock(void) {
	// check if the stack is free
	if (state == false)
		std::cout << "The stack is already available\n";
	else {
		// check if the instance is allowed to unlock
		if (INDEX != key) 
			std::cout << "This instance is not allowed to unlock stack, "
						<<"only the instance that locked can unlock now\n";
		else {
			state = false;
			key = 0;
			std::cout << "The stack is unlocked successfully\n";
		}	// close if 1					
	}	// close if
}	// close unlock