import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;
import java.lang.Math;
class GFG {
	public static void main (String[] args) {
		//code
		int i,j,k,n,t,count;
		Scanner in=new Scanner(System.in);
		t=in.nextInt();
		for(k=0;k<t;k++)
		{
		    count=0;
		    n=in.nextInt();
		    int[] a=new int[n];
		    int[] l=new int[n];
		    int[] r=new int[n];
		    for(i=0;i<n;i++)
		    a[i]=in.nextInt();
		    l[0]=a[0];
		    for(i=1;i<n;i++)
		    {
		        l[i]=Math.max(l[i-1],a[i]);
		    }
		    r[n-1]=a[n-1];
		    for(i=n-2;i>=0;i--)
		    {
		        r[i]=Math.max(r[i+1],a[i]);
		    }
		    for(i=0;i<n;i++)
		    {
		        count+=(Math.min(r[i],l[i])-a[i]);
		    }
		    System.out.println(count);
		}
	}
} 