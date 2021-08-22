#pragma once

#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>

namespace engine
{
enum KeyCode
{
    kUnknown = -1,
    kSpace,
    kApostrophe,
    kComma,
    kMinus,
    kPeriod,
    kSlash,
    k0,
    k1,
    k2,
    k3,
    k4,
    k5,
    k6,
    k7,
    k8,
    k9,
    kSemicolon,
    kEqual,
    kA,
    kB,
    kC,
    kD,
    kE,
    kF,
    kG,
    kH,
    kI,
    kJ,
    kK,
    kL,
    kM,
    kN,
    kO,
    kP,
    kQ,
    kR,
    kS,
    kT,
    kU,
    kV,
    kW,
    kX,
    kY,
    kZ,
    kLeftBracket,
    kBackslash,
    kRightBracket,
    kGraceAccent,
    kEscape,
    kEnter,
    kTab,
    kBackspace,
    kInsert,
    kDelete,
    kRight,
    kLeft,
    kDown,
    kUp,
    kPageUp,
    kPageDown,
    kHome,
    kEnd,
    kCapsLock,
    kScrollLock,
    kNumLock,
    kPrintScreen,
    kPause,
    kF1,
    kF2,
    kF3,
    kF4,
    kF5,
    kF6,
    kF7,
    kF8,
    kF9,
    kF10,
    kF11,
    kF12,
    kKeypad0,
    kKeypad1,
    kKeypad2,
    kKeypad3,
    kKeypad4,
    kKeypad5,
    kKeypad6,
    kKeypad7,
    kKeypad8,
    kKeypad9,
    kKeypadDecimal,
    kKeypadDivide,
    kKeypadMultiply,
    kKeypadSubtract,
    kKeypadAdd,
    kKeypadEnter,
    kKeypadEqual,
    kLeftShift,
    kLeftControl,
    kLeftAlt,
    kLeftSuper,
    kRightShift,
    kRightControl,
    kRightAlt,
    kRightSuper,
    kMenu
};

class Window
{
public:
    Window(std::uint32_t width, std::uint32_t height, char const* title);
    ~Window();

    // Returns HWND in the case of WIN32 platform
    void* GetNativeHandle() const;
    std::uint32_t GetWidth() const { return width_; }
    std::uint32_t GetHeight() const { return height_; }

    void PollEvents();
    bool ShouldClose() const;
    bool GetKey(KeyCode code) const;

private:
    std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)> window_;
    std::uint32_t width_ = ~0u;
    std::uint32_t height_ = ~0u;
};

} // namespace engine
