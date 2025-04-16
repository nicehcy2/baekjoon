
import java.util.*;
import java.io.*;

public class Main {

    static int T;

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        while (T > 0) {

            long result = 0;
            int N = Integer.parseInt(br.readLine());
            ArrayList<Integer> arr = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            for (int i=0; i<N; i++) {
                arr.add(Integer.parseInt(st.nextToken()));
            }

            int max = 0;
            for (int i=arr.size() - 1; i>=0; i--) {
                if (max < arr.get(i)) {
                    max = arr.get(i);
                }
                else {
                    result += max - arr.get(i);
                }
            }

            System.out.println(result);
            T--;
        }

        br.close();
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}