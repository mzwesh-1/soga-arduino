// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <Xitsonga.h>

lexi_nga_cinciki nomboro IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
nomboro amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
nomboro isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

swi_hava sungula() {
    rhendzeleka (nomboro i = 0; i < 8; i++) {
        mpfumawulo(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        rindza(isikhathi_senothi[i] * 1.3);
    }
    yimisa_mpfumawulo(IBHAZA);
}

swi_hava phindha_phindha() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
