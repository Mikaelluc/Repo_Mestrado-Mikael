#include "__cf_RudderActuatorChannel_control_linear.h"
#include <math.h>
#include "RudderActuatorChannel_control_linear_acc.h"
#include "RudderActuatorChannel_control_linear_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; } real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo
; uint32_T hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if
( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T y ; real_T sr ; real_T
si ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static void mdlOutputs ( SimStruct * S , int_T tid ) {
real_T bu2wug5fr4 ; real_T jqpp32g4mz ; int_T iy ; real_T * lastU ; int32_T k
; real_T laxcf0imdv ; real_T pxk3ad1tcz ; real_T cvsoeatfg4 ; real_T
jnz3yg2px3 ; real_T gem3xqzrlf ; real_T dbvvkcgiuo [ 3 ] ; real_T hhiuns2uat
; real_T lzyldtmkry ; real_T e21lkz4bbc ; real_T fqyr3rnt2f ; real_T
nkij1zvx4o ; real_T ae2dep1oyr ; real_T lvo0tpw4vh ; real_T bcyur5ht2d ;
real_T ilmfw3a43s ; real_T l5uluf1r3z ; real_T tmp [ 5 ] ; real_T tmp_p [ 3 ]
; real_T cmt52dftsj_idx_0 ; real_T cmt52dftsj_idx_1 ; real_T cmt52dftsj_idx_2
; real_T khnbliiguu_idx_0 ; real_T khnbliiguu_idx_1 ; real_T khnbliiguu_idx_2
; fqdvu2maow * _rtB ; np4fzkawzt * _rtP ; ow1fcyt2w5 * _rtX ; gs3voni0mk *
_rtDW ; _rtDW = ( ( gs3voni0mk * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
ow1fcyt2w5 * ) ssGetContStates ( S ) ) ; _rtP = ( ( np4fzkawzt * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fqdvu2maow * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> o2opmjctkr = _rtP -> P_11 ; }
if ( ssIsContinuousTask ( S , tid ) ) { bu2wug5fr4 = ssGetT ( S ) ; _rtB ->
pf223njvoo = ssGetTStart ( S ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> pxhk5fwgcz = _rtP -> P_12 ; } if ( ssIsContinuousTask ( S , tid ) ) {
jqpp32g4mz = ssGetT ( S ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
psl2wogm0u = _rtP -> P_13 / _rtP -> P_14 * _rtP -> P_15 ; _rtB -> pbdsp1dy15
= _rtP -> P_16 ; _rtB -> h5jm0nlpvl = _rtP -> P_17 ; } if (
ssIsContinuousTask ( S , tid ) ) { lvo0tpw4vh = muDoubleScalarSin ( _rtP ->
P_20 * ssGetTaskTime ( S , 0 ) + _rtP -> P_21 ) * _rtP -> P_18 + _rtP -> P_19
; if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_22 ) { laxcf0imdv = _rtP -> P_23 ;
} else { laxcf0imdv = _rtP -> P_24 ; } } if ( ssIsSampleHit ( S , 1 , tid ) )
{ _rtB -> l4av5shrni = _rtP -> P_25 ; } if ( ssIsContinuousTask ( S , tid ) )
{ ssCallAccelRunBlock ( S , 14 , 14 , SS_CALL_MDL_OUTPUTS ) ; switch ( (
int32_T ) _rtB -> o2opmjctkr ) { case 1 : _rtB -> j3nghlcafs = look1_binlxpw
( muDoubleScalarRem ( bu2wug5fr4 - _rtB -> pf223njvoo , _rtB -> pxhk5fwgcz )
, _rtP -> P_10 , _rtP -> P_9 , 1U ) ; break ; case 2 : if ( _rtB ->
h5jm0nlpvl > _rtP -> P_8 ) { _rtB -> j3nghlcafs = muDoubleScalarSin ( (
jqpp32g4mz * _rtB -> psl2wogm0u + _rtB -> pbdsp1dy15 ) * jqpp32g4mz ) ; }
else { _rtB -> j3nghlcafs = lvo0tpw4vh ; } break ; case 3 : _rtB ->
j3nghlcafs = laxcf0imdv ; break ; default : switch ( ( int32_T ) _rtB ->
l4av5shrni ) { case 1 : _rtB -> j3nghlcafs = _rtB -> ikbzrtsmir [ 0 ] ; break
; case 2 : _rtB -> j3nghlcafs = _rtB -> ikbzrtsmir [ 1 ] ; break ; case 3 :
_rtB -> j3nghlcafs = _rtB -> ikbzrtsmir [ 2 ] ; break ; default : _rtB ->
j3nghlcafs = _rtB -> ikbzrtsmir [ 3 ] ; break ; } break ; }
ssCallAccelRunBlock ( S , 14 , 19 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> piafrah0n1 = _rtP -> P_26 ; _rtB ->
nmph3qw5iv = _rtP -> P_27 ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
fg4zlkxkrg [ 0 ] = 0.0 ; _rtB -> fg4zlkxkrg [ 1 ] = 0.0 ; _rtB -> fg4zlkxkrg
[ 2 ] = 0.0 ; k = 0 ; while ( k < 1 ) { _rtB -> fg4zlkxkrg [ 0 ] += _rtP ->
P_30 [ 0 ] * _rtX -> ofud5z2sku [ 4 ] ; k = 1 ; } while ( k < 2 ) { _rtB ->
fg4zlkxkrg [ 1 ] += _rtP -> P_30 [ 1 ] * _rtX -> ofud5z2sku [ 3 ] ; k = 2 ; }
while ( k < 3 ) { _rtB -> fg4zlkxkrg [ 2 ] += _rtP -> P_30 [ 2 ] * _rtX ->
ofud5z2sku [ 0 ] ; k = 3 ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
geli3mzqsq = _rtP -> P_32 ; } if ( ssIsContinuousTask ( S , tid ) ) {
cvsoeatfg4 = _rtB -> fg4zlkxkrg [ 0 ] + _rtB -> geli3mzqsq ; lvo0tpw4vh = ( (
muDoubleScalarPower ( _rtB -> piafrah0n1 , 2.0 ) + muDoubleScalarPower ( _rtB
-> nmph3qw5iv , 2.0 ) ) - muDoubleScalarPower ( cvsoeatfg4 , 2.0 ) ) / ( 2.0
* _rtB -> piafrah0n1 * _rtB -> nmph3qw5iv ) ; if ( lvo0tpw4vh > 1.0 ) {
lvo0tpw4vh = 1.0 ; } else { if ( lvo0tpw4vh < - 1.0 ) { lvo0tpw4vh = - 1.0 ;
} } pxk3ad1tcz = muDoubleScalarAcos ( lvo0tpw4vh ) ; } if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtB -> ejk3gx4e4j = _rtP -> P_33 ; } if ( ssIsContinuousTask
( S , tid ) ) { _rtB -> egc5yg5tzc = ( pxk3ad1tcz - _rtB -> ejk3gx4e4j ) *
_rtP -> P_34 ; ssCallAccelRunBlock ( S , 14 , 29 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> dtqovxkfwi >= ssGetT ( S ) ) && ( _rtDW -> dypc4bbpon >= ssGetT
( S ) ) ) { _rtB -> c0pql5yn2w = 0.0 ; } else { laxcf0imdv = _rtDW ->
dtqovxkfwi ; lastU = & _rtDW -> e1jrztsh0f ; if ( _rtDW -> dtqovxkfwi < _rtDW
-> dypc4bbpon ) { if ( _rtDW -> dypc4bbpon < ssGetT ( S ) ) { laxcf0imdv =
_rtDW -> dypc4bbpon ; lastU = & _rtDW -> etqwvqh04u ; } } else { if ( _rtDW
-> dtqovxkfwi >= ssGetT ( S ) ) { laxcf0imdv = _rtDW -> dypc4bbpon ; lastU =
& _rtDW -> etqwvqh04u ; } } _rtB -> c0pql5yn2w = ( _rtB -> egc5yg5tzc - *
lastU ) / ( ssGetT ( S ) - laxcf0imdv ) ; } ssCallAccelRunBlock ( S , 14 , 31
, SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
ktoal4emd5 = _rtP -> P_35 ; } if ( ssIsContinuousTask ( S , tid ) ) {
jnz3yg2px3 = muDoubleScalarSin ( _rtP -> P_38 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_39 ) * _rtP -> P_36 + _rtP -> P_37 ; lvo0tpw4vh = ( (
muDoubleScalarPower ( cvsoeatfg4 , 2.0 ) + muDoubleScalarPower ( _rtB ->
piafrah0n1 , 2.0 ) ) - muDoubleScalarPower ( _rtB -> nmph3qw5iv , 2.0 ) ) / (
2.0 * cvsoeatfg4 * _rtB -> piafrah0n1 ) ; if ( lvo0tpw4vh > 1.0 ) {
lvo0tpw4vh = 1.0 ; } else { if ( lvo0tpw4vh < - 1.0 ) { lvo0tpw4vh = - 1.0 ;
} } cvsoeatfg4 = muDoubleScalarAcos ( lvo0tpw4vh ) ; _rtB -> p0rrnvctba =
_rtB -> piafrah0n1 * muDoubleScalarSin ( cvsoeatfg4 ) ; } if ( ssIsSampleHit
( S , 1 , tid ) ) { _rtB -> k1io5gifsi = _rtP -> P_40 ; } if (
ssIsContinuousTask ( S , tid ) ) { switch ( ( int32_T ) _rtB -> ktoal4emd5 )
{ case 1 : _rtB -> gd2ck0d3qk = jnz3yg2px3 ; break ; case 2 : laxcf0imdv =
look1_binlxpw ( _rtP -> P_5 * _rtB -> egc5yg5tzc , _rtP -> P_7 , _rtP -> P_6
, 2U ) ; _rtB -> gd2ck0d3qk = laxcf0imdv / _rtB -> p0rrnvctba ; break ;
default : _rtB -> gd2ck0d3qk = _rtB -> k1io5gifsi ; break ; }
ssCallAccelRunBlock ( S , 14 , 40 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 41 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 42 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 43 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 44 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 14 , 45 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) {
ssCallAccelRunBlock ( S , 14 , 46 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> luzpdv1nr2 = _rtP -> P_41 ; _rtB ->
myunwcaiy3 = _rtP -> P_42 ; } if ( ssIsContinuousTask ( S , tid ) ) { if (
_rtDW -> e5gheszy35 == ( rtInf ) ) { _rtB -> fpfaurkxom = _rtB -> j3nghlcafs
; } else { laxcf0imdv = ssGetTaskTime ( S , 0 ) - _rtDW -> e5gheszy35 ;
lvo0tpw4vh = laxcf0imdv * _rtP -> P_43 ; jnz3yg2px3 = _rtB -> j3nghlcafs -
_rtDW -> hkfowgtizw ; if ( jnz3yg2px3 > lvo0tpw4vh ) { _rtB -> fpfaurkxom =
_rtDW -> hkfowgtizw + lvo0tpw4vh ; } else { laxcf0imdv *= _rtP -> P_44 ; if (
jnz3yg2px3 < laxcf0imdv ) { _rtB -> fpfaurkxom = _rtDW -> hkfowgtizw +
laxcf0imdv ; } else { _rtB -> fpfaurkxom = _rtB -> j3nghlcafs ; } } } if (
_rtB -> fpfaurkxom > _rtP -> P_45 ) { lvo0tpw4vh = _rtP -> P_45 ; } else if (
_rtB -> fpfaurkxom < _rtP -> P_46 ) { lvo0tpw4vh = _rtP -> P_46 ; } else {
lvo0tpw4vh = _rtB -> fpfaurkxom ; } gem3xqzrlf = _rtP -> P_47 * lvo0tpw4vh *
_rtP -> P_48 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> pgvcrcxkbx =
_rtP -> P_49 ; } if ( ssIsContinuousTask ( S , tid ) ) { lvo0tpw4vh = (
muDoubleScalarPower ( _rtB -> luzpdv1nr2 , 2.0 ) + muDoubleScalarPower ( _rtB
-> myunwcaiy3 , 2.0 ) ) - 2.0 * _rtB -> luzpdv1nr2 * _rtB -> myunwcaiy3 *
muDoubleScalarCos ( gem3xqzrlf + _rtB -> pgvcrcxkbx ) ; if ( lvo0tpw4vh < 0.0
) { cvsoeatfg4 = - muDoubleScalarSqrt ( - lvo0tpw4vh ) ; } else { cvsoeatfg4
= muDoubleScalarSqrt ( lvo0tpw4vh ) ; } } if ( ssIsSampleHit ( S , 1 , tid )
) { _rtB -> ehyzgwnlnk = _rtP -> P_50 ; } if ( ssIsContinuousTask ( S , tid )
) { _rtB -> nnvarwygk0 = cvsoeatfg4 - _rtB -> ehyzgwnlnk ; _rtB -> bq2bxz0xad
= 0.0 ; _rtB -> bq2bxz0xad += _rtP -> P_52 * _rtX -> e1gyirzq21 ; laxcf0imdv
= _rtP -> P_53 / 2.0 ; if ( _rtB -> bq2bxz0xad < _rtDW -> hpnim1mvod -
laxcf0imdv ) { _rtB -> gg2zboyf5y = _rtB -> bq2bxz0xad + laxcf0imdv ; } else
if ( _rtB -> bq2bxz0xad <= _rtDW -> hpnim1mvod + laxcf0imdv ) { _rtB ->
gg2zboyf5y = _rtDW -> hpnim1mvod ; } else { _rtB -> gg2zboyf5y = _rtB ->
bq2bxz0xad - laxcf0imdv ; } _rtB -> evm4d0d1nm = 0.0 ; _rtB -> evm4d0d1nm +=
_rtP -> P_56 * _rtX -> hwsq5vmkdy ; laxcf0imdv = _rtP -> P_57 / 2.0 ; if (
_rtB -> evm4d0d1nm < _rtDW -> flnfzrpkf3 - laxcf0imdv ) { _rtB -> iodwdqkhoj
= _rtB -> evm4d0d1nm + laxcf0imdv ; } else if ( _rtB -> evm4d0d1nm <= _rtDW
-> flnfzrpkf3 + laxcf0imdv ) { _rtB -> iodwdqkhoj = _rtDW -> flnfzrpkf3 ; }
else { _rtB -> iodwdqkhoj = _rtB -> evm4d0d1nm - laxcf0imdv ; } _rtB ->
jdnpe2k3ke = 0.0 ; _rtB -> jdnpe2k3ke += _rtP -> P_60 * _rtX -> mj5udpiwnl ;
laxcf0imdv = _rtP -> P_61 / 2.0 ; if ( _rtB -> jdnpe2k3ke < _rtDW ->
cpc44mw3f2 - laxcf0imdv ) { _rtB -> oqrrphjlgy = _rtB -> jdnpe2k3ke +
laxcf0imdv ; } else if ( _rtB -> jdnpe2k3ke <= _rtDW -> cpc44mw3f2 +
laxcf0imdv ) { _rtB -> oqrrphjlgy = _rtDW -> cpc44mw3f2 ; } else { _rtB ->
oqrrphjlgy = _rtB -> jdnpe2k3ke - laxcf0imdv ; } cmt52dftsj_idx_0 = _rtB ->
iodwdqkhoj ; cmt52dftsj_idx_1 = _rtB -> oqrrphjlgy ; cmt52dftsj_idx_2 = _rtB
-> gg2zboyf5y ; khnbliiguu_idx_0 = _rtX -> gnskp4i0f1 [ 0 ] ;
khnbliiguu_idx_1 = _rtX -> gnskp4i0f1 [ 1 ] ; khnbliiguu_idx_2 = _rtX ->
gnskp4i0f1 [ 2 ] ; for ( k = 0 ; k < 3 ; k ++ ) { dbvvkcgiuo [ k ] = ( ( _rtP
-> P_63 [ k + 3 ] * _rtB -> oqrrphjlgy + _rtP -> P_63 [ k ] * _rtB ->
iodwdqkhoj ) + _rtP -> P_63 [ k + 6 ] * _rtB -> gg2zboyf5y ) + _rtX ->
gnskp4i0f1 [ k ] ; } tmp [ 0 ] = _rtB -> iodwdqkhoj ; tmp [ 1 ] = dbvvkcgiuo
[ 0 ] ; tmp [ 2 ] = dbvvkcgiuo [ 1 ] ; tmp [ 3 ] = _rtB -> oqrrphjlgy ; tmp [
4 ] = dbvvkcgiuo [ 2 ] ; pxk3ad1tcz = 0.0 ; for ( k = 0 ; k < 5 ; k ++ ) {
pxk3ad1tcz += _rtP -> P_65 [ k ] * tmp [ k ] ; } _rtB -> kzdrkjoy0e = ( (
_rtB -> nnvarwygk0 - _rtB -> gg2zboyf5y ) - pxk3ad1tcz ) * _rtP -> P_66 ; if
( _rtB -> kzdrkjoy0e > _rtP -> P_67 ) { _rtB -> ool5lubtht = _rtP -> P_67 ; }
else if ( _rtB -> kzdrkjoy0e < _rtP -> P_68 ) { _rtB -> ool5lubtht = _rtP ->
P_68 ; } else { _rtB -> ool5lubtht = _rtB -> kzdrkjoy0e ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> akqbxnv2ew = _rtP -> P_69 ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> dimiqhd4sb = _rtP -> P_71 * _rtX
-> nq4ergvzwf * _rtP -> P_72 ; if ( _rtB -> akqbxnv2ew >= _rtP -> P_73 ) {
_rtB -> oud3yjwrph = _rtB -> ool5lubtht ; } else { _rtB -> oud3yjwrph = _rtB
-> dimiqhd4sb ; } if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_74 ) { _rtB ->
pksw3jwdh1 = _rtP -> P_75 ; } else { _rtB -> pksw3jwdh1 = _rtP -> P_76 ; }
ssCallAccelRunBlock ( S , 14 , 79 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 14 , 80 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 81 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 82 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { for ( iy =
0 ; iy < 6 ; iy ++ ) { _rtB -> h0134ob2un [ iy ] = 0.0 ; } for ( iy = 0 ; iy
< 6 ; iy ++ ) { for ( k = iy ; k < iy + 1 ; k ++ ) { _rtB -> h0134ob2un [ iy
] += _rtP -> P_79 [ k ] * _rtX -> piybse5prj [ k ] ; } } } if ( ssIsSampleHit
( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 14 , 84 , SS_CALL_MDL_OUTPUTS )
; if ( ssGetLogOutput ( S ) ) { { const char * errMsg = ( NULL ) ; void * fp
= ( void * ) _rtDW -> mfgsp24sxv . FilePtr ; if ( fp != ( NULL ) ) { { real_T
t ; void * u ; t = ssGetTaskTime ( S , 1 ) ; u = ( void * ) & _rtB ->
h0134ob2un [ 0 ] ; errMsg = rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u
) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( S , errMsg ) ; return ; }
} } } } } if ( ssIsContinuousTask ( S , tid ) ) { bcyur5ht2d = look1_binlxpw
( _rtB -> fg4zlkxkrg [ 0 ] , _rtP -> P_82 , _rtP -> P_81 , 2U ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> mm3e3mlwmu = _rtDW -> jgkemazxun ;
} if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtB -> mm3e3mlwmu >= _rtP ->
P_86 ) { _rtB -> je1pg3vprd = _rtB -> fg4zlkxkrg [ 0 ] + bcyur5ht2d ; } else
{ _rtB -> je1pg3vprd = _rtB -> fg4zlkxkrg [ 0 ] - bcyur5ht2d ; } ilmfw3a43s =
look1_binlxpw ( _rtB -> fg4zlkxkrg [ 2 ] , _rtP -> P_88 , _rtP -> P_87 , 2U )
; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> laxdymwia0 = _rtDW ->
cuctsmauno ; } if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtB ->
laxdymwia0 >= _rtP -> P_92 ) { _rtB -> akpegiyksd = _rtB -> fg4zlkxkrg [ 2 ]
+ ilmfw3a43s ; } else { _rtB -> akpegiyksd = _rtB -> fg4zlkxkrg [ 2 ] -
ilmfw3a43s ; } l5uluf1r3z = look1_binlxpw ( _rtB -> fg4zlkxkrg [ 1 ] , _rtP
-> P_94 , _rtP -> P_93 , 2U ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB
-> mrevivaawb = _rtDW -> bs4h2bf0nx ; } if ( ssIsContinuousTask ( S , tid ) )
{ if ( _rtB -> mrevivaawb >= _rtP -> P_98 ) { _rtB -> ne01rh5nsj = _rtB ->
fg4zlkxkrg [ 1 ] + l5uluf1r3z ; } else { _rtB -> ne01rh5nsj = _rtB ->
fg4zlkxkrg [ 1 ] - l5uluf1r3z ; } ssCallAccelRunBlock ( S , 14 , 101 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 14 , 102 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 103 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 104 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 105 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { for ( k = 0 ; k < 3 ; k ++ ) { dbvvkcgiuo
[ k ] = ( ( _rtP -> P_100 [ k + 3 ] * cmt52dftsj_idx_1 + _rtP -> P_100 [ k ]
* cmt52dftsj_idx_0 ) + _rtP -> P_100 [ k + 6 ] * cmt52dftsj_idx_2 ) + _rtP ->
P_101 [ k ] * _rtB -> ool5lubtht ; } for ( k = 0 ; k < 3 ; k ++ ) { tmp_p [ k
] = _rtP -> P_99 [ k + 6 ] * khnbliiguu_idx_2 + ( _rtP -> P_99 [ k + 3 ] *
khnbliiguu_idx_1 + _rtP -> P_99 [ k ] * khnbliiguu_idx_0 ) ; } _rtB ->
gt1ce1fuae [ 0 ] = dbvvkcgiuo [ 0 ] + tmp_p [ 0 ] ; _rtB -> gt1ce1fuae [ 1 ]
= dbvvkcgiuo [ 1 ] + tmp_p [ 1 ] ; _rtB -> gt1ce1fuae [ 2 ] = dbvvkcgiuo [ 2
] + tmp_p [ 2 ] ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtB -> dighgd5hb3
= _rtP -> P_102 ; _rtB -> atfpx2r4ay = _rtP -> P_103 ; ssCallAccelRunBlock (
S , 14 , 112 , SS_CALL_MDL_OUTPUTS ) ; hhiuns2uat = _rtP -> P_104 ;
lzyldtmkry = _rtP -> P_105 ; } if ( ssIsContinuousTask ( S , tid ) && ( ! (
_rtDW -> da1nobwege != 0 ) ) ) { _rtDW -> mt5f5ij4ko = _rtB -> j3nghlcafs ; }
if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> da1nobwege = 1 ; _rtB ->
atfpx2r4ay = _rtDW -> mt5f5ij4ko ; _rtDW -> da1nobwege = 0 ; lvo0tpw4vh = (
_rtB -> atfpx2r4ay - _rtDW -> orq2j0rkqo ) * _rtP -> P_107 ; if ( lvo0tpw4vh
> _rtP -> P_108 ) { lvo0tpw4vh = _rtP -> P_108 ; } else { if ( lvo0tpw4vh <
_rtP -> P_109 ) { lvo0tpw4vh = _rtP -> P_109 ; } } _rtB -> fzghtrugeh = _rtP
-> P_110 * lvo0tpw4vh + _rtDW -> ijrehq3wvu ; if ( _rtB -> fzghtrugeh > _rtP
-> P_112 ) { lvo0tpw4vh = _rtP -> P_112 ; } else if ( _rtB -> fzghtrugeh <
_rtP -> P_113 ) { lvo0tpw4vh = _rtP -> P_113 ; } else { lvo0tpw4vh = _rtB ->
fzghtrugeh ; } _rtB -> dighgd5hb3 = _rtP -> P_114 * lvo0tpw4vh * _rtP ->
P_115 ; lvo0tpw4vh = ( muDoubleScalarPower ( hhiuns2uat , 2.0 ) +
muDoubleScalarPower ( lzyldtmkry , 2.0 ) ) - 2.0 * hhiuns2uat * lzyldtmkry *
muDoubleScalarCos ( _rtB -> dighgd5hb3 + _rtP -> P_116 ) ; e21lkz4bbc = _rtP
-> P_117 ; if ( lvo0tpw4vh < 0.0 ) { lvo0tpw4vh = - muDoubleScalarSqrt ( -
lvo0tpw4vh ) ; } else { lvo0tpw4vh = muDoubleScalarSqrt ( lvo0tpw4vh ) ; }
_rtB -> kfejzd24cq = lvo0tpw4vh - _rtP -> P_117 ; fqyr3rnt2f = _rtP -> P_118
; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW -> ec3tk2w2pd != 0 ) )
) { _rtDW -> lwmd1n40ae = _rtP -> P_119 * _rtB -> gg2zboyf5y ; } if (
ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> ec3tk2w2pd = 1 ; _rtB ->
dvafaumngw = _rtDW -> lwmd1n40ae ; _rtDW -> ec3tk2w2pd = 0 ; if ( ( int32_T )
fqyr3rnt2f == 0 ) { fqyr3rnt2f = _rtB -> dvafaumngw ; } else { fqyr3rnt2f =
0.0 ; } _rtB -> mjx20savei = _rtB -> kfejzd24cq - fqyr3rnt2f ; if ( _rtB ->
mjx20savei >= _rtP -> P_120 ) { _rtDW -> pjffzpezd5 = true ; } else { if (
_rtB -> mjx20savei <= _rtP -> P_121 ) { _rtDW -> pjffzpezd5 = false ; } } if
( _rtDW -> pjffzpezd5 ) { ae2dep1oyr = _rtP -> P_122 ; } else { ae2dep1oyr =
_rtP -> P_123 ; } _rtB -> haglqedtmg = ( _rtP -> P_126 * _rtB -> mjx20savei -
_rtP -> P_125 * _rtDW -> e4tagilch2 ) * _rtP -> P_127 ; _rtDW -> ivw5jkde1g =
( _rtB -> haglqedtmg - _rtP -> P_129 [ 1 ] * _rtDW -> jvudlpyk2p ) / _rtP ->
P_129 [ 0 ] ; _rtB -> iigbdikux3 = _rtDW -> m4v2rh2lh0 ; _rtDW -> ex0p3kmj3s
= ( _rtB -> iigbdikux3 - _rtP -> P_135 [ 1 ] * _rtDW -> phkclogpvf ) / _rtP
-> P_135 [ 0 ] ; _rtB -> hz50o1ao5h = ( _rtP -> P_132 * _rtB -> mjx20savei -
( _rtP -> P_134 [ 0 ] * _rtDW -> ex0p3kmj3s + _rtP -> P_134 [ 1 ] * _rtDW ->
phkclogpvf ) * _rtP -> P_137 ) * _rtP -> P_138 ; e21lkz4bbc = ( ( _rtP ->
P_128 [ 0 ] * _rtDW -> ivw5jkde1g + _rtP -> P_128 [ 1 ] * _rtDW -> jvudlpyk2p
) + _rtP -> P_131 * _rtB -> mjx20savei ) + _rtB -> hz50o1ao5h ; if (
e21lkz4bbc > _rtP -> P_139 ) { nkij1zvx4o = _rtP -> P_139 ; } else if (
e21lkz4bbc < _rtP -> P_140 ) { nkij1zvx4o = _rtP -> P_140 ; } else {
nkij1zvx4o = e21lkz4bbc ; } _rtB -> bxfep4p0xx = _rtB -> kfejzd24cq - _rtB ->
dvafaumngw ; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW ->
ptjosj1jg5 != 0 ) ) ) { _rtDW -> mhfppgsdtx = _rtP -> P_141 * _rtB ->
iodwdqkhoj ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW -> ptjosj1jg5 = 1
; _rtB -> a4zhgwgwdf = _rtDW -> mhfppgsdtx ; _rtDW -> ptjosj1jg5 = 0 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> m0zuos4qj5 = _rtP -> P_145 * _rtDW
-> asjmy1pcli ; } if ( ssIsContinuousTask ( S , tid ) && ( ! ( _rtDW ->
g5153iw1vg != 0 ) ) ) { _rtDW -> jx2hh2r3wu = ( _rtB -> oqrrphjlgy + _rtB ->
m0zuos4qj5 ) * _rtP -> P_146 ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW
-> g5153iw1vg = 1 ; _rtB -> nd0pwboc4z = _rtDW -> jx2hh2r3wu ; _rtDW ->
g5153iw1vg = 0 ; _rtB -> njvco1fbro = _rtB -> bxfep4p0xx - ( _rtP -> P_147 [
0 ] * _rtB -> a4zhgwgwdf + _rtP -> P_147 [ 1 ] * _rtB -> nd0pwboc4z ) ;
switch ( ( int32_T ) _rtB -> oqw2ir0yoz ) { case 1 : _rtB -> ji5lcton0h =
ae2dep1oyr ; break ; case 2 : _rtB -> ji5lcton0h = nkij1zvx4o ; break ; case
3 : _rtB -> ji5lcton0h = _rtP -> P_4 ; break ; case 4 : if ( ssGetTaskTime (
S , 2 ) < _rtP -> P_1 ) { _rtB -> ji5lcton0h = _rtP -> P_2 ; } else { _rtB ->
ji5lcton0h = _rtP -> P_3 ; } break ; default : _rtB -> ji5lcton0h = _rtP ->
P_0 * _rtB -> njvco1fbro ; break ; } ssCallAccelRunBlock ( S , 14 , 167 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 168 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 169 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 170 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 171 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> fhxsxnvanp = e21lkz4bbc - nkij1zvx4o ; if (
_rtB -> ji5lcton0h > _rtP -> P_148 ) { _rtB -> gughit5spb = _rtP -> P_148 ; }
else if ( _rtB -> ji5lcton0h < _rtP -> P_149 ) { _rtB -> gughit5spb = _rtP ->
P_149 ; } else { _rtB -> gughit5spb = _rtB -> ji5lcton0h ; } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> nadthfpkvf = _rtDW -> o0ftgpy5vh [
_rtDW -> fpw3u05azd ] ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fqdvu2maow * _rtB ; np4fzkawzt * _rtP ; gs3voni0mk * _rtDW ; _rtDW = ( (
gs3voni0mk * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( np4fzkawzt * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fqdvu2maow * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsContinuousTask ( S , tid ) ) { if ( _rtDW -> dtqovxkfwi == ( rtInf )
) { _rtDW -> dtqovxkfwi = ssGetT ( S ) ; lastU = & _rtDW -> e1jrztsh0f ; }
else if ( _rtDW -> dypc4bbpon == ( rtInf ) ) { _rtDW -> dypc4bbpon = ssGetT (
S ) ; lastU = & _rtDW -> etqwvqh04u ; } else if ( _rtDW -> dtqovxkfwi < _rtDW
-> dypc4bbpon ) { _rtDW -> dtqovxkfwi = ssGetT ( S ) ; lastU = & _rtDW ->
e1jrztsh0f ; } else { _rtDW -> dypc4bbpon = ssGetT ( S ) ; lastU = & _rtDW ->
etqwvqh04u ; } * lastU = _rtB -> egc5yg5tzc ; _rtDW -> hkfowgtizw = _rtB ->
fpfaurkxom ; _rtDW -> e5gheszy35 = ssGetTaskTime ( S , 0 ) ; _rtDW ->
hpnim1mvod = _rtB -> gg2zboyf5y ; _rtDW -> flnfzrpkf3 = _rtB -> iodwdqkhoj ;
_rtDW -> cpc44mw3f2 = _rtB -> oqrrphjlgy ; } if ( ssIsSampleHit ( S , 1 , tid
) ) { _rtDW -> jgkemazxun = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
nyuqr3myvb ) * _rtP -> P_84 + _rtP -> P_83 ; _rtDW -> cuctsmauno =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> kdrpi3dr4k ) * _rtP -> P_90 + _rtP ->
P_89 ; _rtDW -> bs4h2bf0nx = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
ad0bpxbdty ) * _rtP -> P_96 + _rtP -> P_95 ; } if ( ssIsSampleHit ( S , 2 ,
tid ) ) { _rtDW -> orq2j0rkqo = _rtB -> fzghtrugeh ; _rtDW -> ijrehq3wvu =
_rtB -> fzghtrugeh ; _rtDW -> e4tagilch2 = _rtB -> fhxsxnvanp ; _rtDW ->
jvudlpyk2p = _rtDW -> ivw5jkde1g ; _rtDW -> m4v2rh2lh0 = _rtB -> hz50o1ao5h ;
_rtDW -> phkclogpvf = _rtDW -> ex0p3kmj3s ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { _rtDW -> asjmy1pcli = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
bsiysoz10k ) * _rtP -> P_143 + _rtP -> P_142 ; } if ( ssIsSampleHit ( S , 2 ,
tid ) ) { _rtDW -> o0ftgpy5vh [ _rtDW -> fpw3u05azd == 0 ] = _rtB ->
gughit5spb ; _rtDW -> fpw3u05azd = ( int8_T ) ( _rtDW -> fpw3u05azd == 0 ) ;
} UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { int_T is ; int_T ci ; static
const int8_T ir [ 7 ] = { 0 , 1 , 2 , 5 , 9 , 10 , 12 } ; static const int8_T
ir_p [ 7 ] = { 0 , 0 , 0 , 1 , 1 , 1 , 1 } ; static const int8_T jc [ 12 ] =
{ 1 , 2 , 0 , 1 , 2 , 0 , 3 , 4 , 5 , 5 , 3 , 5 } ; fqdvu2maow * _rtB ;
np4fzkawzt * _rtP ; ow1fcyt2w5 * _rtX ; oasglgycu1 * _rtXdot ; _rtXdot = ( (
oasglgycu1 * ) ssGetdX ( S ) ) ; _rtX = ( ( ow1fcyt2w5 * ) ssGetContStates (
S ) ) ; _rtP = ( ( np4fzkawzt * ) ssGetDefaultParam ( S ) ) ; _rtB = ( (
fqdvu2maow * ) _ssGetBlockIO ( S ) ) ; for ( is = 0 ; is < 6 ; is ++ ) {
_rtXdot -> ofud5z2sku [ is ] = 0.0 ; } for ( is = 0 ; is < 6 ; is ++ ) { for
( ci = ir [ is ] ; ci < ir [ is + 1 ] ; ci ++ ) { _rtXdot -> ofud5z2sku [ is
] += _rtP -> P_28 [ ci ] * _rtX -> ofud5z2sku [ jc [ ci ] ] ; } } for ( is =
0 ; is < 6 ; is ++ ) { ci = ir_p [ is ] ; while ( ci < ir_p [ is + 1 ] ) {
_rtXdot -> ofud5z2sku [ is ] += _rtP -> P_29 * _rtB -> lxotjm23bx ; ci = 1 ;
} } _rtXdot -> e1gyirzq21 = 0.0 ; _rtXdot -> e1gyirzq21 += _rtP -> P_51 *
_rtX -> e1gyirzq21 ; _rtXdot -> e1gyirzq21 += _rtB -> je1pg3vprd ; _rtXdot ->
hwsq5vmkdy = 0.0 ; _rtXdot -> hwsq5vmkdy += _rtP -> P_55 * _rtX -> hwsq5vmkdy
; _rtXdot -> hwsq5vmkdy += _rtB -> akpegiyksd ; _rtXdot -> mj5udpiwnl = 0.0 ;
_rtXdot -> mj5udpiwnl += _rtP -> P_59 * _rtX -> mj5udpiwnl ; _rtXdot ->
mj5udpiwnl += _rtB -> ne01rh5nsj ; _rtXdot -> gnskp4i0f1 [ 0 ] = _rtB ->
gt1ce1fuae [ 0 ] ; _rtXdot -> gnskp4i0f1 [ 1 ] = _rtB -> gt1ce1fuae [ 1 ] ;
_rtXdot -> gnskp4i0f1 [ 2 ] = _rtB -> gt1ce1fuae [ 2 ] ; _rtXdot ->
nq4ergvzwf = 0.0 ; _rtXdot -> nq4ergvzwf += _rtP -> P_70 * _rtX -> nq4ergvzwf
; _rtXdot -> nq4ergvzwf += _rtB -> nadthfpkvf ; for ( is = 0 ; is < 6 ; is ++
) { _rtXdot -> piybse5prj [ is ] = 0.0 ; } for ( is = 0 ; is < 6 ; is ++ ) {
for ( ci = ir [ is ] ; ci < ir [ is + 1 ] ; ci ++ ) { _rtXdot -> piybse5prj [
is ] += _rtP -> P_77 [ ci ] * _rtX -> piybse5prj [ jc [ ci ] ] ; } } for ( is
= 0 ; is < 6 ; is ++ ) { ci = ir_p [ is ] ; while ( ci < ir_p [ is + 1 ] ) {
_rtXdot -> piybse5prj [ is ] += _rtP -> P_78 * _rtB -> lxotjm23bx ; ci = 1 ;
} } } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S
, 0 , 4292683003U ) ; ssSetChecksumVal ( S , 1 , 2042786707U ) ;
ssSetChecksumVal ( S , 2 , 4002589439U ) ; ssSetChecksumVal ( S , 3 ,
481197193U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
gs3voni0mk ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( fqdvu2maow ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofY ( S ) != sizeof
( msd3s1c5li ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalOutputs sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
np4fzkawzt ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & hrxe4lasxt ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static
void mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate
( SimStruct * S ) { }
#include "simulink.c"
