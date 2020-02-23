#include "__cf_RudderActuatorChannel_control_arx.h"
#ifndef RTW_HEADER_RudderActuatorChannel_control_arx_acc_h_
#define RTW_HEADER_RudderActuatorChannel_control_arx_acc_h_
#include <stddef.h>
#ifndef RudderActuatorChannel_control_arx_acc_COMMON_INCLUDES_
#define RudderActuatorChannel_control_arx_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "RudderActuatorChannel_control_arx_acc_types.h"
#include "multiword_types.h"
#include "model_reference_types.h"
#include "BulkModulus.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "look1_binlxpw.h"
#include "look1_linlxpw.h"
#include "look2_linlxpw.h"
#include "mwmathutil.h"
#include "rt_nrand_Upu32_Yd_f_pw_snf.h"
#include "rt_defines.h"
typedef struct { real_T kuhkh31oiy ; real_T igym241rks ; real_T lhr4gozp0y ;
real_T bhwiyzl51m ; real_T lc41kxk0rd ; real_T kbfi0py1fa ; real_T nys5wqvw52
; real_T c3o4da5e5m ; real_T brzar1csag ; real_T o1ncnjjlho ; real_T
btjhdnoh1n ; real_T gz5rzd0exs ; real_T axtg1vvax0 ; real_T jf2qudmasa ;
real_T elosjr5sxa ; real_T odyseg2mo3 ; real_T b2bn0enuzr ; real_T i0hiub223b
; real_T nzddv312n0 ; real_T gxrcytfsrz ; real_T itc1u5vgfa ; real_T
fpjue20mi4 ; real_T fdtyg1vhil ; real_T gcap5ydni2 ; real_T ll4crdwph5 ;
real_T lq0ebzpbhn ; real_T ofmdxnkd2t ; real_T pksilsecp1 ; real_T j5430ydjq2
; real_T hgu3pgigdx ; real_T m1mibckcs4 ; real_T jjzvkidydh ; real_T
ml222pyglw ; real_T lvrrbkxknn ; real_T pbmg0jvkui ; real_T dcdqc53e3p ;
real_T jixctj4i3i ; real_T oykheqek5p ; real_T lchy3tgcue ; real_T n02ocgpj2y
; real_T b31e2dau1u ; real_T fb2wkzllqo ; real_T obuh3nbeb3 ; real_T
l0jlurnmcw ; real_T hsp34m3g0p ; real_T iqkjvj0jst ; real_T gnuywaarye ;
real_T fx0xa2aym3 ; real_T cjayaestjq ; real_T d3i020iazt ; real_T fl2cprobux
; real_T pugxvb2nmo ; real_T k3yqzbkkjr ; real_T ch30gfkvpv ; real_T
okggatoig3 ; real_T ci4hnvidwu ; real_T np4wpishrd ; real_T ehhu1q4m3v ;
real_T h1vi50020h ; real_T gqjrmw2rax ; real_T oqhp4mpb2d ; real_T odmw1npc4y
; real_T nevgoskq1w ; real_T oodrlqisge ; real_T ab5mjcry1c ; real_T
fgmlnqxyxw ; real_T bajdjn1p4w ; real_T ae4wjooiyn ; real_T obquo1tjbj ;
real_T e4gqlcq25j ; real_T bb3g5dhsqf ; real_T pwhthbse5l ; real_T d4ytny2pcb
; real_T ju4pt4e3t1 ; real_T ptxgdw5hau ; real_T bmh0kecgjx ; real_T
hydeaorfmj ; real_T npjmnqlw0m ; real_T e3iaobyfvi ; real_T om01qchcvh ;
real_T mntanavo1v ; real_T hpwtthsgao ; real_T pylbfccqp3 ; real_T cchjidhval
; real_T gx2wc5plqk ; real_T hajaltd403 ; real_T h5blfhj5xb ; real_T
a1llbmfa3y ; real_T kifubppid5 ; real_T ppf0vi1w3f ; real_T fdzfczzrvx ;
real_T mprm5oesqe ; real_T k4qti4y1oj ; real_T danztdweow ; real_T kbhl3xunqh
; real_T nhkyfnhuqx ; real_T j5pecabkao ; real_T hndptwqamr ; real_T
injakv53si ; real_T oglcxk3w0z ; real_T fsqku2flzn ; real_T bfwv2zog2l ;
real_T hynxlmdxe3 ; real_T n2yohgi5ad ; real_T dzftyohstp ; real_T junyims2eh
; real_T fegztkkjgs ; real_T plrvu3y2oe ; real_T ndmfqjzcpb ; real_T
dnwizyu4kv ; real_T keeiuyodd0 ; real_T pryft0gxvr ; real_T dhj32lvu03 ;
real_T bk13bsxxsd ; real_T marnjvecom ; real_T fwpukv440p ; real_T h0xtbghjrk
; real_T hw01og4kj3 ; real_T h5l1b0ivf3 ; real_T hwvupjcl0k ; real_T
ey1s2cmw2j [ 3 ] ; real_T l0kyrdyjl4 ; real_T ijqfpmo2ez ; real_T cskw0mk5um
; real_T jlhwlfxfqm ; real_T btcodpzuax ; real_T edns4zvnob ; real_T
e1fwbxkvy4 ; real_T o33jrm5rsu ; real_T jtb2enq0yo ; real_T fkvf10soow ;
real_T fz5mtyhj2s ; real_T lj0ges5pxa ; real_T mmvwbsq5m1 ; real_T ed0xlb4e1k
; real_T ehlozjhzt3 ; real_T ok3rj2qsql ; real_T i4agjo0o2q ; real_T
dzgeaeio0o ; real_T k02glv12vk ; real_T m2p3ad3ieo ; real_T mdvzy1tj3b ;
real_T mn40rtrgjr ; real_T kyf2pl0l1m ; real_T f0vxhabzwe ; } jtidzxyrjg ;
typedef struct { real_T oo5bsaaczi ; real_T fexrex2lnb ; real_T kipks1c1ub ;
real_T bbrtg1brww ; real_T o1slsgzwiu ; real_T fvg0winctx ; real_T ljsjdsk3bz
; real_T au32dnnyqy ; real_T ipad2pi0bd ; real_T kp1qt5ebjd ; real_T
pjkg1pvb1y ; real_T jjoc4g3mtd ; real_T nlrxhdmjwg ; real_T ky1wvz2he1 ;
real_T ecgh4dfgct ; real_T ilkeiajsjs ; real_T labca0irxk ; real_T dbslzvxac0
; real_T cls3nfmnkx ; real_T i4hp2bhq50 ; real_T kcq2vvwalv ; real_T
kb5wq2lzco ; real_T hp03tby40u ; real_T ke1nxqln0z ; real_T hquj3zpeta ;
real_T llu2czoz4u ; real_T lu1k2mfdqi ; real_T fy0aqenslx ; real_T aqi1oaav1f
; real_T n0q4irobfk ; real_T kbsuvrgwwv ; real_T pyzz1cerdf [ 2 ] ; void *
lpxslevega ; void * j1urgg0wu2 ; void * ku3nsreteq ; struct { void *
LoggedData ; } k4i5qxhmst ; void * hx4idfksip ; struct { void * LoggedData ;
} pc4btcrxyd ; struct { void * LoggedData ; } pcywbq4bbd ; void * bohvdqkzuz
; void * kn2hrn2vqb ; void * faxhnerhr0 ; void * dglvwekvqa ; void *
bohvdqkzuzy ; void * ah53jzosp3 ; struct { void * LoggedData ; } k3geuwqlkz ;
void * p0b3vlbuvc ; void * ozv1ixw5go ; void * fy3y2ana25 ; void * ba12u1s41t
; struct { void * LoggedData ; } ptwd25tfxn ; struct { void * LoggedData ; }
f2nfqdexaq ; struct { void * LoggedData ; } mprbjr3iwx ; void * jn01zvc0xn ;
struct { void * LoggedData ; } j3vbv4tten ; struct { void * LoggedData ; }
fzwndjkwzm ; struct { void * LoggedData ; } cfgltdebxu ; void * owcoj3vuls ;
struct { void * LoggedData ; } cyxsh3xil5 ; struct { void * LoggedData ; }
dknty3fc4o ; struct { void * LoggedData ; } jelahinpvl ; struct { void *
LoggedData ; } iywpyvz0jh ; uint32_T aucxhtei0l ; uint32_T dif2b05yma ;
uint32_T p4sfnkha3x ; uint32_T crf25ruvpb ; int8_T n52kgt5jjk ; int8_T
hb0rm52iyz ; int8_T ir5dmhfx4y ; int8_T flzahjw23w ; int8_T ddwxnuqjtx ;
boolean_T ajnkld54jq ; char pad_ajnkld54jq [ 2 ] ; ou41r25q2gt hbf35cr0n5 ;
ou41r25q2gt hmdb2tvivl ; ou41r25q2gt b0rjuocjuo ; ou41r25q2gt ok0zr421u5 ; }
e1ktjqv0uw ; typedef struct { real_T fjnlo45vm5 ; real_T bcbg0xhhvg ; real_T
psbmjezpot ; real_T ipcpag3ubq ; real_T hmouxgquvh ; real_T ey4zwy0fx2 ;
real_T mnijmgq3uw ; real_T ay2ymrmb4s ; real_T b341ywuexg ; real_T h0eevxq1ts
; real_T laqqdhc3pk [ 3 ] ; real_T cwxakbqjyi ; real_T n5xcqfi1jr [ 2 ] ;
real_T eprrclyryl [ 2 ] ; real_T jyov3a5ehg ; } fgjgo1omwk ; typedef struct {
real_T fjnlo45vm5 ; real_T bcbg0xhhvg ; real_T psbmjezpot ; real_T ipcpag3ubq
; real_T hmouxgquvh ; real_T ey4zwy0fx2 ; real_T mnijmgq3uw ; real_T
ay2ymrmb4s ; real_T b341ywuexg ; real_T h0eevxq1ts ; real_T laqqdhc3pk [ 3 ]
; real_T cwxakbqjyi ; real_T n5xcqfi1jr [ 2 ] ; real_T eprrclyryl [ 2 ] ;
real_T jyov3a5ehg ; } bfvdfxf4la ; typedef struct { boolean_T fjnlo45vm5 ;
boolean_T bcbg0xhhvg ; boolean_T psbmjezpot ; boolean_T ipcpag3ubq ;
boolean_T hmouxgquvh ; boolean_T ey4zwy0fx2 ; boolean_T mnijmgq3uw ;
boolean_T ay2ymrmb4s ; boolean_T b341ywuexg ; boolean_T h0eevxq1ts ;
boolean_T laqqdhc3pk [ 3 ] ; boolean_T cwxakbqjyi ; boolean_T n5xcqfi1jr [ 2
] ; boolean_T eprrclyryl [ 2 ] ; boolean_T jyov3a5ehg ; } k5hzit25dv ;
typedef struct { real_T * B_12_2 ; real_T * B_12_3 ; real_T * B_12_4 ; real_T
* B_12_6 ; real_T * B_12_7 ; } l0cu0nmvu3 ; struct co4cjo04cz_ { real_T P_0 ;
real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ;
real_T P_7 [ 3 ] ; real_T P_8 [ 3 ] ; real_T P_9 ; real_T P_10 [ 21 ] ;
real_T P_11 [ 21 ] ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ;
real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T
P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ;
real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T
P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ;
real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; real_T
P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T P_48 ;
real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ; real_T
P_54 ; real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ;
real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T
P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ;
real_T P_71 ; real_T P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T
P_76 ; real_T P_77 ; real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ;
real_T P_82 ; real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T
P_87 ; real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ;
real_T P_93 ; real_T P_94 [ 7 ] ; real_T P_95 [ 7 ] ; real_T P_96 ; real_T
P_97 ; real_T P_98 ; real_T P_99 [ 18 ] ; real_T P_100 [ 6 ] ; real_T P_101 [
3 ] ; real_T P_102 ; real_T P_103 [ 7 ] ; real_T P_104 [ 7 ] ; real_T P_105 ;
real_T P_106 [ 18 ] ; real_T P_107 [ 6 ] ; real_T P_108 [ 3 ] ; real_T P_109
; real_T P_110 [ 7 ] ; real_T P_111 [ 7 ] ; real_T P_112 ; real_T P_113 ;
real_T P_114 ; real_T P_115 [ 18 ] ; real_T P_116 [ 6 ] ; real_T P_117 [ 3 ]
; real_T P_118 ; real_T P_119 [ 7 ] ; real_T P_120 [ 7 ] ; real_T P_121 ;
real_T P_122 [ 18 ] ; real_T P_123 [ 6 ] ; real_T P_124 [ 3 ] ; real_T P_125
; real_T P_126 ; real_T P_127 [ 7 ] ; real_T P_128 [ 7 ] ; real_T P_129 ;
real_T P_130 ; real_T P_131 ; real_T P_132 [ 18 ] ; real_T P_133 [ 6 ] ;
real_T P_134 [ 3 ] ; real_T P_135 ; real_T P_136 ; real_T P_137 ; real_T
P_138 ; real_T P_139 ; real_T P_140 ; real_T P_141 ; real_T P_142 ; real_T
P_143 ; real_T P_144 ; real_T P_145 ; real_T P_146 ; real_T P_147 ; real_T
P_148 ; real_T P_149 ; real_T P_150 ; real_T P_151 ; real_T P_152 ; real_T
P_153 ; real_T P_154 ; real_T P_155 [ 3 ] ; real_T P_156 [ 3 ] ; real_T P_157
; real_T P_158 ; real_T P_159 ; real_T P_160 ; real_T P_161 ; real_T P_162 ;
real_T P_163 ; real_T P_164 ; real_T P_165 [ 3 ] ; real_T P_166 [ 3 ] ;
real_T P_167 ; real_T P_168 ; real_T P_169 ; real_T P_170 ; real_T P_171 ;
real_T P_172 ; real_T P_173 ; real_T P_174 ; real_T P_175 [ 3 ] ; real_T
P_176 [ 3 ] ; real_T P_177 ; real_T P_178 ; real_T P_179 ; real_T P_180 ;
real_T P_181 ; real_T P_182 ; real_T P_183 ; real_T P_184 ; real_T P_185 ;
real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T P_189 ; real_T P_190 ;
real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T P_194 ; real_T P_195 ;
real_T P_196 [ 9 ] ; real_T P_197 ; real_T P_198 [ 5 ] ; real_T P_199 ;
real_T P_200 ; real_T P_201 ; real_T P_202 ; real_T P_203 ; real_T P_204 ;
real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T P_209 ;
real_T P_210 ; real_T P_211 ; real_T P_212 ; real_T P_213 ; real_T P_214 ;
real_T P_215 ; real_T P_216 [ 2 ] ; real_T P_217 [ 2 ] ; real_T P_218 ;
real_T P_219 ; real_T P_220 ; real_T P_221 ; real_T P_222 [ 2 ] ; real_T
P_223 [ 2 ] ; real_T P_224 ; real_T P_225 ; real_T P_226 ; real_T P_227 ;
real_T P_228 ; real_T P_229 ; real_T P_230 ; real_T P_231 ; real_T P_232 ;
real_T P_233 ; real_T P_234 ; real_T P_235 ; real_T P_236 ; real_T P_237 ;
real_T P_238 ; real_T P_239 ; real_T P_240 ; real_T P_241 ; real_T P_242 ;
real_T P_243 ; real_T P_244 ; real_T P_245 ; real_T P_246 ; real_T P_247 ;
real_T P_248 ; real_T P_249 [ 9 ] ; real_T P_250 [ 9 ] ; real_T P_251 [ 3 ] ;
real_T P_252 ; real_T P_253 ; real_T P_254 ; real_T P_255 ; real_T P_256 ;
real_T P_257 ; real_T P_258 ; real_T P_259 ; real_T P_260 ; real_T P_261 ;
real_T P_262 ; real_T P_263 ; real_T P_264 ; real_T P_265 ; real_T P_266 ;
real_T P_267 ; real_T P_268 ; real_T P_269 ; real_T P_270 ; real_T P_271 ;
real_T P_272 ; real_T P_273 ; real_T P_274 ; real_T P_275 ; real_T P_276 ;
real_T P_277 [ 2 ] ; real_T P_278 [ 2 ] ; real_T P_279 ; real_T P_280 ;
real_T P_281 ; real_T P_282 ; real_T P_283 [ 2 ] ; real_T P_284 [ 2 ] ;
real_T P_285 ; real_T P_286 ; real_T P_287 ; real_T P_288 ; real_T P_289 ;
real_T P_290 ; real_T P_291 ; real_T P_292 ; real_T P_293 ; real_T P_294 ;
real_T P_295 ; real_T P_296 [ 2 ] ; real_T P_297 ; real_T P_298 ; real_T
P_299 ; real_T P_300 ; real_T P_301 ; uint32_T P_302 [ 2 ] ; uint32_T P_303 [
2 ] ; uint32_T P_304 [ 2 ] ; uint32_T P_305 [ 2 ] ; uint32_T P_306 [ 2 ] ;
uint8_T P_307 ; uint8_T P_308 ; uint8_T P_309 ; char pad_P_309 [ 5 ] ; } ;
extern co4cjo04cz oopmglxopz ;
#endif
