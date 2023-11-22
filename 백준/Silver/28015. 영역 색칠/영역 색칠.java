import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;

    public static int[][] arr = new int[100][100];

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void Solve() throws Exception {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int init = 0, oneCnt = 0, twoCnt = 0;
            for (int j = 0; j < m; j++) {
                if (j > 0) {
                    if (arr[i][j] == 1 && arr[i][j - 1] != 1) oneCnt++;
                    if (arr[i][j] == 2 && arr[i][j - 1] != 2) twoCnt++;
                } else if (j == 0) {
                    if (arr[i][j] == 1) oneCnt++;
                    if (arr[i][j] == 2) twoCnt++;
                }

                if (arr[i][j] == 0) {
                    if (oneCnt >= twoCnt && (oneCnt > 0 || twoCnt > 0)) {
                        cnt += 1 + twoCnt;
                        oneCnt = 0;
                        twoCnt = 0;
                    }
                    if (oneCnt < twoCnt && (oneCnt > 0 || twoCnt > 0)) {
                        cnt += 1 + oneCnt;
                        oneCnt = 0;
                        twoCnt = 0;
                    }
                }

                if (j == m - 1 && arr[i][m - 1] != 0) {
                    if (oneCnt >= twoCnt && (oneCnt > 0 || twoCnt > 0)) {
                        cnt += 1 + twoCnt;
                    }
                    if (oneCnt < twoCnt && (oneCnt > 0 || twoCnt > 0)) {
                        cnt += 1 + oneCnt;
                    }
                }
            }
        }

        System.out.println(cnt);
    }
}