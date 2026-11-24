// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <Afrikaans.h>

konstant heelgetal IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Stapmotor imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

leeg opstel() {
    imotha.stel_spoed(10);          // imijikelezo eyi-10 ngomzuzu
    Seriaal.begin(9600);
}

leeg lus() {
    Seriaal.drukreel("Ngokwewashi");
    imotha.neem_stappe(IZINYATHELO_ZOMJIKELEZO);
    wag(500);
    Seriaal.drukreel("Ngokuphambene newashi");
    imotha.neem_stappe(-IZINYATHELO_ZOMJIKELEZO);
    wag(500);
}
