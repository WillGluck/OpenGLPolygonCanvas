README FILE



. Modo de usar:
	

Passo a passo:
		

	Ao iniciar a aplicação ela se encontra em modo de manipulação.
		
	Aperte 'q' para entrar em modo de edição.
		
	Aperta 'a' se desejar criar um polígono aberto.
		
	Efetue cliques na tela para adicionar os vértices.
		
	Aperte 'c' (color) se desejar mudar de cor.
		
	Ao finalizar seu polígono aperte: 'f' (finalize) para finalizar o polígono.
										  
					  'q' para finalizar o polígono e voltar ao modo de manipulação.
										  					  'i' (insert) para finalizar o polígono e inserir um filho.
		
	Voltando ao modo de manipulação é possível selecionar polígonos com o clique.
		
	Aperte 'd' (delete) para remover o polígono.
		
	Clicar e arrastar realiza uma translação.
		
	Clicar e apertar 'r' (rotate) realiza uma rotação.
		
	Clicar e apertar 's' (smaller) realiza uma diminuição da escala.
		
	Clicar e apertar 'b' (bigger) realiza um aumento da escala.
		
	Clique próximo de um vértice para seleciná-lo. A distância definida foi de 20.0f posições.
		
	Mova o vértice segurando o botão de clique e movendo o mouse. Aperte 'v' (vertex) para remover o vértice.
		
	

Mapa de teclas:
		 

	'q' Muda o modo de edição de "Inserção" para "Manipulação".
		 
	'a' Alterna o tipo de polígono entre aberto e fechado.
		 
	'r' Rotaciona um polígono se ele estiver selecionado.
		 
	'b' Aumenta a escala de um polígono se ele estiver selecionado.
		 
	's' Diminui a escala de um polígono se ele estiver selecionado.	
		 
	'd' Remove um polígono se ele estiver selecionado.
		 
	'f' Finaliza a inserção de um polígono.
		 
	'i' Adiciona um polígono filho a um polígono que está selecionado ou que está sendo inserido.
		 
	'c' Muda a cor do polígono de forma randômica.
		 
	'v' Remove um vértice que esteja selecionado.



. Tentativa de atualizar BBox após transformações:

	

	Não foi requisito definido pelo professor, mas tentamos realizar a atualização da BBox, scanLine e detecção de seleção de vértice após transformações.
 A técnica que adotamos, apesar de não ser a correta, foi a manter no objeto gráfico além de sua lista de vértices, que só eram alterados
 com a seleção e movimentação de vértices, uma lista com os vértices transformados, desenhando a BBox sempre na posição real do objeto, ignorando 
	as matrizes de transformação. A transformação era passado de pai pra filho, sendo assim os filhos sempre consideravam todas as transformações.
 Existe no cpp do objeto gráfico a possibilidade de ignorar essa tentativa de solução, indicada no código. Basta comentar uma das seções e
	descomentar a outra, em dois pontos do arquivo GraphicObject.cpp. O único problema encontrado na solução é comportamento estranho do mouse após seleção de vértices e polígonos depois de inúmeras transformações.
