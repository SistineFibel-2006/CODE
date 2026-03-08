public class person {
    private String name;
    private int age;
    public String gname() {
	return name;
    }
    public int gage() {
	return age;
    }
    public void sname(String a) {
	this.name = a;
    }
    public void sage(int a) {
	this.age = a;
    }
    public static void main(String [] argv) {
	person A = new person();
	A.sname("123");
	A.sage(123);
	System.out.println(A.gname());
	System.out.println(A.gage());
    }
}
