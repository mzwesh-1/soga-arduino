// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <Xitsonga.h>

lexi_nga_cinciki nomboro INKINOBHO = 2;

swi_hava sungula() {
    veka_phini(INKINOBHO, LESWI_NGHENAKA_HI_KU_KOKA);
    Siriyali.ku_sungula(9600);
}

swi_hava phindha_phindha() {
    nomboro x = hlaya_analogo(A0);
    nomboro y = hlaya_analogo(A1);
    buliyani kucindezelwe = hlaya_dijitali(INKINOBHO) == HANSI;

    Siriyali.kombisa("X: "); Siriyali.kombisa(x);
    Siriyali.kombisa("  Y: "); Siriyali.kombisa(y);
    loko (x < 300) Siriyali.kombisa("  <- kwesobunxele");
    loko (x > 700) Siriyali.kombisa("  -> kwesokudla");
    loko (y < 300) Siriyali.kombisa("  ^ phezulu");
    loko (y > 700) Siriyali.kombisa("  v phansi");
    loko (kucindezelwe) Siriyali.kombisa("  [kucindezelwe]");
    Siriyali.kombisa_layini();
    rindza(200);
}
