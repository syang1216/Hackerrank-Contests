import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        // your code goes here
        
        double diff = (p-1)/2.0;
        long diffBack;
        
        if(n%2==1){
            diffBack = (long)Math.floor((n-p)/2.0);
        }else{
            diffBack = (long)Math.ceil((n-p)/2.0);
        }

        if(diff<=diffBack){
            System.out.println((long)Math.ceil(diff));
        }else{
            System.out.println(diffBack);
        }
    }
}