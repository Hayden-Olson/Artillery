/*************************************************************
 * 1. Name:
 *      Hayden Olson & Mason Allen
 * 2. Assignment Name:
 *      Practice 09: Pointer Arithmetic
 * 3. Assignment Description:
 *      Traverse a string using pointer notation
 * 4. What was the hardest part? Be as specific as possible.
 *      -The end conditions for the loops were tricky to figure out. 
 *		The countArray function needed an end condition specified,
 *		needing the strlen function to determine the length of the string.
 *		The countPointer function needed to check for the null terminator
 *		which it does on its own when dereferencing the pointer.
 * 5. How long did it take for you to complete the assignment?
 *      -2 hours
 **************************************************************/


/**************************************
 * COUNT - ARRAY
 **************************************/
inline char countArray(char* text, char letter)
{
	int result = 0;
	for (int count = 0; count < strlen(text); count++)
	{
		if (text[count] == letter)
		{
			result++;
		}
	}
	return result;
}

/**************************************
 * COUNT - POINTER
 **************************************/
inline char countPointer(char* text, char letter)
{
	int result = 0;
	for (char* ptr = text; *ptr; ptr++)
	{
		if (*ptr == letter)
		{
			result++;
		}
	}
	return result;
}