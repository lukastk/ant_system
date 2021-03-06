/*
 * This file automatically produced by /usr/local/Wolfram/Mathematica/10.4/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions//wsprep from:
 *	tsp_ants_mathematica.tm
 * mprep Revision 18 Copyright (c) Wolfram Research, Inc. 1990-2013
 */

#define MPREP_REVISION 18

#include "wstp.h"

int WSAbort = 0;
int WSDone  = 0;
long WSSpecialCharacter = '\0';

WSLINK stdlink = 0;
WSEnvironment stdenv = 0;
#if WSINTERFACE >= 3
WSYieldFunctionObject stdyielder = (WSYieldFunctionObject)0;
WSMessageHandlerObject stdhandler = (WSMessageHandlerObject)0;
#else
WSYieldFunctionObject stdyielder = 0;
WSMessageHandlerObject stdhandler = 0;
#endif /* WSINTERFACE >= 3 */

/********************************* end header *********************************/


int startSimulation P(( double * _tp1, long _tpl1, double _tp2, double _tp3, double _tp4, double _tp5, double _tp6));

#if WSPROTOTYPES
static int _tr0( WSLINK mlp)
#else
static int _tr0(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	double * _tp1;
	long _tpl1;
	double _tp2;
	double _tp3;
	double _tp4;
	double _tp5;
	double _tp6;
	int _rp0;
	if ( ! WSGetRealList( mlp, &_tp1, &_tpl1) ) goto L0;
	if ( ! WSGetReal( mlp, &_tp2) ) goto L1;
	if ( ! WSGetReal( mlp, &_tp3) ) goto L2;
	if ( ! WSGetReal( mlp, &_tp4) ) goto L3;
	if ( ! WSGetReal( mlp, &_tp5) ) goto L4;
	if ( ! WSGetReal( mlp, &_tp6) ) goto L5;
	if ( ! WSNewPacket(mlp) ) goto L6;

	_rp0 = startSimulation(_tp1, _tpl1, _tp2, _tp3, _tp4, _tp5, _tp6);

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);
L6: L5: L4: L3: L2: L1:	WSReleaseReal64List(mlp, _tp1, _tpl1);

L0:	return res;
} /* _tr0 */


double updateSimulation P(( void));

#if WSPROTOTYPES
static int _tr1( WSLINK mlp)
#else
static int _tr1(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	double _rp0;
	if ( ! WSNewPacket(mlp) ) goto L0;

	_rp0 = updateSimulation();

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutReal( mlp, _rp0);

L0:	return res;
} /* _tr1 */


int updateSimulation P(( int _tp1));

#if WSPROTOTYPES
static int _tr2( WSLINK mlp)
#else
static int _tr2(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	int _tp1;
	int _rp0;
	if ( ! WSGetInteger( mlp, &_tp1) ) goto L0;
	if ( ! WSNewPacket(mlp) ) goto L1;

	_rp0 = updateSimulation(_tp1);

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);
L1: 
L0:	return res;
} /* _tr2 */


void getEdgeTraces P(( void));

#if WSPROTOTYPES
static int _tr3( WSLINK mlp)
#else
static int _tr3(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	if ( ! WSNewPacket(mlp) ) goto L0;
	if( !mlp) return res; /* avoid unused parameter warning */

	getEdgeTraces();

	res = 1;

L0:	return res;
} /* _tr3 */


int addAnt P(( int _tp1));

#if WSPROTOTYPES
static int _tr4( WSLINK mlp)
#else
static int _tr4(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	int _tp1;
	int _rp0;
	if ( ! WSGetInteger( mlp, &_tp1) ) goto L0;
	if ( ! WSNewPacket(mlp) ) goto L1;

	_rp0 = addAnt(_tp1);

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);
L1: 
L0:	return res;
} /* _tr4 */


int getNumberOfAnts P(( void));

#if WSPROTOTYPES
static int _tr5( WSLINK mlp)
#else
static int _tr5(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	int _rp0;
	if ( ! WSNewPacket(mlp) ) goto L0;

	_rp0 = getNumberOfAnts();

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);

L0:	return res;
} /* _tr5 */


int getNumberOfTowns P(( void));

#if WSPROTOTYPES
static int _tr6( WSLINK mlp)
#else
static int _tr6(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	int _rp0;
	if ( ! WSNewPacket(mlp) ) goto L0;

	_rp0 = getNumberOfTowns();

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);

L0:	return res;
} /* _tr6 */


int getNumberOfCycles P(( void));

#if WSPROTOTYPES
static int _tr7( WSLINK mlp)
#else
static int _tr7(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	int _rp0;
	if ( ! WSNewPacket(mlp) ) goto L0;

	_rp0 = getNumberOfCycles();

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);

L0:	return res;
} /* _tr7 */


void getAntPathHistories P(( void));

#if WSPROTOTYPES
static int _tr8( WSLINK mlp)
#else
static int _tr8(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	if ( ! WSNewPacket(mlp) ) goto L0;
	if( !mlp) return res; /* avoid unused parameter warning */

	getAntPathHistories();

	res = 1;

L0:	return res;
} /* _tr8 */


void getAntPathLengthHistories P(( void));

#if WSPROTOTYPES
static int _tr9( WSLINK mlp)
#else
static int _tr9(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	if ( ! WSNewPacket(mlp) ) goto L0;
	if( !mlp) return res; /* avoid unused parameter warning */

	getAntPathLengthHistories();

	res = 1;

L0:	return res;
} /* _tr9 */


int endSimulation P(( void));

#if WSPROTOTYPES
static int _tr10( WSLINK mlp)
#else
static int _tr10(mlp) WSLINK mlp;
#endif
{
	int	res = 0;
	int _rp0;
	if ( ! WSNewPacket(mlp) ) goto L0;

	_rp0 = endSimulation();

	res = WSAbort ?
		WSPutFunction( mlp, "Abort", 0) : WSPutInteger( mlp, _rp0);

L0:	return res;
} /* _tr10 */


static struct func {
	int   f_nargs;
	int   manual;
	int   (*f_func)P((WSLINK));
	const char  *f_name;
	} _tramps[11] = {
		{ 6, 0, _tr0, "startSimulation" },
		{ 0, 0, _tr1, "updateSimulation" },
		{ 1, 0, _tr2, "updateSimulation" },
		{ 0, 0, _tr3, "getEdgeTraces" },
		{ 1, 0, _tr4, "addAnt" },
		{ 0, 0, _tr5, "getNumberOfAnts" },
		{ 0, 0, _tr6, "getNumberOfTowns" },
		{ 0, 0, _tr7, "getNumberOfCycles" },
		{ 0, 0, _tr8, "getAntPathHistories" },
		{ 0, 0, _tr9, "getAntPathLengthHistories" },
		{ 0, 0, _tr10, "endSimulation" }
		};

static const char* evalstrs[] = {
	"StartSimulation::usage = \"StartSimulation[edgeDistancesData_List",
	", baseTrail_Real, alpha_Real, beta_Real, q_Real, pheromoneDecay_",
	"Real] initializes the simulation with the given parameters\"",
	(const char*)0,
	"UpdateSimulation::usage = \"UpdateSimulation[] updates the simula",
	"tion for a single cycle.\\nUpdateSimulation[ticks_Integer] updates",
	" the simulation for the specified amount of cycles.\"",
	(const char*)0,
	"GetEdgeTraces::usage = \"GetEdgeTraces[] returns a matrix of the ",
	"level of trace on each edge.\"",
	(const char*)0,
	"AddAnt::usage = \"AddAnt[town_Integer] adds an ant to the specifi",
	"ed town.\"",
	(const char*)0,
	"GetNumberOfAnts::usage = \"GetNumberOfAnts[] returns the number o",
	"f ants in the simulation.\"",
	(const char*)0,
	"GetNumberOfTowns::usage = \"GetNumberOfTowns[] returns the number",
	" of towns in the simulation.\"",
	(const char*)0,
	"GetNumberOfTowns::usage = \"GetNumberOfCycles[] returns the numbe",
	"r of cycles that has passed so far in the simulation.\"",
	(const char*)0,
	"GetAntPathHistories::usage = \"GetAntPathHistories[] returns a li",
	"st of all paths that has been traversed by the ants, in the simu",
	"lation so far. Calling the function will flush the path history.",
	"\"",
	(const char*)0,
	"GetAntPathLengthHistories::usage = \"GetAntPathLengthHistories[] ",
	"returns a list of all lengths of the paths that has been travers",
	"ed by the ants, in the simulation so far. Calling the function w",
	"ill flush the path length history.\"",
	(const char*)0,
	"EndSimulation::usage = \"EndSimulation[] ends the simulation.\"",
	(const char*)0,
	(const char*)0
};
#define CARDOF_EVALSTRS 10

static int _definepattern P(( WSLINK, char*, char*, int));

static int _doevalstr P(( WSLINK, int));

int  _WSDoCallPacket P(( WSLINK, struct func[], int));


#if WSPROTOTYPES
int WSInstall( WSLINK mlp)
#else
int WSInstall(mlp) WSLINK mlp;
#endif
{
	int _res;
	_res = WSConnect(mlp);
	if (_res) _res = _definepattern(mlp, (char *)"StartSimulation[edgeDistancesData_List, baseTrail_Real, alpha_Real, beta_Real, q_Real, pheromoneDecay_Real]", (char *)"{ edgeDistancesData, baseTrail, alpha, beta, q, pheromoneDecay }", 0);
	if (_res) _res = _doevalstr( mlp, 0);
	if (_res) _res = _definepattern(mlp, (char *)"UpdateSimulation[]", (char *)"{ }", 1);
	if (_res) _res = _definepattern(mlp, (char *)"UpdateSimulation[ticks_Integer]", (char *)"{ ticks }", 2);
	if (_res) _res = _doevalstr( mlp, 1);
	if (_res) _res = _definepattern(mlp, (char *)"GetEdgeTraces[]", (char *)"{ }", 3);
	if (_res) _res = _doevalstr( mlp, 2);
	if (_res) _res = _definepattern(mlp, (char *)"AddAnt[town_Integer]", (char *)"{ town }", 4);
	if (_res) _res = _doevalstr( mlp, 3);
	if (_res) _res = _definepattern(mlp, (char *)"GetNumberOfAnts[]", (char *)"{ }", 5);
	if (_res) _res = _doevalstr( mlp, 4);
	if (_res) _res = _definepattern(mlp, (char *)"GetNumberOfTowns[]", (char *)"{ }", 6);
	if (_res) _res = _doevalstr( mlp, 5);
	if (_res) _res = _definepattern(mlp, (char *)"GetNumberOfCycles[]", (char *)"{ }", 7);
	if (_res) _res = _doevalstr( mlp, 6);
	if (_res) _res = _definepattern(mlp, (char *)"GetAntPathHistories[]", (char *)"{ }", 8);
	if (_res) _res = _doevalstr( mlp, 7);
	if (_res) _res = _definepattern(mlp, (char *)"GetAntPathLengthHistories[]", (char *)"{ }", 9);
	if (_res) _res = _doevalstr( mlp, 8);
	if (_res) _res = _definepattern(mlp, (char *)"EndSimulation[]", (char *)"{ }", 10);
	if (_res) _res = _doevalstr( mlp, 9);
	if (_res) _res = WSPutSymbol( mlp, "End");
	if (_res) _res = WSFlush( mlp);
	return _res;
} /* WSInstall */


#if WSPROTOTYPES
int WSDoCallPacket( WSLINK mlp)
#else
int WSDoCallPacket( mlp) WSLINK mlp;
#endif
{
	return _WSDoCallPacket( mlp, _tramps, 11);
} /* WSDoCallPacket */

/******************************* begin trailer ********************************/

#ifndef EVALSTRS_AS_BYTESTRINGS
#	define EVALSTRS_AS_BYTESTRINGS 1
#endif


#if CARDOF_EVALSTRS
#if WSPROTOTYPES
static int  _doevalstr( WSLINK mlp, int n)
#else
static int  _doevalstr( mlp, n)
	 WSLINK mlp; int n;
#endif
{
	long bytesleft, charsleft, bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
	long charsnow;
#endif
	char **s, **p;
	char *t;

	s = (char **)evalstrs;
	while( n-- > 0){
		if( *s == 0) break;
		while( *s++ != 0){}
	}
	if( *s == 0) return 0;
	bytesleft = 0;
	charsleft = 0;
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft += bytesnow;
		charsleft += bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
		t = *p;
		charsleft -= WSCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
#endif
		++p;
	}


	WSPutNext( mlp, WSTKSTR);
#if EVALSTRS_AS_BYTESTRINGS
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		WSPut8BitCharacters( mlp, bytesleft, (unsigned char*)*p, bytesnow);
		++p;
	}
#else
	WSPut7BitCount( mlp, charsleft, bytesleft);
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		t = *p;
		charsnow = bytesnow - WSCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
		charsleft -= charsnow;
		WSPut7BitCharacters(  mlp, charsleft, *p, bytesnow, charsnow);
		++p;
	}
#endif
	return WSError( mlp) == WSEOK;
}
#endif /* CARDOF_EVALSTRS */


#if WSPROTOTYPES
static int  _definepattern( WSLINK mlp, char *patt, char *args, int func_n)
#else
static int  _definepattern( mlp, patt, args, func_n)
	WSLINK  mlp;
	char  *patt, *args;
	int    func_n;
#endif
{
	WSPutFunction( mlp, "DefineExternal", (long)3);
	  WSPutString( mlp, patt);
	  WSPutString( mlp, args);
	  WSPutInteger( mlp, func_n);
	return !WSError(mlp);
} /* _definepattern */


#if WSPROTOTYPES
int _WSDoCallPacket( WSLINK mlp, struct func functable[], int nfuncs)
#else
int _WSDoCallPacket( mlp, functable, nfuncs)
	WSLINK mlp;
	struct func functable[];
	int nfuncs;
#endif
{
#if WSINTERFACE >= 4
	int len;
#else
	long len;
#endif
	int n, res = 0;
	struct func* funcp;

	if( ! WSGetInteger( mlp, &n) ||  n < 0 ||  n >= nfuncs) goto L0;
	funcp = &functable[n];

	if( funcp->f_nargs >= 0
#if WSINTERFACE >= 4
	&& ( ! WSTestHead(mlp, "List", &len)
#else
	&& ( ! WSCheckFunction(mlp, "List", &len)
#endif
	     || ( !funcp->manual && (len != funcp->f_nargs))
	     || (  funcp->manual && (len <  funcp->f_nargs))
	   )
	) goto L0;

	stdlink = mlp;
	res = (*funcp->f_func)( mlp);

L0:	if( res == 0)
		res = WSClearError( mlp) && WSPutSymbol( mlp, "$Failed");
	return res && WSEndPacket( mlp) && WSNewPacket( mlp);
} /* _WSDoCallPacket */


#if WSPROTOTYPES
wsapi_packet WSAnswer( WSLINK mlp)
#else
wsapi_packet WSAnswer( mlp)
	WSLINK mlp;
#endif
{
	wsapi_packet pkt = 0;
#if WSINTERFACE >= 4
	int waitResult;

	while( ! WSDone && ! WSError(mlp)
		&& (waitResult = WSWaitForLinkActivity(mlp),waitResult) &&
		waitResult == WSWAITSUCCESS && (pkt = WSNextPacket(mlp), pkt) &&
		pkt == CALLPKT)
	{
		WSAbort = 0;
		if(! WSDoCallPacket(mlp))
			pkt = 0;
	}
#else
	while( !WSDone && !WSError(mlp) && (pkt = WSNextPacket(mlp), pkt) && pkt == CALLPKT){
		WSAbort = 0;
		if( !WSDoCallPacket(mlp)) pkt = 0;
	}
#endif
	WSAbort = 0;
	return pkt;
} /* WSAnswer */



/*
	Module[ { me = $ParentLink},
		$ParentLink = contents of RESUMEPKT;
		Message[ MessageName[$ParentLink, "notfe"], me];
		me]
*/

#if WSPROTOTYPES
static int refuse_to_be_a_frontend( WSLINK mlp)
#else
static int refuse_to_be_a_frontend( mlp)
	WSLINK mlp;
#endif
{
	int pkt;

	WSPutFunction( mlp, "EvaluatePacket", 1);
	  WSPutFunction( mlp, "Module", 2);
	    WSPutFunction( mlp, "List", 1);
		  WSPutFunction( mlp, "Set", 2);
		    WSPutSymbol( mlp, "me");
	        WSPutSymbol( mlp, "$ParentLink");
	  WSPutFunction( mlp, "CompoundExpression", 3);
	    WSPutFunction( mlp, "Set", 2);
	      WSPutSymbol( mlp, "$ParentLink");
	      WSTransferExpression( mlp, mlp);
	    WSPutFunction( mlp, "Message", 2);
	      WSPutFunction( mlp, "MessageName", 2);
	        WSPutSymbol( mlp, "$ParentLink");
	        WSPutString( mlp, "notfe");
	      WSPutSymbol( mlp, "me");
	    WSPutSymbol( mlp, "me");
	WSEndPacket( mlp);

	while( (pkt = WSNextPacket( mlp), pkt) && pkt != SUSPENDPKT)
		WSNewPacket( mlp);
	WSNewPacket( mlp);
	return WSError( mlp) == WSEOK;
}


#if WSPROTOTYPES
#if WSINTERFACE >= 3
int WSEvaluate( WSLINK mlp, char *s)
#else
int WSEvaluate( WSLINK mlp, charp_ct s)
#endif /* WSINTERFACE >= 3 */
#else
int WSEvaluate( mlp, s)
	WSLINK mlp;
#if WSINTERFACE >= 3
	char *s;
#else
	charp_ct s;
#endif /* WSINTERFACE >= 3 */
#endif
{
	if( WSAbort) return 0;
	return WSPutFunction( mlp, "EvaluatePacket", 1L)
		&& WSPutFunction( mlp, "ToExpression", 1L)
		&& WSPutString( mlp, s)
		&& WSEndPacket( mlp);
} /* WSEvaluate */


#if WSPROTOTYPES
#if WSINTERFACE >= 3
int WSEvaluateString( WSLINK mlp, char *s)
#else
int WSEvaluateString( WSLINK mlp, charp_ct s)
#endif /* WSINTERFACE >= 3 */
#else
int WSEvaluateString( mlp, s)
	WSLINK mlp;
#if WSINTERFACE >= 3
	char *s;
#else
	charp_ct s;
#endif /* WSINTERFACE >= 3 */
#endif
{
	int pkt;
	if( WSAbort) return 0;
	if( WSEvaluate( mlp, s)){
		while( (pkt = WSAnswer( mlp), pkt) && pkt != RETURNPKT)
			WSNewPacket( mlp);
		WSNewPacket( mlp);
	}
	return WSError( mlp) == WSEOK;
} /* WSEvaluateString */


#if WSINTERFACE >= 3
#if WSPROTOTYPES
void WSDefaultHandler( WSLINK mlp, int message, int n)
#else
void WSDefaultHandler( mlp, message, n)
	WSLINK mlp;
	int message, n;
#endif
#else
#if WSPROTOTYPES
void WSDefaultHandler( WSLINK mlp, unsigned long message, unsigned long n)
#else
void WSDefaultHandler( mlp, message, n)
	WSLINK mlp;
	unsigned long message, n;
#endif
#endif /* WSINTERFACE >= 3 */
{
	switch (message){
	case WSTerminateMessage:
		WSDone = 1;
	case WSInterruptMessage:
	case WSAbortMessage:
		WSAbort = 1;
	default:
		return;
	}
}

#if WSPROTOTYPES
#if WSINTERFACE >= 3
static int _WSMain( char **argv, char **argv_end, char *commandline)
#else
static int _WSMain( charpp_ct argv, charpp_ct argv_end, charp_ct commandline)
#endif /* WSINTERFACE >= 3 */
#else
static int _WSMain( argv, argv_end, commandline)
#if WSINTERFACE >= 3
  char **argv, argv_end;
  char *commandline;
#else
  charpp_ct argv, argv_end;
  charp_ct commandline;
#endif /* WSINTERFACE >= 3 */
#endif
{
	WSLINK mlp;
#if WSINTERFACE >= 3
	int err;
#else
	long err;
#endif /* WSINTERFACE >= 3 */

#if WSINTERFACE >= 4
	if( !stdenv)
		stdenv = WSInitialize( (WSEnvironmentParameter)0);
#else
	if( !stdenv)
		stdenv = WSInitialize( (WSParametersPointer)0);
#endif

	if( stdenv == (WSEnvironment)0) goto R0;

#if WSINTERFACE >= 3
	if( !stdhandler)
		stdhandler = (WSMessageHandlerObject)WSDefaultHandler;
#else
	if( !stdhandler)
		stdhandler = WSCreateMessageHandler( stdenv, WSDefaultHandler, 0);
#endif /* WSINTERFACE >= 3 */


	mlp = commandline
		? WSOpenString( stdenv, commandline, &err)
#if WSINTERFACE >= 3
		: WSOpenArgcArgv( stdenv, (int)(argv_end - argv), argv, &err);
#else
		: WSOpenArgv( stdenv, argv, argv_end, &err);
#endif
	if( mlp == (WSLINK)0){
		WSAlert( stdenv, WSErrorString( stdenv, err));
		goto R1;
	}

	if( stdyielder) WSSetYieldFunction( mlp, stdyielder);
	if( stdhandler) WSSetMessageHandler( mlp, stdhandler);

	if( WSInstall( mlp))
		while( WSAnswer( mlp) == RESUMEPKT){
			if( ! refuse_to_be_a_frontend( mlp)) break;
		}

	WSClose( mlp);
R1:	WSDeinitialize( stdenv);
	stdenv = (WSEnvironment)0;
R0:	return !WSDone;
} /* _WSMain */


#if WSPROTOTYPES
#if WSINTERFACE >= 3
int WSMainString( char *commandline)
#else
int WSMainString( charp_ct commandline)
#endif /* WSINTERFACE >= 3 */
#else
#if WSINTERFACE >= 3
int WSMainString( commandline)  char *commandline;
#else
int WSMainString( commandline)  charp_ct commandline;
#endif /* WSINTERFACE >= 3 */
#endif
{
	return _WSMain( (charpp_ct)0, (charpp_ct)0, commandline);
}

#if WSPROTOTYPES
int WSMainArgv( char** argv, char** argv_end) /* note not FAR pointers */
#else
int WSMainArgv( argv, argv_end)  char **argv, **argv_end;
#endif
{   
	static char FAR * far_argv[128];
	int count = 0;
	
	while(argv < argv_end)
		far_argv[count++] = *argv++;
		 
	return _WSMain( far_argv, far_argv + count, (charp_ct)0);

}

#if WSPROTOTYPES
#if WSINTERFACE >= 3
int WSMain( int argc, char **argv)
#else
int WSMain( int argc, charpp_ct argv)
#endif /* WSINTERFACE >= 3 */
#else
#if WSINTERFACE >= 3
int WSMain( argc, argv) int argc; char **argv;
#else
int WSMain( argc, argv) int argc; charpp_ct argv;
#endif /* WSINTERFACE >= 3 */
#endif
{
#if WSINTERFACE >= 3
 	return _WSMain( argv, argv + argc, (char *)0);
#else
 	return _WSMain( argv, argv + argc, (charp_ct)0);
#endif /* WSINTERFACE >= 3 */
}
 
