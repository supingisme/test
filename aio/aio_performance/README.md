BUILD:
You must install libaio libeio and libxio (download from my github space) 

make

USE: ./run.sh -e : this test libeio

      ./run.sh -a : this test libaio

      ./run.sh -n : this test native linux aio

AND there is a config file : aioperf.conf

EDIT aioperf.conf:

You can tell me if there is a bug , thank you!

@mail:xuke.coder@gmail.com
