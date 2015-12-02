//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// Velocidad de la pelota
int vx = 5, vy=3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimingMovimiento(TObject *Sender)
{
		if(Pelota->Left + vx < Cursor->Left + Cursor->Width) {
				// If creado para hacer que rebote la pelota
				if (Pelota->Top + Pelota->Height >= Cursor->Top &&
						Cursor->Top + Cursor->Height >= Pelota->Top)
                        vx *= -1.5;
				else {
						static bool derrota = false;

						if(!derrota){
                                derrota = true;
								Timer1->Enabled = false;
								// Alerta cuando se pierde
								MessageBox(NULL, "Demasiado lento!", "PERDISTE", MB_OK);
                        }
                }
        }

        if(Pelota->Left + vx + Pelota->Width > Pared->Left)
        {
                vx *= -1;
        }

        if(Pelota->Top + vy < Borde1->Top + Borde1->Height)
                vy *= -1;

        if(Pelota->Top + Pelota->Height + vy > Borde2->Top)
                vy *= -1;

        Pelota->Left += vx;
        Pelota->Top += vy;
}
void __fastcall TForm1::MovimientoMouse(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
		Cursor->Top = Y;

        if(Cursor->Top < Borde1->Top + Borde1->Height)
                Cursor->Top = Borde1->Top + Borde1->Height;

        if(Cursor->Top + Cursor->Height > Borde2->Top)
                Cursor->Top = Borde2->Top - Cursor->Height;
}

//---------------------------------------------------------------------------











