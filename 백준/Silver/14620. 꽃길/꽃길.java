import java.util.*;
import java.io.*;

public class Main {

    static int N, answer = Integer.MAX_VALUE;
    static int[][] arr;
    static int[][] visited = new int[3][2];
    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        arr= new int[N][N];
        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        backtracking(0, 0);

        System.out.println(answer);
    }

    static void backtracking(int count, int sum) {

        if (count == 3) {
            answer = Math.min(sum, answer);

            return;
        }

        for (int i=1; i< N-1; i++) {

            for (int j=1; j< N-1; j++) {

                // if 체크
                boolean flag = true;
                for (int k=0; k<count; k++) {

                    // if (visited[k][0] == 0 && visited[k][1] == 0) continue;
                    if (Math.abs(visited[k][0] - i) + Math.abs(visited[k][1] - j) <= 2) flag = false;
                }
                if (flag) {
                    visited[count][0] = i;
                    visited[count][1] = j;
                    sum += (arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j]);
                    backtracking(count + 1, sum);
                    sum -= (arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j]);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}