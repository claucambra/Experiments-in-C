#include <stdio.h>
#include <string.h>

int zodiac_calc(int in_num, char in_month[]) {

  if ((in_num >= 21 && in_num <= 31 && (strcmp(in_month, "March") == 0)) ||
             (in_num >= 1 && in_num <= 19 && (strcmp(in_month, "April") == 0)))
        puts("Your star sign is Aries.");
    else if ((in_num >= 20 && in_num <= 30 && (strcmp(in_month, "April") == 0)) ||
             (in_num >= 1 && in_num <= 20 && (strcmp(in_month, "May") == 0)))
        puts("Your star sign is Taurus.");
    else if ((in_num >= 21 && in_num <= 31 && (strcmp(in_month, "May") == 0)) ||
             (in_num >= 1 && in_num <= 20 && (strcmp(in_month, "June") == 0)))
        puts("Your star sign is Gemini.");
    else if ((in_num >= 21 && in_num <= 30 && (strcmp(in_month, "June") == 0)) ||
             (in_num >= 1 && in_num <= 22 && (strcmp(in_month, "July") == 0)))
        puts("Your star sign is Cancer.");
    else if ((in_num >= 23 && in_num <= 31 && (strcmp(in_month, "July") == 0)) ||
             (in_num >= 1 && in_num <= 22 && (strcmp(in_month, "August") == 0)))
        puts("Your star sign is Leo.");
    else if ((in_num >= 23 && in_num <= 31 && (strcmp(in_month, "August") == 0)) ||
             (in_num >= 1 && in_num <= 22 && (strcmp(in_month, "September") == 0)))
        puts("Your star sign is Virgo.");
    else if ((in_num >= 23 && in_num <= 30 && (strcmp(in_month, "September") == 0)) ||
             (in_num >= 1 && in_num <= 22 && (strcmp(in_month, "October") == 0)))
        puts("Your star sign is Libra.");
    else if ((in_num >= 23 && in_num <= 31 && (strcmp(in_month, "October") == 0)) ||
             (in_num >= 1 && in_num <= 21 && (strcmp(in_month, "November") == 0)))
        puts("Your star sign is Scorpio.");
    else if ((in_num >= 22 && in_num <= 30 && (strcmp(in_month, "November") == 0)) ||
             (in_num >= 1 && in_num <= 21 && (strcmp(in_month, "December") == 0)))
        puts("Your star sign is Sagittarius.");
    else if ((in_num >= 22 && in_num <= 31 && (strcmp(in_month, "December") == 0)) ||
             (in_num >= 1 && in_num <= 19 && (strcmp(in_month, "January") == 0)))
        puts("Your star sign is Capricorn.");
    else if ((in_num >= 20 && in_num <= 31 && (strcmp(in_month, "January") == 0)) ||
             (in_num >= 1 && in_num <= 18 && (strcmp(in_month, "February") == 0)))
        puts("Your star sign is Aquarius.");
    else if ((in_num >= 19 && in_num <= 29 && (strcmp(in_month, "February") == 0)) ||
             (in_num >= 1 && in_num <= 20 && (strcmp(in_month, "March") == 0)))
        puts("Your star sign is Pisces.");


  return 0;
}

int main() {
  int day = 0, maxDays = 0;
  char month[10];

  puts("Please enter the month (January-December) in which you were born");
  scanf("%9[^\n]", month);
  if(strcmp(month, "February") == 0) {
    maxDays = 29;
  } else if((strcmp(month, "April") == 0) || (strcmp(month, "June") == 0) || (strcmp(month, "September") == 0) || (strcmp(month, "November") == 0)) {
    maxDays = 30;
  } else if((strcmp(month, "January") == 0) || (strcmp(month, "March") == 0) || (strcmp(month, "May") == 0) || (strcmp(month, "July") == 0) || (strcmp(month, "August") == 0) || (strcmp(month, "October") == 0) || (strcmp(month, "December") == 0)) {
    maxDays = 31;
  } else {
    printf("Month '%s' was not recognised.\nPlease make sure you spell the month correctly, capitalising its first letter.\n", month);
    return 1;
  }

  puts("Please enter the numerical day of the month in which you were born");
  scanf("%d", &day);
  while(day <= 0 || day > maxDays) {
    printf("Please enter a plausible numerical day for %s (1-%i)\n", month, maxDays);
    scanf("%d", &day);
  }

  zodiac_calc(day, month);

  return 0;
}
