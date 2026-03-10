#pragma once
#include <wx/wx.h>
#include <wx/timer.h>

class MyCanvas : public wxPanel
{
public:
    MyCanvas(wxWindow* parent);

private:
    wxTimer m_timer;
    int m_x, m_y;
    int m_dx, m_dy;

    void OnTimer(wxTimerEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnPaint(wxPaintEvent& event);
};