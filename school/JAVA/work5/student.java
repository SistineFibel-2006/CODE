package work5;

import java.util.*;
class wk{
  public static void main(String[] args) {
      student ans [] = new student[10];

  }
}

class student {
  private String name;
  private int age;
  private int gender;
  private String phone;
  private String address;
  private String email;
  public student(){}
  public student(String name,int age,int gender,String phone,String address,String email) {
    this.name = name;
    this.age = age;
    this.gender = gender;
    this.phone = phone;
    this.address = address;
    this.email = email;
  }
  public student(student x) {
    this.name = x.name;
    this.age = x.age;
    this.gender = x.gender;
    this.phone = x.phone;
    this.address = x.address;
    this.email = x.email;    
  }
  public String getname() {
    return this.name;
  }
  public int getage() {
    return this.age;
  }
  public String getgender() {
    if(this.gender == 1) return "Male";
    return "Female"; 
  }
  public String getphone() {
    return this.phone;
  }
  public String getaddress() {
    return this.address;
  }
  public String getemail() {
    return this.email;
  }
  public void setname(String name) {
    this.name = name; 
  }
  public void setage(int age) {
    this.age = age;
  }
  public void setgender() {
    System.out.println("plz enter gender: Male/Female");
    Scanner sc = new Scanner(System.in);
    String gen = sc.next();
    if(gen == "Male")
      this.gender = 1;
    else if(gen == "Female") 
      this.gender = 0;
    else 
      System.out.println("ERROR!");
  }
  public void setphone(String phone) {
    this.phone = phone;
  }
  public void setaddress(String add) {
    this.address = add;
  }
  public void setemail(String em) {
    this.email = em;
  } 
  public boolean find(String name, String address, String email) {
    if(this.name == name && this.address == address && this.email == email)
      return true;
    return false;
  } 
}