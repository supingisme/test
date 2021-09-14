#!/bin/sh
paramsfile="3l-t20-params.txt"
configfile="3l-t20-configuration.conf "
filename=("../data/mnist-test-images-to-file/7_5*.txt" )
for name in ${filename[@]}; do
    # echo $name
    ./mnn_main --load-parameters $paramsfile --config-file $configfile \
        --image $name \
      | grep -i number --color=auto
done
