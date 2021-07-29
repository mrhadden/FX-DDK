
#include "fxtypes.h"
#include "DRIVER_S13.h"

//
// Local function assist in getting the data section where needs to be
// following the code section.
//
static PFX_DEVICE_DRIVER _f_get_driver(VOID);
static LPVOID			 _local_data(VOID);

//
// Section definition here puts the 'f_get_driver' function at the proper location
//
// Section drvcode:
//	00044d30 _BEG_DRVCODE
//	00044dfc _END_DRVCODE
//
// Section drvdata:
//	00044dfc _BEG_DRVDATA
//	00044e00 ~~DRIVER_DESC
//	00044dfc ~~data
//	00044e61 _END_DRVDATA
//
// ABSOLUTES:
//	00044d30 ~~f_get_driver
//

#pragma section CODE=DRVCODE,offset $04:4D30

static PFX_DEVICE_DRIVER f_get_driver(LPCSTR major,LPCSTR minor)
{
	return _f_get_driver();
}

static VOID f_driver_irq(void)
{
	LPVOID data = _local_data();
}

static BOOL f_driver_load(void)
{
	LW_DEBUG_CHAR('X');
	return TRUE;
}

static UINT f_driver_read(LPVOID buffer)
{
	return 0;
}

static UINT f_driver_write(UINT size,LPVOID buffer)
{
	return 0;
}

static BOOL f_driver_unload(void)
{
	return FALSE;
}
//
// Driver data section follows the DRVCODE
// This gives it a linear, compact footprint.
//
// Section: ORG:    ROM ORG:  SIZE:
// drvcode  044D30  044D30       E8H (   232)
// drvdata  044E18  044E18       65H (   101) <-- follow the code section without extensive calculation
// Total                        14DH (   333)
//
#pragma section DATA=DRVDATA
//
//
typedef struct driver_local_data
{
	int data_1;
	int data_2;
}LOCALDATA;

static LOCALDATA FAR data = {0,0};

static FX_DEVICE_DRIVER FAR DRIVER_DESC = {
											"EXT_13\0",
											"v1.0.0\0",
											"A\0",
											"1\0",
											DRIVER_TYPE_EXT_13,
											"E13:\0",
											NOIRQ,//MAKEIRQ(0,5),
											f_driver_irq,
											DDK_BASE_13,
											f_driver_load,
											f_driver_read,
											f_driver_write,
											f_driver_unload
										  };



static PFX_DEVICE_DRIVER _f_get_driver(VOID)
{
	return &DRIVER_DESC;
}

static LPVOID _local_data(VOID)
{
	return &data;
}
