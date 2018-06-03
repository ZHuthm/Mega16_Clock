#define key_is_pressed() (0==(PINC&(1<<i)))
#define key_state_0	    0
#define key_state_1 	1
#define key_state_2 	2
#define key_state_3 	3

unsigned char key_stime_counter = 0;
unsigned char key_stime_ok = 0;

/************************************
// return 0 means no action
// return 1 means one time press key
// return 2 means long press key
************************************/
unsigned char read_key_n(unsigned char i)
{
	static unsigned char key_state[2] = {0}, key_time = 0;
	unsigned char key_return = 0;
	switch (key_state[i-6])
	{
	case key_state_0:
		if (key_is_pressed()) key_state[i-6] = key_state_1;
		break;

	case key_state_1:
		if (key_is_pressed())
		{
			key_state[i-6] = key_state_2;
			key_time = 0;
		}
		else key_state[i-6] = key_state_0;
		break;

	case key_state_2:
		if (!key_is_pressed())
		{
			key_state[i-6] = key_state_0;
			key_return = 1;
		}
		else if (++key_time >= 100)
		{
			key_state[i-6] = key_state_3;
			key_time = 0;
			key_return = 2;
		}
		break;

	case key_state_3:
		if (!key_is_pressed()) key_state[i-6] = key_state_0;
		else
		{
			if (++key_time >= 50)
			{
				key_time = 0;
				key_return = 2;
			}
		}
		break;
	}
	return key_return;
}
