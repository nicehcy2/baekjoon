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

        solve(0, 0, N);

        System.out.println(white);
        System.out.println(blue);
        br.close();
    }

    static void solve(int y, int x, int n) {
        int color = arr[y][x];

        for (int i = y; i < y + n; i++) {
            for (int j = x; j < x + n; j++) {
                if (arr[i][j] != color) {
                    int half = n / 2;
                    solve(y, x, half);
                    solve(y, x + half, half);
                    solve(y + half, x, half);
                    solve(y + half, x + half, half);
                    return;
                }
            }
        }

        if (color == 1) blue++;
        else white++;
    }
}