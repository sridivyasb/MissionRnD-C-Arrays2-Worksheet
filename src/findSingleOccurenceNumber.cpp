/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	int c;
	if (A == nullptr)
		return -1;
	for (int i = 0; i < len; i++){
		c = 0;
		for (int j = 0; j < len; j++){
			if (A[i] == A[j])
				c++;
		}
		if (c == 1)
			return A[i];
	}
}
