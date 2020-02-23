#include "__cf_RudderActuatorChannel_control_arx.h"
#include <math.h>
#include "RudderActuatorChannel_control_arx_acc.h"
#include "RudderActuatorChannel_control_arx_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T nxqvjqjijx ;
real_T * lastU ; real_T fmwx4omvby ; real_T jnz3yg2px3 ; real_T cyob4x5wfb ;
real_T jpoleaj2gp ; real_T pv5gxysp0r ; real_T csjn0hjdfw ; real_T ariiaqsscm
; real_T i1ujgst3xa ; real_T dho01whcev ; real_T g2qkllsoih ; real_T
piih1jylvv ; real_T cyryjohugw ; real_T a2xkjs2hqc ; real_T domwsj3q21 ;
real_T a1ki3pyacd ; real_T dewu3oxpw1 ; real_T iz00jymqcq ; real_T mvzolbzi05
; real_T pma3w2k00n ; real_T hd2ydhacvd ; real_T epv0krrh3n ; real_T
b4illzlho4 ; real_T dggdeh524t ; real_T jqihxm2vua ; real_T eb414jgbzr ;
real_T axcfma0fve ; real_T i12mueccf4 ; real_T g1l41ivyrr ; real_T nbgr2nlpuq
; real_T kw5o4xp3hz ; real_T pj45m5jpuh ; real_T onwcskjgvk ; real_T
etouizavme ; real_T hl04qsrbxl ; real_T c3d3idtpox ; real_T hoboum2epr ;
real_T poqj435wmg ; real_T lvlfpaom5x ; real_T mmmmhtev22 ; real_T o11p3wlknv
; real_T ij030g3mbk ; real_T nhcndasiec ; real_T bo3vs0ki42 ; real_T
dv1r4o0xin ; real_T iwfb0w0i0z ; real_T kvg3fbdoel ; real_T jo3flk0tmt ;
real_T fdbsfvztlu ; real_T iy5lkqckc2 ; real_T hueh1tpvdz ; real_T b3kbxqsduk
; real_T ib4tdkspee ; real_T cehrujfj4k ; real_T j54pjfo1kj ; real_T
flauz2kzwa ; real_T od3uzdjide ; real_T lf0zlayt10 ; real_T o5h4apqaqz ;
real_T nkpl5b0yb5 ; real_T hq2rjrnh5a ; real_T dp1df2xg0i ; real_T bgoektrore
; real_T mqepf30xlr ; real_T ckqcehizdn ; real_T gem3xqzrlf ; real_T
pygprsuz1b ; real_T dbvvkcgiuo [ 3 ] ; real_T ms44qdxwdl ; real_T b5kdxz2cpr
; real_T i3jr05mlql ; real_T im0mupdqxh ; real_T nwe3le3y0t ; real_T
akk0clwswf ; real_T hhiuns2uat ; real_T e21lkz4bbc ; real_T nkij1zvx4o ;
real_T ae2dep1oyr ; real_T bcyur5ht2d ; real_T ilmfw3a43s ; real_T l5uluf1r3z
; int32_T i ; real_T tmp [ 5 ] ; real_T tmp_p [ 3 ] ; real_T iaxn1pf021_idx_0
; real_T iaxn1pf021_idx_1 ; real_T iaxn1pf021_idx_2 ; real_T ggmfj4xq1g_idx_0
; real_T ggmfj4xq1g_idx_1 ; real_T ggmfj4xq1g_idx_2 ; jtidzxyrjg * _rtB ;
co4cjo04cz * _rtP ; fgjgo1omwk * _rtX ; e1ktjqv0uw * _rtDW ; _rtDW = ( (
e1ktjqv0uw * ) ssGetRootDWork ( S ) ) ; _rtX = ( ( fgjgo1omwk * )
ssGetContStates ( S ) ) ; _rtP = ( ( co4cjo04cz * ) ssGetDefaultParam ( S ) )
; _rtB = ( ( jtidzxyrjg * ) _ssGetBlockIO ( S ) ) ; if ( ssIsContinuousTask (
S , tid ) ) { nxqvjqjijx = ssGetT ( S ) ; _rtB -> kuhkh31oiy = ssGetTStart (
S ) ; nxqvjqjijx -= _rtB -> kuhkh31oiy ; } if ( ssIsSampleHit ( S , 1 , tid )
) { _rtB -> igym241rks = _rtP -> P_9 ; } if ( ssIsContinuousTask ( S , tid )
) { nxqvjqjijx = muDoubleScalarRem ( nxqvjqjijx , _rtB -> igym241rks ) ;
nxqvjqjijx = look1_binlxpw ( nxqvjqjijx , _rtP -> P_11 , _rtP -> P_10 , 20U )
; _rtB -> lhr4gozp0y = nxqvjqjijx ; ssCallAccelRunBlock ( S , 12 , 7 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
bhwiyzl51m = _rtP -> P_12 ; _rtB -> lc41kxk0rd = _rtP -> P_13 ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> kbfi0py1fa = _rtX -> fjnlo45vm5 ;
} if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> nys5wqvw52 = _rtP -> P_15 ;
} if ( ssIsContinuousTask ( S , tid ) ) { nxqvjqjijx = _rtB -> kbfi0py1fa +
_rtB -> nys5wqvw52 ; g2qkllsoih = ( ( muDoubleScalarPower ( _rtB ->
bhwiyzl51m , 2.0 ) + muDoubleScalarPower ( _rtB -> lc41kxk0rd , 2.0 ) ) -
muDoubleScalarPower ( nxqvjqjijx , 2.0 ) ) / ( 2.0 * _rtB -> bhwiyzl51m *
_rtB -> lc41kxk0rd ) ; if ( g2qkllsoih > 1.0 ) { g2qkllsoih = 1.0 ; } else {
if ( g2qkllsoih < - 1.0 ) { g2qkllsoih = - 1.0 ; } } fmwx4omvby =
muDoubleScalarAcos ( g2qkllsoih ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> c3o4da5e5m = _rtP -> P_16 ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> brzar1csag = ( fmwx4omvby - _rtB -> c3o4da5e5m ) * _rtP -> P_17 ;
ssCallAccelRunBlock ( S , 12 , 17 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW ->
ljsjdsk3bz >= ssGetT ( S ) ) && ( _rtDW -> ipad2pi0bd >= ssGetT ( S ) ) ) {
_rtB -> o1ncnjjlho = 0.0 ; } else { mvzolbzi05 = _rtDW -> ljsjdsk3bz ; lastU
= & _rtDW -> au32dnnyqy ; if ( _rtDW -> ljsjdsk3bz < _rtDW -> ipad2pi0bd ) {
if ( _rtDW -> ipad2pi0bd < ssGetT ( S ) ) { mvzolbzi05 = _rtDW -> ipad2pi0bd
; lastU = & _rtDW -> kp1qt5ebjd ; } } else { if ( _rtDW -> ljsjdsk3bz >=
ssGetT ( S ) ) { mvzolbzi05 = _rtDW -> ipad2pi0bd ; lastU = & _rtDW ->
kp1qt5ebjd ; } } _rtB -> o1ncnjjlho = ( _rtB -> brzar1csag - * lastU ) / (
ssGetT ( S ) - mvzolbzi05 ) ; } ssCallAccelRunBlock ( S , 12 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
btjhdnoh1n = _rtP -> P_18 ; } if ( ssIsContinuousTask ( S , tid ) ) {
jnz3yg2px3 = muDoubleScalarSin ( _rtP -> P_21 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_22 ) * _rtP -> P_19 + _rtP -> P_20 ; g2qkllsoih = ( (
muDoubleScalarPower ( nxqvjqjijx , 2.0 ) + muDoubleScalarPower ( _rtB ->
bhwiyzl51m , 2.0 ) ) - muDoubleScalarPower ( _rtB -> lc41kxk0rd , 2.0 ) ) / (
2.0 * nxqvjqjijx * _rtB -> bhwiyzl51m ) ; if ( g2qkllsoih > 1.0 ) {
g2qkllsoih = 1.0 ; } else { if ( g2qkllsoih < - 1.0 ) { g2qkllsoih = - 1.0 ;
} } nxqvjqjijx = muDoubleScalarAcos ( g2qkllsoih ) ; _rtB -> gz5rzd0exs =
_rtB -> bhwiyzl51m * muDoubleScalarSin ( nxqvjqjijx ) ; } if ( ssIsSampleHit
( S , 1 , tid ) ) { _rtB -> axtg1vvax0 = _rtP -> P_23 ; } if (
ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T ) _rtB -> btjhdnoh1n )
{ case 1 : _rtB -> jf2qudmasa = jnz3yg2px3 ; break ; case 2 : jnz3yg2px3 =
look1_binlxpw ( _rtP -> P_6 * _rtB -> brzar1csag , _rtP -> P_8 , _rtP -> P_7
, 2U ) ; _rtB -> jf2qudmasa = jnz3yg2px3 / _rtB -> gz5rzd0exs ; break ;
default : _rtB -> jf2qudmasa = _rtB -> axtg1vvax0 ; break ; }
ssCallAccelRunBlock ( S , 12 , 28 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 29 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 30 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 31 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 32 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 12 , 33 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) {
ssCallAccelRunBlock ( S , 12 , 34 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 12 , 35 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
elosjr5sxa = _rtX -> bcbg0xhhvg ; _rtB -> odyseg2mo3 = _rtX -> psbmjezpot ;
_rtB -> b2bn0enuzr = _rtX -> ipcpag3ubq ; _rtB -> i0hiub223b = _rtB ->
elosjr5sxa - _rtB -> odyseg2mo3 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 12 , 40 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { ssCallAccelRunBlock ( S , 12 , 41 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 12 , 42 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
mn40rtrgjr = _rtP -> P_27 ; _rtB -> kyf2pl0l1m = _rtP -> P_28 ;
ssCallAccelRunBlock ( S , 12 , 45 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 46 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 47 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 48 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
itc1u5vgfa = _rtP -> P_29 ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
fpjue20mi4 = _rtX -> hmouxgquvh ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> fdtyg1vhil = _rtP -> P_31 ; } if ( ssIsContinuousTask ( S , tid ) ) {
switch ( ( int32_T ) _rtB -> itc1u5vgfa ) { case 1 : fmwx4omvby = _rtB ->
fpjue20mi4 ; break ; case 2 : fmwx4omvby = _rtB -> fdtyg1vhil ; break ;
default : fmwx4omvby = _rtB -> fpjue20mi4 ; break ; } } if ( ssIsSampleHit (
S , 1 , tid ) ) { _rtB -> gcap5ydni2 = _rtP -> P_32 ; _rtB -> ll4crdwph5 =
_rtP -> P_33 ; } if ( ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T )
_rtB -> gcap5ydni2 ) { case 1 : nxqvjqjijx = _rtB -> elosjr5sxa ; break ;
case 2 : nxqvjqjijx = _rtB -> ll4crdwph5 ; break ; default : nxqvjqjijx =
_rtB -> elosjr5sxa ; break ; } cyob4x5wfb = fmwx4omvby - nxqvjqjijx ;
jnz3yg2px3 = muDoubleScalarSign ( cyob4x5wfb ) ; cyob4x5wfb =
muDoubleScalarAbs ( cyob4x5wfb ) ; cyob4x5wfb = muDoubleScalarSqrt (
cyob4x5wfb ) ; jpoleaj2gp = jnz3yg2px3 * cyob4x5wfb ; } if ( ssIsSampleHit (
S , 1 , tid ) ) { _rtB -> lq0ebzpbhn = _rtP -> P_34 ; } if (
ssIsContinuousTask ( S , tid ) ) { cyob4x5wfb = jpoleaj2gp * _rtB ->
lq0ebzpbhn ; _rtB -> ofmdxnkd2t = 0.0 ; _rtB -> ofmdxnkd2t += _rtP -> P_36 *
_rtX -> ey4zwy0fx2 ; if ( _rtB -> ofmdxnkd2t > _rtP -> P_37 ) { _rtB ->
pksilsecp1 = _rtP -> P_37 ; } else if ( _rtB -> ofmdxnkd2t < _rtP -> P_38 ) {
_rtB -> pksilsecp1 = _rtP -> P_38 ; } else { _rtB -> pksilsecp1 = _rtB ->
ofmdxnkd2t ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> j5430ydjq2 =
_rtP -> P_39 ; } if ( ssIsContinuousTask ( S , tid ) ) { pv5gxysp0r = _rtB ->
pksilsecp1 - _rtB -> j5430ydjq2 ; if ( pv5gxysp0r > _rtP -> P_40 ) {
csjn0hjdfw = _rtP -> P_40 ; } else if ( pv5gxysp0r < _rtP -> P_41 ) {
csjn0hjdfw = _rtP -> P_41 ; } else { csjn0hjdfw = pv5gxysp0r ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> hgu3pgigdx = _rtP -> P_42 ; } if (
ssIsContinuousTask ( S , tid ) ) { ariiaqsscm = csjn0hjdfw * _rtB ->
hgu3pgigdx ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> m1mibckcs4 =
_rtP -> P_43 ; } if ( ssIsContinuousTask ( S , tid ) ) { pv5gxysp0r = (
ariiaqsscm + _rtB -> m1mibckcs4 ) * cyob4x5wfb ; } if ( ssIsSampleHit ( S , 1
, tid ) ) { _rtB -> jjzvkidydh = _rtP -> P_44 ; } if ( ssIsContinuousTask ( S
, tid ) ) { i1ujgst3xa = _rtX -> mnijmgq3uw ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> ml222pyglw = _rtP -> P_46 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { switch ( ( int32_T ) _rtB -> jjzvkidydh ) { case 1 : dho01whcev =
i1ujgst3xa ; break ; case 2 : dho01whcev = _rtB -> ml222pyglw ; break ;
default : dho01whcev = i1ujgst3xa ; break ; } nxqvjqjijx -= dho01whcev ;
g2qkllsoih = muDoubleScalarSign ( nxqvjqjijx ) ; nxqvjqjijx =
muDoubleScalarAbs ( nxqvjqjijx ) ; if ( nxqvjqjijx < 0.0 ) { nxqvjqjijx = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( nxqvjqjijx ) ) ; } else { nxqvjqjijx
= muDoubleScalarSqrt ( nxqvjqjijx ) ; } piih1jylvv = g2qkllsoih * nxqvjqjijx
; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> lvrrbkxknn = _rtP -> P_47
; } if ( ssIsContinuousTask ( S , tid ) ) { nxqvjqjijx = piih1jylvv * _rtB ->
lvrrbkxknn ; cyryjohugw = _rtP -> P_48 * _rtB -> pksilsecp1 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> pbmg0jvkui = _rtP -> P_49 ; } if (
ssIsContinuousTask ( S , tid ) ) { a2xkjs2hqc = cyryjohugw - _rtB ->
pbmg0jvkui ; if ( a2xkjs2hqc > _rtP -> P_50 ) { domwsj3q21 = _rtP -> P_50 ; }
else if ( a2xkjs2hqc < _rtP -> P_51 ) { domwsj3q21 = _rtP -> P_51 ; } else {
domwsj3q21 = a2xkjs2hqc ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
dcdqc53e3p = _rtP -> P_52 ; } if ( ssIsContinuousTask ( S , tid ) ) {
a1ki3pyacd = domwsj3q21 * _rtB -> dcdqc53e3p ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> jixctj4i3i = _rtP -> P_53 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { a2xkjs2hqc = ( a1ki3pyacd + _rtB -> jixctj4i3i ) * nxqvjqjijx ;
_rtB -> mmvwbsq5m1 = pv5gxysp0r - a2xkjs2hqc ; dewu3oxpw1 = _rtP -> P_54 *
_rtB -> b2bn0enuzr ; iz00jymqcq = muDoubleScalarSqrt ( muDoubleScalarAbs (
_rtB -> elosjr5sxa ) ) ; pma3w2k00n = muDoubleScalarSign ( _rtB -> elosjr5sxa
) * iz00jymqcq ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> oykheqek5p
= _rtP -> P_55 ; } if ( ssIsContinuousTask ( S , tid ) ) { hd2ydhacvd =
pma3w2k00n * _rtB -> oykheqek5p ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> lchy3tgcue = _rtP -> P_56 ; } if ( ssIsContinuousTask ( S , tid ) ) {
epv0krrh3n = hd2ydhacvd * _rtB -> lchy3tgcue ; iz00jymqcq = _rtB ->
elosjr5sxa - _rtB -> odyseg2mo3 ; jnz3yg2px3 = muDoubleScalarSign (
iz00jymqcq ) ; iz00jymqcq = muDoubleScalarAbs ( iz00jymqcq ) ; iz00jymqcq =
muDoubleScalarSqrt ( iz00jymqcq ) ; b4illzlho4 = jnz3yg2px3 * iz00jymqcq ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> n02ocgpj2y = _rtP -> P_57 ; }
if ( ssIsContinuousTask ( S , tid ) ) { dggdeh524t = b4illzlho4 * _rtB ->
n02ocgpj2y ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> b31e2dau1u =
_rtP -> P_58 ; } if ( ssIsContinuousTask ( S , tid ) ) { jqihxm2vua =
dggdeh524t * _rtB -> b31e2dau1u ; iz00jymqcq = i1ujgst3xa - _rtB ->
elosjr5sxa ; eb414jgbzr = muDoubleScalarSqrt ( muDoubleScalarAbs ( iz00jymqcq
) ) ; axcfma0fve = muDoubleScalarSign ( iz00jymqcq ) * eb414jgbzr ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> fb2wkzllqo = _rtP -> P_59 ; } if (
ssIsContinuousTask ( S , tid ) ) { eb414jgbzr = ( iz00jymqcq - _rtB ->
fb2wkzllqo ) * _rtP -> P_60 ; if ( eb414jgbzr > _rtP -> P_61 ) { i12mueccf4 =
_rtP -> P_61 ; } else if ( eb414jgbzr < _rtP -> P_62 ) { i12mueccf4 = _rtP ->
P_62 ; } else { i12mueccf4 = eb414jgbzr ; } } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> obuh3nbeb3 = _rtP -> P_63 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { eb414jgbzr = i12mueccf4 * _rtB -> obuh3nbeb3 * axcfma0fve ;
iy5lkqckc2 = ( ( ( _rtB -> mmvwbsq5m1 - dewu3oxpw1 ) - epv0krrh3n ) -
jqihxm2vua ) + eb414jgbzr ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
l0jlurnmcw = _rtP -> P_64 ; _rtB -> hsp34m3g0p = _rtP -> P_65 ; } if (
ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T ) _rtB -> l0jlurnmcw )
{ case 1 : iz00jymqcq = _rtB -> odyseg2mo3 ; break ; case 2 : iz00jymqcq =
_rtB -> hsp34m3g0p ; break ; default : iz00jymqcq = _rtB -> odyseg2mo3 ;
break ; } g1l41ivyrr = iz00jymqcq - dho01whcev ; jnz3yg2px3 =
muDoubleScalarSign ( g1l41ivyrr ) ; g1l41ivyrr = muDoubleScalarAbs (
g1l41ivyrr ) ; g1l41ivyrr = muDoubleScalarSqrt ( g1l41ivyrr ) ; nbgr2nlpuq =
jnz3yg2px3 * g1l41ivyrr ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
iqkjvj0jst = _rtP -> P_66 ; } if ( ssIsContinuousTask ( S , tid ) ) {
g1l41ivyrr = nbgr2nlpuq * _rtB -> iqkjvj0jst ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> gnuywaarye = _rtP -> P_67 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { kw5o4xp3hz = _rtB -> pksilsecp1 - _rtB -> gnuywaarye ; if (
kw5o4xp3hz > _rtP -> P_68 ) { pj45m5jpuh = _rtP -> P_68 ; } else if (
kw5o4xp3hz < _rtP -> P_69 ) { pj45m5jpuh = _rtP -> P_69 ; } else { pj45m5jpuh
= kw5o4xp3hz ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> fx0xa2aym3
= _rtP -> P_70 ; } if ( ssIsContinuousTask ( S , tid ) ) { onwcskjgvk =
pj45m5jpuh * _rtB -> fx0xa2aym3 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> cjayaestjq = _rtP -> P_71 ; } if ( ssIsContinuousTask ( S , tid ) ) {
kw5o4xp3hz = ( onwcskjgvk + _rtB -> cjayaestjq ) * g1l41ivyrr ; iz00jymqcq =
fmwx4omvby - iz00jymqcq ; g2qkllsoih = muDoubleScalarSign ( iz00jymqcq ) ;
iz00jymqcq = muDoubleScalarAbs ( iz00jymqcq ) ; iz00jymqcq =
muDoubleScalarSqrt ( iz00jymqcq ) ; etouizavme = g2qkllsoih * iz00jymqcq ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> d3i020iazt = _rtP -> P_72 ; }
if ( ssIsContinuousTask ( S , tid ) ) { iz00jymqcq = etouizavme * _rtB ->
d3i020iazt ; hl04qsrbxl = _rtP -> P_73 * _rtB -> pksilsecp1 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> fl2cprobux = _rtP -> P_74 ; } if (
ssIsContinuousTask ( S , tid ) ) { c3d3idtpox = hl04qsrbxl - _rtB ->
fl2cprobux ; if ( c3d3idtpox > _rtP -> P_75 ) { hoboum2epr = _rtP -> P_75 ; }
else if ( c3d3idtpox < _rtP -> P_76 ) { hoboum2epr = _rtP -> P_76 ; } else {
hoboum2epr = c3d3idtpox ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
pugxvb2nmo = _rtP -> P_77 ; } if ( ssIsContinuousTask ( S , tid ) ) {
poqj435wmg = hoboum2epr * _rtB -> pugxvb2nmo ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> k3yqzbkkjr = _rtP -> P_78 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { c3d3idtpox = ( poqj435wmg + _rtB -> k3yqzbkkjr ) * iz00jymqcq ;
_rtB -> ed0xlb4e1k = kw5o4xp3hz - c3d3idtpox ; lvlfpaom5x = _rtP -> P_79 *
_rtB -> b2bn0enuzr ; mmmmhtev22 = muDoubleScalarSqrt ( muDoubleScalarAbs (
_rtB -> odyseg2mo3 ) ) ; o11p3wlknv = muDoubleScalarSign ( _rtB -> odyseg2mo3
) * mmmmhtev22 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ch30gfkvpv
= _rtP -> P_80 ; } if ( ssIsContinuousTask ( S , tid ) ) { ij030g3mbk =
o11p3wlknv * _rtB -> ch30gfkvpv ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> okggatoig3 = _rtP -> P_81 ; } if ( ssIsContinuousTask ( S , tid ) ) {
nhcndasiec = ij030g3mbk * _rtB -> okggatoig3 ; mmmmhtev22 = _rtB ->
elosjr5sxa - _rtB -> odyseg2mo3 ; jnz3yg2px3 = muDoubleScalarSign (
mmmmhtev22 ) ; mmmmhtev22 = muDoubleScalarAbs ( mmmmhtev22 ) ; mmmmhtev22 =
muDoubleScalarSqrt ( mmmmhtev22 ) ; bo3vs0ki42 = jnz3yg2px3 * mmmmhtev22 ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ci4hnvidwu = _rtP -> P_82 ; }
if ( ssIsContinuousTask ( S , tid ) ) { dv1r4o0xin = bo3vs0ki42 * _rtB ->
ci4hnvidwu ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> np4wpishrd =
_rtP -> P_83 ; } if ( ssIsContinuousTask ( S , tid ) ) { iwfb0w0i0z =
dv1r4o0xin * _rtB -> np4wpishrd ; mmmmhtev22 = i1ujgst3xa - _rtB ->
odyseg2mo3 ; kvg3fbdoel = muDoubleScalarSqrt ( muDoubleScalarAbs ( mmmmhtev22
) ) ; jo3flk0tmt = muDoubleScalarSign ( mmmmhtev22 ) * kvg3fbdoel ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ehhu1q4m3v = _rtP -> P_84 ; } if (
ssIsContinuousTask ( S , tid ) ) { kvg3fbdoel = ( mmmmhtev22 - _rtB ->
ehhu1q4m3v ) * _rtP -> P_85 ; if ( kvg3fbdoel > _rtP -> P_86 ) { fdbsfvztlu =
_rtP -> P_86 ; } else if ( kvg3fbdoel < _rtP -> P_87 ) { fdbsfvztlu = _rtP ->
P_87 ; } else { fdbsfvztlu = kvg3fbdoel ; } } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> h1vi50020h = _rtP -> P_88 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { kvg3fbdoel = fdbsfvztlu * _rtB -> h1vi50020h * jo3flk0tmt ;
hueh1tpvdz = ( ( ( lvlfpaom5x - _rtB -> ed0xlb4e1k ) - nhcndasiec ) +
iwfb0w0i0z ) + kvg3fbdoel ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
gqjrmw2rax = _rtP -> P_89 ; _rtB -> oqhp4mpb2d = _rtP -> P_90 ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> odmw1npc4y = _rtB -> gxrcytfsrz *
iy5lkqckc2 / ( _rtP -> P_91 * _rtB -> kbfi0py1fa + _rtB -> gqjrmw2rax ) ;
_rtB -> nevgoskq1w = _rtB -> nzddv312n0 * hueh1tpvdz / ( _rtB -> oqhp4mpb2d -
_rtP -> P_92 * _rtB -> kbfi0py1fa ) ; ssCallAccelRunBlock ( S , 12 , 203 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
oodrlqisge = _rtP -> P_93 ; } if ( ssIsContinuousTask ( S , tid ) ) {
mmmmhtev22 = look1_linlxpw ( _rtB -> elosjr5sxa , _rtP -> P_95 , _rtP -> P_94
, 6U ) ; b3kbxqsduk = _rtP -> P_96 * mmmmhtev22 ; } if ( ssIsSampleHit ( S ,
1 , tid ) ) { ib4tdkspee = _rtP -> P_97 ; cehrujfj4k = _rtP -> P_98 ;
j54pjfo1kj = look2_linlxpw ( _rtP -> P_97 , _rtP -> P_98 , _rtP -> P_100 ,
_rtP -> P_101 , _rtP -> P_99 , _rtP -> P_302 , 6U ) ; _rtB -> ab5mjcry1c =
_rtP -> P_102 * j54pjfo1kj ; } if ( ssIsContinuousTask ( S , tid ) ) {
od3uzdjide = b3kbxqsduk + _rtB -> ab5mjcry1c ; mmmmhtev22 = look1_linlxpw (
_rtB -> elosjr5sxa , _rtP -> P_104 , _rtP -> P_103 , 6U ) ; flauz2kzwa = _rtP
-> P_105 * mmmmhtev22 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ib4tdkspee =
look2_linlxpw ( ib4tdkspee , cehrujfj4k , _rtP -> P_107 , _rtP -> P_108 ,
_rtP -> P_106 , _rtP -> P_303 , 6U ) ; _rtB -> fgmlnqxyxw = _rtP -> P_109 *
ib4tdkspee ; } if ( ssIsContinuousTask ( S , tid ) ) { hq2rjrnh5a = (
flauz2kzwa + _rtB -> fgmlnqxyxw ) + od3uzdjide ; mmmmhtev22 = look1_linlxpw (
_rtB -> odyseg2mo3 , _rtP -> P_111 , _rtP -> P_110 , 6U ) ; lf0zlayt10 = _rtP
-> P_112 * mmmmhtev22 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { j54pjfo1kj =
_rtP -> P_113 ; cehrujfj4k = _rtP -> P_114 ; ib4tdkspee = look2_linlxpw (
_rtP -> P_113 , _rtP -> P_114 , _rtP -> P_116 , _rtP -> P_117 , _rtP -> P_115
, _rtP -> P_304 , 6U ) ; _rtB -> bajdjn1p4w = _rtP -> P_118 * ib4tdkspee ; }
if ( ssIsContinuousTask ( S , tid ) ) { nkpl5b0yb5 = lf0zlayt10 + _rtB ->
bajdjn1p4w ; mmmmhtev22 = look1_linlxpw ( _rtB -> odyseg2mo3 , _rtP -> P_120
, _rtP -> P_119 , 6U ) ; o5h4apqaqz = _rtP -> P_121 * mmmmhtev22 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { j54pjfo1kj = look2_linlxpw ( j54pjfo1kj ,
cehrujfj4k , _rtP -> P_123 , _rtP -> P_124 , _rtP -> P_122 , _rtP -> P_305 ,
6U ) ; _rtB -> ae4wjooiyn = _rtP -> P_125 * j54pjfo1kj ; } if (
ssIsContinuousTask ( S , tid ) ) { dp1df2xg0i = ( o5h4apqaqz + _rtB ->
ae4wjooiyn ) + nkpl5b0yb5 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
j54pjfo1kj = look1_linlxpw ( _rtP -> P_126 , _rtP -> P_128 , _rtP -> P_127 ,
6U ) ; jnz3yg2px3 = _rtP -> P_129 * j54pjfo1kj ; j54pjfo1kj = look2_linlxpw (
_rtP -> P_130 , _rtP -> P_131 , _rtP -> P_133 , _rtP -> P_134 , _rtP -> P_132
, _rtP -> P_306 , 6U ) ; _rtB -> obquo1tjbj = ( _rtP -> P_135 * j54pjfo1kj +
jnz3yg2px3 ) * _rtP -> P_136 ; } if ( ssIsContinuousTask ( S , tid ) ) {
bgoektrore = ( hq2rjrnh5a + dp1df2xg0i ) + _rtB -> obquo1tjbj ; g2qkllsoih =
_rtP -> P_137 / 2.0 ; if ( _rtB -> b2bn0enuzr < _rtDW -> pjkg1pvb1y -
g2qkllsoih ) { _rtB -> e4gqlcq25j = _rtB -> b2bn0enuzr + g2qkllsoih ; } else
if ( _rtB -> b2bn0enuzr <= _rtDW -> pjkg1pvb1y + g2qkllsoih ) { _rtB ->
e4gqlcq25j = _rtDW -> pjkg1pvb1y ; } else { _rtB -> e4gqlcq25j = _rtB ->
b2bn0enuzr - g2qkllsoih ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
bb3g5dhsqf = _rtP -> P_139 ; } if ( ssIsContinuousTask ( S , tid ) ) { switch
( ( int32_T ) _rtB -> oodrlqisge ) { case 1 : _rtB -> pwhthbse5l = bgoektrore
; break ; case 2 : ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ;
g2qkllsoih = muDoubleScalarAbs ( _rtB -> f0vxhabzwe ) ; _rtB -> k02glv12vk =
muDoubleScalarExp ( - g2qkllsoih / 10.0 ) ; _rtB -> f0vxhabzwe = g2qkllsoih /
_rtB -> f0vxhabzwe * _rtB -> k02glv12vk ; ssCallAccelRunBlock ( S , 0 , 5 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> pwhthbse5l = bgoektrore * _rtB -> f0vxhabzwe
; break ; default : _rtB -> pwhthbse5l = _rtB -> bb3g5dhsqf ; break ; }
ssCallAccelRunBlock ( S , 12 , 245 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> d4ytny2pcb = _rtP -> P_140 ; } if (
ssIsContinuousTask ( S , tid ) ) { mmmmhtev22 = _rtB -> kbfi0py1fa - _rtB ->
d4ytny2pcb ; if ( mmmmhtev22 > _rtP -> P_141 ) { mqepf30xlr = _rtP -> P_141 ;
} else if ( mmmmhtev22 < _rtP -> P_142 ) { mqepf30xlr = _rtP -> P_142 ; }
else { mqepf30xlr = mmmmhtev22 ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> ju4pt4e3t1 = _rtP -> P_143 ; } if ( ssIsContinuousTask ( S , tid ) )
{ mmmmhtev22 = _rtB -> ju4pt4e3t1 - _rtB -> kbfi0py1fa ; if ( mmmmhtev22 >
_rtP -> P_144 ) { ckqcehizdn = _rtP -> P_144 ; } else if ( mmmmhtev22 < _rtP
-> P_145 ) { ckqcehizdn = _rtP -> P_145 ; } else { ckqcehizdn = mmmmhtev22 ;
} } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ptxgdw5hau = _rtDW ->
jjoc4g3mtd ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB -> bmh0kecgjx = (
( ( ( ( ( ( _rtB -> elosjr5sxa - _rtB -> odyseg2mo3 ) * _rtP -> P_148 - _rtP
-> P_149 * _rtB -> b2bn0enuzr ) - ( _rtB -> kbfi0py1fa - _rtB -> ptxgdw5hau )
* _rtP -> P_147 ) - muDoubleScalarSign ( _rtB -> kbfi0py1fa ) * _rtB ->
pwhthbse5l ) - _rtB -> jf2qudmasa ) - _rtP -> P_150 * mqepf30xlr * _rtP ->
P_151 ) + _rtP -> P_152 * ckqcehizdn * _rtP -> P_153 ) * _rtP -> P_154 ;
bcyur5ht2d = look1_binlxpw ( _rtB -> kbfi0py1fa , _rtP -> P_156 , _rtP ->
P_155 , 2U ) ; _rtB -> hydeaorfmj = 0.0 ; _rtB -> hydeaorfmj += _rtP -> P_158
* _rtX -> ay2ymrmb4s ; g2qkllsoih = _rtP -> P_159 / 2.0 ; if ( _rtB ->
hydeaorfmj < _rtDW -> nlrxhdmjwg - g2qkllsoih ) { _rtB -> npjmnqlw0m = _rtB
-> hydeaorfmj + g2qkllsoih ; } else if ( _rtB -> hydeaorfmj <= _rtDW ->
nlrxhdmjwg + g2qkllsoih ) { _rtB -> npjmnqlw0m = _rtDW -> nlrxhdmjwg ; } else
{ _rtB -> npjmnqlw0m = _rtB -> hydeaorfmj - g2qkllsoih ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> e3iaobyfvi = _rtDW -> ky1wvz2he1 ;
} if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtB -> e3iaobyfvi >= _rtP ->
P_164 ) { _rtB -> om01qchcvh = _rtB -> kbfi0py1fa + bcyur5ht2d ; } else {
_rtB -> om01qchcvh = _rtB -> kbfi0py1fa - bcyur5ht2d ; } ilmfw3a43s =
look1_binlxpw ( _rtB -> pksilsecp1 , _rtP -> P_166 , _rtP -> P_165 , 2U ) ;
_rtB -> mntanavo1v = 0.0 ; _rtB -> mntanavo1v += _rtP -> P_168 * _rtX ->
b341ywuexg ; g2qkllsoih = _rtP -> P_169 / 2.0 ; if ( _rtB -> mntanavo1v <
_rtDW -> ecgh4dfgct - g2qkllsoih ) { _rtB -> hpwtthsgao = _rtB -> mntanavo1v
+ g2qkllsoih ; } else if ( _rtB -> mntanavo1v <= _rtDW -> ecgh4dfgct +
g2qkllsoih ) { _rtB -> hpwtthsgao = _rtDW -> ecgh4dfgct ; } else { _rtB ->
hpwtthsgao = _rtB -> mntanavo1v - g2qkllsoih ; } } if ( ssIsSampleHit ( S , 1
, tid ) ) { _rtB -> pylbfccqp3 = _rtDW -> ilkeiajsjs ; } if (
ssIsContinuousTask ( S , tid ) ) { if ( _rtB -> pylbfccqp3 >= _rtP -> P_174 )
{ _rtB -> cchjidhval = _rtB -> pksilsecp1 + ilmfw3a43s ; } else { _rtB ->
cchjidhval = _rtB -> pksilsecp1 - ilmfw3a43s ; } l5uluf1r3z = look1_binlxpw (
_rtB -> i0hiub223b , _rtP -> P_176 , _rtP -> P_175 , 2U ) ; _rtB ->
gx2wc5plqk = 0.0 ; _rtB -> gx2wc5plqk += _rtP -> P_178 * _rtX -> h0eevxq1ts ;
g2qkllsoih = _rtP -> P_179 / 2.0 ; if ( _rtB -> gx2wc5plqk < _rtDW ->
labca0irxk - g2qkllsoih ) { _rtB -> hajaltd403 = _rtB -> gx2wc5plqk +
g2qkllsoih ; } else if ( _rtB -> gx2wc5plqk <= _rtDW -> labca0irxk +
g2qkllsoih ) { _rtB -> hajaltd403 = _rtDW -> labca0irxk ; } else { _rtB ->
hajaltd403 = _rtB -> gx2wc5plqk - g2qkllsoih ; } } if ( ssIsSampleHit ( S , 1
, tid ) ) { _rtB -> h5blfhj5xb = _rtDW -> dbslzvxac0 ; } if (
ssIsContinuousTask ( S , tid ) ) { if ( _rtB -> h5blfhj5xb >= _rtP -> P_184 )
{ _rtB -> a1llbmfa3y = _rtB -> i0hiub223b + l5uluf1r3z ; } else { _rtB ->
a1llbmfa3y = _rtB -> i0hiub223b - l5uluf1r3z ; } } if ( ssIsSampleHit ( S , 1
, tid ) ) { ssCallAccelRunBlock ( S , 12 , 287 , SS_CALL_MDL_OUTPUTS ) ; } if
( ssIsContinuousTask ( S , tid ) ) { if ( ( _rtDW -> cls3nfmnkx >= ssGetT ( S
) ) && ( _rtDW -> kcq2vvwalv >= ssGetT ( S ) ) ) { _rtB -> kifubppid5 = 0.0 ;
} else { mvzolbzi05 = _rtDW -> cls3nfmnkx ; lastU = & _rtDW -> i4hp2bhq50 ;
if ( _rtDW -> cls3nfmnkx < _rtDW -> kcq2vvwalv ) { if ( _rtDW -> kcq2vvwalv <
ssGetT ( S ) ) { mvzolbzi05 = _rtDW -> kcq2vvwalv ; lastU = & _rtDW ->
kb5wq2lzco ; } } else { if ( _rtDW -> cls3nfmnkx >= ssGetT ( S ) ) {
mvzolbzi05 = _rtDW -> kcq2vvwalv ; lastU = & _rtDW -> kb5wq2lzco ; } } _rtB
-> kifubppid5 = ( _rtB -> pksilsecp1 - * lastU ) / ( ssGetT ( S ) -
mvzolbzi05 ) ; } ssCallAccelRunBlock ( S , 12 , 289 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 290 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 291 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ppf0vi1w3f = _rtP -> P_185 ; _rtB
-> fdzfczzrvx = _rtP -> P_186 ; _rtB -> mprm5oesqe = _rtP -> P_187 ; } if (
ssIsContinuousTask ( S , tid ) ) { if ( _rtDW -> ke1nxqln0z == ( rtInf ) ) {
_rtB -> k4qti4y1oj = _rtB -> lhr4gozp0y ; } else { g2qkllsoih = ssGetTaskTime
( S , 0 ) - _rtDW -> ke1nxqln0z ; mvzolbzi05 = g2qkllsoih * _rtP -> P_188 ;
jnz3yg2px3 = _rtB -> lhr4gozp0y - _rtDW -> hp03tby40u ; if ( jnz3yg2px3 >
mvzolbzi05 ) { _rtB -> k4qti4y1oj = _rtDW -> hp03tby40u + mvzolbzi05 ; } else
{ g2qkllsoih *= _rtP -> P_189 ; if ( jnz3yg2px3 < g2qkllsoih ) { _rtB ->
k4qti4y1oj = _rtDW -> hp03tby40u + g2qkllsoih ; } else { _rtB -> k4qti4y1oj =
_rtB -> lhr4gozp0y ; } } } if ( _rtB -> k4qti4y1oj > _rtP -> P_190 ) {
g2qkllsoih = _rtP -> P_190 ; } else if ( _rtB -> k4qti4y1oj < _rtP -> P_191 )
{ g2qkllsoih = _rtP -> P_191 ; } else { g2qkllsoih = _rtB -> k4qti4y1oj ; }
gem3xqzrlf = _rtP -> P_192 * g2qkllsoih * _rtP -> P_193 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> danztdweow = _rtP -> P_194 ; } if (
ssIsContinuousTask ( S , tid ) ) { mmmmhtev22 = gem3xqzrlf + _rtB ->
danztdweow ; mvzolbzi05 = ( muDoubleScalarPower ( _rtB -> fdzfczzrvx , 2.0 )
+ muDoubleScalarPower ( _rtB -> mprm5oesqe , 2.0 ) ) - 2.0 * _rtB ->
fdzfczzrvx * _rtB -> mprm5oesqe * muDoubleScalarCos ( mmmmhtev22 ) ; if (
mvzolbzi05 < 0.0 ) { pygprsuz1b = - muDoubleScalarSqrt ( - mvzolbzi05 ) ; }
else { pygprsuz1b = muDoubleScalarSqrt ( mvzolbzi05 ) ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> kbhl3xunqh = _rtP -> P_195 ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> nhkyfnhuqx = pygprsuz1b - _rtB ->
kbhl3xunqh ; iaxn1pf021_idx_0 = _rtB -> hpwtthsgao ; iaxn1pf021_idx_1 = _rtB
-> hajaltd403 ; iaxn1pf021_idx_2 = _rtB -> npjmnqlw0m ; ggmfj4xq1g_idx_0 =
_rtX -> laqqdhc3pk [ 0 ] ; ggmfj4xq1g_idx_1 = _rtX -> laqqdhc3pk [ 1 ] ;
ggmfj4xq1g_idx_2 = _rtX -> laqqdhc3pk [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
dbvvkcgiuo [ i ] = ( ( _rtP -> P_196 [ i + 3 ] * _rtB -> hajaltd403 + _rtP ->
P_196 [ i ] * _rtB -> hpwtthsgao ) + _rtP -> P_196 [ i + 6 ] * _rtB ->
npjmnqlw0m ) + _rtX -> laqqdhc3pk [ i ] ; } tmp [ 0 ] = _rtB -> hpwtthsgao ;
tmp [ 1 ] = dbvvkcgiuo [ 0 ] ; tmp [ 2 ] = dbvvkcgiuo [ 1 ] ; tmp [ 3 ] =
_rtB -> hajaltd403 ; tmp [ 4 ] = dbvvkcgiuo [ 2 ] ; pygprsuz1b = 0.0 ; for (
i = 0 ; i < 5 ; i ++ ) { pygprsuz1b += _rtP -> P_198 [ i ] * tmp [ i ] ; }
_rtB -> j5pecabkao = ( ( _rtB -> nhkyfnhuqx - _rtB -> npjmnqlw0m ) -
pygprsuz1b ) * _rtP -> P_199 ; if ( _rtB -> j5pecabkao > _rtP -> P_200 ) {
_rtB -> hndptwqamr = _rtP -> P_200 ; } else if ( _rtB -> j5pecabkao < _rtP ->
P_201 ) { _rtB -> hndptwqamr = _rtP -> P_201 ; } else { _rtB -> hndptwqamr =
_rtB -> j5pecabkao ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
injakv53si = _rtP -> P_202 ; } if ( ssIsContinuousTask ( S , tid ) ) {
pygprsuz1b = _rtP -> P_204 * _rtX -> cwxakbqjyi ; _rtB -> oglcxk3w0z = _rtP
-> P_205 * pygprsuz1b ; switch ( ( int32_T ) _rtB -> ppf0vi1w3f ) { case 1 :
if ( _rtB -> injakv53si >= _rtP -> P_0 ) { _rtB -> fsqku2flzn = _rtB ->
hndptwqamr ; } else { _rtB -> fsqku2flzn = _rtB -> oglcxk3w0z ; } break ;
case 2 : _rtB -> fsqku2flzn = muDoubleScalarSin ( _rtP -> P_208 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_209 ) * _rtP -> P_206 + _rtP -> P_207 ;
break ; default : if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_210 ) { _rtB ->
fsqku2flzn = _rtP -> P_211 ; } else { _rtB -> fsqku2flzn = _rtP -> P_212 ; }
break ; } ssCallAccelRunBlock ( S , 12 , 321 , SS_CALL_MDL_OUTPUTS ) ;
fmwx4omvby -= dho01whcev ; jnz3yg2px3 = muDoubleScalarSign ( fmwx4omvby ) ;
fmwx4omvby = muDoubleScalarAbs ( fmwx4omvby ) ; fmwx4omvby =
muDoubleScalarSqrt ( fmwx4omvby ) ; ms44qdxwdl = jnz3yg2px3 * fmwx4omvby ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> bfwv2zog2l = _rtP -> P_213 ; }
if ( ssIsContinuousTask ( S , tid ) ) { b5kdxz2cpr = ms44qdxwdl * _rtB ->
bfwv2zog2l ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> hynxlmdxe3 =
_rtP -> P_214 ; } if ( ssIsContinuousTask ( S , tid ) ) { pygprsuz1b =
b5kdxz2cpr * _rtB -> hynxlmdxe3 ; _rtB -> n2yohgi5ad = ( ( ( ( nxqvjqjijx *
_rtB -> jixctj4i3i + pygprsuz1b ) + g1l41ivyrr * _rtB -> cjayaestjq ) +
cyob4x5wfb * _rtB -> m1mibckcs4 ) + iz00jymqcq * _rtB -> k3yqzbkkjr ) * _rtP
-> P_215 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S ,
12 , 337 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 12 , 338 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
dzftyohstp = 0.0 ; _rtB -> dzftyohstp += _rtP -> P_217 [ 0 ] * _rtX ->
n5xcqfi1jr [ 0 ] ; _rtB -> dzftyohstp += _rtP -> P_217 [ 1 ] * _rtX ->
n5xcqfi1jr [ 1 ] ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 12 , 340 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { if ( _rtB -> fsqku2flzn > _rtP -> P_218 )
{ g2qkllsoih = _rtP -> P_218 ; } else if ( _rtB -> fsqku2flzn < _rtP -> P_219
) { g2qkllsoih = _rtP -> P_219 ; } else { g2qkllsoih = _rtB -> fsqku2flzn ; }
_rtB -> junyims2eh = _rtP -> P_220 * g2qkllsoih - _rtP -> P_221 * _rtB ->
pksilsecp1 ; mmmmhtev22 = _rtP -> P_223 [ 0 ] * _rtX -> eprrclyryl [ 0 ] +
_rtP -> P_223 [ 1 ] * _rtX -> eprrclyryl [ 1 ] ; if ( mmmmhtev22 > _rtP ->
P_224 ) { mmmmhtev22 = _rtP -> P_224 ; } else { if ( mmmmhtev22 < _rtP ->
P_225 ) { mmmmhtev22 = _rtP -> P_225 ; } } mmmmhtev22 *= _rtP -> P_226 ; if (
mmmmhtev22 > _rtP -> P_227 ) { _rtB -> fegztkkjgs = _rtP -> P_227 ; } else if
( mmmmhtev22 < _rtP -> P_228 ) { _rtB -> fegztkkjgs = _rtP -> P_228 ; } else
{ _rtB -> fegztkkjgs = mmmmhtev22 ; } i3jr05mlql = ( pv5gxysp0r + c3d3idtpox
) + pygprsuz1b ; akk0clwswf = ( kw5o4xp3hz + a2xkjs2hqc ) + pygprsuz1b ; } if
( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> kyf2pl0l1m = _rtP -> P_229 ; _rtB
-> plrvu3y2oe = _rtP -> P_230 ; } if ( ssIsContinuousTask ( S , tid ) ) {
pygprsuz1b = _rtP -> P_232 * _rtX -> jyov3a5ehg ; _rtB -> ndmfqjzcpb = _rtB
-> plrvu3y2oe - pygprsuz1b ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
mn40rtrgjr = _rtP -> P_233 ; ssCallAccelRunBlock ( S , 12 , 356 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> keeiuyodd0 = _rtB -> dnwizyu4kv / _rtP ->
P_234 ; } if ( ssIsContinuousTask ( S , tid ) ) { pygprsuz1b = _rtB ->
ndmfqjzcpb - _rtB -> fpjue20mi4 ; mmmmhtev22 = muDoubleScalarAbs ( pygprsuz1b
) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> pryft0gxvr = _rtP ->
P_235 ; _rtB -> dhj32lvu03 = _rtP -> P_236 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { if ( mmmmhtev22 < 0.0 ) { mmmmhtev22 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( mmmmhtev22 ) ) ; } else { mmmmhtev22 = muDoubleScalarSqrt
( mmmmhtev22 ) ; } g2qkllsoih = ( pygprsuz1b - _rtB -> dhj32lvu03 ) * _rtP ->
P_237 ; if ( g2qkllsoih > _rtP -> P_238 ) { g2qkllsoih = _rtP -> P_238 ; }
else { if ( g2qkllsoih < _rtP -> P_239 ) { g2qkllsoih = _rtP -> P_239 ; } }
pygprsuz1b = muDoubleScalarSign ( pygprsuz1b ) * mmmmhtev22 * ( g2qkllsoih *
_rtB -> pryft0gxvr ) ; _rtB -> bk13bsxxsd = ( pygprsuz1b - i3jr05mlql ) *
_rtB -> keeiuyodd0 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
kyf2pl0l1m = _rtP -> P_240 ; _rtB -> marnjvecom = _rtP -> P_241 ; _rtB ->
mn40rtrgjr = _rtP -> P_242 ; ssCallAccelRunBlock ( S , 12 , 376 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> h0xtbghjrk = _rtB -> fwpukv440p / _rtP ->
P_243 ; } if ( ssIsContinuousTask ( S , tid ) ) { mmmmhtev22 = i1ujgst3xa -
_rtB -> marnjvecom ; im0mupdqxh = muDoubleScalarSign ( mmmmhtev22 ) *
muDoubleScalarSqrt ( muDoubleScalarAbs ( mmmmhtev22 ) ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> hw01og4kj3 = _rtP -> P_244 ; } if (
ssIsContinuousTask ( S , tid ) ) { nwe3le3y0t = ( mmmmhtev22 - _rtB ->
hw01og4kj3 ) * _rtP -> P_245 ; if ( nwe3le3y0t > _rtP -> P_246 ) { nwe3le3y0t
= _rtP -> P_246 ; } else { if ( nwe3le3y0t < _rtP -> P_247 ) { nwe3le3y0t =
_rtP -> P_247 ; } } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
h5l1b0ivf3 = _rtP -> P_248 ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB
-> hwvupjcl0k = ( ( akk0clwswf - nwe3le3y0t * _rtB -> h5l1b0ivf3 * im0mupdqxh
) - ( eb414jgbzr + kvg3fbdoel ) ) * _rtB -> h0xtbghjrk ; ssCallAccelRunBlock
( S , 12 , 394 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid )
) { ssCallAccelRunBlock ( S , 12 , 395 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 396 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 397 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 398 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { for ( i = 0 ; i < 3 ; i ++ ) { dbvvkcgiuo
[ i ] = ( ( _rtP -> P_250 [ i + 3 ] * iaxn1pf021_idx_1 + _rtP -> P_250 [ i ]
* iaxn1pf021_idx_0 ) + _rtP -> P_250 [ i + 6 ] * iaxn1pf021_idx_2 ) + _rtP ->
P_251 [ i ] * _rtB -> hndptwqamr ; } for ( i = 0 ; i < 3 ; i ++ ) { tmp_p [ i
] = _rtP -> P_249 [ i + 6 ] * ggmfj4xq1g_idx_2 + ( _rtP -> P_249 [ i + 3 ] *
ggmfj4xq1g_idx_1 + _rtP -> P_249 [ i ] * ggmfj4xq1g_idx_0 ) ; } _rtB ->
ey1s2cmw2j [ 0 ] = dbvvkcgiuo [ 0 ] + tmp_p [ 0 ] ; _rtB -> ey1s2cmw2j [ 1 ]
= dbvvkcgiuo [ 1 ] + tmp_p [ 1 ] ; _rtB -> ey1s2cmw2j [ 2 ] = dbvvkcgiuo [ 2
] + tmp_p [ 2 ] ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtB -> m2p3ad3ieo
= _rtP -> P_252 ; _rtB -> mdvzy1tj3b = _rtP -> P_253 ; ssCallAccelRunBlock (
S , 12 , 405 , SS_CALL_MDL_OUTPUTS ) ; hhiuns2uat = _rtP -> P_254 ;
e21lkz4bbc = _rtP -> P_255 ; } if ( ssIsContinuousTask ( S , tid ) && ( ! (
_rtDW -> n52kgt5jjk != 0 ) ) ) { _rtDW -> hquj3zpeta = _rtB -> lhr4gozp0y ; }
if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> n52kgt5jjk = 1 ; jnz3yg2px3 =
_rtDW -> hquj3zpeta ; _rtDW -> n52kgt5jjk = 0 ; g2qkllsoih = ( jnz3yg2px3 -
_rtDW -> oo5bsaaczi ) * _rtP -> P_257 ; if ( g2qkllsoih > _rtP -> P_258 ) {
g2qkllsoih = _rtP -> P_258 ; } else { if ( g2qkllsoih < _rtP -> P_259 ) {
g2qkllsoih = _rtP -> P_259 ; } } _rtB -> ijqfpmo2ez = _rtP -> P_260 *
g2qkllsoih + _rtDW -> fexrex2lnb ; if ( _rtB -> ijqfpmo2ez > _rtP -> P_262 )
{ g2qkllsoih = _rtP -> P_262 ; } else if ( _rtB -> ijqfpmo2ez < _rtP -> P_263
) { g2qkllsoih = _rtP -> P_263 ; } else { g2qkllsoih = _rtB -> ijqfpmo2ez ; }
mvzolbzi05 = ( muDoubleScalarPower ( hhiuns2uat , 2.0 ) + muDoubleScalarPower
( e21lkz4bbc , 2.0 ) ) - muDoubleScalarCos ( _rtP -> P_264 * g2qkllsoih *
_rtP -> P_265 + _rtP -> P_266 ) * ( 2.0 * hhiuns2uat * e21lkz4bbc ) ; if (
mvzolbzi05 < 0.0 ) { mvzolbzi05 = - muDoubleScalarSqrt ( - mvzolbzi05 ) ; }
else { mvzolbzi05 = muDoubleScalarSqrt ( mvzolbzi05 ) ; } _rtB -> mdvzy1tj3b
= mvzolbzi05 - _rtP -> P_267 ; } if ( ssIsContinuousTask ( S , tid ) && ( ! (
_rtDW -> hb0rm52iyz != 0 ) ) ) { _rtDW -> llu2czoz4u = _rtP -> P_268 * _rtB
-> npjmnqlw0m ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> hb0rm52iyz
= 1 ; _rtB -> m2p3ad3ieo = _rtDW -> llu2czoz4u ; _rtDW -> hb0rm52iyz = 0 ;
jnz3yg2px3 = _rtB -> mdvzy1tj3b - _rtB -> m2p3ad3ieo ; if ( jnz3yg2px3 >=
_rtP -> P_269 ) { _rtDW -> ajnkld54jq = true ; } else { if ( jnz3yg2px3 <=
_rtP -> P_270 ) { _rtDW -> ajnkld54jq = false ; } } if ( _rtDW -> ajnkld54jq
) { ae2dep1oyr = _rtP -> P_271 ; } else { ae2dep1oyr = _rtP -> P_272 ; } _rtB
-> cskw0mk5um = ( _rtP -> P_275 * jnz3yg2px3 - _rtP -> P_274 * _rtDW ->
kipks1c1ub ) * _rtP -> P_276 ; _rtDW -> lu1k2mfdqi = ( _rtB -> cskw0mk5um -
_rtP -> P_278 [ 1 ] * _rtDW -> bbrtg1brww ) / _rtP -> P_278 [ 0 ] ; _rtB ->
jlhwlfxfqm = _rtDW -> o1slsgzwiu ; _rtDW -> fy0aqenslx = ( _rtB -> jlhwlfxfqm
- _rtP -> P_284 [ 1 ] * _rtDW -> fvg0winctx ) / _rtP -> P_284 [ 0 ] ; _rtB ->
btcodpzuax = ( _rtP -> P_281 * jnz3yg2px3 - ( _rtP -> P_283 [ 0 ] * _rtDW ->
fy0aqenslx + _rtP -> P_283 [ 1 ] * _rtDW -> fvg0winctx ) * _rtP -> P_286 ) *
_rtP -> P_287 ; e21lkz4bbc = ( ( _rtP -> P_277 [ 0 ] * _rtDW -> lu1k2mfdqi +
_rtP -> P_277 [ 1 ] * _rtDW -> bbrtg1brww ) + _rtP -> P_280 * jnz3yg2px3 ) +
_rtB -> btcodpzuax ; if ( e21lkz4bbc > _rtP -> P_288 ) { nkij1zvx4o = _rtP ->
P_288 ; } else if ( e21lkz4bbc < _rtP -> P_289 ) { nkij1zvx4o = _rtP -> P_289
; } else { nkij1zvx4o = e21lkz4bbc ; } _rtB -> ehlozjhzt3 = _rtB ->
mdvzy1tj3b - _rtB -> m2p3ad3ieo ; } if ( ssIsContinuousTask ( S , tid ) && (
! ( _rtDW -> ir5dmhfx4y != 0 ) ) ) { _rtDW -> aqi1oaav1f = _rtP -> P_290 *
_rtB -> hpwtthsgao ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW ->
ir5dmhfx4y = 1 ; _rtB -> ok3rj2qsql = _rtDW -> aqi1oaav1f ; _rtDW ->
ir5dmhfx4y = 0 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> edns4zvnob
= _rtP -> P_294 * _rtDW -> n0q4irobfk ; } if ( ssIsContinuousTask ( S , tid )
&& ( ! ( _rtDW -> flzahjw23w != 0 ) ) ) { _rtDW -> kbsuvrgwwv = ( _rtB ->
hajaltd403 + _rtB -> edns4zvnob ) * _rtP -> P_295 ; } if ( ssIsSampleHit ( S
, 2 , tid ) ) { _rtDW -> flzahjw23w = 1 ; _rtB -> i4agjo0o2q = _rtDW ->
kbsuvrgwwv ; _rtDW -> flzahjw23w = 0 ; _rtB -> e1fwbxkvy4 = _rtB ->
ehlozjhzt3 - ( _rtP -> P_296 [ 0 ] * _rtB -> ok3rj2qsql + _rtP -> P_296 [ 1 ]
* _rtB -> i4agjo0o2q ) ; switch ( ( int32_T ) _rtB -> l0kyrdyjl4 ) { case 1 :
_rtB -> dzgeaeio0o = ae2dep1oyr ; break ; case 2 : _rtB -> dzgeaeio0o =
nkij1zvx4o ; break ; case 3 : _rtB -> dzgeaeio0o = _rtP -> P_5 ; break ; case
4 : if ( ssGetTaskTime ( S , 2 ) < _rtP -> P_2 ) { _rtB -> dzgeaeio0o = _rtP
-> P_3 ; } else { _rtB -> dzgeaeio0o = _rtP -> P_4 ; } break ; default : _rtB
-> dzgeaeio0o = _rtP -> P_1 * _rtB -> e1fwbxkvy4 ; break ; }
ssCallAccelRunBlock ( S , 12 , 458 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 459 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 460 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 12 , 461 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
o33jrm5rsu = e21lkz4bbc - nkij1zvx4o ; if ( _rtB -> dzgeaeio0o > _rtP ->
P_297 ) { _rtB -> jtb2enq0yo = _rtP -> P_297 ; } else if ( _rtB -> dzgeaeio0o
< _rtP -> P_298 ) { _rtB -> jtb2enq0yo = _rtP -> P_298 ; } else { _rtB ->
jtb2enq0yo = _rtB -> dzgeaeio0o ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> fkvf10soow = _rtDW -> pyzz1cerdf [ _rtDW -> ddwxnuqjtx ] ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> fz5mtyhj2s = _rtP -> P_300 *
pygprsuz1b * _rtP -> P_301 ; _rtB -> lj0ges5pxa = ssGetTStart ( S ) ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
jtidzxyrjg * _rtB ; co4cjo04cz * _rtP ; e1ktjqv0uw * _rtDW ; _rtDW = ( (
e1ktjqv0uw * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( co4cjo04cz * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( jtidzxyrjg * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtDW -> ljsjdsk3bz == ( rtInf )
) { _rtDW -> ljsjdsk3bz = ssGetT ( S ) ; lastU = & _rtDW -> au32dnnyqy ; }
else if ( _rtDW -> ipad2pi0bd == ( rtInf ) ) { _rtDW -> ipad2pi0bd = ssGetT (
S ) ; lastU = & _rtDW -> kp1qt5ebjd ; } else if ( _rtDW -> ljsjdsk3bz < _rtDW
-> ipad2pi0bd ) { _rtDW -> ljsjdsk3bz = ssGetT ( S ) ; lastU = & _rtDW ->
au32dnnyqy ; } else { _rtDW -> ipad2pi0bd = ssGetT ( S ) ; lastU = & _rtDW ->
kp1qt5ebjd ; } * lastU = _rtB -> brzar1csag ; _rtDW -> pjkg1pvb1y = _rtB ->
e4gqlcq25j ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtDW -> jjoc4g3mtd =
_rtB -> kbfi0py1fa ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtDW ->
nlrxhdmjwg = _rtB -> npjmnqlw0m ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtDW -> ky1wvz2he1 = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> aucxhtei0l ) *
_rtP -> P_162 + _rtP -> P_161 ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtDW -> ecgh4dfgct = _rtB -> hpwtthsgao ; } if ( ssIsSampleHit ( S , 1 , tid
) ) { _rtDW -> ilkeiajsjs = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
dif2b05yma ) * _rtP -> P_172 + _rtP -> P_171 ; } if ( ssIsContinuousTask ( S
, tid ) ) { _rtDW -> labca0irxk = _rtB -> hajaltd403 ; } if ( ssIsSampleHit (
S , 1 , tid ) ) { _rtDW -> dbslzvxac0 = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW
-> p4sfnkha3x ) * _rtP -> P_182 + _rtP -> P_181 ; } if ( ssIsContinuousTask (
S , tid ) ) { if ( _rtDW -> cls3nfmnkx == ( rtInf ) ) { _rtDW -> cls3nfmnkx =
ssGetT ( S ) ; lastU = & _rtDW -> i4hp2bhq50 ; } else if ( _rtDW ->
kcq2vvwalv == ( rtInf ) ) { _rtDW -> kcq2vvwalv = ssGetT ( S ) ; lastU = &
_rtDW -> kb5wq2lzco ; } else if ( _rtDW -> cls3nfmnkx < _rtDW -> kcq2vvwalv )
{ _rtDW -> cls3nfmnkx = ssGetT ( S ) ; lastU = & _rtDW -> i4hp2bhq50 ; } else
{ _rtDW -> kcq2vvwalv = ssGetT ( S ) ; lastU = & _rtDW -> kb5wq2lzco ; } *
lastU = _rtB -> pksilsecp1 ; _rtDW -> hp03tby40u = _rtB -> k4qti4y1oj ; _rtDW
-> ke1nxqln0z = ssGetTaskTime ( S , 0 ) ; } if ( ssIsSampleHit ( S , 2 , tid
) ) { _rtDW -> oo5bsaaczi = _rtB -> ijqfpmo2ez ; _rtDW -> fexrex2lnb = _rtB
-> ijqfpmo2ez ; _rtDW -> kipks1c1ub = _rtB -> o33jrm5rsu ; _rtDW ->
bbrtg1brww = _rtDW -> lu1k2mfdqi ; _rtDW -> o1slsgzwiu = _rtB -> btcodpzuax ;
_rtDW -> fvg0winctx = _rtDW -> fy0aqenslx ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtDW -> n0q4irobfk = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
crf25ruvpb ) * _rtP -> P_292 + _rtP -> P_291 ; } if ( ssIsSampleHit ( S , 2 ,
tid ) ) { _rtDW -> pyzz1cerdf [ _rtDW -> ddwxnuqjtx == 0 ] = _rtB ->
jtb2enq0yo ; _rtDW -> ddwxnuqjtx = ( int8_T ) ( _rtDW -> ddwxnuqjtx == 0 ) ;
} UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { jtidzxyrjg * _rtB ; co4cjo04cz
* _rtP ; fgjgo1omwk * _rtX ; bfvdfxf4la * _rtXdot ; _rtXdot = ( ( bfvdfxf4la
* ) ssGetdX ( S ) ) ; _rtX = ( ( fgjgo1omwk * ) ssGetContStates ( S ) ) ;
_rtP = ( ( co4cjo04cz * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( jtidzxyrjg *
) _ssGetBlockIO ( S ) ) ; _rtXdot -> fjnlo45vm5 = _rtB -> b2bn0enuzr ;
_rtXdot -> bcbg0xhhvg = _rtB -> odmw1npc4y ; _rtXdot -> psbmjezpot = _rtB ->
nevgoskq1w ; _rtXdot -> ipcpag3ubq = _rtB -> bmh0kecgjx ; _rtXdot ->
hmouxgquvh = _rtB -> bk13bsxxsd ; _rtXdot -> ey4zwy0fx2 = 0.0 ; _rtXdot ->
ey4zwy0fx2 += _rtP -> P_35 * _rtX -> ey4zwy0fx2 ; _rtXdot -> ey4zwy0fx2 +=
_rtB -> fegztkkjgs ; _rtXdot -> mnijmgq3uw = _rtB -> hwvupjcl0k ; _rtXdot ->
ay2ymrmb4s = 0.0 ; _rtXdot -> ay2ymrmb4s += _rtP -> P_157 * _rtX ->
ay2ymrmb4s ; _rtXdot -> ay2ymrmb4s += _rtB -> om01qchcvh ; _rtXdot ->
b341ywuexg = 0.0 ; _rtXdot -> b341ywuexg += _rtP -> P_167 * _rtX ->
b341ywuexg ; _rtXdot -> b341ywuexg += _rtB -> cchjidhval ; _rtXdot ->
h0eevxq1ts = 0.0 ; _rtXdot -> h0eevxq1ts += _rtP -> P_177 * _rtX ->
h0eevxq1ts ; _rtXdot -> h0eevxq1ts += _rtB -> a1llbmfa3y ; _rtXdot ->
laqqdhc3pk [ 0 ] = _rtB -> ey1s2cmw2j [ 0 ] ; _rtXdot -> laqqdhc3pk [ 1 ] =
_rtB -> ey1s2cmw2j [ 1 ] ; _rtXdot -> laqqdhc3pk [ 2 ] = _rtB -> ey1s2cmw2j [
2 ] ; _rtXdot -> cwxakbqjyi = 0.0 ; _rtXdot -> cwxakbqjyi += _rtP -> P_203 *
_rtX -> cwxakbqjyi ; _rtXdot -> cwxakbqjyi += _rtB -> fkvf10soow ; _rtXdot ->
n5xcqfi1jr [ 0 ] = 0.0 ; _rtXdot -> n5xcqfi1jr [ 1 ] = 0.0 ; _rtXdot ->
n5xcqfi1jr [ 0 ] += _rtP -> P_216 [ 0 ] * _rtX -> n5xcqfi1jr [ 0 ] ; _rtXdot
-> n5xcqfi1jr [ 0 ] += _rtP -> P_216 [ 1 ] * _rtX -> n5xcqfi1jr [ 1 ] ;
_rtXdot -> n5xcqfi1jr [ 1 ] += _rtX -> n5xcqfi1jr [ 0 ] ; _rtXdot ->
n5xcqfi1jr [ 0 ] += _rtB -> fsqku2flzn ; _rtXdot -> eprrclyryl [ 0 ] = 0.0 ;
_rtXdot -> eprrclyryl [ 1 ] = 0.0 ; _rtXdot -> eprrclyryl [ 0 ] += _rtP ->
P_222 [ 0 ] * _rtX -> eprrclyryl [ 0 ] ; _rtXdot -> eprrclyryl [ 0 ] += _rtP
-> P_222 [ 1 ] * _rtX -> eprrclyryl [ 1 ] ; _rtXdot -> eprrclyryl [ 1 ] +=
_rtX -> eprrclyryl [ 0 ] ; _rtXdot -> eprrclyryl [ 0 ] += _rtB -> junyims2eh
; _rtXdot -> jyov3a5ehg = 0.0 ; _rtXdot -> jyov3a5ehg += _rtP -> P_231 * _rtX
-> jyov3a5ehg ; _rtXdot -> jyov3a5ehg += _rtB -> fz5mtyhj2s ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 2138600528U
) ; ssSetChecksumVal ( S , 1 , 1576803050U ) ; ssSetChecksumVal ( S , 2 ,
2722211666U ) ; ssSetChecksumVal ( S , 3 , 3767395075U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.5" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( e1ktjqv0uw ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( jtidzxyrjg ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofY ( S ) != sizeof
( l0cu0nmvu3 ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalOutputs sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
co4cjo04cz ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & oopmglxopz ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
co4cjo04cz * ) ssGetDefaultParam ( S ) ) -> P_141 = rtInf ; ( ( co4cjo04cz *
) ssGetDefaultParam ( S ) ) -> P_144 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
