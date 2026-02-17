import java.util.*;
import java.io.*;

public class Main {

    static int N, white = 0, blue = 0;
    static int[][] arr;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        arr = new int[N][N];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j=0; j<N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        solve(N, 0, 0);

        System.out.println(white);
        System.out.println(blue);
        br.close();
    }

    static void solve(int n, int y, int x) {

        if (n == 1) {
            if (arr[y][x] == 1) blue++;
            else white++;
            return;
        }

        int ws = 0, bs =0;
        for (int i=y; i<y + n; i++) {
            for (int j=x; j<x + n; j++) {
                if (arr[i][j] == 1) bs++;
                else ws++;
            }
        }

        if (bs == n * n) {
            blue++;
            return;
        }
        if (ws == n * n) {
            white++;
            return;
        }

        solve(n/2, y, x);
        solve(n/2, y + n/2, x);
        solve(n/2, y, x + n/2);
        solve(n/2, y + n/2, x + n/2);
    }
}
