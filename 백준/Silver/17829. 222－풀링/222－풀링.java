import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int[][] arr;
    static boolean[] dy = { false, false, true, true };
    static boolean[] dx = { false, true, false, true };

    static void solve() throws Exception {

        System.out.println(recursive(0, 0, N));;
    }

    static int recursive(int y, int x, int n) {

        if (n == 2) {
            int[] num = new int[4];
            for (int i=0; i<2; i++) {
                for (int j=0; j<2; j++) {
                    num[i * 2 + j] = arr[y + i][x + j];
                }
            }

            Arrays.sort(num);
            return num[2];
        }

        int[] num = new int[4];
        for (int i=0; i<4; i++) {
            int ny = y, nx = x;
            if (dy[i]) ny = y + n / 2;
            if (dx[i]) nx = x + n / 2;

            num[i] = recursive(ny, nx, n / 2);
        }

        Arrays.sort(num);

        return num[2];
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];

        StringTokenizer st;
        for (int i=0; i<N; i++) {

            st = new StringTokenizer(br.readLine());
            for (int j=0; j<N; j++) {
                int num = Integer.parseInt(st.nextToken());
                arr[i][j] = num;
            }
        }

        solve();
    }
}