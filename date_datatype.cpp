#include <stdio.h>
typedef enum{
	JANUARY=1, FEBRUARY, MARCH, APRIL, MAY, JUN,JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
}month; 
typedef struct {
	month m;  //month
	int d; //day
}date; // month and day format  m and d

void printDates(date *); //function sing for printingk date
date *next_date(date *);
int n_days;
//********************next_date()***********************
date *next_date(date *dt){
	
	int days;
	
	switch(dt->m){
		case JANUARY:
		case MARCH:
		case MAY:
		case JULY:
		case AUGUST:
		case OCTOBER:
		case DECEMBER:
			days = 31;
			break;
		case APRIL:
		case JUN:
		case SEPTEMBER:
		case NOVEMBER:
			days = 30;
			break;
		case FEBRUARY:
			days = 28;
			break;
		
			
	}
	if(dt->d == days){
		dt->d = (dt->d + 1) % days;
        dt->m = (month)((dt->m + 1) % 12); //next month with type conversion
        
	}else{
		dt->d = dt->d +1;
	}
	return dt;	
}

int main(){
	int i; //index for counter
	
	date date1 = {JANUARY, 1};
	date date2 = {FEBRUARY, 28};
	date date3 = {MARCH, 14};
	date date4 = {OCTOBER, 31};
	date date5 = {DECEMBER, 31};
	date dates[] = {date1, date2, date3, date4, date5};
	
	for(i=0;i<5;i++){ //print dates  
		printf("Date is: ");
		printDates(&dates[i]);
		next_date(&dates[i]);
		printf("Next date is: ");
		printDates(&dates[i]);
		printf("\n");
	}
	
	
	
	return 0;
}

//********************printDates()************************
void printDates(date *dt){
	switch(dt->m){
		case 1: printf("January"); break;
		case 2: printf("February"); break;
		case 3: printf("March"); break;
		case 4: printf("April"); break;
		case 5: printf("May"); break;
		case 6: printf("June"); break;
		case 7: printf("July"); break;
		case 8: printf("August"); break;
		case 9: printf("Septempber"); break;
		case 10: printf("October"); break;
		case 11: printf("November"); break;
		case 12: printf("December"); break;
	}
	printf("%3d",dt->d);
	printf("\n");
}
//*********************
