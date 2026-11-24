// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <isiXhosa.h>

engatshintshiyo inani IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Imoto_yenyathelo imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

ize qalisa() {
    imotha.misela_isantya(10);          // imijikelezo eyi-10 ngomzuzu
    Isiriyali.ukuqala(9600);
}

ize phinda_phinda() {
    Isiriyali.bonisa_umgca("Ngokwewashi");
    imotha.thatha_amanyathelo(IZINYATHELO_ZOMJIKELEZO);
    linda(500);
    Isiriyali.bonisa_umgca("Ngokuphambene newashi");
    imotha.thatha_amanyathelo(-IZINYATHELO_ZOMJIKELEZO);
    linda(500);
}
