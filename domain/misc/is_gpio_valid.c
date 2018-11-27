#include <stdio.h> 
#include <linux/gpio.h> 

int main (void) {
    printf ("%d\n ", gpio_is_valid (111));
   return 0;  
}
