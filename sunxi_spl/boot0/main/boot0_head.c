/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2008, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name : Boot0_head.c
*
* Author : Gary.Wang
*
* Version : 1.1.0
*
* Date : 2007.11.06
*
* Description : This file defines the file head part of Boot0, which contains some important
*             infomations such as magic, platform infomation and so on, and MUST be allocted in the
*             head of Boot0.
*
* Others : None at present.
*
*
* History :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang       2007.11.06      1.1.0        build the file
*
************************************************************************************************************************
*/
#include "common.h"
#include <private_boot0.h>

extern char boot0_hash_value[64];
const boot0_file_head_t  BT0_head = {
	                                  {
	      /* jump_instruction */          ( 0xEA000000 | ( ( ( sizeof( boot0_file_head_t ) + sizeof(boot0_hash_value)+ sizeof( int ) - 1 ) / sizeof( int ) - 2 ) & 0x00FFFFFF ) ),
							   		      BOOT0_MAGIC,
							   		      STAMP_VALUE,
#ifdef ALIGN_SIZE_8K
									      0x2000,
#else
                                          0x4000,
#endif
							   		      sizeof( boot_file_head_t ),
							   		      {
							   		      	0, 0, 1, 0
							   		      },
							   		      CONFIG_BOOT0_RET_ADDR,
							   		      CONFIG_BOOT0_RUN_ADDR,
							   		      0,
							   		      {
							   		      	0, 0, '4','.','2','.','0',0
							   		      },
							 	      },
									  
									    {
0, //prvt_head.prvt_head_size
1, //prvt_head.debug_mode
        {552,3,15355,1,284295680,0,7280,64,24,0,4661583,29501771,397379,0,0,0,0,0,0,0,0,0,168,67585,0,0,0,0,0,0,0,0},//prvt_head.dram_para
0, //prvt_head.uart_port
        {
                {
                6,//port
                2,//port_num
                3,//mul_sel
                1,//pull
                1,//drv_level
                -1,//data
                { 0, 0}//prvt_head.uart_ctrl[i].reserved[2]
                },
                {
                6,//port
                4,//port_num
                3,//mul_sel
                1,//pull
                1,//drv_level
                -1,//data
                { 0, 0}//prvt_head.uart_ctrl[i].reserved[2]
                }
        },//prvt_head.uart_ctrl[2]
1, //prvt_head.enable_jtag
        {
                {
                6,//port
                0,//port_num
                3,//mul_sel
                1,//pull
                1,//drv_level
                -1,//data
                { 0, 0}//prvt_head.jtag_gpio[i].reserved[2]
                },
                {
                6,//port
                5,//port_num
                3,//mul_sel
                1,//pull
                1,//drv_level
                -1,//data
                { 0, 0}//prvt_head.jtag_gpio[i].reserved[2]
                },
                {
                6,//port
                3,//port_num
                3,//mul_sel
                1,//pull
                1,//drv_level
                -1,//data
                { 0, 0}//prvt_head.jtag_gpio[i].reserved[2]
                },
                {
                6,//port
                1,//port_num
                3,//mul_sel
                1,//pull
                1,//drv_level
                -1,//data
                { 0, 0}//prvt_head.jtag_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.jtag_gpio[i].reserved[2]
                }
        },//prvt_head.jtag_gpio
        {
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                },
                {
                0,//port
                0,//port_num
                0,//mul_sel
                0,//pull
                0,//drv_level
                0,//data
                { 0, 0}//prvt_head.storage_gpio[i].reserved[2]
                }
        },//prvt_head.storage_gpio


//this is prvt_head.storage_data

        {
1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,4,0,0,0,64,0,0,0,0,16,0,0,-116,0,0,0,30,0,0,0,0,0,0,0,-20,-36,16,-107,86,-1,-1,-1,-128,3,0,0,-128,3,0,0,0,0,0,0,0,0,0,0,8,0,0,0,40,0,0,0,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        }

					

}

};



/*******************************************************************************
*
*                  关于Boot_file_head中的jump_instruction字段
*
*  jump_instruction字段存放的是一条跳转指令：( B  BACK_OF_Boot_file_head )，此跳
*转指令被执行后，程序将跳转到Boot_file_head后面第一条指令。
*
*  ARM指令中的B指令编码如下：
*          +--------+---------+------------------------------+
*          | 31--28 | 27--24  |            23--0             |
*          +--------+---------+------------------------------+
*          |  cond  | 1 0 1 0 |        signed_immed_24       |
*          +--------+---------+------------------------------+
*  《ARM Architecture Reference Manual》对于此指令有如下解释：
*  Syntax :
*  B{<cond>}  <target_address>
*    <cond>    Is the condition under which the instruction is executed. If the
*              <cond> is ommitted, the AL(always,its code is 0b1110 )is used.
*    <target_address>
*              Specified the address to branch to. The branch target address is
*              calculated by:
*              1.  Sign-extending the 24-bit signed(wro's complement)immediate
*                  to 32 bits.
*              2.  Shifting the result left two bits.
*              3.  Adding to the contents of the PC, which contains the address
*                  of the branch instruction plus 8.
*
*  由此可知，此指令编码的最高8位为：0b11101010，低24位根据Boot_file_head的大小动
*态生成，所以指令的组装过程如下：
*  ( sizeof( boot_file_head_t ) + sizeof( int ) - 1 ) / sizeof( int )
*                                              求出文件头占用的“字”的个数
*  - 2                                         减去PC预取的指令条数
*  & 0x00FFFFFF                                求出signed-immed-24
*  | 0xEA000000                                组装成B指令
*
*******************************************************************************/

