#include <iostream>
using namespace std;

#include <string.h>

bool isPalRec(char str[],  
              int s, int e) 
{ 
      
    // If there is only one character 
    if (s == e) 
    return true; 
  
    // If first and last 
    // characters do not match 
    if (str[s] != str[e]) 
    return false; 
  
    // If there are more than  
    // two characters, check if  
    // middle substring is also  
    // palindrome or not. 
    if (s < e + 1) 
    return isPalRec(str, s + 1, e - 1); 
  
    return true; 
} 

bool checkPalindrome(char input[]) {
    
    int n = strlen(input); 
      
    // An empty string is  
    // considered as palindrome 
    if (n == 0) 
        return true; 
      
    return isPalRec(input, 0, n - 1); 
    
    // Write your code here

}


int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

/*

WHY DOES THIS GIVE A SEGMENTATION ERROR ??
// return a pointer to an array from the helper function. 
// this array is the reduced string after removing first and last elements from the input.

char * helper(char input[])
{
    const int len = strlen(input);
    char res[(len-2)];
    
    for (int i = 0; i < (len-2); i++)
        res[i] = input[i+1];
    
    return res;
    
}

bool checkPalindrome(char input[]) {
    
    const int len = strlen(input);
    
    if(len == 1)
        return true;
    else{
        if (input[0] != input[len-1])
            return false;
        else{
            if(len == 2)
                return true;
            else
                return checkPalindrome(helper(input));
        }
    }
    
    
    // Write your code here

}

Gives segmentation error !??

*/
