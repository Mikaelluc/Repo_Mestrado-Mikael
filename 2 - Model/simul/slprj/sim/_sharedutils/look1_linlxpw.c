  
        /*
      * C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\simul\slprj\sim\_sharedutils\look1_linlxpw.c
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
          

      #include "look1_linlxpw.h"

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
               
real_T look1_linlxpw(real_T u0, const real_T bp0[], const real_T table[], uint32_T maxIndex)
{
    real_T frac;
    uint32_T bpIdx;
    /* Lookup 1-D
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
    } else if (u0 < bp0[maxIndex]) {
        /* Linear Search */
        for (bpIdx = maxIndex >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
        }
        while (u0 >= bp0[bpIdx + 1U]) {
            bpIdx++;
        }
        frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
    } else {
        bpIdx = maxIndex - 1U;
        frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
    }
    /* Interpolation 1-D
   Interpolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    return (table[bpIdx + 1U] - table[bpIdx]) * frac + table[bpIdx];
}
            

  
  
  
  
  
  
  
  
