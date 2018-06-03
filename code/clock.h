#define digit_port PORTA
#define SEG_port PORTC

#define normal_mode   0
#define set_mode 	  1

const unsigned char SEG_A_List[16] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,
0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71 };//"0-F" common cathode

unsigned char time[3];// 0 seconds 1 minutes 2 hours
unsigned char time_setter[3];
unsigned char disp_buff[6];

unsigned int microSec = 0; // Warning INT

unsigned char pos = 0;
unsigned char counter_5ms = 0;

unsigned char DP_flag = 0, //  0 is ON ,not 0 is OFF
set_flag = 0;//  0 is ON ,not 0 is OFF

unsigned char keys_states = 0, // 0 run time , 1 set time
set_states = 0;  // 0 set seconds,1 set mins, 2 set hours


void run_time(void)
{
	if (++microSec % 250 == 0) set_flag = ~set_flag;
	if (microSec >= 1000) {
		microSec = 0;
		DP_flag = ~DP_flag;
		if (++time[0] >= 60) {
			time[0] = 0;
			if (++time[1] >= 60) {
				time[1] = 0;
				if (++time[2] >= 24) {
					time[2] = 0;
				}
			}
		}
	}
}

void Get_time(void)
{
	time_setter[2] = time[2];
	time_setter[1] = time[1];
	time_setter[0] = time[0];
}

void Add_time(void)
{
 	switch(set_states)
	{
	 case 0:
	 case 1:
	 	  if(++time_setter[set_states]>=60)time_setter[set_states]=0;break;
	 case 2:
	 	  if(++time_setter[set_states]>=24)time_setter[set_states]=0;break;
	}
	
}

void Sub_time(void)
{
 	switch(set_states)
	{
	 case 0:
	 case 1:
	 	  if(--time_setter[set_states] == 255)time_setter[set_states]=59;break;
	 case 2:
	 	  if(--time_setter[set_states] == 255)time_setter[set_states]=23;break;
	}
}

void quick_Sub_time(void)
{
   switch(set_states)
	{
	 case 0:
	 case 1:
	 	  time_setter[set_states] -=10;
	 	  if(time_setter[set_states] >= 245)time_setter[set_states]-=196;break;
	 case 2:
	 	  time_setter[set_states] -=3;
	 	  if(time_setter[set_states] >= 252)time_setter[set_states]-=232;break;
	}
}

void Set_time(void)
{
	time[2] = time_setter[2];
	time[1] = time_setter[1];
	time[0] = time_setter[0];
}


void time_to_dispbuff(void)
{
	unsigned char i = 0, j = 0;
	for (i = 0; i <= 2; i++)
	{
		disp_buff[j++] = time[i] % 10;
		disp_buff[j++] = time[i] / 10;
	}
}

void setTime_to_dispbuff(void)
{
	unsigned char i = 0, j = 0;
	for (i = 0; i <= 2; i++)
	{
		disp_buff[j++] = time_setter[i] % 10;
		disp_buff[j++] = time_setter[i] / 10;
	}
}

void Disp_time_1_digit(unsigned char states)
{
	SEG_port |= 0x3f; // XX11 1111 HIGH OFF LOW ON 
	if (states == 0) return;
	digit_port = SEG_A_List[disp_buff[pos]];
	if (!DP_flag && (pos == 2 || pos == 4)) digit_port |= 0x80;
	SEG_port &= ~(1 << pos); // open the SEG which subscript is 'pos'
}


void Disp_realTime(void)
{
	time_to_dispbuff();
	Disp_time_1_digit(1);
	if (++pos >= 6) pos = 0;
}

void Disp_setTime(void)
{
	setTime_to_dispbuff();
	if ((set_states == 0 && (pos == 0 || pos == 1))
		|| (set_states == 1 && (pos == 2 || pos == 3))
		|| (set_states == 2 && (pos == 4 || pos == 5)))
		Disp_time_1_digit(set_flag);
	else
		Disp_time_1_digit(1);
	if (++pos >= 6) pos = 0;

}
