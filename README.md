# FXOS-SDK
The FX/OS DDK [Jul 28, 2021 10:43:36 PM] 

This is the offical DDK for FX/OS.  It is still under heavy development for stabilization and enhancement.

* You will need the latest binary for FX/OS. [Download](https://github.com/mrhadden/FXOSBinary)


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
	
**f_driver_load** - Address of the driver load function
	
**f_driver_read** - Address of the read function		 
	
**f_driver_write** - Address of the write function
	
**f_driver_unload** - Address of the unload function


## Exported Functions for a Device Driver
### Kernel Functions

**f_get_driver** - Device Driver Entry Point
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


## Example of a runtime dynamically loaded Device Driver
```
hDriver = DosLoadDriver("HD:\\system\\drivers\\DRIVER_S13.DRV");
```
