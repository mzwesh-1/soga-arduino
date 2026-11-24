// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <Tshivenda.h>

zwi_sa_shanduki nomboro INKINOBHO = 2;

a_huna thoma() {
    vhea_phini(INKINOBHO, ZWI_DZHENAHO_NGA_U_KOKA);
    Siriale.mathomo(9600);
}

a_huna dovholola() {
    nomboro x = vhala_analogo(A0);
    nomboro y = vhala_analogo(A1);
    buliani kucindezelwe = vhala_didzhithala(INKINOBHO) == FHASI;

    Siriale.sumbedza("X: "); Siriale.sumbedza(x);
    Siriale.sumbedza("  Y: "); Siriale.sumbedza(y);
    arali (x < 300) Siriale.sumbedza("  <- kwesobunxele");
    arali (x > 700) Siriale.sumbedza("  -> kwesokudla");
    arali (y < 300) Siriale.sumbedza("  ^ phezulu");
    arali (y > 700) Siriale.sumbedza("  v phansi");
    arali (kucindezelwe) Siriale.sumbedza("  [kucindezelwe]");
    Siriale.sumbedza_mutalo();
    lindela(200);
}
