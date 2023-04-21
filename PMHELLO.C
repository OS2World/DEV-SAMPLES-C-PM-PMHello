//==========================================
// PMHELLO.C : PM Sample Program
// Version: 1.01
// License: 3-Clause BSD License
// Authors:
// - Martin Iturbide, 2022
// - Charles Petzold, 1988
//==========================================
/*
 *  PMHELLO.C -- OS/2 PM "Hello, world" Program -- main() Function
 *              (c) 1988, Ziff Communications Company
 *              PC Magazine * Charles Petzold, 7/88 and 11/88
*/

#define INCL_WIN
#include <os2.h>

MRESULT EXPENTRY ClientWndProc (HWND, USHORT, MPARAM, MPARAM) ;

int main (void)
     {
     unsigned char szClientClass [] = "PMHello" ;
     static ULONG flFrameFlags = FCF_TITLEBAR      | FCF_SYSMENU |
                                 FCF_SIZEBORDER    | FCF_MINMAX  |
                                 FCF_SHELLPOSITION | FCF_TASKLIST ;
     HAB          hab ;
     HMQ          hmq ;
     HWND         hwndFrame, hwndClient ;
     QMSG         qmsg ;

     hab = WinInitialize (0) ;
     hmq = WinCreateMsgQueue (hab, 0) ;
     WinRegisterClass (hab, szClientClass, (PFNWP)ClientWndProc, CS_SIZEREDRAW, 0) ;

     hwndFrame = WinCreateStdWindow (HWND_DESKTOP, WS_VISIBLE,
                                     &flFrameFlags, szClientClass, NULL,
                                     0L, 0, 0, &hwndClient) ;

     WinSendMsg (hwndFrame, WM_SETICON,
                 (MPARAM)WinQuerySysPointer (HWND_DESKTOP, SPTR_APPICON, FALSE),
                 NULL) ;

     while (WinGetMsg (hab, &qmsg, 0, 0, 0))
          WinDispatchMsg (hab, &qmsg) ;

     WinDestroyWindow (hwndFrame) ;
     WinDestroyMsgQueue (hmq) ;
     WinTerminate (hab) ;
     return 0 ;
     }
