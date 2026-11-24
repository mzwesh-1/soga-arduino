// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <isiZulu.h>

engaguquki inombolo INKINOBHO = 2;

ize qala() {
    setha_iphini(INKINOBHO, OKUNGENAYO_KUDONSELWE);
    Isiriyeli.ukuqala(9600);
}

ize phindaphinda() {
    inombolo x = funda_ianalogi(A0);
    inombolo y = funda_ianalogi(A1);
    ibhuli kucindezelwe = funda_idijithali(INKINOBHO) == PHANSI;

    Isiriyeli.bonisa("X: "); Isiriyeli.bonisa(x);
    Isiriyeli.bonisa("  Y: "); Isiriyeli.bonisa(y);
    uma (x < 300) Isiriyeli.bonisa("  <- kwesobunxele");
    uma (x > 700) Isiriyeli.bonisa("  -> kwesokudla");
    uma (y < 300) Isiriyeli.bonisa("  ^ phezulu");
    uma (y > 700) Isiriyeli.bonisa("  v phansi");
    uma (kucindezelwe) Isiriyeli.bonisa("  [kucindezelwe]");
    Isiriyeli.bonisa_umugqa();
    linda(200);
}
