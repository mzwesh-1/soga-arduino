// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <Setswana.h>

e_sa_fetogeng palo INKINOBHO = 2;

lefela simolola() {
    baya_phini(INKINOBHO, TSE_DI_TSENANG_GO_GOGA);
    Seriale.tshimologo(9600);
}

lefela boeletsa() {
    palo x = bala_analoko(A0);
    palo y = bala_analoko(A1);
    bulini kucindezelwe = bala_dijithale(INKINOBHO) == TLASE;

    Seriale.bontsha("X: "); Seriale.bontsha(x);
    Seriale.bontsha("  Y: "); Seriale.bontsha(y);
    fa (x < 300) Seriale.bontsha("  <- kwesobunxele");
    fa (x > 700) Seriale.bontsha("  -> kwesokudla");
    fa (y < 300) Seriale.bontsha("  ^ phezulu");
    fa (y > 700) Seriale.bontsha("  v phansi");
    fa (kucindezelwe) Seriale.bontsha("  [kucindezelwe]");
    Seriale.bontsha_mola();
    ema(200);
}
