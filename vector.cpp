/********************************************************    
    Review of C++. 
    6/29/2019
    Vectors 
 ********************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v(10);
    cout << "Enter a list of positive numbers. \n"
         << "Place a negative number to stop the program.\n";

    int next;
    cin >> next;
    while (next > 0){
        v.push_back(next);
        cout << "v.size() = " << v.size() << endl;
        cin >> next;
    }

    // changes the size of the Vector
    // but does not destroys the elements
    v.resize(5);
    cout << "Vector size: " << v.size() << endl;
    
    // Shrinks to the size
    // till which elements are
    // destroys the elements after 5
    v.push_back(next);
    v.shrink_to_fit();

    cout << "Vector size: " << v.size() << endl;

    return 0;
}