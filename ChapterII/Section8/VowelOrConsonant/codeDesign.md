
# Code design

## Data

### Input
- Info about alphabet in ascii table: decimal code of alphabet both upper case and lower case are in range [65, 90] and [97, 122]
- A constant list of vowel VOWEL_LIST = {a, e, i, o, u}
- The characters in the rest of the alphabet are consonants
- Input character: a char: [c]

### Output
- The result of checking whether [c] is a vowel or a consonant or not in alphabet

## Code flow

1. main
	> `Print` instruction of the program

	> `Ask` user to enter [c]

	> `Run`  checking whether [c] is a vowel, a consonant or not in alphabet

	> `Print` out the result

2. check
- *This function will check if a character is a vowel, a consonant or not in alphabet by return 2, 1, 0 respectively*

	> `Take` a char [c]

	> `Check` if [c] in alphabet ~ in range [65, 90] and [97, 122]

		> If true,  `Check` if [c] <= 90 then `convert` [c] into range [97, 122] by adding to [c] by (97 - 65)

		> `Check` if [c] in VOWEL_LIST:

			> If true: [c] is a vowel, `Return` 2

			> If false: [c] is a consonant, `Return` 1

	> `Return`  0, cuz [c] is not in alphabet