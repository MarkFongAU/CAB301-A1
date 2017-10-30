//Both bubble sort
#include <iostream>
#include <fstream>
#include<time.h>
#include <stdlib.h>     /* srand, rand */
using namespace std;

long long int BubbleSortEfficient(int*, int); //Efficient
long long int BubbleSortNormal(int*, int); //Normal
int main()
{

	clock_t start;//Timer
	long double duration; //Duration of the execution of the algorithm

	int size; //Array size
	long long int basic; //basic operation count

	//Open textfile
	ofstream myfile;

	//Open file
	myfile.open("BubbleTest.txt", ios::out | ios::ate | ios::app);
	//Check is file is open
	if (myfile.is_open())
	{
		myfile << "Case " << endl;
		myfile << "Basic" << "\t\t" << "Time(seconds)" << endl;
		myfile.close();
	}
	else cout << "Unable to open file";

	//Create dynamic array
	size = 40000;
	int *A = new int[size];

	//Set srand seed
	srand(time(NULL));

	//Insert random numbers from 1-100 into the array
	for (int j = 0; j < size; j++)
	{
		A[j] = rand() % 100 + 1;
	}
	cout << "An array of size " << size << " with random numbers has been created." << endl;

	//Display the array (for checking)
	for (int k = 0; k < size; k++)
	{
		cout << A[k] << ",";
	}
	cout << endl;

	//Start timer
	start = clock();

	/* Algorithm execution begins */
	//Returns total number of basic operation
	basic = BubbleSortEfficient(A, size);
	/* Algorithm execution ends */

	//End timer
	duration = (clock() - start) / (long double)CLOCKS_PER_SEC;

	cout << "Algorithm's basic operation count: " << basic << endl;
	cout << "Algorithm's execution time in seconds: " << duration << endl;
	cout << endl;
	//Display the array (for checking)
	for (int l = 0; l < size; l++)
	{
		cout << A[l] << ",";
	}

	//Remove Dynamic array
	delete[] A; // use array delete to deallocate array
	A = NULL;

	//Open file
	myfile.open("BubbleTest.txt", ios::out | ios::ate | ios::app);
	//Check is file is open
	if (myfile.is_open())
	{
		myfile << basic << "\t\t" << duration << endl;
		myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}

//Normal bubble sort
long long int BubbleSortNormal(int *A, int size)
{
	//Basic operation count
	long long int basic = 0;

	//Loop through the array
	for (int i = 0; i <= size - 2; i++)
	{
		for (int j = 0; j <= size - 2 - i; j++)
		{
			//Increment basic operation
			basic++;
			//If element after current is smaller than current,
			//it means the array is not ascending
			if (A[j + 1] < A[j])
			{
				//Swap places
				int temp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = temp;
			}
		}
	}
	return basic;
}

//Efficient bubble sort
long long int BubbleSortEfficient(int *A, int size)
{
	//Basic operation count
	long long int basic = 0;

	//Counter for number of adjacent pairs to be compared
	int count = size - 1;

	//Swap flag
	bool sflag = true;

	//Loop through the array
	while (sflag)
	{
		sflag = false;
		for (int j = 0; j <= count - 1; j++)
		{
			//Increment basic operation
			basic++;
			//If element after current is smaller than current,
			//it means the array is not ascending
			if (A[j + 1] < A[j])
			{
				//Swap places
				int temp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = temp;
				//Swap flag to true
				sflag = true;
			}
		}
		//Decrement counter
		count--;
	}
	return basic;
}

