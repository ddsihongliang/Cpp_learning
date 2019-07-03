/********************************************************    
    Review of C++. 
    6/29/2019
    arrays as parameter in function
    and dynamic arrays
 ********************************************************/
#include<iostream>
using namespace std;

typedef int* IntArrayPtr;
const int MAX_NUM_SCORES = 20;

void fill_up(int array[], int size);
// size is the declared max size of array[]
// the user will type-in any numbers of data
// and this function will pass those data into the array[].

void print_result(const int array[], int size);
// size is the declared size of array[]
// the const int array[] is added as a precaution.
// this function will print the data stored in array[].

void sort(int array[], int size);
// size is the declared size of array[]
// the data stored in array[] will be sorted from low to high.

int main(void)
{
    int numUsed; // Fixed size to prevent overfloating 
    cout << "This program sorts int number from low to high.\n"
         << "How many numbers do you want? ";
    cin  >> numUsed;

    if (numUsed > MAX_NUM_SCORES)
    {
        cout << "Error! Cannot hold more than 20 numbers!\n";
        return 0;
    }

    IntArrayPtr scores = new int[numUsed]; // Initialize new Dynamic array.

    fill_up(scores,numUsed);
    sort(scores, numUsed);
    print_result(scores, numUsed);
    
    delete [] scores; // Free-up space after use. 
    return 0;
}

void fill_up(int array[], int size)
{
    //uses iostream
    int next, index = 0;
    cout << "Enter up to "<< size << " numbers: \n"
         << "End with a negtive input.\n";
    cin >> next;
    while (index < size && next >= 0) 
    {
        array[index] = next;
        cin >> next;
        index++;
    }
}

void print_result(const int array[], int size)
{
    //uses iostream
    cout << "The sorted array is: ";
    int sum =0;float average;
    for (int i = 0; i < size; i++){
        sum += array[i];
        cout << array[i] << " ";
    }

    average = sum/float(size);
    cout.precision(2);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << "\nThe sum is " << sum << "\nThe average is "
         << average << endl;
}

void sort(int array[], int size)
{
    // Simple bubble sort. 
    int temp;
    int RunFlag = 1;
    while (RunFlag == 1)
    {
        RunFlag = 0;
        for (int i=0; i<size-1; i++)
        {
            temp = array[i];
            if (temp>array[i+1])
            {
                RunFlag = 1;
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        } 
    }
}