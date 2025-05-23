
#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_


#define TX_HSIZE 1280*3
#define TX_VSIZE 720

#define CAMERA_TYPE SINGLE_1

#define VIDEO_COLUMNS 1280
#define VIDEO_ROWS 720
#define DEMO_MAX_FRAME (720*1280)

#ifdef SDT
#define XPAR_AXIVDMA_0_DEVICE_ID XPAR_AXI_VDMA_0_BASEADDR
#define XPAR_AXIVDMA_1_DEVICE_ID XPAR_AXI_VDMA_1_BASEADDR
#define XPAR_AXIVDMA_2_DEVICE_ID XPAR_AXI_VDMA_2_BASEADDR
#define XPAR_FABRIC_AXI_VDMA_0_MM2S_INTROUT_INTR XPAR_AXI_VDMA_0_INTERRUPTS
#define XPAR_FABRIC_AXI_VDMA_1_S2MM_INTROUT_INTR XPAR_AXI_VDMA_1_INTERRUPTS
#define XPAR_FABRIC_AXI_VDMA_2_S2MM_INTROUT_INTR XPAR_AXI_VDMA_2_INTERRUPTS
#define XPAR_SCUGIC_0_DEVICE_ID XPAR_XSCUGIC_0_BASEADDR
#define XPAR_XIICPS_0_DEVICE_ID XPAR_XIICPS_0_BASEADDR
#define XPAR_XIICPS_1_DEVICE_ID XPAR_XIICPS_1_BASEADDR
#define XPAR_XGPIOPS_0_DEVICE_ID XPAR_XGPIOPS_0_BASEADDR
#define XPAR_V_TC_0_DEVICE_ID XPAR_XVTC_0_BASEADDR
#define XPAR_RST_GPIO_DEVICE_ID XPAR_RST_GPIO_BASEADDR
#endif

#endif /* SRC_CONFIG_H_ */
