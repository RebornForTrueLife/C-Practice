
# Code design

## Data
0. Used data
	1. Airline
		- Fields:
			1. number: flight number, an long int
			2. oriPort : originating airport code, a string [3]
			3. desPort: destination airport code, a string [3]
			4. depTime: departure time, integer array [hour], [minute]
			5. arrTime:  arrival time, integer array [hour], [minute]
		- Methods:
			1. check_ori: from a given [list of Airline(planes)], return a list of airline(planes) that leave from the given [oriPort]

	2. PlaneList: 
		- Fields:
			1. array: array of Airline with max size = PLANE_SIZE
			2. size: actual size of list

	3. CONST:
		- PLANE_SIZE = 10: the number of plane in array of Airline
		- CODE_SIZE = 4

1. Input
	- [oriPort1], [oriPort2] : 2 originating airport codes
	- [planeList] : list of plane

2. Output
	- print out the list of planes that leave from 2 input airports

## Code flow
1. main
	> `Print` program's instruction

	> `Call` func to initialize a [list of Airline]

	> `Print` the number of airline in the [list of Airline]

	> `Ask` user to enter 2 originating airport code

	> `Find` list of planes that leave from [oriPort1] and [oriPort2]

	> `Print` out the list just found

2. check_ori
	- an operator for Airline data to check if a given airline leave from the input oriPort code

	> `Take` [airline], [oriPort]
	
	> `Compare` [oriPort of [airline]] with the [oriPort]:

		> `If` SAME: `return` TRUE

	> `return` FALSE

3. find_plane
	- given a  list of airline(plane), return the list of airline that leave from 2 given oriPort

	> `Take` [listPlane], [oriPort1], [oriPort2]

	> `Declare` [list] of PlaneList, [size] = 0

	> `For each` [plane] in [listPlane]:

		> `check` if [plane].ori is equal to [oriPort1] or [oriPort2]:

			> `Put` [plane] into [list].array

			> `Increment` [list].size by 1

	> `return` [list]

4. initial_plane_list
	- to initialize list of plane

	> `Take` [list] of PlaneList

	> `For each` [plane] from 1 to 10:
		
		> `Put` information to each [plane] in [list]

		> `Increment` [list].size by 1

