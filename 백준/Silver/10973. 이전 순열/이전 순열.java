import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static List<Integer> arr, result;

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new ArrayList<>();
        result = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i=0; i<N; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        int backup, index = -1, max = -1, index2 = -1;
        for (int i=N-1; i>0; i--) {
            if (arr.get(i - 1) > arr.get(i)) {

                for (int j=i; j<N; j++) {
                    if (arr.get(j) < arr.get(i - 1) && max < arr.get(j)) {
                        max = arr.get(j);
                        index = j;
                    }
                }
                backup = arr.get(i - 1);
                arr.set(i - 1, max);
                arr.set(index, backup);
                index2 = i;

                result = new ArrayList<>(arr.subList(0, i));

                break;
            }
        }

        if (index2 == -1) {
            System.out.println(-1);
            return;
        }

        for (int i = N -1; i>=index2; i--) {
            result.add(arr.get(i));
        }

        for (int i=0; i<result.size(); i++) {
            System.out.print(result.get(i) + " ");
        }
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
