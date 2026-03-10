#include "MyFrame.h"
#include "MyCanvas.h"

MyFrame::MyFrame(wxWindow* parent)
    : MainFrame(parent)  // chiama il costruttore della classe base
{
    // Bind dell'evento per il pulsante
    // Aggiunta del canvas al frame
    MyCanvas* canvas = new MyCanvas(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(canvas, 1, wxEXPAND);
    SetSizer(sizer);
}
