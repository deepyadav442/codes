#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int chrtoint(char a){
int i;
for (i = 48; i<=57; i++)
if (toascii(i)==a) return i-48;
return 0;
}
int strreverse(char *a)
{
    char temp;
    int i,j;
    for(i=0,j=strlen(a)-1;i<j;j--,i++)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }

}
int main(){
char n1[101];
char n2[101];
int rs[200];
int c1, c2;
int i,j,m, cmax, sum;
scanf("%s",n1);
scanf("%s",n2);
c1 = strlen(n1);
c2 = strlen(n2);

strreverse(n1);
strreverse(n2);

cmax = c1;
if(c1<c2){
cmax = c2;
}

m=0;
for(i=0; i< cmax; i++){
if(c1==c2 || (i < c1 && i < c2)){
sum = m+chrtoint(n1[i])+chrtoint(n2[i]);
}else if(i >=c1){
sum = m+chrtoint(n2[i]);
}else if(i >=c2){
sum = m+chrtoint(n1[i]);
}
rs[i] = sum%10;
m = sum/10;
}
if(m){
rs[i]=m;
i++;
}
printf("Result = ");
for(j=0; j < i; j++){
printf("%d", rs[i-j-1]);
}
return 0;

}
