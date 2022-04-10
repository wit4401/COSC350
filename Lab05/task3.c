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
	char *date=calloc(24,sizeof(char)); //date will contian the result to be returned
	
	//sets up the day of the week and stores it in date
	char *dayW;
	int check=t->tm_wday;//defines check with the day of the week 0-6 (Sun-Sat)
	if(check==0){dayW="Sun";}
	else if (check==1){dayW="Mon";}
	else if(check==2){dayW="Tue";}
	else if(check==3){dayW="Wed";}
	else if(check==4){dayW="Thu";}
	else if(check==5){dayW="Fri";}
	else if(check==6){dayW="Sat";}
	strcpy(date,dayW);
	strcat(date," ");
	
	//sets up the current month and stores it in date
	char *month;
	check=t->tm_mon;//redefines check with the month of the year 0-11 (Jan-Dec)
	if(check==0){month="Jan";}
	else if(check==1){month="Feb";}
	else if(check==2){month="Mar";}
	else if(check==3){month="Apr";}
	else if(check==4){month="May";}
	else if(check==5){month="Jun";}
	else if(check==6){month="Jul";}
	else if(check==7){month="Aug";}
	else if(check==8){month="Sep";}
	else if(check==9){month="Oct";}
	else if(check==10){month="Nov";}
	else if(check==11){month="Dec";}
	strcat(date,month);
	strcat(date," ");
	
	//sets up the day of the month and stores it in date
	int dayM=t->tm_mday;
	int dig;
    	char arrInt[]="00";
	for(int i=0;i<2;i++){
	    dig=dayM%10;
	    dig=dig+'0';
	    arrInt[1-i]=(char)dig;
	    dayM=dayM/10; 
	}
	strcat(date,arrInt);
	strcat(date," ");
	
	//sets up the hour of the day and stores it in date
	int hr=t->tm_hour;
    	for(int i=0;i<2;i++){
            dig=hr%10;
	    dig=dig+'0';
            arrInt[1-i]=(char)dig;
	    hr=hr/10;
    	}
    	strcat(date,arrInt);
    	strcat(date,":");
	
    	//sets up the min of the hour and stores it in date
    	int min=t->tm_min;
    	for(int i=0;i<2;i++){
            dig=min%10;
            dig=dig+'0';
            arrInt[1-i]=(char)dig;
	    min=min/10;
    	}
    	strcat(date,arrInt);
    	strcat(date,":");
	
    	//sets up the second of the min and stores it in date
    	int sec=t->tm_sec;
    	for(int i=0;i<2;i++){
            dig=sec%10;
	    dig=dig+'0';
            arrInt[1-i]=(char)dig;
	    sec=sec/10;
    	}
    	strcat(date,arrInt);
    	strcat(date," ");
	
    	//sets up the year and stores it in date
    	int year=t->tm_year + 1900;
    	char arrInt2[]="0000";
    	for(int i=0;i<4;i++){
            dig=year%10;
            dig=dig+'0';
            arrInt2[3-i]=(char)dig;
	    year=year/10;
    	}
    	strcat(date,arrInt2);
    	return date;
}

int main(){
	struct tm *currTime=malloc(sizeof(struct tm));
	time_t t;

	time(&t);
	currTime=localtime(&t);
	puts("Current Local Time:");printf("%s\n",myasctime(currTime));
	free(currTime);
	exit(0);
}
