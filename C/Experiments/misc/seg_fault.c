/**
 * File              : seg_fault.c
 * Author            : Vepuri Vinay Kumar <vk.vepuri@globaledgesoft.com>
 * Date              : 03.08.2018
 * Last Modified Date: 03.08.2018
 * Last Modified By  : Vepuri Vinay Kumar <vk.vepuri@globaledgesoft.com>
 */
#include <stdio.h> 
int main (void)
{
    int *num = NULL;
    *num = 12;
    return 0; 
}
