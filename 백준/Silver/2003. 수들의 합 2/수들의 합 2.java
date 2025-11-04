import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[] prefixNum;

    static void solve() {

        int answer = 0;
        for (int i=0; i<=N; i++) {

            int cur = prefixNum[i];
            int target = M + cur;
            int s = i + 1, e = N;

            while (s <= e) {
                int mid = (s + e) / 2;

                if (target > prefixNum[mid]) s = mid + 1;
                else if (target < prefixNum[mid]) e = mid - 1;
                else {
                    answer++;
                    break;
                }
            }
        }

        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        prefixNum = new int[N + 1];
        st= new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            int num = Integer.parseInt(st.nextToken());
            prefixNum[i + 1] = prefixNum[i] + num;
        }

        solve();
    }
}