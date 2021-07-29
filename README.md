# FXOS-SDK
The FX/OS DDK [Jul 28, 2021 10:43:36 PM] 

This is the offical DDK for FX/OS.  It is still under heavy development for stabilization and enhancement.

* You will need the latest binary for FX/OS. [Download](https://github.com/mrhadden/FXOSBinary)

## Driver Specifications

**Address Space** 	0x040000 - 0x04FFFF
**Max Driver Size** 0x5F0 (1520 bytes) 
**Max Drivers** 	32


## Exported Data Header

```
typedef struct _fx_device_driver
{
	CHAR    name[32];
	CHAR    version[16];
	CHAR    hmajor[8];
	CHAR    hminor[8];
	BYTE    type;
	CHAR	designation[6];
	UINT	irq_ctl;
	LPVOID	f_driver_irq;
	LPVOID  driver_context;
	LPVOID  f_driver_load;
	LPVOID  f_driver_read;
	LPVOID  f_driver_write;
	LPVOID  f_driver_unload;
}FX_DEVICE_DRIVER;

```

**name** - Human Name of the Device Driver
	
**version** - Driver version
	
**hmajor** - Supported major hardware version
	
**hminor** - Supported minor hardware version
	
**type** - Kind of device
	
**designation** - The DOS name of the driver
Example HD:, SDC:, CON: or PC:
	
**irq_ctl**	- IRQ Bus and Number for interrupts expected by the driver
	
**f_driver_irq** - Address of the IRQ handler function
	
**driver_context** - Driver Specific data and also driver load size when dynamically loaded 
	
**f_driver_load** - Address of the driver start function
	
**f_driver_read** - Address of the read function		 
	
**f_driver_write** - Address of the write function
	
**f_driver_unload** - Address of the end function


## Exported Functions for a Device Driver
### Kernel Functions

**f_get_driver** - Returns the FX_DEVICE_DRIVER structure for the hardware detected
One of more FX_DEVICE_DRIVER may be housed in a single driver, based on size and hardware
```
static PFX_DEVICE_DRIVER f_get_driver(LPCSTR major,LPCSTR minor)
```

**f_driver_irq**
```
static VOID f_driver_irq(void)
```	
	
**f_driver_load**
```
static BOOL f_driver_load(void)
```	
	
**f_driver_read**		
```
static UINT f_driver_read(LPVOID buffer)
```	
	
**f_driver_write**
```
static UINT f_driver_write(UINT size,LPVOID buffer)
```
	
**f_driver_unload**

```
static BOOL f_driver_unload(void)
```
## Output from boot time drivers
```

**********************************
******  Welcome to FX/OS   *******
******       Booting       *******
**********************************
Device Load Log Follows:
Scanning for Drivers...
Driver Detected  @0x040000:
  Name:DRIVER_FMXUCOM1D : LOADED
 USING IRQ: FF,FF
.
.
.
Driver Detected  @0x0417C0:
  Name:DRIVER_FMXIDE : LOADED
Driver Detected  @0x041DB0:
  Name:DRIVER_FMXSDCard : LOADED
 USING IRQ: 02,07
Driver Detected  @0x043B60:
  Name:DRIVER_SLOT_10 : UNIMPLEMENTED
Driver Detected  @0x044150:
  Name:DRIVER_SLOT_11 : UNIMPLEMENTED
Driver Detected  @0x044740:
  Name:DRIVER_SLOT_12 : UNIMPLEMENTED
.
.
.
Driver Detected  @0x046AE0:
  Name:DRIVER_TIM1 : LOADED
 USING IRQ: 00,03
Driver Detected  @0x0470D0:
  Name:DRIVER_TIM2 : LOADED
 USING IRQ: FF,FF
Driver Detected  @0x0476C0:
  Name:DRIVER_SOL : LOADED
 USING IRQ: 00,00
Driver Detected  @0x047CB0:
  Name:DRIVER_RTC : INCOMPATIBLE
```

## Example of a runtime dynamically loaded Device Driver
```
hDriver = DosLoadDriver("HD:\\system\\drivers\\DRIVER_S13.DRV");
```
