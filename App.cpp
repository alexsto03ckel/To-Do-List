#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame* mainFrame = new MainFrame("To-Do List"); //set the title
    mainFrame->SetClientSize(800, 600);
    mainFrame->Centre();
    mainFrame->Show();

    return true;
}
