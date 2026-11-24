// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <Xitsonga.h>

lexi_nga_cinciki nomboro INKINOBHO_A = 9;
lexi_nga_cinciki nomboro INKINOBHO_B = 8;
lexi_nga_cinciki nomboro ILED = 5;

swi_hava sungula() {
    veka_phini(INKINOBHO_A, LESWI_NGHENAKA_HI_KU_KOKA);
    veka_phini(INKINOBHO_B, LESWI_NGHENAKA_HI_KU_KOKA);
    veka_phini(ILED, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    loko (hlaya_dijitali(INKINOBHO_A) == HANSI) tsala_dijitali(ILED, HENHLA);
    loko (hlaya_dijitali(INKINOBHO_B) == HANSI) tsala_dijitali(ILED, HANSI);
}
