// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <isiZulu.h>

engaguquki ibhayithi IMIGQA = 4;
engaguquki ibhayithi AMAKHOLOMU = 4;
uhlamvu izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
ibhayithi amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
ibhayithi amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Ikhiphedi ikhiphedi(yenza_imephu_yezinkinobho(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

engaguquki inombolo OKULUHLAZA = 22;
engaguquki inombolo OKUBOMVU = 23;
umbhalo iphasiwedi = "1234";
umbhalo okufakiwe = "";

ize qala() {
    Isiriyeli.ukuqala(9600);
    setha_iphini(OKULUHLAZA, OKUPHUMAYO);
    setha_iphini(OKUBOMVU, OKUPHUMAYO);
    Isiriyeli.bonisa_umugqa("Faka iphasiwedi bese ucindezela #");
}

ize phindaphinda() {
    uhlamvu inkinobho = ikhiphedi.thola_inkinobho();
    uma (inkinobho == AKUKHO_NKINOBHO) buyisa;
    uma (inkinobho == '*') {
        okufakiwe = "";
        Isiriyeli.bonisa_umugqa("Kusuliwe");
    } kungenjalo uma (inkinobho == '#') {
        uma (okufakiwe == iphasiwedi) {
            Isiriyeli.bonisa_umugqa("Iphasiwedi ilungile. Ngena!");
            bhala_idijithali(OKULUHLAZA, PHEZULU);
        } kungenjalo {
            Isiriyeli.bonisa_umugqa("Iphasiwedi ayilungile!");
            bhala_idijithali(OKUBOMVU, PHEZULU);
        }
        linda(2000);
        bhala_idijithali(OKULUHLAZA, PHANSI);
        bhala_idijithali(OKUBOMVU, PHANSI);
        okufakiwe = "";
    } kungenjalo {
        okufakiwe += inkinobho;
        Isiriyeli.bonisa('*');
    }
}
