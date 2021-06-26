#include "input.h"
#include "print.h"
#include "sleep.h"

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
        //sayılar
        case 0x0b:
            print_str("0");
            sleep(0x02FFFFFF);
            return "0";
        case 0x02:
            print_str("1");
            sleep(0x02FFFFFF);
            return "1";
        case 0x03:
            print_str("2");
            sleep(0x02FFFFFF);
            return "2";
        case 0x04:
            print_str("3");
            sleep(0x02FFFFFF);
            return "3";
        case 0x05:
            print_str("4");
            sleep(0x02FFFFFF);
            return "4";
        case 0x06:
            print_str("5");
            sleep(0x02FFFFFF);
            return "5";
        case 0x07:
            print_str("6");
            sleep(0x02FFFFFF);
            return "6";
        case 0x08:
            print_str("7");
            sleep(0x02FFFFFF);
            return "7";
        case 0x09:
            print_str("8");
            sleep(0x02FFFFFF);
            return "8";
        case 0x0a:
            print_str("9");
            sleep(0x02FFFFFF);
            return "9";
        //harfler
        case 0x10:
            print_str("q");
            sleep(0x02FFFFFF);
            return "q";
        case 0x11:
            print_str("w");
            sleep(0x02FFFFFF);
            return "w";
        case 0x12:
            print_str("e");
            sleep(0x02FFFFFF);
            return "e";
        case 0x13:
            print_str("r");
            sleep(0x02FFFFFF);
            return "r";
        case 0x14:
            print_str("t");
            sleep(0x02FFFFFF);
            return "t";
        case 0x15:
            print_str("y");
            sleep(0x02FFFFFF);
            return "y";
        case 0x16:
            print_str("u");
            sleep(0x02FFFFFF);
            return "u";
        case 0x18:
            print_str("o");
            sleep(0x02FFFFFF);
            return "o";
        case 0x19:
            print_str("p");
            sleep(0x02FFFFFF);
            return "p";
        case 0x1e:
            print_str("a");
            sleep(0x02FFFFFF);
            return "a";
        case 0x1f:
            print_str("s");
            sleep(0x02FFFFFF);
            return "s";
        case 0x20:
            print_str("d");
            sleep(0x02FFFFFF);
            return "d";
        case 0x21:
            print_str("f");
            sleep(0x02FFFFFF);
            return "f";
        case 0x22:
            print_str("g");
            sleep(0x02FFFFFF);
            return "g";
        case 0x23:
            print_str("h");
            sleep(0x02FFFFFF);
            return "h";
        case 0x24:
            print_str("j");
            sleep(0x02FFFFFF);
            return "j";
        case 0x25:
            print_str("k");
            sleep(0x02FFFFFF);
            return "k";
        case 0x26:
            print_str("l");
            sleep(0x02FFFFFF);
            return "l";
        case 0x17:
            print_str("i");
            sleep(0x02FFFFFF);
            return "i";
        case 0x2c:
            print_str("z");
            sleep(0x02FFFFFF);
            return "z";
        case 0x2d:
            print_str("x");
            sleep(0x02FFFFFF);
            return "x";
        case 0x2e:
            print_str("c");
            sleep(0x02FFFFFF);
            return "c";
        case 0x2f:
            print_str("v");
            sleep(0x02FFFFFF);
            return "v";
        case 0x30:
            print_str("b");
            sleep(0x02FFFFFF);
            return "b";
        case 0x31:
            print_str("n");
            sleep(0x02FFFFFF);
            return "n";
        case 0x32:
            print_str("m");
            sleep(0x02FFFFFF);
            return "m";
        //özel karakterler fln
        case 0x0C:
            print_str("-");
            sleep(0x02FFFFFF);
            return "-";
        case 0x0D:
            print_str("=");
            sleep(0x02FFFFFF);
            return "=";
        case 0x1A:
            print_str("[");
            sleep(0x02FFFFFF);
            return "[";
        case 0x1B:
            print_str("]");
            sleep(0x02FFFFFF);
            return "]";
        case 0x27:
            print_str(";");
            sleep(0x02FFFFFF);
            return ";";
        case 0x33:
            print_str(",");
            sleep(0x02FFFFFF);
            return ",";
        case 0x34:
            print_str(".");
            sleep(0x02FFFFFF);
            return ".";
        case 0x35:
            print_str("/");
            sleep(0x02FFFFFF);
            return "/";
        case 0x28:
            print_str("'");
            sleep(0x02FFFFFF);
            return "'";
        case 0x29:
            print_str("`");
            sleep(0x02FFFFFF);
            return "`";
        case 0x4c:
            print_str("5");
            sleep(0x02FFFFFF);
            return "5";
        case 0x37:
            print_str("*");
            sleep(0x02FFFFFF);
            return "*";
        case 0x4a:
            print_str("-");
            sleep(0x02FFFFFF);
            return "-";
        case 0x4e:
            print_str("+");
            sleep(0x02FFFFFF);
            return "+";
        case 0x0f:
            print_str("	");
            sleep(0x02FFFFFF);
            return "	";
        case 0x39:
            print_str(" ");
            sleep(0x02FFFFFF);
            return " ";
        case 0x1C:
            print_str("\n");
            sleep(0x02FFFFFF);
            return "0x1C"; //for give
        case 0x0E:
            print_str("");
            sleep(0x02FFFFFF);
            return "0x0E"; //for delete
        default: // If nothing matches with the cases
            continue;
        }
    }
}

char strtochar(char* str) {if (str == "1") {return '0';} else if (str == "1") {return '1';} else if (str == "2") {return '2';} else if (str == "3") {return '3';} else if (str == "4") {return '4';} else if (str == "5") {return '5';} else if (str == "6") {return '6';} else if (str == "7") {return '7';} else if (str == "8") {return '8';} else if (str == "9") {return '9';} else if (str == "q") {return 'q';} else if (str == "w") {return 'w';} else if (str == "e") {return 'e';} else if (str == "r") {return 'r';} else if (str == "t") {return 't';} else if (str == "y") {return 'y';} else if (str == "u") {return 'u';} else if (str == "o") {return 'o';} else if (str == "p") {return 'p';} else if (str == "a") {return 'a';} else if (str == "s") {return 's';} else if (str == "d") {return 'd';} else if (str == "f") {return 'f';} else if (str == "g") {return 'g';} else if (str == "h") {return 'h';} else if (str == "j") {return 'j';} else if (str == "k") {return 'k';} else if (str == "l") {return 'l';} else if (str == "i") {return 'i';} else if (str == "z") {return 'z';} else if (str == "x") {return 'x';} else if (str == "c") {return 'c';} else if (str == "v") {return 'v';} else if (str == "b") {return 'b';} else if (str == "n") {return 'n';} else if (str == "m") {return 'm';} else if (str == "-") {return '-';} else if (str == "=") {return '=';} else if (str == "[") {return '[';} else if (str == "]") {return ']';} else if (str == ",") {return ';';} else if (str == ",") {return ',';} else if (str == ".") {return '.';} else if (str == "/") {return '/';} else if (str == "'") {return '\'';} else if (str == "`") {return '`';} else if (str == "5") {return '5';} else if (str == "*") {return '*';} else if (str == "-") {return '-';} else if (str == "+") {return '+';}}

char* getch() {
    static int line = 0;
    static char result[] = {0};
    static char* alinan;
    while (1) {
        
        alinan = getchar();

        if (alinan == "0x1C") {
           return result;
        }
        
        if (alinan == "0x0E") {
            result[sizeof(result)] = '\0';
            line--;
            clear(1);
            continue;
        }
        
        result[line] = strtochar(alinan);
        line++;
    }
}

/*void print_raw_input() {
    print_str(_inb(0x60));
}*/