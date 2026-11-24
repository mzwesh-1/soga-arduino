// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <Xitsonga.h>

lexi_nga_cinciki nomboro IKHELI_LE_MPU = 0x68;

nomboro16 funda_amabhayithi_amabili() {
    nomboro16 phezulu = Waya.hlaya_bayiti();
    vuyisa (phezulu << 8) | Waya.hlaya_bayiti();
}

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    Waya.ku_sungula();
    Waya.sungula_ku_rhumela(IKHELI_LE_MPU);
    Waya.tsala_bayiti(0x6B);          // irejista yamandla
    Waya.tsala_bayiti(0);             // vusa i-MPU-6050
    Waya.hetisa_ku_rhumela(ntiyiso);
}

swi_hava phindha_phindha() {
    Waya.sungula_ku_rhumela(IKHELI_LE_MPU);
    Waya.tsala_bayiti(0x3B);          // qala kurejista ye-accelerometer
    Waya.hetisa_ku_rhumela(mavunwa);
    Waya.kombela_eka(IKHELI_LE_MPU, 14, ntiyiso);
    nomboro16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    nomboro16 ukushisa = funda_amabhayithi_amabili();
    nomboro16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Siriyali.kombisa("Ukusheshisa X/Y/Z: ");
    Siriyali.kombisa(ax); Siriyali.kombisa(" "); Siriyali.kombisa(ay); Siriyali.kombisa(" "); Siriyali.kombisa(az);
    Siriyali.kombisa("   Ukujika X/Y/Z: ");
    Siriyali.kombisa(gx); Siriyali.kombisa(" "); Siriyali.kombisa(gy); Siriyali.kombisa(" "); Siriyali.kombisa(gz);
    Siriyali.kombisa("   Ukushisa: ");
    Siriyali.kombisa_layini(ukushisa / 340.0 + 36.53);
    rindza(500);
}
