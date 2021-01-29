#include <iostream>
#include <string.h>
using namespace std;

void removeX(char *s) {
    int len;
    len = strlen(s);
    
    if ( len > 1)
    {
        if( *s == 'x'){
            for ( int i = 0; i < (len-1); i++){
                *(s+i) = *(s+i+1);
                *(s+i+1) = ' ';
            }
            removeX(s);
        }
        else{
            removeX((s+1));
        }
    }
    else if ( len == 1){
        if (*s == 'x')
            *s = '\0';
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

