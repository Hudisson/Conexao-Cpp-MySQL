
/*Este código tem o objetivo de realizar uma conexão a um banco de dados MySQL*/

#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <windows.h> 
#include "mysql\mysql.h"

using namespace std;

MYSQL_RES *result;
MYSQL *conexao = mysql_init(NULL);

int main(){
	
	setlocale(LC_ALL,"portuguese");

	if ( mysql_real_connect(conexao, "localhost", "root", "", "meu_db", 3306, NULL, 0) ){
		cout << "\nConexao ao banco realizada com sucesso!\n";
		
		char opc;
		cout << "Deseja continuar? [S/N]";
		cin >> opc;
		if((opc == 's') or (opc == 'S')){
			system("cls");
			cout <<"\n**************** LISTA DE CONTATOS *******************\n";
	
			if(mysql_query(conexao, "SELECT * FROM contatos") == 0){//
			
				result = mysql_store_result(conexao);
			
				if(result !=NULL){
					int linhas = mysql_num_rows(result);
				
					while(linhas){
						 MYSQL_ROW row = mysql_fetch_row(result);
					 
					 	cout << "\n Nome....: " << row[1] << endl;
					 	cout << "\n E-mail..: " << row[2] << endl;
					 	cout << "\n Telefone: " << row[3] << endl;
					 
					 	cout <<"\n========================================\n";
					 
					 	linhas --;	 
			    	}
			
			   		system("pause");
				
				}else {
					cout << "\nErro de Busca!\n";
					system("pause");
				}
			
				return 0;
			}else{
				cout << "Falha na busca - :";
				cout << mysql_error(conexao) << "\n\n";
				system("pause");
			}
		}

	}else {
		cout << "Falha de conexao\n";
		printf("Erro %d : %s\n", mysql_errno(conexao), mysql_error(conexao),"\n\n");
		system("pause");
	}
system("pause");
return 0;
}
