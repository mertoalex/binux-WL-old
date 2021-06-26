#include "print.h"
#include "input.h"
#include "sleep.h"

void kernel_main() { // prinf bruh
    char* GSOD = "Your Computer has been got crashed while trying to make a Action."; // gri ekran ölümü; yo o green ekran ölümü ; ok
    print_clear();
    print_set_color(renk_beyaz, renk_siyah);
    print_str("Welcome To ");
    print_set_color(renk_sari, renk_yesil);
    print_str("B");
    print_set_color(renk_acik_yesil, renk_yesil);
    print_str("INUX");
    print_set_color(renk_beyaz, renk_siyah);
    print_str("!\n");
    /*print_set_color(renk_acik_yesil, renk_kirmizi);
    print_str("YEA BOIIIIIIIIIIIII");*/
    /*if (getch() == "echo") {
        print_str("Hello, World! Yea Boiiiiiiiiii");
    } else {
        return;
    }*/
    while (1) {
    print_str(">");
    print_str(getch());
    print_str("\n");
    }
}