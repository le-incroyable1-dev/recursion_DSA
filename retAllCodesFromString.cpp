/*
Return all codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <string.h>
#include <sstream>

using namespace std;

void helper(string input, string output[10000], int& count, string subset)
{
    //static int num = 0;
    
    if(input.length() == 0)
    {
        output[count] = subset;
        //cout << subset << endl;
        count++;
        return;
    }
    
    string subsetCopy = subset;
    
    int i1;
    string s1 = input.substr(0,1);
    stringstream ss1(s1);
    ss1 >> i1;
    //cout << i1 << endl;
    
    subset += ((char)(i1+96));
    //cout << subset << endl;
    
    
    string subStr1 = input.substr(1, (input.length()-1));
    //cout << subStr1 << endl;
    
    
    helper(subStr1, output, count, subset);
    
    
    if(input.length() >= 2)
    {
        int i2;
    	string s2 = input.substr(0,2);
    	stringstream ss2(s2);
    	ss2 >> i2;
    	//out << i2 << endl;
    	
        if(i2 <= 26)
        {
    		subsetCopy += ((char)(i2+96));
    		//cout << subsetCopy << endl;
    
    
    		string subStr2 = input.substr(2, (input.length()-2));
    		//cout << subStr2 << endl;
    
    
    		helper(subStr2, output, count, subsetCopy);
        }
    }
    
    //count = num;
    
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    int count = 0;
    string subset = "";
    
    helper(input, output, count, subset);
    
    return count;
    
}

