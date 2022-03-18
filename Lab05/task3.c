/*********************
|    Lab 5 Task 3    |
|    Will Townsend   |
|    March  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>

char *myasctime(const struct tm *t){
	char date[24];
	
	char dayW[3];
	if(t.tm_wday==0){dayW="Sun";}
	if(t.tm_wday==1){dayW="Mon";}
	if(t.tm_wday==2){dayW="Tue";}
	if(t.tm_wday==3){dayW="Wed";}
	if(t.tm_wday==4){dayW="Thu";}
	if(t.tm_wday==5){dayW="Fri";}
	if(t.tm_wday==6){dayW="Sat";}
	strcpy(date,dayW);
	strcat(date," ");
	
	char month[3];
	if(t.tm_mon==0){month="Jan";}
	if(t.tm_mon==1){month="Feb";}
	if(t.tm_mon==2){month="Mar";}
	if(t.tm_mon==3){month="Apr";}
	if(t.tm_mon==4){month="May";}
	if(t.tm_mon==5){month="Jun";}
	if(t.tm_mon==6){month="Jul";}
	if(t.tm_mon==7){month="Aug";}
	if(t.tm_mon==8){month="Sep";}
	if(t.tm_mon==9){month="Oct";}
	if(t.tm_mon==10){month="Nov";}
	if(t.tm_mon==11){month="Dec";}
	strcat(date,month);
	strcat(date," ");
	
	int dayM=t.tm_mday;
	char ptrDay[2];
	if(dayM<10){
		strcpy(ptrDay,"0");
		strcat(ptrDay,(char)dayM + '0');
	}
	else{
		while(day!=0){
			strcpy(ptrDay,(char)dayM + '0');
			day/=10;
		}
	}
	strcat(date,dayM);
	strcat(date," ");
	
	char ptrHr[2];
	int hr=t.tm_hour;
	strcat(date,ptrHr);
	strcat(date,":");
	
	char ptrMin[2];
	int min=t.tm_min;
	strcat(date,ptrMin);
	strcat(date,":");
	
	char ptrSec[2];
	int sec=t.tm_sec;
	strcat(date,ptrSec);
	strcat(date," ");
	
	int year=t.tm_year + 1900;
	char ptrYear[4];
	for(year;year!=0;year/10)
	strcat(ptrYear,(char)year + '0');
	strcat(date,ptrYear);
	
	return date;
}

int main(){
	
	return(0);
}
