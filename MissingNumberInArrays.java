package geekforgeeks;

import java.util.Scanner;

public class MissingNumberInArrays {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t= sc.nextInt();
        for(int i=0;i<t;i++){
            int n= sc.nextInt();
            long sum=0;
            for(int j=1;j<n;j++){
                sum=sum+j;
            }
            System.out.println((n*(n+1))/2-sum);
        }
    }
}
