/**
 * \file  velha.cpp
 */


#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

int VerificaColuna( int matriz[3][3] )
{
	
	for(int j = 0; j < 3; j++){
	    if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j] && matriz[0][j] != 0) {
	    	return matriz[0][j];
	    }
	}
	return false;

}

int VerificaLinha( int matriz[3][3] )
{
	
	for(int i = 0; i < 3; i++){
	    if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0) {
	    	return matriz[i][0];
	    }
	}
	return false;

}

int VerificaDiagonal( int matriz[3][3] )
{
	if(matriz[1][1] != 0) {
		if(matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] ){
			return matriz[1][1];
		}
		else if(matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
			return matriz[1][1];
		}
	}
	return 0;
}

int VerificaVelha( int velha[3][3] )
{
	int ganhadorColuna = VerificaColuna(velha);
	if(ganhadorColuna != 0 ) {
		return ganhadorColuna;
	}
	int ganhadorLinha = VerificaLinha(velha);
		if(ganhadorLinha != 0 ) {
		return ganhadorLinha;
	}
	int ganhadorDiagonal = VerificaDiagonal(velha);
	if(ganhadorDiagonal != 0 ) {
		return ganhadorDiagonal;
	}
	return 0;
}


