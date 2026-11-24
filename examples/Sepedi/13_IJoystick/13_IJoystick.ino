// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <Sepedi.h>

sa_fetogego palo INKINOBHO = 2;

lefeela thoma() {
    bea_phini(INKINOBHO, TSE_TSENAGO_GO_GOGA);
    Seriale.mathomo(9600);
}

lefeela boeletsa() {
    palo x = bala_analoko(A0);
    palo y = bala_analoko(A1);
    bulini kucindezelwe = bala_dijithale(INKINOBHO) == FASE;

    Seriale.bontsha("X: "); Seriale.bontsha(x);
    Seriale.bontsha("  Y: "); Seriale.bontsha(y);
    ge (x < 300) Seriale.bontsha("  <- kwesobunxele");
    ge (x > 700) Seriale.bontsha("  -> kwesokudla");
    ge (y < 300) Seriale.bontsha("  ^ phezulu");
    ge (y > 700) Seriale.bontsha("  v phansi");
    ge (kucindezelwe) Seriale.bontsha("  [kucindezelwe]");
    Seriale.bontsha_mothaladi();
    leta(200);
}
