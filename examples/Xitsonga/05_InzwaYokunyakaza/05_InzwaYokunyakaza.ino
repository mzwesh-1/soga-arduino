// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <Xitsonga.h>

lexi_nga_cinciki nomboro I_PIR = 7;
lexi_nga_cinciki nomboro IBHAZA = 6;
lexi_nga_cinciki nomboro ILED = 13;

swi_hava sungula() {
    veka_phini(I_PIR, LESWI_NGHENAKA);
    veka_phini(IBHAZA, LESWI_HUMAKA);
    veka_phini(ILED, LESWI_HUMAKA);
    Siriyali.ku_sungula(9600);
    Siriyali.kombisa_layini("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

swi_hava phindha_phindha() {
    loko (hlaya_dijitali(I_PIR) == HENHLA) {
        tsala_dijitali(ILED, HENHLA);
        tsala_dijitali(IBHAZA, HENHLA);
        Siriyali.kombisa_layini("Kukhona onyakazayo!");
    } ku_nga_ri_tano {
        tsala_dijitali(ILED, HANSI);
        tsala_dijitali(IBHAZA, HANSI);
    }
    rindza(200);
}
