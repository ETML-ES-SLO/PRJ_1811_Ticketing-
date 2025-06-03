
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "appSDCard.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Application Data

  Summary:
    Holds appSDCardlication data

  Description:
    This structure holds the appSDCardlication's data.

  Remarks:
    This structure should be initialized by the APP_SDCARD_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_SDCARD_DATA __attribute__ ((coherent, aligned(4))) appSDCardData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback funtions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SDCARD_Initialize ( void )

  Remarks:
    See prototype in appSDCard.h.
 */

void APP_SDCARD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appSDCardData.state = APP_SDCARD_MOUNT_DISK;

    /* TODO: Initialize your appSDCardlication's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_SDCARD_Tasks ( void )

  Remarks:
    See prototype in appSDCard.h.
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
    }    
    else
    {
        appSDCardData.state = NOP;
        SDCARDPLUGED = false;
        SDCARDMOUNTED = false;
        SDCARDFILEFOUND = false;
        SDCARDFILEREADED = false;
    }
    switch(appSDCardData.state)
    {
        break;
        case NOP:
        {
            appSDCardData.state = APP_SDCARD_MOUNT_DISK;
            break;
        }        
        
        case APP_SDCARD_MOUNT_DISK:
        {
            
            if(SYS_FS_Mount("/dev/mmcblka1", "/mnt/myDrive", FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again untill success. */

                appSDCardData.state = APP_SDCARD_MOUNT_DISK;
            }
            else
            {
                /* Mount was successful. Unmount the disk, for testing. */

                appSDCardData.state = APP_SDCARD_UNMOUNT_DISK;
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

                appSDCardData.state = APP_SDCARD_UNMOUNT_DISK;
            }
            else
            {
                /* UnMount was successful. Mount the disk again */

                appSDCardData.state = APP_SDCARD_MOUNT_DISK_AGAIN;
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

                appSDCardData.state = APP_SDCARD_MOUNT_DISK_AGAIN;
            }
            else
            {
                /* Mount was successful. Set current drive so that we do not have to use absolute path. */
                SDCARDMOUNTED = true;
                appSDCardData.state = APP_SDCARD_SET_CURRENT_DRIVE;
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
                appSDCardData.state = APP_SDCARD_ERROR;
            }
            else
            {
                /* Open a file for reading. */
                appSDCardData.state = APP_SDCARD_Shearch_File;
            }
        }
        break;
            
/******************************************************************************/
/******************************************************************************/      
        case APP_SDCARD_Shearch_File:
        {
            appSDCardData.fileHandle = SYS_FS_FileOpen(fileName,(SYS_FS_FILE_OPEN_READ));
            if(appSDCardData.fileHandle == SYS_FS_HANDLE_INVALID)
            {

            }
            else
            {
                SDCARDFILEFOUND = true;
                appSDCardData.state = APP_SDCARD_ReadNBStudents;               
            }
        }         
        break;  
        
/******************************************************************************/
/******************************************************************************/       
        case APP_SDCARD_ReadNBStudents:
        {
            SYS_FS_FileStringGet(appSDCardData.fileHandle,(void *)appSDCardData.data,50);
            POS = 0;
            while(appSDCardData.data[POS] != ';' && appSDCardData.data[POS] != '\n')
            {
                POS++;
            }
            if(appSDCardData.data[POS] == ';')
            {
                SDCARDFILEREADED = true;
                if(appSDCardData.data[POS+2] == ';')
                {
                    Nbstudents [1] = appSDCardData.data [POS+1];
                    Nbstudents [0] = '0';
                }
                else
                {
                    Nbstudents [1] = appSDCardData.data [POS+2];
                    Nbstudents [0] = appSDCardData.data [POS+1];              
                }    
            }
            I_Nbstudents = atoi(Nbstudents);
            SDCARDFILEREADED = true;
            appSDCardData.state = APP_SDCARD_GetStudentsID;               
        }         
        break;    
                             
        
/******************************************************************************/
/******************************************************************************/    
        case APP_SDCARD_GetStudentsID:
        {
            for(I = 0; I < I_Nbstudents; I ++)
            {
                SYS_FS_FileStringGet(appSDCardData.fileHandle,(void *)appSDCardData.data2,50);
                for(J = 0; J < 8; J++)
                {
                    C_ID[J] = appSDCardData.data2 [J];
                }
                Students_Info[I].ID = strtoul(C_ID,NULL,16);
                for(J = 9; appSDCardData.data2 [J] != ';';J++)
                {
                    Name[J-9] = appSDCardData.data2[J];
                }
                strcpy(Students_Info[I].StudentName,Name);
                if(J+2 == '\r')
                {
                    LimQuest[1] = appSDCardData.data2 [J+1];
                    LimQuest[0] = 0;
                }
                else
                {
                    LimQuest[1] = appSDCardData.data2 [J+2];
                    LimQuest[0] = appSDCardData.data2 [J+1];
                }
                Students_Info[I].LimitQues = atoi(LimQuest);    
                for(J = 0; J < sizeof(Name); J++)
                {
                    Name[J] = '\n';
                }
            }           
            appSDCardData.state = APP_SDCARD_CLOSE_FILE;
            break;
        }
        case APP_SDCARD_CLOSE_FILE:
        {
            /* Close both files */
            SYS_FS_FileClose(appSDCardData.fileHandle);
             /* The test was successful. Lets idle. */
            appSDCardData.state = APP_SDCARD_IDLE;
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
    appSDCardData.state = NewState;
}

void __ISR(_SPI_2_VECTOR, ipl1AUTO) _IntHandlerSPIInstance1(void)
{
    DRV_SPI_Tasks(sysObj.spiObjectIdx1);
}
 
/*******************************************************************************
 End of File
 */
