import java.util.*;
import java.io.*;

public class Main {

    static int A, B, C, D;

    static void solve() throws Exception {

        int denominator = B * D; // 분모
        int molecule = A * D + B * C; // 분자
        int GCD = 1;

        if (denominator >= molecule) GCD = gcd(denominator, molecule);
        else GCD = gcd(molecule, denominator);

        System.out.println(molecule / GCD + " " + denominator / GCD);
    }

    static int gcd(int a, int b) {

        return b != 0 ? gcd(b, a % b) : a;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        solve();
    }
}