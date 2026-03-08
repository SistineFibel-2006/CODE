interface Out {
    int test = 123;
    void out();
    default void shout() {
	System.out.println("shout!");
    }
}

interface Jump extends Out {
    default void testJump() {
	System.out.println("Jump!!!");
    }
    void jump();
}

public class inter implements Out, Jump {
    public void jump() {
	System.out.println(test + "jump!");
    }
    public void out() {
	System.out.println(test);
    }
    public static void main(String[] argv) {
	Out A = new inter();
	Jump B = new inter();
	A.out();
	A.shout();
	B.testJump();
	B.jump();
    }
}
