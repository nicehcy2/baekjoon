import java.util.*;
import java.io.*;

public class Main {

    static int T;

    static void solve() {
    }

    static int gcd(int a, int b) {

        if ((a % b) == 0) return b;
        return gcd(b,a % b);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for (int i=0; i<T; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            int gcd = A > B ? gcd(A, B) : gcd(B, A);
            System.out.println(A * B / gcd);
        }

        solve();
    }
}