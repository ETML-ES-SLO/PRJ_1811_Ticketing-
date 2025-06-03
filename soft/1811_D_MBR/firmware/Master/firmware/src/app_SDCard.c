/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app_sdcard.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_sdcard.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_SDCARD_DATA app_sdcardData;
//APP_SDCARD_DATA __attribute__ ((coherent, aligned(4))) app_sdcardData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/

//bool SD_Card_off = true;
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SDCARD_Initialize ( void )

  Remarks:
    See prototype in app_sdcard.h.
 */

void APP_SDCARD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_sdcardData.state = APP_SDCARD_MOUNT_DISK;

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_SDCARD_Tasks ( void )

  Remarks:
    See prototype in app_sdcard.h.
 */

void APP_SDCARD_Tasks ( void )
{

    /* The appSDCardlication task state machine */
    static char fileName [10] = "File.csv";
    char POS;
    char C_ID [8];
    char Name [15];
    char LimQuest [2];
    int I,J;
    uint32_t ID;
    bool SD_Detect;
    SD_Detect = PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_10);
    if(SD_Detect)
    {
        SDCARDPLUGED = true;
        //SD_Card_off = false;
    }    
    else
    {
        app_sdcardData.state = NOP;
        SDCARDPLUGED = false;
        SDCARDMOUNTED = false;
        SDCARDFILEFOUND = false;
        SDCARDFILEREADED = false;
        //SD_Card_off = true;
    }
    switch(app_sdcardData.state)
    {
        break;
        case NOP:
        {
            app_sdcardData.state = APP_SDCARD_MOUNT_DISK;
            break;
        }        
        
        case APP_SDCARD_MOUNT_DISK:
        {
            
            if(SYS_FS_Mount("/dev/mmcblka1", "/mnt/myDrive", FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again untill success. */

                app_sdcardData.state = APP_SDCARD_MOUNT_DISK;
            }
            else
            {
                /* Mount was successful. Unmount the disk, for testing. */
                SDCARDMOUNTED = true;
                app_sdcardData.state = APP_SDCARD_UNMOUNT_DISK;
            }
        }
        break;
            
            
/******************************************************************************/
/******************************************************************************/            
        case APP_SDCARD_UNMOUNT_DISK:
        {
            if(SYS_FS_Unmount("/mnt/myDrive") != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again untill success. */

                app_sdcardData.state = APP_SDCARD_UNMOUNT_DISK;
            }
            else
            {
                /* UnMount was successful. Mount the disk again */

                app_sdcardData.state = APP_SDCARD_MOUNT_DISK_AGAIN;
            }
        }
        break;
            
            
/******************************************************************************/
/******************************************************************************/      
        case APP_SDCARD_MOUNT_DISK_AGAIN:
        {
            if(SYS_FS_Mount("/dev/mmcblka1", "/mnt/myDrive", FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again untill success. */

                app_sdcardData.state = APP_SDCARD_MOUNT_DISK_AGAIN;
            }
            else
            {
                /* Mount was successful. Set current drive so that we do not have to use absolute path. */
                SDCARDMOUNTED = true;
                app_sdcardData.state = APP_SDCARD_SET_CURRENT_DRIVE;
            }
        }
        break;
            
            
/******************************************************************************/
/******************************************************************************/      
        case APP_SDCARD_SET_CURRENT_DRIVE:
        {
            if(SYS_FS_CurrentDriveSet("/mnt/myDrive") == SYS_FS_RES_FAILURE)
            {
                /* Error while setting current drive */
                app_sdcardData.state = APP_SDCARD_ERROR;
            }
            else
            {
                /* Open a file for reading. */
                app_sdcardData.state = APP_SDCARD_Shearch_File;
            }
        }
        break;
            
/******************************************************************************/
/******************************************************************************/      
        case APP_SDCARD_Shearch_File:
        {
            app_sdcardData.fileHandle = SYS_FS_FileOpen(fileName,(SYS_FS_FILE_OPEN_READ));
            if(app_sdcardData.fileHandle == SYS_FS_HANDLE_INVALID)
            {

            }
            else
            {
                SDCARDFILEFOUND = true;
                app_sdcardData.state = APP_SDCARD_ReadNBStudents;               
            }
        }         
        break;  
        
/******************************************************************************/
/******************************************************************************/       
        case APP_SDCARD_ReadNBStudents:
        {
            SYS_FS_FileStringGet(app_sdcardData.fileHandle,(void *)app_sdcardData.data,50);
            POS = 0;
            while(app_sdcardData.data[POS] != ';' && app_sdcardData.data[POS] != '\n')
            {
                POS++;
            }
            if(app_sdcardData.data[POS] == ';')
            {
                SDCARDFILEREADED = true;
                if(app_sdcardData.data[POS+2] == ';')
                {
                    Nbstudents [1] = app_sdcardData.data [POS+1];
                    Nbstudents [0] = '0';
                }
                else
                {
                    Nbstudents [1] = app_sdcardData.data [POS+2];
                    Nbstudents [0] = app_sdcardData.data [POS+1];              
                }    
            }
            I_Nbstudents = atoi(Nbstudents);
            SDCARDFILEREADED = true;
            app_sdcardData.state = APP_SDCARD_GetStudentsID;               
        }         
        break;    
                             
        
/******************************************************************************/
/******************************************************************************/    
        case APP_SDCARD_GetStudentsID:
        {
            for(I = 0; I < I_Nbstudents; I ++)
            {
                SYS_FS_FileStringGet(app_sdcardData.fileHandle,(void *)app_sdcardData.data2,50);
                for(J = 0; J < 8; J++)
                {
                    C_ID[J] = app_sdcardData.data2 [J];
                }
                Students_Info[I].ID = strtoul(C_ID,NULL,16);
                for(J = 9; app_sdcardData.data2 [J] != ';';J++)
                {
                    Name[J-9] = app_sdcardData.data2[J];
                }
                strcpy(Students_Info[I].StudentName,Name);
                if(J+2 == '\r')
                {
                    LimQuest[1] = app_sdcardData.data2 [J+1];
                    LimQuest[0] = 0;
                }
                else
                {
                    LimQuest[1] = app_sdcardData.data2 [J+2];
                    LimQuest[0] = app_sdcardData.data2 [J+1];
                }
                Students_Info[I].LimitQues = atoi(LimQuest);    
                for(J = 0; J < sizeof(Name); J++)
                {
                    Name[J] = '\n';
                }
            }           
            app_sdcardData.state = APP_SDCARD_CLOSE_FILE;
            break;
        }
        case APP_SDCARD_CLOSE_FILE:
        {
            /* Close both files */
            SYS_FS_FileClose(app_sdcardData.fileHandle);
             /* The test was successful. Lets idle. */
            app_sdcardData.state = APP_SDCARD_IDLE;
        }
        break;

        case APP_SDCARD_IDLE:
            
            break;
        case APP_SDCARD_ERROR:

            break;
        default:
            break;

    }

} //End of APP_SDCARD_Tasks

void SD_StateChange (APP_SDCARD_STATES NewState)
{
    app_sdcardData.state = NewState;
}

void __ISR(_SPI_2_VECTOR, ipl1AUTO) _IntHandlerSPIInstance1(void)
{
    DRV_SPI_Tasks(sysObj.spiObjectIdx1);
}
 
/*******************************************************************************
 End of File
 */
