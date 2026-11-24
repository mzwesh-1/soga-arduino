// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <Sesotho.h>

e_sa_fetoheng baete IMIGQA = 4;
e_sa_fetoheng baete AMAKHOLOMU = 4;
tlhaku izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
baete amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
baete amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Khiphete ikhiphedi(etsa_mmapa_wa_dikonopo(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

e_sa_fetoheng palo OKULUHLAZA = 22;
e_sa_fetoheng palo OKUBOMVU = 23;
mongolo iphasiwedi = "1234";
mongolo okufakiwe = "";

lefeela qala() {
    Seriale.qalo(9600);
    beha_phini(OKULUHLAZA, TSE_TSWANG);
    beha_phini(OKUBOMVU, TSE_TSWANG);
    Seriale.bontsha_mola("Faka iphasiwedi bese ucindezela #");
}

lefeela pheta_pheta() {
    tlhaku inkinobho = ikhiphedi.fumana_konopo();
    haeba (inkinobho == HA_HO_KONOPO) kgutlisa;
    haeba (inkinobho == '*') {
        okufakiwe = "";
        Seriale.bontsha_mola("Kusuliwe");
    } ho_seng_jwalo haeba (inkinobho == '#') {
        haeba (okufakiwe == iphasiwedi) {
            Seriale.bontsha_mola("Iphasiwedi ilungile. Ngena!");
            ngola_dijithale(OKULUHLAZA, HODIMO);
        } ho_seng_jwalo {
            Seriale.bontsha_mola("Iphasiwedi ayilungile!");
            ngola_dijithale(OKUBOMVU, HODIMO);
        }
        ema(2000);
        ngola_dijithale(OKULUHLAZA, TLASE);
        ngola_dijithale(OKUBOMVU, TLASE);
        okufakiwe = "";
    } ho_seng_jwalo {
        okufakiwe += inkinobho;
        Seriale.bontsha('*');
    }
}
