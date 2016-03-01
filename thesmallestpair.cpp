#include<stdio.h>
int main()
{
	long long T,n,a[1000000];
	int j,k;
	scanf(%lld",&T);
	for(k=0;k<T;k++)
	{
		scanf("%lld",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		bubblesort(a,n);



int bubblesort(int a[] ,int s)
{
    int i, j;
    int temp;
    
    for(i = s-1; i>0; i--)
    {
        for(j =0 ; j< i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
}
