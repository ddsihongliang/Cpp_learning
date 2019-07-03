/********************************************************    
    Review of C++. 
    6/29/2019
    arrays as parameter in function
 ********************************************************/
#include<iostream>
#include<math.h>
using namespace std;

const int MAX_NUM_SCORES = 10;

void fill_up(int array[], int size, int &num_used);
// size is the declared max size of array[]
// the user will type-in any numbers of data
// and this function will pass those data into the array[].

void print_result(const int array[], int size);
// size is the declared size of array[]
// the const int array[] is added as a precaution.
// this function will print the data stored in array[].

int main(void){
    int num_used;               // Fixed size to prevent overfloating 
    int scores[MAX_NUM_SCORES]; // Initialize sum. 

    fill_up(scores, MAX_NUM_SCORES,num_used);
    print_result(scores, num_used);
    
    return 0;
}

void fill_up(int array[], int size, int &num_used){
    //uses iostream
    int next, index = 0;

    cout << "Enter up to "<< size << " numbers: \n"
         << "End with a negtive input.\n";
    cin >> next;
    while (index < size && next >= 0) {
        array[index] = next;
        cin >> next;
        index++;
    }
    num_used = index;
}

void print_result(const int array[], int size){
    //uses iostream
    int sum =0;float average;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }

    average = sum/float(size);
    cout.precision(2);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << "\nThe sum is " << sum << "\nThe average is "
         << average << endl;
}