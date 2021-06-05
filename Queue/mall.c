#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue.h"
#define MIN_PER_HR 60.0


bool newcustomer(double x);
Item customertime(long when);

int mall() {
	Queue line;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways=0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	double min_per_cust;
	long line_wait = 0;
	InitializeQueue(&line);
	srand((unsigned int)time(0));
	puts("Case study:sigmund lander's Advice booth");
	puts("Enter the number of simulation horse:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average  number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;
	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line)) {
				turnaways++;
			}
			else {
				customers++;
				temp=customertime(cycle);
				EnQueue(temp, &line);
			}
		}
	}
	if (wait_time <= 0 && !QueueIsEmpty(&line)) {
		DeQueue(&temp, &line);
		wait_time = temp.processtime;
		line_wait += cycle - temp.arrive;
		served++;
		if (wait_time > 0) {
			wait_time--;
		}
		sum_line += QueueItemCount(&line);
	}
	if (customers > 0) {
		printf("customers accepted:%ld\n", customers);
		printf("  customers served:%ld\n", served);
		printf("			turnaways:%ld\n", turnaways);
		printf("average queue size:%.2f\n", (double)sum_line / cyclelimit);
		printf("average wait time%.2f\n", (double)line_wait / served);
	}
	else {
		puts("No customers:");
		EmptyTheQueue(&line);
		puts("Bye!");
		return 0;
	}
}

// x是顾客到来的平均时间(单位:分钟)
//如果一分钟内有顾客到来,则返回true
bool newcustomer(double x) {
	if (rand() * x / RAND_MAX < 1) {
		return true;
	}
	else {
		return false;
	}
}


Item customertime(long when) {
	Item cust;
	cust.processtime = rand() % 3+1;
	cust.arrive = when;
	return cust;
}

