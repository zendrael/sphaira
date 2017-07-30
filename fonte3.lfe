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
	print('<h2>Teste de layout</h2>')
	print('<br><br>')
	div ['align="center"'] :
	
		table['cellpadding="3" width="500" height="300"']:
			row:
				col['colspan="1" rowspan="2" bgcolor="#FF0000"']:
					print('<br><br><br><br><br><br><br><br>')
				;
				col['colspan="1" rowspan="2" bgcolor="#00FF00"']:
					print('<br><br><br><br><br><br><br><br><br><br>')
				;
			;
			row:
				col['bgcolor="#999999"']:
					print('<br><br><br><br><br><br><br><br><br><br>')
				;
				col['colspan="1" rowspan="2" bgcolor="#0000FF"']:
					print('<br><br><br><br><br><br><br><br><br><br>')
				;
			;
			row:
				col['colspan="2" rowspan="1" bgcolor="#ff6600"']:
					print('<br><br><br><br><br><br><br><br><br><br>')
				;
			;
		;
		
	;

;


