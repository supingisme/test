19.6 Special Functions
These are some more exotic mathematical functions which are sometimes useful. Currently
they only have real-valued versions.
double erf (double x) [Function]
float erff (ﬂoat x) [Function]
long double erfl (long double x) [Function]
erf returns the error function of x. The error function is defned as
erf(x) = p2π · Z0x e−t2dt
double erfc (double x) [Function]
float erfcf (ﬂoat x) [Function]
long double erfcl (long double x) [Function]
erfc returns 1.0 - erf(x), but computed in a fashion that avoids round-oﬀ error
when x is large.
double lgamma (double x) [Function]
float lgammaf (ﬂoat x) [Function]
long double lgammal (long double x) [Function]
lgamma returns the natural logarithm of the absolute value of the gamma function of
x. The gamma function is defned as
Γ(x) = Z01 tx−1e−tdt
The sign of the gamma function is stored in the global variable signgam, which is
declared in ‘math.h’. It is 1 if the intermediate result was positive or zero, or -1 if it
was negative.
To compute the real gamma function you can use the tgamma function or you can
compute the values as follows:
lgam = lgamma(x);
gam = signgam*exp(lgam);
The gamma function has singularities at the non-positive integers. lgamma will raise
the zero divide exception if evaluated at a singularity.

double lgamma_r (double x, int *signp) [Function]
float lgammaf_r (ﬂoat x, int *signp) [Function]
long double lgammal_r (long double x, int *signp) [Function]
lgamma_r is just like lgamma, but it stores the sign of the intermediate result in
the variable pointed to by signp instead of in the signgam global. This means it is
reentrant.
double gamma (double x) [Function]
float gammaf (ﬂoat x) [Function]
long double gammal (long double x) [Function]
These functions exist for compatibility reasons. They are equivalent to lgamma etc. It
is better to use lgamma since for one the name reﬂects better the actual computation,
moreover lgamma is standardized in ISO C99 while gamma is not.
double tgamma (double x) [Function]
float tgammaf (ﬂoat x) [Function]
long double tgammal (long double x) [Function]
tgamma applies the gamma function to x. The gamma function is defned as
Γ(x) = Z01 tx−1e−tdt
This function was introduced in ISO C99.
double j0 (double x) [Function]
float j0f (ﬂoat x) [Function]
long double j0l (long double x) [Function]
j0 returns the Bessel function of the frst kind of order 0 of x. It may signal underﬂow
if x is too large.
double j1 (double x) [Function]
float j1f (ﬂoat x) [Function]
long double j1l (long double x) [Function]
j1 returns the Bessel function of the frst kind of order 1 of x. It may signal underﬂow
if x is too large.
double jn (int n, double x) [Function]
float jnf (int n, ﬂoat x) [Function]
long double jnl (int n, long double x) [Function]
jn returns the Bessel function of the frst kind of order n of x. It may signal underﬂow
if x is too large.
double y0 (double x) [Function]
float y0f (ﬂoat x) [Function]
long double y0l (long double x) [Function]
y0 returns the Bessel function of the second kind of order 0 of x. It may signal
underﬂow if x is too large. If x is negative, y0 signals a domain error; if it is zero, y0
signals overﬂow and returns −1.

double y1 (double x) [Function]
float y1f (ﬂoat x) [Function]
long double y1l (long double x) [Function]
y1 returns the Bessel function of the second kind of order 1 of x. It may signal
underﬂow if x is too large. If x is negative, y1 signals a domain error; if it is zero, y1
signals overﬂow and returns −1.
double yn (int n, double x) [Function]
float ynf (int n, ﬂoat x) [Function]
long double ynl (int n, long double x) [Function]
yn returns the Bessel function of the second kind of order n of x. It may signal
underﬂow if x is too large. If x is negative, yn signals a domain error; if it is zero, yn
signals overﬂow and returns −1.