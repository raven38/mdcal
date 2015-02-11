#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year){
  return year%4==0 && (year%100 || year%400 == 0);
}

int daysOfTheWeek(int year, int month, int day){
  return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day)%7;
}

int main(int argc, char *argv[]){
  int d[]={31,28,31,30,31,30,31,31,30,31,30,31};
  int year, month;
  year = atoi(argv[1]);
  month = atoi(argv[2]);

  int c = daysOfTheWeek(month<=2?year-1:year,month<=2?month+12: month, 1);

  printf("%d\n", c);
  int day = d[month-1];
  if(month == 2) day += isLeapYear(year);
  for(int i=0;i<c;i++) printf("  ");
  for(int i=1;i<=day;i++){
    printf("%2d", i);
    c++;
    if(c >= 7){
      puts("");
      c = 0;
    }
  }
  if(c) puts("");
  return 0;
}
