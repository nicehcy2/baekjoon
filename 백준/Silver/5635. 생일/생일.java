import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.*;

public class Main {

    private static int n;
    private static Map<String, Long> map = new HashMap<>();

    public void Input() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        String name;
        int day, mon, year;

        for (int i=0; i<n; i++) {

            st = new StringTokenizer(br.readLine(), " ");

            name = st.nextToken();
            day = Integer.parseInt(st.nextToken());
            mon = Integer.parseInt(st.nextToken());
            year = Integer.parseInt(st.nextToken());

            LocalDate date = LocalDate.of(year, mon, day);
            map.put(name, ChronoUnit.DAYS.between(date, LocalDate.now()));
        }
    }

    public void Solution() throws Exception {

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String oldestPerson = Collections.max(map.entrySet(), Map.Entry.comparingByValue()).getKey();
        String youngestPerson = Collections.min(map.entrySet(), Map.Entry.comparingByValue()).getKey();

        bw.write(youngestPerson + '\n' + oldestPerson + '\n');
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().Input();
        new Main().Solution();
    }
}