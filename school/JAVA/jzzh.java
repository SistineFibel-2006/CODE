import java.util.*;

class jzzh {
  public static void main(String[] args) {
    char c;
    int num = 0;
    for(int i = 0X4E00; i <= 0X9FA5; i ++) {
      num = num + 1;
      c = (char)i;
      System.out.print(i + ": " + c + " ");
      if(num % 10 == 0)
      System.out.print('\n');
    }
    System.out.print('\n');
    System.out.print("total : " + num);
  }
}
