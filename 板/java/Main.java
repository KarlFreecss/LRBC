import java.util.Scanner;
import java.math.*;
import java.text.*;

public class Main{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int T;
        T = cin.nextInt();
        BigInteger N = new BigInteger("0");
        BigInteger M = new BigInteger("0");
        for (int i = 0; i < T; ++i) {
            BigInteger BASE = new BigInteger("1");
            BigInteger ANS = new BigInteger("0");
            
            N = cin.nextBigInteger();
            M = cin.nextBigInteger();
            while (true) {
                BASE = BASE.multiply(new BigInteger("2"));
                if (BASE.compareTo(N) > 0) break;
            }

            while (true) {
                if (N.compareTo(BigInteger.ZERO) == 0) break;
                if (N.compareTo(BASE.subtract(new BigInteger("1")).multiply(M)) > 0) {
                    BigInteger K = N.divide(BASE);
                    K = K.min(M);
                    ANS = ANS.add(BASE);
                    N = N.subtract(K.multiply(BASE));
                }
                BASE = BASE.divide(new BigInteger("2"));
            }

            System.out.println(ANS);
        }
    }
}
