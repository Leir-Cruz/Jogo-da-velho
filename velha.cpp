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

int VerificaVelha( int velha[3][3] )
{
	int ganhadorColuna = VerificaColuna(velha);
	int ganhadorLinha = VerificaLinha(velha);
	if(ganhadorColuna != 0 ) {
		return ganhadorColuna;
	}
	else if(ganhadorLinha != 0) {
		return ganhadorLinha;
	}
	else {
		return 0;
	}
}


