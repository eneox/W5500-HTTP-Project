#include "APP_Web.h"

//#define DATA_BUF_SIZE   2048
//#define DATA_BUF_SIZE   1024
#define _MAIN_DEBUG_

///////////////////////////
// Demo Firmware Version //
///////////////////////////
#define VER_H		1
#define VER_L		00

uint8_t socknumlist[] = {2, 3, 4, 5, 6, 7};

////////////////////////////////////////////////
// Shared Buffer Definition  				  //
////////////////////////////////////////////////
uint8_t RX_BUF[DATA_BUF_SIZE];
uint8_t TX_BUF[DATA_BUF_SIZE];

///////////////////////////
// Network Configuration //
///////////////////////////
wiz_NetInfo gWIZNETINFO = { .mac 	= {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},	// Mac address
                            .ip 	= {192, 168, 0, 12},					// IP address
                            .sn 	= {255, 255, 255, 0},					// Subnet mask
                            .gw 	= {192, 168, 0, 1},						// Gateway address
                            .dns 	= {8, 8, 8, 8},							// DNS server
                            .dhcp 	= NETINFO_STATIC };						// DHCP enable / disable


void Init_WebAPP (void){
	//INIT SPI AND CS PERIPHERAL
	W5500_Init();
	Net_Conf(gWIZNETINFO);
#ifdef _MAIN_DEBUG_
	uint8_t tmpstr[6] = {0,};

	ctlwizchip(CW_GET_ID,(void*)tmpstr);

    printf("\r\n=======================================\r\n");
	printf(" WIZnet %s EVB Demos v%d.%.2d\r\n", tmpstr, VER_H, VER_L);
	printf("=======================================\r\n");
	printf(">> W5500 based Web Server Example\r\n");
	printf("=======================================\r\n");

	Display_Net_Conf(); // Print out the network information to serial terminal
#endif


	/* HTTP Server Initialization  */
	httpServer_init(TX_BUF, RX_BUF, MAX_HTTPSOCK, socknumlist);		// Tx/Rx buffers (1kB) / The number of W5500 chip H/W sockets in use
	reg_httpServer_cbfunc(NVIC_SystemReset, NULL); 					// Callback: NXP MCU Reset

	{
			/* Web content registration (web content in webpage.h, Example web pages) */

			// Index page and netinfo / base64 image demo
			reg_httpServer_webContent((uint8_t *)"index.html", (uint8_t *)index_page);				// index.html 		: Main page example
			reg_httpServer_webContent((uint8_t *)"netinfo.html", (uint8_t *)netinfo_page);			// netinfo.html 	: Network information example page
			reg_httpServer_webContent((uint8_t *)"netinfo.js", (uint8_t *)wiz550web_netinfo_js);	// netinfo.js 		: JavaScript for Read Network configuration 	(+ ajax.js)
			reg_httpServer_webContent((uint8_t *)"img.html", (uint8_t *)img_page);					// img.html 		: Base64 Image data example page

			// Example #1
			reg_httpServer_webContent((uint8_t *)"dio.html", (uint8_t *)dio_page);					// dio.html 		: Digital I/O control example page
			reg_httpServer_webContent((uint8_t *)"dio.js", (uint8_t *)wiz550web_dio_js);			// dio.js 			: JavaScript for digital I/O control 	(+ ajax.js)

			// Example #2
			reg_httpServer_webContent((uint8_t *)"ain.html", (uint8_t *)ain_page);					// ain.html 		: Analog input monitor example page
			reg_httpServer_webContent((uint8_t *)"ain.js", (uint8_t *)wiz550web_ain_js);			// ain.js 			: JavaScript for Analog input monitor	(+ ajax.js)

			// Example #3
			reg_httpServer_webContent((uint8_t *)"ain_gauge.html", (uint8_t *)ain_gauge_page);		// ain_gauge.html 	: Analog input monitor example page; using Google Gauge chart
			reg_httpServer_webContent((uint8_t *)"ain_gauge.js", (uint8_t *)ain_gauge_js);			// ain_gauge.js 	: JavaScript for Google Gauge chart		(+ ajax.js)

			// AJAX JavaScript functions
			reg_httpServer_webContent((uint8_t *)"ajax.js", (uint8_t *)wiz550web_ajax_js);			// ajax.js			: JavaScript for AJAX request transfer

	#ifdef _MAIN_DEBUG_
			display_reg_webContent_list();
	#endif
		}
}

void Task_WebAPP (void){
	// TODO: insert user's code here
	for(uint16_t i = 0; i < MAX_HTTPSOCK; i++)
		httpServer_run(i); 	// HTTP Server handler

	loopback_tcps(SOCK_TCPS, RX_BUF, 5000);
}
