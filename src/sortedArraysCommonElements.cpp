/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <iostream>

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int Equal(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return 0;
		s1++;
		s2++;
	}
	if (!(*s1 || *s2))
		return 1;
	else
		return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	struct transaction *result = NULL;
	int i, j, RLength = 0;
	for (i = 0; i < ALen && A != NULL; i++)
	{
		for (j = i; j < BLen && B != NULL; j++)
		{
			if (Equal(A[i].date, B[j].date))
			{
				RLength++;
				result = (struct transaction *)realloc(result, RLength*sizeof(struct transaction));
				result[RLength - 1] = A[i];
			}
		}
	}
	return result;
}
