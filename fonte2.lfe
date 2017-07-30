start['bgcolor="#e2e2e2"']:

	div['align="center"']: 
		print('<h2><b>EMPRESAS XYZ DO BRASIL</b></h2>') 
	;
	
	print('<br><hr><br>')
	
	//menu
	table['width="100%" cellspacing="10"'] :
		row :
			col['width="10"'] : link('fonte.lfe', 'Sistema') ;
			col['width="10"'] : link('fonte2.lfe', 'Cadastros') ;
			col['width="10"'] : link('fonte3.lfe', 'Ferramentas') ;
			col: div['align="right"'] : link('fonte2.lfe', 'Sair') ; ;
		;
	;
	
	print('<br>')
	//context
	print('<h2>Informacoes do Sistema</h2>')
	print('<br><br>')
	div ['align="center"'] :
	
		table['cellpadding="3"']:
			row:
				col:
					print('<b>Versao: </b>')
				;
				col:
					print('0.0.1')	
				;
			;
			row:
				col:
					print('<b>Login: </b>')
				;
				col:
					edit('login', 45)
				;
			;
			row:
				col:
					print('<b>Senha: </b>')
				;
				col:
					edit('senha', 45)
				;
			;
			row:
				col['colspan="2" align="center"']:
					button('btn',' Confirmar ')
				;
			;
		;
		
	;

;


