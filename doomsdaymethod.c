//by Jeremy Feltracco
//date: 7 december 2012
//doomsday algorithm: find day of week of any num

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582
#define DAYS_IN_WEEK 7
#define GREGOR_REPEAT 400
#define END_OF_FOUR_DIGIT 9999
#define LEAP_YEAR_REPEAT_PLUS_ONE 12
#define THURSDAY 4

//int daysToNextThursday (int year, int month, int day);
int yearToDoomsday (int year);
int centuryDoomsday (int year);
int yearToCentury (int year);
int isLeapYear (int year);
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int daysToNextThursday (int year, int month, int day);

int main (int argc, char *argv[])
{
	int year;
	int month;
	int day;
   
	printf ("Type year #: ");
   
	scanf ("%d", &year);
   
	printf ("Type month #: ");
   
	scanf ("%d", &month);
   
	printf ("Type day #: ");
   
	scanf ("%d", &day);
   
//   assert (year >= START_OF_GREG_CALENDAR);
//   assert (year <= END_OF_FOUR_DIGIT);
	int tempVar = daysToNextThursday (year, month, day);
	printf ("Day of week is %d\n", tempVar);

	return EXIT_SUCCESS;
}



int daysToNextThursday (int year, int month, int day) {
	int doomsday = yearToDoomsday (year);
	int leapYear = isLeapYear(year);
	int weekDay = dayOfWeek (doomsday, leapYear, month, day);
	
	int daysToThursday = (THURSDAY - weekDay) % 7;
	
	return daysToThursday;
}

int yearToDoomsday (int year) {
	int centdoomyday = centuryDoomsday (year);
	int century = yearToCentury (year);
	
	int lastDigitsYear = year - century;
	int divTwelve = lastDigitsYear / 12;
	int remainderTwelve = lastDigitsYear % 12;
	int divFour = remainderTwelve / 4;
	int addNums = divTwelve + remainderTwelve + divFour;
	int modSeven = addNums % 7;
	int addAnchor = modSeven + centdoomyday;
	int doomsday = addAnchor % 7;
	
	printf ("Doomsday is: %d\n", doomsday);

	return doomsday;
}

int centuryDoomsday (int year) {
	//Rounds to nearest hundreds spot, ex 1592 becomes 1500
	int century;
	
	century = yearToCentury (year);
	
	
	int doomremainder = century % GREGOR_REPEAT;
	
	// Only works in 4 digit years
	int centdoomyDay;
	
	if (doomremainder == 0) {
		centdoomyDay = 2;
	}
	if (doomremainder == 100) {
		centdoomyDay = 0;
	}
	if (doomremainder == 200) {
		centdoomyDay = 5;
	}
	if (doomremainder == 300) {
		centdoomyDay = 3;
	}
	
	return centdoomyDay;
		
}

int yearToCentury (int year) {
	//converts year to it's century
	int fracYear = year / 100;
	int century = fracYear * 100;
	return century;
}

int isLeapYear (int year) {
   int boolHold;
   if ((year % 4) == 0 ) {
	   if ((year % 100) == 0 ) {
		   if ((year % 400) == 0) {
			   boolHold = 1;
		   } else {
			   boolHold = 0;
		   }
	   } else {
		   boolHold = 1;
	   }
   } else {
	   boolHold = 0;
   }
   return boolHold;
}

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
	int weekDay = EXIT_FAILURE;
	if (month == 1) {
		if (leapYear == 0) {
			weekDay = (doomsday - (3 - day % DAYS_IN_WEEK)) % 7;
		}
		if (leapYear == 1) {
			weekDay = (doomsday - (4 - day % DAYS_IN_WEEK)) % 7;
		}
		
	}
	if (month == 2) {
		if (leapYear == 0) {
			weekDay = (doomsday - (0 - day % DAYS_IN_WEEK)) % 7;
		}
		if (leapYear == 1) {
			weekDay = (doomsday - (1 - day % DAYS_IN_WEEK)) % 7;
		}
	}
	if (month == 3) {
		weekDay = (doomsday - (0 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 4) {
		weekDay = (doomsday - (4 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 5) {
		weekDay = (doomsday - (2 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 6) {
		weekDay = (doomsday - (6 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 7) {
		weekDay = (doomsday - (4 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 8) {
		weekDay = (doomsday - (8 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 9) {
		weekDay = (doomsday - (5 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 10) {
		weekDay = (doomsday - (3 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 11) {
		weekDay = (doomsday - (0 - day % DAYS_IN_WEEK)) % 7;
	}
	if (month == 12) {
		weekDay = (doomsday - (5 - day % DAYS_IN_WEEK)) % 7;
	}
	return weekDay;
}
