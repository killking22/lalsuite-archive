/*
* Copyright (C) 2017 Tim Dietrich, Sebastiano Bernuzzi, Nathan Johnson-McDaniel, Shasvath J Kapadia, Francesco Pannarale and Sebastian Khan
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with with program; see the file COPYING. If not, write to the
*  Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
*  MA  02111-1307  USA
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <lal/LALStdlib.h>
#include <lal/LALConstants.h>
#include <lal/Date.h>
#include <lal/Units.h>
#include <lal/LALSimIMR.h>

#ifdef __GNUC__
#define UNUSED __attribute__ ((unused))
#else
#define UNUSED
#endif


/**
 * Function to call the frequency domain tidal correction
 * Equation (7) in arXiv:1706.02969
 */
static double NRTunedTidesFDTidalPhase(
    UNUSED const REAL8 PN_x, /**< PN frequency parameter: PN_x = orb_freq^(2./3.) */
    UNUSED const REAL8 PN_x_2,
    UNUSED const REAL8 PN_x_3over2,
    UNUSED const REAL8 PN_x_5over2,
    UNUSED const REAL8 Xa, /**< Mass of companion 1 divided by total mass */
    UNUSED const REAL8 Xb, /**< Mass of companion 2 divided by total mass */
    UNUSED const REAL8 kappa2T, /**< tital coupling constant. Eq. 2 in arXiv:1706.02969 */
    UNUSED const REAL8 mtot
    )
{

    /* model parameters */
    const REAL8 c_Newt = 2.4375; /* 39.0 / 16.0 */

    const REAL8 n_1 = -17.428;
    const REAL8 n_3over2 = 31.867;
    const REAL8 n_2 = -26.414;
    const REAL8 n_5over2 = 62.362;

    const REAL8 d_1 = n_1 - 2.496; /* 3115.0/1248.0 */
    const REAL8 d_3over2 = 36.089;

    REAL8 tidal_phase = - kappa2T * c_Newt / (Xa * Xb) * PN_x_5over2;

    REAL8 num = 1.0 + (n_1 * PN_x) + (n_3over2 * PN_x_3over2) + (n_2 * PN_x_2) + (n_5over2 * PN_x_5over2) ;
    REAL8 den = 1.0 + (d_1 * PN_x) + (d_3over2 * PN_x_3over2) ;

    REAL8 ratio = num / den;

    tidal_phase *= ratio;

    return tidal_phase;
}

int XLALSimNRTunedTidesFDTidalPhaseFrequencySeries(
    UNUSED const REAL8Sequence *phi_tidal, /**< [out] tidal phase frequency series */
    UNUSED const REAL8Sequence *fHz, /**< list of input Gravitational wave Frequency in Hz to evaluate */
    UNUSED const REAL8 m1_SI, /**< Mass of companion 1 (kg) */
    UNUSED const REAL8 m2_SI, /**< Mass of companion 2 (kg) */
    UNUSED const REAL8 kappa2T /**< tital coupling constant. Eq. 2 in arXiv:1706.02969 */
    )
{

    const REAL8 m1 = m1_SI / LAL_MSUN_SI;
    const REAL8 m2 = m2_SI / LAL_MSUN_SI;
    const REAL8 mtot = m1 + m2;

    /* Xa and Xb are the masses normalised for a total mass = 1 */
    /* not the masses appear symmetrically so we don't need to switch them. */
    const REAL8  Xa = m1 / mtot;
    const REAL8  Xb = m2 / mtot;

    REAL8 PN_x = 0.0;
    REAL8 PN_x_2 = 0.0;
    REAL8 PN_x_3over2 = 0.0;
    REAL8 PN_x_5over2 = 0.0;

    for(UINT4 i = 0; i < (*fHz).length; i++){
        /* note the expression is Eq 7 in arXiv:1706.02969
         * is a function of x = orb_freq^(2./3.)
         */
        PN_x = pow((*fHz).data[i] / 2.0, 2.0/3.0);
        PN_x_2 = PN_x * PN_x;
        PN_x_3over2 = pow(PN_x, 3.0/2.0);
        PN_x_5over2 = pow(PN_x, 5.0/2.0);

        (*phi_tidal).data[i] = NRTunedTidesFDTidalPhase(PN_x, PN_x_2, PN_x_3over2, PN_x_5over2, Xa, Xb, kappa2T, mtot);
    }

    return XLAL_SUCCESS;
}
