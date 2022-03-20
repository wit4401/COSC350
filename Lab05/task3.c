/*********************
|    Lab 5 Task 3    |
|    Will Townsend   |
|    March  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *myasctime(const struct tm *t){
	char date[24]; //date will contian the result to be returned
	
	//sets up the day of the week and stores it in date
	char *dayW;
	if(t->tm_wday==0){dayW="Sun";}
	if(t->tm_wday==1){dayW="Mon";}
	if(t->tm_wday==2){dayW="Tue";}
	if(t->tm_wday==3){dayW="Wed";}
	if(t->tm_wday==4){dayW="Thu";}
	if(t->tm_wday==5){dayW="Fri";}
	if(t->tm_wday==6){dayW="Sat";}
	strcpy(date,dayW);
	strcat(date," ");
	
	//sets up the current month and stores it in date
	char *month;
	if(t->tm_mon==0){month="Jan";}
	if(t->tm_mon==1){month="Feb";}
	if(t->tm_mon==2){month="Mar";}
	if(t->tm_mon==3){month="Apr";}
	if(t->tm_mon==4){month="May";}
	if(t->tm_mon==5){month="Jun";}
	if(t->tm_mon==6){month="Jul";}
	if(t->tm_mon==7){month="Aug";}
	if(t->tm_mon==8){month="Sep";}
	if(t->tm_mon==9){month="Oct";}
	if(t->tm_mon==10){month="Nov";}
	if(t->tm_mon==11){month="Dec";}
	strcat(date,month);
	strcat(date," ");
	
	//sets up the day of the month and stores it in date
	int dayM=t->tm_mday;
	char ptrDay[2];
	/*
     * To be added
     */
	strcat(date,ptrDay);
	strcat(date," ");
	
	//sets up the hour of the day and stores it in date
	char ptrHr[2];
	int hr=t->tm_hour;
    /*
     * To be added
     */
	strcat(date,ptrHr);
	strcat(date,":");
	
	//sets up the min of the hour and stores it in date
	char ptrMin[2];
	int min=t->tm_min;
	/*
     * To be added
     */
	strcat(date,ptrMin);
	strcat(date,":");
	
	//sets up the second of the min and stores it in date
	char ptrSec[2];
	int sec=t->tm_sec;
    /*
     * To be added
     */
	strcat(date,ptrSec);
	strcat(date," ");
	
	//sets up the year and stores it in date
	int year=t->tm_year + 1900;
    /*
     * To be added
     */
	strcat(date,ptrYear);
	
	return date;
}

int main(){
	const struct tm *currTime;
    time_t t;
    time(&t);
    currTime=localtime(&t);
	puts(myasctime(currTime));
	return(0);
}
