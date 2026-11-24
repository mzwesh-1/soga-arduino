// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <siSwati.h>

lokungagucuki inombolo IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Imotha_yesitebhu imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

lite cala() {
    imotha.setha_lijubane(10);          // imijikelezo eyi-10 ngomzuzu
    Siriyali.kucala(9600);
}

lite phindza_phindza() {
    Siriyali.khombisa_umugca("Ngokwewashi");
    imotha.tsatsa_tinyatselo(IZINYATHELO_ZOMJIKELEZO);
    lindza(500);
    Siriyali.khombisa_umugca("Ngokuphambene newashi");
    imotha.tsatsa_tinyatselo(-IZINYATHELO_ZOMJIKELEZO);
    lindza(500);
}
