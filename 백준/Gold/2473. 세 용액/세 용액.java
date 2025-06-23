import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int N, r1, r2, r3;
	static ArrayList<Integer> pos = new ArrayList<>();
	static ArrayList<Integer> neg = new ArrayList<>();

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			if (num >= 0)
				pos.add(num);
			else
				neg.add(num);
		}

		long val = Long.MAX_VALUE;
		pos.sort((a, b) -> a - b);
		neg.sort((a, b) -> b - a);

		if (pos.size() >= 3) {
			if (val > (long) pos.get(0) + pos.get(1) + pos.get(2)) {
				val = (long) pos.get(0) + pos.get(1) + pos.get(2);
				r1 = pos.get(0);
				r2 = pos.get(1);
				r3 = pos.get(2);
			}
		}

		// TODO
		if (neg.size() >= 3) {
			if (val > Math.abs((long) neg.get(0) + neg.get(1) + neg.get(2))) {
				val = Math.abs((long) neg.get(0) + neg.get(1) + neg.get(2));
				r1 = neg.get(2);
				r2 = neg.get(1);
				r3 = neg.get(0);
			}
		}

		// 음수 더하는 경우
		for (int i = 0; i < pos.size(); i++) {
			int cur = pos.get(i);

			int start = 0, end = neg.size() - 1;
			while (start < end) {
				long sum = neg.get(start) + neg.get(end);

				if (Math.abs(sum + cur) < val) {
					val = Math.abs(sum + cur);
					r1 = neg.get(end);
					r2 = neg.get(start);
					r3 = cur;
				}

				if (sum + cur > 0) {
					start++;
				} else if (sum + cur < 0) {
					end--;
				} else {
					System.out.println(neg.get(end) + " " + neg.get(start) + " " + cur);
					return;
				}
			}
		}

		// 양수 더하는 경우
		for (int i = 0; i < neg.size(); i++) {
			int cur = neg.get(i);

			int start = 0, end = pos.size() - 1;
			while (start < end) {
				long sum = pos.get(start) + pos.get(end);

				if (Math.abs(sum + cur) < val) {
					val = Math.abs(sum + cur);
					r1 = cur;
					r2 = pos.get(start);
					r3 = pos.get(end);
				}

				if (sum + cur > 0) {
					end--;
				} else if (sum + cur < 0) {
					start++;
				} else {
					System.out.println(cur + " " + pos.get(start) + " " + pos.get(end));
					return;
				}
			}
		}

		System.out.println(r1 + " " + r2 + " " + r3);
	}
}