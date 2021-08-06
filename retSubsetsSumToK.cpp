/*
Return subsets sum to K

Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output :
3 3
5 1
*/

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don't print the subsets, just save them in output.
***/

void helper(int input[], int n, int subset[], int m, int output[][50], int k, int &result)
{
    static int count = 0;
    
    if(n == 0)
    { 
        int sum = 0;
        
        for(int i = 0; i < m; i++)
        {
            sum = sum + subset[i];
            //cout << subset[i];
        }
        //cout << endl;
        
        if(sum == k)
        {
            output[count][0] = m;
            
            for(int i = 0; i < m; i++)
            {
                output[count][i+1] = subset[i];
            }
            
            count++;
            
            result = count;
        }
        
        return;
    }
    
    helper(input+1, n-1, subset, m, output, k, result);
    
    int newSubset[m+1];
    
    for(int i = 0; i < m; i++)
        newSubset[i] = subset[i];
    
    newSubset[m] = input[0];
    
    helper(input+1, n-1, newSubset, m+1, output, k, result);
    
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    int subset[] = {};
    int result = 0;
    
    helper(input, n, subset, 0, output, k, result);
    
    return result;
}
