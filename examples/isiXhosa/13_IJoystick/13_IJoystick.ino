// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <isiXhosa.h>

engatshintshiyo inani INKINOBHO = 2;

ize qalisa() {
    misela_iphini(INKINOBHO, OKUNGENAYO_KUTSALWE);
    Isiriyali.ukuqala(9600);
}

ize phinda_phinda() {
    inani x = funda_ianalogu(A0);
    inani y = funda_ianalogu(A1);
    ibhuli kucindezelwe = funda_idijithali(INKINOBHO) == EZANTSI;

    Isiriyali.bonisa("X: "); Isiriyali.bonisa(x);
    Isiriyali.bonisa("  Y: "); Isiriyali.bonisa(y);
    ukuba (x < 300) Isiriyali.bonisa("  <- kwesobunxele");
    ukuba (x > 700) Isiriyali.bonisa("  -> kwesokudla");
    ukuba (y < 300) Isiriyali.bonisa("  ^ phezulu");
    ukuba (y > 700) Isiriyali.bonisa("  v phansi");
    ukuba (kucindezelwe) Isiriyali.bonisa("  [kucindezelwe]");
    Isiriyali.bonisa_umgca();
    linda(200);
}
