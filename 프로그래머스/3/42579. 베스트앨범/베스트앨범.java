import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> answer = new ArrayList<>();

        HashMap<String, Integer> genresCnt = new HashMap<>(); // 장르별 총 개수
        HashMap<String, HashMap<Integer, Integer>> music = new HashMap<>(); // 장르에 속하는 노래 및 재생횟수

        for(int i=0; i< plays.length; i++){
            if (!genresCnt.containsKey(genres[i])){
                HashMap<Integer, Integer> map = new HashMap<>();
                map.put(i, plays[i]);
                music.put(genres[i], map);
                genresCnt.put(genres[i], plays[i]);
            }
            else{
                music.get(genres[i]).put(i, plays[i]);
                genresCnt.put(genres[i], genresCnt.get(genres[i]) + plays[i]);
            }

        }

        List<String> keySet = new ArrayList(genresCnt.keySet());
        Collections.sort(keySet, (s1, s2) -> genresCnt.get(s2) - genresCnt.get(s1));


        for (String key : keySet) {
            HashMap<Integer, Integer> map = music.get(key);
            List<Integer> genre_key = new ArrayList(map.keySet());

            genre_key.sort((n1, n2) -> map.get(n2) - map.get(n1));

            answer.add(genre_key.get(0));
            if(genre_key.size() > 1)
                answer.add(genre_key.get(1));
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }
}