import java.util.*;
import java.io.*;

public class Main {
    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        Set<String> s = new HashSet<>();

        for (int i=0; i<N; i++) {

            String log = br.readLine();
            String[] arrStr = log.split(" ");

            if (arrStr[1].equals("enter")) {
                s.add(arrStr[0]);
            } else if (arrStr[1].equals("leave")) {
                s.remove(arrStr[0]);
            }
        }

        List<String> list = new ArrayList<>(s);
        list.sort(Comparator.reverseOrder());

        for (String name : list) {
            bw.write(name + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}