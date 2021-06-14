#include "print.h"
// bişey yaz artık efjıoı3; yO
const static size_t num_cols = 80;
const static size_t num_rows = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = renk_beyaz | renk_siyah <<4; 

void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < num_cols; col++) {
       buffer[col + num_cols * row] = empty;
    }
}

void print_clear() {
    for (int i = 0; i < num_rows; i++) {
       clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < num_rows - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < num_rows; row++) {
        for (size_t col = 0; col < num_cols; col++) {
            struct Char character = buffer[col + num_cols * row];
            buffer[col + num_cols * (row - 1)] = character;
        }
    }

    clear_row(num_cols - 1);
}

void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }
    if (col > num_cols) {
        //TODO: eğer hata çıkarırsa bir şey bunu kapa alex  
        print_newline();
    }

    buffer[col + num_cols * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

/*bi an daldım lan fsdıgojsd; */
void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }
        //1 dk gelcem fontları değişip; ok; yaptım yay >=> (dm den atıcam görüntüyü)
        print_char(character);
    }

}

void print_set_color(uint8_t yazi, uint8_t arka) {
    color = yazi + (arka << 4);
     
}