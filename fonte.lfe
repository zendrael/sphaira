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


;

