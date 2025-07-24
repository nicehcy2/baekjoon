import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static ArrayList<Integer> crane = new ArrayList<>(), box = new ArrayList<>();

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			crane.add(Integer.parseInt(st.nextToken()));
		}

		M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			box.add(Integer.parseInt(st.nextToken()));
		}

		crane.sort((a, b) -> Integer.compare(b, a));
		box.sort((a, b) -> Integer.compare(b, a));

		if (box.get(0) > crane.get(0)) {
			System.out.println(-1);
			return;
		}

		long time = 0;
		while (!box.isEmpty()) {

			for (int i = 0; i < crane.size(); i++) {
				for (int j = 0; j < box.size(); j++) {
					if (box.get(j) <= crane.get(i)) {
						box.remove(j);
						break;
					}
				}
			}

			time++;
		}

		System.out.println(time);
	}
}