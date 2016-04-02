/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if ((date1head == NULL) || (date2head == NULL)){
		return -1;
	}
	else{
		struct node *temp1 = date1head, *temp2 = date2head;
		int no_of_days, day1 = 0,mon1=0, year1 = 0, count = 1;
		while ((temp1 != NULL) && (temp2 != NULL)){
			if (count == 1){
				day1 = temp1->data - temp2->data;
				if (day1 < 0){
					day1 = -day1;
				}
				day1 = day1 * 10;
			}
			if (count == 2){
				if (temp1->data - temp2->data < 0){
					day1 = day1 + (-(temp1->data - temp2->data));
				}
				else{
					day1 = day1 + (temp1->data - temp2->data);
				}
			}
			if (count == 3){
				mon1 = temp1->data - temp2->data;
				if (mon1 < 0){
					mon1 = -mon1;
				}
				mon1 = mon1 * 10;
			}
			if (count == 4){
				if (temp1->data - temp2->data < 0){
					mon1 = mon1 + (-temp1->data - temp2->data);
				}
				else{
					mon1 = mon1 + (temp1->data - temp2->data);
				}
			}
			if (count == 5){
				year1 = temp1->data - temp2->data;
				if (year1 < 0){
					year1 = -year1;
				}
				year1 = year1 * 1000;
			}
			if (count == 6){
				if (temp1->data - temp2->data < 0){
					year1 = year1 + (-temp1->data - temp2->data) * 100;
				}
				else{
					year1 = year1 + (temp1->data - temp2->data) * 100;
				}
			}
			if (count == 7){
				year1 = temp1->data - temp2->data;
				if (year1 < 0){
					year1 = -year1;
				}
				year1 = year1 * 10;
			}
			if (count == 8){
				if (temp1->data - temp2->data < 0){
					year1 = year1 + (-(temp1->data - temp2->data));
				}
				else{
					year1 = year1 + (temp1->data - temp2->data);
				}
			}
			count++;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		int leap_days = year1 / 4;
		no_of_days = (day1-1) + mon1 * 30 + year1 * 365 + leap_days;
		return no_of_days;
	}
}