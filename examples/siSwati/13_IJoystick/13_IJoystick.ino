// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <siSwati.h>

lokungagucuki inombolo INKINOBHO = 2;

lite cala() {
    setha_liphini(INKINOBHO, LOKUNGENAKO_KUDONSIWE);
    Siriyali.kucala(9600);
}

lite phindza_phindza() {
    inombolo x = fundza_ianalogi(A0);
    inombolo y = fundza_ianalogi(A1);
    ibhuli kucindezelwe = fundza_idijithali(INKINOBHO) == PHANSI;

    Siriyali.khombisa("X: "); Siriyali.khombisa(x);
    Siriyali.khombisa("  Y: "); Siriyali.khombisa(y);
    nangabe (x < 300) Siriyali.khombisa("  <- kwesobunxele");
    nangabe (x > 700) Siriyali.khombisa("  -> kwesokudla");
    nangabe (y < 300) Siriyali.khombisa("  ^ phezulu");
    nangabe (y > 700) Siriyali.khombisa("  v phansi");
    nangabe (kucindezelwe) Siriyali.khombisa("  [kucindezelwe]");
    Siriyali.khombisa_umugca();
    lindza(200);
}
