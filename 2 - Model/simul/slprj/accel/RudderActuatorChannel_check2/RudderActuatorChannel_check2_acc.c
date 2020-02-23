#include "__cf_RudderActuatorChannel_check2.h"
#include <math.h>
#include "RudderActuatorChannel_check2_acc.h"
#include "RudderActuatorChannel_check2_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T jmpxbqz4zf ;
real_T * lastU ; real_T lvo0tpw4vh ; real_T laxcf0imdv ; real_T fmwx4omvby ;
real_T ktwgpr2alw ; real_T cyob4x5wfb ; real_T pv5gxysp0r ; real_T i1ujgst3xa
; real_T dho01whcev ; real_T a2xkjs2hqc ; real_T iz00jymqcq ; real_T
hd2ydhacvd ; real_T dggdeh524t ; real_T eb414jgbzr ; real_T pfx1wdoity ;
real_T c3d3idtpox ; real_T mmmmhtev22 ; real_T pygprsuz1b ; real_T kvg3fbdoel
; real_T ib4tdkspee ; real_T cehrujfj4k ; real_T h0h5km3ilr ; real_T u0 ;
eg4syviqrx * _rtB ; nngkd1bthi * _rtP ; ko33s010i1 * _rtX ; jr1dsnyn2e *
_rtDW ; _rtDW = ( ( jr1dsnyn2e * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
ko33s010i1 * ) ssGetContStates ( S ) ) ; _rtP = ( ( nngkd1bthi * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( eg4syviqrx * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> glksrkmclb = _rtP -> P_11 ; }
jmpxbqz4zf = ssGetT ( S ) ; _rtB -> gjtrxcu2qz = ssGetTStart ( S ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> i3arelobma = _rtP -> P_12 ; }
lvo0tpw4vh = muDoubleScalarSin ( _rtP -> P_15 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_16 ) * _rtP -> P_13 + _rtP -> P_14 ; if ( ssGetTaskTime ( S , 0 ) <
_rtP -> P_17 ) { laxcf0imdv = _rtP -> P_18 ; } else { laxcf0imdv = _rtP ->
P_19 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gtycoh2shd = _rtP ->
P_20 ; } ssCallAccelRunBlock ( S , 11 , 7 , SS_CALL_MDL_OUTPUTS ) ; switch (
( int32_T ) _rtB -> glksrkmclb ) { case 1 : _rtB -> luaxpakdjp =
look1_binlxpw ( muDoubleScalarRem ( jmpxbqz4zf - _rtB -> gjtrxcu2qz , _rtB ->
i3arelobma ) , _rtP -> P_10 , _rtP -> P_9 , 1U ) ; break ; case 2 : _rtB ->
luaxpakdjp = lvo0tpw4vh ; break ; case 3 : _rtB -> luaxpakdjp = laxcf0imdv ;
break ; default : switch ( ( int32_T ) _rtB -> gtycoh2shd ) { case 1 : _rtB
-> luaxpakdjp = _rtB -> pqczn5xmg4 [ 0 ] ; break ; case 2 : _rtB ->
luaxpakdjp = _rtB -> pqczn5xmg4 [ 1 ] ; break ; case 3 : _rtB -> luaxpakdjp =
_rtB -> pqczn5xmg4 [ 2 ] ; break ; default : _rtB -> luaxpakdjp = _rtB ->
pqczn5xmg4 [ 3 ] ; break ; } break ; } ssCallAccelRunBlock ( S , 11 , 11 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
hrzmpf5z5i = _rtP -> P_21 ; _rtB -> fe2ha43ihs = _rtP -> P_22 ; } _rtB ->
hjen11fk4k = _rtX -> jbp4ut2sjv ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> d3y4tu5tya = _rtP -> P_24 ; } ktwgpr2alw = _rtB -> hjen11fk4k + _rtB ->
d3y4tu5tya ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> pqjcwnn1qn = _rtP
-> P_25 ; } u0 = ( ( muDoubleScalarPower ( _rtB -> hrzmpf5z5i , 2.0 ) +
muDoubleScalarPower ( _rtB -> fe2ha43ihs , 2.0 ) ) - muDoubleScalarPower (
ktwgpr2alw , 2.0 ) ) / ( 2.0 * _rtB -> hrzmpf5z5i * _rtB -> fe2ha43ihs ) ; if
( u0 > 1.0 ) { u0 = 1.0 ; } else { if ( u0 < - 1.0 ) { u0 = - 1.0 ; } } _rtB
-> b3ho1mja30 = ( muDoubleScalarAcos ( u0 ) - _rtB -> pqjcwnn1qn ) * _rtP ->
P_26 ; ssCallAccelRunBlock ( S , 11 , 21 , SS_CALL_MDL_OUTPUTS ) ; if ( (
_rtDW -> gokz4o1ut0 >= ssGetT ( S ) ) && ( _rtDW -> d0xq3nfqih >= ssGetT ( S
) ) ) { _rtB -> bt1mn3q30e = 0.0 ; } else { laxcf0imdv = _rtDW -> gokz4o1ut0
; lastU = & _rtDW -> fjdf5en2la ; if ( _rtDW -> gokz4o1ut0 < _rtDW ->
d0xq3nfqih ) { if ( _rtDW -> d0xq3nfqih < ssGetT ( S ) ) { laxcf0imdv = _rtDW
-> d0xq3nfqih ; lastU = & _rtDW -> oqzs1rwqjl ; } } else { if ( _rtDW ->
gokz4o1ut0 >= ssGetT ( S ) ) { laxcf0imdv = _rtDW -> d0xq3nfqih ; lastU = &
_rtDW -> oqzs1rwqjl ; } } _rtB -> bt1mn3q30e = ( _rtB -> b3ho1mja30 - * lastU
) / ( ssGetT ( S ) - laxcf0imdv ) ; } ssCallAccelRunBlock ( S , 11 , 23 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
fyehrit23j = _rtP -> P_27 ; } u0 = ( ( muDoubleScalarPower ( ktwgpr2alw , 2.0
) + muDoubleScalarPower ( _rtB -> hrzmpf5z5i , 2.0 ) ) - muDoubleScalarPower
( _rtB -> fe2ha43ihs , 2.0 ) ) / ( 2.0 * ktwgpr2alw * _rtB -> hrzmpf5z5i ) ;
if ( u0 > 1.0 ) { u0 = 1.0 ; } else { if ( u0 < - 1.0 ) { u0 = - 1.0 ; } }
_rtB -> ch1jhdufoh = _rtB -> hrzmpf5z5i * muDoubleScalarSin (
muDoubleScalarAcos ( u0 ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
hx4uarl3oc = _rtP -> P_32 ; } switch ( ( int32_T ) _rtB -> fyehrit23j ) {
case 1 : _rtB -> ogep4tyvda = muDoubleScalarSin ( _rtP -> P_30 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_31 ) * _rtP -> P_28 + _rtP -> P_29 ;
break ; case 2 : laxcf0imdv = look1_binlxpw ( _rtP -> P_6 * _rtB ->
b3ho1mja30 , _rtP -> P_8 , _rtP -> P_7 , 2U ) ; _rtB -> ogep4tyvda =
laxcf0imdv / _rtB -> ch1jhdufoh ; break ; default : _rtB -> ogep4tyvda = _rtB
-> hx4uarl3oc ; break ; } ssCallAccelRunBlock ( S , 11 , 32 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 33 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 34 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 35 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 36 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 11 , 37 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 11 , 38 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cygluthzcm = _rtX -> ga3cvy1f2n ; _rtB -> juj0bvdrvl = _rtX -> gzo3n2sici ;
_rtB -> jbez3krbly = _rtB -> cygluthzcm - _rtB -> juj0bvdrvl ; _rtB ->
boc1g3jmak = 0.0 ; _rtB -> boc1g3jmak += _rtP -> P_36 * _rtX -> n4itfsmzfq ;
if ( _rtB -> boc1g3jmak > _rtP -> P_37 ) { _rtB -> bqmdlgt3g0 = _rtP -> P_37
; } else if ( _rtB -> boc1g3jmak < _rtP -> P_38 ) { _rtB -> bqmdlgt3g0 = _rtP
-> P_38 ; } else { _rtB -> bqmdlgt3g0 = _rtB -> boc1g3jmak ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 11 , 44 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 11 , 45 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 46 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
i2xm4npf0y = _rtP -> P_39 ; _rtB -> df4j31fznp = _rtP -> P_40 ;
ssCallAccelRunBlock ( S , 11 , 49 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 11 , 50 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 11 , 51 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 11 , 52 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
byfdcqllyw = _rtP -> P_41 ; } _rtB -> j3hkv2rtec = _rtX -> mpdozhsq0u ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> kxu0z1mds5 = _rtP -> P_43 ; } switch
( ( int32_T ) _rtB -> byfdcqllyw ) { case 1 : fmwx4omvby = _rtB -> j3hkv2rtec
; break ; case 2 : fmwx4omvby = _rtB -> kxu0z1mds5 ; break ; default :
fmwx4omvby = _rtB -> j3hkv2rtec ; break ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> j0tdhokcfl = _rtP -> P_44 ; _rtB -> jnubtwye1q = _rtP -> P_45 ; }
switch ( ( int32_T ) _rtB -> j0tdhokcfl ) { case 1 : ktwgpr2alw = _rtB ->
cygluthzcm ; break ; case 2 : ktwgpr2alw = _rtB -> jnubtwye1q ; break ;
default : ktwgpr2alw = _rtB -> cygluthzcm ; break ; } cyob4x5wfb = fmwx4omvby
- ktwgpr2alw ; laxcf0imdv = muDoubleScalarSign ( cyob4x5wfb ) ; cyob4x5wfb =
muDoubleScalarAbs ( cyob4x5wfb ) ; cyob4x5wfb = muDoubleScalarSqrt (
cyob4x5wfb ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ltcu3dmzjw = _rtP
-> P_46 ; } cyob4x5wfb = laxcf0imdv * cyob4x5wfb * _rtB -> ltcu3dmzjw ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lnmodefnow = _rtP -> P_47 ; _rtB ->
ftkpvly5lm = _rtP -> P_50 ; _rtB -> okx1nf4f15 = _rtP -> P_51 ; } u0 = _rtB
-> bqmdlgt3g0 - _rtB -> lnmodefnow ; if ( u0 > _rtP -> P_48 ) { u0 = _rtP ->
P_48 ; } else { if ( u0 < _rtP -> P_49 ) { u0 = _rtP -> P_49 ; } } pv5gxysp0r
= ( u0 * _rtB -> ftkpvly5lm + _rtB -> okx1nf4f15 ) * cyob4x5wfb ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> i42nbmqyjk = _rtP -> P_52 ; }
i1ujgst3xa = _rtX -> oeiaenrcza ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> hjcz0ofwyi = _rtP -> P_54 ; } switch ( ( int32_T ) _rtB -> i42nbmqyjk ) {
case 1 : dho01whcev = _rtX -> oeiaenrcza ; break ; case 2 : dho01whcev = _rtB
-> hjcz0ofwyi ; break ; default : dho01whcev = _rtX -> oeiaenrcza ; break ; }
ktwgpr2alw -= dho01whcev ; laxcf0imdv = muDoubleScalarSign ( ktwgpr2alw ) ;
ktwgpr2alw = muDoubleScalarAbs ( ktwgpr2alw ) ; ktwgpr2alw =
muDoubleScalarSqrt ( ktwgpr2alw ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> msy2r52krz = _rtP -> P_55 ; } ktwgpr2alw = laxcf0imdv * ktwgpr2alw * _rtB
-> msy2r52krz ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> pwm2ainelz =
_rtP -> P_57 ; _rtB -> o1n1mq0jk3 = _rtP -> P_60 ; _rtB -> aqqzo4x5nk = _rtP
-> P_61 ; } u0 = _rtP -> P_56 * _rtB -> bqmdlgt3g0 - _rtB -> pwm2ainelz ; if
( u0 > _rtP -> P_58 ) { u0 = _rtP -> P_58 ; } else { if ( u0 < _rtP -> P_59 )
{ u0 = _rtP -> P_59 ; } } a2xkjs2hqc = ( u0 * _rtB -> o1n1mq0jk3 + _rtB ->
aqqzo4x5nk ) * ktwgpr2alw ; _rtB -> cpy4t4iefn = pv5gxysp0r - a2xkjs2hqc ;
_rtB -> oamsbk2aqu = _rtX -> kcrab0eeoi ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> pcxaac1w2y = _rtP -> P_64 ; _rtB -> mmk0nlzddy = _rtP -> P_65 ; }
iz00jymqcq = _rtB -> cygluthzcm - _rtB -> juj0bvdrvl ; laxcf0imdv =
muDoubleScalarSign ( iz00jymqcq ) ; iz00jymqcq = muDoubleScalarAbs (
iz00jymqcq ) ; iz00jymqcq = muDoubleScalarSqrt ( iz00jymqcq ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> nxjs5ywptg = _rtP -> P_66 ; }
dggdeh524t = laxcf0imdv * iz00jymqcq * _rtB -> nxjs5ywptg ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> b4vjzpkske = _rtP -> P_67 ; }
iz00jymqcq = _rtX -> oeiaenrcza - _rtB -> cygluthzcm ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> e3zky13ybo = _rtP -> P_68 ; _rtB -> af4y2ucpse = _rtP
-> P_72 ; } u0 = ( iz00jymqcq - _rtB -> e3zky13ybo ) * _rtP -> P_69 ; if ( u0
> _rtP -> P_70 ) { u0 = _rtP -> P_70 ; } else { if ( u0 < _rtP -> P_71 ) { u0
= _rtP -> P_71 ; } } eb414jgbzr = muDoubleScalarSign ( iz00jymqcq ) *
muDoubleScalarSqrt ( muDoubleScalarAbs ( iz00jymqcq ) ) * ( u0 * _rtB ->
af4y2ucpse ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hdtfvkthuv = _rtP
-> P_73 ; _rtB -> n2j0muuw45 = _rtP -> P_74 ; } switch ( ( int32_T ) _rtB ->
hdtfvkthuv ) { case 1 : iz00jymqcq = _rtB -> juj0bvdrvl ; break ; case 2 :
iz00jymqcq = _rtB -> n2j0muuw45 ; break ; default : iz00jymqcq = _rtB ->
juj0bvdrvl ; break ; } pfx1wdoity = iz00jymqcq - dho01whcev ; laxcf0imdv =
muDoubleScalarSign ( pfx1wdoity ) ; pfx1wdoity = muDoubleScalarAbs (
pfx1wdoity ) ; pfx1wdoity = muDoubleScalarSqrt ( pfx1wdoity ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> i20cbefypd = _rtP -> P_75 ; }
pfx1wdoity = laxcf0imdv * pfx1wdoity * _rtB -> i20cbefypd ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> o1geb5l23b = _rtP -> P_76 ; _rtB ->
e1rmlv5m0g = _rtP -> P_79 ; _rtB -> nympuhi13j = _rtP -> P_80 ; } u0 = _rtB
-> bqmdlgt3g0 - _rtB -> o1geb5l23b ; if ( u0 > _rtP -> P_77 ) { u0 = _rtP ->
P_77 ; } else { if ( u0 < _rtP -> P_78 ) { u0 = _rtP -> P_78 ; } } c3d3idtpox
= ( u0 * _rtB -> e1rmlv5m0g + _rtB -> nympuhi13j ) * pfx1wdoity ; iz00jymqcq
= fmwx4omvby - iz00jymqcq ; laxcf0imdv = muDoubleScalarSign ( iz00jymqcq ) ;
iz00jymqcq = muDoubleScalarAbs ( iz00jymqcq ) ; iz00jymqcq =
muDoubleScalarSqrt ( iz00jymqcq ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> c0pcsaoxaw = _rtP -> P_81 ; } iz00jymqcq = laxcf0imdv * iz00jymqcq * _rtB
-> c0pcsaoxaw ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> d5fh1kxlcn =
_rtP -> P_83 ; _rtB -> osgdxjtdcm = _rtP -> P_86 ; _rtB -> pkbnaxxsvh = _rtP
-> P_87 ; } u0 = _rtP -> P_82 * _rtB -> bqmdlgt3g0 - _rtB -> d5fh1kxlcn ; if
( u0 > _rtP -> P_84 ) { u0 = _rtP -> P_84 ; } else { if ( u0 < _rtP -> P_85 )
{ u0 = _rtP -> P_85 ; } } mmmmhtev22 = ( u0 * _rtB -> osgdxjtdcm + _rtB ->
pkbnaxxsvh ) * iz00jymqcq ; _rtB -> duzt1vfhlz = c3d3idtpox - mmmmhtev22 ; if
( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> i50tfenmuz = _rtP -> P_89 ; _rtB ->
edqtgdduof = _rtP -> P_90 ; } pygprsuz1b = _rtB -> cygluthzcm - _rtB ->
juj0bvdrvl ; laxcf0imdv = muDoubleScalarSign ( pygprsuz1b ) ; pygprsuz1b =
muDoubleScalarAbs ( pygprsuz1b ) ; pygprsuz1b = muDoubleScalarSqrt (
pygprsuz1b ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bkv3rqklvf = _rtP
-> P_91 ; } laxcf0imdv = laxcf0imdv * pygprsuz1b * _rtB -> bkv3rqklvf ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> o2vel5thoy = _rtP -> P_92 ; }
pygprsuz1b = _rtX -> oeiaenrcza - _rtB -> juj0bvdrvl ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> f1jfugs5p0 = _rtP -> P_93 ; _rtB -> peatm5g4k5 = _rtP
-> P_97 ; } u0 = ( pygprsuz1b - _rtB -> f1jfugs5p0 ) * _rtP -> P_94 ; if ( u0
> _rtP -> P_95 ) { u0 = _rtP -> P_95 ; } else { if ( u0 < _rtP -> P_96 ) { u0
= _rtP -> P_96 ; } } kvg3fbdoel = muDoubleScalarSign ( pygprsuz1b ) *
muDoubleScalarSqrt ( muDoubleScalarAbs ( pygprsuz1b ) ) * ( u0 * _rtB ->
peatm5g4k5 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hqqmqo30ua = _rtP
-> P_98 ; _rtB -> hfvlizop1f = _rtP -> P_99 ; } _rtB -> bmoa43vmrj = ( ( ( (
_rtB -> cpy4t4iefn - _rtP -> P_63 * _rtB -> oamsbk2aqu ) - muDoubleScalarSign
( _rtB -> cygluthzcm ) * muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB ->
cygluthzcm ) ) * _rtB -> pcxaac1w2y * _rtB -> mmk0nlzddy ) - dggdeh524t *
_rtB -> b4vjzpkske ) + eb414jgbzr ) * _rtB -> b5v1pxmkjl / ( _rtP -> P_100 *
_rtB -> hjen11fk4k + _rtB -> hqqmqo30ua ) ; _rtB -> gto3enxiln = ( ( ( ( _rtP
-> P_88 * _rtB -> oamsbk2aqu - _rtB -> duzt1vfhlz ) - muDoubleScalarSign (
_rtB -> juj0bvdrvl ) * muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB ->
juj0bvdrvl ) ) * _rtB -> i50tfenmuz * _rtB -> edqtgdduof ) + laxcf0imdv *
_rtB -> o2vel5thoy ) + kvg3fbdoel ) * _rtB -> nzhixa5aq0 / ( _rtB ->
hfvlizop1f - _rtP -> P_101 * _rtB -> hjen11fk4k ) ; ssCallAccelRunBlock ( S ,
11 , 206 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> kyim04tyny = _rtP -> P_102 ; } pygprsuz1b = look1_linlxpw ( _rtB ->
cygluthzcm , _rtP -> P_104 , _rtP -> P_103 , 6U ) ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { ib4tdkspee = _rtP -> P_106 ; cehrujfj4k = _rtP -> P_107 ;
h0h5km3ilr = look2_linlxpw ( _rtP -> P_106 , _rtP -> P_107 , _rtP -> P_109 ,
_rtP -> P_110 , _rtP -> P_108 , _rtP -> P_235 , 6U ) ; _rtB -> ephb0jiy3g =
_rtP -> P_111 * h0h5km3ilr ; } dggdeh524t = _rtP -> P_105 * pygprsuz1b + _rtB
-> ephb0jiy3g ; pygprsuz1b = look1_linlxpw ( _rtB -> cygluthzcm , _rtP ->
P_113 , _rtP -> P_112 , 6U ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ib4tdkspee = look2_linlxpw ( ib4tdkspee , cehrujfj4k , _rtP -> P_116 , _rtP
-> P_117 , _rtP -> P_115 , _rtP -> P_236 , 6U ) ; _rtB -> blvtclw405 = _rtP
-> P_118 * ib4tdkspee ; } hd2ydhacvd = _rtP -> P_114 * pygprsuz1b + _rtB ->
blvtclw405 ; pygprsuz1b = look1_linlxpw ( _rtB -> juj0bvdrvl , _rtP -> P_120
, _rtP -> P_119 , 6U ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { h0h5km3ilr =
_rtP -> P_122 ; cehrujfj4k = _rtP -> P_123 ; ib4tdkspee = look2_linlxpw (
_rtP -> P_122 , _rtP -> P_123 , _rtP -> P_125 , _rtP -> P_126 , _rtP -> P_124
, _rtP -> P_237 , 6U ) ; _rtB -> kw0tpgeqon = _rtP -> P_127 * ib4tdkspee ; }
lvo0tpw4vh = _rtP -> P_121 * pygprsuz1b + _rtB -> kw0tpgeqon ; pygprsuz1b =
look1_linlxpw ( _rtB -> juj0bvdrvl , _rtP -> P_129 , _rtP -> P_128 , 6U ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { h0h5km3ilr = look2_linlxpw ( h0h5km3ilr
, cehrujfj4k , _rtP -> P_132 , _rtP -> P_133 , _rtP -> P_131 , _rtP -> P_238
, 6U ) ; _rtB -> buzwx3rvei = _rtP -> P_134 * h0h5km3ilr ; h0h5km3ilr =
look1_linlxpw ( _rtP -> P_135 , _rtP -> P_137 , _rtP -> P_136 , 6U ) ;
laxcf0imdv = _rtP -> P_138 * h0h5km3ilr ; h0h5km3ilr = look2_linlxpw ( _rtP
-> P_139 , _rtP -> P_140 , _rtP -> P_142 , _rtP -> P_143 , _rtP -> P_141 ,
_rtP -> P_239 , 6U ) ; _rtB -> jjzuvgdduh = ( _rtP -> P_144 * h0h5km3ilr +
laxcf0imdv ) * _rtP -> P_145 ; } lvo0tpw4vh = ( ( ( _rtP -> P_130 *
pygprsuz1b + _rtB -> buzwx3rvei ) + lvo0tpw4vh ) + ( dggdeh524t + hd2ydhacvd
) ) + _rtB -> jjzuvgdduh ; laxcf0imdv = _rtP -> P_146 / 2.0 ; if ( _rtB ->
oamsbk2aqu < _rtDW -> ajjktgvzbv - laxcf0imdv ) { _rtB -> c00kn2u2xj = _rtB
-> oamsbk2aqu + laxcf0imdv ; } else if ( _rtB -> oamsbk2aqu <= _rtDW ->
ajjktgvzbv + laxcf0imdv ) { _rtB -> c00kn2u2xj = _rtDW -> ajjktgvzbv ; } else
{ _rtB -> c00kn2u2xj = _rtB -> oamsbk2aqu - laxcf0imdv ; } if ( ssIsSampleHit
( S , 1 , 0 ) ) { _rtB -> n0cryzvtge = _rtP -> P_148 ; } switch ( ( int32_T )
_rtB -> kyim04tyny ) { case 1 : _rtB -> nt5fcbtlut = lvo0tpw4vh ; break ;
case 2 : ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; laxcf0imdv
= muDoubleScalarAbs ( _rtB -> oseeruwrt1 ) ; _rtB -> oposjukg0r =
muDoubleScalarExp ( - laxcf0imdv / 10.0 ) ; _rtB -> oseeruwrt1 = laxcf0imdv /
_rtB -> oseeruwrt1 * _rtB -> oposjukg0r ; ssCallAccelRunBlock ( S , 0 , 5 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> nt5fcbtlut = lvo0tpw4vh * _rtB -> oseeruwrt1
; break ; default : _rtB -> nt5fcbtlut = _rtB -> n0cryzvtge ; break ; }
ssCallAccelRunBlock ( S , 11 , 248 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> oo04ryqmu2 = _rtP -> P_149 ; _rtB ->
o2npd3iaig = _rtP -> P_152 ; _rtB -> dcsqlmf3fb = _rtDW -> eqogczyeii ; _rtB
-> paer03baxe = _rtP -> P_159 ; } u0 = _rtB -> o2npd3iaig - _rtB ->
hjen11fk4k ; hd2ydhacvd = _rtB -> hjen11fk4k - _rtB -> oo04ryqmu2 ; if (
hd2ydhacvd > _rtP -> P_150 ) { hd2ydhacvd = _rtP -> P_150 ; } else { if (
hd2ydhacvd < _rtP -> P_151 ) { hd2ydhacvd = _rtP -> P_151 ; } } if ( u0 >
_rtP -> P_153 ) { u0 = _rtP -> P_153 ; } else { if ( u0 < _rtP -> P_154 ) {
u0 = _rtP -> P_154 ; } } _rtB -> hfqivtrror = ( ( ( ( ( ( ( _rtB ->
cygluthzcm - _rtB -> juj0bvdrvl ) * _rtP -> P_157 - _rtP -> P_158 * _rtB ->
oamsbk2aqu ) - ( _rtB -> hjen11fk4k - _rtB -> dcsqlmf3fb ) * _rtP -> P_156 )
- muDoubleScalarSign ( _rtB -> hjen11fk4k ) * _rtB -> nt5fcbtlut ) - _rtB ->
paer03baxe ) - _rtP -> P_160 * hd2ydhacvd * _rtP -> P_161 ) + _rtP -> P_162 *
u0 * _rtP -> P_163 ) * _rtP -> P_164 ; laxcf0imdv = look1_binlxpw ( _rtB ->
hjen11fk4k , _rtP -> P_166 , _rtP -> P_165 , 2U ) ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> ejkxqs4caf = _rtDW -> iwtt3fsxxb ; } if ( _rtB ->
ejkxqs4caf >= _rtP -> P_172 ) { _rtB -> hgjvzpuaq2 = _rtB -> hjen11fk4k +
laxcf0imdv ; } else { _rtB -> hgjvzpuaq2 = _rtB -> hjen11fk4k - laxcf0imdv ;
} laxcf0imdv = look1_binlxpw ( _rtB -> jbez3krbly , _rtP -> P_174 , _rtP ->
P_173 , 2U ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> eagyozzj2z =
_rtDW -> dsgcw0osno ; } if ( _rtB -> eagyozzj2z >= _rtP -> P_180 ) { _rtB ->
lfnu3eudfz = _rtB -> jbez3krbly + laxcf0imdv ; } else { _rtB -> lfnu3eudfz =
_rtB -> jbez3krbly - laxcf0imdv ; } laxcf0imdv = look1_binlxpw ( _rtB ->
bqmdlgt3g0 , _rtP -> P_182 , _rtP -> P_181 , 2U ) ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> bq1kkvdokp = _rtDW -> astq5xynak ; } if ( _rtB ->
bq1kkvdokp >= _rtP -> P_188 ) { _rtB -> kpkqedknyv = _rtB -> bqmdlgt3g0 +
laxcf0imdv ; } else { _rtB -> kpkqedknyv = _rtB -> bqmdlgt3g0 - laxcf0imdv ;
} if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 11 , 288 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> ddwzeflflv >= ssGetT ( S ) ) && (
_rtDW -> dgg5eexyhx >= ssGetT ( S ) ) ) { _rtB -> dif0byewmn = 0.0 ; } else {
laxcf0imdv = _rtDW -> ddwzeflflv ; lastU = & _rtDW -> jsyxxauwyq ; if ( _rtDW
-> ddwzeflflv < _rtDW -> dgg5eexyhx ) { if ( _rtDW -> dgg5eexyhx < ssGetT ( S
) ) { laxcf0imdv = _rtDW -> dgg5eexyhx ; lastU = & _rtDW -> psvb2ck5cv ; } }
else { if ( _rtDW -> ddwzeflflv >= ssGetT ( S ) ) { laxcf0imdv = _rtDW ->
dgg5eexyhx ; lastU = & _rtDW -> psvb2ck5cv ; } } _rtB -> dif0byewmn = ( _rtB
-> bqmdlgt3g0 - * lastU ) / ( ssGetT ( S ) - laxcf0imdv ) ; } if ( ( _rtDW ->
erankf1tws >= ssGetT ( S ) ) && ( _rtDW -> nrnwmkmrrb >= ssGetT ( S ) ) ) {
_rtB -> puz1q4cvwz = 0.0 ; } else { laxcf0imdv = _rtDW -> erankf1tws ; lastU
= & _rtDW -> d5rgnrm0wd ; if ( _rtDW -> erankf1tws < _rtDW -> nrnwmkmrrb ) {
if ( _rtDW -> nrnwmkmrrb < ssGetT ( S ) ) { laxcf0imdv = _rtDW -> nrnwmkmrrb
; lastU = & _rtDW -> aza2cltbxz ; } } else { if ( _rtDW -> erankf1tws >=
ssGetT ( S ) ) { laxcf0imdv = _rtDW -> nrnwmkmrrb ; lastU = & _rtDW ->
aza2cltbxz ; } } _rtB -> puz1q4cvwz = ( _rtB -> dif0byewmn - * lastU ) / (
ssGetT ( S ) - laxcf0imdv ) ; } ssCallAccelRunBlock ( S , 11 , 291 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 292 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 293 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 294 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
bn10qhmevr = _rtP -> P_189 ; } switch ( ( int32_T ) _rtB -> bn10qhmevr ) {
case 1 : if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_0 ) { _rtB -> al25biegaq =
_rtP -> P_1 ; } else { _rtB -> al25biegaq = _rtP -> P_2 ; } if (
ssGetTaskTime ( S , 0 ) < _rtP -> P_3 ) { _rtB -> ntqafsz5nk = _rtP -> P_4 ;
} else { _rtB -> ntqafsz5nk = _rtP -> P_5 ; } ssCallAccelRunBlock ( S , 7 , 2
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> pz0wpv4s5j = _rtB -> ptywgirvmh ; break ;
case 2 : _rtB -> pz0wpv4s5j = muDoubleScalarSin ( _rtP -> P_192 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_193 ) * _rtP -> P_190 + _rtP -> P_191 ;
break ; default : if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_194 ) { _rtB ->
pz0wpv4s5j = _rtP -> P_195 ; } else { _rtB -> pz0wpv4s5j = _rtP -> P_196 ; }
break ; } ssCallAccelRunBlock ( S , 11 , 300 , SS_CALL_MDL_OUTPUTS ) ;
fmwx4omvby -= dho01whcev ; laxcf0imdv = muDoubleScalarSign ( fmwx4omvby ) ;
fmwx4omvby = muDoubleScalarAbs ( fmwx4omvby ) ; fmwx4omvby =
muDoubleScalarSqrt ( fmwx4omvby ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> bz30zevqpo = _rtP -> P_197 ; _rtB -> hc5qbdzyqx = _rtP -> P_198 ; }
pygprsuz1b = laxcf0imdv * fmwx4omvby * _rtB -> bz30zevqpo * _rtB ->
hc5qbdzyqx ; _rtB -> bn5oroqshd = ( ( ( ( ktwgpr2alw * _rtB -> aqqzo4x5nk +
pygprsuz1b ) + pfx1wdoity * _rtB -> nympuhi13j ) + cyob4x5wfb * _rtB ->
okx1nf4f15 ) + iz00jymqcq * _rtB -> pkbnaxxsvh ) * _rtP -> P_199 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 11 , 316 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 11 , 317 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> mmmmcwaaek = 0.0 ; _rtB -> mmmmcwaaek +=
_rtP -> P_201 [ 0 ] * _rtX -> ewos543v1a [ 0 ] ; _rtB -> mmmmcwaaek += _rtP
-> P_201 [ 1 ] * _rtX -> ewos543v1a [ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 )
) { ssCallAccelRunBlock ( S , 11 , 319 , SS_CALL_MDL_OUTPUTS ) ; } if ( _rtB
-> pz0wpv4s5j > _rtP -> P_202 ) { hd2ydhacvd = _rtP -> P_202 ; } else if (
_rtB -> pz0wpv4s5j < _rtP -> P_203 ) { hd2ydhacvd = _rtP -> P_203 ; } else {
hd2ydhacvd = _rtB -> pz0wpv4s5j ; } _rtB -> h03utnwpiq = _rtP -> P_204 *
hd2ydhacvd - _rtP -> P_205 * _rtB -> bqmdlgt3g0 ; pfx1wdoity = _rtP -> P_207
[ 0 ] * _rtX -> irf2qndv5m [ 0 ] + _rtP -> P_207 [ 1 ] * _rtX -> irf2qndv5m [
1 ] ; if ( pfx1wdoity > _rtP -> P_208 ) { pfx1wdoity = _rtP -> P_208 ; } else
{ if ( pfx1wdoity < _rtP -> P_209 ) { pfx1wdoity = _rtP -> P_209 ; } } u0 =
_rtP -> P_210 * pfx1wdoity ; if ( u0 > _rtP -> P_211 ) { _rtB -> ahwkhfzjhw =
_rtP -> P_211 ; } else if ( u0 < _rtP -> P_212 ) { _rtB -> ahwkhfzjhw = _rtP
-> P_212 ; } else { _rtB -> ahwkhfzjhw = u0 ; } lvo0tpw4vh = ( pv5gxysp0r +
mmmmhtev22 ) + pygprsuz1b ; laxcf0imdv = ( c3d3idtpox + a2xkjs2hqc ) +
pygprsuz1b ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> df4j31fznp = _rtP
-> P_213 ; _rtB -> gegwepbcer = _rtP -> P_214 ; } _rtB -> bb5ckno4hd = _rtB
-> gegwepbcer - _rtP -> P_216 * _rtX -> bc0ghv0mgs ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> i2xm4npf0y = _rtP -> P_217 ; ssCallAccelRunBlock ( S , 11
, 335 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ebtt05cxcf = _rtB -> dvqq54dz0m /
_rtP -> P_218 ; } pygprsuz1b = _rtB -> bb5ckno4hd - _rtB -> j3hkv2rtec ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ofper0evox = _rtP -> P_219 ; _rtB ->
mkyqqinj1p = _rtP -> P_220 ; } u0 = ( pygprsuz1b - _rtB -> mkyqqinj1p ) *
_rtP -> P_221 ; if ( u0 > _rtP -> P_222 ) { u0 = _rtP -> P_222 ; } else { if
( u0 < _rtP -> P_223 ) { u0 = _rtP -> P_223 ; } } pygprsuz1b =
muDoubleScalarSign ( pygprsuz1b ) * muDoubleScalarSqrt ( muDoubleScalarAbs (
pygprsuz1b ) ) * ( u0 * _rtB -> ofper0evox ) ; _rtB -> ke34ultdpx = (
pygprsuz1b - lvo0tpw4vh ) * _rtB -> ebtt05cxcf ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { _rtB -> df4j31fznp = _rtP -> P_224 ; _rtB -> a2h2qfc5il = _rtP ->
P_225 ; _rtB -> i2xm4npf0y = _rtP -> P_226 ; ssCallAccelRunBlock ( S , 11 ,
355 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> j3hwgfm1du = _rtB -> l3vny4jhci / _rtP
-> P_227 ; } mmmmhtev22 = i1ujgst3xa - _rtB -> a2h2qfc5il ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ig32gwp5pt = _rtP -> P_228 ; _rtB ->
mcwkreevah = _rtP -> P_232 ; } u0 = ( mmmmhtev22 - _rtB -> ig32gwp5pt ) *
_rtP -> P_229 ; if ( u0 > _rtP -> P_230 ) { u0 = _rtP -> P_230 ; } else { if
( u0 < _rtP -> P_231 ) { u0 = _rtP -> P_231 ; } } _rtB -> by5i2jtqs5 = ( (
laxcf0imdv - muDoubleScalarSign ( mmmmhtev22 ) * muDoubleScalarSqrt (
muDoubleScalarAbs ( mmmmhtev22 ) ) * ( u0 * _rtB -> mcwkreevah ) ) - (
eb414jgbzr + kvg3fbdoel ) ) * _rtB -> j3hwgfm1du ; _rtB -> ipxnpx11kx = _rtP
-> P_233 * pygprsuz1b * _rtP -> P_234 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
eg4syviqrx * _rtB ; nngkd1bthi * _rtP ; jr1dsnyn2e * _rtDW ; _rtDW = ( (
jr1dsnyn2e * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( nngkd1bthi * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( eg4syviqrx * ) _ssGetBlockIO ( S ) ) ;
if ( _rtDW -> gokz4o1ut0 == ( rtInf ) ) { _rtDW -> gokz4o1ut0 = ssGetT ( S )
; lastU = & _rtDW -> fjdf5en2la ; } else if ( _rtDW -> d0xq3nfqih == ( rtInf
) ) { _rtDW -> d0xq3nfqih = ssGetT ( S ) ; lastU = & _rtDW -> oqzs1rwqjl ; }
else if ( _rtDW -> gokz4o1ut0 < _rtDW -> d0xq3nfqih ) { _rtDW -> gokz4o1ut0 =
ssGetT ( S ) ; lastU = & _rtDW -> fjdf5en2la ; } else { _rtDW -> d0xq3nfqih =
ssGetT ( S ) ; lastU = & _rtDW -> oqzs1rwqjl ; } * lastU = _rtB -> b3ho1mja30
; _rtDW -> ajjktgvzbv = _rtB -> c00kn2u2xj ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtDW -> eqogczyeii = _rtB -> hjen11fk4k ; _rtDW -> iwtt3fsxxb =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> nw0wjoi3qx ) * _rtP -> P_170 + _rtP
-> P_169 ; _rtDW -> dsgcw0osno = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
f3mbthqa5h ) * _rtP -> P_178 + _rtP -> P_177 ; _rtDW -> astq5xynak =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> ptrrl43x0d ) * _rtP -> P_186 + _rtP
-> P_185 ; } if ( _rtDW -> ddwzeflflv == ( rtInf ) ) { _rtDW -> ddwzeflflv =
ssGetT ( S ) ; lastU = & _rtDW -> jsyxxauwyq ; } else if ( _rtDW ->
dgg5eexyhx == ( rtInf ) ) { _rtDW -> dgg5eexyhx = ssGetT ( S ) ; lastU = &
_rtDW -> psvb2ck5cv ; } else if ( _rtDW -> ddwzeflflv < _rtDW -> dgg5eexyhx )
{ _rtDW -> ddwzeflflv = ssGetT ( S ) ; lastU = & _rtDW -> jsyxxauwyq ; } else
{ _rtDW -> dgg5eexyhx = ssGetT ( S ) ; lastU = & _rtDW -> psvb2ck5cv ; } *
lastU = _rtB -> bqmdlgt3g0 ; if ( _rtDW -> erankf1tws == ( rtInf ) ) { _rtDW
-> erankf1tws = ssGetT ( S ) ; lastU = & _rtDW -> d5rgnrm0wd ; } else if (
_rtDW -> nrnwmkmrrb == ( rtInf ) ) { _rtDW -> nrnwmkmrrb = ssGetT ( S ) ;
lastU = & _rtDW -> aza2cltbxz ; } else if ( _rtDW -> erankf1tws < _rtDW ->
nrnwmkmrrb ) { _rtDW -> erankf1tws = ssGetT ( S ) ; lastU = & _rtDW ->
d5rgnrm0wd ; } else { _rtDW -> nrnwmkmrrb = ssGetT ( S ) ; lastU = & _rtDW ->
aza2cltbxz ; } * lastU = _rtB -> dif0byewmn ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { eg4syviqrx * _rtB ; nngkd1bthi
* _rtP ; ko33s010i1 * _rtX ; ho3yee0is3 * _rtXdot ; _rtXdot = ( ( ho3yee0is3
* ) ssGetdX ( S ) ) ; _rtX = ( ( ko33s010i1 * ) ssGetContStates ( S ) ) ;
_rtP = ( ( nngkd1bthi * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( eg4syviqrx *
) _ssGetBlockIO ( S ) ) ; _rtXdot -> jbp4ut2sjv = _rtB -> oamsbk2aqu ;
_rtXdot -> ga3cvy1f2n = _rtB -> bmoa43vmrj ; _rtXdot -> gzo3n2sici = _rtB ->
gto3enxiln ; _rtXdot -> n4itfsmzfq = 0.0 ; _rtXdot -> n4itfsmzfq += _rtP ->
P_35 * _rtX -> n4itfsmzfq ; _rtXdot -> n4itfsmzfq += _rtB -> ahwkhfzjhw ;
_rtXdot -> mpdozhsq0u = _rtB -> ke34ultdpx ; _rtXdot -> oeiaenrcza = _rtB ->
by5i2jtqs5 ; _rtXdot -> kcrab0eeoi = _rtB -> hfqivtrror ; _rtXdot ->
dh03n1fbdy = 0.0 ; _rtXdot -> dh03n1fbdy += _rtP -> P_167 * _rtX ->
dh03n1fbdy ; _rtXdot -> dh03n1fbdy += _rtB -> hgjvzpuaq2 ; _rtXdot ->
klzc3r0sib = 0.0 ; _rtXdot -> klzc3r0sib += _rtP -> P_175 * _rtX ->
klzc3r0sib ; _rtXdot -> klzc3r0sib += _rtB -> lfnu3eudfz ; _rtXdot ->
ksnzbcawi1 = 0.0 ; _rtXdot -> ksnzbcawi1 += _rtP -> P_183 * _rtX ->
ksnzbcawi1 ; _rtXdot -> ksnzbcawi1 += _rtB -> kpkqedknyv ; _rtXdot ->
ewos543v1a [ 0 ] = 0.0 ; _rtXdot -> ewos543v1a [ 1 ] = 0.0 ; _rtXdot ->
ewos543v1a [ 0 ] += _rtP -> P_200 [ 0 ] * _rtX -> ewos543v1a [ 0 ] ; _rtXdot
-> ewos543v1a [ 0 ] += _rtP -> P_200 [ 1 ] * _rtX -> ewos543v1a [ 1 ] ;
_rtXdot -> ewos543v1a [ 1 ] += _rtX -> ewos543v1a [ 0 ] ; _rtXdot ->
ewos543v1a [ 0 ] += _rtB -> pz0wpv4s5j ; _rtXdot -> irf2qndv5m [ 0 ] = 0.0 ;
_rtXdot -> irf2qndv5m [ 1 ] = 0.0 ; _rtXdot -> irf2qndv5m [ 0 ] += _rtP ->
P_206 [ 0 ] * _rtX -> irf2qndv5m [ 0 ] ; _rtXdot -> irf2qndv5m [ 0 ] += _rtP
-> P_206 [ 1 ] * _rtX -> irf2qndv5m [ 1 ] ; _rtXdot -> irf2qndv5m [ 1 ] +=
_rtX -> irf2qndv5m [ 0 ] ; _rtXdot -> irf2qndv5m [ 0 ] += _rtB -> h03utnwpiq
; _rtXdot -> bc0ghv0mgs = 0.0 ; _rtXdot -> bc0ghv0mgs += _rtP -> P_215 * _rtX
-> bc0ghv0mgs ; _rtXdot -> bc0ghv0mgs += _rtB -> ipxnpx11kx ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 1088542709U
) ; ssSetChecksumVal ( S , 1 , 1217646145U ) ; ssSetChecksumVal ( S , 2 ,
2074836590U ) ; ssSetChecksumVal ( S , 3 , 1562905647U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.5" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( jr1dsnyn2e ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( eg4syviqrx ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofY ( S ) != sizeof
( kxll01110h ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalOutputs sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
nngkd1bthi ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & irktoseqst ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
nngkd1bthi * ) ssGetDefaultParam ( S ) ) -> P_150 = rtInf ; ( ( nngkd1bthi *
) ssGetDefaultParam ( S ) ) -> P_153 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
