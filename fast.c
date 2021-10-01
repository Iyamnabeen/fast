/* euta c program banaidinu na jsle 2 to 9 lakh vitra parne sab prime number print garna sakos as fast as possible */

// I am using the Sieve of Atkin method.

#include <stdio.h>
#include <stdbool.h>

int main(){
    int a=2,b=900000;
    bool s[900000] = {0};
    int i,j;
    printf("| 2 | 3 ");
    for(i=0; i<b; i++) s[i] = 0;

    for(i=1; i*i<b; i++){
        for(j=1;j*j<b;j++){
            int n=(4*i*i)+(j*j);
            if((n<=b) && (n%12==1 || n%12==5)) s[n]^=1;
            n=(3*i*i) + (j*j);
            if(n<=b && n%12==7) s[n]^=1;
            n=(3*i*i) - (j*j);
            if(i>j && n<=b && n%12 ==11) s[n]^=1;
        }
    }

    for(int m=5; m*m<b; m++){
        if(s[m]==1) for(i=m*m; i<b; i+=m*m) s[i]=0;
    }

    for(i=5;i<b;i++) if(s[i]==1) printf("| %d ", i);
    return 0;
}