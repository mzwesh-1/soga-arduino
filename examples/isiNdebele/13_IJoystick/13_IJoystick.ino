// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <isiNdebele.h>

okungatjhugulukiko inomboro INKINOBHO = 2;

ilize thoma() {
    beka_iphini(INKINOBHO, OKUNGENAKO_KUDONSIWE);
    Isiriyali.ukuthoma(9600);
}

ilize phinda_phinda() {
    inomboro x = funda_ianalogi(A0);
    inomboro y = funda_ianalogi(A1);
    ibhuli kucindezelwe = funda_idijithali(INKINOBHO) == PHASI;

    Isiriyali.khombisa("X: "); Isiriyali.khombisa(x);
    Isiriyali.khombisa("  Y: "); Isiriyali.khombisa(y);
    nangabe (x < 300) Isiriyali.khombisa("  <- kwesobunxele");
    nangabe (x > 700) Isiriyali.khombisa("  -> kwesokudla");
    nangabe (y < 300) Isiriyali.khombisa("  ^ phezulu");
    nangabe (y > 700) Isiriyali.khombisa("  v phansi");
    nangabe (kucindezelwe) Isiriyali.khombisa("  [kucindezelwe]");
    Isiriyali.khombisa_umugqa();
    lindela(200);
}
