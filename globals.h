/*  This file is included from multiple source files, gcc as of v10 dislikes
    these 'common' declarations. Macros below are an attempt to conform to the
    new behavior without radically altering the structure of this very old code.
*/

#ifdef DEFINE_VARIABLES
#define EXTERN              /* empty */
#define INITIALIZER(...)         = __VA_ARGS__
#else
#define EXTERN      extern
#define INITIALIZER(...)          /* empty */
#endif


typedef struct
{
   int       x0,y0;       /* origin of stamp in region coords*/
   int       x,y;         /* center of stamp in region coords*/
   int       nx,ny;       /* size of stamp */
   int       *xss;        /* x location of test substamp centers */
   int       *yss;        /* y location of test substamp centers */
   int       nss;         /* number of detected substamps, 1 .. nss     */
   int       sscnt;       /* represents which nss to use,  0 .. nss - 1 */
   double    **vectors;   /* contains convolved image data */
   double    *krefArea;   /* contains kernel substamp data */
   double    **mat;       /* fitting matrices */
   double    *scprod;     /* kernel sum solution */
   double    sum;         /* sum of fabs, for sigma use in check_stamps */
   double    mean;
   double    median;
   double    mode;        /* sky estimate */
   double    sd;
   double    fwhm;
   double    lfwhm;
   double    chi2;        /* residual in kernel fitting */
   double    norm;        /* kernel sum */
   double    diff;        /* (norm - mean_ksum) * sqrt(sum) */
} stamp_struct;

/* GLOBAL VARS POSSIBLY SET ON COMMAND LINE */
EXTERN char      *template INITIALIZER(0), *image INITIALIZER(0), *outim INITIALIZER(0);

EXTERN float     tUThresh INITIALIZER(0.0), tUKThresh INITIALIZER(0.0), tLThresh INITIALIZER(0.0),
                 tGain INITIALIZER(0.0), tRdnoise INITIALIZER(0.0), iUThresh INITIALIZER(0.0),
                 iUKThresh INITIALIZER(0.0), iLThresh INITIALIZER(0.0), iGain INITIALIZER(0.0),
                 iRdnoise INITIALIZER(0.0);
EXTERN char      *tNoiseIm INITIALIZER(0), *iNoiseIm INITIALIZER(0), *tMaskIm INITIALIZER(0),
                 *iMaskIm INITIALIZER(0), *kernelImIn INITIALIZER(0), *kernelImOut INITIALIZER(0),
                 *outMask INITIALIZER(0);
EXTERN float     tPedestal INITIALIZER(0.0), iPedestal INITIALIZER(0.0);
EXTERN int       hwKernel INITIALIZER(0);
EXTERN float     kerFitThresh INITIALIZER(0.0), scaleFitThresh INITIALIZER(0.0), minFracGoodStamps INITIALIZER(0.0);
EXTERN float     kfSpreadMask1 INITIALIZER(0.0), kfSpreadMask2 INITIALIZER(0.0);
EXTERN int       gdXmin INITIALIZER(0), gdXmax INITIALIZER(0), gdYmin INITIALIZER(0), gdYmax INITIALIZER(0);
EXTERN int       nRegX INITIALIZER(0), nRegY INITIALIZER(0);
EXTERN char      *regFile INITIALIZER(0);
EXTERN char      *regKeyWord INITIALIZER(0);
EXTERN int       numRegKeyWord INITIALIZER(0);
EXTERN int       nStampY INITIALIZER(0), nStampX INITIALIZER(0), useFullSS INITIALIZER(0);
EXTERN int       nKSStamps INITIALIZER(0), hwKSStamp INITIALIZER(0);
EXTERN char      *sstampFile INITIALIZER(0);
EXTERN int       findSSC INITIALIZER(0);
EXTERN int       kerOrder INITIALIZER(0), bgOrder INITIALIZER(0);
EXTERN float     statSig INITIALIZER(0.0), kerSigReject INITIALIZER(0.0), kerFracMask INITIALIZER(0.0);
EXTERN char      *forceConvolve INITIALIZER(0), *photNormalize INITIALIZER(0), *figMerit INITIALIZER(0);
EXTERN int       sameConv INITIALIZER(0), rescaleOK INITIALIZER(0);
EXTERN float     fillVal INITIALIZER(0.0), fillValNoise INITIALIZER(0.0);
EXTERN char      *effFile INITIALIZER(0), *noiseImage INITIALIZER(0), *sigmaImage INITIALIZER(0),
                 *convImage INITIALIZER(0);
EXTERN int       doSum INITIALIZER(0), inclNoiseImage INITIALIZER(0), inclSigmaImage INITIALIZER(0),
                 inclConvImage INITIALIZER(0), noClobber INITIALIZER(0);
EXTERN int       doKerInfo INITIALIZER(0), outShort INITIALIZER(0), outNShort INITIALIZER(0);
EXTERN float     outBzero INITIALIZER(0.0), outBscale INITIALIZER(0.0), outNiBzero INITIALIZER(0.0),
                 outNiBscale INITIALIZER(0.0);
EXTERN int       convolveVariance INITIALIZER(0);
EXTERN int       usePCA INITIALIZER(0), fwKernelPCA INITIALIZER(0);
EXTERN float     **PCA INITIALIZER(0);

/* GLOBAL VARS NOT SET ON COMMAND LINE */
EXTERN int       ngauss INITIALIZER(0), *deg_fixe INITIALIZER(0);
EXTERN float     *sigma_gauss INITIALIZER(0);

EXTERN int       rPixX INITIALIZER(0), rPixY INITIALIZER(0);
EXTERN int       nStamps INITIALIZER(0), nS INITIALIZER(0), nCompKer INITIALIZER(0), nC INITIALIZER(0);

EXTERN int       nComp INITIALIZER(0), nCompBG INITIALIZER(0), nBGVectors INITIALIZER(0), nCompTotal INITIALIZER(0);

EXTERN int       fwKernel INITIALIZER(0), fwStamp INITIALIZER(0), hwStamp INITIALIZER(0), fwKSStamp INITIALIZER(0),
                 kcStep INITIALIZER(0), *indx INITIALIZER(0);
EXTERN int       cmpFile INITIALIZER(0);
EXTERN float     *temp INITIALIZER(0), *temp2 INITIALIZER(0);
EXTERN double    *check_stack INITIALIZER(0),*filter_x INITIALIZER(0),*filter_y INITIALIZER(0),
                 **kernel_vec INITIALIZER(0);
EXTERN double    **wxy INITIALIZER(0),*kernel_coeffs INITIALIZER(0),*kernel INITIALIZER(0),
                 **check_mat INITIALIZER(0),*check_vec INITIALIZER(0);
EXTERN char      version[32] INITIALIZER("");

/* REGION SIZED */
EXTERN int       *mRData INITIALIZER(0);   /* bad input data mask */

/* armin */
/* a dummy varialbe to do some testing */
EXTERN int        dummy INITIALIZER(0);
/* verbose for debugging */
EXTERN int        verbose INITIALIZER(0);
/* cmp file stuff */
EXTERN char       xyfilename[1000] INITIALIZER("");
EXTERN int        savexyflag INITIALIZER(0);
EXTERN float      *xcmp INITIALIZER(0),*ycmp INITIALIZER(0);
EXTERN int        Ncmp INITIALIZER(0);
