#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <equals.h>

struct ScreenSpace {
    wxPoint location;
    wxSize size;
    ScreenSpace() : location(wxPoint(0,0)), size(wxSize(0,0)) {}
    ScreenSpace(const wxPoint loc, const wxSize sz): location(loc), size(sz) {}
};

inline bool operator==(const ScreenSpace& a, const ScreenSpace& b){
    return a.location == b.location && a.size == b.size;
}

struct LayoutConfig {
    ushort padding;
    ushort btnWidth;
    ushort btnHeight;

    LayoutConfig(
        const ushort p,
        const ushort w,
        const ushort h
    ): padding(p), btnWidth(w), btnHeight(h) {}

    inline ushort WidthPadded() const {
        return this->padding + this->btnWidth;
    }

    inline ushort HeightPadded() const {
        return this->padding + this->btnHeight;
    }
};

struct ButtonLayout {
    ushort x;
    ushort y;
    ushort width;
    ushort height;

    ButtonLayout(
        ushort xx,
        ushort yy,
        ushort w,
        ushort h
    ): x(xx), y(yy), width(w), height(h) {}
};

class SpaceFactory {
    private:
        inline const static LayoutConfig config = LayoutConfig(8, 48, 48);

        SpaceFactory() = delete;
        SpaceFactory(const SpaceFactory& other) = delete;
        void operator=(const SpaceFactory& other) = delete;
    public:
        static ScreenSpace DisplayScreen() {
            return ScreenSpace(wxPoint(0,0), wxSize(640,480));
        }
        static ScreenSpace Button(const ButtonLayout layout){
            ScreenSpace space;
            // add initial padding::x
            space.location.x = SpaceFactory::config.padding;
            // add initial padding::y
            space.location.y = SpaceFactory::config.padding;
            // add additional padding === (width + padding) * rownumber
            space.location.x += (SpaceFactory::config.WidthPadded()) * layout.x;
            // add additional padding === (height + padding) * columnnumber
            space.location.y += (SpaceFactory::config.HeightPadded()) * layout.y;
            // size
            // Add padded width * width
            space.size.x = ((SpaceFactory::config.WidthPadded()) * layout.width) - SpaceFactory::config.padding;
            // Add padding height * height
            space.size.y = ((SpaceFactory::config.HeightPadded()) * layout.height) - SpaceFactory::config.padding;
            // 
            return space; 
        }
        ~SpaceFactory();
};