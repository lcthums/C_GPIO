#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define GPIO_ERR -1
#define GPIO_OK 1
#define GPIO_BASE_PATH "/sys/class/gpio/gpio"
#define GPIO_EXPORT_FILE "/sys/class/gpio/export"
#define GPIO_UNEXPORT_FILE "/sys/class/gpio/unexport"
#define GPIO_OUT 0
#define GPIO_IN 1
#define GPIO_HIGH 1
#define GPIO_LOW 0
#define CHIP_GPIO0 1013
#define CHIP_GPIO1 1014
#define CHIP_GPIO2 1015
#define CHIP_GPIO3 1016
#define CHIP_GPIO4 1017
#define CHIP_GPIO5 1018
#define CHIP_GPIO6 1019
#define CHIP_GPIO7 1020

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

bool gpio_setDirection(int pin, int dir)
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

#endif
