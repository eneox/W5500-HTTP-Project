#include "main.h"
#include "wizchip_conf.h"

void  wizchip_select(void);
void  wizchip_deselect(void);
uint8_t wizchip_read(void);
void  wizchip_write(uint8_t wb);
void wizchip_readburst(uint8_t* pBuf, uint16_t len);
void  wizchip_writeburst(uint8_t* pBuf, uint16_t len);
void delay_cnt(volatile unsigned int nCount);
void Display_Net_Conf(void);
void Net_Conf(wiz_NetInfo netinfo);
void Net_Conf(wiz_NetInfo netinfo);
void W5500_Init(void);
