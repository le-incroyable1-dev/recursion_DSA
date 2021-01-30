#include <iostream>
#include <string.h>
using namespace std;

void pairStar(char * s) {
    int len = strlen(s);
    
    if (len > 1)
    {
        if ( *s == *(s+1) ){
            for (int i = len-1 ; i > 0; i--)
                *(s+i+1) = *(s+i);
            *(s + len + 1) = '\0';
            *(s + 1) = '*';
            pairStar((s+2));
        }
        else{
            pairStar((s+1));
        }
    }
}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
