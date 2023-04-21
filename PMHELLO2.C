//==========================================
// PMHELLO2.C : PM Sample Program
// Version: 1.01
// License: 3-Clause BSD License
// Authors:
// - Martin Iturbide, 2022
// - Charles Petzold, 1988
//==========================================
/*
 *  PMHELLO2.C -- OS/2 PM "Hello, world" Program -- Window Procedure #2
 *               (c) 1988, Ziff Communications Company
 *               PC Magazine * Charles Petzold, 7/88
*/

#define INCL_GPI
#include <os2.h>

MRESULT EXPENTRY ClientWndProc (HWND hwnd, USHORT msg, MPARAM mp1, MPARAM mp2)
     {
     static CHAR  szText[] = "Hello, world" ;
     static LONG  lLen = sizeof szText - 1 ;
     static SHORT cxClient, cyClient ;
     HPS          hps ;
     POINTL       ptl, aptlTextBox[TXTBOX_COUNT] ;

     switch (msg)
          {
          case WM_SIZE:
               cxClient = SHORT1FROMMP (mp2) ;
               cyClient = SHORT2FROMMP (mp2) ;
               return 0 ;

          case WM_PAINT:
               hps = WinBeginPaint (hwnd, 0, NULL) ;
               GpiErase (hps) ;

               GpiQueryTextBox (hps, lLen, (PCH)szText, TXTBOX_COUNT, aptlTextBox) ;

               ptl.x = (cxClient - (aptlTextBox[TXTBOX_BOTTOMRIGHT].x -
                                    aptlTextBox[TXTBOX_BOTTOMLEFT].x)) / 2 ;
               ptl.y = (cyClient - (aptlTextBox[TXTBOX_TOPLEFT].y -
                                    aptlTextBox[TXTBOX_BOTTOMLEFT].y)) / 2 ;

               GpiCharStringAt (hps, &ptl, lLen, (PCCH)szText) ;

               WinEndPaint (hps) ;
               return 0 ;
          }
     return WinDefWindowProc (hwnd, msg, mp1, mp2) ;
     }
