// CTRL + ALT + L - auto format

#include <iostream>
using namespace std;

int main() {
    const int MAX_MOKINIU = 3; // negalima keisti kiekio - const; testavimui 3 mokiniai - atkeisti!!
    const int MAX_PAZYMIU = 10;

    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazymiuKiekis[MAX_MOKINIU] = {0}; // jei nebus nulio, bus random skaiciai..

    int mokiniuKiekis = 0;
    int pasirinkimas;
    bool isRunning = true;
    string ieskomasVardas;



    while (isRunning) {
        cout << "\n--- Mokiniu pazymiu sistema ---" << endl;
        cout << "1. Prideti mokini ir jo pazymius" << endl;
        cout << "2. Rodyti visu mokiniu pazymius" << endl;
        cout << "3. Rodyti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti mokinio pazymi" << endl;
        cout << "5. Pasalinti mokini" << endl;
        cout << "0. Iseiti" << endl;
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                if (mokiniuKiekis >= MAX_MOKINIU) {
                    cout << "Negalima prideti daugiau mokiniu, nes yra pasiektas limitas." << endl;
                    break;
                }

                cout << "Iveskite mokinio varda: ";
                cin >> vardai[mokiniuKiekis];
                int pazKiekis;
                cout << "Kiek pazymiu norite ivesti? (1-10): ";
                cin >> pazKiekis;

                if (pazKiekis > MAX_PAZYMIU || pazKiekis < 1) {
                    cout << "Neteisingas pazymiu kiekis." << endl;
                    break;
                }

                pazymiuKiekis[mokiniuKiekis] = pazKiekis;

                for (int i = 0; i < pazKiekis; i++) {
                    cout << "Iveskite " << (i + 1) << "-aji pazymi: ";
                    cin >> pazymiai[mokiniuKiekis][i];

                    if (pazymiai[mokiniuKiekis][i] < 1 || pazymiai[mokiniuKiekis][i] > 10) {
                        cout << "Pazymys turi buti nuo 1 iki 10. Iveskite is naujo: " << endl;
                        i--;
                    }
                }

                mokiniuKiekis++;
                cout << "Mokinys sekmingai pridetas." << endl;
                break;
            }
            case 2: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                    break;
                }

                cout << "Visu mokiniu pazymiai:" << endl;
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << vardai[i] << ": ";
                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                    break;
                }
                bool rastas = false;

                cout << "Iveskite mokinio varda: ";
                cin >> ieskomasVardas;

                for (int i = 0; i < mokiniuKiekis; i++) {
                    if (ieskomasVardas == vardai[i]) {
                        cout << "Mokinys " << vardai[i] << " ir jo pazymiai: ";
                        for (int j = 0; j < pazymiuKiekis[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                        cout << endl;
                        rastas = true;
                        break;
                    }
                }

                if (!rastas) {
                    cout << "Toks mokinys nerastas." << endl;
                }
                break;
            }
            case 4: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                    break;
                }
                bool rastas = false;

                cout << "Iveskite mokinio varda: ";
                cin >> ieskomasVardas;
                for (int i = 0; i < mokiniuKiekis; i++) {
                    if (vardai[i] == ieskomasVardas) {
                        rastas = true;

                        cout << "Suvesti mokinio pazymiai: ";
                        for (int j = 0; j < pazymiuKiekis[i]; j++) {
                            cout << "(" << j + 1 << ") " << pazymiai[i][j] << " ";
                        }
                        cout << endl;

                        int numeris;
                        int naujasPazymys;

                        cout << "Kuri pazymi norite keisti? (iveskite numeri): ";
                        cin >> numeris;

                        if (numeris < 1 || numeris > pazymiuKiekis[i]) {
                            cout << "Tokio pazymio numerio nera." << endl;
                            break;
                        }

                        cout << "Iveskite nauja pazymi: ";
                        cin >> naujasPazymys;

                        if (naujasPazymys < 1 || naujasPazymys > 10) {
                            cout << "Pazymys turi buti nuo 1 iki 10." << endl;
                            break;
                        }

                        pazymiai[i][numeris - 1] = naujasPazymys;
                        cout << "Pazymys sekmingai atnaujintas." << endl;
                        break;
                    }
                }

                if (!rastas) {
                    cout << "Toks mokinys nerastas." << endl;
                }
                break;
            }
            case 5: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                    break;
                }

                bool rastas = false;

                cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
                cin >> ieskomasVardas;

                for (int i = 0; i < mokiniuKiekis; i++) {
                    if (vardai[i] == ieskomasVardas) {
                        rastas = true;

                        for (int j = i; j < mokiniuKiekis - 1; j++) {
                            vardai[j] = vardai[j + 1];
                            pazymiuKiekis[j] = pazymiuKiekis[j + 1];

                            for (int k = 0; k < MAX_PAZYMIU; k++) {
                                pazymiai[j][k] = pazymiai[j + 1][k];
                            }
                        }

                        mokiniuKiekis--;
                        cout << "Mokinys sekmingai pasalintas." << endl;
                        break;
                    }
                }

                if (!rastas) {
                    cout << "Toks mokinys nerastas." << endl;
                }
                break;
            }
            case 0:
                isRunning = false;
                cout << "Programa baigta." << endl;
                break;


            default:
                cout << "Tokio pasirinkimo nera.";
                break;
        }
    }

    return 0;
}
