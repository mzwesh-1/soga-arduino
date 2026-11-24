// I-joystick: ifunda u-X, u-Y nenkinobho.
// Ukuxhuma: VRx -> A0, VRy -> A1, SW -> 2, +5V -> 5V, GND -> GND
#include <Afrikaans.h>

konstant heelgetal INKINOBHO = 2;

leeg opstel() {
    penmodus(INKINOBHO, INSET_OPTREK);
    Seriaal.begin(9600);
}

leeg lus() {
    heelgetal x = leesanaloog(A0);
    heelgetal y = leesanaloog(A1);
    boolees kucindezelwe = leesdigitaal(INKINOBHO) == LAAG;

    Seriaal.druk("X: "); Seriaal.druk(x);
    Seriaal.druk("  Y: "); Seriaal.druk(y);
    as (x < 300) Seriaal.druk("  <- kwesobunxele");
    as (x > 700) Seriaal.druk("  -> kwesokudla");
    as (y < 300) Seriaal.druk("  ^ phezulu");
    as (y > 700) Seriaal.druk("  v phansi");
    as (kucindezelwe) Seriaal.druk("  [kucindezelwe]");
    Seriaal.drukreel();
    wag(200);
}
