// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <Sepedi.h>

sa_fetogego paete IMIGQA = 4;
sa_fetogego paete AMAKHOLOMU = 4;
tlhaka izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
paete amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
paete amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Khiphete ikhiphedi(dira_mmapa_wa_dikonopo(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

sa_fetogego palo OKULUHLAZA = 22;
sa_fetogego palo OKUBOMVU = 23;
sengwalwa iphasiwedi = "1234";
sengwalwa okufakiwe = "";

lefeela thoma() {
    Seriale.mathomo(9600);
    bea_phini(OKULUHLAZA, TSE_TSWAGO);
    bea_phini(OKUBOMVU, TSE_TSWAGO);
    Seriale.bontsha_mothaladi("Faka iphasiwedi bese ucindezela #");
}

lefeela boeletsa() {
    tlhaka inkinobho = ikhiphedi.hwetsa_konopo();
    ge (inkinobho == GA_GO_KONOPO) busetsa;
    ge (inkinobho == '*') {
        okufakiwe = "";
        Seriale.bontsha_mothaladi("Kusuliwe");
    } go_sego_bjalo ge (inkinobho == '#') {
        ge (okufakiwe == iphasiwedi) {
            Seriale.bontsha_mothaladi("Iphasiwedi ilungile. Ngena!");
            ngwala_dijithale(OKULUHLAZA, GODIMO);
        } go_sego_bjalo {
            Seriale.bontsha_mothaladi("Iphasiwedi ayilungile!");
            ngwala_dijithale(OKUBOMVU, GODIMO);
        }
        leta(2000);
        ngwala_dijithale(OKULUHLAZA, FASE);
        ngwala_dijithale(OKUBOMVU, FASE);
        okufakiwe = "";
    } go_sego_bjalo {
        okufakiwe += inkinobho;
        Seriale.bontsha('*');
    }
}
