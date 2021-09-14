suaddhead < v.dat ns=301 |
sushw key=tracl a=1 b=5 c=0 j=883 |
sushw key=fldr a=1 b=0 c=1 j=883 |
sushw key=sx a=1 b=2 c=2 j=883 |
sushw key=gx a=1 b=3 c=3 j=883 |
sushw key=cdp a=1 b=1 c=0 j=883 |
sushw  key=dt a=1000 |
sushw  key=scalel a=-1 |
sushw  key=scalco a=1 > v.su


#sushw key=sx a=745 c=20 j=301 |
#sushw key=gx a=0 b=5 j=301 |
#suchw key1=gx key2=gx key3=sx  a=-745 b=1 c=1 d=1 |
#suchw key1=cdp key2=gx b=1 d=5 |
#suchw key1=offset key2=gx key3=sx b=1 c=-1 > layer+sin_shot.su


#suximage < fout.su perc=98&
surange < v.su
