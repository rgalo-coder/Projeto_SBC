
 ;********************************Créditos**************************************
 ;Sistemas Baseados em Conhecimento Prof. Dr. Matelli - UNESP 2020
 ;Grupo 5: David, Rafael, Fábio e Thaís
 ;Versão: 1.0 de 01 de Dezembro de 2020
 ;******************************************************************************

 ;funcoes para passar os dados
 
(deffunction factstostring
	()
	
	(str-cat fact1OK)  
)
 
(deffunction teste
	()
	
	(integer 17.3)
)

 
 
 
 
 
 
 ;Fase 3 	
 ;*********************Fase de Inferência da Plataforma************************

	
 		;*************************Regras de Arquitetura************************
 		
 		;regra 1
 		(defrule R_ARC_C ;Regra da Arquitetura Centralizada
 	
 		(Fase Inferencia_PL)
 	 	(Arquitetura Centralizada)
 	
 		=>
 		
 		(assert (Plataforma CDAQ) (Plataforma CRIO) (Plataforma PXI)) ;ok
 		)
 	
 		;regra 2
 		(defrule R_ARC_D ;Regra da Arquitetura Distribuída
 	
 		(Fase Inferencia_PL)
 	 	(Arquitetura Distribuida)
 	
 		=>
 		
 		(assert (Plataforma CDAQ) (Plataforma CRIO) (Plataforma PXI)) ;ok
 		)
 	
 		;regra 3
 		(defrule R_ARC_E ;Regra da Arquitetura Embarcada
 	
 		(Fase Inferencia_PL)
 	 	(Arquitetura Embarcada)
 	
 		=>
 		
 		(assert (Plataforma CDAQ) (Plataforma CRIO) (Plataforma PXI)) ;ok
 		)
 	
 	
 		;*************************Regras do Orçamento**************************
 		
 		;regra 1
 		(defrule R_OC_P ;Regra do Orçamento Pequeno até U$10K
 	
 		(Fase Inferencia_PL)
 		?PL <- (Plataforma CDAQ|CRIO|PXI)
 	 	?OC <- (Orcamento P)
 	 	?AR <- (Arquitetura Centralizada|Distribuida|Embarcada)
 	
 		=>
 		
 		(retract ?PL)
 		(retract ?AR)
 		(assert (Plataforma CDAQ)) ;ok
 		)
 		
 		;regra 2
 		(defrule R_OC_M ;Regra do Orçamento Médio de U$10K a U$50K 
 	
 		(Fase Inferencia_PL)
 		?PL <- (Plataforma CDAQ|CRIO|PXI)
 	 	?OC <- (Orcamento M)
 	 	?AR <- (Arquitetura Centralizada|Distribuida|Embarcada)
 	
 		=>
 		
 		(retract ?PL)
 		(retract ?AR)
 		(assert (Plataforma CDAQ) (Plataforma CRIO))
 		)
 		
 		;regra 3
 		(defrule R_OC_G ;Regra do Orçamento Grande acima de U$50K  
 	
 	 	(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 	 	?OC <- (Orcamento G)
 	 	?AR <- (Arquitetura Centralizada|Distribuida|Embarcada)
 	
 		=>
 		
 		(retract ?PL)
 		(retract ?AR)
 		(assert (Plataforma CDAQ) (Plataforma CRIO) (Plataforma PXI))
 		)
 		
 		;regra 4
 		(defrule R_OC_V ;Regra do Orçamento "vazio"
 	
 	 	(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 	 	?OC <- (Orcamento void)
 	 	?AR <- (Arquitetura Centralizada|Distribuida|Embarcada)
 	
 		=>
 		
 		(retract ?PL)
 		(retract ?AR)
 		(assert (Plataforma CDAQ) (Plataforma CRIO) (Plataforma PXI) (Orcamento void)) ;aqui ele chuta qualquer uma das 3 plataforma e deixa para decidir no pelo barramento...
 		)
 	
 		
 		;*************************Regras do Barramento**************************
 		
 		;regra 1
 		(defrule R_BR_P ;Regra do Barramento Pequeno (USB)
 	
 		(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 	 	?BR <- (Barramento P)
 	 	
 		=>
 		(retract ?PL)
 		(retract ?BR)
 		(assert (Plataforma CDAQ) (Barramento USB))
 		)
 		
 		;regra 2
 		(defrule R_BR_M ;Regra do Barramento Médio (Ethernet)
 	
 		(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 		?BR <- (Barramento M)
 	 	
 		=>
 		(retract ?PL)
 		(retract ?BR)
 		(assert (Plataforma CRIO) (Plataforma CDAQ) (Barramento Ethernet))
 		)
 
 		;regra 3
 		(defrule R_BR_G ;Regra do Barramento Grande (PXI)
 	
 		(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 		?BR <- (Barramento G)
 		
 		=>
 	
 		(retract ?PL)
 		(retract ?BR)
 		(assert (Plataforma PXI) (Barramento Backlane))
 		
 		)
 		
 		;regra 4
 		(defrule R_BR_V ;Regra do Barramento "vazio" 1
 	
 		(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 		?OC <- (Orcamento M|G)
 	 	?BR <- (Barramento void)
 		
 		=>
 	
 		(retract ?PL)
 		(retract ?BR)
 		(assert (Plataforma CDAQ) (Plataforma CRIO) (Barramento M)) ;aqui ele chuta um tipo de barramento pelo orçamento considerado
 		
 		)
 		
 		;regra 5
 		(defrule R_BR_G ;Regra do Barramento "vazio" 2
 	
 		(Fase Inferencia_PL)
 	 	?PL <- (Plataforma CDAQ|CRIO|PXI)
 		?OC <- (Orcamento P)
 	 	?BR <- (Barramento void)
 		
 		=>
 	
 		(retract ?PL)
 		(retract ?BR)
 		(assert (Plataforma CDAQ) (Barramento P)) ;aqui ele chuta um tipo de barramento pelo orçamento considerado
 		
 		)
 		
 		
 		;*************************Regras de Sincronização***********************
 		
 		
 		
 		
 		
 		;*************************Regras de Integração**************************
 		
 		
 		
 		
 		
 		;*************************Regras da Malha de Controle*******************
 
 		
 		
 		
 		

  
  
  
 ;********************************Créditos**************************************
 ;Sistemas Baseados em Conhecimento Prof. Dr. Matelli - UNESP 2020
 ;Grupo 5: David, Rafael, Fábio e Thaís
 ;Versão: 1.1 de XX de Novembro de 2020
 ;******************************************************************************

  