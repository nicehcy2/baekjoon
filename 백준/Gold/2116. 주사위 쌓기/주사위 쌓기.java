import java.io.*;
import java.util.*;

public class Main {

    static int[][] arr;
    static int T, max = -1;

    static void search(int cnt, int up, int sum) {

        int bottom = checkBottom(up);
        int tempMax = -1;

        for (int i=0; i<6; i++) {
            if (i==bottom || i== up)
                continue;
            tempMax = Math.max(tempMax, arr[cnt - 1][i]);
        }
        sum += tempMax;

        if (cnt == T) {
            if (sum > max) max = sum;
            return;
        }

        for (int i=0; i<6; i++) {
            if (arr[cnt - 1][bottom] == arr[cnt][i]) {
                search(cnt + 1, i, sum);
                break;
            }
        }
    }

    static int checkBottom(int up) {
        if (up == 0) return 5;
        else if (up == 1) return 3;
        else if (up == 2) return 4;
        else if (up == 3) return 1;
        else if (up == 4) return 2;
        else return 0;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        arr = new int[T][6];
        for (int i=0; i<T; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<6; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0;i<6;i++) {
            search(1, i, 0);
        }
        bw.write(String.valueOf(max));

        bw.flush();
        bw.close();
        br.close();
    }
}