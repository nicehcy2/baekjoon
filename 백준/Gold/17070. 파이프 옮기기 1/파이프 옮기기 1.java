
import java.util.*;
import java.io.*;

public class Main {

    static int map[][];
    static int N;
    static int result = 0;

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N + 1][N + 1];

        for (int i=1; i<=N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j=1; j<=N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(1, 2, 0);
        System.out.println(result);

        br.close();
    }

    public static void dfs(int y, int x, int dir) {

        if (y == N && x == N && map[y][x] == 0) {
            result++;
            return;
        }

        switch (dir) {
            case 0: // 파이프가 가로 방향일 경우
                if (x + 1 <= N && map[y][x + 1] == 0) {
                    dfs(y, x + 1, 0);
                }
                break;
            case 1: // 파이프가 세로 방향일 경우
                if (y + 1 <= N && map[y + 1][x] == 0) {
                    dfs(y + 1, x, 1);
                }
                break;
            case 2: // 파이프가 대각선 방향일 경우
                if (x + 1 <= N && map[y][x + 1] == 0) { // 가로
                    dfs(y, x + 1, 0);
                }
                if (y + 1 <= N && map[y + 1][x] == 0) { // 세로
                    dfs(y + 1, x, 1);
                }
                break;
        }

        if (y + 1 <= N && x + 1 <= N && map[y + 1][x + 1] == 0 && map[y + 1][x] ==0 && map[y][x+1] == 0) {
            dfs(y + 1, x + 1, 2);
        }
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}