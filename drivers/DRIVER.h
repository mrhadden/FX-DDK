
#ifndef __FX_DRIVER_
#define __FX_DRIVER_

#include "fxos.h"
#include "fxmemorymanager.h"



#define NOIRQ					(0xFFFF)
#define MAKEIRQ(a,b)			(a << 8 | b)
#define IRQREG(a)				(a >> 8 & 0x00FF)
#define IRQNUM(a)				(a & 0x00FF)
#define IRQBUSIDX(a)			(sizeof(a)/sizeof(a[0]))
#define IRQNUMIDX(a)			(sizeof(a[0])/sizeof(a[0][0]))

#define FX_DRV_SIZE				(0x05F0)
#define FX_DRV_IRQ_SLOT_0		((IOPORT)(0x040000))
#define FX_DRV_IRQ_SLOT_1		((IOPORT)(0x0405F0))
#define FX_DRV_IRQ_SLOT_2		((IOPORT)(0x040BE0))
#define FX_DRV_IRQ_SLOT_3		((IOPORT)(0x0411D0))
#define FX_DRV_IRQ_SLOT_4		((IOPORT)(0x0417C0))
#define FX_DRV_IRQ_SLOT_5		((IOPORT)(0x041DB0))
#define FX_DRV_IRQ_SLOT_6		((IOPORT)(0x0423A0))
#define FX_DRV_IRQ_SLOT_7		((IOPORT)(0x042990))
#define FX_DRV_IRQ_SLOT_8		((IOPORT)(0x042F80))
#define FX_DRV_IRQ_SLOT_9		((IOPORT)(0x043570))
#define FX_DRV_IRQ_SLOT_10		((IOPORT)(0x043B60))
#define FX_DRV_IRQ_SLOT_11		((IOPORT)(0x044150))
#define FX_DRV_IRQ_SLOT_12		((IOPORT)(0x044740))
#define FX_DRV_IRQ_SLOT_13		((IOPORT)(0x044D30))
#define FX_DRV_IRQ_SLOT_14		((IOPORT)(0x045320))
#define FX_DRV_IRQ_SLOT_15		((IOPORT)(0x045910))
#define FX_DRV_IRQ_SLOT_16		((IOPORT)(0x045F00))
#define FX_DRV_IRQ_SLOT_17		((IOPORT)(0x0464F0))
#define FX_DRV_IRQ_SLOT_18		((IOPORT)(0x046AE0))
#define FX_DRV_IRQ_SLOT_19		((IOPORT)(0x0470D0))
#define FX_DRV_IRQ_SLOT_20		((IOPORT)(0x0476C0))
#define FX_DRV_IRQ_SLOT_21		((IOPORT)(0x047CB0))
#define FX_DRV_IRQ_SLOT_22		((IOPORT)(0x0482A0))
#define FX_DRV_IRQ_SLOT_23		((IOPORT)(0x0482FF))
#define FX_DRV_IRQ_SLOT_24		((IOPORT)(0x0488EF))
#define FX_DRV_IRQ_SLOT_25		((IOPORT)(0x048EDF))
#define FX_DRV_IRQ_SLOT_26		((IOPORT)(0x0494CF))
#define FX_DRV_IRQ_SLOT_27		((IOPORT)(0x049ABF))
#define FX_DRV_IRQ_SLOT_28		((IOPORT)(0x04A0AF))
#define FX_DRV_IRQ_SLOT_29		((IOPORT)(0x04A69F))
#define FX_DRV_IRQ_SLOT_30		((IOPORT)(0x04AC8F))
#define FX_DRV_IRQ_SLOT_31		((IOPORT)(0x04B27F))


#define FX_DRV_IRQ_COM1  		FX_DRV_IRQ_SLOT_0
#define FX_DRV_IRQ_PS2			FX_DRV_IRQ_SLOT_1
#define FX_DRV_IRQ_KEYBRD		FX_DRV_IRQ_SLOT_2
#define FX_DRV_IRQ_MOUSE		FX_DRV_IRQ_SLOT_3
#define FX_DRV_IRQ_IDE			FX_DRV_IRQ_SLOT_4
#define FX_DRV_IRQ_SDC			FX_DRV_IRQ_SLOT_5
#define FX_DRV_IRQ_FDC			FX_DRV_IRQ_SLOT_6
#define FX_DRV_IRQ_CON			FX_DRV_IRQ_SLOT_7
#define FX_DRV_IRQ_COM2			FX_DRV_IRQ_SLOT_8
#define FX_DRV_IRQ_TIM0			FX_DRV_IRQ_SLOT_17
#define FX_DRV_IRQ_TIM1			FX_DRV_IRQ_SLOT_18
#define FX_DRV_IRQ_TIM2			FX_DRV_IRQ_SLOT_19
#define FX_DRV_IRQ_SOL			FX_DRV_IRQ_SLOT_20
#define FX_DRV_IRQ_RTC			FX_DRV_IRQ_SLOT_21

/*
#define FX_DRV_IRQ_COM1  		FX_DRV_IRQ_SLOT_0
#define FX_DRV_IRQ_MOUSE		FX_DRV_IRQ_SLOT_1
#define FX_DRV_IRQ_KEYBRD		FX_DRV_IRQ_SLOT_2
#define FX_DRV_IRQ_COM2			FX_DRV_IRQ_SLOT_3
#define FX_DRV_IRQ_IDE			FX_DRV_IRQ_SLOT_4
#define FX_DRV_IRQ_SDC			FX_DRV_IRQ_SLOT_5
#define FX_DRV_IRQ_FDC			FX_DRV_IRQ_SLOT_6
#define FX_DRV_IRQ_CON			FX_DRV_IRQ_SLOT_7
#define FX_DRV_IRQ_TIM0			FX_DRV_IRQ_SLOT_17
#define FX_DRV_IRQ_TIM1			FX_DRV_IRQ_SLOT_18
#define FX_DRV_IRQ_TIM2			FX_DRV_IRQ_SLOT_19
#define FX_DRV_IRQ_SOL			FX_DRV_IRQ_SLOT_20
#define FX_DRV_IRQ_RTC			FX_DRV_IRQ_SLOT_21
*/

#define FX_DRV_GET(a,m,n)		((()a)->f_get_driver(m,n))
#define FX_DRV_HAS_IRQ(a)		((((PFX_DEVICE_DRIVER)a)->f_driver_irq)!=NULL)
#define FX_DRV_IRQ(a)			(((DEVICEDRIVER_IRQ)(a)->f_driver_irq)())
#define FX_DRV_HAS_READ(a)		((((PFX_DEVICE_DRIVER)a)->f_driver_read)!=NULL)
#define FX_DRV_READ(a,b,c)		(((PFX_DEVICE_DRIVER)a)->f_driver_read(b,c))
#define FX_DRV_HAS_WRITE(a)		((((PFX_DEVICE_DRIVER)a)->f_driver_write)!=NULL)
#define FX_DRV_WRITE(a,b,c)		(((PFX_DEVICE_DRIVER)a)->f_driver_write(b,c))


#ifdef USE_FX256_FMX
#pragma message "*** Compiling DDK for FMX!"
#include "fxc256fmx.h"
#elif USE_FX256_U
#pragma message "*** Compiling DDK for Model U!"
#include "fxc256u.h"
#else
#pragma message "*** Compiling DDK for B2!"
#include "fxc256.h"
#endif

#define LW_DEBUG_CHAR(a)	{while(!(UART1_BASE[5] & 0x20));UART1_BASE[0] = a;}


#endif
