public class Factorial {
    public static void main(String[] args) {
        long number = 3;
        long result[] = new long[100001];
        result[0]=1;
        for(int i=1;i<=number;i++)
        {
        	result[i]=i*result[i-1];
        }
    
        System.out.println("factorial of "+number +" is :"+result[(int) number]);
    }
}