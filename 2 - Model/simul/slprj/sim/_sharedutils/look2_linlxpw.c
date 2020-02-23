  
        /*
      * C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\simul\slprj\sim\_sharedutils\look2_linlxpw.c
      * 
        * Code generation for model "RudderActuatorChannel_control_acc".
  *
  * Model version              : 1.760
  * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
  * C source code generated on : Mon Mar 20 21:33:10 2017
      * Created for block: RudderActuatorChannel_control_acc
      */


      

  
#include "rtwtypes.h"

#include "multiword_types.h"
          

      #include "look2_linlxpw.h"

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
               
real_T look2_linlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
    real_T frac;
    uint32_T bpIndices[2];
    real_T fractions[2];
    real_T yL_1d;
    uint32_T bpIdx;
    /* Lookup 2-D
   Search method: 'linear'
   Use previous index: 'off'
   Interpolation method: 'Linear'
   Extrapolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    /* Prelookup - Index and Fraction
   Index Search method: 'linear'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u0 <= bp0[0U]) {
        bpIdx = 0U;
        frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
    } else if (u0 < bp0[maxIndex[0U]]) {
        /* Linear Search */
        for (bpIdx = maxIndex[0U] >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
        }
        while (u0 >= bp0[bpIdx + 1U]) {
            bpIdx++;
        }
        frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
    } else {
        bpIdx = maxIndex[0U] - 1U;
        frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U] - 1U]);
    }
    fractions[0U] = frac;
    bpIndices[0U] = bpIdx;
    /* Prelookup - Index and Fraction
   Index Search method: 'linear'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u1 <= bp1[0U]) {
        bpIdx = 0U;
        frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
    } else if (u1 < bp1[maxIndex[1U]]) {
        /* Linear Search */
        for (bpIdx = maxIndex[1U] >> 1U; u1 < bp1[bpIdx]; bpIdx--) {
        }
        while (u1 >= bp1[bpIdx + 1U]) {
            bpIdx++;
        }
        frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1U] - bp1[bpIdx]);
    } else {
        bpIdx = maxIndex[1U] - 1U;
        frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U] - 1U]);
    }
    /* Interpolation 2-D
   Interpolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    bpIdx = bpIdx * stride + bpIndices[0U];
    yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
    bpIdx += stride;
    return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) - yL_1d) * frac + yL_1d;
}
            

  
  
  
  
  
  
  
  
