
import java.util.*;
import java.io.*;
import java.util.concurrent.ConcurrentHashMap;

public class Main {

    static List<Integer> arr;
    static int N;

    static boolean possible(int mid) {

        int target = 0;

        for (int i=0; i<arr.size(); i++) {

            if (arr.get(i) - mid <= target) {
                target = arr.get(i) + mid;
            } else return false;
        }

        return N - target <= 0;
    }

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        arr = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i=0; i<M; i++) {
            arr.add(Integer.valueOf(st.nextToken()));
        }

        int left = 1, right = N;
        int result = 0;

        while (left <= right) {

            int mid = (left + right) / 2;

            if (possible(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        System.out.println(result);

        br.close();
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}