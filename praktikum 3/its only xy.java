import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    // fungsi untuk mengalikan dua bilangan dengan algoritma Divide and Conquer
    public static BigInteger Kali2(BigInteger X, BigInteger Y, int n) {
        if (n == 1) {
            return X.multiply(Y);
        }
        else {
            int s = n / 2;
            BigInteger a = X.divide(BigInteger.TEN.pow(s)); // bagi X menjadi a dan b
            BigInteger b = X.mod(BigInteger.TEN.pow(s));
            BigInteger c = Y.divide(BigInteger.TEN.pow(s)); // bagi Y menjadi c dan d
            BigInteger d = Y.mod(BigInteger.TEN.pow(s));
            BigInteger p = Kali2(a, c, s); // hitung a*c
            BigInteger q = Kali2(b, d, s); 
            BigInteger r = Kali2(a.add(b), c.add(d), s);
            System.out.println(p + " " + r + " " + q); // print semua nilai rekursif
            BigInteger temp = r.subtract(p).subtract(q);
            BigInteger temp2 = temp.multiply(BigInteger.TEN.pow(s));
            return p.multiply(BigInteger.TEN.pow(2 * s)).add(temp2).add(q); // hitung hasil perkalian
        }
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String X = input.next();
        String Y = input.next();
        int n = Math.min(X.length(), Y.length());
        X = String.format("%" + n + "s", X).replace(' ', '0'); 
        Y = String.format("%" + n + "s", Y).replace(' ', '0');
        BigInteger x = new BigInteger(X);
        BigInteger y = new BigInteger(Y);
        BigInteger hasil = Kali2(x, y, n);
        System.out.println(hasil); // print hasil perkalian
        input.close();  
}
}