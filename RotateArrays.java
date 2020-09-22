package geekforgeeks;

import java.util.Scanner;

public class RotateArrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt();
            }
            for (int j = d % n; j < n; j++) {
                System.out.print(a[j] + " ");
            }
            for (int j = 0; j < d % n; j++) {
                System.out.print(a[j] + " ");
            }
            System.out.println();
        }
    }
}
