import java.util.*;
import java.io.*;

public class Main {

    static int N, H, cnt1 = 0, cnt2 = 0;;
    static int[] arr1, arr2;

    static void solve() {

        Arrays.sort(arr1);
        Arrays.sort(arr2);
        int minBarrierCnt = Integer.MAX_VALUE, rangeCnt = 0;

        for (int i=1; i<=H; i++) {

            int collision = binarySearch1(i) + binarySearch2(i);
            if (collision < minBarrierCnt) {
                minBarrierCnt = collision;
                rangeCnt = 1;
            }
            else if (collision == minBarrierCnt) {
                rangeCnt++;
            }
        }

        System.out.println(minBarrierCnt + " " + rangeCnt);
    }

    // 아래 장애물은 부딪히는 횟수
    static int binarySearch1(int height) {

        int s = 0, e = (N/2) - 1, idx = N/2;
        while (s <= e) {

            int m = (s + e) /2;
            if (height > arr1[m]) {
                s = m + 1;
            }
            else {
                e = m - 1;
                idx = m;
            }
        }

        return N/2 - idx;
    }

    // 위 장애물은 H - 통과하는 횟수
    static int binarySearch2(int height) {

        int s = 0, e = (N/2) - 1, idx = N/2;
        while (s <= e) {

            int m = (s + e) /2;
            if (height > arr2[m]) {
                s = m + 1;
            }
            else {
                e = m - 1;
                idx = m;
            }
        }

        return idx;
    }


    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        arr1 = new int[N/2]; // 아래 장애물
        arr2 = new int[N/2]; // 위 장애물

        for (int i=0; i<N; i++) {

            int num = Integer.parseInt(br.readLine());
            if (i%2 == 0) arr1[cnt1++] = num;
            else arr2[cnt2++] = (H - num);
        }

        solve();
    }
}