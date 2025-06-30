import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, min = 1_000_000_000, result = 0;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int start = 0, end = N - 1;
		while (start < end) {
			int sum = arr[start] + arr[end];

			if (Math.abs(sum) < min) {
				min = Math.abs(sum);
				result = sum;
			}

			if (sum > 0) {
				end--;
			} else if (sum < 0) {
				start++;
			} else {
				System.out.println(0);
				return;
			}
		}

		System.out.println(result);
	}
}