//CORRECT CODE

int patition(int input[],int s,int e){
    if(s>=e){
        return 0;
    }
    int count=0;
    for(int i=1+s;i<=e;i++)
    {
    if(input[s]>=input[i])
    {
    	    count++;
    }
      int   c=s+count;
        
        }
    
    int temp=input[s];
    input[s]=input[s+count];
    input[s+count]=temp;
    
    int i=0,j=e;
    while(i<s+count && j>s+count)
    {
        if(input[i]<=input[s+count]){
            i++;
        }
        else if(input[j]>input[s+count]){
            j--;
        }
        else
        {
            int temp=input[i];
    		input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
            
    }
    return s+count;
    }

void qs(int input[],int s,int e){
    if(s>=e){
        return;
    }
    int c=patition(input,s,e);
    qs(input,s,c-1);
    qs(input,c+1,e);
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
int s=0,e=size-1;
    if(s>=e){
        return;
    }
  qs(input,s,e);
 		   
}

//EXPERIMENT - WITHOUT PASSING INDEXES
/*
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void partitionArray(int input[], int size, int count)
{
    
    swap(input, input + count);
    
    int j = 0;
    int k = size-1 ;
    
    while ( j < count && k > count)
    {
        if ( input[j] > input[count] )
        {
            if(input[k] < input[count])
            {
                swap((input+j), (input+k));
                j++;
            }
            else
            {
                k--;
            }
            
        }
        else
        {
            j++;
        }
    }
    
    
}

void quickSort(int input[], int size) {
      Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.

	if( size == 0 or size == 1)
        return;
    else
    {
        int count = 0;
    	for(int i = 1; i < size; i++)
    	{
        	if (input[0] > input[i])
            count++;
    	}
        
        partitionArray(input , size, count);
        
        const int s1 = count;
        const int s2 = size - count - 1 ;
        
        if (s1 > 0 && s2 > 0)
        {
        
        	int part1[s1];
        	int part2[s2];
        
        	for(int l = 0; l < s1; l++)
            	part1[l] = input[l];
        	for(int m = 0; m < s2; m++)
            	part2[m] = input[count+m+1];
        
        	quickSort(part1, s1);
        	quickSort(part2, s2);
            
        }
        
        else if ( s1 > 0 && s2 == 0)
        {
            int part1[s1];
            for(int l = 0; l < s1; l++)
                part1[l] = input[l];
            
            quickSort(part1, s1);
        }
        
        else if (s1 == 0 && s2 > 0)
        {
            int part2[s2];
            for(int m = 0; m < s2; m++)
                part2[m] = input[count+m+1];
            
            quickSort(part2, s2);
        }
    }
}
*/
