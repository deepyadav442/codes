#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int count(long long int S[], int m, int n )
{
    long long int table[n+1][m];
    long long int x,y;
    for(int i=0;i<m;i++)
        table[0][i] = 1;
    for(int j=1; j<=n; j++)
        {
            for(int k=0; k<m; k++)
                {
                    x = (j-S[k] >= 0)? table[j - S[k]][k]: 0;
                    y = (k >= 1)? table[j][k-1]: 0;
                    table[j][k] = x+y;
            }


    }

    return table[n][m-1];
}
int main() {
    int n ,m;
    scanf("%d",&m);
    long long int S[m];
    for(int j=0;j<m;j++)
                {
                    scanf("%lli",&S[j]);
            }
    scanf("%d",&n);
    long long int x = count(S,m,n);
    printf("%lli",x);
    return 0;
}
