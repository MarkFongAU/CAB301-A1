//Normal bubble sort
#include <iostream>
#include <fstream>
#include<time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>     /* srand, rand */
using namespace std;

long long int NormalBubbleSort(int*, int);

int main()
{
	//Timer
	clock_t start;
	long double duration; //Duration of the execution of the algorithm

	int size; //Array size
	long long int basic; //basic operation count

	//Open textfile
	ofstream myfile;

    //An array of sample set sizes
    int setSizes[] = {
        2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,
        4000,4000,4000,4000,4000,4000,4000,4000,4000,4000,
        6000,6000,6000,6000,6000,6000,6000,6000,6000,6000,
        8000,8000,8000,8000,8000,8000,8000,8000,8000,8000,
        10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
        12000,12000,12000,12000,12000,12000,12000,12000,12000,12000,
        14000,14000,14000,14000,14000,14000,14000,14000,14000,14000,
        16000,16000,16000,16000,16000,16000,16000,16000,16000,16000,
        18000,18000,18000,18000,18000,18000,18000,18000,18000,18000,
        20000,20000,20000,20000,20000,20000,20000,20000,20000,20000,
        22000,22000,22000,22000,22000,22000,22000,22000,22000,22000,
        24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,
        26000,26000,26000,26000,26000,26000,26000,26000,26000,26000,
        28000,28000,28000,28000,28000,28000,28000,28000,28000,28000,
        30000,30000,30000,30000,30000,30000,30000,30000,30000,30000,
        32000,32000,32000,32000,32000,32000,32000,32000,32000,32000,
        34000,34000,34000,34000,34000,34000,34000,34000,34000,34000,
        36000,36000,36000,36000,36000,36000,36000,36000,36000,36000,
        38000,38000,38000,38000,38000,38000,38000,38000,38000,38000,
        40000,40000,40000,40000,40000,40000,40000,40000,40000,40000
    };
	//Open file
	myfile.open("BubbleNormal.txt", ios::out | ios::ate | ios::app);
	//Check is file is open
	if (myfile.is_open())
	{
		myfile << "Case " << endl;
		myfile << "Basic" << "\t\t\t\t" << "Time(seconds)" << endl;
		myfile.close();
	}
	else cout << "Unable to open file";

	for (int i = 0; i < 200; i++)
	{
		size = setSizes[i];
		//Create dynamic array
		int *A = new int[size];

		//Set srand seed
		srand(time(NULL));

		//Insert random numbers from 1-RANDMAX into the array
		for (int j = 0; j < size; j++)
		{
			A[j] = rand() % RAND_MAX + 1;
		}

		cout << "An array of size " << size << " with random numbers has been created." << endl;

		//Display the array (for checking), commented out
//        for (int k = 0; k < size; k++)
//        {
//            cout << A[k] << ",";
//        }
//        cout << endl;

		//Start timer
		start = clock();

		/* Algorithm execution begins */
		//Returns total number of basic operation
		basic = NormalBubbleSort(A, size);
		/* Algorithm execution ends */

		//End timer
		duration = (clock() - start) / (long double)CLOCKS_PER_SEC;

		cout << "Algorithm's basic operation count: " << basic << endl;
		cout << "Algorithm's execution time in seconds: " << duration << endl;
		cout << endl;
		//Display the array (for checking), commented out
//        for (int l = 0; l < size; l++)
//        {
//            cout << A[l] << ",";
//        }

		//Remove Dynamic array
		delete[] A; // use array delete to deallocate array
		A = NULL;

		//Open file
		myfile.open("BubbleNormal.txt", ios::out | ios::ate | ios::app);
		//Check is file is open
		if (myfile.is_open())
		{
			myfile << basic << "\t\t\t\t" << duration << endl;
			myfile.close();
		}
		else cout << "Unable to open file";
		Sleep(1000);
	}
	return 0;
}

long long int NormalBubbleSort(int *A, int size)
{
	//Basic operation count
	long long int basic = 0;

	//Loop through the array
	for (int i = 0; i <= size - 2; i++)
	{
		for (int j = 0; j <= size - 2 - i; j++)
		{
			//Increment basic
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

