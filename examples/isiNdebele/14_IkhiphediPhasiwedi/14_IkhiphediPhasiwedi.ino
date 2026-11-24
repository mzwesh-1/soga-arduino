// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <isiNdebele.h>

okungatjhugulukiko ibhayithi IMIGQA = 4;
okungatjhugulukiko ibhayithi AMAKHOLOMU = 4;
uhlamvu izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
ibhayithi amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
ibhayithi amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Ikhiphedi ikhiphedi(yenza_imephu_yamakunubhu(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

okungatjhugulukiko inomboro OKULUHLAZA = 22;
okungatjhugulukiko inomboro OKUBOMVU = 23;
umtlolo iphasiwedi = "1234";
umtlolo okufakiwe = "";

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    beka_iphini(OKULUHLAZA, OKUPHUMAKO);
    beka_iphini(OKUBOMVU, OKUPHUMAKO);
    Isiriyali.khombisa_umugqa("Faka iphasiwedi bese ucindezela #");
}

ilize phinda_phinda() {
    uhlamvu inkinobho = ikhiphedi.fumana_ikunubhu();
    nangabe (inkinobho == AKUKHO_KUNUBHU) buyisa;
    nangabe (inkinobho == '*') {
        okufakiwe = "";
        Isiriyali.khombisa_umugqa("Kusuliwe");
    } ngokunye nangabe (inkinobho == '#') {
        nangabe (okufakiwe == iphasiwedi) {
            Isiriyali.khombisa_umugqa("Iphasiwedi ilungile. Ngena!");
            tlola_idijithali(OKULUHLAZA, PHEZULU);
        } ngokunye {
            Isiriyali.khombisa_umugqa("Iphasiwedi ayilungile!");
            tlola_idijithali(OKUBOMVU, PHEZULU);
        }
        lindela(2000);
        tlola_idijithali(OKULUHLAZA, PHASI);
        tlola_idijithali(OKUBOMVU, PHASI);
        okufakiwe = "";
    } ngokunye {
        okufakiwe += inkinobho;
        Isiriyali.khombisa('*');
    }
}
