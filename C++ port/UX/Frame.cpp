//Class Implementation of Frame.h

#include "Frame.h"
#include "../InputHandler/commandHandler.h"

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_CLOSE(MainFrame::OnExit)
    EVT_MENU(ID_Save, MainFrame::OnSave)
    EVT_MENU(ID_Load, MainFrame::OnLoad)
    EVT_MENU(ID_About, MainFrame::OnAbout)
    EVT_MENU(ID_Exit, MainFrame::OnClose)
    EVT_TEXT_ENTER(ID_Input, MainFrame::OnEnter)
    EVT_UPDATE_UI(ID_Input, MainFrame::OnFocus)
END_EVENT_TABLE()

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
:wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

MainFrame::~MainFrame()
{
}

int init = 0;

void MainFrame::CreateGUIControls()
{
    AppSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(AppSizer);
    this->SetAutoLayout(true);

    Panel = new wxPanel(this, ID_Panel, wxPoint(0,0), wxSize(330,330));
    AppSizer->Add(Panel, 1, wxALIGN_CENTER|wxEXPAND|wxALL, 0);

    MainSizer = new wxBoxSizer(wxVERTICAL);
    Panel->SetSizer(MainSizer);
    Panel->SetAutoLayout(true);

    Output = new wxTextCtrl(Panel, ID_Output, wxEmptyString, wxPoint(5,5), wxSize(185,89), wxTE_READONLY|wxTE_LEFT|wxTE_MULTILINE, wxDefaultValidator, _("Output"));
    Output->SetMaxLength(0);
    Output->SetFocus();
    MainSizer->Add(Output, 1, wxALIGN_CENTER|wxEXPAND|wxALL, 5);

    Input = new wxTextCtrl(Panel, ID_Input, wxEmptyString, wxPoint(5,99), wxSize(185,25), wxTE_LEFT|wxTE_NO_VSCROLL|wxTE_MULTILINE, wxDefaultValidator, _("Output"));
    Input->SetMaxLength(0);
    Input->AppendText("Input command here...");
    MainSizer->Add(Input, 0, wxALIGN_CENTER|wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    MenuBar = new wxMenuBar();
	wxMenu *ID_File = new wxMenu();
	wxMenu *ID_About = new wxMenu();
	ID_File->Append(ID_Save, _("Save..."), _(""), wxITEM_NORMAL);
	ID_File->Append(ID_Load, _("Load..."), _(""), wxITEM_NORMAL);
	ID_File->Append(ID_Exit, _("Exit"), _(""), wxITEM_NORMAL);
	MenuBar->Append(ID_File, _("File"));
	MenuBar->Append(ID_About, _("About"));
	SetMenuBar(MenuBar);

	SetTitle(_("Text Based Game"));
	SetIcon(wxIcon("C:/Users/JunDong/Documents/GitHub/Text-Based-Game/Images/Icon.ico", wxBITMAP_TYPE_ICO));

	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
}

void MainFrame::OnSave(wxCommandEvent& event)
{
	wxFileDialog
	   saveFileDialog(this, _("Save game file"), "", "",
                      "JSON files (*json)|*.json",
                      wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

    //Do saving code here
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;

    //Need saving validation
}

void MainFrame::OnLoad(wxCommandEvent& event)
{
    wxFileDialog
        openFileDialog(this, _("Load game file"), "", "",
                       "JSON files (*.json)|*.json",
                       wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    //Do loading code here
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    //Need loading validation, goto "http://docs.wxwidgets.org/trunk/classwx_file_dialog.html"
}

void MainFrame::OnEnter(wxCommandEvent& event)
{
    if (Input->GetValue() == ""){
        return;
    }
    Output->AppendText(Input->GetValue());
    Output->AppendText(_("\n"));
    Handler(std::string(Input->GetValue()));
    Input->SetValue(wxT(""));
}

void MainFrame::OnFocus(wxUpdateUIEvent& event)
{
    if (init == 0 && Input->HasFocus()){
        Input->SetValue(wxT(""));
        init++;
    }
    return;
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	//AboutForm* aframe = new AboutForm(this);
	//aframe->Show();
}

void MainFrame::OnExit(wxCloseEvent& event)
{
	Destroy();
}

void MainFrame::OnClose(wxCommandEvent& event)
{
    Destroy();
}
