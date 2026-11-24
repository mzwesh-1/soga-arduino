// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <siSwati.h>

lokungagucuki inombolo IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
inombolo amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
inombolo isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

lite cala() {
    jikeleta (inombolo i = 0; i < 8; i++) {
        ithoni(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        lindza(isikhathi_senothi[i] * 1.3);
    }
    misa_ithoni(IBHAZA);
}

lite phindza_phindza() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
