
/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */

#include <stdio.h>
#include "math.h"
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "xparameters.h"
#include "xiicps.h"
#include "i2c/PS_i2c.h"
#include "demosaic/demosaic.h"
#include "cam_config.h"
#include "config.h"
#include "sleep.h"

#include "xil_cache.h"

#include "xgpiops.h"
#include "xscugic.h"
#include "vtc.h"
#include "xaxivdma.h"
#include "xaxivdma_i.h"

//#include "ff.h"
/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */

#define LED_MIO	25
#define CAM1_EMIO	26
#define CAM2_EMIO	27

XAxiVdma vdma;
XAxiVdma_DmaSetup vdmaDMA;
XAxiVdma_Config *vdmaConfig;

XVtc Vtc_inst;

//static int WriteError;

int wr_index=0;
int rd_index=0;


XIicPs ps_i2c0;
XIicPs ps_i2c1;
XGpioPs GPIO_PTR ;


int PsGpioSetup() ;

/*
 * Framebuffers for video data
 */

u8 frameBuf0[1][DEMO_MAX_FRAME] __attribute__ ((aligned(4096)));
u8 *pFrames0; 


void InitVideoFmt(XIicPs *IicInstance,int w, int h)
{

	i2c_reg16_write(IicInstance, 0x36, 0x3808, (w>>8)&0xff);
	i2c_reg16_write(IicInstance, 0x36, 0x3809, (w>>0)&0xff);
	i2c_reg16_write(IicInstance, 0x36, 0x380a, (h>>8)&0xff);
	i2c_reg16_write(IicInstance, 0x36, 0x380b, (h>>0)&0xff);

}

void InitDisplay()
{
    Vtc_init(&Vtc_inst,VMODE_1280x720);
    
}

int main(void)
{

	int i;
    int Status;

	PsGpioSetup() ;

    for (i = 0; i < 1; i++) 
	{
		pFrames0 = frameBuf0[i];
	}
	
	demosaic_init(XPAR_V_DEMOSAIC_0_BASEADDR,VIDEO_COLUMNS,VIDEO_ROWS);

	i2c_init(&ps_i2c0,100000);

    XGpioPs_WritePin(&GPIO_PTR, CAM1_EMIO, 1) ;
	usleep(500000);
	XGpioPs_WritePin(&GPIO_PTR, CAM1_EMIO, 0) ;
	usleep(500000);
	XGpioPs_WritePin(&GPIO_PTR, CAM1_EMIO, 1) ;
	usleep(500000);

	sensor_init(&ps_i2c0);
    InitVideoFmt(&ps_i2c0,VIDEO_COLUMNS,VIDEO_ROWS);



	InitDisplay();

	xil_printf("config done!\r\n");

    vdmaConfig = XAxiVdma_LookupConfig(XPAR_AXI_VDMA_0_BASEADDR);
	XAxiVdma_CfgInitialize(&vdma, vdmaConfig, vdmaConfig->BaseAddress);
	//video = VMODE_1280x720;
	vdmaDMA.FrameDelay = 0;
	vdmaDMA.EnableCircularBuf = 1;
	vdmaDMA.EnableSync = 0;
	vdmaDMA.PointNum = 0;
	vdmaDMA.EnableFrameCounter = 0;

	vdmaDMA.VertSizeInput = 720;
	vdmaDMA.HoriSizeInput = (1280)*3;
	vdmaDMA.FixedFrameStoreAddr = 0;
	vdmaDMA.FrameStoreStartAddr[0] = (u32)  pFrames0[0];
	vdmaDMA.Stride = (1280)*3;

	XAxiVdma_DmaConfig(&vdma, XAXIVDMA_WRITE, &(vdmaDMA));
    XAxiVdma_DmaSetBufferAddr(&vdma, XAXIVDMA_WRITE,vdmaDMA.FrameStoreStartAddr);

	XAxiVdma_DmaConfig(&vdma, XAXIVDMA_READ, &(vdmaDMA));
	XAxiVdma_DmaSetBufferAddr(&vdma, XAXIVDMA_READ,vdmaDMA.FrameStoreStartAddr);


	XAxiVdma_DmaStart(&vdma, XAXIVDMA_WRITE);
	//Status = XAxiVdma_StartParking(&vdma, 0, XAXIVDMA_WRITE);
	XAxiVdma_DmaStart(&vdma, XAXIVDMA_READ);
	//XAxiVdma_StartParking(&vdma, 0, XAXIVDMA_READ);

	while(1){
		XGpioPs_WritePin(&GPIO_PTR, LED_MIO, 0) ;
		usleep(500000);
		XGpioPs_WritePin(&GPIO_PTR, LED_MIO, 1) ;
		usleep(500000);
	}


	return 0;
}


int PsGpioSetup()
{
	XGpioPs_Config *GPIO_CONFIG ;
	int Status ;


	GPIO_CONFIG = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_DEVICE_ID) ;

	Status = XGpioPs_CfgInitialize(&GPIO_PTR, GPIO_CONFIG, GPIO_CONFIG->BaseAddr) ;
	if (Status != XST_SUCCESS)
	{
		return XST_FAILURE ;
	}

	XGpioPs_SetDirectionPin(&GPIO_PTR, LED_MIO, 1) ;
	XGpioPs_SetOutputEnablePin(&GPIO_PTR, LED_MIO, 1) ;

	return XST_SUCCESS ;
}




