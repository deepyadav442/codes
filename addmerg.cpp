#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll arr[1001]={1LL,2LL,3LL,5LL,8LL,13LL,21LL,34LL,55LL,89LL,144LL,233LL,377LL,610LL,987LL,1597LL,2584LL,4181LL,6765LL,10946LL,17711LL,28657LL,46368LL,75025LL,121393LL,196418LL,317811LL,514229LL,832040LL,1346269LL,2178309LL,3524578LL,5702887LL,9227465LL,14930352LL,24157817LL,39088169LL,63245986LL,102334155LL,165580141LL,267914296LL,433494437LL,701408733LL,1134903170LL,1836311903LL,2971215073LL,4807526976LL,7778742049LL,12586269025LL,20365011074LL,32951280099LL,53316291173LL,86267571272LL,139583862445LL,225851433717LL,365435296162LL,591286729879LL,956722026041LL,1548008755920LL,2504730781961LL,4052739537881LL,6557470319842LL,10610209857723LL,17167680177565LL,27777890035288LL,44945570212853LL,72723460248141LL,117669030460994LL,190392490709135LL,308061521170129LL,498454011879264LL,806515533049393LL,1304969544928657LL,2111485077978050LL,3416454622906707LL,5527939700884757LL,8944394323791464LL,14472334024676221LL,23416728348467685LL,37889062373143906LL,61305790721611591LL,99194853094755497LL,160500643816367088LL};
int main()
{
    ll t;
    ll n;
    scanf("%lld",&t);
    while(t--)
    {
        ll count=0,i;
        scanf("%lld",&n);
        for(i=0;;i++)
        {
            if(arr[i]<n)
                count++;
            else if(arr[i]==n){
                count++;
                break;
            }
            else
                break;
        }
        printf("%lld\n",count);
    }
    return 0;
}
