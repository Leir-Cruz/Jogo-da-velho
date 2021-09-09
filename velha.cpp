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

int VerificaVelha( int velha[3][3] )
{
	for(int j = 0; j < 3; j++) {
		int ganhador = VerificaColuna(velha);
		if(ganhador != 0) {
			return ganhador;
		}
	}
	return 0;
}


