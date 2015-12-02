//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// Pr�dkosc pilki
int vx = 3, vy=3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZegarDzwoni(TObject *Sender)
{
        // Musimy to troch� poprawic
        if(Pilka->Left + vx < Problem1->Left + Problem1->Width) {
                // Pilka odbija si� od paletki
                if (Pilka->Top + Pilka->Height >= Problem1->Top &&
                        Problem1->Top + Problem1->Height >= Pilka->Top)
                        vx *= -1.5;
                else { // Przegra�es
                        static bool pokazano = false;

						if(!pokazano){
                                pokazano = true;
                                Timer1->Enabled = false;
								MessageBox(NULL, "Demasiado lento!", "PERDISTE", MB_OK);
                        }
                }
        }

        if(Pilka->Left + vx + Pilka->Width > Problem2->Left)
        {
                vx *= -1;
        }

        if(Pilka->Top + vy < Blokada1->Top + Blokada1->Height)
                vy *= -1;

        if(Pilka->Top + Pilka->Height + vy > Blokada2->Top)
                vy *= -1;

        Pilka->Left += vx;
        Pilka->Top += vy;
}
void __fastcall TForm1::MyszkaRusza(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
		Problem1->Top = Y;

        if(Problem1->Top < Blokada1->Top + Blokada1->Height)
                Problem1->Top = Blokada1->Top + Blokada1->Height;

        if(Problem1->Top + Problem1->Height > Blokada2->Top)
                Problem1->Top = Blokada2->Top - Problem1->Height;  
}

//---------------------------------------------------------------------------







