#include "window.hpp"

#ifdef WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#else
#error Other platforms are not currently supported
#endif

#include <stdexcept>
#include <unordered_map>

namespace engine
{
namespace
{
std::unordered_map<int, KeyCode> kGlfwKeyToKeyCode =
{
    { GLFW_KEY_UNKNOWN,       kUnknown          },
    { GLFW_KEY_SPACE,         kSpace            },
    { GLFW_KEY_APOSTROPHE,    kApostrophe       },
    { GLFW_KEY_COMMA,         kComma            },
    { GLFW_KEY_MINUS,         kMinus            },
    { GLFW_KEY_PERIOD,        kPeriod           },
    { GLFW_KEY_SLASH,         kSlash            },
    { GLFW_KEY_0,             k0                },
    { GLFW_KEY_1,             k1                },
    { GLFW_KEY_2,             k2                },
    { GLFW_KEY_3,             k3                },
    { GLFW_KEY_4,             k4                },
    { GLFW_KEY_5,             k5                },
    { GLFW_KEY_6,             k6                },
    { GLFW_KEY_7,             k7                },
    { GLFW_KEY_8,             k8                },
    { GLFW_KEY_9,             k9                },
    { GLFW_KEY_SEMICOLON,     kSemicolon        },
    { GLFW_KEY_EQUAL,         kEqual            },
    { GLFW_KEY_A,             kA                },
    { GLFW_KEY_B,             kB                },
    { GLFW_KEY_C,             kC                },
    { GLFW_KEY_D,             kD                },
    { GLFW_KEY_E,             kE                },
    { GLFW_KEY_F,             kF                },
    { GLFW_KEY_G,             kG                },
    { GLFW_KEY_H,             kH                },
    { GLFW_KEY_I,             kI                },
    { GLFW_KEY_J,             kJ                },
    { GLFW_KEY_K,             kK                },
    { GLFW_KEY_L,             kL                },
    { GLFW_KEY_M,             kM                },
    { GLFW_KEY_N,             kN                },
    { GLFW_KEY_O,             kO                },
    { GLFW_KEY_P,             kP                },
    { GLFW_KEY_Q,             kQ                },
    { GLFW_KEY_R,             kR                },
    { GLFW_KEY_S,             kS                },
    { GLFW_KEY_T,             kT                },
    { GLFW_KEY_U,             kU                },
    { GLFW_KEY_V,             kV                },
    { GLFW_KEY_W,             kW                },
    { GLFW_KEY_X,             kX                },
    { GLFW_KEY_Y,             kY                },
    { GLFW_KEY_Z,             kZ                },
    { GLFW_KEY_LEFT_BRACKET,  kLeftBracket      },
    { GLFW_KEY_BACKSLASH,     kBackslash        },
    { GLFW_KEY_RIGHT_BRACKET, kRightBracket     },
    { GLFW_KEY_GRAVE_ACCENT,  kGraceAccent      },
    { GLFW_KEY_ESCAPE,        kEscape           },
    { GLFW_KEY_ENTER,         kEnter            },
    { GLFW_KEY_TAB,           kTab              },
    { GLFW_KEY_BACKSPACE,     kBackspace        },
    { GLFW_KEY_INSERT,        kInsert           },
    { GLFW_KEY_DELETE,        kDelete           },
    { GLFW_KEY_RIGHT,         kRight            },
    { GLFW_KEY_LEFT,          kLeft             },
    { GLFW_KEY_DOWN,          kDown             },
    { GLFW_KEY_UP,            kUp               },
    { GLFW_KEY_PAGE_UP,       kPageUp           },
    { GLFW_KEY_PAGE_DOWN,     kPageDown         },
    { GLFW_KEY_HOME,          kHome             },
    { GLFW_KEY_END,           kEnd              },
    { GLFW_KEY_CAPS_LOCK,     kCapsLock         },
    { GLFW_KEY_SCROLL_LOCK,   kScrollLock       },
    { GLFW_KEY_NUM_LOCK,      kNumLock          },
    { GLFW_KEY_PRINT_SCREEN,  kPrintScreen      },
    { GLFW_KEY_PAUSE,         kPause            },
    { GLFW_KEY_F1,            kF1               },
    { GLFW_KEY_F2,            kF2               },
    { GLFW_KEY_F3,            kF3               },
    { GLFW_KEY_F4,            kF4               },
    { GLFW_KEY_F5,            kF5               },
    { GLFW_KEY_F6,            kF6               },
    { GLFW_KEY_F7,            kF7               },
    { GLFW_KEY_F8,            kF8               },
    { GLFW_KEY_F9,            kF9               },
    { GLFW_KEY_F10,           kF10              },
    { GLFW_KEY_F11,           kF11              },
    { GLFW_KEY_F12,           kF12              },
    { GLFW_KEY_KP_0,          kKeypad0          },
    { GLFW_KEY_KP_1,          kKeypad1          },
    { GLFW_KEY_KP_2,          kKeypad2          },
    { GLFW_KEY_KP_3,          kKeypad3          },
    { GLFW_KEY_KP_4,          kKeypad4          },
    { GLFW_KEY_KP_5,          kKeypad5          },
    { GLFW_KEY_KP_6,          kKeypad6          },
    { GLFW_KEY_KP_7,          kKeypad7          },
    { GLFW_KEY_KP_8,          kKeypad8          },
    { GLFW_KEY_KP_9,          kKeypad9          },
    { GLFW_KEY_KP_DECIMAL,    kKeypadDecimal    },
    { GLFW_KEY_KP_DIVIDE,     kKeypadDivide     },
    { GLFW_KEY_KP_MULTIPLY,   kKeypadMultiply   },
    { GLFW_KEY_KP_SUBTRACT,   kKeypadSubtract   },
    { GLFW_KEY_KP_ADD,        kKeypadAdd        },
    { GLFW_KEY_KP_ENTER,      kKeypadEnter      },
    { GLFW_KEY_KP_EQUAL,      kKeypadEqual      },
    { GLFW_KEY_LEFT_SHIFT,    kLeftShift        },
    { GLFW_KEY_LEFT_CONTROL,  kLeftControl      },
    { GLFW_KEY_LEFT_ALT,      kLeftAlt          },
    { GLFW_KEY_LEFT_SUPER,    kLeftSuper        },
    { GLFW_KEY_RIGHT_SHIFT,   kRightShift       },
    { GLFW_KEY_RIGHT_CONTROL, kRightControl     },
    { GLFW_KEY_RIGHT_ALT,     kRightAlt         },
    { GLFW_KEY_RIGHT_SUPER,   kRightSuper       },
    { GLFW_KEY_MENU,          kMenu             },
};

}

Window::Window(std::uint32_t width, std::uint32_t height, char const* title)
    : window_(nullptr, glfwDestroyWindow)
    , width_(width)
    , height_(height)
{
    if (!glfwInit())
    {
        throw std::runtime_error("glfwInit() failed");
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create the main window
    window_.reset(glfwCreateWindow(width, height, title, nullptr, nullptr));

    if (!window_.get())
    {
        throw std::runtime_error("Failed to create GLFW window!");
    }

    glfwMakeContextCurrent(window_.get());

}

Window::~Window()
{

}

void Window::PollEvents()
{
    glfwPollEvents();
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(window_.get());
}

bool Window::GetKey(KeyCode code) const
{
    return true;//glfwGetKey
}

void* Window::GetNativeHandle() const
{
    return glfwGetWin32Window(window_.get());
}

} // namespace engine
