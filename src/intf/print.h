#pragma once

#include <stdint.h>
#include <stddef.h>
enum {
    renk_siyah = 0,
    renk_mavi = 1,
    renk_yesil = 2,
    renk_aqua = 3,
    renk_kirmizi = 4,
    renk_pembenot = 5,
    renk_kahverengi = 6,
    renk_acik_gri = 7,
    renk_kara_gri = 8,
    renk_acik_mavi = 9,
    renk_acik_yesil = 10,
    renk_acik_aqua = 11,
    renk_acik_kirmizi = 12,
    renk_pembe = 13,
    renk_sari = 14,
    renk_beyaz = 15,
};

void print_clear();
void print_char(char character); //CHARA İMPOSTER ; amogustale
void print_str(char* string);
void print_set_color(uint8_t yazi, uint8_t arka);
void clear(int chars);