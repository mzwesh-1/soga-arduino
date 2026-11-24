// Ikhiphedi ye-4x4: faka iphasiwedi "1234" bese ucindezela #. * iyasula.
// Ukuxhuma (kusuka kwesobunxele): amaphini 1-4 (imigqa) -> 9, 8, 7, 6; amaphini 5-8 (amakholomu) -> 5, 4, 3, 2
// i-LED eluhlaza -> 22, i-LED ebomvu -> 23
// Dinga umtapo: "Keypad" (Tools -> Manage Libraries)
#include <Keypad.h>
#include <Xitsonga.h>

lexi_nga_cinciki bayiti IMIGQA = 4;
lexi_nga_cinciki bayiti AMAKHOLOMU = 4;
letere izinkinobho[IMIGQA][AMAKHOLOMU] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
bayiti amaphini_emigqa[IMIGQA] = {9, 8, 7, 6};
bayiti amaphini_amakholomu[AMAKHOLOMU] = {5, 4, 3, 2};
Khiphedi ikhiphedi(endla_mepe_wa_tibathani(izinkinobho), amaphini_emigqa, amaphini_amakholomu, IMIGQA, AMAKHOLOMU);

lexi_nga_cinciki nomboro OKULUHLAZA = 22;
lexi_nga_cinciki nomboro OKUBOMVU = 23;
matsalwa iphasiwedi = "1234";
matsalwa okufakiwe = "";

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    veka_phini(OKULUHLAZA, LESWI_HUMAKA);
    veka_phini(OKUBOMVU, LESWI_HUMAKA);
    Siriyali.kombisa_layini("Faka iphasiwedi bese ucindezela #");
}

swi_hava phindha_phindha() {
    letere inkinobho = ikhiphedi.kuma_bathani();
    loko (inkinobho == KU_HAVA_BATHANI) vuyisa;
    loko (inkinobho == '*') {
        okufakiwe = "";
        Siriyali.kombisa_layini("Kusuliwe");
    } ku_nga_ri_tano loko (inkinobho == '#') {
        loko (okufakiwe == iphasiwedi) {
            Siriyali.kombisa_layini("Iphasiwedi ilungile. Ngena!");
            tsala_dijitali(OKULUHLAZA, HENHLA);
        } ku_nga_ri_tano {
            Siriyali.kombisa_layini("Iphasiwedi ayilungile!");
            tsala_dijitali(OKUBOMVU, HENHLA);
        }
        rindza(2000);
        tsala_dijitali(OKULUHLAZA, HANSI);
        tsala_dijitali(OKUBOMVU, HANSI);
        okufakiwe = "";
    } ku_nga_ri_tano {
        okufakiwe += inkinobho;
        Siriyali.kombisa('*');
    }
}
