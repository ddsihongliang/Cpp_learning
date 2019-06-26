/******************************************************************************
    C++ Practise 6/26
    Using string and length function.
    Hongliang Si
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{

    string word = "abcdDcBa"; // default.
    cout <<"Enter a word for palindrome check ->";
    cin >> word; 
    
    int length = word.length();
    int tureFlag;
    int absDiff;
    
    for(int i; i < length/2; ++i){
        absDiff = abs(int(word[i])-int(word[length-i-1]));
        //cout << absDiff << endl;
        if(absDiff == 32 || absDiff == 0){ // same letter check in ASCII 
            tureFlag = 1;                 // not case-sensitive. 
        }else{
            tureFlag = 0;
            break;
        }
    }
    
    if(tureFlag ==1){
        cout<<"TRUE\n";
    }else{
        cout<<"FALSE\n";
    }

    return 0;
}
