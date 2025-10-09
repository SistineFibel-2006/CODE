import java.util.*;

class hanzi {
  public static void main(String[] args) {
    try{
      System.out.print("insert an chinese character : ");
      Scanner in = new Scanner(System.in);
      String s = in.nextLine();
      char c = s.charAt(0);
      int i;
      for(i = 0X4E00; i <= 0X9FA5; i ++)
        if(c == i) break;
      if(c <= 0X9FA5)
        System.out.println(c + "Unicode : " + Integer.toHexString(i) + " " + i);
      else {
        System.out.println(c + "not an chinese character!");
      }
    }
    catch(Exception e){}
  }
}
