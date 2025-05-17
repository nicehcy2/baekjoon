import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static List<Integer> list;

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int result = 0;

        for (int i=0; i<N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(list);

        for (int i=0; i<N; i++) {

            int start = 0, end = N - 1;
            while (start < end) {

                if (start == i) {
                    start++; continue;
                }
                if (end == i) {
                    end--; continue;
                }

                if (list.get(start) + list.get(end) > list.get(i)) {
                    end--;
                } else if (list.get(start) + list.get(end) < list.get(i)) {
                    start++;
                } else {
                    if (start != i && end != i) {
                        result++;
                        break;
                    }
                }
            }
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
