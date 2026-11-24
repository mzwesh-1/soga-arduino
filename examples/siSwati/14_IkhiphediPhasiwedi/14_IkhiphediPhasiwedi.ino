// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <siSwati.h>

lokungagucuki libhayithi IMIGQA = 4;
lokungagucuki libhayithi AMAKHOLOMU = 4;
luhlavu izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
libhayithi amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
libhayithi amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Likhiphedi ikhiphedi(yenta_imephu_yetinkinobho(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

lokungagucuki inombolo OKULUHLAZA = 22;
lokungagucuki inombolo OKUBOMVU = 23;
umbhalo iphasiwedi = "1234";
umbhalo okufakiwe = "";

lite cala() {
    Siriyali.kucala(9600);
    setha_liphini(OKULUHLAZA, LOKUPHUMAKO);
    setha_liphini(OKUBOMVU, LOKUPHUMAKO);
    Siriyali.khombisa_umugca("Faka iphasiwedi bese ucindezela #");
}

lite phindza_phindza() {
    luhlavu inkinobho = ikhiphedi.tfola_inkinobho();
    nangabe (inkinobho == AKUKHO_NKINOBHO) buyisa;
    nangabe (inkinobho == '*') {
        okufakiwe = "";
        Siriyali.khombisa_umugca("Kusuliwe");
    } ngalokunye nangabe (inkinobho == '#') {
        nangabe (okufakiwe == iphasiwedi) {
            Siriyali.khombisa_umugca("Iphasiwedi ilungile. Ngena!");
            bhala_idijithali(OKULUHLAZA, PHETULU);
        } ngalokunye {
            Siriyali.khombisa_umugca("Iphasiwedi ayilungile!");
            bhala_idijithali(OKUBOMVU, PHETULU);
        }
        lindza(2000);
        bhala_idijithali(OKULUHLAZA, PHANSI);
        bhala_idijithali(OKUBOMVU, PHANSI);
        okufakiwe = "";
    } ngalokunye {
        okufakiwe += inkinobho;
        Siriyali.khombisa('*');
    }
}
