#include "__cf_RudderActuatorChannel_control.h"
#ifndef RTW_HEADER_RudderActuatorChannel_control_acc_h_
#define RTW_HEADER_RudderActuatorChannel_control_acc_h_
#include <stddef.h>
#ifndef RudderActuatorChannel_control_acc_COMMON_INCLUDES_
#define RudderActuatorChannel_control_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "RudderActuatorChannel_control_acc_types.h"
#include "multiword_types.h"
#include "model_reference_types.h"
#include "BulkModulus.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "look1_binlxpw.h"
#include "look1_linlxpw.h"
#include "look2_linlxpw.h"
#include "rt_nrand_Upu32_Yd_f_pw_snf.h"
#include "rt_defines.h"
typedef struct { real_T n5emepncmu ; real_T faoqu1m5v4 ; real_T kzdamwyw3y ;
real_T agfrurf4tx ; real_T bym1hzgcjt [ 4 ] ; real_T i0k30klgz3 ; real_T
jnh3ysabca ; real_T fvrpmyjesg ; real_T iipde23lg1 ; real_T gi3lwll4k5 ;
real_T bzdqipcxyh ; real_T lwtrphnwqm ; real_T ijzigm3tu2 ; real_T njdjezvee1
; real_T exg0gzodra ; real_T ktr3uo02c5 ; real_T jnbn02bc4b ; real_T
okyitkmldm ; real_T nd1tjssbnu ; real_T dhfwk5wgw3 ; real_T e5ytxmbo2y ;
real_T cpsyjd4ujv ; real_T i5jb5x1hwe ; real_T lda0k3wtsc ; real_T aajkn5pdud
; real_T czjjdd4dxv ; real_T pn131hzyrx ; real_T lxoac0gpgt ; real_T
fygqumipk1 ; real_T iep5g5nadw ; real_T hq13wkbxn0 ; real_T fyga3ffmyi ;
real_T hfiku0fgbq ; real_T i3fa5njf5q ; real_T hlgy0qbkt1 ; real_T azegqsok2u
; real_T mbgka1fvn0 ; real_T gjhq1huomz ; real_T l4lsyjuw45 ; real_T
k3shlvb3gp ; real_T kiqjhvwxmk ; real_T lqs0qtumlg ; real_T ooq0xetnu0 ;
real_T irwzp0i140 ; real_T cfyrjvq2cd ; real_T igidwvw0cb ; real_T eren1giag3
; real_T hxc1npfrcu ; real_T jc1int1tnm ; real_T jupgpngfc0 ; real_T
apsexklret ; real_T lvhxzh5wen ; real_T kjjam3iuct ; real_T ihhvhzkyyw ;
real_T fhkd3jogb1 ; real_T la0ioupyuv ; real_T lxprry1ur5 ; real_T plvx1n4hou
; real_T jatz1czkos ; real_T nsze2qvrua ; real_T atr12hy2hg ; real_T
m3pst3z3rp ; real_T fdzhaeivsn ; real_T ijusgjmrb1 ; real_T efdlrqzvh3 ;
real_T cllzn14spg ; real_T nhxbajkayv ; real_T detm4kyomp ; real_T ltj5psptec
; real_T emnalec1lg ; real_T aujqqvoyss ; real_T fdsodfi5hw ; real_T
ortgjvjrai ; real_T o0mnfpeek1 ; real_T az05srhslu ; real_T pzjkqnbxki ;
real_T nx4k0np51b ; real_T lvketmabyk ; real_T fu4s4jqfql ; real_T a1cmn4hecs
; real_T n5v0xcyhwf ; real_T mvmvnwt4kc ; real_T m5izyy5fzp ; real_T
m5qi2iswbl ; real_T endgm2wl02 ; real_T jl5ttxenkq ; real_T ghe1b5xcmw ;
real_T nqyidwr5mo ; real_T foknucrrmx ; real_T hvmjkfdffw ; real_T mgunkgvq1i
; real_T letnfetl4s ; real_T dyhdbudjg3 ; real_T h1m52zrdbx ; real_T
lvnpppsyaq ; real_T j53qjf3tzq ; real_T lprlyity5x ; real_T eajsgqro1h ;
real_T fp2h1ttszi ; real_T m2x05ags3q ; real_T e1kmntv5m0 ; real_T ehsvda1ttn
; real_T alfhmkp2bb ; real_T he2jhyzdjm ; real_T iisu01hcme ; real_T
b5313odkwp ; real_T kmpw22kren ; real_T f1caahebik ; real_T gasw43jrmv ;
real_T kzte5nxxvp ; real_T fysw5twj0f ; real_T oztwkrhoim ; real_T mitv5vijdv
; real_T ghtk1wnvfe ; real_T eenqzyuj23 ; real_T cc2k5h2su0 ; real_T
kcpvnpttau ; real_T pj0taobhqi ; real_T f2n5fmv2av ; real_T i3x1cusrvt ;
real_T fs3snfwfeo ; real_T hcllqr1qlp ; real_T mbz0o5xdfy ; real_T pqzatmkaqm
[ 3 ] ; real_T gbnkdxxeun ; real_T f4ilowdy0t ; real_T hxhb1tehfn ; real_T
pyoiul2yvl ; real_T j5wqppxc0d ; real_T okpmzwlszi ; real_T gcunfakedo ;
real_T myiovf3hkb ; real_T fj2siwitfl ; real_T ccrol0lzdr ; real_T lkssgrecvc
; real_T h5cz5si5rf ; real_T odjz4hx5el ; real_T dacscz5nes ; real_T
kwbejuxgmj ; real_T ordbqqfm4f ; real_T fgy3tvipl3 ; real_T kp2wkgocdx ;
real_T bn1ydfh5v0 ; real_T ib4jjpdudr ; real_T alel31g0ei ; real_T dthirzbact
; real_T nxzuwnn1lh ; real_T dx0x3ylkku ; } cdc1qietk5 ; typedef struct {
real_T igbe5jrrkp ; real_T phsimlohfo ; real_T cdtlclcegx ; real_T ap215umohx
; real_T faewpkcrfr ; real_T cst0tsnp5p ; real_T lofcpccd3v ; real_T
kiduujgizo ; real_T lskn5i0tu2 ; real_T lnjwuesc4c ; real_T ddcz5bsrj4 ;
real_T etrlhmj31i ; real_T guyuccv315 ; real_T nvnj0uqpc1 ; real_T kuxx0h0hjr
; real_T ft4eexgqzb ; real_T mprqka25vy ; real_T a21gu23ss2 ; real_T
hli3eybjuh ; real_T est5crkpfo ; real_T in4ciyh5xv ; real_T drjzfovyiw ;
real_T dkvz24omzk ; real_T biztplgyzb ; real_T cmc4u4kowe ; real_T pscuiydqnr
; real_T apkjbfmgwu ; real_T frjs32r5d5 ; real_T gibdfdest4 ; real_T
pghhpntp0k ; real_T pibnpkg2kp ; real_T aymq1cztf4 [ 2 ] ; void * k2ozihwwma
[ 3 ] ; void * nr5aa0mzgf ; void * nkhnc0twsa ; void * k5y4j5vr3b ; struct {
void * LoggedData ; } awqfwdb3it ; void * epeeyhjgab ; struct { void *
LoggedData ; } asxodj0tab ; struct { void * LoggedData ; } kraoyidq3u ;
struct { void * LoggedData ; } bfblxx2ezj ; void * heimgn4ehv ; void *
lml22i32ll ; void * i0jkipnfgj ; void * kbch2ezmgg ; void * heimgn4ehv2 ;
void * hhcd3brxur ; struct { void * LoggedData ; } ivycya3dyl ; void *
ntef2vhpv1 ; void * egst3e5hyz ; void * cs0ykbgqqf ; void * gdkx00hcos ;
struct { void * LoggedData ; } dao1aq4rbv ; struct { void * LoggedData ; }
h5w1v3ez2f ; struct { void * LoggedData ; } ilzvaeeu3w ; void * pukqah5pj1 ;
struct { void * LoggedData ; } lbwcmt4mng ; struct { void * LoggedData ; }
ebsdb4nlk5 ; struct { void * LoggedData ; } ij3m5kewag ; void * emphuvzvux ;
struct { void * LoggedData ; } mbgefkjtln ; struct { void * LoggedData ; }
bwz3iorsda ; struct { void * LoggedData ; } oicxlrgnzi ; struct { void *
LoggedData ; } fio00ji4e0 ; uint32_T oru5anql4n ; uint32_T kibvnefr2o ;
uint32_T kvnrclqtkg ; uint32_T aagvbk04st ; int_T lv01cvdz1j ; int8_T
efwzkfiqr0 ; int8_T ipf2guf5kv ; int8_T bexmglytmi ; int8_T fmonm4o1ag ;
int8_T boewbumlpr ; boolean_T fumsexngms ; char pad_fumsexngms [ 6 ] ;
ou41r25q2gt pnetvuxaum ; ou41r25q2gt itjhdh5dsh ; ou41r25q2gt eiyrrw0cvw ;
ou41r25q2gt bjkgrudyjz ; } gnhrdqndaw ; typedef struct { real_T drig45tzgq ;
real_T i5gw4xodpn ; real_T pnhrmy1uiy ; real_T ppodbibpay ; real_T puv5m1t14e
[ 3 ] ; real_T oarjlg0z11 ; real_T k1z5ksayfm ; real_T fmmi3ei4ik ; real_T
f11ic0i0dy ; real_T eo0bwreyi4 ; real_T p0s35axnlc ; real_T gsa5h5kyri ;
real_T fspor4sjtq [ 2 ] ; real_T cxsfbwsttm [ 2 ] ; real_T p4ateoyaz0 ; }
mkvrtd44mj ; typedef struct { real_T drig45tzgq ; real_T i5gw4xodpn ; real_T
pnhrmy1uiy ; real_T ppodbibpay ; real_T puv5m1t14e [ 3 ] ; real_T oarjlg0z11
; real_T k1z5ksayfm ; real_T fmmi3ei4ik ; real_T f11ic0i0dy ; real_T
eo0bwreyi4 ; real_T p0s35axnlc ; real_T gsa5h5kyri ; real_T fspor4sjtq [ 2 ]
; real_T cxsfbwsttm [ 2 ] ; real_T p4ateoyaz0 ; } gvd2nzujxx ; typedef struct
{ boolean_T drig45tzgq ; boolean_T i5gw4xodpn ; boolean_T pnhrmy1uiy ;
boolean_T ppodbibpay ; boolean_T puv5m1t14e [ 3 ] ; boolean_T oarjlg0z11 ;
boolean_T k1z5ksayfm ; boolean_T fmmi3ei4ik ; boolean_T f11ic0i0dy ;
boolean_T eo0bwreyi4 ; boolean_T p0s35axnlc ; boolean_T gsa5h5kyri ;
boolean_T fspor4sjtq [ 2 ] ; boolean_T cxsfbwsttm [ 2 ] ; boolean_T
p4ateoyaz0 ; } borz1w2w12 ; typedef struct { real_T * B_13_5 ; real_T *
B_13_6 ; real_T * B_13_7 ; real_T * B_13_9 ; real_T * B_13_10 ; } elxtisijyd
; struct nffqwkkk0o_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 [ 3 ] ; real_T P_7 [ 3 ] ; real_T P_8 [
2 ] ; real_T P_9 [ 2 ] ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T
P_13 ; real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ;
real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T
P_24 ; real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ;
real_T P_30 ; real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T
P_35 ; real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ;
real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T
P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ;
real_T P_52 ; real_T P_53 ; real_T P_54 [ 9 ] ; real_T P_55 ; real_T P_56 [ 5
] ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ;
real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T
P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ;
real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T
P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ;
real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T
P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T P_94 ;
real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ; real_T
P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ; real_T
P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ; real_T
P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ; real_T
P_115 ; real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ; real_T
P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T
P_125 ; real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T
P_130 ; real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T
P_135 [ 7 ] ; real_T P_136 [ 7 ] ; real_T P_137 ; real_T P_138 ; real_T P_139
; real_T P_140 [ 18 ] ; real_T P_141 [ 6 ] ; real_T P_142 [ 3 ] ; real_T
P_143 ; real_T P_144 [ 7 ] ; real_T P_145 [ 7 ] ; real_T P_146 ; real_T P_147
[ 18 ] ; real_T P_148 [ 6 ] ; real_T P_149 [ 3 ] ; real_T P_150 ; real_T
P_151 [ 7 ] ; real_T P_152 [ 7 ] ; real_T P_153 ; real_T P_154 ; real_T P_155
; real_T P_156 [ 18 ] ; real_T P_157 [ 6 ] ; real_T P_158 [ 3 ] ; real_T
P_159 ; real_T P_160 [ 7 ] ; real_T P_161 [ 7 ] ; real_T P_162 ; real_T P_163
[ 18 ] ; real_T P_164 [ 6 ] ; real_T P_165 [ 3 ] ; real_T P_166 ; real_T
P_167 ; real_T P_168 [ 7 ] ; real_T P_169 [ 7 ] ; real_T P_170 ; real_T P_171
; real_T P_172 ; real_T P_173 [ 18 ] ; real_T P_174 [ 6 ] ; real_T P_175 [ 3
] ; real_T P_176 ; real_T P_177 ; real_T P_178 ; real_T P_179 ; real_T P_180
; real_T P_181 ; real_T P_182 ; real_T P_183 ; real_T P_184 ; real_T P_185 ;
real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T P_189 ; real_T P_190 ;
real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T P_194 ; real_T P_195 ;
real_T P_196 [ 3 ] ; real_T P_197 [ 3 ] ; real_T P_198 ; real_T P_199 ;
real_T P_200 ; real_T P_201 ; real_T P_202 [ 3 ] ; real_T P_203 [ 3 ] ;
real_T P_204 ; real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 [ 3
] ; real_T P_209 [ 3 ] ; real_T P_210 ; real_T P_211 ; real_T P_212 ; real_T
P_213 ; real_T P_214 ; real_T P_215 ; real_T P_216 ; real_T P_217 ; real_T
P_218 ; real_T P_219 ; real_T P_220 ; real_T P_221 ; real_T P_222 ; real_T
P_223 ; real_T P_224 ; real_T P_225 [ 2 ] ; real_T P_226 [ 2 ] ; real_T P_227
; real_T P_228 ; real_T P_229 ; real_T P_230 ; real_T P_231 [ 2 ] ; real_T
P_232 [ 2 ] ; real_T P_233 ; real_T P_234 ; real_T P_235 ; real_T P_236 ;
real_T P_237 ; real_T P_238 ; real_T P_239 ; real_T P_240 ; real_T P_241 ;
real_T P_242 ; real_T P_243 ; real_T P_244 ; real_T P_245 ; real_T P_246 ;
real_T P_247 ; real_T P_248 ; real_T P_249 ; real_T P_250 ; real_T P_251 ;
real_T P_252 ; real_T P_253 ; real_T P_254 ; real_T P_255 ; real_T P_256 ;
real_T P_257 ; real_T P_258 [ 9 ] ; real_T P_259 [ 9 ] ; real_T P_260 [ 3 ] ;
real_T P_261 ; real_T P_262 ; real_T P_263 ; real_T P_264 ; real_T P_265 ;
real_T P_266 ; real_T P_267 ; real_T P_268 ; real_T P_269 ; real_T P_270 ;
real_T P_271 ; real_T P_272 ; real_T P_273 ; real_T P_274 ; real_T P_275 ;
real_T P_276 ; real_T P_277 ; real_T P_278 ; real_T P_279 ; real_T P_280 ;
real_T P_281 ; real_T P_282 ; real_T P_283 ; real_T P_284 ; real_T P_285 ;
real_T P_286 [ 2 ] ; real_T P_287 [ 2 ] ; real_T P_288 ; real_T P_289 ;
real_T P_290 ; real_T P_291 ; real_T P_292 [ 2 ] ; real_T P_293 [ 2 ] ;
real_T P_294 ; real_T P_295 ; real_T P_296 ; real_T P_297 ; real_T P_298 ;
real_T P_299 ; real_T P_300 ; real_T P_301 ; real_T P_302 ; real_T P_303 ;
real_T P_304 ; real_T P_305 [ 2 ] ; real_T P_306 ; real_T P_307 ; real_T
P_308 ; real_T P_309 ; real_T P_310 ; uint32_T P_311 [ 2 ] ; uint32_T P_312 [
2 ] ; uint32_T P_313 [ 2 ] ; uint32_T P_314 [ 2 ] ; uint32_T P_315 [ 2 ] ;
uint8_T P_316 ; uint8_T P_317 ; uint8_T P_318 ; char pad_P_318 [ 5 ] ; } ;
extern nffqwkkk0o ba4bxx1frp ;
#endif
