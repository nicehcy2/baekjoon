import java.io.*;
import java.util.*;

public class Main {

    static String A, B;
    static int[][] dp;

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        A = br.readLine();
        B = br.readLine();
        dp = new int[A.length() + 1][B.length() + 1];

        for (int i=0; i< A.length(); i++) {
            for (int j=0; j< B.length(); j++) {

                if (A.charAt(i) == B.charAt(j)) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        int count = dp[A.length()][B.length()];
        System.out.println(count);

        Stack<Character> s = new Stack<>();

        int y = A.length();
        int x = B.length();
        while (true) {
            if (y < 0 && x < 0) break;
            if (count == 0) break;

            if (count == dp[y - 1][x]) y--;
            else if (count == dp[y][x -1]) x--;
            else {
                y--; x--; count--;
                s.push(A.charAt(y));
            }
        }

        while(!s.empty()) {
            System.out.print(s.pop());
        }
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}