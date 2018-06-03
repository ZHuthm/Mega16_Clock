#include "init_devices.h"
#include "clock.h"
#include "read_key.h"

#pragma interrupt_handler timer0_ovf_isr:iv_TIM0_OVF
void timer0_ovf_isr(void)
{
	TCNT0 = 0x83; //reload counter value

	run_time();

	if (++key_stime_counter >= 10)
	{
		key_stime_counter = 0;
		key_stime_ok = 1;
	}

}

void main(void)
{
	static unsigned char key1_holdTime = 0;
	static unsigned int no_action_time = 0;
	init_devices();
	//insert your functional code here...
	while (1)
	{

		switch (keys_states)
		{
		case normal_mode :Disp_realTime(); break;
		case set_mode :Disp_setTime(); break;
		default:break;
		}

		if (key_stime_ok)// 10ms watch key one time 
		{
			key_stime_ok = 0;

			switch (read_key_n(7))
			{
			case 0:
				 if(++no_action_time>=1000) no_action_time=keys_states = set_states = 0;
				 break;
			case 1:
				 no_action_time=0;
				 if(keys_states==1)
				 	Add_time();
				
				break;
			case 2:
				 no_action_time=0;
				 if (++key1_holdTime >= 2) {
					key1_holdTime = 0;
					if (keys_states == normal_mode )
					{
						keys_states = set_mode ;
						Get_time();
					}
					else if (++set_states >= 3)
					{
						keys_states = set_states = normal_mode ;
						Set_time();
					}
				 }
				 break;
			}
			if(keys_states== set_mode )
			{
			switch (read_key_n(6))
			{
			case 1:
				 no_action_time=0;
				 Sub_time();break;
			case 2:
				 no_action_time=0;
				 quick_Sub_time();break;
			}
			}
		}
	}
	return;
}