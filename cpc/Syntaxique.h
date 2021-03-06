#pragma once
#include "Lexical.h"
#include "Semantique.h"
#include "ObjectCodeGenerator.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <map>
#include "ObjectCodeGenerator.h"
class Syntaxique
{
public:
	// Constructeurs - Destructeurs
	Syntaxique(string inputFile, bool logIden,bool logMotRes);
	Syntaxique(Lexical* lexical);
	~Syntaxique();
	
	// M�thodes divers
	void startParsing();

private:
	// Attributs	
	Lexical* lexical;
	Semantique* semantique; 
	ObjectCodeGenerator *generator;
	TUniteLexicale uniteCourante;
	vector<string> errors;
	ofstream xmlFile;
	map <pair<int, int>, vector<string>> syntaxErrors;//Un arbre d'erreurs de la forme <<Ln,Col>,vecteur des symbols attendus>
	// variables du sémantique
	vector<string> listeparam;
	string tmp;
	string expr;
	string fct_tmp;
	int ite_varlocalglobal;
	// variables de la gen de code
	int nbrDeclarations,nbrParam;
	map<int, string> adresses;//les adresses des labels <adresse, label>
	string currentFunction;
	bool needReverse;
	// Methodes
	void end();
	void printErrors();
	void xmlOpen(string caller); // Ecrit dans le fichier XML la balise ouvrante de la fonction caller
	void xmlClose(string caller);  // De m�me pour la balise fermante$
	void logError(string error);
	void logDebug(string message);
	void syntaxError(Production prod);
	void consommer(TUnite expected);//consomme en vérifiant si ul==expected
	bool estPremierDe(Production unite);
	bool estSuivantDe(Production unite);
	bool isMotCle(string mc); // voir si l'unite coutrante est mot cle egal au parametre entre 
	// M�thodes issues des productions
	void programme();
	void listeDeFonctions();
	void fonction();
	void listeDeDeclarations();
	void declarations();
	void declarationsPrime();
	void declaration();
	void declarationPrime();
	void declarationSeconde();
	void listeDeParametres();
	void parametres();
	void parametresPrime();
	void parametre();
	void listeInstructions();
	void instruction();
	void instructionPrime();
	void instructionPrime(string); /// SOUHAIL
	string instructionTriple(); /// SOUHAIL
	void instructionSeconde();
	void expression();
	void expressionPrime();
	void expressionLogique();
	void expressionLogiquePrime();
	void expressionSimple();
	string expressionSimplePrime(); /// SOUHAIL
	string terme(); /// SOUHAIL
	string termePrime();
	string termePrioritaire();
	string facteur(); /// SOUHAIL
	int facteurPrime(); 
	void parametresEffectifs();
	void expressions();
	void expressionsPrime();
	void operateurLogique();
	string comparaison();
	void identif();
	void cte();
	friend class ObjectCodeGenerator;
};

