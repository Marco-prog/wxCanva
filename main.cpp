#include <wx/wx.h>
#include "MyFrame.h"

// Applicazione wxWidgets
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(nullptr);
    frame->Show(true);	
    return true;
}
