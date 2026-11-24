// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <isiZulu.h>

engaguquki inombolo ITILT = 2;
engaguquki inombolo ILED = 13;

ize qala() {
    setha_iphini(ITILT, OKUNGENAYO_KUDONSELWE);
    setha_iphini(ILED, OKUPHUMAYO);
    Isiriyeli.ukuqala(9600);
}

ize phindaphinda() {
    uma (funda_idijithali(ITILT) == PHANSI) {
        bhala_idijithali(ILED, PHANSI);
    } kungenjalo {
        bhala_idijithali(ILED, PHEZULU);
        Isiriyeli.bonisa_umugqa("Kutshekile!");
    }
    linda(100);
}
