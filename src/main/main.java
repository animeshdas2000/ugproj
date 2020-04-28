package main;

import java.io.*;
import java.util.*;
import main.Login;
import main.BoardingPass;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Welcome to Flight Reservation System");
        System.out.println("-------LOGIN PAGE-------");

        System.out.println("*****Main Menu*****");
        System.out.println("1.Reserve Ticket");
        System.out.println("2.View Available FLights");
        System.out.println("3.Search Flights");
        System.out.println("4.Cancel FLights");

        int ch = sc.nextInt();

        /*
         * switch (ch) { case 1: reserve(); break; case 2: avaiable_flights(); break;
         * case 3: search(); break;
         * 
         * case 4:
         * 
         * break; case 5:
         * 
         * break;
         * 
         * default: break; }
         */

        System.out.println("\t\t\t|        -----------------------       |\n");
        System.out.println("\t\t\t|        |CUSTOMER REGISTRATION|       |\n");
        System.out.println("\t\t\t|        -----------------------       |\n\n");
        System.out.println("\nEnter your name: ");
        c.name = nextString();
        System.out.println("\nEnter father's name: ");
        c.father_name = nextString();
        System.out.println("\nEnter Date of Birth (DD/MM/YY): ");
        c.dob = nextString();
        System.out.println("\nEnter address: ");
        c.address = nextString();
        System.out.println("\nEnter Phone Number: ");
        c.pnum = nextDouble();

        System.out.println("\nEnter country: ");
        c.country = nextString();
        FileWriter fw = new FileWriter("D:\\customer.txt");
        fw.write(ptr, "%s", c.name);
        fw.write(ptr, "\t\t%s", c.father_name);
        fw.write(ptr, "\t\t%s", c.dob);
        fw.write(ptr, "\t\t%s", c.address);
        fw.write(ptr, "\t\t%s", c.country);
        fw.write(ptr, "\t\t%d\n", c.pnum);

    }
}