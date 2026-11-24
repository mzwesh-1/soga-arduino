// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <siSwati.h>

lokungagucuki inombolo IKHELI_LE_MPU = 0x68;

inombolo16 funda_amabhayithi_amabili() {
    inombolo16 phezulu = Lucingo.fundza_ibhayithi();
    buyisa (phezulu << 8) | Lucingo.fundza_ibhayithi();
}

lite cala() {
    Siriyali.kucala(9600);
    Lucingo.kucala();
    Lucingo.cala_kutfumela(IKHELI_LE_MPU);
    Lucingo.bhala_ibhayithi(0x6B);          // irejista yamandla
    Lucingo.bhala_ibhayithi(0);             // vusa i-MPU-6050
    Lucingo.ceda_kutfumela(liciniso);
}

lite phindza_phindza() {
    Lucingo.cala_kutfumela(IKHELI_LE_MPU);
    Lucingo.bhala_ibhayithi(0x3B);          // qala kurejista ye-accelerometer
    Lucingo.ceda_kutfumela(emanga);
    Lucingo.cela_ku(IKHELI_LE_MPU, 14, liciniso);
    inombolo16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    inombolo16 ukushisa = funda_amabhayithi_amabili();
    inombolo16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Siriyali.khombisa("Ukusheshisa X/Y/Z: ");
    Siriyali.khombisa(ax); Siriyali.khombisa(" "); Siriyali.khombisa(ay); Siriyali.khombisa(" "); Siriyali.khombisa(az);
    Siriyali.khombisa("   Ukujika X/Y/Z: ");
    Siriyali.khombisa(gx); Siriyali.khombisa(" "); Siriyali.khombisa(gy); Siriyali.khombisa(" "); Siriyali.khombisa(gz);
    Siriyali.khombisa("   Ukushisa: ");
    Siriyali.khombisa_umugca(ukushisa / 340.0 + 36.53);
    lindza(500);
}
