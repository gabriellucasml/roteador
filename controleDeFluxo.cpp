#ifndef _FLUXO_
#define _FLUXO_

#include <iostream>
#include "roteamento.cpp"
#include "arbitro.cpp"
#include "memoria.cpp"
#include "chaveamento.cpp"

class ControleDeFluxo{
	public:
		Pacote * pacote;
		Roteamento * roteamento;
		Memoria * memoria;
		ControleDeFluxo * controle1, *controle2, *controle3, *controle4;
		Chaveamento * chaveamento;

		ControleDeFluxo(Chaveamento * _chaveamento, Arbitro * _arbitro1, Arbitro * _arbitro2, Arbitro * _arbitro3, Arbitro * _arbitro4){
			memoria = new Memoria();
			chaveamento = _chaveamento;
			roteamento = new Roteamento(_arbitro1, _arbitro2, _arbitro3, _arbitro4, memoria);
		}

		void setControles(ControleDeFluxo * _controle1, ControleDeFluxo * _controle2, ControleDeFluxo * _controle3, ControleDeFluxo * _controle4){
			controle1 = _controle1;
			controle2 = _controle2;
			controle3 = _controle3;
			controle4 = _controle4;
		}
		//parte da esquerda
		void enviarPacote(){
			std::cout << "enviando pacote" << std::endl;
			int rotear = roteamento->rotear();
			switch(rotear){
				case 0:	std::cout << controle1->chaveamento->setPacote(memoria->lerMem(), rotear) << std::endl;
						controle1->chaveamento->pacote1->imprimir();
						std::cout << "chaveamento 0" << std::endl;
						break;
				case 1: std::cout << controle2->chaveamento->setPacote(memoria->lerMem(), rotear) << std::endl;
						controle2->chaveamento->pacote2->imprimir();
						std::cout << "chaveamento 1" << std::endl;
						break;		
				case 2: std::cout << controle3->chaveamento->setPacote(memoria->lerMem(), rotear) << std::endl;
						controle3->chaveamento->pacote3->imprimir();
						std::cout << "chaveamento 2" << std::endl;
						break;
				case 3: std::cout << controle4->chaveamento->setPacote(memoria->lerMem(), rotear) << std::endl;
						controle4->chaveamento->pacote4->imprimir();
						std::cout << "chaveamento 3" << std::endl;
						break;
			}
		}
		//Parte da direita
		void receberPacote(){
			std::cout << "recebendo pacote" << std::endl;
			Pacote * aux = chaveamento->chavear();
			memoria->escreverMem(aux);
			//ux->imprimir();
		}
};

#endif
