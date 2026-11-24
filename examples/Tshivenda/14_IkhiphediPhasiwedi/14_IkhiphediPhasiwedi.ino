// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <Tshivenda.h>

zwi_sa_shanduki baithi IMIGQA = 4;
zwi_sa_shanduki baithi AMAKHOLOMU = 4;
ledere izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
baithi amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
baithi amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Khiphedi ikhiphedi(ita_mepe_wa_dzibathani(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

zwi_sa_shanduki nomboro OKULUHLAZA = 22;
zwi_sa_shanduki nomboro OKUBOMVU = 23;
manwalwa iphasiwedi = "1234";
manwalwa okufakiwe = "";

a_huna thoma() {
    Siriale.mathomo(9600);
    vhea_phini(OKULUHLAZA, ZWI_BVAHO);
    vhea_phini(OKUBOMVU, ZWI_BVAHO);
    Siriale.sumbedza_mutalo("Faka iphasiwedi bese ucindezela #");
}

a_huna dovholola() {
    ledere inkinobho = ikhiphedi.wana_bathani();
    arali (inkinobho == A_HU_NA_BATHANI) vhuisa;
    arali (inkinobho == '*') {
        okufakiwe = "";
        Siriale.sumbedza_mutalo("Kusuliwe");
    } nga_inwe_ndila arali (inkinobho == '#') {
        arali (okufakiwe == iphasiwedi) {
            Siriale.sumbedza_mutalo("Iphasiwedi ilungile. Ngena!");
            nwala_didzhithala(OKULUHLAZA, NTHA);
        } nga_inwe_ndila {
            Siriale.sumbedza_mutalo("Iphasiwedi ayilungile!");
            nwala_didzhithala(OKUBOMVU, NTHA);
        }
        lindela(2000);
        nwala_didzhithala(OKULUHLAZA, FHASI);
        nwala_didzhithala(OKUBOMVU, FHASI);
        okufakiwe = "";
    } nga_inwe_ndila {
        okufakiwe += inkinobho;
        Siriale.sumbedza('*');
    }
}
