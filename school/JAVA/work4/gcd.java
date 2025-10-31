import java.util.*;
class prime {
  public static void main(String[] args) {
    int a = Integer.parseInt(args[0]);
    int p[]; p = new int[a];
    int po = 0;
    for(int i = 4; i <= a; i ++) {
      boolean flag = false;
      for(int j = 2; j * j <= i; j ++) {
        if(i % j == 0) flag = true;
      }
      if(flag) continue;
      //System.out.println(i);
      p[po++] = i;
    }
    for(int i = 0; i < po; i ++){
      System.out.print(p[i]); System.out.print(' ');
    }
  }  
}
