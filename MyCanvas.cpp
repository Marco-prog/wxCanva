#include "MyCanvas.h"

MyCanvas::MyCanvas(wxWindow* parent)
    : wxPanel(parent),
      m_x(300), m_y(150),
      m_dx(3), m_dy(2)
{
    Bind(wxEVT_PAINT,    &MyCanvas::OnPaint,   this);
    Bind(wxEVT_KEY_DOWN, &MyCanvas::OnKeyDown, this);
    m_timer.Bind(wxEVT_TIMER, &MyCanvas::OnTimer, this);
    m_timer.Start(16);
    SetFocus();
}

void MyCanvas::OnTimer(wxTimerEvent& event)
{
    m_x += m_dx;
    m_y += m_dy;

    wxSize size = GetClientSize();
    if (m_x - 60 < 0 || m_x + 60 > size.x) m_dx = -m_dx;
    if (m_y - 60 < 0 || m_y + 60 > size.y) m_dy = -m_dy;

    Refresh();
}

void MyCanvas::OnKeyDown(wxKeyEvent& event)
{
    int step = 10;
    switch (event.GetKeyCode())
    {
        case WXK_LEFT:  m_x -= step; break;
        case WXK_RIGHT: m_x += step; break;
        case WXK_UP:    m_y -= step; break;
        case WXK_DOWN:  m_y += step; break;
        case WXK_SPACE:
            if (m_timer.IsRunning()) m_timer.Stop();
            else m_timer.Start(16);
            break;
    }
    Refresh();
    event.Skip();
}

void MyCanvas::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    dc.SetBackground(wxBrush(*wxWHITE));
    dc.Clear();

    // Rettangolo fisso
    dc.SetPen(wxPen(*wxBLUE,6));
    dc.SetBrush(wxBrush(*wxYELLOW));
    dc.DrawRectangle(50, 50, 150, 80);

    // Cerchio mobile
    dc.SetPen(wxPen(*wxRED, 3));
    dc.SetBrush(wxBrush(*wxGREEN));
    dc.DrawCircle(m_x, m_y, 60);
}