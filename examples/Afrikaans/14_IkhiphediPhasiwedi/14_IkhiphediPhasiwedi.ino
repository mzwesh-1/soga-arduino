// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <Afrikaans.h>

konstant greep IMIGQA = 4;
konstant greep AMAKHOLOMU = 4;
karakter izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
greep amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
greep amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Sleutelbord ikhiphedi(maak_sleutelkaart(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

konstant heelgetal OKULUHLAZA = 22;
konstant heelgetal OKUBOMVU = 23;
teks iphasiwedi = "1234";
teks okufakiwe = "";

leeg opstel() {
    Seriaal.begin(9600);
    penmodus(OKULUHLAZA, UITSET);
    penmodus(OKUBOMVU, UITSET);
    Seriaal.drukreel("Faka iphasiwedi bese ucindezela #");
}

leeg lus() {
    karakter inkinobho = ikhiphedi.kry_sleutel();
    as (inkinobho == GEEN_SLEUTEL) terug;
    as (inkinobho == '*') {
        okufakiwe = "";
        Seriaal.drukreel("Kusuliwe");
    } anders as (inkinobho == '#') {
        as (okufakiwe == iphasiwedi) {
            Seriaal.drukreel("Iphasiwedi ilungile. Ngena!");
            skryfdigitaal(OKULUHLAZA, HOOG);
        } anders {
            Seriaal.drukreel("Iphasiwedi ayilungile!");
            skryfdigitaal(OKUBOMVU, HOOG);
        }
        wag(2000);
        skryfdigitaal(OKULUHLAZA, LAAG);
        skryfdigitaal(OKUBOMVU, LAAG);
        okufakiwe = "";
    } anders {
        okufakiwe += inkinobho;
        Seriaal.druk('*');
    }
}
