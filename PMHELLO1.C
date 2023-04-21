//==========================================
// PMHELLO1.C : PM Sample Program
// Version: 1.01
// License: 3-Clause BSD License
// Authors:
// - Martin Iturbide, 2022
// - Charles Petzold, 1988
//==========================================
/*
 *  PMHELLO1.C -- OS/2 PM "Hello, world" Program -- Window Procedure #1
 *               (c) 1988, Ziff Communications Company
 *               PC Magazine * Charles Petzold, 7/88
*/

#include <os2.h>

MRESULT EXPENTRY ClientWndProc (HWND hwnd, USHORT msg, MPARAM mp1, MPARAM mp2)
     {
     HPS   hps ;
     RECTL rcl ;

     switch (msg)
	  {
          case WM_PAINT:
               hps = WinBeginPaint (hwnd, 0, NULL) ;

               WinQueryWindowRect (hwnd, &rcl) ;
               WinDrawText (hps, -1, (PCCH)"Hello, world", &rcl,
                            CLR_NEUTRAL, CLR_BACKGROUND,
                            DT_CENTER | DT_VCENTER | DT_ERASERECT) ;

               WinEndPaint (hps) ;
               return 0 ;
          }
     return WinDefWindowProc (hwnd, msg, mp1, mp2) ;
     }
