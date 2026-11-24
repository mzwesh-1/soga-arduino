// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <Sesotho.h>

e_sa_fetoheng palo INKINOBHO = 2;

lefeela qala() {
    beha_phini(INKINOBHO, TSE_KENANG_HO_HULA);
    Seriale.qalo(9600);
}

lefeela pheta_pheta() {
    palo x = bala_analoko(A0);
    palo y = bala_analoko(A1);
    bulini kucindezelwe = bala_dijithale(INKINOBHO) == TLASE;

    Seriale.bontsha("X: "); Seriale.bontsha(x);
    Seriale.bontsha("  Y: "); Seriale.bontsha(y);
    haeba (x < 300) Seriale.bontsha("  <- kwesobunxele");
    haeba (x > 700) Seriale.bontsha("  -> kwesokudla");
    haeba (y < 300) Seriale.bontsha("  ^ phezulu");
    haeba (y > 700) Seriale.bontsha("  v phansi");
    haeba (kucindezelwe) Seriale.bontsha("  [kucindezelwe]");
    Seriale.bontsha_mola();
    ema(200);
}
