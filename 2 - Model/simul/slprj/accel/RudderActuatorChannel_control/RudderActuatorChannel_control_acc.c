#include "__cf_RudderActuatorChannel_control.h"
#include <math.h>
#include "RudderActuatorChannel_control_acc.h"
#include "RudderActuatorChannel_control_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T dc3gyirnpi ;
real_T * lastU ; real_T lvo0tpw4vh ; real_T laxcf0imdv ; real_T fmwx4omvby ;
real_T ktwgpr2alw ; real_T jnz3yg2px3 ; real_T gem3xqzrlf ; real_T dbvvkcgiuo
[ 3 ] ; real_T cyob4x5wfb ; real_T llwe3gzhub ; real_T jpoleaj2gp ; real_T
pv5gxysp0r ; real_T csjn0hjdfw ; real_T ariiaqsscm ; real_T i1ujgst3xa ;
real_T dho01whcev ; real_T piih1jylvv ; real_T cyryjohugw ; real_T a2xkjs2hqc
; real_T domwsj3q21 ; real_T a1ki3pyacd ; real_T dewu3oxpw1 ; real_T
iz00jymqcq ; real_T pma3w2k00n ; real_T hd2ydhacvd ; real_T epv0krrh3n ;
real_T b4illzlho4 ; real_T dggdeh524t ; real_T jqihxm2vua ; real_T eb414jgbzr
; real_T axcfma0fve ; real_T i12mueccf4 ; real_T pfx1wdoity ; real_T
nbgr2nlpuq ; real_T c3d3idtpox ; real_T pj45m5jpuh ; real_T onwcskjgvk ;
real_T etouizavme ; real_T hl04qsrbxl ; real_T mmmmhtev22 ; real_T hoboum2epr
; real_T poqj435wmg ; real_T lvlfpaom5x ; real_T pygprsuz1b ; real_T
o11p3wlknv ; real_T ij030g3mbk ; real_T nhcndasiec ; real_T bo3vs0ki42 ;
real_T dv1r4o0xin ; real_T iwfb0w0i0z ; real_T kvg3fbdoel ; real_T jo3flk0tmt
; real_T fdbsfvztlu ; real_T iy5lkqckc2 ; real_T hueh1tpvdz ; real_T
b3kbxqsduk ; real_T ib4tdkspee ; real_T cehrujfj4k ; real_T j54pjfo1kj ;
real_T flauz2kzwa ; real_T od3uzdjide ; real_T lf0zlayt10 ; real_T o5h4apqaqz
; real_T nkpl5b0yb5 ; real_T hq2rjrnh5a ; real_T dp1df2xg0i ; real_T
bgoektrore ; real_T mqepf30xlr ; real_T ckqcehizdn ; real_T ms44qdxwdl ;
real_T b5kdxz2cpr ; real_T i3jr05mlql ; real_T im0mupdqxh ; real_T nwe3le3y0t
; real_T akk0clwswf ; real_T hhiuns2uat ; real_T e21lkz4bbc ; real_T
nkij1zvx4o ; real_T ae2dep1oyr ; real_T bcyur5ht2d ; real_T ilmfw3a43s ;
real_T l5uluf1r3z ; int32_T i ; real_T tmp [ 5 ] ; real_T tmp_p [ 3 ] ;
real_T nen02ddbrh_idx_0 ; real_T nen02ddbrh_idx_1 ; real_T nen02ddbrh_idx_2 ;
real_T hcgfhyfy02_idx_0 ; real_T hcgfhyfy02_idx_1 ; real_T hcgfhyfy02_idx_2 ;
cdc1qietk5 * _rtB ; nffqwkkk0o * _rtP ; mkvrtd44mj * _rtX ; gnhrdqndaw *
_rtDW ; _rtDW = ( ( gnhrdqndaw * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
mkvrtd44mj * ) ssGetContStates ( S ) ) ; _rtP = ( ( nffqwkkk0o * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( cdc1qietk5 * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> n5emepncmu = _rtP -> P_10 ; }
if ( ssIsContinuousTask ( S , tid ) ) { dc3gyirnpi = ssGetT ( S ) ; _rtB ->
faoqu1m5v4 = ssGetTStart ( S ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> kzdamwyw3y = _rtP -> P_11 ; } if ( ssIsContinuousTask ( S , tid ) ) {
lvo0tpw4vh = muDoubleScalarSin ( _rtP -> P_14 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_15 ) * _rtP -> P_12 + _rtP -> P_13 ; if ( ssGetTaskTime ( S , 0 ) <
_rtP -> P_16 ) { laxcf0imdv = _rtP -> P_17 ; } else { laxcf0imdv = _rtP ->
P_18 ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> agfrurf4tx = _rtP
-> P_19 ; } if ( ssIsContinuousTask ( S , tid ) ) { ssCallAccelRunBlock ( S ,
13 , 7 , SS_CALL_MDL_OUTPUTS ) ; switch ( ( int32_T ) _rtB -> n5emepncmu ) {
case 1 : _rtB -> i0k30klgz3 = look1_binlxpw ( muDoubleScalarRem ( dc3gyirnpi
- _rtB -> faoqu1m5v4 , _rtB -> kzdamwyw3y ) , _rtP -> P_9 , _rtP -> P_8 , 1U
) ; break ; case 2 : _rtB -> i0k30klgz3 = lvo0tpw4vh ; break ; case 3 : _rtB
-> i0k30klgz3 = laxcf0imdv ; break ; default : switch ( ( int32_T ) _rtB ->
agfrurf4tx ) { case 1 : _rtB -> i0k30klgz3 = _rtB -> bym1hzgcjt [ 0 ] ; break
; case 2 : _rtB -> i0k30klgz3 = _rtB -> bym1hzgcjt [ 1 ] ; break ; case 3 :
_rtB -> i0k30klgz3 = _rtB -> bym1hzgcjt [ 2 ] ; break ; default : _rtB ->
i0k30klgz3 = _rtB -> bym1hzgcjt [ 3 ] ; break ; } break ; }
ssCallAccelRunBlock ( S , 13 , 11 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> jnh3ysabca = _rtP -> P_20 ; _rtB ->
fvrpmyjesg = _rtP -> P_21 ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
iipde23lg1 = _rtX -> drig45tzgq ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> gi3lwll4k5 = _rtP -> P_23 ; } if ( ssIsContinuousTask ( S , tid ) ) {
ktwgpr2alw = _rtB -> iipde23lg1 + _rtB -> gi3lwll4k5 ; llwe3gzhub = ( (
muDoubleScalarPower ( _rtB -> jnh3ysabca , 2.0 ) + muDoubleScalarPower ( _rtB
-> fvrpmyjesg , 2.0 ) ) - muDoubleScalarPower ( ktwgpr2alw , 2.0 ) ) / ( 2.0
* _rtB -> jnh3ysabca * _rtB -> fvrpmyjesg ) ; if ( llwe3gzhub > 1.0 ) {
llwe3gzhub = 1.0 ; } else { if ( llwe3gzhub < - 1.0 ) { llwe3gzhub = - 1.0 ;
} } fmwx4omvby = muDoubleScalarAcos ( llwe3gzhub ) ; } if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtB -> bzdqipcxyh = _rtP -> P_24 ; } if ( ssIsContinuousTask
( S , tid ) ) { _rtB -> lwtrphnwqm = ( fmwx4omvby - _rtB -> bzdqipcxyh ) *
_rtP -> P_25 ; ssCallAccelRunBlock ( S , 13 , 21 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> lofcpccd3v >= ssGetT ( S ) ) && ( _rtDW -> lskn5i0tu2 >= ssGetT
( S ) ) ) { _rtB -> ijzigm3tu2 = 0.0 ; } else { laxcf0imdv = _rtDW ->
lofcpccd3v ; lastU = & _rtDW -> kiduujgizo ; if ( _rtDW -> lofcpccd3v < _rtDW
-> lskn5i0tu2 ) { if ( _rtDW -> lskn5i0tu2 < ssGetT ( S ) ) { laxcf0imdv =
_rtDW -> lskn5i0tu2 ; lastU = & _rtDW -> lnjwuesc4c ; } } else { if ( _rtDW
-> lofcpccd3v >= ssGetT ( S ) ) { laxcf0imdv = _rtDW -> lskn5i0tu2 ; lastU =
& _rtDW -> lnjwuesc4c ; } } _rtB -> ijzigm3tu2 = ( _rtB -> lwtrphnwqm - *
lastU ) / ( ssGetT ( S ) - laxcf0imdv ) ; } ssCallAccelRunBlock ( S , 13 , 23
, SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
njdjezvee1 = _rtP -> P_26 ; } if ( ssIsContinuousTask ( S , tid ) ) {
jnz3yg2px3 = muDoubleScalarSin ( _rtP -> P_29 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_30 ) * _rtP -> P_27 + _rtP -> P_28 ; llwe3gzhub = ( (
muDoubleScalarPower ( ktwgpr2alw , 2.0 ) + muDoubleScalarPower ( _rtB ->
jnh3ysabca , 2.0 ) ) - muDoubleScalarPower ( _rtB -> fvrpmyjesg , 2.0 ) ) / (
2.0 * ktwgpr2alw * _rtB -> jnh3ysabca ) ; if ( llwe3gzhub > 1.0 ) {
llwe3gzhub = 1.0 ; } else { if ( llwe3gzhub < - 1.0 ) { llwe3gzhub = - 1.0 ;
} } ktwgpr2alw = muDoubleScalarAcos ( llwe3gzhub ) ; _rtB -> exg0gzodra =
_rtB -> jnh3ysabca * muDoubleScalarSin ( ktwgpr2alw ) ; } if ( ssIsSampleHit
( S , 1 , tid ) ) { _rtB -> ktr3uo02c5 = _rtP -> P_31 ; } if (
ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T ) _rtB -> njdjezvee1 )
{ case 1 : _rtB -> jnbn02bc4b = jnz3yg2px3 ; break ; case 2 : jnz3yg2px3 =
look1_binlxpw ( _rtP -> P_5 * _rtB -> lwtrphnwqm , _rtP -> P_7 , _rtP -> P_6
, 2U ) ; _rtB -> jnbn02bc4b = jnz3yg2px3 / _rtB -> exg0gzodra ; break ;
default : _rtB -> jnbn02bc4b = _rtB -> ktr3uo02c5 ; break ; }
ssCallAccelRunBlock ( S , 13 , 32 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 33 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 34 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 35 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 36 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 13 , 37 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) {
ssCallAccelRunBlock ( S , 13 , 38 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 13 , 39 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> okyitkmldm = _rtP -> P_32 ; _rtB ->
nd1tjssbnu = _rtP -> P_33 ; } if ( ssIsContinuousTask ( S , tid ) ) { if (
_rtDW -> etrlhmj31i == ( rtInf ) ) { _rtB -> dhfwk5wgw3 = _rtB -> i0k30klgz3
; } else { laxcf0imdv = ssGetTaskTime ( S , 0 ) - _rtDW -> etrlhmj31i ;
lvo0tpw4vh = laxcf0imdv * _rtP -> P_34 ; llwe3gzhub = _rtB -> i0k30klgz3 -
_rtDW -> ddcz5bsrj4 ; if ( llwe3gzhub > lvo0tpw4vh ) { _rtB -> dhfwk5wgw3 =
_rtDW -> ddcz5bsrj4 + lvo0tpw4vh ; } else { laxcf0imdv *= _rtP -> P_35 ; if (
llwe3gzhub < laxcf0imdv ) { _rtB -> dhfwk5wgw3 = _rtDW -> ddcz5bsrj4 +
laxcf0imdv ; } else { _rtB -> dhfwk5wgw3 = _rtB -> i0k30klgz3 ; } } } if (
_rtB -> dhfwk5wgw3 > _rtP -> P_36 ) { llwe3gzhub = _rtP -> P_36 ; } else if (
_rtB -> dhfwk5wgw3 < _rtP -> P_37 ) { llwe3gzhub = _rtP -> P_37 ; } else {
llwe3gzhub = _rtB -> dhfwk5wgw3 ; } gem3xqzrlf = _rtP -> P_38 * llwe3gzhub *
_rtP -> P_39 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> e5ytxmbo2y =
_rtP -> P_40 ; } if ( ssIsContinuousTask ( S , tid ) ) { fmwx4omvby =
gem3xqzrlf + _rtB -> e5ytxmbo2y ; lvo0tpw4vh = ( muDoubleScalarPower ( _rtB
-> okyitkmldm , 2.0 ) + muDoubleScalarPower ( _rtB -> nd1tjssbnu , 2.0 ) ) -
2.0 * _rtB -> okyitkmldm * _rtB -> nd1tjssbnu * muDoubleScalarCos (
fmwx4omvby ) ; if ( lvo0tpw4vh < 0.0 ) { ktwgpr2alw = - muDoubleScalarSqrt (
- lvo0tpw4vh ) ; } else { ktwgpr2alw = muDoubleScalarSqrt ( lvo0tpw4vh ) ; }
} if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> cpsyjd4ujv = _rtP -> P_41 ;
} if ( ssIsContinuousTask ( S , tid ) ) { _rtB -> i5jb5x1hwe = ktwgpr2alw -
_rtB -> cpsyjd4ujv ; _rtB -> lda0k3wtsc = 0.0 ; _rtB -> lda0k3wtsc += _rtP ->
P_43 * _rtX -> i5gw4xodpn ; jnz3yg2px3 = _rtP -> P_44 / 2.0 ; if ( _rtB ->
lda0k3wtsc < _rtDW -> guyuccv315 - jnz3yg2px3 ) { _rtB -> aajkn5pdud = _rtB
-> lda0k3wtsc + jnz3yg2px3 ; } else if ( _rtB -> lda0k3wtsc <= _rtDW ->
guyuccv315 + jnz3yg2px3 ) { _rtB -> aajkn5pdud = _rtDW -> guyuccv315 ; } else
{ _rtB -> aajkn5pdud = _rtB -> lda0k3wtsc - jnz3yg2px3 ; } _rtB -> czjjdd4dxv
= 0.0 ; _rtB -> czjjdd4dxv += _rtP -> P_47 * _rtX -> pnhrmy1uiy ; jnz3yg2px3
= _rtP -> P_48 / 2.0 ; if ( _rtB -> czjjdd4dxv < _rtDW -> nvnj0uqpc1 -
jnz3yg2px3 ) { _rtB -> pn131hzyrx = _rtB -> czjjdd4dxv + jnz3yg2px3 ; } else
if ( _rtB -> czjjdd4dxv <= _rtDW -> nvnj0uqpc1 + jnz3yg2px3 ) { _rtB ->
pn131hzyrx = _rtDW -> nvnj0uqpc1 ; } else { _rtB -> pn131hzyrx = _rtB ->
czjjdd4dxv - jnz3yg2px3 ; } _rtB -> lxoac0gpgt = 0.0 ; _rtB -> lxoac0gpgt +=
_rtP -> P_51 * _rtX -> ppodbibpay ; jnz3yg2px3 = _rtP -> P_52 / 2.0 ; if (
_rtB -> lxoac0gpgt < _rtDW -> kuxx0h0hjr - jnz3yg2px3 ) { _rtB -> fygqumipk1
= _rtB -> lxoac0gpgt + jnz3yg2px3 ; } else if ( _rtB -> lxoac0gpgt <= _rtDW
-> kuxx0h0hjr + jnz3yg2px3 ) { _rtB -> fygqumipk1 = _rtDW -> kuxx0h0hjr ; }
else { _rtB -> fygqumipk1 = _rtB -> lxoac0gpgt - jnz3yg2px3 ; }
nen02ddbrh_idx_0 = _rtB -> pn131hzyrx ; nen02ddbrh_idx_1 = _rtB -> fygqumipk1
; nen02ddbrh_idx_2 = _rtB -> aajkn5pdud ; hcgfhyfy02_idx_0 = _rtX ->
puv5m1t14e [ 0 ] ; hcgfhyfy02_idx_1 = _rtX -> puv5m1t14e [ 1 ] ;
hcgfhyfy02_idx_2 = _rtX -> puv5m1t14e [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
dbvvkcgiuo [ i ] = ( ( _rtP -> P_54 [ i + 3 ] * _rtB -> fygqumipk1 + _rtP ->
P_54 [ i ] * _rtB -> pn131hzyrx ) + _rtP -> P_54 [ i + 6 ] * _rtB ->
aajkn5pdud ) + _rtX -> puv5m1t14e [ i ] ; } tmp [ 0 ] = _rtB -> pn131hzyrx ;
tmp [ 1 ] = dbvvkcgiuo [ 0 ] ; tmp [ 2 ] = dbvvkcgiuo [ 1 ] ; tmp [ 3 ] =
_rtB -> fygqumipk1 ; tmp [ 4 ] = dbvvkcgiuo [ 2 ] ; fmwx4omvby = 0.0 ; for (
i = 0 ; i < 5 ; i ++ ) { fmwx4omvby += _rtP -> P_56 [ i ] * tmp [ i ] ; }
_rtB -> iep5g5nadw = ( ( _rtB -> i5jb5x1hwe - _rtB -> aajkn5pdud ) -
fmwx4omvby ) * _rtP -> P_57 ; if ( _rtB -> iep5g5nadw > _rtP -> P_58 ) { _rtB
-> hq13wkbxn0 = _rtP -> P_58 ; } else if ( _rtB -> iep5g5nadw < _rtP -> P_59
) { _rtB -> hq13wkbxn0 = _rtP -> P_59 ; } else { _rtB -> hq13wkbxn0 = _rtB ->
iep5g5nadw ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> fyga3ffmyi =
_rtP -> P_60 ; } if ( ssIsContinuousTask ( S , tid ) ) { fmwx4omvby = _rtP ->
P_62 * _rtX -> oarjlg0z11 ; _rtB -> h5cz5si5rf = _rtP -> P_63 * fmwx4omvby ;
if ( _rtB -> fyga3ffmyi >= _rtP -> P_64 ) { _rtB -> hfiku0fgbq = _rtB ->
hq13wkbxn0 ; } else { _rtB -> hfiku0fgbq = _rtB -> h5cz5si5rf ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 13 , 71 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
i3fa5njf5q = _rtX -> k1z5ksayfm ; _rtB -> hlgy0qbkt1 = _rtX -> fmmi3ei4ik ;
_rtB -> azegqsok2u = _rtX -> f11ic0i0dy ; _rtB -> mbgka1fvn0 = _rtB ->
i3fa5njf5q - _rtB -> hlgy0qbkt1 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 13 , 76 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { ssCallAccelRunBlock ( S , 13 , 77 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 78 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
dthirzbact = _rtP -> P_68 ; _rtB -> nxzuwnn1lh = _rtP -> P_69 ;
ssCallAccelRunBlock ( S , 13 , 81 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 82 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 83 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 84 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
k3shlvb3gp = _rtP -> P_70 ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
kiqjhvwxmk = _rtX -> eo0bwreyi4 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> lqs0qtumlg = _rtP -> P_72 ; } if ( ssIsContinuousTask ( S , tid ) ) {
switch ( ( int32_T ) _rtB -> k3shlvb3gp ) { case 1 : fmwx4omvby = _rtB ->
kiqjhvwxmk ; break ; case 2 : fmwx4omvby = _rtB -> lqs0qtumlg ; break ;
default : fmwx4omvby = _rtB -> kiqjhvwxmk ; break ; } } if ( ssIsSampleHit (
S , 1 , tid ) ) { _rtB -> ooq0xetnu0 = _rtP -> P_73 ; _rtB -> irwzp0i140 =
_rtP -> P_74 ; } if ( ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T )
_rtB -> ooq0xetnu0 ) { case 1 : ktwgpr2alw = _rtB -> i3fa5njf5q ; break ;
case 2 : ktwgpr2alw = _rtB -> irwzp0i140 ; break ; default : ktwgpr2alw =
_rtB -> i3fa5njf5q ; break ; } cyob4x5wfb = fmwx4omvby - ktwgpr2alw ;
llwe3gzhub = muDoubleScalarSign ( cyob4x5wfb ) ; cyob4x5wfb =
muDoubleScalarAbs ( cyob4x5wfb ) ; cyob4x5wfb = muDoubleScalarSqrt (
cyob4x5wfb ) ; jpoleaj2gp = llwe3gzhub * cyob4x5wfb ; } if ( ssIsSampleHit (
S , 1 , tid ) ) { _rtB -> cfyrjvq2cd = _rtP -> P_75 ; } if (
ssIsContinuousTask ( S , tid ) ) { cyob4x5wfb = jpoleaj2gp * _rtB ->
cfyrjvq2cd ; _rtB -> igidwvw0cb = 0.0 ; _rtB -> igidwvw0cb += _rtP -> P_77 *
_rtX -> p0s35axnlc ; if ( _rtB -> igidwvw0cb > _rtP -> P_78 ) { _rtB ->
eren1giag3 = _rtP -> P_78 ; } else if ( _rtB -> igidwvw0cb < _rtP -> P_79 ) {
_rtB -> eren1giag3 = _rtP -> P_79 ; } else { _rtB -> eren1giag3 = _rtB ->
igidwvw0cb ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> hxc1npfrcu =
_rtP -> P_80 ; } if ( ssIsContinuousTask ( S , tid ) ) { pv5gxysp0r = _rtB ->
eren1giag3 - _rtB -> hxc1npfrcu ; if ( pv5gxysp0r > _rtP -> P_81 ) {
csjn0hjdfw = _rtP -> P_81 ; } else if ( pv5gxysp0r < _rtP -> P_82 ) {
csjn0hjdfw = _rtP -> P_82 ; } else { csjn0hjdfw = pv5gxysp0r ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> jc1int1tnm = _rtP -> P_83 ; } if (
ssIsContinuousTask ( S , tid ) ) { ariiaqsscm = csjn0hjdfw * _rtB ->
jc1int1tnm ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> jupgpngfc0 =
_rtP -> P_84 ; } if ( ssIsContinuousTask ( S , tid ) ) { pv5gxysp0r = (
ariiaqsscm + _rtB -> jupgpngfc0 ) * cyob4x5wfb ; } if ( ssIsSampleHit ( S , 1
, tid ) ) { _rtB -> apsexklret = _rtP -> P_85 ; } if ( ssIsContinuousTask ( S
, tid ) ) { i1ujgst3xa = _rtX -> gsa5h5kyri ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> lvhxzh5wen = _rtP -> P_87 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { switch ( ( int32_T ) _rtB -> apsexklret ) { case 1 : dho01whcev =
i1ujgst3xa ; break ; case 2 : dho01whcev = _rtB -> lvhxzh5wen ; break ;
default : dho01whcev = i1ujgst3xa ; break ; } ktwgpr2alw -= dho01whcev ;
lvo0tpw4vh = muDoubleScalarSign ( ktwgpr2alw ) ; ktwgpr2alw =
muDoubleScalarAbs ( ktwgpr2alw ) ; ktwgpr2alw = muDoubleScalarSqrt (
ktwgpr2alw ) ; piih1jylvv = lvo0tpw4vh * ktwgpr2alw ; } if ( ssIsSampleHit (
S , 1 , tid ) ) { _rtB -> kjjam3iuct = _rtP -> P_88 ; } if (
ssIsContinuousTask ( S , tid ) ) { ktwgpr2alw = piih1jylvv * _rtB ->
kjjam3iuct ; cyryjohugw = _rtP -> P_89 * _rtB -> eren1giag3 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ihhvhzkyyw = _rtP -> P_90 ; } if (
ssIsContinuousTask ( S , tid ) ) { a2xkjs2hqc = cyryjohugw - _rtB ->
ihhvhzkyyw ; if ( a2xkjs2hqc > _rtP -> P_91 ) { domwsj3q21 = _rtP -> P_91 ; }
else if ( a2xkjs2hqc < _rtP -> P_92 ) { domwsj3q21 = _rtP -> P_92 ; } else {
domwsj3q21 = a2xkjs2hqc ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
fhkd3jogb1 = _rtP -> P_93 ; } if ( ssIsContinuousTask ( S , tid ) ) {
a1ki3pyacd = domwsj3q21 * _rtB -> fhkd3jogb1 ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> la0ioupyuv = _rtP -> P_94 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { a2xkjs2hqc = ( a1ki3pyacd + _rtB -> la0ioupyuv ) * ktwgpr2alw ;
_rtB -> odjz4hx5el = pv5gxysp0r - a2xkjs2hqc ; dewu3oxpw1 = _rtP -> P_95 *
_rtB -> azegqsok2u ; iz00jymqcq = muDoubleScalarSqrt ( muDoubleScalarAbs (
_rtB -> i3fa5njf5q ) ) ; pma3w2k00n = muDoubleScalarSign ( _rtB -> i3fa5njf5q
) * iz00jymqcq ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> lxprry1ur5
= _rtP -> P_96 ; } if ( ssIsContinuousTask ( S , tid ) ) { hd2ydhacvd =
pma3w2k00n * _rtB -> lxprry1ur5 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> plvx1n4hou = _rtP -> P_97 ; } if ( ssIsContinuousTask ( S , tid ) ) {
epv0krrh3n = hd2ydhacvd * _rtB -> plvx1n4hou ; iz00jymqcq = _rtB ->
i3fa5njf5q - _rtB -> hlgy0qbkt1 ; jnz3yg2px3 = muDoubleScalarSign (
iz00jymqcq ) ; iz00jymqcq = muDoubleScalarAbs ( iz00jymqcq ) ; iz00jymqcq =
muDoubleScalarSqrt ( iz00jymqcq ) ; b4illzlho4 = jnz3yg2px3 * iz00jymqcq ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> jatz1czkos = _rtP -> P_98 ; }
if ( ssIsContinuousTask ( S , tid ) ) { dggdeh524t = b4illzlho4 * _rtB ->
jatz1czkos ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> nsze2qvrua =
_rtP -> P_99 ; } if ( ssIsContinuousTask ( S , tid ) ) { jqihxm2vua =
dggdeh524t * _rtB -> nsze2qvrua ; iz00jymqcq = i1ujgst3xa - _rtB ->
i3fa5njf5q ; eb414jgbzr = muDoubleScalarSqrt ( muDoubleScalarAbs ( iz00jymqcq
) ) ; axcfma0fve = muDoubleScalarSign ( iz00jymqcq ) * eb414jgbzr ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> atr12hy2hg = _rtP -> P_100 ; } if (
ssIsContinuousTask ( S , tid ) ) { eb414jgbzr = ( iz00jymqcq - _rtB ->
atr12hy2hg ) * _rtP -> P_101 ; if ( eb414jgbzr > _rtP -> P_102 ) { i12mueccf4
= _rtP -> P_102 ; } else if ( eb414jgbzr < _rtP -> P_103 ) { i12mueccf4 =
_rtP -> P_103 ; } else { i12mueccf4 = eb414jgbzr ; } } if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtB -> m3pst3z3rp = _rtP -> P_104 ; } if (
ssIsContinuousTask ( S , tid ) ) { eb414jgbzr = i12mueccf4 * _rtB ->
m3pst3z3rp * axcfma0fve ; iy5lkqckc2 = ( ( ( _rtB -> odjz4hx5el - dewu3oxpw1
) - epv0krrh3n ) - jqihxm2vua ) + eb414jgbzr ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> fdzhaeivsn = _rtP -> P_105 ; _rtB -> ijusgjmrb1 = _rtP ->
P_106 ; } if ( ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T ) _rtB
-> fdzhaeivsn ) { case 1 : iz00jymqcq = _rtB -> hlgy0qbkt1 ; break ; case 2 :
iz00jymqcq = _rtB -> ijusgjmrb1 ; break ; default : iz00jymqcq = _rtB ->
hlgy0qbkt1 ; break ; } pfx1wdoity = iz00jymqcq - dho01whcev ; llwe3gzhub =
muDoubleScalarSign ( pfx1wdoity ) ; pfx1wdoity = muDoubleScalarAbs (
pfx1wdoity ) ; pfx1wdoity = muDoubleScalarSqrt ( pfx1wdoity ) ; nbgr2nlpuq =
llwe3gzhub * pfx1wdoity ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
efdlrqzvh3 = _rtP -> P_107 ; } if ( ssIsContinuousTask ( S , tid ) ) {
pfx1wdoity = nbgr2nlpuq * _rtB -> efdlrqzvh3 ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> cllzn14spg = _rtP -> P_108 ; } if ( ssIsContinuousTask ( S
, tid ) ) { c3d3idtpox = _rtB -> eren1giag3 - _rtB -> cllzn14spg ; if (
c3d3idtpox > _rtP -> P_109 ) { pj45m5jpuh = _rtP -> P_109 ; } else if (
c3d3idtpox < _rtP -> P_110 ) { pj45m5jpuh = _rtP -> P_110 ; } else {
pj45m5jpuh = c3d3idtpox ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
nhxbajkayv = _rtP -> P_111 ; } if ( ssIsContinuousTask ( S , tid ) ) {
onwcskjgvk = pj45m5jpuh * _rtB -> nhxbajkayv ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> detm4kyomp = _rtP -> P_112 ; } if ( ssIsContinuousTask ( S
, tid ) ) { c3d3idtpox = ( onwcskjgvk + _rtB -> detm4kyomp ) * pfx1wdoity ;
iz00jymqcq = fmwx4omvby - iz00jymqcq ; lvo0tpw4vh = muDoubleScalarSign (
iz00jymqcq ) ; iz00jymqcq = muDoubleScalarAbs ( iz00jymqcq ) ; iz00jymqcq =
muDoubleScalarSqrt ( iz00jymqcq ) ; etouizavme = lvo0tpw4vh * iz00jymqcq ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ltj5psptec = _rtP -> P_113 ; }
if ( ssIsContinuousTask ( S , tid ) ) { iz00jymqcq = etouizavme * _rtB ->
ltj5psptec ; hl04qsrbxl = _rtP -> P_114 * _rtB -> eren1giag3 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> emnalec1lg = _rtP -> P_115 ; } if (
ssIsContinuousTask ( S , tid ) ) { mmmmhtev22 = hl04qsrbxl - _rtB ->
emnalec1lg ; if ( mmmmhtev22 > _rtP -> P_116 ) { hoboum2epr = _rtP -> P_116 ;
} else if ( mmmmhtev22 < _rtP -> P_117 ) { hoboum2epr = _rtP -> P_117 ; }
else { hoboum2epr = mmmmhtev22 ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> aujqqvoyss = _rtP -> P_118 ; } if ( ssIsContinuousTask ( S , tid ) )
{ poqj435wmg = hoboum2epr * _rtB -> aujqqvoyss ; } if ( ssIsSampleHit ( S , 1
, tid ) ) { _rtB -> fdsodfi5hw = _rtP -> P_119 ; } if ( ssIsContinuousTask (
S , tid ) ) { mmmmhtev22 = ( poqj435wmg + _rtB -> fdsodfi5hw ) * iz00jymqcq ;
_rtB -> dacscz5nes = c3d3idtpox - mmmmhtev22 ; lvlfpaom5x = _rtP -> P_120 *
_rtB -> azegqsok2u ; pygprsuz1b = muDoubleScalarSqrt ( muDoubleScalarAbs (
_rtB -> hlgy0qbkt1 ) ) ; o11p3wlknv = muDoubleScalarSign ( _rtB -> hlgy0qbkt1
) * pygprsuz1b ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ortgjvjrai
= _rtP -> P_121 ; } if ( ssIsContinuousTask ( S , tid ) ) { ij030g3mbk =
o11p3wlknv * _rtB -> ortgjvjrai ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> o0mnfpeek1 = _rtP -> P_122 ; } if ( ssIsContinuousTask ( S , tid ) )
{ nhcndasiec = ij030g3mbk * _rtB -> o0mnfpeek1 ; pygprsuz1b = _rtB ->
i3fa5njf5q - _rtB -> hlgy0qbkt1 ; jnz3yg2px3 = muDoubleScalarSign (
pygprsuz1b ) ; pygprsuz1b = muDoubleScalarAbs ( pygprsuz1b ) ; pygprsuz1b =
muDoubleScalarSqrt ( pygprsuz1b ) ; bo3vs0ki42 = jnz3yg2px3 * pygprsuz1b ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> az05srhslu = _rtP -> P_123 ; }
if ( ssIsContinuousTask ( S , tid ) ) { dv1r4o0xin = bo3vs0ki42 * _rtB ->
az05srhslu ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> pzjkqnbxki =
_rtP -> P_124 ; } if ( ssIsContinuousTask ( S , tid ) ) { iwfb0w0i0z =
dv1r4o0xin * _rtB -> pzjkqnbxki ; pygprsuz1b = i1ujgst3xa - _rtB ->
hlgy0qbkt1 ; kvg3fbdoel = muDoubleScalarSqrt ( muDoubleScalarAbs ( pygprsuz1b
) ) ; jo3flk0tmt = muDoubleScalarSign ( pygprsuz1b ) * kvg3fbdoel ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> nx4k0np51b = _rtP -> P_125 ; } if (
ssIsContinuousTask ( S , tid ) ) { kvg3fbdoel = ( pygprsuz1b - _rtB ->
nx4k0np51b ) * _rtP -> P_126 ; if ( kvg3fbdoel > _rtP -> P_127 ) { fdbsfvztlu
= _rtP -> P_127 ; } else if ( kvg3fbdoel < _rtP -> P_128 ) { fdbsfvztlu =
_rtP -> P_128 ; } else { fdbsfvztlu = kvg3fbdoel ; } } if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtB -> lvketmabyk = _rtP -> P_129 ; } if (
ssIsContinuousTask ( S , tid ) ) { kvg3fbdoel = fdbsfvztlu * _rtB ->
lvketmabyk * jo3flk0tmt ; hueh1tpvdz = ( ( ( lvlfpaom5x - _rtB -> dacscz5nes
) - nhcndasiec ) + iwfb0w0i0z ) + kvg3fbdoel ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtB -> fu4s4jqfql = _rtP -> P_130 ; _rtB -> a1cmn4hecs = _rtP ->
P_131 ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB -> n5v0xcyhwf = _rtB
-> l4lsyjuw45 * iy5lkqckc2 / ( _rtP -> P_132 * _rtB -> iipde23lg1 + _rtB ->
fu4s4jqfql ) ; _rtB -> mvmvnwt4kc = _rtB -> gjhq1huomz * hueh1tpvdz / ( _rtB
-> a1cmn4hecs - _rtP -> P_133 * _rtB -> iipde23lg1 ) ; ssCallAccelRunBlock (
S , 13 , 239 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) )
{ _rtB -> m5izyy5fzp = _rtP -> P_134 ; } if ( ssIsContinuousTask ( S , tid )
) { pygprsuz1b = look1_linlxpw ( _rtB -> i3fa5njf5q , _rtP -> P_136 , _rtP ->
P_135 , 6U ) ; b3kbxqsduk = _rtP -> P_137 * pygprsuz1b ; } if ( ssIsSampleHit
( S , 1 , tid ) ) { ib4tdkspee = _rtP -> P_138 ; cehrujfj4k = _rtP -> P_139 ;
j54pjfo1kj = look2_linlxpw ( _rtP -> P_138 , _rtP -> P_139 , _rtP -> P_141 ,
_rtP -> P_142 , _rtP -> P_140 , _rtP -> P_311 , 6U ) ; _rtB -> m5qi2iswbl =
_rtP -> P_143 * j54pjfo1kj ; } if ( ssIsContinuousTask ( S , tid ) ) {
od3uzdjide = b3kbxqsduk + _rtB -> m5qi2iswbl ; pygprsuz1b = look1_linlxpw (
_rtB -> i3fa5njf5q , _rtP -> P_145 , _rtP -> P_144 , 6U ) ; flauz2kzwa = _rtP
-> P_146 * pygprsuz1b ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ib4tdkspee =
look2_linlxpw ( ib4tdkspee , cehrujfj4k , _rtP -> P_148 , _rtP -> P_149 ,
_rtP -> P_147 , _rtP -> P_312 , 6U ) ; _rtB -> endgm2wl02 = _rtP -> P_150 *
ib4tdkspee ; } if ( ssIsContinuousTask ( S , tid ) ) { hq2rjrnh5a = (
flauz2kzwa + _rtB -> endgm2wl02 ) + od3uzdjide ; pygprsuz1b = look1_linlxpw (
_rtB -> hlgy0qbkt1 , _rtP -> P_152 , _rtP -> P_151 , 6U ) ; lf0zlayt10 = _rtP
-> P_153 * pygprsuz1b ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { j54pjfo1kj =
_rtP -> P_154 ; cehrujfj4k = _rtP -> P_155 ; ib4tdkspee = look2_linlxpw (
_rtP -> P_154 , _rtP -> P_155 , _rtP -> P_157 , _rtP -> P_158 , _rtP -> P_156
, _rtP -> P_313 , 6U ) ; _rtB -> jl5ttxenkq = _rtP -> P_159 * ib4tdkspee ; }
if ( ssIsContinuousTask ( S , tid ) ) { nkpl5b0yb5 = lf0zlayt10 + _rtB ->
jl5ttxenkq ; pygprsuz1b = look1_linlxpw ( _rtB -> hlgy0qbkt1 , _rtP -> P_161
, _rtP -> P_160 , 6U ) ; o5h4apqaqz = _rtP -> P_162 * pygprsuz1b ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { j54pjfo1kj = look2_linlxpw ( j54pjfo1kj ,
cehrujfj4k , _rtP -> P_164 , _rtP -> P_165 , _rtP -> P_163 , _rtP -> P_314 ,
6U ) ; _rtB -> ghe1b5xcmw = _rtP -> P_166 * j54pjfo1kj ; } if (
ssIsContinuousTask ( S , tid ) ) { dp1df2xg0i = ( o5h4apqaqz + _rtB ->
ghe1b5xcmw ) + nkpl5b0yb5 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
j54pjfo1kj = look1_linlxpw ( _rtP -> P_167 , _rtP -> P_169 , _rtP -> P_168 ,
6U ) ; llwe3gzhub = _rtP -> P_170 * j54pjfo1kj ; j54pjfo1kj = look2_linlxpw (
_rtP -> P_171 , _rtP -> P_172 , _rtP -> P_174 , _rtP -> P_175 , _rtP -> P_173
, _rtP -> P_315 , 6U ) ; _rtB -> nqyidwr5mo = ( _rtP -> P_176 * j54pjfo1kj +
llwe3gzhub ) * _rtP -> P_177 ; } if ( ssIsContinuousTask ( S , tid ) ) {
bgoektrore = ( hq2rjrnh5a + dp1df2xg0i ) + _rtB -> nqyidwr5mo ; jnz3yg2px3 =
_rtP -> P_178 / 2.0 ; if ( _rtB -> azegqsok2u < _rtDW -> ft4eexgqzb -
jnz3yg2px3 ) { _rtB -> foknucrrmx = _rtB -> azegqsok2u + jnz3yg2px3 ; } else
if ( _rtB -> azegqsok2u <= _rtDW -> ft4eexgqzb + jnz3yg2px3 ) { _rtB ->
foknucrrmx = _rtDW -> ft4eexgqzb ; } else { _rtB -> foknucrrmx = _rtB ->
azegqsok2u - jnz3yg2px3 ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
hvmjkfdffw = _rtP -> P_180 ; } if ( ssIsContinuousTask ( S , tid ) ) { switch
( ( int32_T ) _rtB -> m5izyy5fzp ) { case 1 : _rtB -> mgunkgvq1i = bgoektrore
; break ; case 2 : ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ;
lvo0tpw4vh = muDoubleScalarAbs ( _rtB -> dx0x3ylkku ) ; _rtB -> bn1ydfh5v0 =
muDoubleScalarExp ( - lvo0tpw4vh / 10.0 ) ; _rtB -> dx0x3ylkku = lvo0tpw4vh /
_rtB -> dx0x3ylkku * _rtB -> bn1ydfh5v0 ; ssCallAccelRunBlock ( S , 0 , 5 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> mgunkgvq1i = bgoektrore * _rtB -> dx0x3ylkku
; break ; default : _rtB -> mgunkgvq1i = _rtB -> hvmjkfdffw ; break ; }
ssCallAccelRunBlock ( S , 13 , 281 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> letnfetl4s = _rtP -> P_181 ; } if (
ssIsContinuousTask ( S , tid ) ) { pygprsuz1b = _rtB -> iipde23lg1 - _rtB ->
letnfetl4s ; if ( pygprsuz1b > _rtP -> P_182 ) { mqepf30xlr = _rtP -> P_182 ;
} else if ( pygprsuz1b < _rtP -> P_183 ) { mqepf30xlr = _rtP -> P_183 ; }
else { mqepf30xlr = pygprsuz1b ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> dyhdbudjg3 = _rtP -> P_184 ; } if ( ssIsContinuousTask ( S , tid ) )
{ pygprsuz1b = _rtB -> dyhdbudjg3 - _rtB -> iipde23lg1 ; if ( pygprsuz1b >
_rtP -> P_185 ) { ckqcehizdn = _rtP -> P_185 ; } else if ( pygprsuz1b < _rtP
-> P_186 ) { ckqcehizdn = _rtP -> P_186 ; } else { ckqcehizdn = pygprsuz1b ;
} } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> h1m52zrdbx = _rtDW ->
mprqka25vy ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB -> lvnpppsyaq = (
( ( ( ( ( ( _rtB -> i3fa5njf5q - _rtB -> hlgy0qbkt1 ) * _rtP -> P_189 - _rtP
-> P_190 * _rtB -> azegqsok2u ) - ( _rtB -> iipde23lg1 - _rtB -> h1m52zrdbx )
* _rtP -> P_188 ) - muDoubleScalarSign ( _rtB -> iipde23lg1 ) * _rtB ->
mgunkgvq1i ) - _rtB -> jnbn02bc4b ) - _rtP -> P_191 * mqepf30xlr * _rtP ->
P_192 ) + _rtP -> P_193 * ckqcehizdn * _rtP -> P_194 ) * _rtP -> P_195 ;
bcyur5ht2d = look1_binlxpw ( _rtB -> iipde23lg1 , _rtP -> P_197 , _rtP ->
P_196 , 2U ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> j53qjf3tzq =
_rtDW -> a21gu23ss2 ; } if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtB ->
j53qjf3tzq >= _rtP -> P_201 ) { _rtB -> lprlyity5x = _rtB -> iipde23lg1 +
bcyur5ht2d ; } else { _rtB -> lprlyity5x = _rtB -> iipde23lg1 - bcyur5ht2d ;
} ilmfw3a43s = look1_binlxpw ( _rtB -> eren1giag3 , _rtP -> P_203 , _rtP ->
P_202 , 2U ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> eajsgqro1h =
_rtDW -> hli3eybjuh ; } if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtB ->
eajsgqro1h >= _rtP -> P_207 ) { _rtB -> fp2h1ttszi = _rtB -> eren1giag3 +
ilmfw3a43s ; } else { _rtB -> fp2h1ttszi = _rtB -> eren1giag3 - ilmfw3a43s ;
} l5uluf1r3z = look1_binlxpw ( _rtB -> mbgka1fvn0 , _rtP -> P_209 , _rtP ->
P_208 , 2U ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> m2x05ags3q =
_rtDW -> est5crkpfo ; } if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtB ->
m2x05ags3q >= _rtP -> P_213 ) { _rtB -> e1kmntv5m0 = _rtB -> mbgka1fvn0 +
l5uluf1r3z ; } else { _rtB -> e1kmntv5m0 = _rtB -> mbgka1fvn0 - l5uluf1r3z ;
} } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 13 , 317
, SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { if ( (
_rtDW -> in4ciyh5xv >= ssGetT ( S ) ) && ( _rtDW -> dkvz24omzk >= ssGetT ( S
) ) ) { _rtB -> ehsvda1ttn = 0.0 ; } else { laxcf0imdv = _rtDW -> in4ciyh5xv
; lastU = & _rtDW -> drjzfovyiw ; if ( _rtDW -> in4ciyh5xv < _rtDW ->
dkvz24omzk ) { if ( _rtDW -> dkvz24omzk < ssGetT ( S ) ) { laxcf0imdv = _rtDW
-> dkvz24omzk ; lastU = & _rtDW -> biztplgyzb ; } } else { if ( _rtDW ->
in4ciyh5xv >= ssGetT ( S ) ) { laxcf0imdv = _rtDW -> dkvz24omzk ; lastU = &
_rtDW -> biztplgyzb ; } } _rtB -> ehsvda1ttn = ( _rtB -> eren1giag3 - * lastU
) / ( ssGetT ( S ) - laxcf0imdv ) ; } ssCallAccelRunBlock ( S , 13 , 319 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 320 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 321 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
alfhmkp2bb = _rtP -> P_214 ; } if ( ssIsContinuousTask ( S , tid ) ) { switch
( ( int32_T ) _rtB -> alfhmkp2bb ) { case 1 : _rtB -> he2jhyzdjm = _rtB ->
hfiku0fgbq ; break ; case 2 : _rtB -> he2jhyzdjm = muDoubleScalarSin ( _rtP
-> P_217 * ssGetTaskTime ( S , 0 ) + _rtP -> P_218 ) * _rtP -> P_215 + _rtP
-> P_216 ; break ; default : if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_219 ) {
_rtB -> he2jhyzdjm = _rtP -> P_220 ; } else { _rtB -> he2jhyzdjm = _rtP ->
P_221 ; } break ; } ssCallAccelRunBlock ( S , 13 , 326 , SS_CALL_MDL_OUTPUTS
) ; fmwx4omvby -= dho01whcev ; laxcf0imdv = muDoubleScalarSign ( fmwx4omvby )
; fmwx4omvby = muDoubleScalarAbs ( fmwx4omvby ) ; fmwx4omvby =
muDoubleScalarSqrt ( fmwx4omvby ) ; ms44qdxwdl = laxcf0imdv * fmwx4omvby ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> iisu01hcme = _rtP -> P_222 ; }
if ( ssIsContinuousTask ( S , tid ) ) { b5kdxz2cpr = ms44qdxwdl * _rtB ->
iisu01hcme ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> b5313odkwp =
_rtP -> P_223 ; } if ( ssIsContinuousTask ( S , tid ) ) { pygprsuz1b =
b5kdxz2cpr * _rtB -> b5313odkwp ; _rtB -> kmpw22kren = ( ( ( ( ktwgpr2alw *
_rtB -> la0ioupyuv + pygprsuz1b ) + pfx1wdoity * _rtB -> detm4kyomp ) +
cyob4x5wfb * _rtB -> jupgpngfc0 ) + iz00jymqcq * _rtB -> fdsodfi5hw ) * _rtP
-> P_224 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S ,
13 , 342 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 343 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
f1caahebik = 0.0 ; _rtB -> f1caahebik += _rtP -> P_226 [ 0 ] * _rtX ->
fspor4sjtq [ 0 ] ; _rtB -> f1caahebik += _rtP -> P_226 [ 1 ] * _rtX ->
fspor4sjtq [ 1 ] ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 13 , 345 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { if ( _rtB -> he2jhyzdjm > _rtP -> P_227 )
{ llwe3gzhub = _rtP -> P_227 ; } else if ( _rtB -> he2jhyzdjm < _rtP -> P_228
) { llwe3gzhub = _rtP -> P_228 ; } else { llwe3gzhub = _rtB -> he2jhyzdjm ; }
_rtB -> gasw43jrmv = _rtP -> P_229 * llwe3gzhub - _rtP -> P_230 * _rtB ->
eren1giag3 ; pfx1wdoity = _rtP -> P_232 [ 0 ] * _rtX -> cxsfbwsttm [ 0 ] +
_rtP -> P_232 [ 1 ] * _rtX -> cxsfbwsttm [ 1 ] ; if ( pfx1wdoity > _rtP ->
P_233 ) { pfx1wdoity = _rtP -> P_233 ; } else { if ( pfx1wdoity < _rtP ->
P_234 ) { pfx1wdoity = _rtP -> P_234 ; } } llwe3gzhub = _rtP -> P_235 *
pfx1wdoity ; if ( llwe3gzhub > _rtP -> P_236 ) { _rtB -> kzte5nxxvp = _rtP ->
P_236 ; } else if ( llwe3gzhub < _rtP -> P_237 ) { _rtB -> kzte5nxxvp = _rtP
-> P_237 ; } else { _rtB -> kzte5nxxvp = llwe3gzhub ; } i3jr05mlql = (
pv5gxysp0r + mmmmhtev22 ) + pygprsuz1b ; akk0clwswf = ( c3d3idtpox +
a2xkjs2hqc ) + pygprsuz1b ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
nxzuwnn1lh = _rtP -> P_238 ; _rtB -> fysw5twj0f = _rtP -> P_239 ; } if (
ssIsContinuousTask ( S , tid ) ) { pygprsuz1b = _rtP -> P_241 * _rtX ->
p4ateoyaz0 ; _rtB -> oztwkrhoim = _rtB -> fysw5twj0f - pygprsuz1b ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> dthirzbact = _rtP -> P_242 ;
ssCallAccelRunBlock ( S , 13 , 361 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ghtk1wnvfe = _rtB -> mitv5vijdv / _rtP -> P_243 ; } if ( ssIsContinuousTask (
S , tid ) ) { pygprsuz1b = _rtB -> oztwkrhoim - _rtB -> kiqjhvwxmk ;
mmmmhtev22 = muDoubleScalarAbs ( pygprsuz1b ) ; } if ( ssIsSampleHit ( S , 1
, tid ) ) { _rtB -> eenqzyuj23 = _rtP -> P_244 ; _rtB -> cc2k5h2su0 = _rtP ->
P_245 ; } if ( ssIsContinuousTask ( S , tid ) ) { if ( mmmmhtev22 < 0.0 ) {
mmmmhtev22 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( mmmmhtev22 ) ) ; }
else { mmmmhtev22 = muDoubleScalarSqrt ( mmmmhtev22 ) ; } llwe3gzhub = (
pygprsuz1b - _rtB -> cc2k5h2su0 ) * _rtP -> P_246 ; if ( llwe3gzhub > _rtP ->
P_247 ) { llwe3gzhub = _rtP -> P_247 ; } else { if ( llwe3gzhub < _rtP ->
P_248 ) { llwe3gzhub = _rtP -> P_248 ; } } pygprsuz1b = muDoubleScalarSign (
pygprsuz1b ) * mmmmhtev22 * ( llwe3gzhub * _rtB -> eenqzyuj23 ) ; _rtB ->
kcpvnpttau = ( pygprsuz1b - i3jr05mlql ) * _rtB -> ghtk1wnvfe ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> nxzuwnn1lh = _rtP -> P_249 ; _rtB
-> pj0taobhqi = _rtP -> P_250 ; _rtB -> dthirzbact = _rtP -> P_251 ;
ssCallAccelRunBlock ( S , 13 , 381 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
i3x1cusrvt = _rtB -> f2n5fmv2av / _rtP -> P_252 ; } if ( ssIsContinuousTask (
S , tid ) ) { mmmmhtev22 = i1ujgst3xa - _rtB -> pj0taobhqi ; im0mupdqxh =
muDoubleScalarSign ( mmmmhtev22 ) * muDoubleScalarSqrt ( muDoubleScalarAbs (
mmmmhtev22 ) ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> fs3snfwfeo
= _rtP -> P_253 ; } if ( ssIsContinuousTask ( S , tid ) ) { nwe3le3y0t = (
mmmmhtev22 - _rtB -> fs3snfwfeo ) * _rtP -> P_254 ; if ( nwe3le3y0t > _rtP ->
P_255 ) { nwe3le3y0t = _rtP -> P_255 ; } else { if ( nwe3le3y0t < _rtP ->
P_256 ) { nwe3le3y0t = _rtP -> P_256 ; } } } if ( ssIsSampleHit ( S , 1 , tid
) ) { _rtB -> hcllqr1qlp = _rtP -> P_257 ; } if ( ssIsContinuousTask ( S ,
tid ) ) { _rtB -> mbz0o5xdfy = ( ( akk0clwswf - nwe3le3y0t * _rtB ->
hcllqr1qlp * im0mupdqxh ) - ( eb414jgbzr + kvg3fbdoel ) ) * _rtB ->
i3x1cusrvt ; ssCallAccelRunBlock ( S , 13 , 399 , SS_CALL_MDL_OUTPUTS ) ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 13 , 400 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 401 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 402 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 403 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { for ( i = 0
; i < 3 ; i ++ ) { dbvvkcgiuo [ i ] = ( ( _rtP -> P_259 [ i + 3 ] *
nen02ddbrh_idx_1 + _rtP -> P_259 [ i ] * nen02ddbrh_idx_0 ) + _rtP -> P_259 [
i + 6 ] * nen02ddbrh_idx_2 ) + _rtP -> P_260 [ i ] * _rtB -> hq13wkbxn0 ; }
for ( i = 0 ; i < 3 ; i ++ ) { tmp_p [ i ] = _rtP -> P_258 [ i + 6 ] *
hcgfhyfy02_idx_2 + ( _rtP -> P_258 [ i + 3 ] * hcgfhyfy02_idx_1 + _rtP ->
P_258 [ i ] * hcgfhyfy02_idx_0 ) ; } _rtB -> pqzatmkaqm [ 0 ] = dbvvkcgiuo [
0 ] + tmp_p [ 0 ] ; _rtB -> pqzatmkaqm [ 1 ] = dbvvkcgiuo [ 1 ] + tmp_p [ 1 ]
; _rtB -> pqzatmkaqm [ 2 ] = dbvvkcgiuo [ 2 ] + tmp_p [ 2 ] ; } if (
ssIsSampleHit ( S , 2 , tid ) ) { _rtB -> ib4jjpdudr = _rtP -> P_261 ; _rtB
-> alel31g0ei = _rtP -> P_262 ; ssCallAccelRunBlock ( S , 13 , 410 ,
SS_CALL_MDL_OUTPUTS ) ; hhiuns2uat = _rtP -> P_263 ; e21lkz4bbc = _rtP ->
P_264 ; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW -> efwzkfiqr0 !=
0 ) ) ) { _rtDW -> cmc4u4kowe = _rtB -> i0k30klgz3 ; } if ( ssIsSampleHit ( S
, 2 , tid ) ) { _rtDW -> efwzkfiqr0 = 1 ; laxcf0imdv = _rtDW -> cmc4u4kowe ;
_rtDW -> efwzkfiqr0 = 0 ; llwe3gzhub = ( laxcf0imdv - _rtDW -> igbe5jrrkp ) *
_rtP -> P_266 ; if ( llwe3gzhub > _rtP -> P_267 ) { llwe3gzhub = _rtP ->
P_267 ; } else { if ( llwe3gzhub < _rtP -> P_268 ) { llwe3gzhub = _rtP ->
P_268 ; } } _rtB -> f4ilowdy0t = _rtP -> P_269 * llwe3gzhub + _rtDW ->
phsimlohfo ; if ( _rtB -> f4ilowdy0t > _rtP -> P_271 ) { llwe3gzhub = _rtP ->
P_271 ; } else if ( _rtB -> f4ilowdy0t < _rtP -> P_272 ) { llwe3gzhub = _rtP
-> P_272 ; } else { llwe3gzhub = _rtB -> f4ilowdy0t ; } lvo0tpw4vh = (
muDoubleScalarPower ( hhiuns2uat , 2.0 ) + muDoubleScalarPower ( e21lkz4bbc ,
2.0 ) ) - muDoubleScalarCos ( _rtP -> P_273 * llwe3gzhub * _rtP -> P_274 +
_rtP -> P_275 ) * ( 2.0 * hhiuns2uat * e21lkz4bbc ) ; if ( lvo0tpw4vh < 0.0 )
{ lvo0tpw4vh = - muDoubleScalarSqrt ( - lvo0tpw4vh ) ; } else { lvo0tpw4vh =
muDoubleScalarSqrt ( lvo0tpw4vh ) ; } _rtB -> alel31g0ei = lvo0tpw4vh - _rtP
-> P_276 ; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW -> ipf2guf5kv
!= 0 ) ) ) { _rtDW -> pscuiydqnr = _rtP -> P_277 * _rtB -> aajkn5pdud ; } if
( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> ipf2guf5kv = 1 ; _rtB ->
ib4jjpdudr = _rtDW -> pscuiydqnr ; _rtDW -> ipf2guf5kv = 0 ; jnz3yg2px3 =
_rtB -> alel31g0ei - _rtB -> ib4jjpdudr ; if ( jnz3yg2px3 >= _rtP -> P_278 )
{ _rtDW -> fumsexngms = true ; } else { if ( jnz3yg2px3 <= _rtP -> P_279 ) {
_rtDW -> fumsexngms = false ; } } if ( _rtDW -> fumsexngms ) { ae2dep1oyr =
_rtP -> P_280 ; } else { ae2dep1oyr = _rtP -> P_281 ; } _rtB -> hxhb1tehfn =
( _rtP -> P_284 * jnz3yg2px3 - _rtP -> P_283 * _rtDW -> cdtlclcegx ) * _rtP
-> P_285 ; _rtDW -> apkjbfmgwu = ( _rtB -> hxhb1tehfn - _rtP -> P_287 [ 1 ] *
_rtDW -> ap215umohx ) / _rtP -> P_287 [ 0 ] ; _rtB -> pyoiul2yvl = _rtDW ->
faewpkcrfr ; _rtDW -> frjs32r5d5 = ( _rtB -> pyoiul2yvl - _rtP -> P_293 [ 1 ]
* _rtDW -> cst0tsnp5p ) / _rtP -> P_293 [ 0 ] ; _rtB -> j5wqppxc0d = ( _rtP
-> P_290 * jnz3yg2px3 - ( _rtP -> P_292 [ 0 ] * _rtDW -> frjs32r5d5 + _rtP ->
P_292 [ 1 ] * _rtDW -> cst0tsnp5p ) * _rtP -> P_295 ) * _rtP -> P_296 ;
e21lkz4bbc = ( ( _rtP -> P_286 [ 0 ] * _rtDW -> apkjbfmgwu + _rtP -> P_286 [
1 ] * _rtDW -> ap215umohx ) + _rtP -> P_289 * jnz3yg2px3 ) + _rtB ->
j5wqppxc0d ; if ( e21lkz4bbc > _rtP -> P_297 ) { nkij1zvx4o = _rtP -> P_297 ;
} else if ( e21lkz4bbc < _rtP -> P_298 ) { nkij1zvx4o = _rtP -> P_298 ; }
else { nkij1zvx4o = e21lkz4bbc ; } _rtB -> kwbejuxgmj = _rtB -> alel31g0ei -
_rtB -> ib4jjpdudr ; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW ->
bexmglytmi != 0 ) ) ) { _rtDW -> gibdfdest4 = _rtP -> P_299 * _rtB ->
pn131hzyrx ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> bexmglytmi = 1
; _rtB -> ordbqqfm4f = _rtDW -> gibdfdest4 ; _rtDW -> bexmglytmi = 0 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> okpmzwlszi = _rtP -> P_303 * _rtDW
-> pghhpntp0k ; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW ->
fmonm4o1ag != 0 ) ) ) { _rtDW -> pibnpkg2kp = ( _rtB -> fygqumipk1 + _rtB ->
okpmzwlszi ) * _rtP -> P_304 ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW
-> fmonm4o1ag = 1 ; _rtB -> fgy3tvipl3 = _rtDW -> pibnpkg2kp ; _rtDW ->
fmonm4o1ag = 0 ; _rtB -> gcunfakedo = _rtB -> kwbejuxgmj - ( _rtP -> P_305 [
0 ] * _rtB -> ordbqqfm4f + _rtP -> P_305 [ 1 ] * _rtB -> fgy3tvipl3 ) ;
switch ( ( int32_T ) _rtB -> gbnkdxxeun ) { case 1 : _rtB -> kp2wkgocdx =
ae2dep1oyr ; break ; case 2 : _rtB -> kp2wkgocdx = nkij1zvx4o ; break ; case
3 : _rtB -> kp2wkgocdx = _rtP -> P_4 ; break ; case 4 : if ( ssGetTaskTime (
S , 2 ) < _rtP -> P_1 ) { _rtB -> kp2wkgocdx = _rtP -> P_2 ; } else { _rtB ->
kp2wkgocdx = _rtP -> P_3 ; } break ; default : _rtB -> kp2wkgocdx = _rtP ->
P_0 * _rtB -> gcunfakedo ; break ; } ssCallAccelRunBlock ( S , 13 , 463 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 464 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 465 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 466 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> myiovf3hkb = e21lkz4bbc - nkij1zvx4o ; if (
_rtB -> kp2wkgocdx > _rtP -> P_306 ) { _rtB -> fj2siwitfl = _rtP -> P_306 ; }
else if ( _rtB -> kp2wkgocdx < _rtP -> P_307 ) { _rtB -> fj2siwitfl = _rtP ->
P_307 ; } else { _rtB -> fj2siwitfl = _rtB -> kp2wkgocdx ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> ccrol0lzdr = _rtDW -> aymq1cztf4 [
_rtDW -> boewbumlpr ] ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
lkssgrecvc = _rtP -> P_309 * pygprsuz1b * _rtP -> P_310 ; } UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
cdc1qietk5 * _rtB ; nffqwkkk0o * _rtP ; gnhrdqndaw * _rtDW ; _rtDW = ( (
gnhrdqndaw * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( nffqwkkk0o * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( cdc1qietk5 * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtDW -> lofcpccd3v == ( rtInf )
) { _rtDW -> lofcpccd3v = ssGetT ( S ) ; lastU = & _rtDW -> kiduujgizo ; }
else if ( _rtDW -> lskn5i0tu2 == ( rtInf ) ) { _rtDW -> lskn5i0tu2 = ssGetT (
S ) ; lastU = & _rtDW -> lnjwuesc4c ; } else if ( _rtDW -> lofcpccd3v < _rtDW
-> lskn5i0tu2 ) { _rtDW -> lofcpccd3v = ssGetT ( S ) ; lastU = & _rtDW ->
kiduujgizo ; } else { _rtDW -> lskn5i0tu2 = ssGetT ( S ) ; lastU = & _rtDW ->
lnjwuesc4c ; } * lastU = _rtB -> lwtrphnwqm ; _rtDW -> ddcz5bsrj4 = _rtB ->
dhfwk5wgw3 ; _rtDW -> etrlhmj31i = ssGetTaskTime ( S , 0 ) ; _rtDW ->
guyuccv315 = _rtB -> aajkn5pdud ; _rtDW -> nvnj0uqpc1 = _rtB -> pn131hzyrx ;
_rtDW -> kuxx0h0hjr = _rtB -> fygqumipk1 ; _rtDW -> ft4eexgqzb = _rtB ->
foknucrrmx ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtDW -> mprqka25vy =
_rtB -> iipde23lg1 ; _rtDW -> a21gu23ss2 = rt_nrand_Upu32_Yd_f_pw_snf ( &
_rtDW -> oru5anql4n ) * _rtP -> P_199 + _rtP -> P_198 ; _rtDW -> hli3eybjuh =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> kibvnefr2o ) * _rtP -> P_205 + _rtP
-> P_204 ; _rtDW -> est5crkpfo = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
kvnrclqtkg ) * _rtP -> P_211 + _rtP -> P_210 ; } if ( ssIsContinuousTask ( S
, tid ) ) { if ( _rtDW -> in4ciyh5xv == ( rtInf ) ) { _rtDW -> in4ciyh5xv =
ssGetT ( S ) ; lastU = & _rtDW -> drjzfovyiw ; } else if ( _rtDW ->
dkvz24omzk == ( rtInf ) ) { _rtDW -> dkvz24omzk = ssGetT ( S ) ; lastU = &
_rtDW -> biztplgyzb ; } else if ( _rtDW -> in4ciyh5xv < _rtDW -> dkvz24omzk )
{ _rtDW -> in4ciyh5xv = ssGetT ( S ) ; lastU = & _rtDW -> drjzfovyiw ; } else
{ _rtDW -> dkvz24omzk = ssGetT ( S ) ; lastU = & _rtDW -> biztplgyzb ; } *
lastU = _rtB -> eren1giag3 ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW
-> igbe5jrrkp = _rtB -> f4ilowdy0t ; _rtDW -> phsimlohfo = _rtB -> f4ilowdy0t
; _rtDW -> cdtlclcegx = _rtB -> myiovf3hkb ; _rtDW -> ap215umohx = _rtDW ->
apkjbfmgwu ; _rtDW -> faewpkcrfr = _rtB -> j5wqppxc0d ; _rtDW -> cst0tsnp5p =
_rtDW -> frjs32r5d5 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtDW ->
pghhpntp0k = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> aagvbk04st ) * _rtP ->
P_301 + _rtP -> P_300 ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW ->
aymq1cztf4 [ _rtDW -> boewbumlpr == 0 ] = _rtB -> fj2siwitfl ; _rtDW ->
boewbumlpr = ( int8_T ) ( _rtDW -> boewbumlpr == 0 ) ; } UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { cdc1qietk5 * _rtB ; nffqwkkk0o
* _rtP ; mkvrtd44mj * _rtX ; gvd2nzujxx * _rtXdot ; _rtXdot = ( ( gvd2nzujxx
* ) ssGetdX ( S ) ) ; _rtX = ( ( mkvrtd44mj * ) ssGetContStates ( S ) ) ;
_rtP = ( ( nffqwkkk0o * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( cdc1qietk5 *
) _ssGetBlockIO ( S ) ) ; _rtXdot -> drig45tzgq = _rtB -> azegqsok2u ;
_rtXdot -> i5gw4xodpn = 0.0 ; _rtXdot -> i5gw4xodpn += _rtP -> P_42 * _rtX ->
i5gw4xodpn ; _rtXdot -> i5gw4xodpn += _rtB -> lprlyity5x ; _rtXdot ->
pnhrmy1uiy = 0.0 ; _rtXdot -> pnhrmy1uiy += _rtP -> P_46 * _rtX -> pnhrmy1uiy
; _rtXdot -> pnhrmy1uiy += _rtB -> fp2h1ttszi ; _rtXdot -> ppodbibpay = 0.0 ;
_rtXdot -> ppodbibpay += _rtP -> P_50 * _rtX -> ppodbibpay ; _rtXdot ->
ppodbibpay += _rtB -> e1kmntv5m0 ; _rtXdot -> puv5m1t14e [ 0 ] = _rtB ->
pqzatmkaqm [ 0 ] ; _rtXdot -> puv5m1t14e [ 1 ] = _rtB -> pqzatmkaqm [ 1 ] ;
_rtXdot -> puv5m1t14e [ 2 ] = _rtB -> pqzatmkaqm [ 2 ] ; _rtXdot ->
oarjlg0z11 = 0.0 ; _rtXdot -> oarjlg0z11 += _rtP -> P_61 * _rtX -> oarjlg0z11
; _rtXdot -> oarjlg0z11 += _rtB -> ccrol0lzdr ; _rtXdot -> k1z5ksayfm = _rtB
-> n5v0xcyhwf ; _rtXdot -> fmmi3ei4ik = _rtB -> mvmvnwt4kc ; _rtXdot ->
f11ic0i0dy = _rtB -> lvnpppsyaq ; _rtXdot -> eo0bwreyi4 = _rtB -> kcpvnpttau
; _rtXdot -> p0s35axnlc = 0.0 ; _rtXdot -> p0s35axnlc += _rtP -> P_76 * _rtX
-> p0s35axnlc ; _rtXdot -> p0s35axnlc += _rtB -> kzte5nxxvp ; _rtXdot ->
gsa5h5kyri = _rtB -> mbz0o5xdfy ; _rtXdot -> fspor4sjtq [ 0 ] = 0.0 ; _rtXdot
-> fspor4sjtq [ 1 ] = 0.0 ; _rtXdot -> fspor4sjtq [ 0 ] += _rtP -> P_225 [ 0
] * _rtX -> fspor4sjtq [ 0 ] ; _rtXdot -> fspor4sjtq [ 0 ] += _rtP -> P_225 [
1 ] * _rtX -> fspor4sjtq [ 1 ] ; _rtXdot -> fspor4sjtq [ 1 ] += _rtX ->
fspor4sjtq [ 0 ] ; _rtXdot -> fspor4sjtq [ 0 ] += _rtB -> he2jhyzdjm ;
_rtXdot -> cxsfbwsttm [ 0 ] = 0.0 ; _rtXdot -> cxsfbwsttm [ 1 ] = 0.0 ;
_rtXdot -> cxsfbwsttm [ 0 ] += _rtP -> P_231 [ 0 ] * _rtX -> cxsfbwsttm [ 0 ]
; _rtXdot -> cxsfbwsttm [ 0 ] += _rtP -> P_231 [ 1 ] * _rtX -> cxsfbwsttm [ 1
] ; _rtXdot -> cxsfbwsttm [ 1 ] += _rtX -> cxsfbwsttm [ 0 ] ; _rtXdot ->
cxsfbwsttm [ 0 ] += _rtB -> gasw43jrmv ; _rtXdot -> p4ateoyaz0 = 0.0 ;
_rtXdot -> p4ateoyaz0 += _rtP -> P_240 * _rtX -> p4ateoyaz0 ; _rtXdot ->
p4ateoyaz0 += _rtB -> lkssgrecvc ; } static void mdlInitializeSizes (
SimStruct * S ) { ssSetChecksumVal ( S , 0 , 604654644U ) ; ssSetChecksumVal
( S , 1 , 2066612932U ) ; ssSetChecksumVal ( S , 2 , 2339479734U ) ;
ssSetChecksumVal ( S , 3 , 252936619U ) ; { mxArray * slVerStructMat = NULL ;
mxArray * slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ;
int status = mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" )
; if ( status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
gnhrdqndaw ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( cdc1qietk5 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofY ( S ) != sizeof
( elxtisijyd ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalOutputs sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
nffqwkkk0o ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & ba4bxx1frp ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
nffqwkkk0o * ) ssGetDefaultParam ( S ) ) -> P_182 = rtInf ; ( ( nffqwkkk0o *
) ssGetDefaultParam ( S ) ) -> P_185 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
