import java.util.*;
import java.io.*;

public class Main  {

    static int N;
    static char[][] arr = new char[3126][3126];
    static int[][] PATTERN = {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 1, 1, 0},
            {0, 1, 0, 1, 0},
    };

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        if (N == 0) {
            System.out.println("*");
            return;
        } else {

            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    if (PATTERN[i][j] == 1) star(N - 1, i, j);
                }
            }
        }

        int size = (int)Math.pow(5, N);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sb.append(arr[i][j] == '*' ? '*' : ' ');
            }
            sb.append('\n');
        }
        System.out.print(sb);

        br.close();
    }

    static void star(int n, int y, int x) {

        if (n == 0) {
            arr[y][x] = '*';
            return;
        }

        int ny = y * 5;
        int nx = x * 5;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (PATTERN[i][j] == 1) star(n - 1, ny + i, nx + j);
            }
        }
    }
}