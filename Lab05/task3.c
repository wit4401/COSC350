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
	int check=t->tm_wday;
	if(check==0){dayW="Sun";}
	if(check==1){dayW="Mon";}
	if(check==2){dayW="Tue";}
	if(check==3){dayW="Wed";}
	if(check==4){dayW="Thu";}
	if(check==5){dayW="Fri";}
	if(check==6){dayW="Sat";}
	strcpy(date,dayW);
	strcat(date," ");
	
	//sets up the current month and stores it in date
	char *month;
	check=t->tm_mon;
	if(check==0){month="Jan";}
	if(check==1){month="Feb";}
	if(check==2){month="Mar";}
	if(check==3){month="Apr";}
	if(check==4){month="May";}
	if(check==5){month="Jun";}
	if(check==6){month="Jul";}
	if(check==7){month="Aug";}
	if(check==8){month="Sep";}
	if(check==9){month="Oct";}
	if(check==10){month="Nov";}
	if(check==11){month="Dec";}
	strcat(date,month);
	strcat(date," ");
	
	//sets up the day of the month and stores it in date
	int dayM=t->tm_mday;
	int dig;
	char insert;
	for(int i=0;i<2;i++){
	    dig=dayM%10;
	    dig=dig+'0';
	    insert=(char)dig;
	    strcat(date,&insert);
	    dayM=dayM/10; 
	}
	strcat(date," ");
	
	//sets up the hour of the day and stores it in date
	int hr=t->tm_hour;
	for(int i=0;i<2;i++){
            dig=hr%10;
	    dig=dig+'0';
            insert=(char)dig;
            strcat(date,&insert);
	    hr=hr/10;
        }
	strcat(date,":");
	
	//sets up the min of the hour and stores it in date
	int min=t->tm_min;
	for(int i=0;i<2;i++){
            dig=min%10;
	    dig=dig+'0';
            insert=(char)dig;
            strcat(date,&insert);
	    min=min/10;
        }
	strcat(date,":");
	
	//sets up the second of the min and stores it in date
	int sec=t->tm_sec;
	for(int i=0;i<2;i++){
            dig=sec%10;
	    dig=dig+'0';
            insert=(char)dig;
            strcat(date,&insert);
	    sec=sec/10;
        }
	strcat(date,":");
	
	//sets up the year and stores it in date
	int year=t->tm_year + 1900;
	for(int i=0;i<4;i++){
            dig=year%10;
	    dig=dig+'0';
            insert=(char)dig;
            strcat(date,&insert);
	    year=year/10;
        }
	return date;
}

int main(){
	const struct tm *currTime;
	time_t t;
	char *res;

	time(&t);
	currTime=localtime(&t);
	res=myasctime(currTime);
	printf("%s",res);
	puts("");
	return(0);
}
