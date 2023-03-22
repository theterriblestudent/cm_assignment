#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************************
*                              Exercise 1.1(A)                                  *
*********************************************************************************/

int get_day_of_the_week(char*); //date format: dd/mm/yyyy
int get_day_index(int, int, int);
char* get_day_name(int);
void generate_calender(int, int);
char* get_month_name(int);

int get_day_of_the_week(char* input_date) {
    if(input_date == NULL) {
        printf("Invalid Date!");
        return 8;
    }
    char date[10];
    strcpy(date, input_date);

    char* token = strtok(date, "/");
    int date_day = atoi(token);
    int month, year;

    int i = 0;
    while (token != NULL) {
        if (i == 1) month = atoi(token);
        else year = atoi(token);
        i++;

        token = strtok(NULL, "/");
    }

    return get_day_index(date_day, month, year);
}

int get_day_index(int date_day, int month, int year) {

    int m1 = (month >= 3) ? month - 2 : month + 10;
    year = (month >= 3) ? year : year - 1;

    int ns = year / 100;
    int as = year % 100;

    int non_mod = date_day + as + (as/4) - (2*ns) + (ns / 4) + ((26 * m1 -2)/10);

    int day_index = non_mod % 7;

    return (day_index < 0) ? 7 + day_index : day_index;

}

char* get_day_name(int day_index) {
    switch(day_index) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: {
            return "Invalid Index";
        }
    }
}

/*****************************************************************************
*                               Exercse 1.1(B)                               *
******************************************************************************/

char* get_month_name(int month_index){
    switch(month_index) {
        case 1: return "Jan";
        case 2: return "Feb";
        case 3: return "Mar";
        case 4: return "Apr";
        case 5: return "May";
        case 6: return "Jun";
        case 7: return "Jul";
        case 8: return "Aug";
        case 9: return "Sep";
        case 10: return "Oct";
        case 11: return "Nov";
        case 12: return "Dec";
        default: return "Invalid Month";
    }
}

void generate_calender(int month_index, int year) {

    int j = get_day_index(1, month_index, year);
    int n;
    printf("*******************************************************\n");
    printf("*                       %s %d                      *\n", get_month_name(month_index), year);
    printf("*  S   *   M   *   T   *   W   *   T   *   F   *   S  *\n");
    printf("*      *       *       *       *       *       *      *\n");
    printf("*******************************************************\n");

    if (month_index == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            n = 29;
        else n = 28;
    }
    else if (month_index == 4 || month_index == 6 || month_index == 9 || month_index == 11) {
        n = 30;
    }
    else n = 31;

    for(int i = 0; i <= n; i++) {
        if (i == 0) {
            printf("*  ");
            for(int k = 0; k < j; k++) {
                printf("        "); get_day_index(1, month_index, year);
            }
            continue;
        }

        if (j % 6 == 0 && j <= 7 && j > 0) {
            printf("%d  *\n*                                                     *\n*  ", i);
            j++;
            continue;
        }

        if (j % 7 == 6 && j > 7) {
            if(i < 10)
                printf("%d  *\n*                                                     *\n*  ", i);
            else
                printf("%d *\n*                                                     *\n*  ", i);

            j++;
            continue;
        }



        if(i == n && get_day_index(1, month_index, year) > 0) {
            printf("%d", i);
            for(int k = 0; k <= get_day_index(1, month_index, year); k++) {
                printf("       ");
            }
            printf("*");
            continue;
        }
        if (i < 10)
            printf("%d       ", i);
        else
            printf("%d      ", i);
        j++;
    }

    printf("\n*                                                     *\n");
    printf("*******************************************************\n");
}

/*****************************************************************************
*                               Exercse 1.1(C)                               *
******************************************************************************/

void get_year_calender(int year) {
    for(int i = 1; i <= 12; i++) {
        generate_calender(i, year);
        printf("\n");
    }
}

void main() {
    while(1) {
        printf("Welcome to my program!\n");
        printf("Menu:\n1.Check the day of the week of a given South African Public Holiday.\n");
        printf("2.Generate and display on the screen the calender of a given month of a given year.\n");
        printf("3.Generate and save in memory the calender of a given year.\n");
        printf("4.Exit\n");

        int option;
        printf("Select an option: ");

        scanf("%d", &option);

        if (option == 1) {
            printf("1. Choose a South African Holiday\n");
            printf("2. Enter your own custom date\n");

            printf("Response: ");
            scanf("%d", &option);

            if(option == 1) {
                printf("1. Workers Day (01 May 2023)\n");
                printf("2. Freedom Day (27 April 2023)\n");
                printf("3. Human Rights Day (21 March 2023)\n");
                printf("Response: ");
                char* dates[] = {"01/05/2023", "27/04/2023", "21/03/2023"};

                scanf("%d", &option);

                printf("The selected holiday is on %s!\n", get_day_name(get_day_of_the_week(dates[option - 1])));
                printf("\n\n");
            } else if (option == 2) {
                printf("Input date (dd/mm/yyyy): ");
                char* input_date;
                scanf("%s", input_date);
                printf("The holiday is on %s!\n", get_day_name(get_day_of_the_week(input_date)));
                printf("\n\n");
            }

            else{
                printf("Invalid option!\n\n");
                continue;
            }
        }

        else if(option == 2) {
            printf("Input the month (1 is Jan, 2 is Feb..., 12 is Dec): ");
            scanf("%d", &option);
            printf("Input year (yyyy): ");
            int year;
            scanf("%d", &year);
            generate_calender(option, year);
            printf("\n\n");

        }

        else if (option == 3) {
            printf("Input year(yyyy): ");
            scanf("%d", &option);
            get_year_calender(option);
            printf("\n\n");
        }

        else if (option == 4) {
            break;
        }

        else{
            printf("Invalid Option!\n\n");
            continue;
        }
    }
    
}