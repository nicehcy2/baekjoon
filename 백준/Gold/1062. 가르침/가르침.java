import java.util.*;
import java.io.*;

public class Main {

    static int N, K, result = 0;
    static String[] arr;
    static int[] wordVec;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new String[N];
        wordVec = new int[N];

        for (int i=0; i<N; i++) {
            arr[i] = br.readLine();
            for (int j=0; j<arr[i].length(); j++) {
                wordVec[i] |= (1 << (arr[i].charAt(j) - 'a'));
            }
        }
        int flag = 0;
        flag |= (1<<0); // a
        flag |= (1<<2); // c
        flag |= (1<<19); // t
        flag |= (1<<8); // i
        flag |= (1<<13); // n

        if (K < 5) result = 0;
        else if (K == 26) result = N;
        else comb(5, flag, 0);

        System.out.println(result);
        br.close();
    }

    static void comb(int cnt, int flag, int start) {

        if (cnt == K) {
            result = Math.max(result, count(flag));
            return;
        }

        for (int i=start; i<26; i++) {
            if ((flag & (1<<i)) != 0) continue;
            comb(cnt + 1, flag | (1<<i), i + 1);
        }
    }

    static int count(int flag) {

        int sum = 0;
        for (int i=0; i<N; i++) {

            if ((wordVec[i] & ~flag) == 0) sum++;
        }

        return sum;
    }
}