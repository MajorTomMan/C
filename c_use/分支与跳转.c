#include<stdio.h>
#define Size 12
#define Stop 0

int if_switch_classwork1(void) {
	int space_c, next_c, puna_c;
	space_c = next_c = puna_c = 0;
	char ch;
	printf("请输入一段话(输入#停止):");
	while ((ch = getchar()) != 35) {
		if (ch== 10) {
			next_c++;
		}
		else if (ch == 32) {
			space_c++;
		}
		else {
			puna_c++;
		}
	}
	printf("输入的话中空格的数量是%d,换行符的数量是%d , 其他字符的数量是%d\n", space_c, next_c, puna_c);
}

int if_switch_classwork2(void) {
	int i=0;

	char ch=0;
	printf("请输入一段话(输入#停止):");
	while ((ch == getchar()) != 0) {
		break;
	}
	while ((ch = getchar()) != 35) {
		for (int i = 0; i != 9;i++) {
			if (ch == '\n') {
				continue;
			}
			printf("输出结果:%c-%d ", ch, (int)ch);
			ch = getchar();
		}
		printf("\n");
	}
}


int if_switch_classwork3(void) {
	int  even_number, odd_number,get_number,even_average,odd_average ;
	int i, j;
	int input_n[Size] = { 0 },even_n[Size] = { 0 },odd_n[Size] = { 0 };
	i = j = 0;
	even_number = odd_number = get_number = 0;
	even_average=odd_average = 0;
	printf("请输入12个整数(按0停止):");
	while ((scanf("%d", &get_number))) {
		if (get_number % 2 == 0 && get_number != 0) {
			even_n[i] = get_number;
			even_number++;
			i++;
		}
		else if(get_number % 2 != 0 && get_number != 0){
			odd_n[j] = get_number;
			odd_number++;
			j++;
		}
		else {
			break;
		}
	}
	i = j = 0;
	for (; ; i++) {
		if (even_n[i] != 0)
			even_average += even_n[i];
		else
			break;
	}
	for (;; j++) {
		if (odd_n[j] != 0)
			odd_average += odd_n[j];
		else
			break;
	}
	if (i != 0 && j != 0) {
		printf("偶数个数是%d 偶数的平均数是%d 奇数个数是%d,奇数的平均数是%d\n", even_number, even_average / i, odd_number, odd_average / j);
	}
	else {
		printf("程序结束");
	}
}

int if_switch_classwork4() {
	int replace_n=0,i=0;
	char ch;
	char ch_1[Size] = {""};
	printf("请输入一段话(按#停止):");
	while ((ch = getchar()) != 35) {
		if (ch == '.') {
			ch = '!';
			replace_n++;
			printf("%c", ch);
		}
		else if (ch == '!') {
			ch_1[i] = '!';
			i++;
			ch_1[i] = '!';
			i++;
			replace_n++;
			i = 0;
			printf(" %s", &ch_1);
		}
		else {
			printf("%c", ch);
		}
	}
	printf("替换了%d次\n",replace_n);
}

int if_switch_classwork5(void) {
	int replace_n = 0, i = 0;
	char ch;
	char ch_1[Size] = { "" };
	printf("请输入一段话(按#停止):");
	while ((ch = getchar()) != 35) {
		switch (ch) {
		case '.':ch = '!', replace_n++, printf("%c", ch); break;
		case '!':ch_1[i] = '!',i++, ch_1[i] = '!',i++, replace_n++, printf(" %s", &ch_1),i=0;break;
		default:printf("%c", ch);
		}
	}
	printf("替换了%d次\n", replace_n);
}


int if_switch_classwork6(void) {
	int found_n=0;
	char ch = ' ',ch_next=' ';
	printf("请输入一段话(按#停止):");
	while ((ch = getchar()) != '#') {
		if (ch == 'e' && (ch_next = getchar()) == 'i'|| ch == 'E' && (ch_next = getchar()) == 'I') {
			found_n++;
		}
		else {
			;
		}
	}
	printf("单词e和i在句子中出现的次数是%d次\n", found_n);
}

int if_switch_classwork7(void) {
	float base_salary=10.00, work_overtime=1.5, tax_rate=0.0,tax_money=0.0,income=0.0;
	int  hour = 0;
	float week_salary=0.0;
	printf("请输入每周的工作时间数:");
	while ((scanf("%d", &hour) != 0)) {
		if(hour<=40)
			week_salary = base_salary *hour;
		else {
			week_salary = (base_salary + (base_salary * work_overtime)) * hour;
		}
		if (week_salary <= 300) {
			tax_rate = 0.15;
		}
		else if (week_salary > 300 && week_salary <= 450) {
			tax_rate = 0.2;
		}
		else {
			tax_rate = 0.25;
		}
		tax_money = week_salary * tax_rate;
		income = week_salary - tax_money;
		break;
	}
	printf("每周的总收入    税金          净收入\n%-15f %-13f %f\n",week_salary,tax_money,income);
}

int calculate_salary(float base_salary, int hour) {
	float work_overtime = 1.5, tax_rate = 0.0, tax_money = 0.0, income = 0.0;
	float week_salary = 0.0;
	if (hour != 0) {
		if (hour <= 40)
			week_salary = base_salary * hour;
		else {
			week_salary = (base_salary + (base_salary * work_overtime)) * hour;
		}
		if (week_salary <= 300) {
			tax_rate = 0.15;
		}
		else if (week_salary > 300 && week_salary <= 450) {
			tax_rate = 0.2;
		}
		else {
			tax_rate = 0.25;
		}
		tax_money = week_salary * tax_rate;
		income = week_salary - tax_money;
		printf("每周的总收入    税金          净收入\n%-15f %-13f %f\n", week_salary, tax_money, income);
		if_switch_classwork8();
	}
	else {
		printf("请输入正确的工作时间数\n");
		if_switch_classwork8();
	}
}

int menu(void) {
	char ch = ' ';
	printf("*************************************\n");
	printf("工资菜单如下:\n");
	printf("1) $8.75/hr %-15c 2) $9.33/hr\n"
		"3) $10.00/hr %-14c 4) $11.20/hr\n"
		"5) quit\n", ch, ch);
	printf("*************************************\n");
	printf("请输入要选择的基本工资:");
}

int if_switch_classwork8(void) {
	float base_salary = 10.00;
	int  hour = 0,input=0;
	float week_salary = 0.0;
	menu();
	while ((scanf("%d", &input) != 5)) {
		switch (input) {
		case 1:base_salary = 8.75,
			printf("请输入工作的小时数:"),
			scanf("%d", &hour); break;
		case 2:base_salary = 9.33, 
			printf("请输入工作的小时数:"),
			scanf("%d", &hour); break;
		case 3:base_salary = 10.00, 
			printf("请输入工作的小时数:"),
			scanf("%d", &hour); break;
		case 4:base_salary = 11.20,
			printf("请输入工作的小时数:"),
			scanf("%d", &hour); break;
		case 5:goto quit;
		default:printf("请输入正确的数字\n"),menu(); continue;
		}
		if (input < 5) {
			calculate_salary(base_salary,hour);
		}
	quit:break;
	}
	printf("程序结束\n");
}


/*
int if_switch_classwork9(void) {
	int input = 0;
	printf("请输入一个正整数");
	scanf("%d", &input);
}
*/

int ten_menu(void) {
	char ch = ' ';
	printf("*************************************\n");
	printf("税收类别菜单如下:\n");
	printf("1) 单身 %-15c 2) 户主\n"
		"3) 已婚,共有 %-10c 4) 已婚,离异\n"
		"5) Quit\n", ch, ch);
	printf("*************************************\n");
	printf("请输入属于类别前的数字:");
}
int if_switch_classwork10(void) {
	float total_salary = 0.0, over_money = 0.0,tax_money=0.0,over_tax_money=0.0;
	int taxation;
	float over_tax_rate = 0.0,tax_rate=0.0;
	char ch = ' ';
	ten_menu();
	while ((scanf("%d", &taxation)) != 0) {
		switch (taxation) {
		case 1:
			printf("请输入工资总额:");
			scanf("%f", &total_salary);
			if (total_salary <= 17850)
				tax_rate = 0.15;
			else {
				tax_rate = 0.15;
				over_money = total_salary - 17850;
				over_tax_rate = 0.28;
			}; break;
		case 2:
			printf("请输入工资总额:");
			scanf("%f", &total_salary);
			if (total_salary <= 23900)
				over_tax_rate = 0.15;
			else {
				tax_rate = 0.15;
				over_money = total_salary - 23900;
				over_tax_rate = 0.28;
			}; break;
		case 3:
			printf("请输入工资总额:");
			scanf("%f", &total_salary);
			if (total_salary <= 29750)
				tax_rate = 0.15;
			else {
				tax_rate = 0.15;
				over_money = total_salary - 29750;
				over_tax_rate = 0.28;
			}; break;
		case 4:
			printf("请输入工资总额:");
			scanf("%f", &total_salary);
			if (total_salary <= 14875)
				tax_rate = 0.15;
			else {
				tax_rate = 0.15;
				over_money = total_salary - 14875;
				over_tax_rate = 0.28;
			}; break;
		case 5:goto Quit; break;
		default:printf("请输入正确的数字!\n"),ten_menu(); continue;
		}
		if (over_money != 0) {
			over_tax_money = over_money * over_tax_rate;
			tax_money = (total_salary - over_money) * tax_rate;
			tax_money += over_tax_money;
		}
		else {
			tax_money = total_salary * tax_rate;
		}
		printf("  工资总额 %-15c 税金\n%f %-10c %f\n",ch,total_salary,ch,tax_money);
		if_switch_classwork10();
	Quit: break;
	}
	printf("程序结束 \n");
}

int if_switch_classwork11(void) {
	char ch = ' ',comfirm=' ';
	float onion_price=2.05, beet_price=1.15,carrot_price=1.09;
	float cartage = 0.0, total_pound=0.0 , input_p = 0.0, onion_p = 0.0, beet_p = 0.0, carrot_p = 0.0;
	float cost = 0.0,onion_c=0.0,beet_c=0.0,carrot_c=0.0;
	float discount_rate = 0.05,discount_cost=0.0;
	int input_n=0;
	int flag = 0;
	while (1){
		twelve_menu();
		scanf("%d", &input_n);
		switch (input_n) {
		case 1: printf("请输入要购买的洋葱磅数:");
			scanf("%f", &input_p);
			onion_p += input_p;
			break;
		case 2: printf("请输入要购买的甜菜磅数:");
			scanf("%f", &input_p);
			beet_p += input_p;
			break;
		case 3: printf("请输入要购买的胡萝卜磅数:");
			scanf("%f", &input_p);
			carrot_p += input_p;
			break;
		case 4:goto Quit;
		default:printf("请输入正确的数字\n"); continue;
		}
		comfirm = getchar();
		printf("请问是否要继续购买?(Y/N)");
		comfirm = getchar();
		if (comfirm == 'Y' || comfirm == 'y') {
			continue;
		}
	Quit:printf("已退出\n");
		onion_c = onion_p * onion_price;
		beet_c = beet_p * beet_price;
		carrot_c= carrot_p * carrot_price;
		cost = onion_c + beet_c + carrot_c;
		if (cost-100>=0) {
			flag = 1;
			discount_cost = discount_rate * cost;
			cost -= discount_cost;
		}
		total_pound = onion_p + beet_p + carrot_p;
		if (total_pound <= 5&& total_pound!=0) {
			cartage = 6.5;
			cost += cartage;
			break;
		}
		else if (total_pound>5 &&total_pound<=20 && total_pound != 0){
			cartage = 14;
			cost += cartage;
			break;
		}
		else if(total_pound>20 && total_pound != 0){
			cartage = 14 + (((long float)total_pound - 20) * 0.5);
			cost += cartage;
			break;
		}
		else {
			break;
		}
	}
	printf("     商品售价清单\n商品名 \t 价格\n");
	printf("洋葱 \t $%1.2lf \n", onion_price);
	printf("甜菜 \t $%1.2lf  \n", beet_price);
	printf("胡萝卜 \t $%1.2lf \n", carrot_price);
	printf("-----------------------------------------------------\n");
	printf("     购买清单\n商品名 \t 磅数 \t 花费\n");
	printf("洋葱 \t %1.2lf \t $%1.2lf \n", onion_p,onion_c);
	printf("甜菜 \t %1.2lf \t $%1.2lf \n",  beet_p, beet_c);
	printf("胡萝卜 \t %1.2lf \t $%1.2lf \n",  carrot_p, carrot_c);
	printf("-----------------------------------------------------\n");
	if (flag != 0) {
		printf("折扣:%1.2lf\n", discount_cost);
	}
	printf("总费用 \t 总磅数  总运费\n");
	printf("$%1.2lf \t %1.2lf \t $%1.2lf\n", cost, total_pound, cartage);
	printf("-------------------------祝您购物愉快----------------\n");
}
int twelve_menu(void) {
	char ch = ' ';
	printf("*************************************\n");
	printf("商品种类如下:\n");
	printf("1) 洋葱 %-15c 2) 甜菜\n"
		"3) 胡萝卜 %-13c 4) Quit \n", ch, ch);
	printf("*************************************\n");
	printf("请输入要购买的商品:");
}