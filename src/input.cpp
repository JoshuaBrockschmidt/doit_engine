#include <algorithm>
#include <type_traits>
#include "input.hpp"

namespace DOIT {
	namespace Input {
		bool keysUp[to_integral(Keys::NUM_ITEMS)];
		bool keysDown[to_integral(Keys::NUM_ITEMS)];
		bool keysActive[to_integral(Keys::NUM_ITEMS)];
		bool mouseUp[to_integral(Mouse::NUM_ITEMS)];
		bool mouseDown[to_integral(Mouse::NUM_ITEMS)];
		bool mouseActive[to_integral(Mouse::NUM_ITEMS)];
		int mouse_x, mouse_y;

		void init() {
			for (int k=0; k<to_integral(Keys::NUM_ITEMS); k++) {
				keysDown[k] = false;
				keysUp[k] = false;
				keysActive[k] = false;
			}
			for (int k=0; k<to_integral(Mouse::NUM_ITEMS); k++) {
				mouseDown[k] = false;
				mouseUp[k] = false;
				mouseActive[k] = false;
			}
			mouse_x = 0;
			mouse_y = 0;
		}

		void update() {
			int numkeys;
			const Uint8* keystate = SDL_GetKeyboardState(&numkeys);
			int kSDL, k;
			for (kSDL=0; kSDL<numkeys; kSDL++) {
				k = to_integral(SDLtoKey(kSDL));
				if (keystate[kSDL]) {
					if (!keysActive[k]) {
						keysUp[k] = false;
						keysDown[k] = true;
						keysActive[k] = true;
					} else if (keysDown[k]) {
						keysDown[k] = false;
					}
				} else {
					if (keysActive[k]) {
						keysDown[k] = false;
						keysActive[k] = false;
						keysUp[k] = true;
					} else if (keysUp[k]) {
						keysUp[k] = false;
					}
				}
			}

			Uint32 mousestate = SDL_GetMouseState(&mouse_x, &mouse_y);
			for (k=0; k<to_integral(Mouse::NUM_ITEMS); k++) {
				if (mousestate & SDL_BUTTON(k+1)) {
					if (!mouseActive[k]) {
						mouseUp[k] = false;
						mouseDown[k] = true;
						mouseActive[k] = true;
					} else if (mouseDown[k]) {
						mouseDown[k] = false;
					}
				} else {
					if (mouseActive[k]) {
						mouseDown[k] = false;
						mouseActive[k] = false;
						mouseUp[k] = true;
					} else if (mouseUp[k]) {
						mouseUp[k] = false;
					}
				}
			}
		}

		bool getKeyDown(Keys k) {
			return keysDown[to_integral(k)];
		}

		bool getKeyUp(Keys k) {
			return keysUp[to_integral(k)];
		}

		bool getKey(Keys k) {
			return keysActive[to_integral(k)];
		}

		bool getMouseDown(Mouse btn) {
			return mouseDown[to_integral(btn)];
		}

		bool getMouseUp(Mouse btn) {
			return mouseUp[to_integral(btn)];
		}

		bool getMouse(Mouse btn) {
			return mouseActive[to_integral(btn)];
		}

		void getMouseXY(int& x, int& y) {
			x = mouse_x;
			y = mouse_y;
		}

		Keys SDLtoKey(int SDLkey) {
			switch (SDLkey) {
			case SDL_SCANCODE_UNKNOWN: return Keys::UNKNOWN;
			case SDL_SCANCODE_A: return Keys::A;
			case SDL_SCANCODE_B: return Keys::B;
			case SDL_SCANCODE_C: return Keys::C;
			case SDL_SCANCODE_D: return Keys::D;
			case SDL_SCANCODE_E: return Keys::E;
			case SDL_SCANCODE_F: return Keys::F;
			case SDL_SCANCODE_G: return Keys::G;
			case SDL_SCANCODE_H: return Keys::H;
			case SDL_SCANCODE_I: return Keys::I;
			case SDL_SCANCODE_J: return Keys::J;
			case SDL_SCANCODE_K: return Keys::K;
			case SDL_SCANCODE_L: return Keys::L;
			case SDL_SCANCODE_M: return Keys::M;
			case SDL_SCANCODE_N: return Keys::N;
			case SDL_SCANCODE_O: return Keys::O;
			case SDL_SCANCODE_P: return Keys::P;
			case SDL_SCANCODE_Q: return Keys::Q;
			case SDL_SCANCODE_R: return Keys::R;
			case SDL_SCANCODE_S: return Keys::S;
			case SDL_SCANCODE_T: return Keys::T;
			case SDL_SCANCODE_U: return Keys::U;
			case SDL_SCANCODE_V: return Keys::V;
			case SDL_SCANCODE_W: return Keys::W;
			case SDL_SCANCODE_X: return Keys::X;
			case SDL_SCANCODE_Y: return Keys::Y;
			case SDL_SCANCODE_Z: return Keys::Z;
			case SDL_SCANCODE_1: return Keys::NUM1;
			case SDL_SCANCODE_2: return Keys::NUM2;
			case SDL_SCANCODE_3: return Keys::NUM3;
			case SDL_SCANCODE_4: return Keys::NUM4;
			case SDL_SCANCODE_5: return Keys::NUM5;
			case SDL_SCANCODE_6: return Keys::NUM6;
			case SDL_SCANCODE_7: return Keys::NUM7;
			case SDL_SCANCODE_8: return Keys::NUM8;
			case SDL_SCANCODE_9: return Keys::NUM9;
			case SDL_SCANCODE_0: return Keys::NUM0;
			case SDL_SCANCODE_RETURN: return Keys::RETURN;
			case SDL_SCANCODE_ESCAPE: return Keys::ESCAPE;
			case SDL_SCANCODE_BACKSPACE: return Keys::BACKSPACE;
			case SDL_SCANCODE_TAB: return Keys::TAB;
			case SDL_SCANCODE_SPACE: return Keys::SPACE;
			case SDL_SCANCODE_MINUS: return Keys::MINUS;
			case SDL_SCANCODE_EQUALS: return Keys::EQUALS;
			case SDL_SCANCODE_LEFTBRACKET: return Keys::LEFTBRACKET;
			case SDL_SCANCODE_RIGHTBRACKET: return Keys::RIGHTBRACKET;
			case SDL_SCANCODE_BACKSLASH: return Keys::BACKSLASH;
			case SDL_SCANCODE_NONUSHASH: return Keys::NONUSHASH;
			case SDL_SCANCODE_SEMICOLON: return Keys::SEMICOLON;
			case SDL_SCANCODE_APOSTROPHE: return Keys::APOSTROPHE;
			case SDL_SCANCODE_GRAVE: return Keys::GRAVE;
			case SDL_SCANCODE_COMMA: return Keys::COMMA;
			case SDL_SCANCODE_PERIOD: return Keys::PERIOD;
			case SDL_SCANCODE_SLASH: return Keys::SLASH;
			case SDL_SCANCODE_CAPSLOCK: return Keys::CAPSLOCK;
			case SDL_SCANCODE_F1: return Keys::F1;
			case SDL_SCANCODE_F2: return Keys::F2;
			case SDL_SCANCODE_F3: return Keys::F3;
			case SDL_SCANCODE_F4: return Keys::F4;
			case SDL_SCANCODE_F5: return Keys::F5;
			case SDL_SCANCODE_F6: return Keys::F6;
			case SDL_SCANCODE_F7: return Keys::F7;
			case SDL_SCANCODE_F8: return Keys::F8;
			case SDL_SCANCODE_F9: return Keys::F9;
			case SDL_SCANCODE_F10: return Keys::F10;
			case SDL_SCANCODE_F11: return Keys::F11;
			case SDL_SCANCODE_F12: return Keys::F12;
			case SDL_SCANCODE_PRINTSCREEN: return Keys::PRINTSCREEN;
			case SDL_SCANCODE_SCROLLLOCK: return Keys::SCROLLLOCK;
			case SDL_SCANCODE_PAUSE: return Keys::PAUSE;
			case SDL_SCANCODE_INSERT: return Keys::INSERT;
			case SDL_SCANCODE_HOME: return Keys::HOME;
			case SDL_SCANCODE_PAGEUP: return Keys::PAGEUP;
			case SDL_SCANCODE_DELETE: return Keys::DELETE;
			case SDL_SCANCODE_END: return Keys::END;
			case SDL_SCANCODE_PAGEDOWN: return Keys::PAGEDOWN;
			case SDL_SCANCODE_RIGHT: return Keys::RIGHT;
			case SDL_SCANCODE_LEFT: return Keys::LEFT;
			case SDL_SCANCODE_DOWN: return Keys::DOWN;
			case SDL_SCANCODE_UP: return Keys::UP;
			case SDL_SCANCODE_NUMLOCKCLEAR: return Keys::NUMLOCKCLEAR;
			case SDL_SCANCODE_KP_DIVIDE: return Keys::KP_DIVIDE;
			case SDL_SCANCODE_KP_MULTIPLY: return Keys::KP_MULTIPLY;
			case SDL_SCANCODE_KP_MINUS: return Keys::KP_MINUS;
			case SDL_SCANCODE_KP_PLUS: return Keys::KP_PLUS;
			case SDL_SCANCODE_KP_ENTER: return Keys::KP_ENTER;
			case SDL_SCANCODE_KP_1: return Keys::KP_1;
			case SDL_SCANCODE_KP_2: return Keys::KP_2;
			case SDL_SCANCODE_KP_3: return Keys::KP_3;
			case SDL_SCANCODE_KP_4: return Keys::KP_4;
			case SDL_SCANCODE_KP_5: return Keys::KP_5;
			case SDL_SCANCODE_KP_6: return Keys::KP_6;
			case SDL_SCANCODE_KP_7: return Keys::KP_7;
			case SDL_SCANCODE_KP_8: return Keys::KP_8;
			case SDL_SCANCODE_KP_9: return Keys::KP_9;
			case SDL_SCANCODE_KP_0: return Keys::KP_0;
			case SDL_SCANCODE_KP_PERIOD: return Keys::KP_PERIOD;
			case SDL_SCANCODE_NONUSBACKSLASH: return Keys::NONUSBACKSLASH;
			case SDL_SCANCODE_APPLICATION: return Keys::APPLICATION;
			case SDL_SCANCODE_POWER: return Keys::POWER;
			case SDL_SCANCODE_KP_EQUALS: return Keys::KP_EQUALS;
			case SDL_SCANCODE_F13: return Keys::F13;
			case SDL_SCANCODE_F14: return Keys::F14;
			case SDL_SCANCODE_F15: return Keys::F15;
			case SDL_SCANCODE_F16: return Keys::F16;
			case SDL_SCANCODE_F17: return Keys::F17;
			case SDL_SCANCODE_F18: return Keys::F18;
			case SDL_SCANCODE_F19: return Keys::F19;
			case SDL_SCANCODE_F20: return Keys::F20;
			case SDL_SCANCODE_F21: return Keys::F21;
			case SDL_SCANCODE_F22: return Keys::F22;
			case SDL_SCANCODE_F23: return Keys::F23;
			case SDL_SCANCODE_F24: return Keys::F24;
			case SDL_SCANCODE_EXECUTE: return Keys::EXECUTE;
			case SDL_SCANCODE_HELP: return Keys::HELP;
			case SDL_SCANCODE_MENU: return Keys::MENU;
			case SDL_SCANCODE_SELECT: return Keys::SELECT;
			case SDL_SCANCODE_STOP: return Keys::STOP;
			case SDL_SCANCODE_AGAIN: return Keys::AGAIN;
			case SDL_SCANCODE_UNDO: return Keys::UNDO;
			case SDL_SCANCODE_CUT: return Keys::CUT;
			case SDL_SCANCODE_COPY: return Keys::COPY;
			case SDL_SCANCODE_PASTE: return Keys::PASTE;
			case SDL_SCANCODE_FIND: return Keys::FIND;
			case SDL_SCANCODE_MUTE: return Keys::MUTE;
			case SDL_SCANCODE_VOLUMEUP: return Keys::VOLUMEUP;
			case SDL_SCANCODE_VOLUMEDOWN: return Keys::VOLUMEDOWN;
			case SDL_SCANCODE_KP_COMMA: return Keys::COMMA;
			case SDL_SCANCODE_KP_EQUALSAS400: return Keys::KP_EQUALSAS400;
			case SDL_SCANCODE_INTERNATIONAL1: return Keys::INTERNATIONAL1;
			case SDL_SCANCODE_INTERNATIONAL2: return Keys::INTERNATIONAL2;
			case SDL_SCANCODE_INTERNATIONAL3: return Keys::INTERNATIONAL3;
			case SDL_SCANCODE_INTERNATIONAL4: return Keys::INTERNATIONAL4;
			case SDL_SCANCODE_INTERNATIONAL5: return Keys::INTERNATIONAL5;
			case SDL_SCANCODE_INTERNATIONAL6: return Keys::INTERNATIONAL6;
			case SDL_SCANCODE_INTERNATIONAL7: return Keys::INTERNATIONAL7;
			case SDL_SCANCODE_INTERNATIONAL8: return Keys::INTERNATIONAL8;
			case SDL_SCANCODE_INTERNATIONAL9: return Keys::INTERNATIONAL9;
			case SDL_SCANCODE_LANG1: return Keys::LANG1;
			case SDL_SCANCODE_LANG2: return Keys::LANG2;
			case SDL_SCANCODE_LANG3: return Keys::LANG3;
			case SDL_SCANCODE_LANG4: return Keys::LANG4;
			case SDL_SCANCODE_LANG5: return Keys::LANG5;
			case SDL_SCANCODE_LANG6: return Keys::LANG6;
			case SDL_SCANCODE_LANG7: return Keys::LANG7;
			case SDL_SCANCODE_LANG8: return Keys::LANG8;
			case SDL_SCANCODE_LANG9: return Keys::LANG9;
			case SDL_SCANCODE_ALTERASE: return Keys::ALTERASE;
			case SDL_SCANCODE_SYSREQ: return Keys::SYSREQ;
			case SDL_SCANCODE_CANCEL: return Keys::CANCEL;
			case SDL_SCANCODE_CLEAR: return Keys::CLEAR;
			case SDL_SCANCODE_PRIOR: return Keys::PRIOR;
			case SDL_SCANCODE_RETURN2: return Keys::RETURN2;
			case SDL_SCANCODE_SEPARATOR: return Keys::SEPARATOR;
			case SDL_SCANCODE_OUT: return Keys::OUT;
			case SDL_SCANCODE_OPER: return Keys::OPER;
			case SDL_SCANCODE_CLEARAGAIN: return Keys::CLEARAGAIN;
			case SDL_SCANCODE_CRSEL: return Keys::CRSEL;
			case SDL_SCANCODE_EXSEL: return Keys::EXSEL;
			case SDL_SCANCODE_KP_00: return Keys::KP_00;
			case SDL_SCANCODE_KP_000: return Keys::KP_000;
			case SDL_SCANCODE_THOUSANDSSEPARATOR: return Keys::THOUSANDSSEPARATOR;
			case SDL_SCANCODE_DECIMALSEPARATOR: return Keys::DECIMALSEPARATOR;
			case SDL_SCANCODE_CURRENCYUNIT: return Keys::CURRENCYUNIT;
			case SDL_SCANCODE_CURRENCYSUBUNIT: return Keys::CURRENCYSUBUNIT;
			case SDL_SCANCODE_KP_LEFTPAREN: return Keys::KP_LEFTPAREN;
			case SDL_SCANCODE_KP_RIGHTPAREN: return Keys::KP_RIGHTPAREN;
			case SDL_SCANCODE_KP_LEFTBRACE: return Keys::KP_LEFTBRACE;
			case SDL_SCANCODE_KP_RIGHTBRACE: return Keys::KP_RIGHTBRACE;
			case SDL_SCANCODE_KP_TAB: return Keys::KP_TAB;
			case SDL_SCANCODE_KP_BACKSPACE: return Keys::KP_BACKSPACE;
			case SDL_SCANCODE_KP_A: return Keys::KP_A;
			case SDL_SCANCODE_KP_B: return Keys::KP_B;
			case SDL_SCANCODE_KP_C: return Keys::KP_C;
			case SDL_SCANCODE_KP_D: return Keys::KP_D;
			case SDL_SCANCODE_KP_E: return Keys::KP_E;
			case SDL_SCANCODE_KP_F: return Keys::KP_F;
			case SDL_SCANCODE_KP_XOR: return Keys::KP_XOR;
			case SDL_SCANCODE_KP_POWER: return Keys::KP_POWER;
			case SDL_SCANCODE_KP_PERCENT: return Keys::KP_PERCENT;
			case SDL_SCANCODE_KP_LESS: return Keys::KP_LESS;
			case SDL_SCANCODE_KP_GREATER: return Keys::KP_GREATER;
			case SDL_SCANCODE_KP_AMPERSAND: return Keys::KP_AMPERSAND;
			case SDL_SCANCODE_KP_DBLAMPERSAND: return Keys::KP_DBLAMPERSAND;
			case SDL_SCANCODE_KP_VERTICALBAR: return Keys::KP_VERTICALBAR;
			case SDL_SCANCODE_KP_DBLVERTICALBAR: return Keys::KP_DBLVERTICALBAR;
			case SDL_SCANCODE_KP_COLON: return Keys::KP_COLON;
			case SDL_SCANCODE_KP_HASH: return Keys::KP_HASH;
			case SDL_SCANCODE_KP_SPACE: return Keys::KP_SPACE;
			case SDL_SCANCODE_KP_AT: return Keys::KP_AT;
			case SDL_SCANCODE_KP_EXCLAM: return Keys::KP_EXCLAM;
			case SDL_SCANCODE_KP_MEMSTORE: return Keys::KP_MEMSTORE;
			case SDL_SCANCODE_KP_MEMRECALL: return Keys::KP_MEMRECALL;
			case SDL_SCANCODE_KP_MEMCLEAR: return Keys::KP_MEMCLEAR;
			case SDL_SCANCODE_KP_MEMADD: return Keys::KP_MEMADD;
			case SDL_SCANCODE_KP_MEMSUBTRACT: return Keys::KP_MEMSUBTRACT;
			case SDL_SCANCODE_KP_MEMMULTIPLY: return Keys::KP_MEMMULTIPLY;
			case SDL_SCANCODE_KP_MEMDIVIDE: return Keys::KP_MEMDIVIDE;
			case SDL_SCANCODE_KP_PLUSMINUS: return Keys::KP_PLUSMINUS;
			case SDL_SCANCODE_KP_CLEAR: return Keys::KP_CLEAR;
			case SDL_SCANCODE_KP_CLEARENTRY: return Keys::KP_CLEARENTRY;
			case SDL_SCANCODE_KP_BINARY: return Keys::KP_BINARY;
			case SDL_SCANCODE_KP_OCTAL: return Keys::KP_OCTAL;
			case SDL_SCANCODE_KP_DECIMAL: return Keys::KP_DECIMAL;
			case SDL_SCANCODE_KP_HEXADECIMAL: return Keys::KP_HEXADECIMAL;
			case SDL_SCANCODE_LCTRL: return Keys::LCTRL;
			case SDL_SCANCODE_LSHIFT: return Keys::LSHIFT;
			case SDL_SCANCODE_LALT: return Keys::LALT;
			case SDL_SCANCODE_LGUI: return Keys::LGUI;
			case SDL_SCANCODE_RCTRL: return Keys::RCTRL;
			case SDL_SCANCODE_RSHIFT: return Keys::RSHIFT;
			case SDL_SCANCODE_RALT: return Keys::RALT;
			case SDL_SCANCODE_RGUI: return Keys::RGUI;
			case SDL_SCANCODE_MODE: return Keys::MODE;
			case SDL_SCANCODE_AUDIONEXT: return Keys::AUDIONEXT;
			case SDL_SCANCODE_AUDIOPREV: return Keys::AUDIOPREV;
			case SDL_SCANCODE_AUDIOSTOP: return Keys::AUDIOSTOP;
			case SDL_SCANCODE_AUDIOPLAY: return Keys::AUDIOPLAY;
			case SDL_SCANCODE_AUDIOMUTE: return Keys::AUDIOMUTE;
			case SDL_SCANCODE_MEDIASELECT: return Keys::MEDIASELECT;
			case SDL_SCANCODE_WWW: return Keys::WWW;
			case SDL_SCANCODE_MAIL: return Keys::MAIL;
			case SDL_SCANCODE_CALCULATOR: return Keys::CALCULATOR;
			case SDL_SCANCODE_COMPUTER: return Keys::COMPUTER;
			case SDL_SCANCODE_AC_SEARCH: return Keys::AC_SEARCH;
			case SDL_SCANCODE_AC_HOME: return Keys::AC_HOME;
			case SDL_SCANCODE_AC_BACK: return Keys::AC_BACK;
			case SDL_SCANCODE_AC_FORWARD: return Keys::AC_FORWARD;
			case SDL_SCANCODE_AC_STOP: return Keys::AC_STOP;
			case SDL_SCANCODE_AC_REFRESH: return Keys::AC_REFRESH;
			case SDL_SCANCODE_AC_BOOKMARKS: return Keys::AC_BOOKMARKS;
			case SDL_SCANCODE_BRIGHTNESSDOWN: return Keys::BRIGHTNESSDOWN;
			case SDL_SCANCODE_BRIGHTNESSUP: return Keys::BRIGHTNESSUP;
			case SDL_SCANCODE_DISPLAYSWITCH: return Keys::DISPLAYSWITCH;
			case SDL_SCANCODE_KBDILLUMTOGGLE: return Keys::KBDILLUMTOGGLE;
			case SDL_SCANCODE_KBDILLUMDOWN: return Keys::KBDILLUMDOWN;
			case SDL_SCANCODE_KBDILLUMUP: return Keys::KBDILLUMUP;
			case SDL_SCANCODE_EJECT: return Keys::EJECT;
			case SDL_SCANCODE_SLEEP: return Keys::SLEEP;
			case SDL_SCANCODE_APP1: return Keys::APP2;
			case SDL_SCANCODE_APP2: return Keys::APP1;
			}
		}
	}
}
