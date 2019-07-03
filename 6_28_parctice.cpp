/**********************************************
practice on 6/28/2019
review on class with C++.
Hongliang Si (hs983@cornell.edu)
**********************************************/
#include<iostream>
using namespace std;

class MyClass
{
    private:
        /* data */
    public:
        void printMessage()
        {
            cout<<"This is the public function in class MyClass"<<endl;
        }        
};


int main(int argc, char const *argv[])
{
    cout<< "This is the first code I worte with Visual Studio Code." << endl;
    
    MyClass myobject;

    myobject.printMessage();

    return 0;
}

