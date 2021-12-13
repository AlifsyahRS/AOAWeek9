#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono; // Chrono will be used to measure the time


void printArray(int arr[], int n){ // To show the results of the sort
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


void insertionSort(int arr[], int n){ // Insertion sort algorithm from GeeksForGeeks (Source: https://www.geeksforgeeks.org/insertion-sort/). Has an estimated time complexity of O(N^2)
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Source for merge sort: https://www.geeksforgeeks.org/merge-sort/
// Has an estimated time complexity of O(N(Log(N)))
void merge(int array[], int const left, int const mid, int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}




int main(){
    // Comparisons will be done from sizes 100 - 100000
    int* arrCaseOne = new int[100];
	int* arrCaseTwo = new int[1000];
	int* arrCaseThree = new int[10000];
	int* arrCaseFour = new int[100000];


    // Filling arrays with random values
    for(int i = 0; i < 100; i++){
		arrCaseOne[i] = rand() % 999;
	}

	for(int i = 0; i < 1000; i++){
		arrCaseTwo[i] = rand() % 999;
	}

	for(int i = 0 ; i < 10000; i++){
		arrCaseThree[i] = rand() % 999;
	}


	for(int i = 0 ; i < 100000 ; i++){
		arrCaseFour[i] = rand() % 999;
	}

    auto startInsertOne = steady_clock::now(); // Measuring time using std::chrono::steady_clock
	insertionSort(arrCaseOne, 100);
	auto endInsertOne = steady_clock::now();
	double timeInsertOne = double(duration_cast<nanoseconds>(endInsertOne-startInsertOne).count());
	cout << "Run time for case 1 of insertion sort (100 elements): " << timeInsertOne << " nanoseconds." << endl;

    auto startMergeOne = steady_clock::now();
	mergeSort(arrCaseOne, 0, 99);
	auto endMergeOne = steady_clock::now();
	double timeMergeOne = double(duration_cast<nanoseconds>(endMergeOne-startMergeOne).count());
	cout << "Run time for case 1 of merge sort sort (100 elements): " << timeMergeOne << " nanoseconds." << endl;
    
    auto startInsertTwo = steady_clock::now(); // Measuring time using std::chrono::steady_clock
	insertionSort(arrCaseTwo, 1000);
	auto endInsertTwo = steady_clock::now();
	double timeInsertTwo = double(duration_cast<nanoseconds>(endInsertTwo-startInsertTwo).count());
	cout << "Run time for case 2 of insertion sort (1000 elements): " << timeInsertTwo << " nanoseconds." << endl;

    auto startMergeTwo = steady_clock::now();
	mergeSort(arrCaseTwo, 0, 999);
	auto endMergeTwo = steady_clock::now();
	double timeMergeTwo = double(duration_cast<nanoseconds>(endMergeTwo-startMergeTwo).count());
	cout << "Run time for case 2 of merge sort sort (1000 elements): " << timeMergeTwo << " nanoseconds." << endl;
    
    auto startInsertThree = steady_clock::now(); // Measuring time using std::chrono::steady_clock
	insertionSort(arrCaseThree, 10000);
	auto endInsertThree = steady_clock::now();
	double timeInsertThree = double(duration_cast<nanoseconds>(endInsertThree-startInsertThree).count());
	cout << "Run time for case 3 of insertion sort (10000 elements): " << timeInsertThree << " nanoseconds." << endl;

    auto startMergeThree = steady_clock::now();
	mergeSort(arrCaseThree, 0, 9999);
	auto endMergeThree = steady_clock::now();
	double timeMergeThree = double(duration_cast<nanoseconds>(endMergeThree-startMergeThree).count());
	cout << "Run time for case 3 of merge sort sort (10000 elements): " << timeMergeThree << " nanoseconds." << endl;

    auto startInsertFour = steady_clock::now(); // Measuring time using std::chrono::steady_clock
	insertionSort(arrCaseFour, 100000);
	auto endInsertFour = steady_clock::now();
	double timeInsertFour = double(duration_cast<nanoseconds>(endInsertFour-startInsertFour).count());
	cout << "Run time for case 4 of insertion sort (100000 elements): " << timeInsertFour << " nanoseconds." << endl;

    auto startMergeFour = steady_clock::now();
	mergeSort(arrCaseFour, 0, 99999);
	auto endMergeFour = steady_clock::now();
	double timeMergeFour = double(duration_cast<nanoseconds>(endMergeFour-startMergeFour).count());
	cout << "Run time for case 4 of merge sort sort (100000 elements): " << timeMergeFour << " nanoseconds." << endl;


    return 0;
}

 