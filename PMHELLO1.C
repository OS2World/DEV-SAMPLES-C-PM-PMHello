/*---------------------------------------------------------------------
   PMHELLO1.C -- OS/2 PM "Hello, world" Program -- Window Procedure #1
                 (c) 1988, Ziff Communications Company
                 PC Magazine * Charles Petzold, 7/88
  ---------------------------------------------------------------------*/

#include <os2.h>

MRESULT EXPENTRY ClientWndProc (HWND hwnd, USHORT msg, MPARAM mp1, MPARAM mp2)
     {
     HPS   hps ;
     RECTL rcl ;

     switch (msg)
	  {
          case WM_PAINT:
               hps = WinBeginPaint (hwnd, NULL, NULL) ;

               WinQueryWindowRect (hwnd, &rcl) ;
               WinDrawText (hps, -1, "Hello, world", &rcl,
                            CLR_NEUTRAL, CLR_BACKGROUND,
                            DT_CENTER | DT_VCENTER | DT_ERASERECT) ;

               WinEndPaint (hps) ;
               return 0 ;
          }
     return WinDefWindowProc (hwnd, msg, mp1, mp2) ;
     }
