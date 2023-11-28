// jogoDaAdivinhacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype> 
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;
    cout << "Tente acertar o numero entre 0 e 99 " << endl;

    cout << "Escolha o seu nivel de dificuldade " << endl;
    cout << "Facil (F), Medio (M), Dificil (D) " << endl;

    char dificuldade ;
    cin >> dificuldade;
    dificuldade = toupper(dificuldade);

    int numero_de_tentativas;

    if (dificuldade == 'D') {
        numero_de_tentativas = 2;
        cout << "Voce tera " << numero_de_tentativas << " tentativas" << endl;
    }
    else if (dificuldade == 'M') {
        numero_de_tentativas = 4;
        cout << "Voce tera " << numero_de_tentativas << " tentativas" << endl;
        }
    else if(dificuldade == 'F') {
        numero_de_tentativas = 8;
        cout << "Voce tera " << numero_de_tentativas << " tentativas" << endl;
    }
    else
    {
        cout << "Opcao invalida! " << endl;
    }

    srand(time(NULL));// "srand()" para setar a semente dos numero aleatorios, a funcao "time()" é usada porque sempre esta mudando o valor, retorna um numero de segundos
    const int NUMERO_SECRETO = rand() % 100;
    

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;



    for(tentativas = 1 ; tentativas <= numero_de_tentativas ; tentativas ++){

        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;  //abs para retornar um valor absoluto positivo
        pontos = (pontos - pontos_perdidos);

        cout << "O valor do seu chute e: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;


        if (acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
    }
    if (nao_acertou) {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;

        // para imprir variáveis de valores decimais com duas casas decemais
        cout.precision(2);// quantas casa decimais queremos
        cout << fixed; // para fixar a virgula na hora de imprimir

        cout << "Sua pontuacao foi " << pontos << " pontos" << endl;
    }
    cout << "Fim de jogo!!! " << endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
