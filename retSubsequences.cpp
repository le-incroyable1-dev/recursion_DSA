#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;


int subseq(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    else
    {
        int smallCount = subseq(input.substr(1), output);
        for(int i = 0; i < smallCount; i++)
        {
            output[smallCount + i] = output[i] + input[0];
        }
        return 2*smallCount;
    }
}

int main()
{
    string input;
    cin >> input;
    
    int size = input.size();
    int outputSize = pow(2, size);
    
    string  *output = new string[outputSize];
    int count = subseq(input, output);
    
    for(int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
