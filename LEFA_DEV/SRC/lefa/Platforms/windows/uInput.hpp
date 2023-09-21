#ifndef UINPUT_HPP
#define UINPUT_HPP

void setInputEnabled(bool enabled);

void processInput();
void mouseInput();
bool keyInput(int key);

struct KeyState {
    bool isActive;
    bool isReleased;
    int  mouseX;
    int  mouseY;
    bool isSinglePress;
};


enum keyMaps {
    PRESS_STATE = 0x8000, //is not a Key


//Mouse
    KEY_MS1  = 0x01,   //Left button
    KEY_MS2  = 0x02,   //Right button
    KEY_MS3  = 0x04,   //Middle button
  //KEY_MS4  = 0000,   //otherbuttons
  //KEY_MS5  = 0000,   //otherbuttons

//Keyboard
    //Special Keys
    KEY_ESC  = 0x1B,   //Escape
    KEY_F1   = 0x70,   // F1
    KEY_F2   = 0x71,   // F2
    KEY_F3   = 0x72,   // F3
    KEY_F4   = 0x73,   // F4
    KEY_F5   = 0x74,   // F5
    KEY_F6   = 0x75,   // F6
    KEY_F7   = 0x76,   // F7
    KEY_F8   = 0x77,   // F8
    KEY_F9   = 0x78,   // F9
    KEY_F10  = 0x79,   // F10
    KEY_F11  = 0x7A,   // F11
    KEY_F12  = 0x7B,   // F12
    KEY_BSPC = 0x08,   // Backspace
    KEY_TAB  = 0x09,   // TAB Key
    KEY_CPSL = 0x14,   // Caps lock
    KEY_SHIFT = 0x10,   // Shift Key
    KEY_CTRL = 0x11,   // Control Key
    KEY_ALT  = 0x12,   // Alt Keys
    KEY_SPC  = 0x20,   // Space Key
    KEY_ENTR = 0x0D,   // Enter Key
    KEY_LFAR = 0x25,   // <  left arrow
    KEY_UPAR = 0x26,   // ^  Up arrow
    KEY_RIAR = 0x27,   // >  Right Arrow  
    KEY_DWAR = 0x28,   // ˅  Down Arrow
    //double Keys/key combination/secondary function
    KEY_HYPH = 0xBD,   // OEM_MINUS (_ -) = KEY_HYPH
    //
    KEY_QUOT = 0xDE,   //Quote ' "
    // KEY_DQ   0x22   //Double Quote " = KEY_DQ
    //
    KEY_0    = 0x30,   // 0
    KEY_1    = 0x31,   // 1
    KEY_2    = 0x32,   // 2
    KEY_3    = 0x33,   // 3
    KEY_4    = 0x34,   // 4
    KEY_5    = 0x35,   // 5
    KEY_6    = 0x36,   // 6
    KEY_7    = 0x37,   // 7
    KEY_8    = 0x38,   // 8
    KEY_9    = 0x39,   // 9
    //
    KEY_A    = 0x41,
    KEY_B    = 0x42,
    KEY_C    = 0x43,
    KEY_D    = 0x44,
    KEY_E    = 0x45,
    KEY_F    = 0x46,
    KEY_G    = 0x47,
    KEY_H    = 0x48,
    KEY_I    = 0x49,
    KEY_J    = 0x4A,
    KEY_K    = 0x4B,
    KEY_L    = 0x4C,
    KEY_M    = 0x4D,
    KEY_N    = 0x4E,
    KEY_O    = 0x4F,
    KEY_P    = 0x50,
    KEY_Q    = 0x51,
    KEY_R    = 0x52,
    KEY_S    = 0x53,
    KEY_T    = 0x54,
    KEY_U    = 0x55,
    KEY_V    = 0x56,
    KEY_W    = 0x57,
    KEY_X    = 0x58,
    KEY_Y    = 0x59,
    KEY_Z    = 0x5A,

};

extern KeyState keyStates[256];
extern KeyState previousKeyStates[256]; // Variável para armazenar os estados anteriores dos botões


#endif //UINPUT_HPP