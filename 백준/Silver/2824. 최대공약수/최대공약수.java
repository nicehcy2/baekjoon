import java.io.*;
import java.util.*;

public class Main {
    public static int N, M;
    public static long A = 1, B = 1;
    public static long[] arrN = new long[1001];
    public static long[] arrM = new long[1001];
    public static final int div = 1000000000;

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.valueOf(br.readLine());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arrN[i] = (long) Integer.parseInt(st.nextToken());
        }

        M = Integer.valueOf(br.readLine());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            arrM[i] = (long) Integer.parseInt(st.nextToken());
        }
    }

    static void Solve() throws Exception {
        long result = 1;
        boolean flag = false;

        // 데이터 값이 많아 분리해서 계산
        // 나머지를 분리해서 곱해도 값이 똑같다
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // A가 B보다 크거나 같게 만드는 함수
                long a = arrN[i], b = arrM[j];

                if (!max(a, b)) {
                    long temp = a;
                    a = b;
                    b = temp;
                }
                long cur = gdc(a, b);
                result *= cur;

                // 같은 값을 중복해서 곱하는 것을 방지하기 위해 계산을 했으면 나눠줌
                arrN[i] /= cur;
                arrM[j] /= cur;

                if (result >= div) {
                    flag = true;
                    result %= div;
                }
            }
        }

        if (flag) {
            result %= div;

            String strRes = String.valueOf(result);
            String zeroRes = "";

            int zeroCnt = 9 - strRes.length();
            for (int i = 0; i < zeroCnt; i++) {
                zeroRes += "0";
            }
            strRes = zeroRes + strRes;
            System.out.println(strRes);
        } else {
            System.out.println(result);
        }
    }


    static Boolean max(long a, long b) {
        return a >= b ? true : false;
    }

    // 유클리드 호제법(재귀)
    static long gdc(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gdc(b, a % b);
        }
    }
}