// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <isiNdebele.h>

okungatjhugulukiko inomboro IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Imoto_yesitebhu imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

ilize thoma() {
    imotha.setha_ibelo(10);          // imijikelezo eyi-10 ngomzuzu
    Isiriyali.ukuthoma(9600);
}

ilize phinda_phinda() {
    Isiriyali.khombisa_umugqa("Ngokwewashi");
    imotha.thatha_amagadango(IZINYATHELO_ZOMJIKELEZO);
    lindela(500);
    Isiriyali.khombisa_umugqa("Ngokuphambene newashi");
    imotha.thatha_amagadango(-IZINYATHELO_ZOMJIKELEZO);
    lindela(500);
}
