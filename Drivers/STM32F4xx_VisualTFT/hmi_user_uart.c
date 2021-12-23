/************************************��Ȩ����********************************************
**                             ���ݴ�ʹ��Ƽ����޹�˾
**                             http://www.gz-dc.com
**-----------------------------------�ļ���Ϣ--------------------------------------------
** �ļ�����:   hmi_user_uart.c
** �޸�ʱ��:   2011-05-18
** �ļ�˵��:   �û�MCU��������������
** ����֧�֣�  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------
                                  ʹ�ñض�
   hmi_user_uart.c�еĴ��ڷ��ͽ��պ�����3�����������ڳ�ʼ��Uartinti()������1���ֽ�SendChar()��
   �����ַ���SendStrings().����ֲ������ƽ̨����Ҫ�޸ĵײ��
   ��������,����ֹ�޸ĺ������ƣ������޷���HMI������(hmi_driver.c)ƥ�䡣
--------------------------------------------------------------------------------------



----------------------------------------------------------------------------------------
                          1. ����STM32ƽ̨��������
----------------------------------------------------------------------------------------*/
#include "base.h"
#include "usart.h"
#include "hmi_user_uart.h"
#include "hmi_driver.h"
#include "cmd_queue.h"
#include "cmd_process.h"
/****************************************************************************
* ��    �ƣ� UartInit()
* ��    �ܣ� ���ڳ�ʼ��
* ��ڲ����� ��
* ���ڲ����� ��
****************************************************************************/

#define T_UART	huart1
#define R_UART	huart1
//#define R_UART_IRQ	huart1
#define R_UART_	USART1

unsigned char buffer[1];

void TFT_Init(void)
{
    HAL_UART_Receive_IT(&R_UART, buffer,sizeof(buffer));//ʹ�ܽ����ж�
    queue_reset();
}
void Param_Update(void) //��ȡ��ǰ�²���
{
    qsize size = queue_find_cmd(cmd_buffer,CMD_MAX_SIZE);
    if(size)
    {
        ProcessMessage((PCTRL_MSG)cmd_buffer, size);//ָ���
        //LED1_T;
    }
}
void USART1_IRQHandler() 
{ 
	HAL_UART_IRQHandler(&R_UART); 
	HAL_UART_Receive_IT(&R_UART, buffer,sizeof(buffer));
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==R_UART_)
	{
		u8 rec=*((huart->pRxBuffPtr)-1); //�����鸳ֵ
		queue_push(rec);//��������
		Param_Update();//�ж����洦����ָ��
		HAL_UART_Receive_IT(&R_UART, buffer,sizeof(buffer));
	}
}

/*****************************************************************
* ��    �ƣ� SendChar()
* ��    �ܣ� ����1���ֽ�
* ��ڲ����� t  ���͵��ֽ�
* ���ڲ����� ��
 *****************************************************************/
void  SendChar(uchar t)
{
    HAL_UART_Transmit(&T_UART,&t,1,1000);
}


