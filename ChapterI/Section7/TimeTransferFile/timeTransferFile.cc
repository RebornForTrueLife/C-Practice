/********************************************
 * timeTransferFile.o - calculate time transfering for a file given its size
 * 
 * Uage - Run the object file
 * 			- Enter file size which is a float
 * 			- The program will print out the time needed to transfer that file
 ********************************************/

#include <iostream>


// Data
const int transferSpeed = 960; 		// number of character(a byte) can be transfer in a second
int timeReturn[3];							// global variable to return time array format


// Function to calculate time transfer
int calTimeTransfer(float fileSize) {
	int second;			// time needed to transfer
	// convert fileSize in MB to B
	// cuz fileSize is in megabyte = 1024 ^ 2 bytes
	fileSize *= 1024 * 1024;
	// calculate and return the time needed to transfer the file
	second = fileSize / transferSpeed;
	return second;
}	//end calTimeTransfer


// Fucntion to convert time in second into time in [hour:minute:second] format
int* convertTime(int second) {
	int hour; 				// hour
	int min;					// minute
	// calculate hour
	hour = second / 3600;		// 1 hour = 3600 secs
	second -= hour * 3600;		// number of seconds left after removing hours
	// calculate minute
	min = second / 60;				// 1 min = 60 secs
	second -= min * 60;
	// return result
	timeReturn[0] = hour;
	timeReturn[1] = min;
	timeReturn[2] = second;
	return timeReturn;
}	//end convertTime


// main
int main(int argc, char const *argv[]) {
	float fileSize;			// the size of file in MB
	int second;			// the time needed to transfer
	// Print the instruction to the user
	std::cout << "The program is used to calculate the time needed to transfer a file\n";
	std::cout << "The default transfer speed is: 960 characters/second\n";
	// Ask user to enter file size
	std::cout << "Enter the file size in MB(megabytes): ";
	std::cin >> fileSize;
	// calculate time needed
	second = calTimeTransfer(fileSize);
	// print out result
	// // convert into hour:min:second format
	convertTime(second);
	std::cout << "Time needed to transfer the file with size " << fileSize << " MB is [hour : min: second]: " 
						<< timeReturn[0] << " : " << timeReturn[1]  << " : " << timeReturn[2] << " \n"; 
	return 0;
}	// end  main 