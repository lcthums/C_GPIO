#ifndef GPIO_H
#define GPIO_H

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

int gpio_export(int pin);
int gpio_unexport(int pin);
int gpio_setValue(int pin, int value);
int gpio_setDirection(int pin, int dir);
int gpio_getValue(int pin);
int gpio_getDirection(int pin);

#endif