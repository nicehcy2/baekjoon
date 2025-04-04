import java.util.*;
import java.io.*;

public class Main {

    public static void solution() throws IOException {

        // 타입 주의!!!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long min = Long.parseLong(st.nextToken());
        long max = Long.parseLong(st.nextToken());

        int sqrt = (int) Math.sqrt(max);
        int count = (int) (max - min + 1); // 방문 배열 압축 (max는 min + 1000000보다 클 수 없다)
        boolean[] visited = new boolean[count];

        // 에라토스테네스의 체 기반으로 문제를 풀자 (제곱수 버전으로)
        for (long i=2; i<=sqrt; i++) {

            long squared = i * i;
            long start = min % squared == 0 ? min / squared : (min / squared) + 1; // squared의 배수이면서 min 이상인 수를 구하는 공식

            for (long j = start; j * squared <= max; j++) {
                if (!visited[(int) (j * squared - min)]) {
                    visited[(int) (j * squared - min)] = true;
                    count--;
                }
            }
        }

        System.out.println(count);

        br.close();
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}