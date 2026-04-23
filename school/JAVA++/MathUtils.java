public class MathUtils {
    private final static double PI = 3.1415926535;
    static double circleArea(double r) {
        return PI * r * r;
    }
    static double circleCircumference(double r) {
        return 2 * PI * r;
    }
    static double rectangleArea(double L, double W) {
        return L * W / 2;
    }
    static double rectanglePerimeter(double L, double W) {
        return L + W + Math.sqrt(L * L + W * W);
    }
    static int add(int a, int b) {
        return a + b;
    }
    static int subtract(int a, int b) {
        return a - b;
    }
}
