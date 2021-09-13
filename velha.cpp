/**
 * \file  velha.cpp
 * Copyright 2021 Gabriel Cruz
 */


#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Gabriel Cruz
 * @param  velha é uma matriz 3x3 que sera de base para o jogo da velha 
 * 
 *  a função Verifica uma matriz 3x3 a situacao do jogo da velha, o vencedor, caso empate, caso impossível pelas regras
 */ 
int VerificaColuna(int matriz[3][3]) {
    int primeiroGanhador = 0;
    int segundoGanhador = 0;
    for ( int j = 0; j < 3; j++ ) {
        if ( matriz[0][j] != 0 ) {
            if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j]) {
                if (primeiroGanhador == 0) {
                    primeiroGanhador =  matriz[0][j];
                } else {
                    segundoGanhador = matriz[0][j];
                }
            }
        }
    }
    if (primeiroGanhador != 0 && segundoGanhador != 0) {
        return -2;
    } else {
        return primeiroGanhador;
    }
}

int VerificaLinha(int matriz[3][3]) {
    int primeiroGanhador = 0;
    int segundoGanhador = 0;
    for ( int i = 0; i < 3; i++ ) {
        if ( matriz[i][0] != 0 ) {
            if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
                if (primeiroGanhador == 0) {
                    primeiroGanhador =  matriz[i][0];
                } else {
                    segundoGanhador = matriz[i][0];
                }
            }
        }
    }
    if (primeiroGanhador != 0 && segundoGanhador != 0) {
        return -2;
    } else {
        return primeiroGanhador;
    }
}

int VerificaDiagonal(int matriz[3][3]) {
    if ( matriz[1][1] != 0 ) {
        if ( matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] ) {
            return matriz[1][1];
        }
        if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
            return matriz[1][1];
        }
    }
    return 0;
}

int VerificaNumeros(int matriz[3][3]) {
    int zeros = 0;
    int numX = 0;
    int numO = 0;
    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            if (matriz[i][j] == 1) {
                numX++;
            } else if (matriz[i][j] == 2) {
                numO++;
            } else if (matriz[i][j] == 0) {
                zeros++;
            } else {
                return -2;
            }
        }
    }
    if (numO > numX + 1 || numX > numO + 1) {
        return -2;
    } else if (zeros > 0) {
        return -1;
    }
    return 0;
}

int VerificaVelha(int velha[3][3]) {
    int indefinido = VerificaNumeros(velha);
    if ( indefinido < -1 ) {
        return indefinido;
    }
    int ganhadorDiagonal = VerificaDiagonal(velha);
    if ( ganhadorDiagonal != 0 ) {
        return ganhadorDiagonal;
    }
    int ganhadorColuna = VerificaColuna(velha);
    if ( ganhadorColuna != 0 ) {
        return ganhadorColuna;
    }
    int ganhadorLinha = VerificaLinha(velha);
    if ( ganhadorLinha != 0 ) {
       return ganhadorLinha;
    }
    return indefinido;
}
