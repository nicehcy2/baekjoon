import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			int[] arr = new int[N];

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}

			Arrays.sort(arr);

			int start = 0, end = N - 1, min = 500_000_005, count = 0;
			while (start < end) {
				int sum = arr[start] + arr[end];

				if (Math.abs(sum - K) < min) {
					min = Math.abs(sum - K);
					count = 1;
				} else if (Math.abs(sum - K) == min) {
					count++;
				}

				if (sum - K < 0) {
					start++;
				} else if (sum - K > 0) {
					end--;
				} else {
					start++;
					end--;
				}
			}

			sb.append(count).append("\n");
		}

		System.out.println(sb);
	}
}