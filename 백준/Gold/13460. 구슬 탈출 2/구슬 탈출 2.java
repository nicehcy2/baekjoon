
import java.util.*;
import java.io.*;

public class Main {

    static final char WALL = '#';
    static final char HOLE = 'O';
    static final char AIR = '.';

    static boolean visited[] = new boolean[100101]; // red: 앞에 세 자리, blue: 뒤에 세 자리

    static int[] dy = {0, -1, 0, 1};
    static int[] dx = {-1, 0, 1, 0};

    static int result = 0;
    static char board[][];

    static int calcVisit(int[] pos) {

        return (pos[0] * 10 + pos[1]) * 1000 + (pos[2] * 10 + pos[3]);
    }


    static void bfs(int[] pos) {

        Queue<int[]> q = new LinkedList<>();
        q.add(pos);
        visited[calcVisit(pos)] = true;

        while (!q.isEmpty()) {

            int[] cur = q.poll();
            if (cur[4] > 10) {
                result = -1;
                return;
            }

            for (int i=0; i<4; i++) {
                int nry = cur[0];
                int nrx = cur[1];
                int nby = cur[2];
                int nbx = cur[3];

                boolean isRedGoal = false;
                boolean isBlueGoal = false;

                // 빨간 구슬 이동 -> 벽을 만날 때 까지
                while (board[nry + dy[i]][nrx + dx[i]] != WALL) {

                    if (board[nry + dy[i]][nrx + dx[i]] == HOLE) {
                        isRedGoal = true;
                        break;
                    }

                    nry += dy[i];
                    nrx += dx[i];
                }

                // 파란 구슬 이동 -> 벽을 만날 때 까지
                while (board[nby + dy[i]][nbx + dx[i]] != WALL) {

                    if (board[nby + dy[i]][nbx + dx[i]] == HOLE) {
                        isBlueGoal = true;
                        break;
                    }

                    nby += dy[i];
                    nbx += dx[i];
                }

                if (isBlueGoal) continue;;
                if (isRedGoal && !isBlueGoal) {
                    result = cur[4];
                    return;
                }

                if (nry == nby && nrx == nbx) {

                    if (i == 0) {
                        if (cur[1] > cur[3]) nrx -= dx[i];
                        else nbx -= dx[i];
                    } else if (i == 1) {
                        if (cur[0] > cur[2]) nry -= dy[i];
                        else nby -= dy[i];
                    } else if (i == 2) {
                        if (cur[1] > cur[3]) nbx -= dx[i];
                        else nrx -= dx[i];
                    } else if (i == 3) {
                        if (cur[0] > cur[2]) nby -= dy[i];
                        else nry -= dy[i];
                    }
                }

                int nPos[] = {nry, nrx, nby, nbx, cur[4] + 1};
                if (!visited[calcVisit(nPos)]) {
                    visited[calcVisit(nPos)] = true;
                    q.add(nPos);
                }
            }
        }

        result = -1;
    }

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        board = new char[N][M];
        int[] pos = new int[5];

        for (int i=0; i<N; i++) {

            String inputString = br.readLine();
            for (int j = 0; j < M; j++) {
                if (inputString.charAt(j) == 'R') {
                    board[i][j] = AIR;
                    pos[0] = i;
                    pos[1] = j;
                }
                else if (inputString.charAt(j) == 'B') {
                    board[i][j] = AIR;
                    pos[2] = i;
                    pos[3] = j;
                }
                else board[i][j] = inputString.charAt(j);
            }
        }

        pos[4] = 1;
        bfs(pos);

        System.out.println(result);

        br.close();
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}