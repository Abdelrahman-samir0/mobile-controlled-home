/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : GI DRIVER                        */
/*   DATE        : 23 SEP 2022                      */
/*   VERSION     : V01                              */
/****************************************************/

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../Include/MCAL/GI/GI_configuration.h"


void MGI_voidEnable (void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
void MGI_voidDisable (void)
{
	CLR_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
