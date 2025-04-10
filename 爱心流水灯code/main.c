#include <REGX52.H>


typedef unsigned char uchar;
typedef unsigned int uint;


void Delay_ms(unsigned int xms);

void clock_wise(uint x);
void anticlock_wise(uint x);
void all_dance(void);
void two_flanks(uint x);
void breath_effect(void);
void cross_flash(void);
void random_flash(void);
void heartbeat(void);
void wave_effect(void);
void marquee(void);
void gradient_blink(void);
void spiral(void);

void main()
{
    while(1)
    {   
		uint i;
        Delay_ms(1000);
        for (i = 250; i > 0; i -= 50)
        {
            clock_wise(i);
        }
 
				for (i = 250; i > 0; i -= 50)
        {
            anticlock_wise(i);
        }
				Delay_ms(60);
				clock_wise(20);
				Delay_ms(60);
				anticlock_wise(20);
        Delay_ms(60);
        two_flanks(10);
        Delay_ms(60);
        all_dance();
        Delay_ms(60);
        breath_effect();    // 新增呼吸效果
				Delay_ms(60);
        cross_flash();      // 新增交叉闪烁
				Delay_ms(60);
        random_flash();     // 新增随机闪烁
				Delay_ms(60);
        heartbeat();        // 新增心跳效果
				wave_effect();      // 新增波浪效果
        Delay_ms(60);
        marquee();          // 新增跑马灯
        Delay_ms(60);
        gradient_blink();   // 新增渐变闪烁
        Delay_ms(60);
        spiral();           // 新增螺旋闪烁
    }
}

//12m晶振频率，毫秒级延时
void Delay_ms(uint xms)
{
	uchar i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}
//全体led闪烁
void all_dance(void){
		P0=0x00;P1=0x00;P2=0x00;P3=0x00;
		Delay_ms(600);
		P0=0xff;P1=0xff;P2=0xff;P3=0xff;
		Delay_ms(600);
}
//顺时针流水灯
void clock_wise(uint x){
    P1=0x7F;Delay_ms(x);P1=0xBF;Delay_ms(x);P1=0xDF;Delay_ms(x);P1=0xEF;Delay_ms(x);
    P1=0xF7;Delay_ms(x);P1=0xFB;Delay_ms(x);P1=0xFD;Delay_ms(x);P1=0xFE;Delay_ms(x);
    P1=0xFF;Delay_ms(x);
    
    P0=0xFE;Delay_ms(x);P0=0xFD;Delay_ms(x);P0=0xFB;Delay_ms(x);P0=0xF7;Delay_ms(x);
    P0=0xEF;Delay_ms(x);P0=0xDF;Delay_ms(x);P0=0xBF;Delay_ms(x);P0=0x7F;Delay_ms(x);
    P0=0xFF;Delay_ms(x);
    
    P2=0x7F;Delay_ms(x);P2=0xBF;Delay_ms(x);P2=0xDF;Delay_ms(x);P2=0xEF;Delay_ms(x);
    P2=0xF7;Delay_ms(x);P2=0xFB;Delay_ms(x);P2=0xFD;Delay_ms(x);P2=0xFE;Delay_ms(x);
    P2=0xFF;Delay_ms(x);
    
    P3=0x7f;Delay_ms(x);P3=0xBF;Delay_ms(x);P3=0xDF;Delay_ms(x);P3=0xEF;Delay_ms(x);
    P3=0xF7;Delay_ms(x);P3=0xFB;Delay_ms(x);P3=0xFD;Delay_ms(x);P3=0xFE;Delay_ms(x);
    P3=0xFF;Delay_ms(x);
}
//逆时针流水灯
void anticlock_wise(uint x){
    P3=0xFE;Delay_ms(x);P3=0xFD;Delay_ms(x);P3=0xFB;Delay_ms(x);P3=0xF7;Delay_ms(x);
    P3=0xEF;Delay_ms(x);P3=0xDF;Delay_ms(x);P3=0xBF;Delay_ms(x);P3=0x7F;Delay_ms(x);
    P3=0xFF;Delay_ms(x);
    
    P2=0xFE;Delay_ms(x);P2=0xFD;Delay_ms(x);P2=0xFB;Delay_ms(x);P2=0xF7;Delay_ms(x);
    P2=0xEF;Delay_ms(x);P2=0xDF;Delay_ms(x);P2=0xBF;Delay_ms(x);P2=0x7F;Delay_ms(x);
    P2=0xFF;Delay_ms(x);
    
    P0=0x7F;Delay_ms(x);P0=0xBF;Delay_ms(x);P0=0xDF;Delay_ms(x);P0=0xEF;Delay_ms(x);
    P0=0xF7;Delay_ms(x);P0=0xFB;Delay_ms(x);P0=0xFD;Delay_ms(x);P0=0xFE;Delay_ms(x);
    P0=0xFF;Delay_ms(x);
    
    P1=0xFE;Delay_ms(x);P1=0xFD;Delay_ms(x);P1=0xFB;Delay_ms(x);P1=0xF7;Delay_ms(x);
    P1=0xEF;Delay_ms(x);P1=0xDF;Delay_ms(x);P1=0xBF;Delay_ms(x);P1=0x7F;Delay_ms(x);
    P1=0xFF;Delay_ms(x);
}
//两侧同时流水
void two_flanks(uint x){
		P1=0x7F;P3=0xFE;Delay_ms(x);P1=0xBF;P3=0xFD;Delay_ms(x);P1=0xDF;P3=0xFB;Delay_ms(x);P1=0xEF;P3=0xF7;Delay_ms(x);
		P1=0xF7;P3=0xEF;Delay_ms(x);P1=0xFB;P3=0xDF;Delay_ms(x);P1=0xFD;P3=0xBF;Delay_ms(x);P1=0xFE;P3=0x7F;Delay_ms(x);
		P1=0xFF;P3=0xFF;Delay_ms(x);

		P0=0xFD;P2=0xFD;Delay_ms(x);P0=0xFE;P2=0xFE;Delay_ms(x);P0=0xFB;P2=0xFB;Delay_ms(x);P0=0xF7;P2=0xF7;Delay_ms(x);
		P0=0xEF;P2=0xEF;Delay_ms(x);P0=0xDF;P2=0xDF;Delay_ms(x);P0=0xBF;P2=0xBF;Delay_ms(x);P0=0x7F;P2=0x7F;Delay_ms(x);
		P0=0xFF;P2=0xFF;Delay_ms(x);
}

// 新增效果1：呼吸灯效果（所有LED渐变亮度）
void breath_effect(void) {
	uchar i;
    for(i=0; i<5; i++) {
        P0=0xFF<<i; P1=0xFF<<i; P2=0xFF<<i; P3=0xFF<<i;
        Delay_ms(80);
    }
    for(i=5; i>0; i--) {
        P0=0xFF<<i; P1=0xFF<<i; P2=0xFF<<i; P3=0xFF<<i;
        Delay_ms(80);
    }
}

// 新增效果2：随机闪烁（随机位置LED闪烁）
void random_flash(void) {
	uchar i;
    for(i=0; i<8; i++) {
        P0 = ~(0x01 << (i%8)); 
        P1 = ~(0x01 << ((i+2)%8));
        P2 = ~(0x01 << ((i+4)%8));
        P3 = ~(0x01 << ((i+6)%8));
        Delay_ms(80);
    }
}

// 新增效果3：交叉闪烁（左右交替）
void cross_flash(void) {
	uchar i;
    for(i=0; i<3; i++) {
        P0=0xAA; P1=0xAA; P2=0x55; P3=0x55;  // 左半亮右半灭
        Delay_ms(200);
        P0=0x55; P1=0x55; P2=0xAA; P3=0xAA;  // 右半亮左半灭
        Delay_ms(200);
    }
    P0=0xFF; P1=0xFF; P2=0xFF; P3=0xFF;
}

// 新增效果4：心跳效果（快速闪烁三次）
void heartbeat(void) {
	uchar i;
    for(i=0; i<3; i++) {
        P0=0x00; P1=0x00; P2=0x00; P3=0x00;
        Delay_ms(100);
        P0=0xFF; P1=0xFF; P2=0xFF; P3=0xFF;
        Delay_ms(100);
    }
}

// 新增效果5：波浪效果（从中心向四周扩散）
void wave_effect(void) {
    uchar i;
    for(i=0; i<4; i++){
        P0 = ~(0x18 >> i);  // 00011000 右移
        P1 = ~(0x18 >> i);
        P2 = ~(0x18 << i);  // 00011000 左移
        P3 = ~(0x18 << i);
        Delay_ms(120);
    }
    P0=0xFF;P1=0xFF;P2=0xFF;P3=0xFF;
}

// 新增效果6：跑马灯效果（四端口循环追逐）
void marquee(void) {
    uchar i;
    for(i=0; i<8; i++){
        P0 = ~(0x80 >> i); 
        P1 = ~(0x80 >> (i+2)%8);
        P2 = ~(0x80 >> (i+4)%8);
        P3 = ~(0x80 >> (i+6)%8);
        Delay_ms(150);
    }
}

// 新增效果7：渐变闪烁（不同频率闪烁）
void gradient_blink(void) {
    uchar i;
    for(i=0; i<6; i++){
        P0=0x00;P1=0xFF;P2=0x00;P3=0xFF;
        Delay_ms(100 + i*20);
        P0=0xFF;P1=0x00;P2=0xFF;P3=0x00;
        Delay_ms(100 + i*20);
    }
}

// 新增效果8：螺旋效果（内外交替旋转）
void spiral(void) {
    uchar patterns[] = {0x7E,0xBD,0xDB,0xE7};
	uchar i;
    for(i=0; i<4; i++){
        P0 = patterns[i];
        P1 = patterns[(i+1)%4];
        P2 = patterns[(i+2)%4];
        P3 = patterns[(i+3)%4];
        Delay_ms(200);
    }
    P0=0xFF;P1=0xFF;P2=0xFF;P3=0xFF;
}
