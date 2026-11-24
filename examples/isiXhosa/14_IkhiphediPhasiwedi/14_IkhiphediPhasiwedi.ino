// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <isiXhosa.h>

engatshintshiyo ibhayithi IMIGQA = 4;
engatshintshiyo ibhayithi AMAKHOLOMU = 4;
unobumba izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
ibhayithi amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
ibhayithi amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Ikhiphedi ikhiphedi(yenza_imaphu_yamaqhosha(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

engatshintshiyo inani OKULUHLAZA = 22;
engatshintshiyo inani OKUBOMVU = 23;
umbhalo iphasiwedi = "1234";
umbhalo okufakiwe = "";

ize qalisa() {
    Isiriyali.ukuqala(9600);
    misela_iphini(OKULUHLAZA, OKUPHUMAYO);
    misela_iphini(OKUBOMVU, OKUPHUMAYO);
    Isiriyali.bonisa_umgca("Faka iphasiwedi bese ucindezela #");
}

ize phinda_phinda() {
    unobumba inkinobho = ikhiphedi.fumana_iqhosha();
    ukuba (inkinobho == AKUKHO_QHOSHA) buyisa;
    ukuba (inkinobho == '*') {
        okufakiwe = "";
        Isiriyali.bonisa_umgca("Kusuliwe");
    } kungenjalo ukuba (inkinobho == '#') {
        ukuba (okufakiwe == iphasiwedi) {
            Isiriyali.bonisa_umgca("Iphasiwedi ilungile. Ngena!");
            bhala_idijithali(OKULUHLAZA, PHEZULU);
        } kungenjalo {
            Isiriyali.bonisa_umgca("Iphasiwedi ayilungile!");
            bhala_idijithali(OKUBOMVU, PHEZULU);
        }
        linda(2000);
        bhala_idijithali(OKULUHLAZA, EZANTSI);
        bhala_idijithali(OKUBOMVU, EZANTSI);
        okufakiwe = "";
    } kungenjalo {
        okufakiwe += inkinobho;
        Isiriyali.bonisa('*');
    }
}
