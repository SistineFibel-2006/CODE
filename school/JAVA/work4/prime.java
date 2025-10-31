import java.util.*;
class prime {
  static int gcd(int a, int b)  {
    if(a < b) {
      int r = a;
      a = b;
      b = r;
    }
    while(b != 0) {
      int r = a % b;
      a = b;
      b = r;
    }
    return a;
  }
  public static void main(String[] args) {
    int a = Integer.parseInt(args[0]);
    int b = Integer.parseInt(args[1]);
    int ans = gcd(a, b);
    System.out.println(ans);
  }  
}
