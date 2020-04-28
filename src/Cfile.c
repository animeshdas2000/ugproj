#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct flight
{
    char name[20], source[20], destination[20], time[10], flightnum[20]; //Details of Flight that need to be displayed
    int num_seats, available_seats, booked_seats, charge;
} f;

struct customer
{ //Details of customer to be accepted
    char name[20], father_name[20], dob[10], address[20], country[20];
    int pnum; //Customer's phone no.
} c;

int seat_struct[20]; //Display seat structure of flight

void flight_details();   //Return details of all flight
void specific_details(); //Display all details of flight using flight name
void cust_details();     //Input customer details
void type();             //Assign business or economy class
void login();            //Customer will first have to login
void boardingpass();     //Display final ticket of the customer
void cancel();           //To cancel reservation
void reservation();      //To make a reservation

int main()
{
    int choice;
    for (int i = 0; i < 20; i++)
        seat_struct[i] = 0; //Initialize members to show all seats are empty
    login();
start:
    system("cls");
    printf("Logged in as Anant\n");
    printf("\n==================================\n");
    printf("     FLIGHT RESERVATION SYSTEM");
    printf("\n==================================");
    printf("\n1: Reserve A Ticket");
    printf("\n------------------------");
    printf("\n2: View All Available Flights");
    printf("\n------------------------");
    printf("\n3: Search A Specific Flight");
    printf("\n------------------------");
    printf("\n4: Cancel Reservation");
    printf("\n------------------------");
    printf("\n5: Exit");
    printf("\n------------------------");
    printf("\n\n-->");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        reservation();
        break;
    case 2:
        flight_details();
        break;
    case 3:
        specific_details();
        break;
    case 4:
        cancel();
        break;
    case 5:
        return 0;
        break;
    default:
        printf("\nInvalid choice, press Enter to continue\n");
    }
    printf("\n\nPress Enter to continue: ");
    getch();
    goto start;
    return 0;
}

void flight_details()
{
    char read[50];
    int flag = 0;
    FILE *ptr = fopen("flight.txt", "r+");
    printf("\nName\t\tSource\t\tDestination\t\tTime\t\tFlight Number\n\n");
    while (feof(ptr) == 0)
    {
        fscanf(ptr, "%s ", read);
        printf("%s\t\t", read);
        flag++;
        if (flag == 5)
        {
            printf("\n");
            flag = 0;
        }
    }
}

void specific_details()
{
    char read[50];
    int flag = 0, temp = 0;
    FILE *ptr = fopen("flight.txt", "r+");
start:
    printf("Enter flight name, available flights are\n\n");
    printf("Air_India\nEthihad\nVistara\nQatar_Airways\nAir_Asia\nIndiGo\nSpice_Jet\nAlliance\nGoAir\n\nEnter choice: ");
    fflush(stdin);
    gets(f.name);
    printf("\nName\t\tSource\t\tDestination\t\tTime\t\tFlight Number\n\n");
    while (feof(ptr) == 0)
    {
        fscanf(ptr, "%s ", read);
        if (strcmp(read, f.name) == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                printf("%s\t\t", read);
                fscanf(ptr, "%s ", read);
                flag++;
                temp++;
            }
        }
        if (flag == 5)
        {
            printf("\n");
            flag = 0;
        }
    }
    if (temp == 0)
    {
        system("cls");
        printf("\Wrong input, enter again\n\n");
        goto start;
    }
}

void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "Anant";
    char pass[10] = "anantncu";
    system("cls");
    printf("\t\t\t=============================================\n");
    printf("\t\t\t|                                           |\n");
    printf("\t\t\t|        ---------------------------        |\n");
    printf("\t\t\t|        |Flight RESERVATION SYSTEM|        |\n");
    printf("\t\t\t|        ---------------------------        |\n");
    printf("\t\t\t|                                           |\n");
    printf("\t\t\t=============================================\n\n\n");
    printf("\n************LOGIN************\n  ");
    do
    {
        printf(" \nENTER USERNAME: ");
        scanf("%s", &uname);
        printf(" \nENTER PASSWORD: ");
        for (i = 0; i < 10; i++)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
        }
        pword[i] = '\0';
        if (strcmp(uname, "Anant") == 0 && strcmp(pword, "anantncu") == 0)
        {
            printf("  \n\n\nWelcome to Flight Reservation, Anant. Press Enter to continue: ");
            getch();
            break;
        }
        else
        {
            printf("\n\nWrong credentials, enter again\n\n");
            a++;
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nPassword entered incorrectly too many times, exiting");
        exit(0);
    }
}

void cust_details()
{
    system("cls");
    fflush(stdin);
    printf("\t\t\t|        -----------------------       |\n");
    printf("\t\t\t|        |CUSTOMER REGISTRATION|       |\n");
    printf("\t\t\t|        -----------------------       |\n\n");
    printf("\nEnter your name: ");
    gets(c.name);
    printf("\nEnter father's name: ");
    gets(c.father_name);
    printf("\nEnter Date of Birth (DD/MM/YY): ");
    gets(c.dob);
    printf("\nEnter address: ");
    gets(c.address);
    printf("\nEnter Phone Number: ");
    scanf("%d", &c.pnum);
    fflush(stdin);
    printf("\nEnter country: ");
    gets(c.country);
    FILE *ptr = fopen("customer.txt", "a");
    fprintf(ptr, "%s", c.name);
    fprintf(ptr, "\t\t%s", c.father_name);
    fprintf(ptr, "\t\t%s", c.dob);
    fprintf(ptr, "\t\t%s", c.address);
    fprintf(ptr, "\t\t%s", c.country);
    fprintf(ptr, "\t\t%d\n", c.pnum);
}

void boardingpass()
{
    fflush(stdin);
    system("cls");
    printf("Structure of the plane is:\n");
    for (int i = 1; i < 20; i++)
    {
        printf("%d ", seat_struct[i]);
    }
    printf("0\n\n");
    printf("\t\t==============================================\n");
    printf("\t\t|%s                 %s => %s   |\n", f.name, f.source, f.destination);
    printf("\t\t|                                             |\n");
    printf("\t\t|               ---------------               |\n");
    printf("\t\t|               |BOARDING PASS|               |\n");
    printf("\t\t|               ---------------               |\n");
    printf("\t\t|Your Flight: %s                Time: %s  |\n", f.flightnum, f.time);
    printf("\t\t|                                             |\n");
    printf("\t\t|Seat No.: ");
    for (int i = 1; i < 20; i++)
    {
        if (seat_struct[i] == 1)
            printf("%d,", i);
    }
    printf("         |\n\t\t|                                Price: %d |\n", f.charge);
    printf("\t\t===============================================\n\n\n");
}

void cancel()
{
    char flightnum[20];
    system("cls");
    printf("------------------------\n");
    printf("Enter the flight number: \n");
    fflush(stdin);
    scanf("%s", f.flightnum);
    printf("------------------------\n");
    printf("\n\nTIcket %s canceled. Press Enter to continue", f.flightnum);
    getch();
}

void type()
{
    f.charge = 0;
    int firstClass = 1, economy = 6, choice = 0, i = 0, temp;
    char response[2];
    while (i < 20)
    {
    start:
        printf("\n%s\n%s\n", "Enter 1 for \"First class\"", "Enter 2 for \"Economy\"");
        scanf("%d", &choice);
        if (choice == 2)
        {
            if (!seat_struct[economy] && economy <= 20)
            {
                printf("Your seat assignment is %d cost = 3000\n", economy);
                seat_struct[economy++] = 1;
                i++;
                f.charge += 3000;
                printf("Enter 1 to book more seats, 2 to exit: ");
                scanf("%d", &temp);
                if (temp != 1)
                    goto exit;
            }
            else if (economy > 20 && firstClass <= 5)
            {
                printf("The economy section is full.\n");
                printf("would you like to sit in first class");
                printf("section(Y or N)?");
                scanf("%s", response);
                if (toupper(response[0]) == 'Y')
                {
                    printf("Your seat assignment is %d cost = 5000\n", firstClass);
                    seat_struct[firstClass++] = 1;
                    i++;
                    f.charge += 5000;
                    printf("Enter 1 to book more seats, 2 to exit: ");
                    scanf("%d", &temp);
                    if (temp != 1)
                        goto exit;
                }
                else
                    printf("Next flight leaves in 3 hours.\n");
            }
            if (choice == 1)
            {
                if (!seat_struct[firstClass] && firstClass <= 5)
                {
                    printf("Your seat assignment is%d cost = 5000\n", firstClass);
                    seat_struct[firstClass++] = 1;
                    i++;
                    f.charge += 5000;
                    printf("Enter 1 to book more seats, 2 to exit: ");
                    scanf("%d", &temp);
                    if (temp != 1)
                        goto exit;
                }
                else if (firstClass > 5 && economy <= 20)
                {
                    printf("The firstClass section is full.\n");
                    printf("Would you like to sit in the economy");
                    printf("section (Y or N)?");
                    scanf("%s", response);
                    if (toupper(response[0]) == 'Y')
                    {
                        printf("Your seat assignment is %d cost = 3000\n", economy);
                        seat_struct[economy++] = 1;
                        i++;
                        f.charge += 3000;
                        printf("Enter 1 to book more seats, 2 to exit: ");
                        scanf("%d", &temp);
                        if (temp != 1)
                            goto exit;
                    }
                    else
                        printf("Next flight leaves in 3 hours.\n");
                }
                else
                    printf("Next flight leaves in 3 hours.\n");
            }
        }
        else if (choice == 1)
        {
            if (!seat_struct[firstClass] && firstClass <= 5)
            {
                printf("Your seat assignment is %d cost = 5000\n", firstClass);
                seat_struct[firstClass++] = 1;
                i++;
                f.charge += 5000;
                printf("Enter 1 to book more seats, 2 to exit: ");
                scanf("%d", &temp);
                if (temp != 1)
                    goto exit;
            }
            else if (firstClass > 5 && economy <= 20)
            {
                printf("The first class section is full.\n");
                printf("Would you like to sit in the economy ");
                printf(" section (Y or N)?");
                scanf("%s", response);
                if (toupper(response[0]) == 'Y')
                {
                    printf("Your seat assignment is %d 3000 \n", economy);
                    seat_struct[economy++] = 1;
                    i++;
                    f.charge += 3000;
                    printf("Enter 1 to book more seats, 2 to exit: ");
                    scanf("%d", &temp);
                    if (temp != 1)
                        goto exit;
                }
                else
                    printf("Next flight leaves in 3 hours.\n");
            }
            else
                printf("Next flight leaves in 3 hours.\n");
        }
        else
        {
            printf("Wrong input, enter again\n");
            goto start;
        }
    }
    printf("\nAll the seats for this flight are sold\n");
exit:
    printf("\nPress Enter to continue: ");
    getch();
}

void reservation()
{
    int i = 0, j;
    system("cls");
    cust_details();
    flight_details();
start:
    printf("\nInput Flight Number: ");
    scanf("%s", &f.flightnum);
    char read[50];
    int flag = 0;
    FILE *ptr = fopen("flight.txt", "r+");
    while (feof(ptr) == 0)
    {
        fscanf(ptr, "%s ", read);
        if (strcmp(read, f.flightnum) == 0)
            flag = 1;
    }
    fclose(ptr);
    FILE *ptr1 = fopen("flight.txt", "r+");
    if (flag == 0)
    {
        printf("\nInvalid Flight number\n\n");
        goto start;
    }
    else if (flag == 1)
    {
        while (feof(ptr1) == 0)
        {
            i = ftell(ptr1);
            for (j = 0; j < 5; j++)
            {
                fscanf(ptr1, "%s ", read);
                if (strcmp(read, f.flightnum) == 0)
                {
                    fseek(ptr1, i, SEEK_SET);
                    fscanf(ptr1, "%s ", read);
                    strcpy(f.name, read);
                    fscanf(ptr1, "%s ", read);
                    strcpy(f.source, read);
                    fscanf(ptr1, "%s ", read);
                    strcpy(f.destination, read);
                    fscanf(ptr1, "%s ", read);
                    strcpy(f.time, read);
                    fscanf(ptr1, "%s ", read);
                    strcpy(f.flightnum, read);
                    goto temp;
                }
            }
        }
    }
temp:
    type();
    fclose(ptr1);
    boardingpass();
}
