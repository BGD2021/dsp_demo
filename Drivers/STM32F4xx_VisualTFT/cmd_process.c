#include "hmi_driver.h"
#include "hmi_user_uart.h"
#include "cmd_queue.h"
#include "cmd_process.h"
#include "base.h"
#include "stdio.h"
#include "string.h"
#include "stm32f4xx_hal.h"
//#include "head_define.h"//���̺궨��

/*! 
 *  \brief  ��Ϣ��������
 *  \param msg ��������Ϣ
 *  \param size ��Ϣ����
 */


uint8 cmd_buffer[CMD_MAX_SIZE];//ָ���
 
void ProcessMessage( PCTRL_MSG msg, uint16 size)
{
	uint8 cmd_type = msg->cmd_type;//ָ������
	uint8 ctrl_msg = msg->ctrl_msg;   //��Ϣ������
	uint8 control_type = msg->control_type;//�ؼ�����
	uint16 screen_id = PTR2U16(&msg->screen_id);//����ID
	uint16 control_id = PTR2U16(&msg->control_id);//�ؼ�ID
	uint32 value = PTR2U32(msg->param);//��ֵ

	switch(cmd_type)
	{		
	case NOTIFY_TOUCH_PRESS://����������
	case NOTIFY_TOUCH_RELEASE://�������ɿ�
		NotifyTouchXY(cmd_buffer[1],PTR2U16(cmd_buffer+2),PTR2U16(cmd_buffer+4),NULL);
		break;	
	case NOTIFY_WRITE_FLASH_OK://дFLASH�ɹ�
		NotifyWriteFlash(1,NULL);
		break;
	case NOTIFY_WRITE_FLASH_FAILD://дFLASHʧ��
		NotifyWriteFlash(0,NULL);
		break;
	case NOTIFY_READ_FLASH_OK://��ȡFLASH�ɹ�
		NotifyReadFlash(1,cmd_buffer+2,size-6,NULL);//ȥ��֡ͷ֡β
		break;
	case NOTIFY_READ_FLASH_FAILD://��ȡFLASHʧ��
		NotifyReadFlash(0,0,0,NULL);
		break;
	case NOTIFY_READ_RTC://��ȡRTCʱ��
		NotifyReadRTC(cmd_buffer[1],cmd_buffer[2],cmd_buffer[3],cmd_buffer[4],cmd_buffer[5],cmd_buffer[6],cmd_buffer[7],NULL);
		break;
	case NOTIFY_CONTROL:
		{
			if(ctrl_msg==MSG_GET_CURRENT_SCREEN)//����ID�仯֪ͨ
			{
				NotifyScreen(screen_id,NULL);
			}
			else
			{
				switch(control_type)
				{
				case kCtrlButton: //��ť�ؼ�
					NotifyButton(screen_id,control_id,msg->param[0],NULL);
					break;
				case kCtrlText://�ı��ؼ�
					NotifyText(screen_id,control_id,msg->param,NULL);
					break;
				case kCtrlProgress: //�������ؼ�
					NotifyProgress(screen_id,control_id,value,NULL);
					break;
				case kCtrlSlider: //�������ؼ�
					NotifySlider(screen_id,control_id,value,NULL);
					break;
				case kCtrlMeter: //�Ǳ�ؼ�
					NotifyMeter(screen_id,control_id,value,NULL);
					break;
				case kCtrlMenu://�˵��ؼ�
					NotifyMenu(screen_id,control_id,msg->param[0],msg->param[1],NULL);
					break;
				case kCtrlSelector://ѡ��ؼ�
					NotifySelector(screen_id,control_id,msg->param[0],NULL);
					break;
				case kCtrlRTC://����ʱ�ؼ�
					NotifyTimer(screen_id,control_id,NULL);
					break;
				default:
					break;
				}
			}			
		}
		break;
	default:
		break;
	}
}

void SetTextValueInt32(uint16 screen_id, uint16 control_id,int32 value)
{
	
}

void SetTextValueFloat(uint16 screen_id, uint16 control_id,float value)
{
	
}

void UpdateUI()
{
	//TODO: ����û�����
}

/*! 
 *  \brief  �����л�֪ͨ
 *  \details  ��ǰ����ı�ʱ(�����GetScreen)��ִ�д˺���
 *  \param screen_id ��ǰ����ID
 */
void NotifyScreen(uint16 screen_id,void* userdata)
{
   
}

/*! 
 *  \brief  ���������¼���Ӧ
 *  \param press 1���´�������3�ɿ�������
 *  \param x x����
 *  \param y y����
 */
void NotifyTouchXY(uint8 press,uint16 x,uint16 y,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  ��ť�ؼ�֪ͨ
 *  \details  ����ť״̬�ı�(�����GetControlValue)ʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param state ��ť״̬��0����1����
 */

void NotifyButton(uint16 screen_id, uint16 control_id, uint8  state,void* userdata)
{
     if(screen_id==0)
	 {
		 if(control_id==4)
		 {

		 }
		 else if(control_id==5)
		 {

		 }
		 else if(control_id==3)
		 {
			 
		 }
	 }
}

/*! 
 *  \brief  �ı��ؼ�֪ͨ
 *  \details  ���ı�ͨ�����̸���(�����GetControlValue)ʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param str �ı��ؼ�����
 */
void NotifyText(uint16 screen_id, uint16 control_id, uint8 *str,void* userdata)
{
	
}

/*! 
 *  \brief  �������ؼ�֪ͨ
 *  \details  ����GetControlValueʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param value ֵ
 */
void NotifyProgress(uint16 screen_id, uint16 control_id, uint32 value,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  �������ؼ�֪ͨ
 *  \details  ���������ı�(�����GetControlValue)ʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param value ֵ
 */
void NotifySlider(uint16 screen_id, uint16 control_id, uint32 value,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  �Ǳ�ؼ�֪ͨ
 *  \details  ����GetControlValueʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param value ֵ
 */
void NotifyMeter(uint16 screen_id, uint16 control_id, uint32 value,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  �˵��ؼ�֪ͨ
 *  \details  ���˵���»��ɿ�ʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param item �˵�������
 *  \param state ��ť״̬��0�ɿ���1����
 */
void NotifyMenu(uint16 screen_id, uint16 control_id, uint8  item, uint8  state,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  ѡ��ؼ�֪ͨ
 *  \details  ��ѡ��ؼ��仯ʱ��ִ�д˺���
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 *  \param item ��ǰѡ��
 */
void NotifySelector(uint16 screen_id, uint16 control_id, uint8  item,void* userdata)
{
    
	//TODO: ����û����� 
}

/*! 
 *  \brief  ��ʱ����ʱ֪ͨ����
 *  \param screen_id ����ID
 *  \param control_id �ؼ�ID
 */
void NotifyTimer(uint16 screen_id, uint16 control_id,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  ��ȡ�û�FLASH״̬����
 *  \param status 0ʧ�ܣ�1�ɹ�
 *  \param _data ��������
 *  \param length ���ݳ���
 */
void NotifyReadFlash(uint8 status,uint8 *_data,uint16 length,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  д�û�FLASH״̬����
 *  \param status 0ʧ�ܣ�1�ɹ�
 */
void NotifyWriteFlash(uint8 status,void* userdata)
{
	//TODO: ����û�����
}

/*! 
 *  \brief  ��ȡRTCʱ�䣬ע�ⷵ�ص���BCD��
 *  \param year �꣨BCD��
 *  \param month �£�BCD��
 *  \param week ���ڣ�BCD��
 *  \param day �գ�BCD��
 *  \param hour ʱ��BCD��
 *  \param minute �֣�BCD��
 *  \param second �루BCD��
 */
void NotifyReadRTC(uint8 year,uint8 month,uint8 week,uint8 day,uint8 hour,uint8 minute,uint8 second,void* userdata)
{
    
}
