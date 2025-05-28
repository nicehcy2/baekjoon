import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] vertex;

	static int upperBound(int target) {

		int start = 0, end = N - 1, result = -1;

		while (start <= end) {

			int mid = (start + end) / 2;

			if (vertex[mid] <= target) {
				result = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		return result;
	}

	static int lowerBound(int target) {

		int start = 0, end = N - 1, result = -1;

		while (start <= end) {

			int mid = (start + end) / 2;

			if (vertex[mid] >= target) {
				result = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		return result;
	}

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		vertex = new int[N];
		int max = 0, min = 1000000001;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			vertex[i] = Integer.parseInt(st.nextToken());
			max = Math.max(max, vertex[i]);
			min = Math.min(min, vertex[i]);
		}

		Arrays.sort(vertex);

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());

			if (max < start || min > end)
				System.out.println(0);
			else
				System.out.println(upperBound(end) - lowerBound(start) + 1);
		}
	}
}