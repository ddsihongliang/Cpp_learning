//*****************************************
//	online practice
//	focused on pointer, memory allocation
//	2/5/2019
//	Hongliang Si (hs983@cornell.edu)
//*****************************************

#include <iostream>
using namespace std;

int main()
{
	int x = 3;
  int* p = &x;

  cout <<   "the x holds value of "<< x;
  cout << "\nthe pointer p holds memory of "<< p;
	cout << "\nthe pointer p holds value of "<< *p;
  cout << "\nif we change the address of the pointer"<<
          "\nnow p holds value "<< *(p+1) <<endl;
  printf("Which is a floating number that changes upon every excution\n");
	return 0;
}
