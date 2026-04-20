#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int pasirinkimas;
    string valiuta;
    double kiekis, rezultatas;
    bool isRunning = true;

    double GBP_Bendras   = 0.8729;
    double GBP_Pirkti    = 0.8600;
    double GBP_Parduoti  = 0.9220;
    double USD_Bendras   = 1.1793;
    double USD_Pirkti    = 1.1460;
    double USD_Parduoti  = 1.2340;
    double INR_Bendras   = 104.6918;
    double INR_Pirkti    = 101.3862;
    double INR_Parduoti  = 107.8546;

    cout << "Valiutos keitykla (EUR):" << endl;
    while (isRunning) {
        cout << "\n Pasirinkite veiksma:" << endl;
        cout << "1. Valiutos kurso palyginimas su kita valiuta." << endl;
        cout << "2. Galimybe isigyti valiutos (t. y. pirkti valiuta)." << endl;
        cout << "3. Galimybe parduoti valiuta (t. y. parduoti valiuta)." << endl;
        cout << "0. Iseiti." << endl;
        cout << "Jusu pasirinkimas: "; // kodel tarpo nera po : console, kai paleidziu programa?
        cin >> pasirinkimas;

        if (pasirinkimas == 0) {
            isRunning = false;
            break;
        }

        cout << "Iveskite valiuta - GBP, USD, INR: ";
        cin >> valiuta;

        switch (pasirinkimas) {
            case 1:
                if (valiuta == "GBP" || valiuta == "gbp") {
                    rezultatas = GBP_Bendras;
                }
                else if (valiuta == "USD" || valiuta == "usd") {
                    rezultatas = USD_Bendras;
                }
                else if (valiuta == "INR" || valiuta == "inr") {
                    rezultatas = INR_Bendras;
                }
                else {
                    cout << "Tokios valiutos duomenu bazeje nera." << endl;
                    break;
                }
                cout << "1 EUR palyginus su jusu pasirinkta valiuta yra: " << rezultatas << endl;
                break;
                case 2:
                cout << "Iveskite kiek euru norite keisti i " << valiuta << ": ";
                cin >> kiekis;
                if (kiekis <= 0) {
                    cout << "Kiekis negali buti 0 arba neigiamas skaicius." << endl;
                    break;
                }

                if (valiuta == "GBP" || valiuta == "gbp") {
                    rezultatas = kiekis * GBP_Pirkti;
                }
                else if (valiuta == "USD" || valiuta == "usd") {
                    rezultatas = kiekis * USD_Pirkti;
                }
                else if (valiuta == "INR" || valiuta == "inr") {
                    rezultatas = kiekis * INR_Pirkti;
                }
                else {
                    cout << "Tokios valiutos duomenu bazeje nera." << endl;
                    break;
                }
                cout << fixed << setprecision(2);
                cout << "Jus gausite: " << rezultatas << " " << valiuta << endl;
                break;

                case 3:
                cout << "Iveskite kiek " << valiuta << " norite parduoti: ";
                cin >> kiekis;
                if (kiekis <= 0) {
                    cout << "Kiekis negali buti 0 arba neigiamas skaicius." << endl;
                    break;
                }

                if (valiuta == "GBP" || valiuta == "gbp") {
                    rezultatas = kiekis * GBP_Parduoti;
                }
                else if (valiuta == "USD" || valiuta == "usd") {
                    rezultatas = kiekis * USD_Parduoti;
                }
                else if (valiuta == "INR" || valiuta == "inr") {
                    rezultatas = kiekis * INR_Parduoti;
                }
                else {
                    cout << "Tokios valiutos duomenu bazeje nera." << endl;
                    break;
                }

                cout << fixed << setprecision(2);
                cout << "Jus gausite: " << rezultatas << " EUR" << endl;
                break;

            default:
                cout << "Tokio pasirinkimo nera." << endl;

        }
    }

    cout << "Programa isjungta sekmingai." << endl;
    return 0;
}