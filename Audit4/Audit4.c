#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct realtok {
	double n;
	struct realtok* next;
};
typedef struct realtok spisok;
void addRandomValue(spisok* head) {
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = (spisok*)malloc(sizeof(spisok));
	head->next->next = NULL;
	head->next->n = (double)(rand()) / RAND_MAX * 100;
	return;
}
void outputList(spisok* head) {
	while (head != NULL) {
		printf("%lf\n", head->n);
		head = head->next;
	}
	return;
}
void find(spisok* head, double value) {
	while (head != NULL) {
		if (((value - (head->n)) <= 0.000001) && ((value - (head->n)) >= -0.000001)) {
			printf("First appearance-> ");
		}
		printf("%lf\n", head->n);
		head = head->next;
	}
	return;
}
void count(spisok* head, double value) {
	int num = 0;
	while (head != NULL) {
		if (((value - (head->n)) <= 0.000001) && ((value - (head->n)) >= -0.000001)) {
			num++;
		}
		head = head->next;
	}
	printf("Was found %d value.\n", num);
	return;
}
void addBeforeValue(spisok* head, double value) {
	while (1 == 1) {
		if (head == NULL) {
			printf("Not found\n");
			return;
		}
		if (((value - (head->n)) <= 0.000001) && ((value - (head->n)) >= -0.000001)) {
			break;
		}
		else {
			head = head->next;
		}
	}
	spisok* new;
	new = (spisok*)malloc(sizeof(spisok));
	new->next = head->next;
	head->next = new;
	new->n = (double)(rand()) / RAND_MAX * 100;
	return;
}
int main() {
	srand(time(0));
	spisok* head;
	head = (spisok*)malloc(sizeof(spisok));
	head->n = (double)(rand()) / RAND_MAX * 100;
	head->next = NULL;
	printf("Choose action\n");
	printf("1-add Random Value\n");
	printf("2-output List\n");
	printf("3-find value\n");
	printf("4-add Before Value\n");
	printf("5-count\n");
	printf("6-exit\n");
	int choose = 0;
	while (choose != 6) {
		scanf_s("%d", &choose);
		switch (choose) {
		case 1:
			addRandomValue(head);
			break;
		case 2:
			outputList(head);
			break;
		case 3: {
			printf("input number\n");
			double value;
			scanf_s("%lf", &value);
			find(head, value);
			break;
		}
		case 4: {
			printf("input number\n");
			double value;
			scanf_s("%lf", &value);
			addBeforeValue(head, value);
			break;
		}
		case 5: {
			printf("input number\n");
			double value;
			scanf_s("%lf", &value);
			count(head, value);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double Pi =    3.141592653589793238;
double sqrt2 = 1.414213;
int main() {
	double garden, rope;
	double result;
	scanf_s("%lf", &garden); 
	scanf_s("%lf", &rope); 
	if (rope <= (garden / 2)) {
		result = Pi * (rope * rope);
	}
	if (((garden / 2) * sqrt2) <= rope) {
		result = garden * garden;
	}
	if ((((garden / 2) * sqrt2) > rope)&&(rope > (garden / 2))) {
		float s;
		double a;
		garden /= 2;
		a = 2*garden*sqrt((rope-garden)*(rope+garden))/(rope*rope);
		s = rope * rope*(asin(a)-a);
		result = Pi * (rope * rope) - (2 * s);
		int f = result * 1000;
		f = f % 10;
		if (f >= 5) {
			result += 0.001;
		}
	}
	printf("%0.3lf",result);
	return 0;
}*/