#include "input.h"
#include "print.h"
#include "sleep.h"
#include "string.h"
char empty[256];

#define DFT(value)

static inline uint8_t _inb(uint16_t port) {
	uint8_t ret;
	asm volatile ( "inb %1, %0"
					: "=a"(ret)
					: "Nd"(port) );
	return ret;
}

char* input_character(void) {
	while (1) {
	switch(_inb(0x60)) {
		case 0x0b: //sayılar
			print_str("0");
 			return "0";
		case 0x02:
			print_str("1");
 			return "1";
		case 0x03:
			print_str("2");
 			return "2";
		case 0x04:
			print_str("3");
 			return "3";
		case 0x05:
			print_str("4");
 			return "4";
		case 0x06:
			print_str("5");
 			return "5";
		case 0x07:
			print_str("6");
 			return "6";
		case 0x08:
			print_str("7");
 			return "7";
		case 0x09:
			print_str("8");
 			return "8";
		case 0x0a:
			print_str("9");
 			return "9";
		case 0x10: //harfler
			print_str("q");
 			return "q";
		case 0x11:
			print_str("w");
 			return "w";
		case 0x12:
			print_str("e");
 			return "e";
		case 0x13:
			print_str("r");
 			return "r";
		case 0x14:
			print_str("t");
 			return "t";
		case 0x15:
			print_str("y");
 			return "y";
		case 0x16:
			print_str("u");
 			return "u";
		case 0x18:
			print_str("o");
 			return "o";
		case 0x19:
			print_str("p");
 			return "p";
		case 0x1e:
			print_str("a");
 			return "a";
		case 0x1f:
			print_str("s");
 			return "s";
		case 0x20:
			print_str("d");
 			return "d";
		case 0x21:
			print_str("f");
 			return "f";
		case 0x22:
			print_str("g");
 			return "g";
		case 0x23:
			print_str("h");
 			return "h";
		case 0x24:
			print_str("j");
 			return "j";
		case 0x25:
			print_str("k");
 			return "k";
		case 0x26:
			print_str("l");
 			return "l";
		case 0x17:
			print_str("i");
 			return "i";
		case 0x2c:
			print_str("z");
 			return "z";
		case 0x2d:
			print_str("x");
 			return "x";
		case 0x2e:
			print_str("c");
 			return "c";
		case 0x2f:
			print_str("v");
 			return "v";
		case 0x30:
			print_str("b");
 			return "b";
		case 0x31:
			print_str("n");
 			return "n";
		case 0x32:
			print_str("m");
 			return "m";
		case 0x0C: //özel karakterler
			print_str("-");
 			return "-";
		case 0x0D:
			print_str("=");
 			return "=";
		case 0x1A:
			print_str("[");
 			return "[";
		case 0x1B:
			print_str("]");
			return "]";
		case 0x27:
			print_str(";");
 			return ";";
		case 0x33:
			print_str(",");
 			return ",";
		case 0x34:
			print_str(".");
 			return ".";
		case 0x35:
			print_str("/");
 			return "/";
		case 0x28:
			print_str("'");
 			return "'";
		case 0x29:
			print_str("`");
 			return "`";
		case 0x4c:
			print_str("5");
 			return "5";
		case 0x37:
			print_str("*");
 			return "*";
		case 0x4a:
			print_str("-");
 			return "-";
		case 0x4e:
			print_str("+");
 			return "+";
		case 0x0f:
			print_str("	");
 			return "	";
		case 0x39:
			print_str(" ");
 			return " ";
		case 0x1C: //enter
			print_str("\n");
 			return "0x1C"; 
		case 0x0E: //backspace
			print_str("");
 			return "0x0E"; 
		default: // If nothing matches with the cases
			continue;
		}
	}
}

char* input(char* output DFT('')) {
	static int line = 0;
	static char result[256];
	static char backup[256];
	static char* alinan;
	memset(result,0,256);
	memset(backup,0,256);
	print_str(output);
	while (1) {
		alinan = input_character();
		sleep(0x02000000);

		if (alinan == "0x1C") { //enter
			line = 0;
			alinan = NULL;
			return result;
		}
		
		if (alinan == "0x0E") { //backspace
			if (!memcmp(result,empty,256) == 0) {
				result[strlen(result)] = '\0';
				memcpy(backup, result, strlen(result)-1);
				memset(result,0,256);
				memcpy(result, backup, strlen(backup));
				memset(backup,0,256);
				line--;
				clear(strlen(backup)-1,strlen(backup));
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
