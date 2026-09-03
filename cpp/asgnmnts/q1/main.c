#include <stdio.h>

int SERVICE_CHARGE = 50;

typedef struct consumer {
	char name[30];
	int number;
	double units;
} consumer;

consumer input_func() {

	struct consumer c;
	printf("[input]: enter the consumer name : ");
	fgets(c.name, sizeof(c.name), stdin);


	printf("[input]: enter the consumer mobile number: ");
	scanf("%d", &(c.number));

	printf("[input]: enter the consumer units: ");
	scanf("%lf", &(c.units));

	return c;
}

double charge(struct consumer c) {
	double chrge;
	double tmp = c.units;


	// if (c.units <= 100) {
	// 	chrge = 2 * c.units;
	// } else if (c.units > 100 && c.units <= 200) {
	// 	chrge = 3.50 * c.units;
	// } else if (c.units > 200 && c.units <= 500) { 
	// 	chrge = 5 * c.units;
	// } else {
	// 	chrge = 7.5 * c.units;
	// }
	return chrge;
}

void display(struct consumer c, double charge) {
	printf("BILL\n");
	printf("\n");
	printf("CONSUMER NAME: %s\n", c.name);
	printf("CONSUMER MOBILE: %d\n", c.number);
	printf("CONSUMED UNITS: %.2lf\n", c.units);
	printf("\n");
	printf("CHARGE: %.2lf\n", charge);
	printf("SERVICE FEE: %d\n", SERVICE_CHARGE);
	printf("\n");
	printf("TOTAL CHARGE: %.2lf\n", charge + SERVICE_CHARGE);
	printf("\n");
}


int main (void) {
	struct consumer c = input_func();
	double chrge = charge(c);

	display(c, chrge);
}
