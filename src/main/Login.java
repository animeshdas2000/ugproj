package main;

import java.util.Scanner;

public class Login {
    public static void main(String args[]) {
        String username, password;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter username:");
        username = s.nextLine();
        System.out.print("Enter password:");
        password = s.nextLine();
        if (username.equals("Animesh") && password.equals("19csu027")) {
            System.out.println("Authentication Successful");
        } else {
            System.out.println("Authentication Failed");
        }
    
}