import java.util.*;
class weiyunsuan {
  public static void main(String[] args) {
    /*
    int a = 5, b = 10;
    // a = 0101
    // b = 1010
    System.out.println(a & b); // 0000
    System.out.println(a | b); // 1111
    System.out.println(a ^ b); // 1111
    int c = 7, d = 10;
    // c = 0111
    // d = 1010
    System.out.println(c & d); // 0010
    System.out.println(c | d); // 1111
    System.out.println(c ^ d); // 1101
    */

    Scanner in = new Scanner(System.in);
    int e = in.nextInt();
    int f = in.nextInt();
    System.out.println();
    System.out.println(e & f); // 0010
    System.out.println(e | f); // 1111
    System.out.println(e ^ f); // 1101
    
  }  
}
