/*
 * Final_Project.c
 *
 *  Created on: Dec 25, 2023
 *      Author: E-M-W-E
 */
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/MCAL/GI/GI_interface.h"

#include "../Include/MCAL/UART/UART_Interface.h"

#include "../Include/MCAL/TIMER/TIMER_Interface.h"


#include "../Include/HAL/Final_Project/Final_Project_Interface.h"
#include "../Include/HAL/Final_Project/Final_Project_Private.h"
#include "../Include/HAL/Final_Project/Final_Project_Cfg.h"


#define F_CPU 8000000UL

typedef struct {
    u8 username[20];
    u8 password[20];
} Account;

u8 Global_AccountCounter = 0;
Account accounts[20];

void H_voidRegister()
{
    if (Global_AccountCounter < 10)
    {
        Account newAccount;
        u8 spaceCounter = 0;
        while (1)
        {
            spaceCounter = 0;
            MUART_voidSendStringSyncNonBlocking("Enter your Username:\n(Note: Username must not include spaces)\n(Note: Press # when you are done)\n");
            MUART_voidClearBuffer();
            MUART_voidClearBuffer();
            for (u8 i = 0; i < 20; i++)
            {
                newAccount.username[i] = MUART_u8ReadByteSyncBlocking();
                if (newAccount.username[i] == '#')
                {
                    newAccount.username[i] = '\0';
                    break;
                }
            }
            for (u8 i = 0; newAccount.username[i] != '\0'; i++)
            {
                if (newAccount.username[i] == ' ')
                {
                    spaceCounter++;
                }
            }
            if (spaceCounter == 0)
            {
                MUART_voidSendStringSyncNonBlocking("\nEnter your Password\n(Note: Press # when you are done)\n");
                MUART_voidClearBuffer();
                MUART_voidClearBuffer();
                for (u8 i = 0; i < 20; i++)
                {
                    newAccount.password[i] = MUART_u8ReadByteSyncBlocking();
                    if (newAccount.password[i] == '#')
                    {
                        newAccount.password[i] = '\0';
                        break;
                    }
                }
                accounts[Global_AccountCounter++] = newAccount;
                MUART_voidSendStringSyncNonBlocking("Account Has been Registered Successfully\n");
                break;
            }
            else
            {
                MUART_voidSendStringSyncNonBlocking("Username must not include spaces\nPlease Try Again");
            }
        }
    }
    else
    {
        MUART_voidSendStringSyncNonBlocking("Maximum number of accounts (10) reached.\n");
        MUART_voidSendStringSyncNonBlocking("Would you like to replace an existing account? (Y/N)\n");
        MUART_voidClearBuffer();
        MUART_voidClearBuffer();
        u8 choice = MUART_u8ReadByteSyncBlocking();
        if (choice == 'Y' || choice == 'y')
        {
            H_voidReplaceAccount();
        }
    }
    H_voidHomePageLogOrReg();
}

void H_voidReplaceAccount()
{
    MUART_voidSendStringSyncNonBlocking("Enter the username of the account you want to replace:\n");
    u8 usernameToReplace[20];
    MUART_voidClearBuffer();
    MUART_voidClearBuffer();
    for (u8 i = 0; i < 20; i++)
    {
        usernameToReplace[i] = MUART_u8ReadByteSyncBlocking();
        if (usernameToReplace[i] == '#')
        {
            usernameToReplace[i] = '\0';
            break;
        }
    }

    u8 found = 0;
    for (u8 i = 0; i < Global_AccountCounter; i++)
    {
        if (strcmp(accounts[i].username, usernameToReplace) == 0)
        {
            found = 1;
            Account newAccount;
            MUART_voidSendStringSyncNonBlocking("Enter the new Username:\n");
            MUART_voidClearBuffer();
            MUART_voidClearBuffer();
            for (u8 j = 0; j < 20; j++)
            {
                newAccount.username[j] = MUART_u8ReadByteSyncBlocking();
                if (newAccount.username[j] == '#')
                {
                    newAccount.username[j] = '\0';
                    break;
                }
            }
            MUART_voidSendStringSyncNonBlocking("\nEnter the new Password:\n");
            MUART_voidClearBuffer();
            MUART_voidClearBuffer();
            for (u8 j = 0; j < 20; j++)
            {
                newAccount.password[j] = MUART_u8ReadByteSyncBlocking();
                if (newAccount.password[j] == '#')
                {
                    newAccount.password[j] = '\0';
                    break;
                }

            }
            accounts[i] = newAccount;
            MUART_voidSendStringSyncNonBlocking("Account has been replaced successfully.\n");
            break;
        }
    }
    if (!found)
    {
        MUART_voidSendStringSyncNonBlocking("Account not found.\n");
    }
    H_voidHomePageLogOrReg();
}

void H_voidLogIn()
{
    u8 localu8FirstChoice;
    Account loggedInAccount;
    u8 usernameFound = 0;
    MUART_voidSendStringSyncNonBlocking("Enter your Username:\n(Note: Press # when you are done)\n");
    MUART_voidClearBuffer();
    MUART_voidClearBuffer();
    for (u8 i = 0; i < 20; i++)
    {
        loggedInAccount.username[i] = MUART_u8ReadByteSyncBlocking();
        if (loggedInAccount.username[i] == '#')
        {
            loggedInAccount.username[i] = '\0';
            break;
        }
    }
    for (u8 i = 0; i < Global_AccountCounter; i++)
    {
        if (strcmp(loggedInAccount.username, accounts[i].username) == 0)
        {
            usernameFound = 1;
            u8 attempts = 0;
            while (attempts < 3)
            {
                MUART_voidSendStringSyncNonBlocking("\nEnter your Password:\n(Note: Press # when you are done)\n");
                MUART_voidClearBuffer();
                MUART_voidClearBuffer();
                for (u8 j = 0; j < 20; j++)
                {
                    loggedInAccount.password[j] = MUART_u8ReadByteSyncBlocking();
                    if (loggedInAccount.password[j] == '#')
                    {
                        loggedInAccount.password[j] = '\0';
                        break;
                    }
                }
                if (strcmp(loggedInAccount.password, accounts[i].password) == 0)
                {
                    MUART_voidSendStringSyncNonBlocking("1.Home Page\n2.Replace Account\n");
                    MUART_voidClearBuffer();
                    MUART_voidClearBuffer();
                    localu8FirstChoice = MUART_u8ReadByteSyncBlocking();
                    if (localu8FirstChoice == '1')
                    {
                        H_voidHomePageAfterLogIn();
                    }
                    else if (localu8FirstChoice == '2')
                    {
                        H_voidReplaceAccount();
                    }
                    break;
                }
                else
                {
                    attempts++;
                    MUART_voidSendStringSyncNonBlocking("Incorrect Password. Please try again.\n");
                }
            }
            if (attempts == 3)
            {
                MUART_voidSendStringSyncNonBlocking("Maximum attempts reached. Please try again later.\n");

                H_voidGenerateSirenSound();
                H_voidHomePageLogOrReg();

            }
            break;
        }
    }
    if (!usernameFound)
    {
        MUART_voidSendStringSyncNonBlocking("Username not found. Please try again.\n");
        H_voidHomePageLogOrReg();
    }
}




void H_voidGenerateSirenSound()
{
    for (int i = 0; i < 4; i++)
    {
    	for (u16 i=0 ; i<255 ;i+=10)
    	{
		MTIMER0_voidSetOCR0Value(i);
		_delay_ms(200);
    	}
        for (int j = 255; j >= 0; j-=10)
        {
            MTIMER0_voidSetOCR0Value(j);
            _delay_ms(200);
        }
    }
}

void H_voidHomePageLogOrReg()
{
	u8 localu8FirstChoise=0;
	MUART_voidSendStringSyncNonBlocking("\nHello in your Home\n");
	MUART_voidSendStringSyncNonBlocking("\n1-log in\n2-Register\n");
	MUART_voidClearBuffer();
	MUART_voidClearBuffer();
	localu8FirstChoise=MUART_u8ReadByteSyncBlocking();

	if (localu8FirstChoise=='1')
	{
		H_voidLogIn();
	}
	else if (localu8FirstChoise=='2')
	{
		H_voidRegister();
	}

}

void H_voidHomePageAfterLogIn()
{
	u8 local_u8choice=0;
	u8 local_u8Option=0;
	MUART_voidSendStringSyncNonBlocking("HELLO IN YOUR HOME\n");
	MUART_voidSendStringSyncNonBlocking("1-OPEN THE DOOR\n");
	MUART_voidSendStringSyncNonBlocking("2-CLOSE THE DOOR\n");
	MUART_voidSendStringSyncNonBlocking("3-LED ON\n");
	MUART_voidSendStringSyncNonBlocking("4-LED OFF\n");
	MUART_voidSendStringSyncNonBlocking("5-Log Out\n");
	MUART_voidClearBuffer();
	MUART_voidClearBuffer();
	local_u8Option=MUART_u8ReadByteSyncBlocking();
	if (local_u8Option=='1')
	{
		H_voidOpeningDoor();
		H_voidHomePageAfterLogIn();
	}
	else if (local_u8Option=='2')
	{
		H_voidClosingDoor();
		H_voidHomePageAfterLogIn();
	}
	else if (local_u8Option=='3')
	{
		H_voidLedOn();
		H_voidHomePageAfterLogIn();

	}
	else if (local_u8Option=='4')
	{
		H_voidLedOff();
		H_voidHomePageAfterLogIn();
	}
	else if (local_u8Option == '5')
	{
		H_voidHomePageLogOrReg();
	}
	else
	{
		MUART_voidSendStringSyncNonBlocking("\nPlease Enter Valid Option\n");
		H_voidHomePageAfterLogIn();
	}

}

void H_voidOpeningDoor()
{
	u8 local_u8Check=0;
	local_u8Check=MDIO_GetPinValue(MOTOR_PORT,MOTOR_PIN);
	if(local_u8Check==DIO_SET)
	{
		MUART_voidSendStringSyncNonBlocking("DOOR IS ALREADY OPENED\n");
	}
	else
	{
	MUART_voidSendStringSyncNonBlocking("DOOR IS OPENENIG NOW\n\n");
	MDIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN,DIO_SET);
	_delay_ms(1000);
	MUART_voidSendStringSyncNonBlocking("DOOR OPENED\n\n");
	MUART_voidSendStringSyncNonBlocking("-----------------------\n");
	}
}

void H_voidClosingDoor()
{
	u8 local_u8Check=0;
	local_u8Check=MDIO_GetPinValue(MOTOR_PORT,MOTOR_PIN);
	if(local_u8Check==DIO_RESET)
	{
		MUART_voidSendStringSyncNonBlocking("DOOR IS ALREADY CLOSED\n");
	}
	else
	{
	MUART_voidSendStringSyncNonBlocking("DOOR IS CLOSING NOW\n\n");
	MDIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN,DIO_RESET);
	_delay_ms(1000);
	MUART_voidSendStringSyncNonBlocking("DOOR CLOSED\n\n");
	MUART_voidSendStringSyncNonBlocking("-----------------------\n");
	}
}

void H_voidLedOn()
{
	u8 local_u8Check=0;
	local_u8Check=MDIO_GetPinValue(LED_PORT,LED_PIN);
	if(local_u8Check==DIO_SET)
	{
		MUART_voidSendStringSyncNonBlocking("LED IS ALREADY ON\n\n");
	}
	else
	{
	MUART_voidSendStringSyncNonBlocking("LED IS ON NOW\n\n");
	MDIO_voidSetPinValue(LED_PORT,LED_PIN,DIO_SET);
	_delay_ms(1000);
	MUART_voidSendStringSyncNonBlocking("LED ON\n\n");
	MUART_voidSendStringSyncNonBlocking("-----------------------\n");
	}
}

void H_voidLedOff()
{
	u8 local_u8Check=0;
	local_u8Check=MDIO_GetPinValue(LED_PORT,LED_PIN);
	if(local_u8Check==DIO_RESET)
	{
		MUART_voidSendStringSyncNonBlocking("LED IS ALREADY OFF\n");
	}
	else
	{
		MUART_voidSendStringSyncNonBlocking("LED IS OFF NOW\n\n");
		MDIO_voidSetPinValue(LED_PORT,LED_PIN,DIO_RESET);
		_delay_ms(1000);
		MUART_voidSendStringSyncNonBlocking("LED OFF\n\n");
		MUART_voidSendStringSyncNonBlocking("-----------------------\n");
	}
}
