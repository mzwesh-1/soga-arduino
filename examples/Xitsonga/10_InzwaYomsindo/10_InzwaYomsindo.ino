// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <Xitsonga.h>

lexi_nga_cinciki nomboro INZWA = 2;
lexi_nga_cinciki nomboro ILED = 13;
buliyani ikhanyile = mavunwa;
handle_ka_mfungho leha isikhathi_sokugcina = 0;

swi_hava sungula() {
    veka_phini(INZWA, LESWI_NGHENAKA);
    veka_phini(ILED, LESWI_HUMAKA);
    Siriyali.ku_sungula(9600);
}

swi_hava phindha_phindha() {
    loko (hlaya_dijitali(INZWA) == HENHLA && timilisekoni() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        tsala_dijitali(ILED, ikhanyile ? HENHLA : HANSI);
        isikhathi_sokugcina = timilisekoni();
        Siriyali.kombisa("Ngizwe umsindo! Izinga: ");
        Siriyali.kombisa_layini(hlaya_analogo(A0));
    }
}
