import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] arr;
	static long result = Long.MAX_VALUE;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				long sum1 = (long) arr[i] + arr[j];

				int start = 0, end = N - 1;
				while (start < end) {
					while (start == i || start == j) {
						start++;
					}
					while (end == i || end == j) {
						end--;
					}
					if (start >= end)
						break;

					long sum2 = (long) arr[start] + arr[end];

					long diff = Math.abs(sum2 - sum1);

					if (diff < result) {
						result = diff;
					}

					if (sum2 - sum1 > 0) {
						end--;
					} else if (sum2 - sum1 < 0) {
						start++;
					} else {
						System.out.println(0);
						return;
					}
				}
			}
		}

		System.out.println(result);
	}
}