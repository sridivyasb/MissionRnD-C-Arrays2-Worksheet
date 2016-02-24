/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int day, month, year, dayarray, montharray,yeararray;
	day = date[0] * 10 + date[1];
	month = date[3] * 10 + date[4];
	year = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9];
	int i = 0, c = 0;
	while (i < len)
	{
		yeararray = Arr[i].date[6] * 1000 + Arr[i].date[7] * 100 + Arr[i].date[8] * 10 + Arr[i].date[9];
		if (yeararray > year)
		{
			c++;
			i++;
		}
		else if (yeararray == year)
		{
			montharray = Arr[i].date[3] * 10 + Arr[i].date[4];
			if (montharray > month)
			{
				c++;
				i++;
			}
			else if (montharray == month)
			{
				dayarray = Arr[i].date[0] * 10 + Arr[i].date[1];
				if (dayarray > day)
				{
					c++;
					i++;
				}
				else
					i++;
			}
			else
				i++;
		}
		else
			i++;
	}
	return c;
}
