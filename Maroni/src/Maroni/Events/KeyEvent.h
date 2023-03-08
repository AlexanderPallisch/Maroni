#pragma once

#include "Event.h"
#include <sstream>

namespace Maroni {
    class MARONI_API KeyEvent: public Event {
    public:
        inline int GetKeyCode() const { return m_keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode) : m_keyCode(keycode) {}
        int m_keyCode;
    };

    class MARONI_API KeyPressedEvent: public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount): KeyEvent(keycode), m_repeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_repeatCount; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_repeatCount;
    };

    class MARONI_API KeyTypedEvent: public KeyEvent {
    public:
        KeyTypedEvent(int keycode): KeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };

    class MARONI_API KeyReleasedEvent: public KeyEvent {
    public:
        KeyReleasedEvent(int keycode): KeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    };
}
