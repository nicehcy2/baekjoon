import java.io.*;
import java.util.*;

public class Main {
    public static int n;
    public static int[] arr = new int[1001];
    public static int[] dp = new int[1001];
    public static ArrayList<Integer>[] dpSet = new ArrayList[1001];
    public static ArrayList<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.valueOf(br.readLine());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void Solve() throws Exception {
        int max = 1;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            dpSet[i] = new ArrayList<>();
            dpSet[i].add(arr[i]);

            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dpSet[i].clear();
                        dpSet[i].addAll(dpSet[j]);
                        dpSet[i].add(arr[i]);

                        dp[i] = dp[j] + 1;

                        if (max < dp[i]) max = dp[i];
                    }
                }
            }
            if (answer.size() < dpSet[i].size()) {
                answer.clear();
                answer.addAll(dpSet[i]);
            }
        }

        System.out.println(max);
        for (int i = 0; i < answer.size(); i++) {
            System.out.print(answer.get(i) + " ");
        }
        System.out.println();
    }
}