/*
 * (C) Copyright 2007-2013
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Jerry Wang <wangflord@allwinnertech.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef  __USB_PBURN_H__
#define  __USB_PBURN_H__

#include <common.h>

#define  SUNXI_USB_PBURN_DEV_MAX       (4)

unsigned char  sunxi_usb_pbur_normal_LangID[8]        = {0x04, 0x03, 0x09, 0x04, '\0'};

unsigned char  sunxi_usb_pburn_iSerialNum0[32] = "20101201120001";

unsigned char  sunxi_usb_pburn_iManufacturer[32] = "AllWinner Technology";

unsigned char  sunxi_usb_pburn_iProduct[32] = "USB Mass Storage";

#define  SUNXI_USB_STRING_LANGIDS			 (0)
#define  SUNXI_USB_STRING_IMANUFACTURER	 	 (1)
#define  SUNXI_USB_STRING_IPRODUCT		 	 (2)
#define  SUNXI_USB_STRING_ISERIALNUMBER    	 (3)

unsigned char  *sunxi_usb_pburn_dev[SUNXI_USB_PBURN_DEV_MAX] = {sunxi_usb_pbur_normal_LangID, 		\
																sunxi_usb_pburn_iSerialNum0, 		\
																sunxi_usb_pburn_iManufacturer, 		\
																sunxi_usb_pburn_iProduct};


const unsigned char  pburn_InquiryData[40]  = {0x00, 0x80, 0x02, 0x02, 0x1f, 										\
										 0x00, 0x00, 0x00, 													\
										 'U',  'S',  'B',  '2',  '.',  '0',  0x00, 0x00, 					\
	                                     'U' , 'S',  'B',  ' ', 'S',  't',  'o' , 'r' , 'a' , 'g' , 'e',	\
	                                     0x00, 0x00, 0x00, 0x00, 0x00,
	                                     '0',  '1',  '0',  '0',  '\0' };

const unsigned char pburn_RequestSense[20] = {0x07,0x00,0x02,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x3a,0x00,0x00,0x00,0x00,0x00};


#define  SUNXI_USB_PBURN_IDLE					 (0)
#define  SUNXI_USB_PBURN_SETUP					 (1)
#define  SUNXI_USB_PBURN_SEND_DATA				 (2)
#define  SUNXI_USB_PBURN_RECEIVE_DATA			 (3)
#define  SUNXI_USB_PBURN_STATUS					 (4)
#define  SUNXI_USB_PBURN_EXIT                    (5)
#define  SUNXI_USB_PBURN_RECEIVE_NULL			 (6)
#define  SUNXI_USB_PBURN_RECEIVE_PART_INFO		 (7)
#define  SUNXI_USB_PBURN_RECEIVE_PART_VERIFY	 (8)


typedef struct
{
	uchar *base_recv_buffer;		//??????????????????????????????????????????????????????
	uint   act_recv_buffer;//
	uint   recv_size;
	uint   to_be_recved_size;
	uchar *base_send_buffer;		//??????????????????????????????????????????????????????
	uint   act_send_buffer;//
	uint   send_size;		//???????????????????????????
	uint   flash_start;			//?????????????????????????????????????????????flash??????
	uint   flash_sectors;
}
pburn_trans_set_t;


typedef struct
{
	char  magic[16];       	//??????????????????????????? "usbhandshake"??????????????????
	int   sizelo;			//????????????32?????????????????????
	int   sizehi;			//????????????32?????????????????????
	int   res1;
	int   res2;
}
__usb_handshake_t;

typedef struct
{
	char magic[16];				//??????????????????????????? "usbburnpart"??????????????????
	char name[16];				//?????????????????????
	unsigned int lenhi;			//?????????????????????32???,????????????
	unsigned int lenlo;			//?????????????????????32???,????????????
	char reserved[1024-40]; 	//?????????1024 byte
}__attribute__ ((packed))pburn_partition_set_t;

typedef struct
{
	char magic[16];					//??????????????????????????? "usbburnpart"??????????????????
	char name[16];					//?????????????????????
	unsigned int check_sum;			//pc?????????????????????????????????
	char reserved[1024-36]; 		//?????????1024 byte
}__attribute__ ((packed))pburn_verify_part_set_t;


typedef struct
{
	char  magic[32];       	//??????????????????????????? "usbhandshake"??????????????????
}
__usb_handshake_sec_t;

typedef struct
{
	char  magic[64];   //???????????????
	int   err_no;
}
__usb_handshake_ext_t;

//?????????0???????????????
//?????????1???????????????(key)???????????????
//?????????2?????????key???????????????????????????????????????????????????
//?????????3?????????(key)????????????
//?????????4??????????????????
//?????????5?????????????????????????????????
//?????????6???????????????????????????
//		7: ????????????magic????????????
#define ERR_NO_SUCCESS					0
#define ERR_NO_KEY_VERIFY_ERR			1
#define ERR_NO_KEY_HASEXIST				2
#define ERR_NO_WRITE_ERR				3

#define ERR_NO_PART_NOEXIST				4
#define ERR_NO_PART_SIZE_ERR			5
#define ERR_NO_PART_VERIFY_ERR			6
#define ERR_NO_PART_MAGIC_ERR			7

#define ERR_NO_ERASE_KEY_FAILED			8
#define ERR_NO_KEY_NOEXIST				9

#define ERR_NO_READ_KEY_NOEXIST			10
#define ERR_NO_READ_KEY_FAILED			11

typedef struct
{
    //?????????????????????????????????key?????????
    char  name[64];      //key?????????
    u32 type;          //0:aes   1:rsa    ???????????????key
	u32 len;           //key?????????????????????
	u32 if_burn;       //?????????????????????0???????????????1?????????
	u32 if_replace;    //???????????????????????????key???0???????????????1?????????
	u32 if_crypt;     //?????????????????????????????????
    u8  *key_data[];   //???????????????????????????key?????????????????????????????????len??????
}
sunxi_usb_burn_key_info_t;

typedef struct
{
	u8  magic[16];	//??????????????????????????????"key-group-db"
	u8  hash[256]; //hash???(??????rootkey?????????????????????key??????????????????)
	u32 count;      //key?????????
	u32 res[3];     //??????

	sunxi_usb_burn_key_info_t  key_info;
}
sunxi_usb_burn_main_info_t;

#define   SUNXI_PBURN_RECV_MEM_SIZE   (512 * 1024)
#define   SUNXI_PBURN_SEND_MEM_SIZE   (512 * 1024)

#endif

