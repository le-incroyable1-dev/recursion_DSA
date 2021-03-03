/*
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.
*/

int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     *  Verify using Principle of Mathematical Induction.
     */
    
    if (n == 1 || n == 0)
            return 1;
    else if (n == 2)
        return 2;
 
    else
        return staircase(n - 3) + staircase(n - 2) + staircase(n - 1);
    
}
