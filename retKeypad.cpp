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
