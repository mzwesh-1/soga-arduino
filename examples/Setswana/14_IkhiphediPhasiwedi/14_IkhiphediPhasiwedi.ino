// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <Setswana.h>

e_sa_fetogeng baete IMIGQA = 4;
e_sa_fetogeng baete AMAKHOLOMU = 4;
tlhaka izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
baete amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
baete amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Khiphete ikhiphedi(dira_mmapa_wa_dikonopo(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

e_sa_fetogeng palo OKULUHLAZA = 22;
e_sa_fetogeng palo OKUBOMVU = 23;
mokwalo iphasiwedi = "1234";
mokwalo okufakiwe = "";

lefela simolola() {
    Seriale.tshimologo(9600);
    baya_phini(OKULUHLAZA, TSE_DI_TSWANG);
    baya_phini(OKUBOMVU, TSE_DI_TSWANG);
    Seriale.bontsha_mola("Faka iphasiwedi bese ucindezela #");
}

lefela boeletsa() {
    tlhaka inkinobho = ikhiphedi.bona_konopo();
    fa (inkinobho == GA_GO_KONOPO) busa;
    fa (inkinobho == '*') {
        okufakiwe = "";
        Seriale.bontsha_mola("Kusuliwe");
    } go_seng_jalo fa (inkinobho == '#') {
        fa (okufakiwe == iphasiwedi) {
            Seriale.bontsha_mola("Iphasiwedi ilungile. Ngena!");
            kwala_dijithale(OKULUHLAZA, GODIMO);
        } go_seng_jalo {
            Seriale.bontsha_mola("Iphasiwedi ayilungile!");
            kwala_dijithale(OKUBOMVU, GODIMO);
        }
        ema(2000);
        kwala_dijithale(OKULUHLAZA, TLASE);
        kwala_dijithale(OKUBOMVU, TLASE);
        okufakiwe = "";
    } go_seng_jalo {
        okufakiwe += inkinobho;
        Seriale.bontsha('*');
    }
}
