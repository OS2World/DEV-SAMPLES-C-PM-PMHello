/*---------------------------------------------------------------------
   PMHELLO3.C -- OS/2 PM "Hello, world" Program -- Window Procedure #3
                 (c) 1988, Ziff Communications Company
                 PC Magazine * Charles Petzold, 7/88
  ---------------------------------------------------------------------*/

#define INCL_GPI
#include <os2.h>

MRESULT EXPENTRY ClientWndProc (HWND hwnd, USHORT msg, MPARAM mp1, MPARAM mp2)
     {
     static CHAR  szText[] = "Hello, world" ;
     static LONG  lLen = sizeof szText - 1 ;
     static SHORT cxClient, cyClient ;
     HPS          hps ;
     GRADIENTL    gradl ;
     POINTL       ptl, aptlTextBox[TXTBOX_COUNT] ;

     switch (msg)
          {
          case WM_SIZE:
               cxClient = SHORT1FROMMP (mp2) ;
               cyClient = SHORT2FROMMP (mp2) ;
               return 0 ;

          case WM_PAINT:
               hps = WinBeginPaint (hwnd, NULL, NULL) ;
               GpiErase (hps) ;

               gradl.x = cxClient ;
               gradl.y = cyClient ;
               GpiSetCharAngle (hps, &gradl) ;
               GpiSetCharMode (hps, CM_MODE3) ;

               GpiQueryTextBox (hps, lLen, szText, TXTBOX_COUNT, aptlTextBox) ;

               ptl.x = (cxClient - (aptlTextBox[TXTBOX_BOTTOMRIGHT].x -
                                    aptlTextBox[TXTBOX_TOPLEFT].x)) / 2 ;
               ptl.y = (cyClient - (aptlTextBox[TXTBOX_TOPRIGHT].y -
                                    aptlTextBox[TXTBOX_BOTTOMLEFT].y)) / 2 ;

               GpiCharStringAt (hps, &ptl, lLen, szText) ;

               WinEndPaint (hps) ;
               return 0 ;
          }
     return WinDefWindowProc (hwnd, msg, mp1, mp2) ;
     }
