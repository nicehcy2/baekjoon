import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int N, M, sum = 0, max = 0;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			sum += arr[i];
			max = Math.max(max, arr[i]);
		}

		M = Integer.parseInt(br.readLine());

		if (sum <= M) {
			System.out.println(max);
			return;
		}

		int start = 0, end = M, result = 0;

		while (start <= end) {

			int mid = Math.round((start + end) / 2);

			int iSum = 0;
			for (int i = 0; i < N; i++) {
				if (mid < arr[i])
					iSum += mid;
				else
					iSum += arr[i];
			}

			if (iSum <= M) {
				result = mid;
				start = mid + 1;
			} else if (iSum > M) {
				end = mid - 1;
			}
		}

		System.out.println(result);
	}
}