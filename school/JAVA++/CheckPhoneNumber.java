import java.util.*;
import java.util.regex.*;
import java.util.regex.*;
public class CheckPhoneNumber {
    public static void main(String []argv) {
        Pattern p = Pattern.compile("1[3-9]\\d{9}$");
        if(argv[0] == null)
            System.out.println("ERROR!");
        else {
            Matcher m = p.matcher(argv[0]);
            if(m.matches()) {
               System.out.println("YES");
                }
                else {
                    System.out.println("No");
                }

        }
    }
}
