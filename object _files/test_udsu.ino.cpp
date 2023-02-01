#include <Arduino.h>
#line 1 "C:\\Users\\Michael\\Documents\\Arduino\\test_udsu\\test_udsu.ino"
/*
 * lgt8f328p dsu test
 *
 */ 

//#include "udsu.h"

int array_dx[] = {
	8, 1000, -20, 44, 80, -100, 107, 20,
	9, 10, -1, -1, 40, 20, 10, 7,
	0, 5, 7, 13, 20, -31, 6, -1,
	9, 120, -22, 34, 80, -110, 117, 11	
};

int array_dy[] = {
	1, 2, 1, 3, 4, 2, 1, 2,
	3, 2, -1, -1, 4, 2, 1, 3,
	3, 1, 0, 4, 2, 11, -17, 1,
	1, 2, 1, 3, 4, 2, 1, 2	
};


volatile unsigned int  uint16 = 0;
volatile signed int     int16 = 0;
volatile unsigned long uint32 = 0;
volatile signed long    int32 = 0;
volatile long int      timer_uDSC0,timer_uDSC1 = 0;
volatile long int      timer_norm0,timer_norm1 = 0;

///////////////////////////////////////////////
#include <avr/io.h>

#define DSU_MM_FAST          0x00
#define DSU_MM_NORMAL    0x40

extern void dsu_init(unsigned char dsu_mm);

extern unsigned int dsu_xadd(unsigned int dx, unsigned int dy);
extern int signed   dsu_xads(int dx, int dy);
extern unsigned int dsu_xsub(unsigned int dx, unsigned int dy);
extern int dsu_xsbs(int dx, int dy);
extern unsigned long dsu_aday(unsigned long da, unsigned int dy);
extern long dsu_adays(long da, int dy);
extern unsigned long dsu_sbay(unsigned long da, unsigned int dy);
extern long dsu_sbays(long da, int dy);
extern unsigned long dsu_xmuluu(unsigned int dx, unsigned int dy);
extern long dsu_xmulsu(int dx, unsigned int dy);
extern long dsu_xmulus(unsigned int dx, int dy);
extern unsigned long dsu_xmulss(int dx, int dy);

extern unsigned long dsu_xmacuu0(unsigned int dx, unsigned int dy);
extern unsigned long dsu_xmacuu1(unsigned long da, unsigned int dx, unsigned int dy);
extern unsigned long dsu_xmacus0(unsigned int dx, int dy);
extern unsigned long dsu_xmacus1(unsigned long da, unsigned int dx, int dy);
extern unsigned long dsu_xmacsu0(int dx, unsigned int dy);
extern unsigned long dsu_xmacsu1(unsigned long da, int dx, unsigned int dy);
extern unsigned long dsu_xmacss0(int dx, int dy);
extern unsigned long dsu_xmacss1(unsigned long da, int dx, int dy);
extern long dsu_smacuu0(unsigned int dx, unsigned int dy);
extern long dsu_smacuu1(long da, unsigned int dx, unsigned int dy);
extern long dsu_smacus0(unsigned int dx, int dy);
extern long dsu_smacus1(long da, unsigned int dx, int dy);
extern long dsu_smacsu0(int dx, unsigned int dy);
extern long dsu_smacsu1(long da, int dx, unsigned int dy);
extern long dsu_smacss0(int dx, int dy);
extern long dsu_smacss1(long da, int dx, int dy);

extern unsigned long dsu_xmscuu0(unsigned int dx, unsigned int dy);
extern unsigned long dsu_xmscuu1(unsigned long da, unsigned int dx, unsigned int dy);
extern unsigned long dsu_xmscus0(unsigned int dx, int dy);
extern unsigned long dsu_xmscus1(unsigned long da, unsigned int dx, int dy);
extern unsigned long dsu_xmscsu0(int dx, unsigned int dy);
extern unsigned long dsu_xmscsu1(unsigned long da, int dx, unsigned int dy);
extern unsigned long dsu_xmscss0(int dx, int dy);
extern unsigned long dsu_xmscss1(unsigned long da, int dx, int dy);
extern long dsu_smscuu0(unsigned int dx, unsigned int dy);
extern long dsu_smscuu1(long da, unsigned int dx, unsigned int dy);
extern long dsu_smscus0(unsigned int dx, int dy);
extern long dsu_smscus1(long da, unsigned int dx, int dy);
extern long dsu_smscsu0(int dx, unsigned int dy);
extern long dsu_smscsu1(long da, int dx, unsigned int dy);
extern long dsu_smscss0(int dx, int dy);
extern long dsu_smscss1(long da, int dx, int dy);

extern void dsu_usqx0(unsigned int dx);
extern void dsu_ssqx0(int dx);
extern void dsu_usqy0(unsigned int dy);
extern void dsu_ssqy0(int dy);
extern unsigned long dsu_usqx1(unsigned int dx);
extern unsigned long dsu_ssqx1(int dx);
extern unsigned long dsu_usqy1(unsigned int dy);
extern unsigned long dsu_ssqy1(int dy);
extern void dsu_uneg0(void);
extern void dsu_uneg1(unsigned long da);
extern long dsu_uneg2(void);
extern long dsu_uneg3(unsigned long da);
extern void dsu_sneg0(void);
extern void dsu_sneg1(long da);
extern long dsu_sneg2(void);
extern long dsu_sneg3(long da);
extern void dsu_abs0(void);
extern void dsu_abs1(long da);
extern unsigned long dsu_abs2(void);
extern unsigned long dsu_abs3(long da);
extern void dsu_clr(void);
extern unsigned long dsu_div0(void);
extern unsigned long dsu_div1(unsigned long da, unsigned int dy);

extern unsigned long dsu_ashl0(unsigned char shn);
extern unsigned long dsu_ashl1(unsigned long da, unsigned char shn);
extern unsigned long dsu_ashr0(unsigned char shn);
extern unsigned long dsu_ashr1(unsigned long da, unsigned char shn);
extern long dsu_ashr2(unsigned char shn);
extern long dsu_ashr3(long da, unsigned char shn);

extern unsigned long dsu_da(void);
extern unsigned int dsu_dx(void);
extern unsigned int dsu_dy(void);

extern long dsu_fmacss(unsigned int dx, unsigned int dy, unsigned char cnt);

void setup(void);
void loop(void);


/////////////////////////////////////////////
#line 127 "C:\\Users\\Michael\\Documents\\Arduino\\test_udsu\\test_udsu.ino"
void setup();
#line 132 "C:\\Users\\Michael\\Documents\\Arduino\\test_udsu\\test_udsu.ino"
void loop();
#line 127 "C:\\Users\\Michael\\Documents\\Arduino\\test_udsu\\test_udsu.ino"
void setup() {
    Serial.begin(115200);
    while (!Serial) { }
}
	
	void loop() {
	
	Serial.println("uDSC Test");
	Serial.println("---------");
	Serial.println();
		
	
// ============= Normal Math ==================

	timer_norm0 = millis();

	uint16 = 1000 + 3111;
	if(uint16 != 4111) goto error;
	
	int16 = -1000 + -3111;
	if(int16 != -4111) goto error;
	
	uint32 = 0x70000000 + 0x1000;
	if(uint32 != 0x70001000) goto error;
	
	uint32 = 20 * 300;	
	if(uint32 != 6000) 	goto error;

	int32 = -20 * 300;
	if(int32 != -6000) goto error;
	
	int32 = -20 * 100;
	if(int32 != -2000) goto error;
	
	int32 = -20 * -200;
	if(int32 != 4000) goto error;
	
	uint32 = 40 * 300;
	if(uint32 != 12000) goto error;
		
	uint32 = 1000 + (40 * 300);
	if(uint32 != 13000) goto error;		
		
	uint32 = uint32 + (20 * 500);
	if(uint32 != 23000) goto error;
	
	uint32 = sq(200);
	if(uint32 != 40000) goto error;
	
	uint32 = sq(300);
	if(uint32 != 90000) goto error;
	
	uint32 = 0; // dsu_clr()
	uint32 = uint32;  // dsu_da()
	if(uint32 != 0) goto error;
	
	uint32 = 0x00 + 0x400;
	if(uint32 != 0x400) goto error;
	
	int32 = uint32 * -1;
	if(int32 != -0x400) goto error;
	
	uint32 = abs(uint32);
	if(uint32 != 0x400) goto error;
	
	int xadd = 0 + 0;  // dsu_xadd(0, 0) best guess
	uint32 = xadd;     // dsu_da() 
	if(uint32 != 0) goto error;
	
	uint32 = 33333/11111; //dsu_div1 da=da/dy, dy=da%dy
	uint16_t dy = 33333%11111;
	if(uint32 != 3) goto error;
	
	uint16 = dy; //dsu_dy();
	if(uint16 != 0) goto error;
	
	uint32 = 5666/1111;
	dy = 5666%1111;
	if(uint32 != 5) goto error;
	
	uint16 = dy;
	if(uint16 != 111) goto error;
	
	// clean up dsu status
	uint32 = 0; // dsu_clr()	

	// add 0x2000 offset to map to 16bit SRAM
	//int32 = dsu_fmacss(((uint16_t)array_dx | 0x2000), ((uint16_t)array_dy | 0x2000), 32);
         // the 0x2000 adress offset not used

	uint16_t dx = 0;
	dy = 0;
	int *Z = array_dx; // dx_addr load to Z
	int *Y = array_dy; // dy_addr load to Y
	unsigned char r20=32;     //loop count is in r20
	fmacss2_loop:
		// ldd r0, Z+2	
			dx = *Z; // DX = *(dx_addr)
			Z += 2;    // dx_addr += 2 (for 16bit address)
		// ldd r1, Y+2
			dy = *Y; // DY = *(dy_addr), then 
			Y += 2;    // dy_addr += 2 (for 16bit address)
		// out DSIR, r20  da += dx * dy
		int32 += (dx * dy);
		--r20;
		if (r20 > 0) goto fmacss2_loop; //	breq fmacss2_done; rjmp fmacss2_loop;
		                                 // condensed into one IF
//	if (int32 != ) goto error;

	
	// test done
	timer_norm1 = millis();
	Serial.print ("Time for uDSC test:");
	Serial.println (timer_norm0 - timer_norm1);	


// ============= uDSC =========================	

	timer_uDSC0 = millis();

	// initial uDSU module to fast io addressing mode
	dsu_init(DSU_MM_FAST); // 0x00
	
	uint16 = dsu_xadd(1000, 3111);
	if(uint16 != 4111) goto error;
	
	int16 = dsu_xads(-1000, -3111);
	if(int16 != -4111) goto error;
	
	uint32 = dsu_aday(0x70000000, 0x1000);
	if(uint32 != 0x70001000) goto error;
	
	uint32 = dsu_xmuluu(20, 300);	
	if(uint32 != 6000) 	goto error;

	int32 = dsu_xmulsu(-20, 300);
	if(int32 != -6000) goto error;
	
	int32 = dsu_xmulss(-20, 100);
	if(int32 != -2000) goto error;
	
	int32 = dsu_xmulss(-20, -200);
	if(int32 != 4000) goto error;
	
	uint32 = dsu_xmacuu1(0, 40, 300);
	if(uint32 != 12000) goto error;
		
	uint32 = dsu_xmacuu1(1000, 40, 300);
	if(uint32 != 13000) goto error;		
		
	uint32 = dsu_xmacuu0(20, 500);
	if(uint32 != 23000) goto error;
	
	uint32 = dsu_usqx1(200);
	if(uint32 != 40000) goto error;
	
	uint32 = dsu_usqy1(300);
	if(uint32 != 90000) goto error;
	
	dsu_clr();
	uint32 = dsu_da();
	if(uint32 != 0) goto error;
	
	uint32 = dsu_xadd(0, 0x400);
	if(uint32 != 0x400) goto error;
	
	int32 = dsu_uneg2();
	if(int32 != -0x400) goto error;
	
	uint32 = dsu_abs2();
	if(uint32 != 0x400) goto error;
	
	dsu_xadd(0, 0);
	uint32 = dsu_da();
	if(uint32 != 0) goto error;
	
	uint32 = dsu_div1(33333, 11111);
	if(uint32 != 3) goto error;
	
	uint16 = dsu_dy();
	if(uint16 != 0) goto error;
	
	uint32 = dsu_div1(5666, 1111);
	if(uint32 != 5) goto error;
	
	uint16 = dsu_dy();
	if(uint16 != 111) goto error;
	
	// clean up dsu status
	dsu_clr();	

	// add 0x2000 offset to map to 16bit SRAM
	int32 = dsu_fmacss(((uint16_t)array_dx | 0x2000), ((uint16_t)array_dy | 0x2000), 32);
//	if (int32 != ) goto error;
	
	// test done
	timer_uDSC1 = millis();
	Serial.print ("Time for uDSC test:");
	Serial.println (timer_uDSC0 - timer_uDSC1);

// test done
	while(1);

		
error:	// if test failed!
	while(1)
	{
		Serial.print("ERROR");
	}	
	

}

