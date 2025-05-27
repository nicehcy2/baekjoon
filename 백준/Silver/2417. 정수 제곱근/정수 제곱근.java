import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		long N = Long.parseLong(br.readLine());

		long start = 0, end = N, mid = 0, answer = 0;

		while (start <= end) {

			mid = (start + end) / 2;

			if (Math.pow(mid, 2) >= N) {
				answer = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		System.out.println(answer);
	}
}
