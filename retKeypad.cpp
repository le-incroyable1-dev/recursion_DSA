/*
Return Keypad Code

Given an integer n, using the "standard phone keypad" find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return 
the count of elements populated in the output array.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

string mapping[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void createOutput(int s, int cur, string output[], int n)
{
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < n;j++)
        {
            output[i*n + j] = output[j];
        }
    }
    
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < n;j++)
        {
            output[i*n + j] += mapping[cur-2][i];
        }
    }
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0 or num==1)
    {
        output[0] = "";
        return 1;
    }
    else
    {
        int next = num/10;
        int cur = num%10;
        
        int n = keypad(next, output);
        
     
        int s = (mapping[cur-2]).size();
        
        createOutput(s,cur,output,n);
        
        return (n*s) ;
        
    }
    
    
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
