#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, wxEmptyString) {
      button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText1->SetLabel(wxString::Format("button1 clicked %d times", ++button1Clicked));
      });

      button2->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText2->SetLabel(wxString::Format("button2 clicked %d times", ++button2Clicked));
      });
    }
    
  private:
    const char* ONE =     "1";
    const char* TWO =     "2";
    const char* THREE =   "3";
    const char* FOUR =    "4";
    const char* FIVE =    "5";
    const char* SIX =     "6";
    const char* SEVEN =   "7";
    const char* EIGHT =   "8";
    const char* NINE =    "9";
    const char* ZERO =    "0";

    const int PDG = 8;
    const int ULW = 48;
    const int BLW = PDG + ULW;
    const int TLW = 20;

    wxPanel* panel = new wxPanel(this);
    wxButton* button1 = new wxButton(panel, wxID_ANY, ONE, {PDG, PDG}, {ULW, ULW});
    wxButton* button2 = new wxButton(panel, wxID_ANY, TWO, {(PDG + BLW), PDG}, {ULW, ULW});
    wxButton* button3 = new wxButton(panel, wxID_ANY, THREE, {(PDG + (2*BLW)), PDG}, {ULW, ULW});
    wxButton* button4 = new wxButton(panel, wxID_ANY, FOUR, {PDG, (PDG + BLW)}, {ULW, ULW});
    wxButton* button5 = new wxButton(panel, wxID_ANY, FIVE, {(PDG + BLW), (PDG + BLW)}, {ULW, ULW});
    wxButton* button6 = new wxButton(panel, wxID_ANY, SIX, {(PDG + (2*BLW)), (PDG + BLW)}, {ULW, ULW});
    wxButton* button7 = new wxButton(panel, wxID_ANY, SEVEN, {PDG, (PDG + (2*BLW))}, {ULW, ULW});
    wxButton* button8 = new wxButton(panel, wxID_ANY, EIGHT, {(PDG + BLW), (PDG + (2*BLW))}, {ULW, ULW});
    wxButton* button9 = new wxButton(panel, wxID_ANY, NINE, {(PDG + (2*BLW)), (PDG + (2*BLW))}, {ULW, ULW});
    wxButton* button0 = new wxButton(panel, wxID_ANY, ZERO, {(PDG + BLW), (PDG + (3*BLW))}, {ULW, ULW});
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "button1 clicked 0 times", {50, (PDG + (12*TLW))}, {200, 20});
    wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, "button2 clicked 0 times", {50, (PDG + (13*TLW))}, {200, 20});
    int button1Clicked = 0;
    int button2Clicked = 0;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
