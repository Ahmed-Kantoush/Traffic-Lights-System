/*********************************************/
/* Author : Mario Ramzy                      */
/* Date : 24/2/2018		                     */
/* version : V01		                     */

#include "std_types.h"
#include "bitmath.h"
#include "GIE_reg.h"
#include "GIE_int.h"
#include "GIE_priv.h"
#include "GIE_config.h"

/* Enable globale interrupt  */
void GIE_voidEnable(void)
{
	setbit(SREG, GIE_u8_BIT_INDIX);
}

void GIE_voidDisable(void)
{
	clrbit(SREG, GIE_u8_BIT_INDIX);
}




