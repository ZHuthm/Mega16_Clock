NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0020 =     32. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0074  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0074   0806 =   2054. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       003A  __text_start
       003A  __start
       005C  _exit
       005D  _port_init
       006B  _timer0_init
       0074  _init_devices
       007E  _run_time
       00CA  _Get_time
       00D7  _Add_time
       0112  _Sub_time
       014E  _quick_Sub_time
       01A0  _Set_time
       01AD  _time_to_dispbuff
       01E0  _setTime_to_dispbuff
       0213  _Disp_time_1_digit
       0242  _Disp_realTime
       0251  _Disp_setTime
       0287  _read_key_n
       0317  _timer0_ovf_isr
       0355  _main
       03EB  mod16u
       03ED  div16u
       03EE  xdiv16u
       0407  mod8u
       0409  div8u
       040A  xdiv8u
       041F  push_xgset300C
       0424  pop_xgset300C
       0429  push_xgsetF00C
       0430  pop_xgsetF00C
       0437  lsl8
       043D  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0020 =     32. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _SEG_A_List
       0060  __data_start
       0070  _microSec
       0072  _pos
       0073  _counter_5ms
       0074  _DP_flag
       0075  _set_flag
       0076  _keys_states
       0077  _set_states
       0078  _key_stime_counter
       0079  _key_stime_ok
       007A  read_key.h:key_state
       007C  read_key.h:key_time
       007D  main.c:key1_holdTime
       007E  main.c:no_action_time
       0080  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0080   000C =     12. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0080  _disp_buff
       0080  __bss_start
       0086  _time_setter
       0089  _time
       008C  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0028 =     40. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
<library>	[ div16u.s, div8u.s, gpushx.s, gpushz.s, lsl8.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

