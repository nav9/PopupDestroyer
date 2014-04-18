#include <windows.h>
#include <stdio.h>
#define VK_0	0x30//for the zero key on the keyboard
#define BUFFER_LENGTH 255

BOOL CALLBACK EnumWindowsProc(HWND hWnd, long lParam) 
{
    char buff[BUFFER_LENGTH];//to store the name of the window title

    if (IsWindowVisible(hWnd)) 
    {
        GetWindowText(hWnd, (LPSTR) buff, BUFFER_LENGTH-1);//get the window name
        //printf("%s\n\n", buff);//print window name

        for(short i=0;i<BUFFER_LENGTH-1;++i)
        {
            //yes I know this isn't the best way, but at that time I needed to create the program quickly, and
            //the string comparison functions were strangely not working!
            if (buff[i]=='A')
            {
                if (buff[i+1]=='u' && buff[i+2]=='t' && buff[i+3]=='h' && buff[i+4]=='e' && buff[i+5]=='n' && buff[i+6]=='t' && buff[i+7]=='i' \
                    && buff[i+8]=='c' && buff[i+9]=='a' && buff[i+10]=='t' && buff[i+11]=='i' && buff[i+12]=='o' && buff[i+13]=='n' \
                    && buff[i+14]==' ' && buff[i+15]=='R' && buff[i+16]=='e' && buff[i+17]=='q' && buff[i+18]=='u' && buff[i+19]=='i' \
                    && buff[i+20]=='r' && buff[i+21]=='e' && buff[i+22]=='d' )
                {//kept this if condition separate so that it doesn't go out of buffer bounds
                    //printf("destroyed popup\n");
                    keybd_event(VK_ESCAPE , NULL, KEYEVENTF_EXTENDEDKEY | 0, 0);//key code to press ESC
                    break;//to exit the for loop
                }
            }
        }//for  
    }//if
    return TRUE;
}//EnumWindowsProc

int main() 
{
    printf("\nPopup Destroyer - By Navin Ipe\n");
    printf("------------------------------------------------ \n");
    printf("              30th October 2012 \n");
    printf("------------------------------------------------ \n\n\n");
    
    printf("This program will simulate an Esc keypress on any window whose name begins with 'Authentication Required' \n");
    printf("To close this program, use the taskmanager or just click the close button of this window \n");
    printf("\nListening...\n");
    while(1)
    {
        EnumWindows(EnumWindowsProc, 0);//Enumerates the windows open, once
        Sleep(1);
    }//while

    return 0;
}//main
