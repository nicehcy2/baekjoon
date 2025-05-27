import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int K, N;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		K = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr = new int[K];

		int max = 0;
		for (int i = 0; i < K; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			max = Math.max(arr[i], max);
		}

		long start = 1, end = max, result = 0;

		while (start <= end) {

			long mid = (start + end) / 2;

			long sum = 0;
			for (int i = 0; i < K; i++) {
				sum += (arr[i] / mid);
			}

			if (sum < N) {
				end = mid - 1;
			} else {
				result = mid;
				start = mid + 1;
			}
		}

		System.out.println(result);
	}
}