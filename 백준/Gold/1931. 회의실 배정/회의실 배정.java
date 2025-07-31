import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, result = 1;
	static TimeInfo[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new TimeInfo[N];

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());

			arr[i] = new TimeInfo(start, end);
		}

		Arrays.sort(arr, (a, b) -> {
			if (a.getEnd() == b.getEnd()) {
				return Integer.compare(a.getStart(), b.getStart());
			}
			return Integer.compare(a.getEnd(), b.getEnd());
		});

		int prevEnd = arr[0].getEnd();
		for (int i = 1; i < N; i++) {

			int curStart = arr[i].getStart();
			if (curStart >= prevEnd) {
				prevEnd = arr[i].getEnd();
				result++;
			}
		}

		System.out.println(result);
	}

	static class TimeInfo {
		private int start, end;

		TimeInfo(int start, int end) {
			this.start = start;
			this.end = end;
		}

		public int getStart() {
			return start;
		}

		public int getEnd() {
			return end;
		}
	}
}