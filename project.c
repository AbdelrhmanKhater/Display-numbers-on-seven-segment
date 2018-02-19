#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
int masks[10] = {252, 24, 364, 316, 408, 436, 500, 28, 508, 444};
int cnt = 0;
int main()
{
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }
    int i;
    for (i = 2; i < 9; i++)
        bcm2835_gpio_fsel(i,1);
    bcm2835_gpio_fsel(12, 0);
    while (1)
    {
        if (bcm2835_gpio_lev(12) == 1)
            bcm2835_gpio_set_multi(masks[cnt]);
        else
        {
            bcm2835_gpio_clr_multi(masks[cnt]);
            cnt++;
            cnt %= 10;
            while(!bcm2835_gpio_lev(12));
        }
    }
    return 0;
}
