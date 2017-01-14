This is a very simple C GPIO library for the [CHIP](https://getchip.com/pages/chip).

Example:

```
// This program will set GPIO pin 6 to OUT-LOW until a key is pressed

#include "gpio.h"
#include <stdio.h>

int main()
{
        if (gpio_export(CHIP_GPIO6) == GPIO_ERR) {
                printf("You have to run this program as root.\n");
                return 1;
        }
        
        gpio_setDirection(CHIP_GPIO6, GPIO_OUT);
        gpio_setValue(CHIP_GPIO6, GPIO_LOW);
        
        printf("Press Enter to quit.\n");
        
        getchar();
        
        gpio_setValue(CHIP_GPIO6, GPIO_HIGH);
        gpio_unexport(CHIP_GPIO6);

        return 0;
}
```
