  
        /*
      * C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\simul\slprj\sim\_sharedutils\rt_nrand_Upu32_Yd_f_pw_snf.c
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
              #include "mwmathutil.h"
        #include "rt_urand_Upu32_Yd_f_pw_snf.h"
    

      #include "rt_nrand_Upu32_Yd_f_pw_snf.h"

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
                                  
          
    
    
        
     

              
     real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
    {
          real_T y;
real_T sr;
real_T si;

/* Normal (Gaussian) random number generator */
do {


    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;


    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
} while (si > 1.0);
y = muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(si) / si) * sr;
return y;


    }
    

            

  
  
  
  
  
  
  
  
