#include "gpio.h"
#include <stdio.h>
#include <string.h>

int gpio_export(int pin)
{
	FILE *f = fopen(GPIO_EXPORT_FILE, "w");

	if (f == NULL)
		return GPIO_ERR;

	int ret = fprintf(f, "%d", pin);

	fclose(f);

        return ret < 0 ? GPIO_ERR : GPIO_OK;
}

int gpio_unexport(int pin)
{
        FILE *f = fopen(GPIO_UNEXPORT_FILE, "w");

        if (f == NULL)
                return GPIO_ERR;

	int ret = fprintf(f, "%d", pin);

        fclose(f);

	return ret < 0 ? GPIO_ERR : GPIO_OK;
}

int gpio_setValue(int pin, int value)
{
	char buf[100];
	snprintf(buf, 100, "%s%d/value", GPIO_BASE_PATH, pin);

	FILE *f = fopen(buf, "w");

	if (f == NULL)
		return GPIO_ERR;

	int ret = fprintf(f, "%d", value);

	fclose(f);

	return ret < 0 ? GPIO_ERR : GPIO_OK;
}

int gpio_setDirection(int pin, int dir)
{
        char buf[100];

        snprintf(buf, 100, "%s%d/direction", GPIO_BASE_PATH, pin);

        FILE *f = fopen(buf, "w");

        if (f == NULL)
                return GPIO_ERR;

	if (dir == GPIO_OUT)
		snprintf(buf, 100, "out");
	else if (dir == GPIO_IN)
		snprintf(buf, 100, "in");
	else
		return GPIO_ERR;

	int ret = fprintf(f, "%s", buf);

	fclose(f);

	return ret < 0 ? GPIO_ERR : GPIO_OK;
}

int gpio_getValue(int pin)
{
        char buf[100];
	snprintf(buf, 100, "%s%d/value", GPIO_BASE_PATH, pin);

        FILE *f = fopen(buf, "r");

        if (f == NULL)
                return GPIO_ERR;

	int r, ret = fscanf(f, "%d", &r);

        fclose(f);

	return ret < 0 ? GPIO_ERR : r;
}


int gpio_getDirection(int pin)
{
        char buf[100];
        snprintf(buf, 100, "%s%d/direction", GPIO_BASE_PATH, pin);

        FILE *f = fopen(buf, "r");

        if (f == NULL)
                return GPIO_ERR;

	fscanf(f, "%s", buf);

        fclose(f);

	if (strcmp(buf, "out") == 0)
		return GPIO_OUT;
	else if (strcmp(buf, "in") == 0)
		return GPIO_IN;
	else
	        return GPIO_ERR;
}