#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/string.h>

struct ScreenSpace {
    wxPoint* location;
    wxSize* size;
    ScreenSpace(wxPoint* location, wxSize* size): location(location), size(size){};
};

class SpaceFactory {
    private:
        SpaceFactory() = delete;
        SpaceFactory(const SpaceFactory& other) = delete;
        void operator=(const SpaceFactory& other) = delete;
    public:
        static ScreenSpace* DisplayScreen() {
            return new ScreenSpace(new wxPoint{0,0}, new wxSize{0,0});
        }
        ~SpaceFactory();
};