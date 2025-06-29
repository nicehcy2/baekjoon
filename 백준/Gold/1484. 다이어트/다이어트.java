import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static long G;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		G = Long.parseLong(br.readLine());
		StringTokenizer st;
		ArrayList<Long> list = new ArrayList<>();

		long start = 1, end = 2;

		while (true) {

			if (end <= start || end >= 100000 || start >= 100000) {
				break;
			}

			long val = (long) ((long) Math.pow(end, 2) - Math.pow(start, 2));

			if (val == G) {
				list.add(end);
				end++;
				start++;
			}

			else if (G > val) {
				end++;
			} else if (G < val) {
				start++;
			}
		}

		if (list.size() == 0)
			System.out.println(-1);
		else {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < list.size(); i++) {
				sb.append(list.get(i)).append("\n");
			}
			System.out.println(sb);
		}
	}
}