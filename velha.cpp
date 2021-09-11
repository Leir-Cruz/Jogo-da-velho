/**
 * \file  velha.cpp
 * Copyright 2021 Gabriel Cruz
 */


#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 
int VerificaColuna(int matriz[3][3]) {
    for ( int j = 0; j < 3; j++ ) {
        if ( matriz[0][j] != 0 ) {
            if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j]) {
                return matriz[0][j];
            }
        }
    }
    return false;
}

int VerificaLinha(int matriz[3][3]) {
    for ( int i = 0; i < 3; i++ ) {
        if ( matriz[i][0] != 0 ) {
            if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
                return matriz[i][0];
            }
        }
    }
    return false;
}

int VerificaDiagonal(int matriz[3][3]) {
    if ( matriz[1][1] != 0 ) {
        if ( matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] ) {
            return matriz[1][1];
        }
        if (matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
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
            } else {
                zeros++;
            }
        }
    }
    if (numO > numX + 1 || numX > numO + 1) {
        return -2;
    }else if (zeros > 0) {
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
