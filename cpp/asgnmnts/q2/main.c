#include <stdio.h>

typedef struct patient {
	char name[30];
	float temperature;
	int heart_rate;
	char status[40];
} patient;

patient input_func() {
	struct patient p;
	printf("[input]: enter patient's temperature: ");
	scanf("%f", &(p.temperature));

	printf("[input]: enter patient's heart rate: ");
	scanf("%d", &(p.heart_rate));

	return p;
}

void display(struct patient p) {

	if (p.temperature >= 36 || p.temperature <= 37.5) {
		printf("[condition status]: NORMAL\n");
	} else if (p.temperature > 37.5) {
		printf("[condition status]: FEVER\n");
	} else {
		printf("[condition status]: LOW TEMP\n");
	}

	if (p.heart_rate == 60 || p.heart_rate <= 100) {
		printf("[condition status]: NORMAL\n");
	} else if (p.temperature > 100) {
		printf("[condition status]: HIGH HEART RATE\n");
	} else {
		printf("[condition status]: LOW HEART RATE\n");
	}

}

int main(void) {
	while (1) {
		struct patient p = input_func();
		display(p);
	}
}
