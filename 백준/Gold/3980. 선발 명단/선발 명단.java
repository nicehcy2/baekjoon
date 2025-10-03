import java.util.*;
import java.io.*;

public class Main {

    static int C, answer = 0;
    static int[][] arr;
    static int[] best = new int[11];
    static boolean[] visited = new boolean[11];
    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        C = Integer.parseInt(br.readLine());

        while (C-- > 0) {
            arr = new int[11][11];
            answer = 0;

            for (int i=0; i<11; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j=0; j<11; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            backtracking(0);

            sb.append(answer).append("\n");
        }

        System.out.println(sb);
    }

    static void backtracking(int position) {

        if (position == 11) {
            int sum = 0;
            for (int i=0; i<11;i++) {
                sum += best[i];
            }
            answer = Math.max(sum, answer);
            return;
        }

        // 백트래킹은 특정 포지션에 대한 적절한 선수를 고르는거. 각 포지션에는 최대 5명
        int count = 0;
        for (int i=0; i<11; i++) {

            if (count > 5) return;

            if (arr[i][position] != 0 && !visited[i]) {
                best[position] = arr[i][position];
                visited[i] = true;
                count++;
                backtracking(position + 1);
                best[position] = 0;
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}