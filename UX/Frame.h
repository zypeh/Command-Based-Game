// Header for the main frame

#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

//If compiler can use pre-compiled header....
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/frame.h>
#else
#include <wx/wxprec.h>
#endif // WX_PRECOMP

//All the necessary "components"
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/menu.h>

//Define MainFrame first for later initialization
#undef MainFrame_STYLE
#define MainFrame_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX | wxFRAME_SHAPED

//Handling of the main app
class TextBasedGame: public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
};

//Handling of the MainFrame
class MainFrame: public wxFrame
{
public:
    MainFrame(wxWindow *parent, wxWindowID id = 1, const wxString& title = wxT("Command Based Game"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = MainFrame_STYLE);
    virtual ~MainFrame();

    //Stating the event handler for each interaction
    void OnExit(wxCloseEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnLoad(wxCommandEvent& event);
    void OnEnter(wxCommandEvent& event);
    void OnFocus(wxUpdateUIEvent& event);
    void OnClose(wxCommandEvent& event);
    void OnKey(wxKeyEvent& event);


private:
    //Declares the event table
    wxDECLARE_EVENT_TABLE();

    //Control declaration
    wxMenuBar *MenuBar;
    wxTextCtrl *Output;
    wxTextCtrl *Input;
    wxPanel *Panel;
    wxBoxSizer *AppSizer;
    wxBoxSizer *MainSizer;
    wxFileDialog *SaveFileDialog;
    wxFileDialog *LoadFileDialog;

    //Creates control in a new place
    void CreateGUIControls();

    //Declares the function call IDs
    enum
    {
        ID_Save = 1,
        ID_Load = 2,
        ID_Panel = 3,
        ID_Exit = 4,
        ID_Input = 5,
        ID_Output = 6,
        ID_About = 7
    };
};
#endif // FRAME_H_INCLUDED
