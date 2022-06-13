#include <iostream>
#include <conio.h> //getch();
#include <cstdlib> //system("cls");
#include <windows.h> //Sleep

#define ESC 27
#define SUBIR 72
#define BAJAR 80

using namespace std;

int menu();

void autoFantastico(); //por algoritmo
void elChoque(); //por tabla
void estrellaFugaz(); //por tabla
void elIndeciso(); //por algoritmo

void disp_binary(int);
void delay(int);

int main() {
    char password[] = {'A', 'B', 'C', '1', '0', '\0'}; //"\0" indica el fin de la cadena de caracteres
    char arr[6] = {};
    int verificarPsw = 1; //1 = password correcta
    int contador = 0; //3 intentos para ingresar el password

    do {
        cout << "Ingrese su password de 5 digitos: ";
        for(int i = 0; i < 5; i++) {
            arr[i] = getch();
            cout << "*";
        }
        cout << endl;

        //verificar password
        for(int i = 0; i < 5; i++) {
            if(password[i] != arr[i]) {
                verificarPsw = 0;
            }
        }

        if(verificarPsw == 1) {
            cout << endl;
            cout << "Bienvenido al sistema" << endl;
            contador = 99;
        } else {
            cout << "Password no valida" << endl;
            cout << endl;
            verificarPsw = 1;
            contador++;
        }
    } while(contador < 3);

    if(contador == 3) {
        return 0;
    }

    //menú
    menu();
}

int menu() {
    int opcion;

    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1 -> Auto fantastico" << endl;
        cout << "2 -> El choque" << endl;
        cout << "3 -> Estrella fugaz" << endl;
        cout << "4 -> El indeciso" << endl;
        cout << "5 -> Salir" << endl;
        cout << endl;
        cout << "Elija su opcion: ";
        cin >> opcion;
    } while(opcion < 1 || opcion > 5);

    switch(opcion) {
        case 1:
            autoFantastico();
        break;

        case 2:
            elChoque();
        break;

        case 3:
            estrellaFugaz();
        break;

        case 4:
            elIndeciso();
        break;

        default:
            return 0;
    }
}

void autoFantastico() {
    Sleep(2000);
    system("cls"); //limpiar pantalla

    unsigned char output; //un entero de 8 bits sin signo (rango de 0 a 255)
    int time = 1300; //tiempo de espera

    cout << "AUTO FANTASTICO" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima la tecla ESC para finalizar" << endl;
    cout << endl;

    do {
        //ida
        output = 0x80;
        for(int i = 0; i < 8; i++) { //8 leds
            disp_binary(output);
            delay(time); //espera un momento
            output = output >> 1; //">>" desplazamiento a la derecha
        }

        //vuelta
        output = 0x01;
        for(int i = 0; i < 6; i++) {
            output = output << 1; //"<<" desplazamiento a la izquierda
            disp_binary(output);
            delay(time);
        }
    } while(!kbhit()); //repeat loop until the keyboard is hit

    char tecla = getch();

    if(tecla == ESC) {
        system("cls");
        menu();
    } /* else {
        cout << endl << endl;
        cout << "Error";
        autoFantastico();
    } */
}

void elChoque() {
    Sleep(2000);
    system("cls");

    unsigned char output[8] = {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81};
    int time = 3000;

    cout << "EL CHOQUE" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima la tecla ESC para finalizar" << endl;
    cout << endl;

    do {
        for(int i = 0; i < 8; i++) {
            disp_binary(output[i]);
            delay(time);
        }

    } while (!kbhit());

    char tecla = getch();

    if(tecla == ESC) {
        system("cls");
        menu();
    }
}

void estrellaFugaz() {
    Sleep(2000);
    system("cls");

    unsigned char output[16] = {0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00};

    cout << "ESTRELLA FUGAZ" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima la tecla ESC para finalizar" << endl;
    cout << endl;

    do {
        for(int i = 0; i < 8; i++) { //se prende
            disp_binary(output[i]);
            delay(700);
        }

        //1000 0000
        //1100 0000
        //1110 0000
        //1111 0000
        //1111 1000
        //1111 1100
        //1111 1110
        //1111 1111

        for(int i = 8; i < 16; i++) { //se apaga
            disp_binary(output[i]);
            delay(2300);
        }

        //0111 1111
        //0011 1111
        //0001 1111
        //0000 1111
        //0000 0111
        //0000 0011
        //0000 0001
        //0000 0000

        delay(17000);
    } while(!kbhit());

    char tecla = getch();

    if(tecla == ESC) {
        system("cls");
        menu();
    }
}

void elIndeciso() {
    Sleep(2000);
    system("cls");

    unsigned char output;
    int time = 4000;
    int avanza = 1;

    cout << "EL INDECISO" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima la tecla ESC para finalizar" << endl;
    cout << endl;

    do {
        for(int i = 0; i < 8; i++) { //8 leds
            output = 0x80;
            for(int j = 0; j < avanza; j++) {
                disp_binary(output);
                delay(time);
                output = output >> 1; //">>" desplazamiento a la derecha
            }
            avanza = avanza + 1;
        }
        avanza = 1;
    } while(!kbhit());

    char tecla = getch();

    if(tecla == ESC) {
        system("cls");
        menu();
    }
}

void disp_binary(int n) {
    for(int i = 128; i > 0; i = i / 2) {
        if(n&i) { //"&" producto bit a bit (AND)
            cout << "* ";
        } else {
            cout << "_ ";
        }
    }
    cout << "\b \r"; //borrar línea
}

//no entiendo como funciona
void delay(int time) {
    for(int i = time; i > 0; i--) {
        for(int j = 0; j < 65535; j++);
    }
}
