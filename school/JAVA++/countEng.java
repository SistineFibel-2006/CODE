import java.util.*;
import java.util.regex.*;

public class countEng {
    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        Pattern b = Pattern.compile("[A-Za-z]+");
        Matcher word = b.matcher(a);
        int cnt = 0;
        while(word.find()) cnt ++;
        System.out.println("cntWord = " + cnt);
        int cntw[] = new int[26];
        Pattern c = Pattern.compile("[A-Za-z]");
        Matcher d = c.matcher(a);
        while(d.find()) {
            char x = d.group().toLowerCase().charAt(0);
            cntw[x - 'a'] ++;
        }
        for (int i = 0; i < 26; i ++) {
            System.out.println("\"" + (char)('a' + i) + "\"  = " + cntw[i]);
        }
    }
}
