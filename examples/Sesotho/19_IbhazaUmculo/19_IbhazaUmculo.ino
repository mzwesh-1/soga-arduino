// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <Sesotho.h>

e_sa_fetoheng palo IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
palo amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
palo isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

lefeela qala() {
    bakeng_sa (palo i = 0; i < 8; i++) {
        molumo(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        ema(isikhathi_senothi[i] * 1.3);
    }
    emisa_molumo(IBHAZA);
}

lefeela pheta_pheta() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
