#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <vector>
#include <string>

using std::string;

typedef const char* cchp;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, wxEmptyString) {
      b1.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += ONE;
        updateTextField(display);
      });
      
      b2.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += TWO;
        updateTextField(display);
      });
      
      b3.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += THREE;
        updateTextField(display);
      });
      
      b4.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += FOUR;
        updateTextField(display);
      });
      
      b5.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += FIVE;
        updateTextField(display);
      });
      
      b6.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += SIX;
        updateTextField(display);
      });
      
      b7.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += SEVEN;
        updateTextField(display);
      });
      
      b8.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += EIGHT;
        updateTextField(display);
      });
      
      b9.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += NINE;
        updateTextField(display);
      });
      
      b0.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += ZERO;
        updateTextField(display);
      });
      
      bPlus.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += PLUS;
        updateTextField(display);
      });
      
      bMinus.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        display += MINUS;
        updateTextField(display);
      });
    }
    
    // The two indexes mark the positions of the button in the calculator grid.
    const wxPoint buttonPosition(const wxPoint idx) {
      const wxPoint initialPosition = BUTTON_STARTING_POSITION + PADDING;
      const wxPoint additionalOffset = mult(BUTTON_SIZE_PADDING, idx);
      const wxPoint finalPosition = initialPosition + additionalOffset;
      return finalPosition;
    }

  private:

    void updateTextField(const std::string& text) {
      operation_display->SetValue(text);
    }

    const wxPoint mult(const wxPoint point, const wxPoint _mult) {
      const wxPoint result = wxPoint{point.x * _mult.x, point.y * _mult.y};
      return result;
    }

    // const vector<char> display = new vector<char>();
    string display{""};

    cchp ONE{"1"};
    cchp TWO{"2"};
    cchp THREE{"3"};
    cchp FOUR{"4"};
    cchp FIVE{"5"};
    cchp SIX{"6"};
    cchp SEVEN{"7"};
    cchp EIGHT{"8"};
    cchp NINE{"9"};
    cchp ZERO{"0"};
    // --
    cchp PLUS{"+"};
    cchp MINUS{"-"};
    cchp MULTIPLY{"x"};
    cchp DIVIDE{"/"};
    cchp EQUAL{"="};

    const int PDG{8};
    const int ULW{48};
    const int BLW{PDG + ULW};
    const int TLW{20};

    const wxPoint BUTTON_SIZE_POINT{ULW, ULW};
    const wxPoint PADDING{PDG, PDG};
    const wxPoint BUTTON_SIZE_PADDING{BLW, BLW};
    const wxSize BUTTON_STARTING_POSITION{0, 50};

    const wxSize BUTTON_SIZE{BUTTON_SIZE_POINT.x, BUTTON_SIZE_POINT.y};
    const wxSize WIDE_BUTTON_SIZE{(BLW + ULW), BUTTON_SIZE_POINT.y};


    wxPanel* panel = new wxPanel(this);
    /// wxStaticText* operation_display = new wxStaticText(panel, wxID_ANY, "", {PDG, PDG}, {200, 20});
    wxTextCtrl* operation_display = new wxTextCtrl(panel, wxID_ANY, "0", {10, 10});
    wxButton b1{panel, wxID_ANY, ONE, buttonPosition({0, 0}), BUTTON_SIZE};
    wxButton b2{panel, wxID_ANY, TWO, buttonPosition({1, 0}), BUTTON_SIZE};
    wxButton b3{panel, wxID_ANY, THREE, buttonPosition({2, 0}), BUTTON_SIZE};
    wxButton b4{panel, wxID_ANY, FOUR, buttonPosition({0, 1}), BUTTON_SIZE};
    wxButton b5{panel, wxID_ANY, FIVE, buttonPosition({1, 1}), BUTTON_SIZE};
    wxButton b6{panel, wxID_ANY, SIX, buttonPosition({2, 1}), BUTTON_SIZE};
    wxButton b7{panel, wxID_ANY, SEVEN, buttonPosition({0, 2}), BUTTON_SIZE};
    wxButton b8{panel, wxID_ANY, EIGHT, buttonPosition({1, 2}), BUTTON_SIZE};
    wxButton b9{panel, wxID_ANY, NINE, buttonPosition({2, 2}), BUTTON_SIZE};
    wxButton b0{panel, wxID_ANY, ZERO, buttonPosition({0, 3}), BUTTON_SIZE};
    wxButton bPlus{panel, wxID_ANY, PLUS, buttonPosition({3, 0}), BUTTON_SIZE};
    wxButton bMinus{panel, wxID_ANY, MINUS, buttonPosition({3, 1}), BUTTON_SIZE};
    wxButton bEqual{panel, wxID_ANY, EQUAL, buttonPosition({1, 3}), WIDE_BUTTON_SIZE};
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
