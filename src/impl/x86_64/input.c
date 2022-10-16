#include "input.h"
#include "print.h"
#include "sleep.h"
#include "string.h"

static inline uint8_t _inb(uint16_t port) {
	uint8_t ret;
	asm volatile ( "inb %1, %0"
					: "=a"(ret)
					: "Nd"(port) );
	return ret;
}

char* getchar(void) {
	while (1) {
	switch(_inb(0x60)) {
		case 0x0b: //sayılar
			print_str("0");
			sleep(0x02000000);
			return "0";
		case 0x02:
			print_str("1");
			sleep(0x02000000);
			return "1";
		case 0x03:
			print_str("2");
			sleep(0x02000000);
			return "2";
		case 0x04:
			print_str("3");
			sleep(0x02000000);
			return "3";
		case 0x05:
			print_str("4");
			sleep(0x02000000);
			return "4";
		case 0x06:
			print_str("5");
			sleep(0x02000000);
			return "5";
		case 0x07:
			print_str("6");
			sleep(0x02000000);
			return "6";
		case 0x08:
			print_str("7");
			sleep(0x02000000);
			return "7";
		case 0x09:
			print_str("8");
			sleep(0x02000000);
			return "8";
		case 0x0a:
			print_str("9");
			sleep(0x02000000);
			return "9";
		case 0x10: //harfler
			print_str("q");
			sleep(0x02000000);
			return "q";
		case 0x11:
			print_str("w");
			sleep(0x02000000);
			return "w";
		case 0x12:
			print_str("e");
			sleep(0x02000000);
			return "e";
		case 0x13:
			print_str("r");
			sleep(0x02000000);
			return "r";
		case 0x14:
			print_str("t");
			sleep(0x02000000);
			return "t";
		case 0x15:
			print_str("y");
			sleep(0x02000000);
			return "y";
		case 0x16:
			print_str("u");
			sleep(0x02000000);
			return "u";
		case 0x18:
			print_str("o");
			sleep(0x02000000);
			return "o";
		case 0x19:
			print_str("p");
			sleep(0x02000000);
			return "p";
		case 0x1e:
			print_str("a");
			sleep(0x02000000);
			return "a";
		case 0x1f:
			print_str("s");
			sleep(0x02000000);
			return "s";
		case 0x20:
			print_str("d");
			sleep(0x02000000);
			return "d";
		case 0x21:
			print_str("f");
			sleep(0x02000000);
			return "f";
		case 0x22:
			print_str("g");
			sleep(0x02000000);
			return "g";
		case 0x23:
			print_str("h");
			sleep(0x02000000);
			return "h";
		case 0x24:
			print_str("j");
			sleep(0x02000000);
			return "j";
		case 0x25:
			print_str("k");
			sleep(0x02000000);
			return "k";
		case 0x26:
			print_str("l");
			sleep(0x02000000);
			return "l";
		case 0x17:
			print_str("i");
			sleep(0x02000000);
			return "i";
		case 0x2c:
			print_str("z");
			sleep(0x02000000);
			return "z";
		case 0x2d:
			print_str("x");
			sleep(0x02000000);
			return "x";
		case 0x2e:
			print_str("c");
			sleep(0x02000000);
			return "c";
		case 0x2f:
			print_str("v");
			sleep(0x02000000);
			return "v";
		case 0x30:
			print_str("b");
			sleep(0x02000000);
			return "b";
		case 0x31:
			print_str("n");
			sleep(0x02000000);
			return "n";
		case 0x32:
			print_str("m");
			sleep(0x02000000);
			return "m";
		case 0x0C: //özel karakterler
			print_str("-");
			sleep(0x02000000);
			return "-";
		case 0x0D:
			print_str("=");
			sleep(0x02000000);
			return "=";
		case 0x1A:
			print_str("[");
			sleep(0x02000000);
			return "[";
		case 0x1B:
			print_str("]");
			sleep(0x02000000);
			return "]";
		case 0x27:
			print_str(";");
			sleep(0x02000000);
			return ";";
		case 0x33:
			print_str(",");
			sleep(0x02000000);
			return ",";
		case 0x34:
			print_str(".");
			sleep(0x02000000);
			return ".";
		case 0x35:
			print_str("/");
			sleep(0x02000000);
			return "/";
		case 0x28:
			print_str("'");
			sleep(0x02000000);
			return "'";
		case 0x29:
			print_str("`");
			sleep(0x02000000);
			return "`";
		case 0x4c:
			print_str("5");
			sleep(0x02000000);
			return "5";
		case 0x37:
			print_str("*");
			sleep(0x02000000);
			return "*";
		case 0x4a:
			print_str("-");
			sleep(0x02000000);
			return "-";
		case 0x4e:
			print_str("+");
			sleep(0x02000000);
			return "+";
		case 0x0f:
			print_str("	");
			sleep(0x02000000);
			return "	";
		case 0x39:
			print_str(" ");
			sleep(0x02000000);
			return " ";
		case 0x1C: //enter
			print_str("\n");
			sleep(0x02000000);
			return "0x1C"; 
		case 0x0E: //backspace
			print_str("");
			sleep(0x02000000);
			return "0x0E"; 
		default: // If nothing matches with the cases
			continue;
		}
	}
}

char* getch() {
	static int line = 0;
	static char result[256];
	static char* alinan;
	memset(result,0,256);
	while (1) {
		
		alinan = getchar();

		if (alinan == "0x1C") {
			line = 0;
			alinan = NULL;
			return result;
		}
		
		if (alinan == "0x0E") {
			if (!strlen(result) <= (size_t) 0) {
				result[strlen(result)] = '\0';
				line--;
				clear(1);
			}
			continue;
		}
		
		result[line] = alinan[0];
		line++;
	}
}

/*void print_raw_input() {
	print_str(_inb(0x60));
}*/
