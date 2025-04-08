import java.util.*;
import java.io.*;

public class Main {

    static int R;
    static int C;
    static int M;

    static int[] dy = {0, -1, 1, 0, 0};
    static int[] dx = {0, 0, 0, 1, -1};

    static int board[][]; // 상어의 중복을 막기 위해 사용

    static int bfs(int[][] shark) {

        int idx = 0;
        int count = 0;

        while(idx < C) {

            // 1. 낚시왕 이동
            idx++;

            // 2. 낚시왕이 상어를 잡는다.
            int[] nearSharkPos = findNearShark(idx);
            if (nearSharkPos != null) {
                count += board[nearSharkPos[0]][nearSharkPos[1]];
                board[nearSharkPos[0]][nearSharkPos[1]] = 0; // 보드에서 상어 삭제
                for (int i=0; i<M; i++) {
                    int y = shark[i][0];
                    int x = shark[i][1];
                    if (nearSharkPos[0] == y && nearSharkPos[1] == x) {
                        shark[i][5] = 0; // 상어 죽음 처리
                    }
                }
            }

            // 이동 시작 전 맵 초기화
            for(int i=1; i<=R; i++) {
                for (int j=1; j<=C; j++) {
                    board[i][j] = 0;
                }
            }

            // 3. 상어 이동
            for (int i=0; i<M; i++) {

                int y = shark[i][0];
                int x = shark[i][1];
                int s = shark[i][2];
                int d = shark[i][3];
                int z = shark[i][4];
                int sur = shark[i][5];

                if (sur == 1) { // 상어가 살아있다면

                    int[] npos = move(y, x, s, d);
                    int ny = npos[0];
                    int nx = npos[1];
                    shark[i][0] = ny;
                    shark[i][1] = nx;
                    shark[i][3] = npos[2];

                    if (board[ny][nx] == 0) {
                        board[ny][nx] = z;
                    } else {
                        // 현재 상어가 다른 상어보다 더 큰 경우
                        if (board[ny][nx] < z) {

                            // 기존에 있던 상어 죽음 처리
                            for (int j = 0; j < i; j++) {
                                int info[] = shark[j];
                                if (info[5] == 1 && info[0] == ny && info[1] == nx) {
                                    shark[j][5] = 0;
                                }
                            }

                            board[ny][nx] = z;
                        } else {
                            shark[i][5] = 0;
                        }
                    }
                }
            }
        }

        return count;
    }

    static int[] move(int y, int x, int s, int d) {

        int dirY = 1, dirX = 1;
        if (d == 1) { dirY = -1; dirX = 0; }
        else if (d == 2) { dirY = 1; dirX = 0; }
        else if (d == 3) { dirY = 0; dirX = 1; }
        else if (d == 4) { dirY = 0; dirX = -1; }

        while (s > 0) {

            if (y == 1 && dirY < 0) dirY *= -1;
            if (y == R && dirY > 0) dirY *= -1;
            if (x == 1 && dirX < 0) dirX *= -1;
            if (x == C && dirX > 0) dirX *= -1;

            y += dirY;
            x += dirX;

            s--;
        }

        if (dirY == -1) d = 1;
        else if (dirY == 1) d = 2;
        else if (dirX == 1) d = 3;
        else if (dirX == -1) d = 4;

        return new int[]{y, x, d};
    }

    static int[] findNearShark(int x) {

        for (int i=1; i<=R; i++) {
            if (board[i][x] != 0) {
                return new int[]{i, x};
            }
        }

        return null;
    }

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[R + 1][C + 1];
        int[][] shark = new int[M][6];

        for (int i=0; i<M; i++) {

            st = new StringTokenizer(br.readLine());
            for (int j=0; j<5; j++) {
                shark[i][j] = Integer.parseInt(st.nextToken());
            }
            board[shark[i][0]][shark[i][1]] = shark[i][4];
            shark[i][5] = 1; // 생존하면 1, 죽으면 0
        }

        System.out.println(bfs(shark));

        br.close();
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}