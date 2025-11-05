/*************************************************************
 * 1. Name:
 *      Mason Allen & Hayden Olson
 * 2. Assignment Name:
 *      Practice 08: Allocation
 * 3. Assignment Description:
 *      Allocate an array and then use it
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

 /****************************
  * ALLOCATE ONE FLOAT
  ****************************/

float* allocateOneFloat(float number)
{
	float* p = new float(number);
	return p;
}

/****************************
 * ALLOCATE ARRAY of DOUBLEs
 ****************************/

double* allocateArrayDouble(int number)
{
	if (number <= 0)
	{
		return nullptr;
	}
	else
	{
		return new double[number];
	}
}

/****************************
 * DELETE ONE FLOAT
 ****************************/

void deleteOneFloat(float *number)
{
	if (number != nullptr)
	{
		delete number;
		number = nullptr;
	}
}

/****************************
 * DELETE ARRAY of DOUBLEs
 ****************************/

void deleteArrayDouble(double *number)
{
	if (number != nullptr)
	{
		delete[] number;
		number = nullptr;
	}
}