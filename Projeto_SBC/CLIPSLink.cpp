#include "pch.h"

extern "C"
{
#include "d:\Documents\Google Drive\Mestrado\SBC\CLIPS\Projects\Source\CLIPS\clips.h"
#include "CLIPSDLL.h"  // tem q estar  dentro do externt C ou nao encontra a DLL do clips

}

#include "CLIPSLink.h"



int CCLIPSLink::runCLIPS()
{
    DATA_OBJECT outputValue{}; //receive data from Eval

    int eval = 0; // receive DEBUG data from Eval functions

    void* theEnv;   
    theEnv = __CreateEnvironment(); //create environment

    __EnvClear(theEnv);
    int envload = __EnvLoad(theEnv,"projeto_sbc para cpp.clp");  //clear and load file

    int watch = __EnvEval(theEnv, "(watch all)", &outputValue);
    int dribble = __EnvEval(theEnv, "(dribble-on log.txt)", &outputValue);  //log CLIPS debug data to log.txt
   
    __EnvReset(theEnv);   // reset environment
 
    //start to ASSERT facts into environment

    if (m_ARQ == 0) eval = __EnvEval(theEnv, "(assert (Arquitetura Centralizada))", &outputValue);
    if (m_ARQ == 1) eval = __EnvEval(theEnv, "(assert (Arquitetura Distribuida))", &outputValue);
    if (m_ARQ == 2) eval = __EnvEval(theEnv, "(assert (Arquitetura Embarcada))", &outputValue);

    if (m_OC == 0) eval = __EnvEval(theEnv, "(assert (Orcamento P))", &outputValue);
    if (m_OC == 1) eval = __EnvEval(theEnv, "(assert (Orcamento M))", &outputValue);
    if (m_OC == 2) eval = __EnvEval(theEnv, "(assert (Orcamento G))", &outputValue);

    if (m_VLC_BR == 0) eval = __EnvEval(theEnv, "(assert (Barramento P))", &outputValue);
    if (m_VLC_BR == 1) eval = __EnvEval(theEnv, "(assert (Barramento M))", &outputValue);
    if (m_VLC_BR == 2) eval = __EnvEval(theEnv, "(assert (Barramento G))", &outputValue);

    if (m_S_I == 0) eval = __EnvEval(theEnv, "(assert (Sincronizacao S))", &outputValue);
    if (m_S_I == 1) eval = __EnvEval(theEnv, "(assert (Sincronizacao N))", &outputValue);

    if (m_P_I == 0) eval = __EnvEval(theEnv, "(assert (Integracao S))", &outputValue);
    if (m_P_I == 1) eval = __EnvEval(theEnv, "(assert (Integracao N))", &outputValue);

    if (m_M_C == 0) eval = __EnvEval(theEnv, "(assert (Malha Controle N))", &outputValue);
    if (m_M_C == 1) eval = __EnvEval(theEnv, "(assert (Malha Controle S))", &outputValue);
    if (m_M_C == 2) eval = __EnvEval(theEnv, "(assert (Malha Controle C))", &outputValue);

    // assert das malhas de controle
    char AssertInput[50]{};
    
    AssertIntValue(i_V_E_S, _T("Strain"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_E_T, _T("Temperatura"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_E_SV, _T("Som_Vibracao"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_E_E, _T("Encoder"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_E_C, _T("Corrente_Entrada"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_E_TS, _T("Tensao_Entrada"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_E_D, _T("Digital_Entrada"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_S_C, _T("Corrente_Saida"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_S_TS, _T("Tensao_Saida"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);
    AssertIntValue(i_V_S_D, _T("Digital_Saida"), AssertInput);
    eval = __EnvEval(theEnv, AssertInput, &outputValue);

    //inicia fase de inferenccia

     eval = __EnvEval(theEnv, "(assert (Fase Inferencia_PL))", &outputValue);
   
     eval = __EnvEval(theEnv, "(rules)", &outputValue);

     int numrules;
     numrules = __EnvRun(theEnv, -1);


     //TODO ---------- Recebimento das  respostas  do clips  atraves de funcoes
    // obter respostas de texto
    int eval8 = __EnvEval(theEnv, "(factstostring)", &outputValue);
    const char* stfacts = DOToString(outputValue);

     // obter respostas numbericas
     int eval9 = __EnvEval(theEnv, "(teste)", &outputValue);
     int result = DOToInteger(outputValue);

     //-------------------- fim do recebimento das repostas

     eval = __EnvEval(theEnv, "(facts)", &outputValue);
     eval = __EnvEval(theEnv, "(dribble-off)", &outputValue);
       
    __DestroyEnvironment(theEnv);
    

    return 1;
}

void CCLIPSLink::AssertIntValue(int i_V_E_S, CString CLIPSVariable, char *AssertInputAdd)
{
    

    WCHAR buffer[5];
    _itot_s(i_V_E_S, buffer, 5, 10);
    CString AssertString;
    AssertString = _T("(assert (");
    AssertString += CLIPSVariable;
    AssertString += _T(" ");
    AssertString += buffer;
    AssertString += _T(" ))");

    int i = 0;
    for (; i < AssertString.GetLength(); i++)
        AssertInputAdd[i] = (char)*(AssertString.GetBuffer() + i);
    AssertString.ReleaseBuffer();

}
