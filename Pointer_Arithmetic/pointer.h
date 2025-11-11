/*************************************************************
 * 1. Name:
 *      Hayden Olson & Mason Allen
 * 2. Assignment Name:
 *      Practice 09: Pointer Arithmetic
 * 3. Assignment Description:
 *      Traverse a string using pointer notation
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
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
	for (char* ptr = text; ptr != NULL; ptr++)
	{
		if (*ptr == letter)
		{
			result++;
		}
	}
	return result;
}